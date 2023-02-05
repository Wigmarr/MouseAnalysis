#ifndef FILESAVER_H
#define FILESAVER_H

#include <QObject>
#include <QDateTime>
#include <QTextStream>
#include <QSettings>
#include <QFile>
class FileSaver : public QObject
{
    Q_OBJECT
public:
    FileSaver(QObject * parent = nullptr);
private:
    int pathLength;
    QString filePath;
signals:
    void fileSaved();
public slots:
    void on_save_file(int);
    void on_path_changed(QString);
};

#endif // FILESAVER_H
