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

	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(onAddBtnclicked()));

	ui.monthListWidget->setSortingEnabled(true); // 自动排序

	m_iMonth = E_MONTH_TYPE_JAN;
}

monthPlan::~monthPlan()
{

}

void monthPlan::onJanBtnclicked()
{
	qDebug() << "1..";
	LoadResource(D_JAN_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_JAN;
}

void monthPlan::onFebBtnclicked()
{
	qDebug() << "2..";
	LoadResource(D_FEB_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_FEB;
}

void monthPlan::onMarBtnclicked()
{
	qDebug() << "3..";
	LoadResource(D_MAR_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_MAR;
}

void monthPlan::onAprBtnclicked()
{
	qDebug() << "4..";
	LoadResource(D_APR_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_APR;
}

void monthPlan::onMayBtnclicked()
{
	qDebug() << "5..";
	LoadResource(D_MAY_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_MAY;

}

void monthPlan::onJunBtnclicked()
{
	qDebug() << "6..";
	LoadResource(D_JUN_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_JUN;
}

void monthPlan::onJulBtnclicked()
{
	qDebug() << "7..";
	LoadResource(D_JUL_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_JUL;
}

void monthPlan::onAugBtnclicked()
{
	qDebug() << "8..";
	LoadResource(D_AUG_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_AUG;
}

void monthPlan::onSepBtnclicked()
{
	qDebug() << "9..";
	LoadResource(D_SEP_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_SEP;
}

void monthPlan::onOctBtnclicked()
{
	qDebug() << "10..";
	LoadResource(D_OCT_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_OCT;
}

void monthPlan::onNovBtnclicked()
{
	qDebug() << "11..";
	LoadResource(D_NOV_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_NOV;
}

void monthPlan::onDecBtnclicked()
{
	qDebug() << "12..";
	LoadResource(D_DEV_PLAN_CONFIG);

	m_iMonth = E_MONTH_TYPE_DEC;
}

void monthPlan::onAddBtnclicked()
{
	int inumber = ui.numEdit->text().toInt();
	QString qsPlan = ui.planLineEdit->text();

	// 验证当前序号是否存在
	std::set<int>::iterator itSet = m_iSetItem.find(inumber);
	if (itSet != m_iSetItem.end())
	{
		QString QsTitle = QString::fromLocal8Bit("重复");
		QString QsContent = QString::fromLocal8Bit("当前序号的计划已经存在");
		QMessageBox::about(NULL, QsTitle, QsContent);

		return;
	}
	QString qstrPlan;
	qstrPlan = QString::number(inumber);

	qstrPlan.append(":");
	qstrPlan.append(qsPlan);

	qDebug() << "qstrPlan" << qstrPlan;
	ui.monthListWidget->insertItem(0, qstrPlan);

	m_iSetItem.insert(inumber); // 保存当前序号
	QString qsPath = "monthplan//";
	const char* pszFile = QuerySeasonPlanFile();
	if (!pszFile)
	{
		return;
	}

	qsPath.append(pszFile);
	QFile fileout(qsPath);

	if (!fileout.open(QIODevice::Append | QIODevice::Text))
	{
		qDebug() << "Open failed";
		return;
	}

	qstrPlan.append("\n");
	std::string strPlan = qstrPlan.toStdString();
	const char* pszPlan = strPlan.c_str();

	fileout.write(pszPlan);

	ui.numEdit->clear();
	ui.planLineEdit->clear();
}

bool monthPlan::LoadResource(const char* pszPlancfg)
{
	if (NULL == pszPlancfg)
	{
		return false;
	}

	QString qsPath = "monthplan\\";
	qsPath.append(pszPlancfg);
	QFile file(qsPath);
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

const char* monthPlan::QuerySeasonPlanFile()
{
	const char* pszFile;
	switch(m_iMonth)
	{
		case E_MONTH_TYPE_JAN:
			{
				pszFile = D_JAN_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_FEB:
			{
				pszFile = D_FEB_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_MAR:
			{
				pszFile = D_MAR_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_APR:
			{
				pszFile = D_APR_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_MAY:
			{
				pszFile = D_MAY_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_JUN:
			{
				pszFile = D_JUN_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_JUL:
			{
				pszFile = D_JUL_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_AUG:
			{
				pszFile = D_AUG_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_SEP:
			{
				pszFile = D_SEP_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_OCT:
			{
				pszFile = D_OCT_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_NOV:
			{
				pszFile = D_NOV_PLAN_CONFIG;
			}
			break;
		case E_MONTH_TYPE_DEC:
			{
				pszFile = D_DEV_PLAN_CONFIG;
			}
			break;
	default:
		break;
	}
	if(!pszFile)
	{
		return "";
	}
	return pszFile;
}
