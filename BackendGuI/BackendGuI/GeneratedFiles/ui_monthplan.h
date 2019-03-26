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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monthPlan
{
public:
    QListWidget *monthListWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *JanBtn;
    QPushButton *MarBtn;
    QPushButton *MayBtn;
    QPushButton *JulBtn;
    QPushButton *SepBtn;
    QPushButton *NovBtn;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *FebBtn;
    QPushButton *AprBtn;
    QPushButton *JunBtn;
    QPushButton *AugBtn;
    QPushButton *OctBtn;
    QPushButton *DecBtn;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *numEdit;
    QLineEdit *planLineEdit;
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
        widget = new QWidget(monthPlan);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(430, 50, 77, 170));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        JanBtn = new QPushButton(widget);
        JanBtn->setObjectName(QStringLiteral("JanBtn"));

        verticalLayout->addWidget(JanBtn);

        MarBtn = new QPushButton(widget);
        MarBtn->setObjectName(QStringLiteral("MarBtn"));

        verticalLayout->addWidget(MarBtn);

        MayBtn = new QPushButton(widget);
        MayBtn->setObjectName(QStringLiteral("MayBtn"));

        verticalLayout->addWidget(MayBtn);

        JulBtn = new QPushButton(widget);
        JulBtn->setObjectName(QStringLiteral("JulBtn"));

        verticalLayout->addWidget(JulBtn);

        SepBtn = new QPushButton(widget);
        SepBtn->setObjectName(QStringLiteral("SepBtn"));

        verticalLayout->addWidget(SepBtn);

        NovBtn = new QPushButton(widget);
        NovBtn->setObjectName(QStringLiteral("NovBtn"));

        verticalLayout->addWidget(NovBtn);

        widget1 = new QWidget(monthPlan);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(530, 50, 77, 170));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        FebBtn = new QPushButton(widget1);
        FebBtn->setObjectName(QStringLiteral("FebBtn"));

        verticalLayout_2->addWidget(FebBtn);

        AprBtn = new QPushButton(widget1);
        AprBtn->setObjectName(QStringLiteral("AprBtn"));

        verticalLayout_2->addWidget(AprBtn);

        JunBtn = new QPushButton(widget1);
        JunBtn->setObjectName(QStringLiteral("JunBtn"));

        verticalLayout_2->addWidget(JunBtn);

        AugBtn = new QPushButton(widget1);
        AugBtn->setObjectName(QStringLiteral("AugBtn"));

        verticalLayout_2->addWidget(AugBtn);

        OctBtn = new QPushButton(widget1);
        OctBtn->setObjectName(QStringLiteral("OctBtn"));

        verticalLayout_2->addWidget(OctBtn);

        DecBtn = new QPushButton(widget1);
        DecBtn->setObjectName(QStringLiteral("DecBtn"));

        verticalLayout_2->addWidget(DecBtn);

        widget2 = new QWidget(monthPlan);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(50, 400, 355, 25));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        numEdit = new QLineEdit(widget2);
        numEdit->setObjectName(QStringLiteral("numEdit"));

        horizontalLayout->addWidget(numEdit);

        planLineEdit = new QLineEdit(widget2);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));

        horizontalLayout->addWidget(planLineEdit);

        addBtn = new QPushButton(widget2);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);


        retranslateUi(monthPlan);

        QMetaObject::connectSlotsByName(monthPlan);
    } // setupUi

    void retranslateUi(QWidget *monthPlan)
    {
        monthPlan->setWindowTitle(QApplication::translate("monthPlan", "monthPlan", Q_NULLPTR));
        JanBtn->setText(QApplication::translate("monthPlan", "\344\270\200\346\234\210", Q_NULLPTR));
        MarBtn->setText(QApplication::translate("monthPlan", "\344\270\211\346\234\210", Q_NULLPTR));
        MayBtn->setText(QApplication::translate("monthPlan", "\344\272\224\346\234\210", Q_NULLPTR));
        JulBtn->setText(QApplication::translate("monthPlan", "\344\270\203\346\234\210", Q_NULLPTR));
        SepBtn->setText(QApplication::translate("monthPlan", "\344\271\235\346\234\210", Q_NULLPTR));
        NovBtn->setText(QApplication::translate("monthPlan", "\345\215\201\344\270\200\346\234\210", Q_NULLPTR));
        FebBtn->setText(QApplication::translate("monthPlan", "\344\272\214\346\234\210", Q_NULLPTR));
        AprBtn->setText(QApplication::translate("monthPlan", "\345\233\233\346\234\210", Q_NULLPTR));
        JunBtn->setText(QApplication::translate("monthPlan", "\345\205\255\346\234\210", Q_NULLPTR));
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
