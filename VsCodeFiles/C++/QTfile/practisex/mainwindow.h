#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Mainwindow; }
namespace Si {class SunWindow;}
QT_END_NAMESPACE

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();
    void Change();
private:
    Ui::Mainwindow *ui;
    QPushButton Button1;
    QPushButton *Button2;
    QPushButton Button3;
};
#endif // MAINWINDOW_H
