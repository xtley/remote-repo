#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Teacher.h"
#include "Student.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Teacher *teacher;
    Student *student;
private:
    Ui::Widget *ui;
    void test1();
    void test2();
};
#endif // WIDGET_H
