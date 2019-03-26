/********************************************************************************
** Form generated from reading UI file 'seasonPlan.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEASONPLAN_H
#define UI_SEASONPLAN_H

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

class Ui_seasonPlan
{
public:
    QPushButton *springBtn;
    QPushButton *summerBtn;
    QPushButton *autumnBtn;
    QPushButton *winterBtn;
    QListWidget *seasonlistWidget;
    QLineEdit *numEdit;
    QLineEdit *planLineEdit;
    QPushButton *addBtn;

    void setupUi(QWidget *seasonPlan)
    {
        if (seasonPlan->objectName().isEmpty())
            seasonPlan->setObjectName(QStringLiteral("seasonPlan"));
        seasonPlan->resize(630, 411);
        seasonPlan->setMinimumSize(QSize(630, 411));
        seasonPlan->setMaximumSize(QSize(630, 411));
        springBtn = new QPushButton(seasonPlan);
        springBtn->setObjectName(QStringLiteral("springBtn"));
        springBtn->setGeometry(QRect(450, 50, 75, 23));
        summerBtn = new QPushButton(seasonPlan);
        summerBtn->setObjectName(QStringLiteral("summerBtn"));
        summerBtn->setGeometry(QRect(530, 50, 75, 23));
        autumnBtn = new QPushButton(seasonPlan);
        autumnBtn->setObjectName(QStringLiteral("autumnBtn"));
        autumnBtn->setGeometry(QRect(450, 90, 75, 23));
        winterBtn = new QPushButton(seasonPlan);
        winterBtn->setObjectName(QStringLiteral("winterBtn"));
        winterBtn->setGeometry(QRect(530, 90, 75, 23));
        seasonlistWidget = new QListWidget(seasonPlan);
        seasonlistWidget->setObjectName(QStringLiteral("seasonlistWidget"));
        seasonlistWidget->setGeometry(QRect(10, 10, 421, 261));
        numEdit = new QLineEdit(seasonPlan);
        numEdit->setObjectName(QStringLiteral("numEdit"));
        numEdit->setGeometry(QRect(22, 350, 101, 20));
        planLineEdit = new QLineEdit(seasonPlan);
        planLineEdit->setObjectName(QStringLiteral("planLineEdit"));
        planLineEdit->setGeometry(QRect(152, 350, 271, 20));
        addBtn = new QPushButton(seasonPlan);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(450, 350, 75, 23));

        retranslateUi(seasonPlan);

        QMetaObject::connectSlotsByName(seasonPlan);
    } // setupUi

    void retranslateUi(QWidget *seasonPlan)
    {
        seasonPlan->setWindowTitle(QApplication::translate("seasonPlan", "seasonPlan", Q_NULLPTR));
        springBtn->setText(QApplication::translate("seasonPlan", "\346\230\245\345\244\251", Q_NULLPTR));
        summerBtn->setText(QApplication::translate("seasonPlan", "\345\244\217\345\244\251", Q_NULLPTR));
        autumnBtn->setText(QApplication::translate("seasonPlan", "\347\247\213\345\244\251", Q_NULLPTR));
        winterBtn->setText(QApplication::translate("seasonPlan", "\345\206\254\345\244\251", Q_NULLPTR));
        addBtn->setText(QApplication::translate("seasonPlan", "\346\226\260\345\242\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class seasonPlan: public Ui_seasonPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEASONPLAN_H
