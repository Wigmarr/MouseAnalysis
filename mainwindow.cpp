#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //инициализация сцены
    PaintScene * paintScene = new PaintScene();
    const QRectF rect = QRectF(0,0, ui->graphicsView->width() - 20,
                                ui->graphicsView->height() - 20);
    ui->graphicsView->setScene(paintScene);
    //разрешить отслежевание мыши без нажатия кнопок
    ui->graphicsView->setMouseTracking(true);

    ui->graphicsView->fitInView(rect,Qt::KeepAspectRatio);
    ui->graphicsView->setSceneRect(rect);



    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

MainWindow::~MainWindow()
{
    delete ui;
}
