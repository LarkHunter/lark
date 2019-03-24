#ifndef YEARPLANDIALOG_H
#define YEARPLANDIALOG_H

#include <QWidget>
#include "ui_yearplandialog.h"
#include <QFile>

#include<set>

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

public:
	std::set<int> m_iSetItem;

private:
	Ui::YearPlanDialog ui;
};

#endif // YEARPLANDIALOG_H
