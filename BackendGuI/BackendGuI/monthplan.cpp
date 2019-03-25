#include "monthplan.h"
#include <QIcon>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include "Define/monthPlanDefine.h"

monthPlan::monthPlan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺每月计划 "));
	this->setWindowIcon(QIcon("wheet.png"));

	connect(ui.JanBtn, SIGNAL(clicked()), this, SLOT(onJanBtnclicked())); // 
	connect(ui.FebBtn, SIGNAL(clicked()), this, SLOT(onFebBtnclicked()));
	connect(ui.MarBtn, SIGNAL(clicked()), this, SLOT(onMarBtnclicked()));

	connect(ui.AprBtn, SIGNAL(clicked()), this, SLOT(onAprBtnclicked()));
	connect(ui.MayBtn, SIGNAL(clicked()), this, SLOT(onMayBtnclicked()));
	connect(ui.JunBtn, SIGNAL(clicked()), this, SLOT(onJunBtnclicked()));

	//
	connect(ui.JulBtn, SIGNAL(clicked()), this, SLOT(onJulBtnclicked())); // 
	connect(ui.AugBtn, SIGNAL(clicked()), this, SLOT(onAugBtnclicked()));
	connect(ui.SepBtn, SIGNAL(clicked()), this, SLOT(onSepBtnclicked()));

	connect(ui.OctBtn, SIGNAL(clicked()), this, SLOT(onOctBtnclicked()));
	connect(ui.NovBtn, SIGNAL(clicked()), this, SLOT(onNovBtnclicked()));
	connect(ui.DecBtn, SIGNAL(clicked()), this, SLOT(onDecBtnclicked()));
	ui.monthListWidget->setSortingEnabled(true); // 自动排序

	m_iMonth = 1;
}

monthPlan::~monthPlan()
{

}

void monthPlan::onJanBtnclicked()
{
	qDebug() << "1..";
}

void monthPlan::onFebBtnclicked()
{
	qDebug() << "2..";
}

void monthPlan::onMarBtnclicked()
{
	qDebug() << "3..";
}

void monthPlan::onAprBtnclicked()
{
	qDebug() << "4..";
}

void monthPlan::onMayBtnclicked()
{
	qDebug() << "5..";
}

void monthPlan::onJunBtnclicked()
{
	qDebug() << "6..";
}

void monthPlan::onJulBtnclicked()
{
	qDebug() << "7..";
}

void monthPlan::onAugBtnclicked()
{
	qDebug() << "8..";
}

void monthPlan::onSepBtnclicked()
{
	qDebug() << "9..";
}

void monthPlan::onOctBtnclicked()
{
	qDebug() << "10..";
}

void monthPlan::onNovBtnclicked()
{
	qDebug() << "11..";
}

void monthPlan::onDecBtnclicked()
{
	qDebug() << "12..";
}

bool monthPlan::LoadResource(const char* pszPlancfg)
{
	if (NULL == pszPlancfg)
	{
		return false;
	}

	QFile file(pszPlancfg);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	ui.monthListWidget->clear();
	m_iSetItem.clear();

	QTextStream in(&file);
	in.setCodec("UTF-8");
	while (!in.atEnd())
	{
		QString line = in.readLine();

		InitListWidget(line);
		//process_line(line);
	}
	return true;
}

bool monthPlan::InitListWidget(QString& qstrInfo)
{
	QStringList list = qstrInfo.split(":");
	QString qstrNumber = list[0];
	QString qstrText = list[1];

	int iNumber = qstrNumber.toInt();
	std::set<int>::iterator itSet = m_iSetItem.find(iNumber);
	if (itSet != m_iSetItem.end())
	{
		QString QsTitle = QString::fromLocal8Bit("重复");
		QString QsContent = QString::fromLocal8Bit("当前序号的计划已经存在");
		QMessageBox::about(NULL, QsTitle, QsContent);

		return false;
	}

	ui.monthListWidget->insertItem(iNumber, qstrInfo);

	return true;
}
