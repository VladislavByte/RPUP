#include "turnlight.h"
#include "unistd.h"
#include <QApplication>
#include <QDebug>
#include <Qt>
#include <X11/XKBlib.h>
#include <testkeynumcaps.h>

TurnLight::TurnLight(QObject *parent) : QObject(parent)
{

}


void TurnLight::process()
{
    bool canTurnOnCaps = !getCapsLockOn();
    bool canTurnOnNum = !getNumLockOn();

    qDebug() << ((!canTurnOnNum == true) ? "On" : "Off");

    if(canTurnOnCaps)
        system("xdotool key Caps_Lock");
    if(canTurnOnNum)
        system("xdotool key Num_Lock");

    sleep(2);

        system("xdotool key Caps_Lock");
        system("xdotool key Num_Lock");

    emit finished();
}
