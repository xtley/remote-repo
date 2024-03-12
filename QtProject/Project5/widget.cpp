#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    teacher=new Teacher();
    student=new Student();
    //connect(teacher,&Teacher::el,student,&Student::qkcf);
    //test();

    void (Teacher:: *uteacherSignal)()=&Teacher::el;
    void (Student:: *ustudentSlot)()=&Student::qkcf;
    connect(teacher,uteacherSignal,student,ustudentSlot);
    test1();


    //信号和槽的参数必须一一对应 否则会报错 信号和槽的参数数量不一定要一致 信号的个数可以比槽多 但是前面的类型也必须要一致
    void (Teacher:: *teacherSignal)(QString)=&Teacher::el;
    void (Student:: *studnetSlot)(QString)=&Student::qkcf;
    connect(teacher,teacherSignal,student,studnetSlot);
    test2();

    //断开信号
    //disconnect(teacher,uteacherSignal,student,ustudentSlo);

    //点击按钮触发下课
    QPushButton *btn=new QPushButton("下课",this);
    this->resize(600,400);

   // connect(btn,&QPushButton::clicked,this,&Widget::test1);

    //信号连接信号 click有一个bool类型的参数 而void 0个参数 多一个参数可以使用 信号->信号->槽函数
    connect(btn,&QPushButton::clicked,teacher,uteacherSignal);

    //Qt4版本以前的信号和槽连接方式
    //
    connect(teacher,SIGNAL(el()),student,SLOT(qkcf()));
    //Qt4版本优点 参数直观 缺点 类型不做检测 原因 低层 会直接把SIGNAL("el")转成字符串去找
    //Qt5以上支持Qt4方法
}

Widget::~Widget()
{
    delete ui;
}
void Widget::test1(){
    emit this->teacher->el();  //emit发射信号
}
void Widget::test2(){
    emit this->teacher->el("鸡腿");
}

