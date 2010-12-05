#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDate>
#include <QTime>

class QPushButton;

class model : public QObject
{
Q_OBJECT
public:
    explicit model(QObject *parent = 0);

private:

    QPushButton * button;
    QDate       * myDate ;
    QTime       * myTime ;

    QDateTime   * myDateTime ;

signals:
    //void updateDisplay(QDateTime *newTime);
    void sig_closeApp();

public slots:
    void sl_exitPressed();
    void sl_updateTime(QTime);
    void sl_updateDateTime(QDateTime);
    void sl_closeApp();

private slots:
    void sl_deleteButton();
    //void sl_closeProgram();

};

#endif // MODEL_H
