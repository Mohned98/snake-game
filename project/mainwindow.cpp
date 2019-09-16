#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(500,500);
    s1=new SNAKE;
    s2=new SNAKE;
    s1->setParent(this);
    s2->setParent(this);
    c1=new client(this);
    c2=new client(this);

    s1->setFocus();
    connect(s1, SIGNAL(signalGameOver()),this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


