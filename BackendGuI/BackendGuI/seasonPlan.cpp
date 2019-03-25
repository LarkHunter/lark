#include "seasonPlan.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

#define D_SEASON_SPRING_PLAN_CONFIG "springPlan.txt"
#define D_SEASON_SUMMER_PLAN_CONFIG "summerPlan.txt"
#define D_SEASON_AUTUMN_PLAN_CONFIG "autumnPlan.txt"
#define D_SEASON_WINTER_PLAN_CONFIG "winterPlan.txt"

//
enum E_SEASON_TYPE
{
	E_SEASON_TYPE_SPRING = 1,
	E_SEASON_TYPE_SUMMER = 2,
	E_SEASON_TYPE_AUTUMN = 3,
	E_SEASON_TYPE_WINTER = 4,
};

//autumnPlan winterPlan
seasonPlan::seasonPlan(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//connect(, SIGNAL(clicked()), this, SLOT(onAccountBtnclicked()));
	connect(ui.springBtn, SIGNAL(clicked()), this, SLOT(onSpringBtnclicked()));
	connect(ui.summerBtn, SIGNAL(clicked()), this, SLOT(onSummerBtnclicked()));
	connect(ui.autumnBtn, SIGNAL(clicked()), this, SLOT(onAutumnBtnclicked()));
	connect(ui.winterBtn, SIGNAL(clicked()), this, SLOT(onWinterBtnclicked()));

	connect(ui.addBtn, SIGNAL(clicked()), this, SLOT(onAddBtnclicked()));

	//connect(ui.add); //onAddBtnclicked addBtn
	ui.seasonlistWidget->setSortingEnabled(true); // 自动排序

	m_iSeason = 1;
}

seasonPlan::~seasonPlan()
{
}
/*--------------------------------------------------------------------
** 名称 : LoadResource
**--------------------------------------------------------------------
** 功能 : 加载资源
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.03.25		Mark
**-------------------------------------------------------------------*/
bool seasonPlan::LoadResource(const char* pszPlancfg)
{
	if(NULL == pszPlancfg)
	{
		return false;
	}

	QFile file(pszPlancfg);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	ui.seasonlistWidget->clear();

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

bool seasonPlan::InitListWidget(QString& qstrInfo)
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

	ui.seasonlistWidget->insertItem(iNumber, qstrInfo);

	return true;
}

void seasonPlan::onSpringBtnclicked()
{
	LoadResource(D_SEASON_SPRING_PLAN_CONFIG);
}

void seasonPlan::onSummerBtnclicked()
{
	LoadResource(D_SEASON_SUMMER_PLAN_CONFIG);
}

void seasonPlan::onAutumnBtnclicked()
{
	
	LoadResource(D_SEASON_AUTUMN_PLAN_CONFIG);
}

void seasonPlan::onWinterBtnclicked()
{
	LoadResource(D_SEASON_WINTER_PLAN_CONFIG);
}

void seasonPlan::onAddBtnclicked()
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
	ui.seasonlistWidget->insertItem(0, qstrPlan);

	m_iSetItem.insert(inumber); // 保存当前序号

	QFile fileout("yearPlan.txt");

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
