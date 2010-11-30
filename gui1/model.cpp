#include "model.h"
#include "qpushbutton.h"


model::model(QObject *parent) :
    QObject(parent)
{
    this->myDate = new QDate( QDate::currentDate());
    this->myTime = new QTime( QTime::currentTime());
    //this->updateDisplay(date);
}


void model::sl_exitPressed(){

    this->button = new QPushButton("ok");

    QObject::connect(button, SIGNAL(clicked()), this , SLOT(sl_deleteButton()) );
    button->show();

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
