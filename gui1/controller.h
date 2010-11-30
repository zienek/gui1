#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>


class controller : public QObject
{
    Q_OBJECT
public:
    controller();
    ~controller();

    static controller * instance();

    QObject* getMainWindow() const { return mp_window; }

    void connectMua(QObject * pView, QObject * pModel);

private:

    QObject * mp_window;

    
    
    // do not implement !!
    controller(const controller & rhs );
    controller* operator=(const controller & rhs );

public slots:
    void funkcja();


};

#endif // CONTROLLER_H
