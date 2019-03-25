#ifndef MONTHPLAN_H
#define MONTHPLAN_H

#include <QWidget>
#include "ui_monthplan.h"
#include <set>

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

public:
	bool LoadResource(const char* pszPlancfg); // 加载资源

	bool InitListWidget(QString& qstrInfo); // 初始化planlist

private:
	Ui::monthPlan ui;

public:
	std::set<int> m_iSetItem;
private:
	int m_iMonth;
};

#endif // MONTHPLAN_H
