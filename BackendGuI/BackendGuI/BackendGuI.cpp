#include "BackendGuI.h"
#include <QDebug>
BackendGuI::BackendGuI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.accountBtn->setStyleSheet("color:red");

	yearPlanButton->setGeometry(10, 10, 200, 200);

	connect(ui.accountBtn, SIGNAL(clicked()), this, SLOT(onAccountBtnclicked()));

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
** 18.06.28		任伟
**-------------------------------------------------------------------*/
void BackendGuI::onAccountBtnclicked()
{
	qDebug() << "..";
}
