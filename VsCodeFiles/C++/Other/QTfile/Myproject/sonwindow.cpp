#include "sonwindow.h"

SonWindow::SonWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("副窗口");
    button.setText("切换窗口");
    button.setParent(this);
    connect(&button, &QPushButton::pressed, this, &SonWindow::soltsingal);
    resize(500, 500);
}
void SonWindow::soltsingal(){
    emit mysingal();
}
