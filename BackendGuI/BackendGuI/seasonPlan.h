#pragma once

#include <QWidget>
#include "ui_seasonPlan.h"
#include "DataOpration/DataOperation.h"
#include "FileOpration/FileOpration.h"

#include <set>
#include <map>

typedef std::map<int, QString> MapPlanSeason; // 迭代器，保存的每月的计划

typedef std::map<int, MapPlanSeason> MapSeasonSum;

class seasonPlan : public QWidget
{
	Q_OBJECT

public:
	seasonPlan(QWidget *parent = Q_NULLPTR);
	~seasonPlan();

public:

	// 把计划显示到List控件上
	bool ShowListWidget(const char* pszPlancfg);

	// 加载资源
	bool LoadResource(const char* pszPlancfg); 

	// 初始化计划
	bool InitListWidget(QString& qstrInfo); // 初始化planlist

	// 更新计划
	bool UpdateListWidget(QString& qstrInfo);

public slots:

	// 春季
	void onSpringBtnclicked();
	
	// 夏季
	void onSummerBtnclicked();

	// 秋季
	void onAutumnBtnclicked();

	// 冬季
	void onWinterBtnclicked();

	// 新增
	void onAddBtnclicked();

	// 删除
	void onDeletePlan();
public:
	
	// 取出当前key
	int  QueryQurrentKey();

	// 保存到迭代器里面
	void SavePlanOnMap(int iKey,QString&qstrPlan);

	// 取得当前文件
	const char* QuerySeasonPlanFile();
public:
	std::set<int> m_iSetItem;

	MapSeasonSum m_MapSeasonSum; // 季节总计划
private:
	int m_iSeason;
private:
	Ui::seasonPlan ui;

};
