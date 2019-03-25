#include "loginwarn.h"

loginWarn::loginWarn(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

 	QPixmap *pixmap = new QPixmap("loginerror.png");
	pixmap->scaled(ui.label->size(), Qt::KeepAspectRatio);
	ui.label->setScaledContents(true);
 	ui.label->setPixmap(*pixmap);
}

loginWarn::~loginWarn()
{

}
