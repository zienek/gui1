#ifndef CONTROLLER_H
#define CONTROLLER_H

class QWidget ;

class controller
{
public:
    controller();
    ~controller();

    static controller * instance();

    void setMainWindow(QWidget *pWidget )  {mp_window = pWidget;}
    QWidget  getMainWindow() const { return mp_window; }

    void connectMua();

private:

    QWidget * mp_window;

    
    
    // do not implement !!
    controller(const controller & rhs );
    controller* operator=(const controller & rhs );


};

#endif // CONTROLLER_H
