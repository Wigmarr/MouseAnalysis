#include "filesaver.h"

FileSaver::FileSaver(QObject * parent) : QObject (parent)
{
    QSettings settings("config.ini", QSettings::IniFormat);
    filePath = settings.value("path").toString();
}

void FileSaver::on_save_file(int pathLength)
{
    QDateTime datetime = QDateTime::currentDateTimeUtc();
    // так как в windows нельзя в имени файла использовать ":", используется "."
    QString fullFilePath = filePath + "/" + datetime.toString("dd.mm.yyyy hh.mm.ss") +".txt";
    QFile file(fullFilePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QTextStream out(&file);
    out << pathLength;
    file.close();
    emit fileSaved();
}

void FileSaver::on_path_changed(QString path) {
    filePath = path;
}
