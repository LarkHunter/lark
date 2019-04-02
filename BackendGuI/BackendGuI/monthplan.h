#ifndef MONTHPLAN_H
#define MONTHPLAN_H

#include <QWidget>
#include "ui_monthplan.h"
#include "DataOpration/DataOperation.h"
#include "FileOpration/FileOpration.h"

class monthPlan : public QWidget
{
	Q_OBJECT

public:
	monthPlan(QWidget *parent = 0);
	~monthPlan();

	public slots:
	
	// 一月
	void onJanBtnclicked();

	// 二月
	void onFebBtnclicked();

	// 三月
	void onMarBtnclicked();

	// 四月
	void onAprBtnclicked();

	// 五月
	void onMayBtnclicked();

	// 六月
	void onJunBtnclicked();

	// 七月
	void onJulBtnclicked();

	// 八月
	void onAugBtnclicked();

	// 九月
	void onSepBtnclicked();

	// 十月
	void onOctBtnclicked();

	// 十一月
	void onNovBtnclicked();

	// 十二月
	void onDecBtnclicked();

	// 新增
	void onAddBtnclicked();

	// 删除
	void onDoubleClickedDelete();

public:
	bool LoadResource(const char* pszPlancfg); // 加载资源

	bool InitListWidget(QString& qstrInfo, MapItemPlan& mapItemPlan); // 初始化planlist

	// 取得当前文件
	const char* QuerySeasonPlanFile();

	// 取得当前迭代器
	void QueryQurrentMap(MapItemPlan& mapItemPlan);

	// 保存到当前迭代器里面
	void SaveMonthPlanMap(int iKey,QString & qstrPlan);

private:
	Ui::monthPlan ui;

public:

	//MapItemPlan m_mapMonthPlan; //
	MapItemPlan m_mapPlanJan; // 1月计划 
	MapItemPlan m_mapPlanFeb; // 2月计划 
	MapItemPlan m_mapPlanMar; // 3月计划 

	MapItemPlan m_mapPlanApr; // 4月计划 
	MapItemPlan m_mapPlanMay; // 5月计划 
	MapItemPlan m_mapPlanJun; // 6月计划 

	MapItemPlan m_mapPlanJul; // 7月计划 
	MapItemPlan m_mapPlanAug; // 8月计划 
	MapItemPlan m_mapPlanSep; // 9月计划 

	MapItemPlan m_mapPlanOct; // 10月计划 
	MapItemPlan m_mapPlanNov; // 11月计划 
	MapItemPlan m_mapPlanDec; // 12月计划 
private:
	int m_iMonth;
};

#endif // MONTHPLAN_H
