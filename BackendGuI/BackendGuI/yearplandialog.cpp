#include "yearplandialog.h"
#include<QDebug>
#include <QMessageBox>

YearPlanDialog::YearPlanDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_cTimer = new QTimer(this);

	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺 "));
	this->setWindowIcon(QIcon("wheet.png"));

	connect(ui.addButton,SIGNAL(clicked()),this,SLOT(onAddPlanBtnclicked()));

	bool bResult = connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onPlanWidgetBtnclicked()));

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

	QFile file("yearPlan.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return false;
	}

	QTextStream in(&file);
	in.setCodec("UTF-8");
	while(!in.atEnd()) 
	{
		QString line = in.readLine();

		InitListWidget(line);
		//process_line(line);
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

	int iNumber = qstrNumber.toInt();
	std::set<int>::iterator itSet = m_iSetItem.find(iNumber);
	if(itSet != m_iSetItem.end())
	{
		QString QsTitle = QString::fromLocal8Bit("重复");
		QString QsContent = QString::fromLocal8Bit("当前序号的计划已经存在");
		QMessageBox::about(NULL, QsTitle, QsContent);

		return false;
	}

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
	int inumber = ui.numEdit->text().toInt();
	QString qsPlan = ui.planLineEdit->text();

	// 验证当前序号是否存在
	std::set<int>::iterator itSet = m_iSetItem.find(inumber);
	if(itSet != m_iSetItem.end())
	{
		QString QsTitle = QString::fromLocal8Bit("重复");
		QString QsContent = QString::fromLocal8Bit("当前序号的计划已经存在");
		QMessageBox::about(NULL, QsTitle, QsContent);

		return ;
	}

	QString qstrPlan;
	qstrPlan = QString::number(inumber);

	qstrPlan.append(":");
	qstrPlan.append(qsPlan);

	qDebug() <<"qstrPlan"<< qstrPlan;
	ui.listWidget->insertItem(0, qstrPlan);

	m_iSetItem.insert(inumber); // 保存当前序号

	QFile fileout("yearPlan.txt");

	if(!fileout.open(QIODevice::Append | QIODevice::Text))
	{
		qDebug() << "Open failed";
		return;
	}	
	
	qstrPlan.append("\n");
	std::string strPlan = qstrPlan.toStdString();
	const char* pszPlan = strPlan.c_str();

	fileout.write(pszPlan);

	
	//ui.listWidget->scrollToBottom();
	//ui.listWidget->insertItem(0, QString::fromLocal8Bit("2、今年小目标:再花他一个亿"));
	//ui.listWidget->scrollToBottom();
	

	ui.numEdit->clear();
	ui.planLineEdit->clear();
}

void YearPlanDialog::onPlanWidgetBtnclicked()
{
	m_nClickTimes += 1;

	qDebug() << "PlanWidgetBtnclicked ...";
	m_cTimer->start(200);
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
