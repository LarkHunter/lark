/********************************************************************************
** Form generated from reading UI file 'loginwarn.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWARN_H
#define UI_LOGINWARN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWarn
{
public:
    QLabel *label;

    void setupUi(QWidget *loginWarn)
    {
        if (loginWarn->objectName().isEmpty())
            loginWarn->setObjectName(QStringLiteral("loginWarn"));
        loginWarn->resize(670, 422);
        label = new QLabel(loginWarn);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 501, 341));

        retranslateUi(loginWarn);

        QMetaObject::connectSlotsByName(loginWarn);
    } // setupUi

    void retranslateUi(QWidget *loginWarn)
    {
        loginWarn->setWindowTitle(QApplication::translate("loginWarn", "loginWarn", Q_NULLPTR));
        label->setText(QApplication::translate("loginWarn", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginWarn: public Ui_loginWarn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWARN_H
