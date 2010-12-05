#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controller.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect ( ui->pushButton_3, SIGNAL(clicked()),this,SIGNAL(exitPressedSignal()));  // button EXIT - ask for application quit
    connect ( ui->pushButton, SIGNAL(clicked()),this,SLOT(sl_updateDateTime()));      // button NOW  - insert current tima and date

    controller::instance()->connectMua(this,NULL);

    connect(ui->dateEdit, SIGNAL(dateTimeChanged(QDateTime)), this, SIGNAL(sig_updateTimeDate(QDateTime)) ); // if date modified - inform model about it
    connect(ui->timeEdit, SIGNAL(dateTimeChanged(QDateTime)), this, SIGNAL(sig_updateTimeDate(QDateTime)) ); // if time modified - inform model about it

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


