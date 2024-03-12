#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);
    //菜单栏创建 菜单栏最多只能有一个
    QMenuBar *bar=menuBar();
    //将菜单栏放到窗口中
    setMenuBar(bar);

    //创建菜单
    //bar->addMenu("文件");

    QMenu *fileMenu=bar->addMenu("文件"); //接收他的返回值
    QMenu *editMenu=bar->addMenu("编辑");

    //创建菜单项
    fileMenu->addAction("新建");
    //添加分割符
    fileMenu->addSeparator();
    fileMenu->addAction("打开");

    //工具栏  可以有多个 可以拖左上拖曳(有两个小点)
    QToolBar *toolBar=new QToolBar(this);
    //addToolBar(toolBar);
    addToolBar(Qt::LeftToolBarArea,toolBar);  //设置默认停靠范围
    //后期设置只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);// | | |
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动(总开关)
    toolBar->setMovable(false);

    //工具栏可以设置内容
    QAction *newAction=fileMenu->addAction("新建");
    QAction *openAction=editMenu->addAction("打开");
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    //工具栏中添加一些控件
    QPushButton *btn=new QPushButton("aa",this);
    toolBar->addWidget(btn);
}

MainWindow::~MainWindow()
{
}

