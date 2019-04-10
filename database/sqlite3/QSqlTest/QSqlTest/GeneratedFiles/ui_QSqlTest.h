/********************************************************************************
** Form generated from reading UI file 'QSqlTest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSQLTEST_H
#define UI_QSQLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSqlTestClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QPushButton *showButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QSqlTestClass)
    {
        if (QSqlTestClass->objectName().isEmpty())
            QSqlTestClass->setObjectName(QStringLiteral("QSqlTestClass"));
        QSqlTestClass->resize(600, 400);
        centralWidget = new QWidget(QSqlTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(280, 270, 113, 20));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(450, 270, 75, 23));
        showButton = new QPushButton(centralWidget);
        showButton->setObjectName(QStringLiteral("showButton"));
        showButton->setGeometry(QRect(450, 310, 75, 23));
        QSqlTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QSqlTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        QSqlTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QSqlTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSqlTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QSqlTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSqlTestClass->setStatusBar(statusBar);

        retranslateUi(QSqlTestClass);

        QMetaObject::connectSlotsByName(QSqlTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QSqlTestClass)
    {
        QSqlTestClass->setWindowTitle(QApplication::translate("QSqlTestClass", "QSqlTest", Q_NULLPTR));
        addButton->setText(QApplication::translate("QSqlTestClass", "\345\242\236\345\212\240", Q_NULLPTR));
        showButton->setText(QApplication::translate("QSqlTestClass", "\345\261\225\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QSqlTestClass: public Ui_QSqlTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSQLTEST_H
