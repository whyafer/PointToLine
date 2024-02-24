//
// Created by whyafer on 2024/2/24.
//

#include "BezierCurve.h"

BezierCurve::BezierCurve() {}

void BezierCurve::createNBezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision)
{
    if (src.size() <= 0) return;

    //清空
    QList<QPointF>().swap(dest);

    for (qreal t = 0; t < 1.0000; t += precision) {
        int size = src.size();
        QVector<qreal> coefficient(size, 0);
        coefficient[0] = 1.000;
        qreal u1 = 1.0 - t;

        for (int j = 1; j <= size - 1; j++) {
            qreal saved = 0.0;
            for (int k = 0; k < j; k++){
                qreal temp = coefficient[k];
                coefficient[k] = saved + u1 * temp;
                saved = t * temp;
            }
            coefficient[j] = saved;
        }

        QPointF resultPoint;
        for (int i = 0; i < size; i++) {
            QPointF point = src.at(i);
            resultPoint = resultPoint + point * coefficient[i];
        }

        dest.append(resultPoint);
    }
}