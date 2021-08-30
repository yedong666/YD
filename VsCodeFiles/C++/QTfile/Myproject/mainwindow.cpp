#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowTitle("主窗口");
    ui->setupUi(this);
    button.setText("切换窗口");
    button.move(200, 200);
    button.setParent(this);
    connect(&button, &QPushButton::pressed, this, &MainWindow::ChangewinSon);
    connect(&son, &SonWindow::mysingal, this, &MainWindow::Changewin);
    resize(500, 500);
}
void MainWindow::Changewin(){
    show();
    son.hide();
}
void MainWindow::ChangewinSon(){
    this->hide();
    son.show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

