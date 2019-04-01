#ifndef YEARPLANDIALOG_H
#define YEARPLANDIALOG_H

#include <QWidget>
#include "ui_yearplandialog.h"
#include <QFile>
#include <QTimer>
#include <map>
#include "DataOpration/DataOperation.h"
#include "FileOpration/FileOpration.h"

/*---------------------------------------------------------------------------
** 类名 : YearPlanDialog
**---------------------------------------------------------------------------
** 功能 : 年计划
**---------------------------------------------------------------------------
** Date			Name
** 2019.04.01	Mark
**---------------------------------------------------------------------------*/
class YearPlanDialog : public QWidget
{
	Q_OBJECT

public:
	YearPlanDialog(QWidget *parent = 0);
	~YearPlanDialog();

public:
	bool LoadResource(); // 加载资源

	bool InitListWidget(QString& qstrInfo); // 初始化planlist

	public slots:

	// 新增计划
	void onAddPlanBtnclicked();

	// 单击修改(进行中)
	void onPlanWidgetBtnclicked();

	// 双击右键删除
	void onDoubleClickedDelete();

	// 超时
	void onTimeOut();
public:
	//std::set<int> m_iSetItem;

	MapItemPlan m_mapItemYearPlan;
	QTimer *m_cTimer;

private:
	Ui::YearPlanDialog ui;

private:
	int m_nClickTimes;

};

#endif // YEARPLANDIALOG_H
