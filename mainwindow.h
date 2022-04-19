#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QtGui>
#include "turnlight.h"
#include "infoprocdev.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseMoveEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
private slots:

    void on_textEdit_windowIconTextChanged(const QString &iconText);

    void on_actionRandomChange_triggered();

    void on_actiondevices_triggered();

    void on_actionCPU_triggered();

    void on_actionmemory_triggered();

    void on_actionperiphery_triggered();

    void on_lightOn_clicked();

    void on_pushButton_clicked();

    void on_actionRS_232_triggered();

private:
    Ui::MainWindow *ui;
    QThread *thread;
    TurnLight* turnLight;
    InfoProcDev inf;
};

#endif // MAINWINDOW_H
