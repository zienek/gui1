#include "controller.h"

#include <memory>
#include <cassert>
#include <QObject>
#include <QWidget>

#include "model.h"



controller::controller()
{
}

controller::~controller()
{
}


controller * controller::instance() {
    static std::auto_ptr<controller> apContr ( new controller() ) ;
    return apContr.get() ;
}


void controller::connectMua(QObject * pView, QObject * pModel) {  // here connect all neccesary items
    //assert ( pView && pModel ) ;

    model* pCurrentModel = qobject_cast<model*>( pModel ) ;

    if (pCurrentModel== NULL){
        pCurrentModel = new model(this);

    }
    connect (  pView, SIGNAL(exitPressedSignal())           , pCurrentModel, SLOT(sl_exitPressed()));
    connect (  pView, SIGNAL(sig_updateTimeDate(QDateTime)) , pCurrentModel, SLOT(sl_updateDateTime(QDateTime)));
    connect ( pModel, SIGNAL(sig_closeApp())                , this ,         SLOT(funkcja()));

}
/*
void setMainWindow(QWidget * pWidget ){
    mp_window = pWidget;

}

QWidget getMainWindow(){
    return mp_window;
}
*/

void controller::funkcja(){
    int z = 4 ;


}

   //QPixmap(":/plik.png");
