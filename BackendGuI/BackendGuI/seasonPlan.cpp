#include "seasonPlan.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "Define/seasonPlanDefine.h"

//autumnPlan winterPlan
seasonPlan::seasonPlan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//connect(, SIGNAL(clicked()), this, SLOT(onAccountBtnclicked()));
	connect(ui.springBtn, SIGNAL(clicked()), this, SLOT(onSpringBtnclicked()));
	connect(ui.summerBtn, SIGNAL(clicked()), this, SLOT(onSummerBtnclicked()));
	connect(ui.autumnBtn, SIGNAL(clicked()), this, SLOT(onAutumnBtnclicked()));
	connect(ui.winterBtn, SIGNAL(clicked()), this, SLOT(onWinterBtnclicked()));

	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(onAddBtnclicked()));
	connect(ui.seasonlistWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onDeletePlan()));

	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺季度计划 "));
	this->setWindowIcon(QIcon("wheet.png"));

	//connect(ui.add); //onAddBtnclicked addBtn
	ui.seasonlistWidget->setSortingEnabled(true); // 自动排序

	m_iSeason = 1;
}

seasonPlan::~seasonPlan()
{
}
/*--------------------------------------------------------------------
** 名称 : LoadResource
**--------------------------------------------------------------------
** 功能 : 加载资源
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
bool seasonPlan::LoadResource(const char* pszPlancfg)
{
	if(NULL == pszPlancfg)
	{
		return false;
	}

	QFile file(pszPlancfg);
	if(!file.open(QIODevice::ReadWrite | QIODevice::Text))// ReadOnly
	{
		return false;
	}

	ui.seasonlistWidget->clear();
	m_iSetItem.clear();

	QTextStream in(&file);
	in.setCodec("UTF-8");
	while(!in.atEnd())
	{
		QString line = in.readLine();

		InitListWidget(line);
	}
	return true;
}
/*--------------------------------------------------------------------
** 名称 : 插入每一行
**--------------------------------------------------------------------
** 功能 : 加载资源
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.034.3		Mark
**-------------------------------------------------------------------*/
bool seasonPlan::InitListWidget(QString& qstrInfo)
{
	if(qstrInfo.isEmpty())
	{
		return false;
	}

	QStringList list = qstrInfo.split(":");
	if(list.empty())
	{
		return false;
	}

	QString qstrText = list[1];
	int iKey = QueryQurrentKey(); // 查key

	MapSeasonSum::iterator itSeasonSum = m_MapSeasonSum.find(m_iSeason);
	if(itSeasonSum == m_MapSeasonSum.end())
	{
		MapItemPlan mapItemPlan;
		mapItemPlan.insert(std::make_pair(iKey, qstrText));

		m_MapSeasonSum.insert(std::make_pair(m_iSeason, mapItemPlan));
	}
	else
	{
		itSeasonSum->second.insert(std::make_pair(iKey, qstrText));
	}

	ui.seasonlistWidget->insertItem(iKey, qstrInfo);

	return true;
}
/*--------------------------------------------------------------------
** 名称 : onSpringBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:春季计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onSpringBtnclicked()
{
	m_iSeason = E_SEASON_TYPE_SPRING;

	LoadResource(D_SEASON_SPRING_PLAN_CONFIG);

}
/*--------------------------------------------------------------------
** 名称 : onSummerBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:夏季计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onSummerBtnclicked()
{
	m_iSeason = E_SEASON_TYPE_SUMMER;

	LoadResource(D_SEASON_SUMMER_PLAN_CONFIG);

}
/*--------------------------------------------------------------------
** 名称 : onAutumnBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:秋季计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onAutumnBtnclicked()
{	
	m_iSeason = E_SEASON_TYPE_AUTUMN;

	LoadResource(D_SEASON_AUTUMN_PLAN_CONFIG);

}
/*--------------------------------------------------------------------
** 名称 : onWinterBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:冬季计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onWinterBtnclicked()
{
	m_iSeason = E_SEASON_TYPE_WINTER;

	LoadResource(D_SEASON_WINTER_PLAN_CONFIG);

}
/*--------------------------------------------------------------------
** 名称 : onAddBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:新增计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onAddBtnclicked()
{
	//int inumber = ui.numEdit->text().toInt();
	QString qsPlan = ui.planLineEdit->text();

	MapItemPlan mapMonthPlan;

	int iKey = QueryQurrentKey(); // 查key
	SavePlanOnMap(iKey,qsPlan); // 保存到迭代器里

	QString qstrPlan;
	qstrPlan = QString::number(iKey);

	qstrPlan.append(":");
	qstrPlan.append(qsPlan);

	qDebug() << "qstrPlan" << qstrPlan;
	ui.seasonlistWidget->insertItem(0, qstrPlan);

	const char* pszFile = QuerySeasonPlanFile();
	if(!pszFile)
	{
		return;
	}

	FileOpration::addPlanItem(pszFile, qstrPlan); // 保存到文件里面

	ui.planLineEdit->clear();
}
/*--------------------------------------------------------------------
** 名称 : onDeletePlan
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:删除计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::onDeletePlan()
{
	int iRow = ui.seasonlistWidget->currentRow();
	int iKey = iRow + 1;

	const char* pszFile = QuerySeasonPlanFile();
	if(!pszFile)
	{
		return;
	}
	
	MapSeasonSum::iterator itSeasonSum = m_MapSeasonSum.find(m_iSeason);
	if(itSeasonSum == m_MapSeasonSum.end())
	{
		return;
	}

	bool bResult = DataOperation::deletePlan(itSeasonSum->second, iKey); // 删除迭代器中的计划
	if(!bResult)
	{
		return;
	}

	FileOpration::UpdatePlanFile(pszFile, itSeasonSum->second); // 更新文件中的计划

	DataOperation::renewPlanItem(pszFile, itSeasonSum->second); // 更新迭代器

	LoadResource(pszFile);
}

/*--------------------------------------------------------------------
** 名称 : QueryQurrentKey
**--------------------------------------------------------------------
** 功能 :取出当前key
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
int seasonPlan::QueryQurrentKey()
{
	/*
	MapPlanSeason mapPlanSeason;
	switch(m_iSeason)
	{
		case E_SEASON_TYPE_SPRING:
			{
				MapSeasonSum::iterator itSeasonSum = m_MapSeasonSum.find(m_iSeason);
			}
			break;
		case E_SEASON_TYPE_SUMMER:
			{
			}
			break;
		case E_SEASON_TYPE_AUTUMN:
			{
			}
			break;
		case E_SEASON_TYPE_WINTER:
			{
			}
			break;
		default:
			break;
	}
	*/
	MapSeasonSum::iterator itSeasonSum = m_MapSeasonSum.find(m_iSeason);
	if(itSeasonSum == m_MapSeasonSum.end())
	{
		return 1;
	}

	MapItemPlan mapPlanSeason = itSeasonSum->second;
	int iKey = DataOperation::QueryPlanKey(mapPlanSeason);

	return iKey;
	
}
/*--------------------------------------------------------------------
** 名称 : SavePlanOnMap
**--------------------------------------------------------------------
** 功能 : 将计划保存到迭代器里
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
void seasonPlan::SavePlanOnMap(int iKey, QString&qstrPlan)
{
	MapSeasonSum::iterator itSeasonSum = m_MapSeasonSum.find(m_iSeason);
	if (itSeasonSum == m_MapSeasonSum.end())
	{
		MapPlanSeason mapPlanSeason;

		mapPlanSeason.insert(std::make_pair(iKey,qstrPlan));
		m_MapSeasonSum.insert(std::make_pair(m_iSeason, mapPlanSeason));
	}
	else
	{
		DataOperation::addPlan(itSeasonSum->second, iKey, qstrPlan); // 
	}

}

/*--------------------------------------------------------------------
** 名称 : QuerySeasonPlanFile
**--------------------------------------------------------------------
** 功能 : 获取季节文件
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.03		Mark
**-------------------------------------------------------------------*/
const char* seasonPlan::QuerySeasonPlanFile()
{
	const char* pszFile = D_SEASON_SPRING_PLAN_CONFIG;
	switch (m_iSeason)
	{
		case E_SEASON_TYPE_SPRING:
			{
				pszFile = D_SEASON_SPRING_PLAN_CONFIG;
			}
			break;
		case E_SEASON_TYPE_SUMMER:
			{
				pszFile = D_SEASON_SUMMER_PLAN_CONFIG;
			}
			break;
		case E_SEASON_TYPE_AUTUMN:
			{
				pszFile = D_SEASON_AUTUMN_PLAN_CONFIG;
			}
			break;
		case E_SEASON_TYPE_WINTER:
			{
				pszFile = D_SEASON_WINTER_PLAN_CONFIG;
			}
			break;

	default:
		break;
	}

	if(!pszFile)
	{
		return "";
	}
	return pszFile;
}
