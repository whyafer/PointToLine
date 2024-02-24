//
// Created by whyafer on 2024/2/23.
//
#include "mygview.h"
#include <QSinglePointEvent>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>

MyGView::MyGView(QWidget *parent) : QGraphicsView(parent) {
    this->setSizeIncrement(350, 220);
    gs = new QGraphicsScene(
            QRectF(QPointF(0, 0), QSizeF(350, 220)));
    index = 0;
    this->setScene(gs);
    //抗锯齿
    this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void MyGView::mousePressEvent(QMouseEvent *event) {
    //qDebug()<<"MouseCLick";
    index++;
    QSinglePointEvent *pointEvent = event;
    float x = pointEvent->position().x();
    float y = pointEvent->position().y();
    //qDebug()<<x<<y;

    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(x - 18, y - 5, 10, 10);

    item->setBrush(Qt::red);

    gs->addItem(item);
}

MyGView::~MyGView() {
    delete gs;
}
