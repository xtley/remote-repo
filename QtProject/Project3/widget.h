#ifndef WIDGET_H
#define WIDGET_H

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

private:
    Ui::Widget *ui;
    QPixmap *pixmap1;  //图片对象
    QPixmap *pixmap2;
private slots:
    void changeImages1();  //槽函数
    void changeImages2();

};
#endif // WIDGET_H
