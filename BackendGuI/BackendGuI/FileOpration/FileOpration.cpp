#include "FileOpration.h"
#include <QFile>
#include <QDebug>
/*--------------------------------------------------------------------
** 名称 : FileOpration
**--------------------------------------------------------------------
** 功能 : 构造函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
FileOpration::FileOpration()
{

}
/*--------------------------------------------------------------------
** 名称 : ~FileOpration
**--------------------------------------------------------------------
** 功能 : 析构函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
FileOpration::~FileOpration()
{

}

/*--------------------------------------------------------------------
** 名称 : addPlanItem
**--------------------------------------------------------------------
** 功能 : 保存新增的计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool FileOpration::addPlanItem(const char* pszFile, QString& qstrPlan)
{
	if(!pszFile ||
		qstrPlan.isNull())
	{
		return false;
	}

	// 保存到文件里
	QFile fileout(pszFile);

	if(!fileout.open(QIODevice::Append | QIODevice::Text))
	{
		qDebug() << "Open failed";
		return false;
	}

	qstrPlan.append("\n");
	std::string strPlan = qstrPlan.toStdString();
	const char* pszPlan = strPlan.c_str();

	fileout.write(pszPlan);

	return true;
}
/*--------------------------------------------------------------------
** 名称 : UpdatePlanFile
**--------------------------------------------------------------------
** 功能 : 删除计划之后，更新文件
**--------------------------------------------------------------------
** 参数 : pszFile 文件名 
** 参数 : mapItemPlan 计划迭代器
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool FileOpration::UpdatePlanFile(const char* pszFile, MapItemPlan& mapItemPlan)
{
	if(!pszFile)
	{
		return false;
	}

// 	int iSize = mapItemPlan.size();
// 	if(iSize <=0)
// 	{
// 		return false;
// 	}

	QFile oldfile(pszFile);

	oldfile.remove(); // 删除之前的文件

	QFile file(pszFile);
	//	file.setFileName(D_YEAR_PLAN);
	if(!file.exists())
	{
		if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
		{
			return false;
		}
	}
	else
	{
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			return false;
		}
	}

	MapItemPlan::iterator itMap = mapItemPlan.begin();
	int iKey = 1;

	for(; itMap!= mapItemPlan.end(); itMap++)
	{
		
		QString qstrPlan = itMap->second;

		QString qstrKeyAndPlan;
		qstrKeyAndPlan = QString::number(iKey);
		qstrKeyAndPlan.append(":");
		qstrKeyAndPlan.append(qstrPlan);

		addPlanItem(pszFile, qstrKeyAndPlan);

		iKey += 1;
	}
	
	return true;
}
