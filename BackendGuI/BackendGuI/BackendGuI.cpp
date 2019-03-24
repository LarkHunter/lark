#include "BackendGuI.h"
#include <QDebug>
#include <QMessageBox>

BackendGuI::BackendGuI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.confirmBtn->setStyleSheet("color:red");

	//yearPlanButton->setGeometry(10, 10, 200, 200);
	this->setWindowTitle(QString::fromLocal8Bit("神奇海螺 "));
	//this->setWindowTitle(QString::fromUtf8("计划管理器@Mark "));
	this->setWindowIcon(QIcon("wheet.png"));

	m_nClickTimes = 0;

	m_cTimer = new QTimer(this);

	connect(ui.yearPlanBtn, SIGNAL(clicked()), this, SLOT(onYearPlanBtnclicked()));
	connect(ui.resetBtn, SIGNAL(clicked()),this,SLOT(onResetBtnClicked()));
	connect(ui.confirmBtn, SIGNAL(clicked()), this, SLOT(onAccountBtnclicked()));

	ui.yearPlanBtn->setEnabled(false);

	//connect(m_cTimer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
}
/*--------------------------------------------------------------------
** 名称 : onAccountBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 18.06.28		Mark
**-------------------------------------------------------------------*/
void BackendGuI::onAccountBtnclicked()
{
	qDebug() << "CWinButton::clicked" << endl;
	int iAccount = ui.accountEdit->text().toInt();
	int iPwd = ui.pwdEdit->text().toInt();
	if(1996 != iAccount ||
		1112 != iPwd)
	{
		ui.accountEdit->clear();
		ui.pwdEdit->clear();

		QString QsTitle = QString::fromLocal8Bit("警告！");
		QString QsContent = QString::fromLocal8Bit("不是本人登录，软件会崩溃！！");
		QMessageBox::about(NULL, QsTitle, QsContent);

	}
	ui.accountEdit->clear();
	ui.accountEdit->clear();
	//m_nClickTimes++;
	//m_cTimer->start(200);

	ui.yearPlanBtn->setEnabled(true);
	qDebug() << "..";
}

void BackendGuI::onResetBtnClicked()
{
	ui.accountEdit->clear();
	ui.pwdEdit->clear();
}

/*--------------------------------------------------------------------
** 名称 : onYearPlanBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 18.06.28		Mark
**-------------------------------------------------------------------*/
void BackendGuI::onYearPlanBtnclicked()
{
	qDebug() << "onYearPlanBtnclicked" << endl;
	yearPlanDialog.show();
}

/*--------------------------------------------------------------------
** 名称 : onConfirmBtnclicked
**--------------------------------------------------------------------
** 功能 : 事件响应槽函数
**--------------------------------------------------------------------
** 参数 : NULL
** 返值 : NULL
**--------------------------------------------------------------------
** Date:		Name
** 18.06.28		Mark
**-------------------------------------------------------------------*/
void BackendGuI::onTimeOut()
{
	//qDebug() << "...";
	qDebug() << "CWinButton::slotTimerTimeOut" << endl;
	m_cTimer->stop();
	if (1 == m_nClickTimes) {
		qDebug() << "click event" << endl;
		//TODO Click respond.
	}
	else if (2 == m_nClickTimes) {
		qDebug() << "double click event" << endl;
		//TODO Double click respond.
	}
	else if(3 == m_nClickTimes)
	{
		qDebug() << "Triple  click event" << endl;
	}
	m_nClickTimes = 0;

}
