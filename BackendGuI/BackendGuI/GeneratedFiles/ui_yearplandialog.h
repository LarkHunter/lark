/********************************************************************************
** Form generated from reading UI file 'yearplandialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YEARPLANDIALOG_H
#define UI_YEARPLANDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YearPlanDialog
{
public:

    void setupUi(QWidget *YearPlanDialog)
    {
        if (YearPlanDialog->objectName().isEmpty())
            YearPlanDialog->setObjectName(QStringLiteral("YearPlanDialog"));
        YearPlanDialog->resize(757, 581);
        YearPlanDialog->setMinimumSize(QSize(757, 581));
        YearPlanDialog->setMaximumSize(QSize(757, 581));

        retranslateUi(YearPlanDialog);

        QMetaObject::connectSlotsByName(YearPlanDialog);
    } // setupUi

    void retranslateUi(QWidget *YearPlanDialog)
    {
        YearPlanDialog->setWindowTitle(QApplication::translate("YearPlanDialog", "YearPlanDialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class YearPlanDialog: public Ui_YearPlanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEARPLANDIALOG_H
