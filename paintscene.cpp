#include "paintscene.h"

PaintScene::PaintScene(QObject * parent) : QGraphicsScene(parent)
{

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // отрисовка пути курсора
    addLine(event->lastScenePos().x(), event->lastScenePos().y(),
            event->scenePos().x(), event->scenePos().y(),
            QPen(Qt::blue,5,Qt::SolidLine, Qt::RoundCap));
    _currentPosition = event->scenePos();
    QVector2D vec = QVector2D( event->scenePos()-event->lastScenePos());
   // qDebug() << vec;
    _pathLength += double (vec.length());
    emit mouse_moved(event->scenePos().x(), event->scenePos().y());

}

void PaintScene::on_reset()
{
    this->clear();
    emit path_calculated(int (_pathLength));
    _pathLength = 0;

}

PaintScene::~PaintScene(){}
