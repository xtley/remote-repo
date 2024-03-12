#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:   //早起Qt版本必须写到public slots下 5.4版本以后可以写到public一下 或者是全局函数下
    void qkcf();   //槽函数 必须实现 不然会报错
    void qkcf(QString foodName);
};

#endif // STUDENT_H
