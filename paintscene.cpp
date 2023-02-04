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
}

void PaintScene::reset()
{
    this->clear();
}

PaintScene::~PaintScene(){}
