#include "student.h"
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{

}

void Student::qkcf(){

    qDebug()<<"老师，我请你吃饭";

}
void Student::qkcf(QString foodName){

    qDebug()<<"老师，我请你吃:"<<foodName.toUtf8().data();

}
