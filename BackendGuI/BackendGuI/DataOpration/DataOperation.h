#pragma once
#include <map>
#include <QString>
#include <QFile>
#include <QtCore/QTextStream>

typedef std::map<int, QString> MapItemPlan;
/*---------------------------------------------------------------------------
** 类名 : DataOperation
**---------------------------------------------------------------------------
** 功能 : 迭代器数据操作
**---------------------------------------------------------------------------
** Date			Name
** 2019.04.01	Mark
**---------------------------------------------------------------------------*/
class DataOperation
{
public:
	// 构造函数 
	DataOperation();

	// 析构函数
	~DataOperation();

public:

	// 新增计划
	static bool addPlan(MapItemPlan& mapPlan,int iKey,QString &qstrPlan);

	// 删除计划
	static bool deletePlan(MapItemPlan& mapPlan, int iKey);

	// 修改计划
	static bool modifyPlan(MapItemPlan& mapPlan, int iKey, QString &qstrPlan);

	// 判断当前计划是否存在
	static bool isPlanExist(MapItemPlan& mapPlan, int iKey);

	// 新增计划，获取Key
	static int QueryPlanKey(MapItemPlan& mapPlan);

	// 更新计划
	static bool renewPlanItem(const char* pszPlanFile,MapItemPlan& mapPlan);

private:
	
	// 更新迭代器中的计划
	static void renewPlanMap(QString& qstrInfo, MapItemPlan& mapPlan);
};