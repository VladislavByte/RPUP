#include "infoprocdev.h"
#include <QFile>
#include <QDebug>

InfoProcDev::InfoProcDev()
{
    system("cat /proc/meminfo > mem_info.txt");
    QFile file("/home/program/build-RPUP_2-Desktop-Debug/mem_info.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error \n /home/program/build-RPUP_2-Desktop-Debug/mem_info.txt";
    }
    infProcMem = file.readAll();

    system("cat /proc/cpuinfo > cpu_info.txt");
    QFile file_1("/home/program/build-RPUP_2-Desktop-Debug/cpu_info.txt");
    if(!file_1.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error \n /home/program/build-RPUP_2-Desktop-Debug/cpu_info.txt";
    }
    infProcCPU = file_1.readAll();

    system("cat /proc/devices > devices_info.txt");
    QFile file_2("/home/program/build-RPUP_2-Desktop-Debug/devices_info.txt");
    if(!file_2.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error \n /home/program/build-RPUP_2-Desktop-Debug/devices_info.txt";
    }
    infProcDev = file_2.readAll();

    system("dmesg | grep -i usb > perip_info.txt");
    QFile file_3("/home/program/build-RPUP_2-Desktop-Debug/perip_info.txt");
    if(!file_3.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error \n /home/program/build-RPUP_2-Desktop-Debug/perip_info.txt";
    }
    infPerip = file_3.readAll();
}

QString InfoProcDev::getMemInf()
{
    return infProcMem;
}

QString InfoProcDev::getCPUInf()
{
    return infProcCPU;
}

QString InfoProcDev::getDevInf()
{
    return infProcDev;
}

QString InfoProcDev::getPeripInf()
{
    return infPerip;
}
