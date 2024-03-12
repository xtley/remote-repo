#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->teacher=new Teacher();
    this->student=new Student();
//    connect(this->teacher,&Teacher::el,this->student,&Student::qkcf);
//    connect(teacher,SIGNAL(el()),student,SLOT(qkcf()));
//    test();

    //自定义信号槽函数遇到重载时 重载为同名带从参数的信号和槽
    //connect(teacher,&Teacher::el,student,&Student::qkcf);

    void (Teacher:: *teacherSignal)(QString)=&Teacher::el;
    void (Student:: *studentSlot)(QString)=&Student::qkcf;
    connect(teacher,teacherSignal,student,studentSlot);
    test();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::test(){

    emit this->teacher->el();  //使用emit 将信号辐射
    emit this->teacher->el("鸡腿");

}
