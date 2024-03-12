#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pixmap1=new QPixmap("1.jpg");
    pixmap2=new QPixmap("2.jpg");

    //利用SIGNAL(信号)和SLOT(槽函数)
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(changeImages1()));
    //connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(changeImages2()));

    //参数1 信号的发送者 参数2  发送的信号(函数的地址) 参数3 信号的接收者 参数4 处理的槽函数
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::changeImages1);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::changeImages2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeImages1(){

    QSize sz=ui->label->size();
    ui->label->setPixmap(pixmap1->scaled(sz));
}
void Widget::changeImages2(){
    QSize sz=ui->label->size();
    ui->label->setPixmap(pixmap2->scaled(sz));
}
