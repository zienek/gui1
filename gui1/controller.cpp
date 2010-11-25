#include "controller.h"

#include <memory>
#include <cassert>
#include <QObject>
#include <QWidget>

class QWidget ;

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


void controller::connectMua() {  // here connect all neccesary items
//    assert ( m_pWindow && m_pModel ) ;

}
/*
void setMainWindow(QWidget * pWidget ){
    mp_window = pWidget;

}

QWidget getMainWindow(){
    return mp_window;
}
*/
