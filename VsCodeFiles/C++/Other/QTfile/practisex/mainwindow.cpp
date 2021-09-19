#include "mainwindow.h"
#include "ui_mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
    Button1.setText("^_^");
    Button1.setParent(this);
    connect(&Button1, &QPushButton::pressed, this,  &Mainwindow::close);
    Button2 = new QPushButton(this);
    Button2->setText("Change");
    Button2->move(100, 100);
    connect(Button2, &QPushButton::released, this, &Mainwindow::Change);
    Button3.setText("ChangeWin");
    Button3.setParent(this);

}

void Mainwindow::Change(){
    Button1.setText("Close");
}
Mainwindow::~Mainwindow()
{
    delete ui;
}


