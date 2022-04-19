#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMouseEvent>
#include <QThread>
#include "unistd.h"
#include <QtGui>
#include "QtTest/QTest"
#include <QMessageBox>
#include <testkeynumcaps.h>

#include "infoprocdev.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    MainWindow::setFocus();
    ui->setupUi(this);
    setMouseTracking(true);

    thread = new QThread;
    turnLight = new TurnLight;
    turnLight->moveToThread(thread);

    connect(thread, SIGNAL(started()), turnLight, SLOT(process()));
    connect(turnLight, SIGNAL(finished()), thread, SLOT(quit()));

    ui->textEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete thread;
    delete turnLight;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->Info->setText("Курсор: x = " + QString::number(event->pos().x()) + " y= " + QString::number(event->pos().y()));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->text() == "1")
        thread->start();

    if(event->key() == Qt::Key_F1){
        system("xdotool key Caps_Lock");
        system("xdotool key Num_Lock");
    }


    if(event->type() == QEvent::KeyPress){
        QKeyEvent *ke = static_cast<QKeyEvent*>(event);
        if(ke->key() == Qt::Key_Up){
            QString infAboutKey{};

            if(getCapsLockOn() == false){
                infAboutKey += "CapsLk включился";
                system("xdotool key Caps_Lock");
            }
            else
                infAboutKey += "Caps был уже включен";
            if(getNumLockOn() == false){
                infAboutKey += "\tNumLock включился";
                system("xdotool key Num_Lock");
            }
            else
                infAboutKey += "\tNumLock был уже включен";

            qDebug() << "Key_Up";
                QMessageBox::information(this, "Information", infAboutKey);


        }
    }
}

void MainWindow::on_textEdit_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_actionRandomChange_triggered()
{
    int sInt = rand();
    QPalette pal(QPalette::Background, QColor(sInt));
    pal.setColor(QPalette::Button, QColor(Qt::white));
    this->setPalette(pal);
}

void MainWindow::on_actiondevices_triggered()
{

    ui->textEdit->setText(inf.getDevInf());
}

void MainWindow::on_actionCPU_triggered()
{

    ui->textEdit->setText(inf.getCPUInf());
}

void MainWindow::on_actionmemory_triggered()
{

    ui->textEdit->setText(inf.getMemInf());
}

void MainWindow::on_actionperiphery_triggered()
{

    ui->textEdit->setText(inf.getPeripInf());
}


void MainWindow::on_lightOn_clicked()
{
    thread->start();
}



void MainWindow::on_pushButton_clicked()
{
    system("gnome-open https://files.support.epson.com/docid/cpd5/cpd54229.pdf");
}



void MainWindow::on_actionRS_232_triggered()
{
    ui->textEdit->setText("Алгоритм взаимодействия с RS-232\n"
                          "1- Подготовка и настройка скорости передачи данных и прерывания, формата передаваемого слова, кол-во битов контроля четности\n"
                          "2- Подготовка к передачи слова\n"
                          "3 - Проверка готовности линии к приёму слова\n"
                          "4 - Берём слово из адриса в регистр\n"
                          "5 - Проверка состояния: пусты ли сдвиговые и регистровые регисты, готовность передачи слова в другое место\n"
                          "6 - Передача слова в адрес\n"
                          "");
}
