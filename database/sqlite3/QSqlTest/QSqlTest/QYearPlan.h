#pragma once

#include <QWidget>
#include "ui_QYearPlan.h"

class QYearPlan : public QWidget
{
	Q_OBJECT

public:
	QYearPlan(QWidget *parent = Q_NULLPTR);
	~QYearPlan();

private:
	Ui::QYearPlan ui;
};
