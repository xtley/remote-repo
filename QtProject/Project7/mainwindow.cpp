#include "mainwindow.h"
#include "ui_mainwindow.h"
//QMianWindow 里面有一些基件
//比如 菜单工具栏 状态栏 主窗体 浮动窗口
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //重置窗口大小
    resize(600,400);
    //菜单栏创建
    QMenuBar *bar=menuBar();
    //将菜单栏放到窗口中
    setMenuBar(bar);

    //创建菜单
    bar->addMenu("文件");



    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

