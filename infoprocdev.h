#ifndef INFOPROCDEV_H
#define INFOPROCDEV_H

#include <QFile>

class InfoProcDev
{
public:
    InfoProcDev();

    QString getDevInf();
    QString getMemInf();
    QString getCPUInf();
    QString getPeripInf();
private:
    QString infProcMem;
    QString infProcCPU;
    QString infProcDev;
    QString infPerip;
};

#endif // INFOPROCDEV_H
