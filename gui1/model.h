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


signals:
    //void updateDisplay(QDateTime *newTime);

public slots:
    void sl_exitPressed();
    void sl_updateTime(QTime);

private slots:
    void sl_deleteButton();

};

#endif // MODEL_H
