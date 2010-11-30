#include <QtGui/QApplication>
#include "mainwindow.h"

#include "controller.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);
    QApplication app(argc, argv);

    controller * pController = controller::instance();
    Q_UNUSED(pController);


    MainWindow w;
    w.show();
    return app.exec();
}
