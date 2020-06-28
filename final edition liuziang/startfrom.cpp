#include "startfrom.h"
#include "ui_startfrom.h"
#include "mainwindow.h"

StartFrom::StartFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartFrom)
{
    ui->setupUi(this);
    setWindowTitle("开始界面");
    //关卡数量
    const int NumLevelvel = 3;
    //按钮数组
    QPushButton* btnarr[NumLevelvel] = {ui->pushButton, ui->pushButton_2, ui->pushButton_3};
    for (int i = 0; i < NumLevelvel; i++)
        connect(btnarr[i], &QPushButton::clicked, [=]() //监听所有按钮点击
        {
            MainWindow *mainwindow = new MainWindow(i); //向MainWindow传入对应关卡编号
            mainwindow->show();     //显示窗口
        });
}
StartFrom::~StartFrom()
{
    delete ui;
}
