#ifndef WIDGET_H
#define WIDGET_H

#include "teacher.h"
#include "student.h"
#include <QWidget>

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
    void test();

};
#endif // WIDGET_H
