//
// Created by whyafer on 2024/2/22.
//

#ifndef THREEPOINT_POINTTOLINE_H
#define THREEPOINT_POINTTOLINE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class pointToLine; }
QT_END_NAMESPACE

class pointToLine : public QWidget {
    Q_OBJECT

public:
    explicit pointToLine(QWidget *parent = nullptr);

    ~pointToLine() override;

private:
    Ui::pointToLine *ui;
private
    slots:
            void rb_onClick();
            void mousePressEvent(QMouseEvent *event);
};

#endif //THREEPOINT_POINTTOLINE_H
