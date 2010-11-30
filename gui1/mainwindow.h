#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
private slots:
//    void exitPressed() ;

public slots:
    void sl_updateDateTime();

signals:
    void exitPressedSignal() ;
    void sig_updateTime(QTime) ;
};

#endif // MAINWINDOW_H
