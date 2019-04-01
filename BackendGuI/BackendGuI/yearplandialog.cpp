#include "yearplandialog.h"
#include<QDebug>
#include <QMessageBox>

#define D_YEAR_PLAN "yearPlan.txt"
YearPlanDialog::YearPlanDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_cTimer = new QTimer(this);

	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺 "));
	this->setWindowIcon(QIcon("wheet.png"));

	connect(ui.addButton,SIGNAL(clicked()),this,SLOT(onAddPlanBtnclicked()));

	bool bResult = connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onDoubleClickedDelete()));

	bResult = connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),this, SLOT(onDoubleClickedDelete()));

	connect(m_cTimer,SIGNAL(timeout()),this,SLOT(onTimeOut()));

	ui.listWidget->setSortingEnabled(true); // 自动排序

	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺年计划 "));
	this->setWindowIcon(QIcon("wheet.png"));

	m_nClickTimes = 0;

	LoadResource();
}

YearPlanDialog::~YearPlanDialog()
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
** 19.03.24		Mark
**-------------------------------------------------------------------*/
bool YearPlanDialog::LoadResource()
{

	QFile file(D_YEAR_PLAN);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	QTextStream in(&file);
	in.setCodec("UTF-8");
	
	if(in.atEnd())
	{
		ui.listWidget->clear();
		
		m_mapItemYearPlan.clear();

		return false;
	}

	while(!in.atEnd()) 
	{
		QString line = in.readLine();

		InitListWidget(line);
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
** 19.03.24		Mark
**-------------------------------------------------------------------*/
bool YearPlanDialog::InitListWidget(QString& qstrInfo)
{
	if(qstrInfo.isEmpty())
	{
		return false;
	}
	QStringList list = qstrInfo.split(":");

	QString qstrNumber = list[0]; 
	QString qstrText = list[1]; 

	int iKey = qstrNumber.toInt();

	m_mapItemYearPlan.insert(std::make_pair(iKey,qstrText));
// 	bool bExist = DataOperation::isPlanExist(m_mapItemYearPlan, iKey);
// 	if(bExist)
// 	{
// 		QString QsTitle = QString::fromLocal8Bit("重复");
// 		QString QsContent = QString::fromLocal8Bit("当前序号的计划已经存在");
// 		QMessageBox::about(NULL, QsTitle, QsContent);
// 
// 		return false;
// 	}
	
	ui.listWidget->insertItem(0, qstrInfo);

	return true;
}

/*--------------------------------------------------------------------
** 名称 : onAddPlanBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:新增计划
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.03.24		Mark
**-------------------------------------------------------------------*/
void YearPlanDialog::onAddPlanBtnclicked()
{
	QString qsPlan = ui.planLineEdit->text();

	int iKey = DataOperation::QueryPlanKey(m_mapItemYearPlan);

	bool bData = DataOperation::addPlan(m_mapItemYearPlan, iKey, qsPlan); // 保存到迭代器里面
	if (!bData)
	{
		return;
	}

	QString qstrPlan;
	qstrPlan = QString::number(iKey);

	qstrPlan.append(":");
	qstrPlan.append(qsPlan);

	qDebug() <<"qstrPlan"<< qstrPlan;

	ui.listWidget->insertItem(0, qstrPlan); // 显示到界面上
	
	FileOpration::addPlanItem(D_YEAR_PLAN, qstrPlan); // 保存到文件里面

	ui.planLineEdit->clear();
}

void YearPlanDialog::onPlanWidgetBtnclicked()
{
	m_nClickTimes += 1;

	qDebug() << "PlanWidgetBtnclicked ...";
	m_cTimer->start(200);
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
** 19.04.01		Mark
**-------------------------------------------------------------------*/
void YearPlanDialog::onDoubleClickedDelete()
{
	int iRow = ui.listWidget->currentRow();
	int iKey = iRow + 1;

	DataOperation::deletePlan(m_mapItemYearPlan,iKey); // 删除迭代器中的计划

	FileOpration::UpdatePlanFile(D_YEAR_PLAN,m_mapItemYearPlan); // 更新文件中的计划

	DataOperation::renewPlanItem(D_YEAR_PLAN, m_mapItemYearPlan); // 更新迭代器

	LoadResource(); // 加载资源

	qDebug() << "iRow = "<< iRow<< endl;
}

/*--------------------------------------------------------------------
** 名称 : onTimeOut
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数:定时器超时响应
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 19.03.30		Mark
**-------------------------------------------------------------------*/
void YearPlanDialog::onTimeOut()
{
	m_cTimer->stop();
	if (1 == m_nClickTimes) {
		qDebug() << "click event" << endl;
		//TODO Click respond.
	}
	else if (2 == m_nClickTimes) {
		qDebug() << "double click event" << endl;
		//TODO Double click respond.
	}
	m_nClickTimes = 0;
}
