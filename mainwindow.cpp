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
    //задаем размер виджета
    ui->graphicsView->fitInView(rect,Qt::KeepAspectRatio);
    ui->graphicsView->setSceneRect(rect);
    //отключение скроллбаров
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    /* инициализация таймера, связываем таймаут таймера с
    очисткой сцены и ресетом длины пройденного пути */
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,this, &MainWindow::on_timer_timeout);
    connect(timer, &QTimer::timeout, paintScene, &PaintScene::reset);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btSetTimer_clicked()
{
    double time = QInputDialog::getDouble(this, tr("QInputDialog::getInteger()"),
                                 tr("Интервал:"));
    ui->lbTimer->setText("Интервал: " + QString::number(time));
}

void MainWindow::on_timer_timeout()
{

}
