/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 500, 80, 18));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(530, 500, 80, 18));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 721, 471));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\214\211\351\222\2561", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\214\211\351\222\2562", nullptr));
        label->setText(QCoreApplication::translate("Widget", "                                                                                                             \345\233\276\347\211\207\345\210\207\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
