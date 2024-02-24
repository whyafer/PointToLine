//
// Created by whyafer on 2024/2/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_pointToLine.h" resolved

#include "pointtoline.h"
#include "ui_pointToLine.h"
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include "BezierCurve.h"

pointToLine::pointToLine(QWidget *parent) :
        QWidget(parent), ui(new Ui::pointToLine) {
    ui->setupUi(this);
}

void pointToLine::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    //qDebug()<<"MouseCLick";
}

void pointToLine::rb_onClick() {
    QPushButton *qPushButton = (QPushButton *) sender();
    QString name = qPushButton->objectName();

    QList<QPointF*> point;

    QList<QGraphicsItem *> items = ui->gv->gs->items();
    QList<QGraphicsItem *> saveItems;

    for (QGraphicsItem *item: items) {
        if (QGraphicsEllipseItem::Type == item->type()) {
            saveItems.append(item);
        } else if (QGraphicsLineItem::Type == item->type()) {
            ui->gv->gs->removeItem(item);
        }
    }

    items.clear();

    if (saveItems.count() > 0) {
                foreach(QGraphicsItem *item, saveItems) {
                items.append(item);
            }
    }

    for (QGraphicsItem *item: items) {
        QRectF rectF = item->boundingRect();
        point.append(new QPointF(rectF.x(), rectF.y()));
        //qDebug() << rectF.x()<<rectF.y();
    }

    if (name == "bt1") {
        if (point.count() > 1) {
            for (int i = 0; i < point.count() - 1; i++) {
                ui->gv->gs->addLine(point[i]->x() + 5, point[i]->y() + 5,
                                    point[i + 1]->x() + 5, point[i + 1]->y() + 5,
                                    QPen(Qt::green));
            }
        } else {
            qDebug() << "Error,only one point!";
        }

        //gs->addLine(m, n, o, p, QPen(Qt::green));
    } else if (name == "bt2") {
        if (point.count() >= 3) {
            float xsum = 0.0;
            float ysum = 0.0;
            for (int i = 0; i < point.count() - 1; i++) {
                xsum += point[i]->x();
                ysum += point[i]->y();
            }
            ui->gv->gs->addLine(point.last()->x() + 5, point.last()->y() + 5,
                                xsum / (point.count() - 1), ysum / (point.count() - 1),
                                QPen(Qt::green));
        } else if (point.count() == 2) {
            for (int i = 0; i < point.count() - 1; i++) {
                ui->gv->gs->addLine(point[i]->x() + 5, point[i]->y() + 5,
                                    point[i + 1]->x() + 5, point[i + 1]->y() + 5,
                                    QPen(Qt::green));
            }
        }

    } else {
        BezierCurve bc;
        QList<QPointF> curvePoint;
        QList<QPointF> points;
        foreach(QPointF* pf,point){
            points.append(*pf);
        }
        bc.createNBezierCurve(points,curvePoint,0.1);
        for (int i = 0; i < curvePoint.count() - 1; i++) {
            ui->gv->gs->addLine(curvePoint[i].x() + 5, curvePoint[i].y() + 5,
                                curvePoint[i + 1].x() + 5, curvePoint[i + 1].y() + 5,
                                QPen(Qt::green));
        }
    }
}

pointToLine::~pointToLine() {
    delete ui;
}
