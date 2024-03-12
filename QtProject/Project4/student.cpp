#include "student.h"
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{

}
void Student::qkcf(){
    qDebug()<<"老师，我请你吃饭\n";
}
void Student::qkcf(QString foodName){

    //如果打印char*内容不加"" QString加"" 可以将QString转为char*
    //先转成QByteArray (.toUtf8())  再转char* 这样就没有""了
    qDebug()<<"老师我请你吃:"<<foodName.toUtf8().data();
}
