/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox_Font;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QLabel *label_2;
    QGroupBox *groupBox_Color;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnOk;
    QPushButton *btnClear;
    QPushButton *btnExit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(349, 249);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Dialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        groupBox_Font = new QGroupBox(Dialog);
        groupBox_Font->setObjectName("groupBox_Font");
        horizontalLayout_2 = new QHBoxLayout(groupBox_Font);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        chkBoxUnder = new QCheckBox(groupBox_Font);
        chkBoxUnder->setObjectName("chkBoxUnder");

        horizontalLayout_2->addWidget(chkBoxUnder);

        chkBoxItalic = new QCheckBox(groupBox_Font);
        chkBoxItalic->setObjectName("chkBoxItalic");

        horizontalLayout_2->addWidget(chkBoxItalic);

        chkBoxBold = new QCheckBox(groupBox_Font);
        chkBoxBold->setObjectName("chkBoxBold");

        horizontalLayout_2->addWidget(chkBoxBold);


        verticalLayout->addWidget(groupBox_Font);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        groupBox_Color = new QGroupBox(Dialog);
        groupBox_Color->setObjectName("groupBox_Color");
        horizontalLayout = new QHBoxLayout(groupBox_Color);
        horizontalLayout->setObjectName("horizontalLayout");
        radioBlack = new QRadioButton(groupBox_Color);
        radioBlack->setObjectName("radioBlack");
        radioBlack->setChecked(true);

        horizontalLayout->addWidget(radioBlack);

        radioRed = new QRadioButton(groupBox_Color);
        radioRed->setObjectName("radioRed");

        horizontalLayout->addWidget(radioRed);

        radioBlue = new QRadioButton(groupBox_Color);
        radioBlue->setObjectName("radioBlue");

        horizontalLayout->addWidget(radioBlue);


        verticalLayout->addWidget(groupBox_Color);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName("plainTextEdit");
        QFont font;
        font.setPointSize(20);
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnOk = new QPushButton(Dialog);
        btnOk->setObjectName("btnOk");

        horizontalLayout_3->addWidget(btnOk);

        btnClear = new QPushButton(Dialog);
        btnClear->setObjectName("btnClear");

        horizontalLayout_3->addWidget(btnClear);

        btnExit = new QPushButton(Dialog);
        btnExit->setObjectName("btnExit");

        horizontalLayout_3->addWidget(btnExit);


        verticalLayout->addLayout(horizontalLayout_3);

        QWidget::setTabOrder(chkBoxUnder, plainTextEdit);
        QWidget::setTabOrder(plainTextEdit, radioRed);
        QWidget::setTabOrder(radioRed, radioBlue);
        QWidget::setTabOrder(radioBlue, radioBlack);
        QWidget::setTabOrder(radioBlack, chkBoxItalic);
        QWidget::setTabOrder(chkBoxItalic, chkBoxBold);
        QWidget::setTabOrder(chkBoxBold, btnClear);
        QWidget::setTabOrder(btnClear, btnOk);
        QWidget::setTabOrder(btnOk, btnExit);

        retranslateUi(Dialog);
        QObject::connect(btnOk, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnExit, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\344\277\241\345\217\267\344\270\216\346\247\275\347\232\204\344\275\277\347\224\250", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\255\227\344\275\223", nullptr));
        groupBox_Font->setTitle(QString());
        chkBoxUnder->setText(QCoreApplication::translate("Dialog", "Underline", nullptr));
        chkBoxItalic->setText(QCoreApplication::translate("Dialog", "Italic", nullptr));
        chkBoxBold->setText(QCoreApplication::translate("Dialog", "Bold", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\351\242\234\350\211\262", nullptr));
        groupBox_Color->setTitle(QString());
        radioBlack->setText(QCoreApplication::translate("Dialog", "Black", nullptr));
        radioRed->setText(QCoreApplication::translate("Dialog", "Red", nullptr));
        radioBlue->setText(QCoreApplication::translate("Dialog", "Blue", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Dialog", "Qt 6 C++\345\274\200\345\217\221\346\214\207\345\215\227", nullptr));
        btnOk->setText(QCoreApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        btnClear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272", nullptr));
        btnExit->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
