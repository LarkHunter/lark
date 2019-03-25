/********************************************************************************
** Form generated from reading UI file 'monthplan.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTHPLAN_H
#define UI_MONTHPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monthPlan
{
public:
    QListWidget *monthListWidget;
    QPushButton *JanBtn;
    QPushButton *MayBtn;
    QPushButton *JulBtn;
    QPushButton *NovBtn;
    QPushButton *SepBtn;
    QPushButton *MarBtn;
    QPushButton *FebBtn;
    QPushButton *JunBtn;
    QPushButton *AprBtn;
    QPushButton *AugBtn;
    QPushButton *OctBtn;
    QPushButton *DecBtn;
    QLineEdit *planLineEdit;
    QLineEdit *numEdit;
    QPushButton *addBtn;

    void setupUi(QWidget *monthPlan)
    {
        if (monthPlan->objectName().isEmpty())
            monthPlan->setObjectName(QStringLiteral("monthPlan"));
        monthPlan->resize(613, 480);
        monthPlan->setMinimumSize(QSize(613, 480));
        monthPlan->setMaximumSize(QSize(613, 480));
        monthListWidget = new QListWidget(monthPlan);
        monthListWidget->setObjectName(QStringLiteral("monthListWidget"));
        monthListWidget->setGeometry(QRect(40, 30, 351, 271));
        JanBtn = new QPushButton(monthPlan);
        JanBtn->setObjectName(QStringLiteral("JanBtn"));
        JanBtn->setGeometry(QRect(430, 50, 75, 23));
        MayBtn = new QPushButton(monthPlan);
        MayBtn->setObjectName(QStringLiteral("MayBtn"));
        MayBtn->setGeometry(QRect(430, 130, 75, 23));
        JulBtn = new QPushButton(monthPlan);
        JulBtn->setObjectName(QStringLiteral("JulBtn"));
        JulBtn->setGeometry(QRect(430, 170, 75, 23));
        NovBtn = new QPushButton(monthPlan);
        NovBtn->setObjectName(QStringLiteral("NovBtn"));
        NovBtn->setGeometry(QRect(430, 250, 75, 23));
        SepBtn = new QPushButton(monthPlan);
        SepBtn->setObjectName(QStringLiteral("SepBtn"));
        SepBtn->setGeometry(QRect(430, 210, 75, 23));
        MarBtn = new QPushButton(monthPlan);
        MarBtn->setObjectName(QStringLiteral("MarBtn"));
        MarBtn->setGeometry(QRect(430, 90, 75, 23));
        FebBtn = new QPushButton(monthPlan);
        FebBtn->setObjectName(QStringLiteral("FebBtn"));
        FebBtn->setGeometry(QRect(530, 50, 75, 23));
        JunBtn = new QPushButton(monthPlan);
        JunBtn->setObjectName(QStringLiteral("JunBtn"));
        JunBtn->setGeometry(QRect(530, 130, 75, 23));
        AprBtn = new QPushButton(monthPlan);
        AprBtn->setObjectName(QStringLiteral("AprBtn"));
        AprBtn->setGeometry(QRect(530, 90, 75, 23));
        AugBtn = new QPushButton(monthPlan);
        AugBtn->setObjectName(QStringLiteral("AugBtn"));
        AugBtn->setGeometry(QRect(530, 170, 75, 23));
        OctBtn = new QPushButton(monthPlan);
        OctBtn->setObjectName(QStringLiteral("OctBtn"));
        OctBtn->setGeometry(QRect(530, 210, 75, 23));
        DecBtn = new QPushButton(monthPlan);
        DecBtn->setObjectName(QStringLiteral("DecBtn"));
        DecBtn->setGeometry(QRect(530, 250, 75, 23));
        planLineEdit = new QLineEdit(monthPlan);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));
        planLineEdit->setGeometry(QRect(180, 400, 271, 20));
        numEdit = new QLineEdit(monthPlan);
        numEdit->setObjectName(QStringLiteral("numEdit"));
        numEdit->setGeometry(QRect(50, 400, 101, 20));
        addBtn = new QPushButton(monthPlan);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(480, 400, 75, 23));

        retranslateUi(monthPlan);

        QMetaObject::connectSlotsByName(monthPlan);
    } // setupUi

    void retranslateUi(QWidget *monthPlan)
    {
        monthPlan->setWindowTitle(QApplication::translate("monthPlan", "monthPlan", Q_NULLPTR));
        JanBtn->setText(QApplication::translate("monthPlan", "\344\270\200\346\234\210", Q_NULLPTR));
        MayBtn->setText(QApplication::translate("monthPlan", "\344\272\224\346\234\210", Q_NULLPTR));
        JulBtn->setText(QApplication::translate("monthPlan", "\344\270\203\346\234\210", Q_NULLPTR));
        NovBtn->setText(QApplication::translate("monthPlan", "\345\215\201\344\270\200\346\234\210", Q_NULLPTR));
        SepBtn->setText(QApplication::translate("monthPlan", "\344\271\235\346\234\210", Q_NULLPTR));
        MarBtn->setText(QApplication::translate("monthPlan", "\344\270\211\346\234\210", Q_NULLPTR));
        FebBtn->setText(QApplication::translate("monthPlan", "\344\272\214\346\234\210", Q_NULLPTR));
        JunBtn->setText(QApplication::translate("monthPlan", "\345\205\255\346\234\210", Q_NULLPTR));
        AprBtn->setText(QApplication::translate("monthPlan", "\345\233\233\346\234\210", Q_NULLPTR));
        AugBtn->setText(QApplication::translate("monthPlan", "\345\205\253\346\234\210", Q_NULLPTR));
        OctBtn->setText(QApplication::translate("monthPlan", "\345\215\201\346\234\210", Q_NULLPTR));
        DecBtn->setText(QApplication::translate("monthPlan", "\345\215\201\344\272\214\346\234\210", Q_NULLPTR));
        addBtn->setText(QApplication::translate("monthPlan", "\346\226\260\345\242\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class monthPlan: public Ui_monthPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTHPLAN_H
