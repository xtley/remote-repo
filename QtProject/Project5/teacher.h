#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:  //信号 不可以实现 否则会报错
     void el();
     void el(QString foodNmae);
};

#endif // TEACHER_H
