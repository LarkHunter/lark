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
#include <QtWidgets/QHBoxLayout>
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
    QAction *action;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *yearPlanBtn;
    QPushButton *seasonPlanBtn;
    QPushButton *monthPlanBtn;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *accountEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *pwdEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *confirmBtn;
    QPushButton *resetBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuHL1_0;
    QMenu *menu_2;

    void setupUi(QMainWindow *BackendGuIClass)
    {
        if (BackendGuIClass->objectName().isEmpty())
            BackendGuIClass->setObjectName(QStringLiteral("BackendGuIClass"));
        BackendGuIClass->resize(600, 400);
        BackendGuIClass->setMinimumSize(QSize(600, 400));
        BackendGuIClass->setMaximumSize(QSize(600, 400));
        action = new QAction(BackendGuIClass);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(BackendGuIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(292, 241, 182, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(290, 216, 184, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(41, 20));
        label->setMaximumSize(QSize(41, 20));

        horizontalLayout->addWidget(label);

        accountEdit = new QLineEdit(layoutWidget2);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));

        horizontalLayout->addWidget(accountEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(41, 20));
        label_2->setMaximumSize(QSize(41, 20));

        horizontalLayout_3->addWidget(label_2);

        pwdEdit = new QLineEdit(layoutWidget2);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));

        horizontalLayout_3->addWidget(pwdEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(300, 300, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        confirmBtn = new QPushButton(layoutWidget3);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));

        horizontalLayout_4->addWidget(confirmBtn);

        resetBtn = new QPushButton(layoutWidget3);
        resetBtn->setObjectName(QStringLiteral("resetBtn"));

        horizontalLayout_4->addWidget(resetBtn);

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
        menuHL1_0 = new QMenu(menuBar);
        menuHL1_0->setObjectName(QStringLiteral("menuHL1_0"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        BackendGuIClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuHL1_0->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuHL1_0->addAction(action);

        retranslateUi(BackendGuIClass);

        QMetaObject::connectSlotsByName(BackendGuIClass);
    } // setupUi

    void retranslateUi(QMainWindow *BackendGuIClass)
    {
        BackendGuIClass->setWindowTitle(QApplication::translate("BackendGuIClass", "BackendGuI", Q_NULLPTR));
        action->setText(QApplication::translate("BackendGuIClass", "f", Q_NULLPTR));
        yearPlanBtn->setText(QApplication::translate("BackendGuIClass", "\345\271\264\345\272\246\350\256\241\345\210\222", Q_NULLPTR));
        seasonPlanBtn->setText(QApplication::translate("BackendGuIClass", "\345\255\243\350\212\202\350\256\241\345\210\222", Q_NULLPTR));
        monthPlanBtn->setText(QApplication::translate("BackendGuIClass", "\346\234\210\350\256\241\345\210\222", Q_NULLPTR));
        label->setText(QApplication::translate("BackendGuIClass", "\350\264\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("BackendGuIClass", "\345\257\206\347\240\201", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("BackendGuIClass", "\347\241\256\345\256\232", Q_NULLPTR));
        resetBtn->setText(QApplication::translate("BackendGuIClass", "\351\207\215\347\275\256", Q_NULLPTR));
        menu->setTitle(QApplication::translate("BackendGuIClass", "\350\256\241\345\210\222\347\256\241\347\220\206\345\231\250 HL1.0", Q_NULLPTR));
        menuHL1_0->setTitle(QString());
        menu_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class BackendGuIClass: public Ui_BackendGuIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKENDGUI_H
