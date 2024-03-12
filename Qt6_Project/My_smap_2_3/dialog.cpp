#include "dialog.h"
#include <QHBoxLayout>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("手工创建UI");
}

Dialog::~Dialog()
{
}



void Dialog::iniUI()
{
    chkBoxUnder=new QCheckBox("Underline");
    chkBoxItalic=new QCheckBox("Italic");
    chkBoxBold=new QCheckBox("Bold");
    QHBoxLayout *HLay1=new QHBoxLayout();
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);
    radioBlack=new QRadioButton("Black");
    radioBlack->setChecked(true);
    radioRed=new QRadioButton("Red");
    radioBlue=new QRadioButton("Blue");
    QHBoxLayout *HLay2=new QHBoxLayout();
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioRed);
    HLay2->addWidget(radioBlue);
    btnOK=new QPushButton("确定");
    btnCancel=new QPushButton("取消");
    btnClose= new QPushButton("退出");
    QHBoxLayout *HLay3=new QHBoxLayout();
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);

    txtEdit=new QTextEdit();
    txtEdit->setPlainText("Hello World\n 手工创建");
    QFont font=txtEdit->font();
    font.setPixelSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *VLay=new QVBoxLayout();
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void Dialog::iniSignalSlots() {
    connect(radioBlue,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(radioRed,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(radioBlack,SIGNAL(clicked()),this,SLOT(do_setFontColor()));

    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_chkBoxBold(bool)));

    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
}
void Dialog::do_chkBoxUnder(bool checked)
{
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxItalic(bool checked)
{
    QFont font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_chkBoxBold(bool checked)
{
    QFont font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet=txtEdit->palette();
    if(radioBlack->isChecked()) {
        plet.setColor(QPalette::Text,Qt::black);
    }
    else if(radioRed->isChecked()) {
        plet.setColor(QPalette::Text,Qt::red);
    }
    else if(radioBlue->isChecked()) {
        plet.setColor(QPalette::Text,Qt::blue);
    }
    else {
        plet.setColor(QPalette::Text,Qt::black);
    }
    txtEdit->setPalette(plet);
}


