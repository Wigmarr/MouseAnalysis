#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    SetUI();
    SetTimer();
    SetSettings();
    SetConnections();
}

void MainWindow::SetSettings()
{
    QSettings settings("config.ini", QSettings::IniFormat);
    filePath = settings.value("path").toString();
    timerInterval = settings.value("time").toInt();
    //если в настройках не задан путь к файлам, открывается диалог для установки пути
    if (filePath == "")
    {
        on_btSetPath_clicked();
    }
    else
    {
        ui->lbTimer->setText("Интервал: " + QString::number(double(timerInterval)/1000));
    }

    // если в натсройках не задан интервал, открывается диалог для установки интервала
    if (!timerInterval)
    {
        on_btSetTimer_clicked();
    }
    else
    {
        ui->lbFilePath->setText("Файлы пути: " + filePath);
    }
}

void MainWindow::SetConnections()
{
    connect(paintScene, &PaintScene::mouse_moved, this, &MainWindow::on_coords_update);// обновление координат
    connect(timer, &QTimer::timeout, paintScene,&PaintScene::on_reset);// сообщение сцене о завершение таймера
    connect(paintScene, &PaintScene::path_calculated, this, &MainWindow::on_path_calculated);// обновление пути за интервал времени
}

void MainWindow::SetUI()
{
    ui->setupUi(this);

    //инициализация сцены
    paintScene = new PaintScene();
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

}

void MainWindow::SetTimer()
{
    /* инициализация таймера */
    timer = new QTimer(this);
}

void MainWindow::on_btSetTimer_clicked()
{
    double time = QInputDialog::getDouble(this,
                  tr("QInputDialog::getInteger()"),tr("Интервал:"));
    // переводим полученное время в милисекунды и задаем интервал
    timerInterval = int (time * 1000);
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("time", timerInterval);
    ui->lbTimer->setText("Интервал: " + QString::number(time));
    timer->setInterval(timerInterval);
}

void MainWindow::on_path_calculated(int pathLength)
{
    path = pathLength;
    ui->lbPath->setText("Пройденный путь: " + QString::number(path));

    SavePathFile();
}

void MainWindow::SavePathFile()
{
    QDateTime datetime = QDateTime::currentDateTimeUtc();
    // так как в windows нельзя в имени файла использовать ":", используется "."
    QString fullFilePath = filePath + "/" + datetime.toString("dd.mm.yyyy hh.mm.ss") +".txt";
    QFile file(fullFilePath);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << path;
    file.close();

}

void MainWindow::on_coords_update(double x, double y)
{
    ui->lbXPos->setText("X pos: " + QString::number(x));
    ui->lbYPos->setText("Y pos: " + QString::number(y));
}

void MainWindow::on_btSetPath_clicked()
{
    // записать полученный путь в файл настроек

    filePath = QFileDialog::getExistingDirectory(this,"Укажите путь",
                            QCoreApplication::applicationDirPath(),QFileDialog::ShowDirsOnly);
    ui->lbFilePath->setText("Файлы пути: " + filePath);
    QSettings settings("config.ini", QSettings::IniFormat);
    settings.setValue("path", filePath);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btStartTimer_clicked()
{
    timer->start(timerInterval);
}

void MainWindow::on_btStopTimer_clicked()
{
    timer->stop();
}
