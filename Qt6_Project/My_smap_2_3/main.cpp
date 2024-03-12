#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    QObject *btn= new QRadioButton();
    const QMetaObject *meta=btn->metaObject();
    QString str1=QString(meta->className());
    qDebug()<<str1<<"\n";
    QRadioButton *btnPush=qobject_cast<QRadioButton*>(btn);
    const QMetaObject *meta2=btnPush->metaObject();
    QString str2=QString(meta2->className());
    qDebug()<<str2<<"\n";





    return a.exec();
}
