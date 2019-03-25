#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QTimer>
#include "ui_BackendGuI.h"
#include "YearPlanDialog.h"
#include "loginwarn.h"
#include "seasonPlan.h"
#include "monthplan.h"
class BackendGuI : public QMainWindow
{
	Q_OBJECT

public:
	BackendGuI(QWidget *parent = Q_NULLPTR);
	
	public slots:
	void onAccountBtnclicked();
	void onResetBtnClicked(); // 重置
	void onYearPlanBtnclicked(); // 年度计划
	void onSeasonPlanBtnclicked(); // 季度计划
	void onMonthPlanBtnclicked(); // 每月计划

	void onTimeOut();

public:
	//QPushButton *yearPlanButton = new QPushButton;
	QTimer *m_cTimer;
	loginWarn m_loginWarn;

	YearPlanDialog yearPlanDialog; // 年度计划
	seasonPlan m_seasonPlanDiglog; //季度计划
	monthPlan m_monthPlanDialog; // 每月计划
private:
	int m_nClickTimes;

	int m_nErrorCount; // 密码可以重新输入的次数 
private:
	Ui::BackendGuIClass ui;
};
