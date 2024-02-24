//
// Created by whyafer on 2024/2/24.
//

#ifndef THREEPOINT_BEZIERCURVE_H
#define THREEPOINT_BEZIERCURVE_H
#include <QWidget>

class BezierCurve {
public:
    BezierCurve();
    static void createNBezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision);
};


#endif //THREEPOINT_BEZIERCURVE_H
