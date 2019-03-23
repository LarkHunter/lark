#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include "ui_BackendGuI.h"

class BackendGuI : public QMainWindow
{
	Q_OBJECT

public:
	BackendGuI(QWidget *parent = Q_NULLPTR);
	
	public slots:
	void onAccountBtnclicked();

public:
	QPushButton *yearPlanButton = new QPushButton;

private:
	Ui::BackendGuIClass ui;
};
