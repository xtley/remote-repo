#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)       //调用基类构造函数
    , ui(new Ui::Widget)    //对类内ui做初始化  Ui::Widget *ui;
{
    ui->setupUi(this);

    pixmap1 =new QPixmap("1.jpg");
    pixmap2 =new QPixmap("2.jpg");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(changeImage1()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(changeImage2()));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeImage1(void)
{
    QSize sz=ui->label->size();
    ui->label->setPixmap(pixmap1->scaled(sz));
}
void Widget::changeImage2(void)
{
    QSize sz=ui->label->size();
    ui->label->setPixmap(pixmap2->scaled(sz));
}
