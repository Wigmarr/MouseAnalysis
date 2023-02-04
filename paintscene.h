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

signals:
    void on_MouseMoved(int, int);
public slots:
    void reset();
private:
    QPointF _currentPosition;
    int _pathLength;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);


};

#endif // PAINTSCENE_H
