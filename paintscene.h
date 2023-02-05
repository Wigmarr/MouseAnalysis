#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>
#include <QDebug>
#include <QtMath>
class PaintScene : public QGraphicsScene
{

    Q_OBJECT
public:
    PaintScene(QObject *parent = nullptr);

    ~PaintScene();

signals:
    void mouse_moved(double, double);
    void path_calculated(int);
public slots:
    void on_reset();
private:
    QPointF _currentPosition;
    double _pathLength = 0;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);


};

#endif // PAINTSCENE_H
