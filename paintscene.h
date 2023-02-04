#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{

    Q_OBJECT
public:
    PaintScene(QObject *parent = nullptr);
    ~PaintScene();
private:
    QPointF _currentPosition;

private:
//    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PAINTSCENE_H
