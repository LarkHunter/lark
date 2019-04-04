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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *JanBtn;
    QPushButton *MarBtn;
    QPushButton *MayBtn;
    QPushButton *JulBtn;
    QPushButton *SepBtn;
    QPushButton *NovBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *FebBtn;
    QPushButton *AprBtn;
    QPushButton *JunBtn;
    QPushButton *AugBtn;
    QPushButton *OctBtn;
    QPushButton *DecBtn;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
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
        layoutWidget = new QWidget(monthPlan);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 50, 77, 170));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        JanBtn = new QPushButton(layoutWidget);
        JanBtn->setObjectName(QStringLiteral("JanBtn"));

        verticalLayout->addWidget(JanBtn);

        MarBtn = new QPushButton(layoutWidget);
        MarBtn->setObjectName(QStringLiteral("MarBtn"));

        verticalLayout->addWidget(MarBtn);

        MayBtn = new QPushButton(layoutWidget);
        MayBtn->setObjectName(QStringLiteral("MayBtn"));

        verticalLayout->addWidget(MayBtn);

        JulBtn = new QPushButton(layoutWidget);
        JulBtn->setObjectName(QStringLiteral("JulBtn"));

        verticalLayout->addWidget(JulBtn);

        SepBtn = new QPushButton(layoutWidget);
        SepBtn->setObjectName(QStringLiteral("SepBtn"));

        verticalLayout->addWidget(SepBtn);

        NovBtn = new QPushButton(layoutWidget);
        NovBtn->setObjectName(QStringLiteral("NovBtn"));

        verticalLayout->addWidget(NovBtn);

        layoutWidget1 = new QWidget(monthPlan);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(530, 50, 77, 170));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        FebBtn = new QPushButton(layoutWidget1);
        FebBtn->setObjectName(QStringLiteral("FebBtn"));

        verticalLayout_2->addWidget(FebBtn);

        AprBtn = new QPushButton(layoutWidget1);
        AprBtn->setObjectName(QStringLiteral("AprBtn"));

        verticalLayout_2->addWidget(AprBtn);

        JunBtn = new QPushButton(layoutWidget1);
        JunBtn->setObjectName(QStringLiteral("JunBtn"));

        verticalLayout_2->addWidget(JunBtn);

        AugBtn = new QPushButton(layoutWidget1);
        AugBtn->setObjectName(QStringLiteral("AugBtn"));

        verticalLayout_2->addWidget(AugBtn);

        OctBtn = new QPushButton(layoutWidget1);
        OctBtn->setObjectName(QStringLiteral("OctBtn"));

        verticalLayout_2->addWidget(OctBtn);

        DecBtn = new QPushButton(layoutWidget1);
        DecBtn->setObjectName(QStringLiteral("DecBtn"));

        verticalLayout_2->addWidget(DecBtn);

        layoutWidget2 = new QWidget(monthPlan);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 400, 355, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        planLineEdit = new QLineEdit(layoutWidget2);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));
        planLineEdit->setMinimumSize(QSize(0, 31));
        planLineEdit->setMaximumSize(QSize(16777215, 31));

        horizontalLayout->addWidget(planLineEdit);

        addBtn = new QPushButton(layoutWidget2);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setMinimumSize(QSize(0, 31));
        addBtn->setMaximumSize(QSize(16777215, 31));

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
