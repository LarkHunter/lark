/********************************************************************************
** Form generated from reading UI file 'BackendGuI.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKENDGUI_H
#define UI_BACKENDGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackendGuIClass
{
public:
    QWidget *centralWidget;
    QPushButton *confirmBtn;
    QPushButton *resetBtn;
    QLineEdit *accountEdit;
    QLineEdit *pwdEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *yearPlanBtn;
    QPushButton *seasonPlanBtn;
    QPushButton *monthPlanBtn;
    QLabel *label;
    QLabel *label_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *BackendGuIClass)
    {
        if (BackendGuIClass->objectName().isEmpty())
            BackendGuIClass->setObjectName(QStringLiteral("BackendGuIClass"));
        BackendGuIClass->resize(600, 400);
        BackendGuIClass->setMinimumSize(QSize(600, 400));
        BackendGuIClass->setMaximumSize(QSize(600, 400));
        centralWidget = new QWidget(BackendGuIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        confirmBtn = new QPushButton(centralWidget);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(300, 300, 75, 23));
        resetBtn = new QPushButton(centralWidget);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));
        resetBtn->setGeometry(QRect(400, 300, 75, 23));
        accountEdit = new QLineEdit(centralWidget);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setGeometry(QRect(330, 220, 141, 20));
        pwdEdit = new QLineEdit(centralWidget);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setGeometry(QRect(330, 250, 141, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 35, 133, 167));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        yearPlanBtn = new QPushButton(layoutWidget);
        yearPlanBtn->setObjectName(QStringLiteral("yearPlanBtn"));
        yearPlanBtn->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(yearPlanBtn);

        seasonPlanBtn = new QPushButton(layoutWidget);
        seasonPlanBtn->setObjectName(QStringLiteral("seasonPlanBtn"));
        seasonPlanBtn->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(seasonPlanBtn);

        monthPlanBtn = new QPushButton(layoutWidget);
        monthPlanBtn->setObjectName(QStringLiteral("monthPlanBtn"));
        monthPlanBtn->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(monthPlanBtn);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 216, 41, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 245, 31, 21));
        BackendGuIClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(BackendGuIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BackendGuIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BackendGuIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BackendGuIClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(BackendGuIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        BackendGuIClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(BackendGuIClass);

        QMetaObject::connectSlotsByName(BackendGuIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BackendGuIClass)
    {
        BackendGuIClass->setWindowTitle(QApplication::translate("BackendGuIClass", "BackendGuI", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("BackendGuIClass", "\347\241\256\345\256\232", Q_NULLPTR));
        resetBtn->setText(QApplication::translate("BackendGuIClass", "\351\207\215\347\275\256", Q_NULLPTR));
        yearPlanBtn->setText(QApplication::translate("BackendGuIClass", "\345\271\264\345\272\246\350\256\241\345\210\222", Q_NULLPTR));
        seasonPlanBtn->setText(QApplication::translate("BackendGuIClass", "\345\255\243\350\212\202\350\256\241\345\210\222", Q_NULLPTR));
        monthPlanBtn->setText(QApplication::translate("BackendGuIClass", "\346\234\210\350\256\241\345\210\222", Q_NULLPTR));
        label->setText(QApplication::translate("BackendGuIClass", "\350\264\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("BackendGuIClass", "\345\257\206\347\240\201", Q_NULLPTR));
        menu->setTitle(QApplication::translate("BackendGuIClass", "\347\245\236\345\245\207\346\265\267\350\236\272\345\271\264\345\272\246\350\256\241\345\210\222\347\256\241\347\220\206\345\231\250 ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BackendGuIClass: public Ui_BackendGuIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKENDGUI_H
