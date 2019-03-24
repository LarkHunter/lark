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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YearPlanDialog
{
public:
    QLineEdit *planLineEdit;
    QPushButton *addButton;
    QLineEdit *numEdit;
    QListWidget *listWidget;

    void setupUi(QWidget *YearPlanDialog)
    {
        if (YearPlanDialog->objectName().isEmpty())
            YearPlanDialog->setObjectName(QStringLiteral("YearPlanDialog"));
        YearPlanDialog->resize(757, 581);
        YearPlanDialog->setMinimumSize(QSize(757, 581));
        YearPlanDialog->setMaximumSize(QSize(757, 581));
        planLineEdit = new QLineEdit(YearPlanDialog);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));
        planLineEdit->setGeometry(QRect(290, 480, 291, 31));
        addButton = new QPushButton(YearPlanDialog);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(610, 480, 121, 31));
        numEdit = new QLineEdit(YearPlanDialog);
        numEdit->setObjectName(QStringLiteral("numEdit"));
        numEdit->setGeometry(QRect(192, 480, 81, 31));
        listWidget = new QListWidget(YearPlanDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(80, 40, 631, 321));

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
