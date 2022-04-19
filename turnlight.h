#ifndef TURNLIGHT_H
#define TURNLIGHT_H

#include <QObject>

class TurnLight : public QObject
{
    Q_OBJECT
public:
    explicit TurnLight(QObject *parent = nullptr);

signals:
    void finished();

public slots:
    void process();

};



#endif // TURNLIGHT_H
