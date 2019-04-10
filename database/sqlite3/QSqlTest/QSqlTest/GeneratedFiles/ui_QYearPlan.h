/********************************************************************************
** Form generated from reading UI file 'QYearPlan.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QYEARPLAN_H
#define UI_QYEARPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QYearPlan
{
public:

    void setupUi(QWidget *QYearPlan)
    {
        if (QYearPlan->objectName().isEmpty())
            QYearPlan->setObjectName(QStringLiteral("QYearPlan"));
        QYearPlan->resize(400, 300);

        retranslateUi(QYearPlan);

        QMetaObject::connectSlotsByName(QYearPlan);
    } // setupUi

    void retranslateUi(QWidget *QYearPlan)
    {
        QYearPlan->setWindowTitle(QApplication::translate("QYearPlan", "QYearPlan", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QYearPlan: public Ui_QYearPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QYEARPLAN_H
