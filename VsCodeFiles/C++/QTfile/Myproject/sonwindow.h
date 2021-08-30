#ifndef SONWINDOW_H
#define SONWINDOW_H

#include <QWidget>
#include <QPushButton>

class SonWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SonWindow(QWidget *parent = nullptr);
    void soltsingal();
private:
    QPushButton button;
signals:
    void mysingal();
};

#endif // SONWINDOW_H
