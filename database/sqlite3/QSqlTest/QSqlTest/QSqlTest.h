#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QSqlTest.h"
#include "Service/QSqlService.h"
#include "QYearPlan.h"

class QSqlTest : public QMainWindow
{
	Q_OBJECT

public:
	QSqlTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QSqlTestClass ui;

public slots:

	// 槽函数:增加条目
	void onAddBtn(); 

	// 槽函数:查看
	void onReviewInfo();

public:

	static QSqlService *m_sqlService; // 数据库服务

	QYearPlan m_yearPlan; // 年计划
};
