#ifndef LOGINWARN_H
#define LOGINWARN_H

#include <QWidget>
#include "ui_loginwarn.h"

class loginWarn : public QWidget
{
	Q_OBJECT

public:
	loginWarn(QWidget *parent = 0);
	~loginWarn();

private:
	Ui::loginWarn ui;
};

#endif // LOGINWARN_H
