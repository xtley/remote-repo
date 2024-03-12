#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    //C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的,
    //而非隐式的, 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).
    //不能隐式转换 Person p=10; 不可以这样在类只有一个参数时进行缺省的隐式转换
    explicit Teacher(QObject *parent = nullptr);


signals://编写自定义信号 不能实现会报错
    void el();
    void el(QString foodName);
};

#endif // TEACHER_H
