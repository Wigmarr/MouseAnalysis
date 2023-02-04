#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <QTimer>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btSetTimer_clicked();
    void on_timer_timeout();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int timerInterval;
};

#endif // MAINWINDOW_H
