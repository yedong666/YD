#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *mybar = menuBar();
    setMenuBar(mybar);
    QMenu *menu = mybar->addMenu("对话框");
    QAction *p1 = menu ->addAction("模态对话框");
    connect(p1, &QAction::triggered,
            [=] ()
    {
        QDialog dig;
        dig.exec();
        qDebug() << "^_^";

    });
    QAction *p2 = menu ->addAction("非模态对话框");
    connect(p2 , &QAction::triggered,
            [=] ()
    {
        QDialog dig;
        dig.exec();
        qDebug() << "^_^";

    });
    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
            [=] ()
    {
        QMessageBox::about(this, "about", "关于qt");
    });
    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
            [=] ()
    {
        int ret = QMessageBox::question(this, "question", "Are you ok?");
        switch(ret){
        case QMessageBox::Yes:
            qDebug() << "I'm ok";
            break;
        case QMessageBox::No:
            qDebug() << "I'm bad!";
            break;
        default:
            break;
        }
     });
}

MainWindow::~MainWindow()
{
    delete ui;
}

