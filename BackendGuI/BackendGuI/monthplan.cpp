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
	bool bResult = connect(ui.monthListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onDoubleClickedDelete())); // 删除计划

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
/*--------------------------------------------------------------------
** 名称 : onAddBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:新增计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
void monthPlan::onAddBtnclicked()
{
	QString qsPlan = ui.planLineEdit->text();
	if (qsPlan.isEmpty())
	{
		return;
	}

	MapItemPlan mapMonthPlan;
	QueryQurrentMap(mapMonthPlan); // 取出当前计划迭代器

	int iKey = DataOperation::QueryPlanKey(mapMonthPlan);

	// 保存迭代器
// 	bool bData = DataOperation::addPlan(mapMonthPlan, iKey, qsPlan); // 保存到迭代器里面
// 	if (!bData)
// 	{
// 		return;
// 	}

	QString qstrPlan;
	qstrPlan = QString::number(iKey);

	qstrPlan.append(":");
	qstrPlan.append(qsPlan);

	qDebug() << "qstrPlan" << qstrPlan;
	const char* pszMonthFile = QuerySeasonPlanFile(); // 查询当前月文件

	ui.monthListWidget->insertItem(0, qstrPlan); // 显示到界面上

	FileOpration::addPlanItem(pszMonthFile, qstrPlan); // 保存到文件里面

	ui.planLineEdit->clear();
}
/*--------------------------------------------------------------------
** 名称 : onDoubleClickedDelete
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:删除计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
void monthPlan::onDoubleClickedDelete()
{
	int iRow = ui.monthListWidget->currentRow();
	int iKey = iRow + 1;

	MapItemPlan mapMonthPlan;
	QueryQurrentMap(mapMonthPlan); // 取出当前计划迭代器

	DataOperation::deletePlan(mapMonthPlan, iKey); // 删除迭代器中的计划

	const char* pszMonthFile = QuerySeasonPlanFile(); // 查询当前月文件

	FileOpration::UpdatePlanFile(pszMonthFile, mapMonthPlan); // 更新文件中的计划

	DataOperation::renewPlanItem(pszMonthFile, mapMonthPlan); // 更新迭代器

	LoadResource(pszMonthFile); // 加载资源
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
** 19.04.02		Mark
**-------------------------------------------------------------------*/
bool monthPlan::LoadResource(const char* pszPlancfg)
{
	if (NULL == pszPlancfg)
	{
		return false;
	}

	QString qsPath;
	qsPath.append(pszPlancfg);
	QFile file(qsPath);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	ui.monthListWidget->clear();

	MapItemPlan mapMonthPlan;

	QueryQurrentMap(mapMonthPlan); // 取出当前计划迭代器

	QTextStream in(&file);
	in.setCodec("UTF-8");
	while (!in.atEnd())
	{
		QString line = in.readLine();

		InitListWidget(line, mapMonthPlan);
	}
	return true;
}
/*--------------------------------------------------------------------
** 名称 : InitListWidget
**--------------------------------------------------------------------
** 功能 : 初始化list控件
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
bool monthPlan::InitListWidget(QString& qstrInfo, MapItemPlan& mapItemPlan)
{
	if (qstrInfo.isEmpty())
	{
		return false;
	}

	QStringList list = qstrInfo.split(":");
	
	QString qstrNumber = list[0];
	QString qstrText = list[1];

	int iKey = qstrNumber.toInt();
	
	mapItemPlan.insert(std::make_pair(iKey,qstrText));

	ui.monthListWidget->insertItem(0, qstrInfo);

	return true;
}
/*--------------------------------------------------------------------
** 名称 : QuerySeasonPlanFile
**--------------------------------------------------------------------
** 功能 : 获取当月计划的文件
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
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
/*--------------------------------------------------------------------
** 名称 : QueryQurrentMap
**--------------------------------------------------------------------
** 功能 : 取出当前迭代器
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
void monthPlan::QueryQurrentMap(MapItemPlan& mapItemPlan)
{
	switch(m_iMonth)
	{
		case E_MONTH_TYPE_JAN:
			{
				mapItemPlan = m_mapPlanJan;
			}
			break;
		case E_MONTH_TYPE_FEB:
			{
				mapItemPlan = m_mapPlanFeb;
			}
			break;
		case E_MONTH_TYPE_MAR:
			{
				mapItemPlan = m_mapPlanMar;
			}
			break;
		case E_MONTH_TYPE_APR:  // 4月
			{
				mapItemPlan = m_mapPlanApr;
			}
			break;
		case E_MONTH_TYPE_MAY:
			{
				mapItemPlan = m_mapPlanMay;
			}
			break;
		case E_MONTH_TYPE_JUN:
			{
				mapItemPlan = m_mapPlanJun;
			}
			break;
		case E_MONTH_TYPE_JUL:// 7月份
			{
				mapItemPlan = m_mapPlanJul;
			}
			break;
		case E_MONTH_TYPE_AUG:
			{
				mapItemPlan = m_mapPlanAug;
			}
			break;
		case E_MONTH_TYPE_SEP:
			{
				mapItemPlan = m_mapPlanSep;
			}
			break;
		case E_MONTH_TYPE_OCT: // 10月份
			{
				mapItemPlan = m_mapPlanOct;
			}
			break;
		case E_MONTH_TYPE_NOV:
			{
				mapItemPlan = m_mapPlanNov;
			}
			break;
		case E_MONTH_TYPE_DEC:
			{
				mapItemPlan = m_mapPlanDec;
			}
			break;
		default:
			break;
		}
}
/*--------------------------------------------------------------------
** 名称 : SaveMonthPlanMap
**--------------------------------------------------------------------
** 功能 : 保存月份迭代器
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.04.02		Mark
**-------------------------------------------------------------------*/
void monthPlan::SaveMonthPlanMap(int iKey,QString & qsPlan)
{
	switch (m_iMonth)
	{
		case E_MONTH_TYPE_JAN:
			{
				DataOperation::addPlan(m_mapPlanJan, iKey,qsPlan); // 保存到迭代器里面
			}
			break;
 		case E_MONTH_TYPE_FEB:
 			{
					DataOperation::addPlan(m_mapPlanFeb, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_MAR:
 			{
				DataOperation::addPlan(m_mapPlanMar, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_APR:  // 4月
 			{
				DataOperation::addPlan(m_mapPlanApr, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_MAY:
 			{
				DataOperation::addPlan(m_mapPlanMay, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_JUN:
 			{
 	
				DataOperation::addPlan(m_mapPlanJun, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_JUL:// 7月份
 			{
				DataOperation::addPlan(m_mapPlanJul, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_AUG:
 			{
				DataOperation::addPlan(m_mapPlanAug, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_SEP:
 			{
				DataOperation::addPlan(m_mapPlanSep, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_OCT: // 10月份
 			{
				DataOperation::addPlan(m_mapPlanOct, iKey, qsPlan); // 保存到迭代器里面

 			}
 			break;
 		case E_MONTH_TYPE_NOV:
 			{
				DataOperation::addPlan(m_mapPlanNov, iKey, qsPlan); // 保存到迭代器里面
 			}
 			break;
 		case E_MONTH_TYPE_DEC:
 			{
				DataOperation::addPlan(m_mapPlanDec, iKey, qsPlan); // 保存到迭代器里面

 			}
 			break;
		default:
			break;
	}
}
