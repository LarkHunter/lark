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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YearPlanDialog
{
public:
    QPushButton *addButton;
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *planLineEdit;

    void setupUi(QWidget *YearPlanDialog)
    {
        if (YearPlanDialog->objectName().isEmpty())
            YearPlanDialog->setObjectName(QStringLiteral("YearPlanDialog"));
        YearPlanDialog->resize(757, 581);
        YearPlanDialog->setMinimumSize(QSize(757, 581));
        YearPlanDialog->setMaximumSize(QSize(757, 581));
        addButton = new QPushButton(YearPlanDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(610, 470, 75, 31));
        addButton->setMinimumSize(QSize(75, 31));
        addButton->setMaximumSize(QSize(75, 31));
        listWidget = new QListWidget(YearPlanDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(80, 40, 631, 321));
        widget = new QWidget(YearPlanDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 470, 553, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        planLineEdit = new QLineEdit(widget);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));
        planLineEdit->setMinimumSize(QSize(470, 31));
        planLineEdit->setMaximumSize(QSize(470, 31));

        horizontalLayout->addWidget(planLineEdit);


        retranslateUi(YearPlanDialog);

        QMetaObject::connectSlotsByName(YearPlanDialog);
    } // setupUi

    void retranslateUi(QWidget *YearPlanDialog)
    {
        YearPlanDialog->setWindowTitle(QApplication::translate("YearPlanDialog", "YearPlanDialog", Q_NULLPTR));
        addButton->setText(QApplication::translate("YearPlanDialog", "\346\226\260\345\242\236\350\256\241\345\210\222", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class YearPlanDialog: public Ui_YearPlanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEARPLANDIALOG_H
