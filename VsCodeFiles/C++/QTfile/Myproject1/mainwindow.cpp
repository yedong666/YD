#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar *myBar  = menuBar();
    QMenu *pfile = myBar->addMenu("File");
    QAction *pNew = pfile->addAction("New");
     connect(pNew, &QAction::triggered,
             [=]  ()
     {
         qDebug() << "Hello! ^_^";

     }         );
     QToolBar *toolbar = addToolBar("mybar");
     toolbar->addAction(pNew);
     QPushButton *p = new QPushButton(this);
     p->setText("^_^");
     toolbar->addWidget(p);
     connect(p, &QPushButton::clicked,
             [=] ()
     {
             p->setText("@_@");
     }
     );
     QStatusBar *sBar = statusBar();
     QLabel *label = new QLabel(this);
     label->setText("I'm good!");
     sBar->addWidget(label);
     sBar->addWidget(new QLabel("error", this));
     sBar->addPermanentWidget(new QLabel("yes", this));
     QTextEdit *textEdit = new QTextEdit(this);
     setCentralWidget(textEdit);
     QDockWidget *dock = new QDockWidget(this);
     addDockWidget(Qt::RightDockWidgetArea, dock);
     QTextEdit *textEditl = new QTextEdit(this);
     dock->setWidget(textEditl);



}

MainWindow::~MainWindow()
{
    delete ui;
}

