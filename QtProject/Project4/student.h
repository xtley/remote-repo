#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:  //编写自定义信号

//早起Qt版本必须写到public slots下 5.4版本以后可以写到public一下 或者是全局函数下
public slots: //编写自定义槽函数 槽函数必须实现 否则会报错
    void qkcf(void);
    void qkcf(QString foodName);
};

#endif // STUDENT_H
