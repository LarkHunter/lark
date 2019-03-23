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
    QPushButton *accountBtn;
    QPushButton *pwdBtn;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *yearPlanButton;
    QPushButton *seasonPlanBtn;
    QPushButton *Btn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *BackendGuIClass)
    {
        if (BackendGuIClass->objectName().isEmpty())
            BackendGuIClass->setObjectName(QStringLiteral("BackendGuIClass"));
        BackendGuIClass->resize(600, 400);
        centralWidget = new QWidget(BackendGuIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        accountBtn = new QPushButton(centralWidget);
        accountBtn->setObjectName(QStringLiteral("accountBtn"));
        accountBtn->setGeometry(QRect(350, 250, 75, 23));
        pwdBtn = new QPushButton(centralWidget);
        pwdBtn->setObjectName(QStringLiteral("pwdBtn"));
        pwdBtn->setGeometry(QRect(350, 290, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(450, 250, 101, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(450, 290, 101, 20));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 35, 133, 167));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        yearPlanButton = new QPushButton(widget);
        yearPlanButton->setObjectName(QStringLiteral("yearPlanButton"));
        yearPlanButton->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(yearPlanButton);

        seasonPlanBtn = new QPushButton(widget);
        seasonPlanBtn->setObjectName(QStringLiteral("seasonPlanBtn"));
        seasonPlanBtn->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(seasonPlanBtn);

        Btn = new QPushButton(widget);
        Btn->setObjectName(QStringLiteral("Btn"));
        Btn->setMinimumSize(QSize(131, 51));

        verticalLayout->addWidget(Btn);

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
        accountBtn->setText(QApplication::translate("BackendGuIClass", "\350\264\246\345\217\267", Q_NULLPTR));
        pwdBtn->setText(QApplication::translate("BackendGuIClass", "\345\257\206\347\240\201", Q_NULLPTR));
        yearPlanButton->setText(QApplication::translate("BackendGuIClass", "\345\271\264\345\272\246\350\256\241\345\210\222", Q_NULLPTR));
        seasonPlanBtn->setText(QApplication::translate("BackendGuIClass", "\345\255\243\350\212\202\350\256\241\345\210\222", Q_NULLPTR));
        Btn->setText(QApplication::translate("BackendGuIClass", "\346\234\210\350\256\241\345\210\222", Q_NULLPTR));
        menu->setTitle(QApplication::translate("BackendGuIClass", "\346\265\267\350\236\272\345\271\264\345\272\246\350\256\241\345\210\222\347\256\241\347\220\206\347\263\273\347\273\237 ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BackendGuIClass: public Ui_BackendGuIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKENDGUI_H
