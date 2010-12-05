#include "model.h"
#include "qpushbutton.h"
#include <QHBoxLayout>




model::model(QObject *parent) :
    QObject(parent)
{
    this->myDate = new QDate( QDate::currentDate());
    this->myTime = new QTime( QTime::currentTime());
    //this->updateDisplay(date);
}


void model::sl_exitPressed(){

    QWidget *yesNoDialog = new QWidget;
    yesNoDialog->setWindowTitle("Are you sure?");


    QPushButton *myButton = new QPushButton();
    myButton->setText("Yes");
    connect(myButton, SIGNAL(clicked()), this       , SLOT(sl_closeApp()));
    connect(myButton, SIGNAL(clicked()), yesNoDialog, SLOT(close()));


    QPushButton *myButton_2 = new QPushButton();
    myButton_2->setText("No");
    connect(myButton_2, SIGNAL(clicked()), yesNoDialog, SLOT(close()));

    QHBoxLayout *myLayout = new QHBoxLayout;
    myLayout->addWidget(myButton);
    myLayout->addWidget(myButton_2);

    yesNoDialog->setLayout(myLayout);

    //button->setText("okej");
    //QObject::connect(button, SIGNAL(clicked()), this , SLOT(sl_deleteButton()) );

    //yesNoDialog->show();
    yesNoDialog->show();

}

void model::sl_deleteButton(){
    button->close();
}

//void model::updateDisplay(QDateTime *now){

//}

void model::sl_updateTime(QTime time){
    this->myTime->setHMS(this->myTime->hour(), this->myTime->minute(), this->myTime->second(), 0);
    this->button = new QPushButton("czas ustawiony");
    button->show();
}

void model::sl_updateDateTime(QDateTime dt){
    this->myDateTime = new QDateTime(dt) ;

    this->button = new QPushButton("sl_updateDateTime");
    connect(button, SIGNAL(clicked()), button, SLOT(close()));
    button->show();
}

void model::sl_closeApp(){

    this->button = new QPushButton("sl_closeApp osiagniety");
    button->show();

    emit sig_closeApp();
}
