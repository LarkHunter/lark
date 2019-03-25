#pragma once

#include <QWidget>
#include "ui_seasonPlan.h"

#include <set>

class seasonPlan : public QWidget
{
	Q_OBJECT

public:
	seasonPlan(QWidget *parent = Q_NULLPTR);
	~seasonPlan();

public:
	bool LoadResource(const char* pszPlancfg); // 加载资源

	bool InitListWidget(QString& qstrInfo); // 初始化planlist

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
public:
	std::set<int> m_iSetItem;
private:
	int m_iSeason;
private:
	Ui::seasonPlan ui;

};
