#include "DataOperation.h"
/*--------------------------------------------------------------------
** 名称 : DataOpration
**--------------------------------------------------------------------
** 功能 : 构造函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
DataOperation::DataOperation()
{

}
/*--------------------------------------------------------------------
** 名称 : ~DataOperation
**--------------------------------------------------------------------
** 功能 : 析构函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
DataOperation::~DataOperation()
{

}

/*--------------------------------------------------------------------
** 名称 : addPlan
**--------------------------------------------------------------------
** 功能 : 新增计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool DataOperation::addPlan(MapItemPlan& mapPlan, int iKey, QString &qstrPlan)
{
	if(iKey <0)
	{
		return false;
	}

 	if(qstrPlan.isNull())
 	{
 		return false;
 	}

	mapPlan.insert(std::make_pair(iKey,qstrPlan));

	return true;
}
/*--------------------------------------------------------------------
** 名称 : deletePlan
**--------------------------------------------------------------------
** 功能 : 删除加护
**--------------------------------------------------------------------
** 参数 : mapPlan 计划迭代器
** 参数 : iKey 计划Key
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool DataOperation::deletePlan(MapItemPlan& mapPlan, int iKey)
{
	MapItemPlan::iterator itMapFind = mapPlan.find(iKey);
	if(itMapFind == mapPlan.end())
	{
		return false;
	}

	MapItemPlan::iterator itMap = mapPlan.begin();

	for(; itMap != mapPlan.end(); )
	{
		if(iKey == itMap->first)
		{
			mapPlan.erase(itMap++);
		}
		else
		{
			itMap++;
		}
	}

	return true;
}

/*--------------------------------------------------------------------
** 名称 : modifyPlan
**--------------------------------------------------------------------
** 功能 : 修改计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool DataOperation::modifyPlan(MapItemPlan& mapPlan, int iKey, QString &qstrPlan)
{
	MapItemPlan::iterator itMapPlan = mapPlan.find(iKey);
	if(itMapPlan == mapPlan.end())
	{
		return false;
	}

	itMapPlan->second = qstrPlan;

	return true;
}
/*--------------------------------------------------------------------
** 名称 : isPlanExist
**--------------------------------------------------------------------
** 功能 : 判断当前计划是否存在
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool DataOperation::isPlanExist(MapItemPlan& mapPlan, int iKey)
{
	MapItemPlan::iterator itMapPlan = mapPlan.find(iKey);
	if(itMapPlan == mapPlan.end())
	{
		return false;
	}

	return true;
}
/*--------------------------------------------------------------------
** 名称 : QueryPlanKey
**--------------------------------------------------------------------
** 功能 : 新增计划、获取Key
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
int DataOperation::QueryPlanKey(MapItemPlan& mapPlan)
{
	int iSize = mapPlan.size();
	
	int iKey = iSize + 1;

	return iKey;
}

/*--------------------------------------------------------------------
** 名称 : renewPlanItem
**--------------------------------------------------------------------
** 功能 : 更新计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
bool DataOperation::renewPlanItem(const char* pszPlanFile, MapItemPlan& mapPlan)
{
	mapPlan.clear();

	if(!pszPlanFile)
	{
		return false;
	}

	QFile file(pszPlanFile);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	QTextStream in(&file);
	in.setCodec("UTF-8");
	while(!in.atEnd())
	{
		QString line = in.readLine();

		renewPlanMap(line, mapPlan); // 更新计划

	}

	return true;
}
/*--------------------------------------------------------------------
** 名称 : renewPlanMap
**--------------------------------------------------------------------
** 功能 : 更新计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.1		Mark
**-------------------------------------------------------------------*/
void DataOperation::renewPlanMap(QString& qstrInfo, MapItemPlan& mapPlan)
{

	QStringList list = qstrInfo.split(":");

	QString qstrKey = list[0];
	QString qstrText = list[1];

	int iKey = qstrKey.toInt();
	
	MapItemPlan::iterator itMap = mapPlan.find(iKey);
	if(itMap != mapPlan.end())
	{
		itMap->second = qstrText;
	}

	mapPlan.insert(std::make_pair(iKey,qstrText));
}
