#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect ( ui->pushButton_3, SIGNAL(clicked()),this,SIGNAL(exitPressedSignal()));
    connect ( ui->pushButton, SIGNAL(clicked()),this,SLOT(sl_updateDateTime()));
    controller::instance()->connectMua(this,NULL);

    connect(ui->timeEdit, SIGNAL(timeChanged(QTime)),this, SIGNAL(sig_updateTime(QTime)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }

}

void MainWindow::sl_updateDateTime(){
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
}
