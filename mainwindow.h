#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QSettings>
#include <QFile>
#include <QDateTime>
#include "filesaver.h"
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
    void on_btSetPath_clicked();
    void on_btStartTimer_clicked();
    void on_coords_update(double, double);
    void on_btStopTimer_clicked();
    void on_path_calculated(int);

private:
    Ui::MainWindow * ui;
    QTimer * timer;
    QThread * saveThread;
    PaintScene * paintScene;
    FileSaver * fileSaver;
    int timerInterval = 1000; // интервал в милисекундах
    int path = 0;
    int posX;
    int posY;
signals:
    void pathChange(QString);
private:
    void SetUI();
    void SetTimer();
    void SetSettings();
    void SetConnections();
    void SetFileSaver();

};

#endif // MAINWINDOW_H
