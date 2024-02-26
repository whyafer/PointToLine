//
// Created by whyafer on 2024/2/23.
//

#ifndef THREEPOINT_MYGVIEW_H
#define THREEPOINT_MYGVIEW_H

#include <QGraphicsView>

class MyGView : public QGraphicsView {
public:
    QGraphicsScene *gs;
    QList<QGraphicsItem *> qItemsList;

    explicit MyGView(QWidget* parent= nullptr);
    ~MyGView() override;
private:
    int index;
private slots:
    void mousePressEvent(QMouseEvent *event);
};

#endif //THREEPOINT_MYGVIEW_H
