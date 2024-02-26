/********************************************************************************
** Form generated from reading UI file 'pointtoline.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTTOLINE_H
#define UI_POINTTOLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mygview.h"

QT_BEGIN_NAMESPACE

class Ui_pointToLine
{
public:
    QPushButton *bt1;
    QPushButton *bt2;
    QPushButton *bt3;
    MyGView *gv;
    QPushButton *pb4;

    void setupUi(QWidget *pointToLine)
    {
        if (pointToLine->objectName().isEmpty())
            pointToLine->setObjectName("pointToLine");
        pointToLine->resize(538, 280);
        pointToLine->setMouseTracking(false);
        bt1 = new QPushButton(pointToLine);
        bt1->setObjectName("bt1");
        bt1->setGeometry(QRect(410, 40, 95, 20));
        bt2 = new QPushButton(pointToLine);
        bt2->setObjectName("bt2");
        bt2->setGeometry(QRect(410, 70, 95, 20));
        bt3 = new QPushButton(pointToLine);
        bt3->setObjectName("bt3");
        bt3->setGeometry(QRect(410, 100, 95, 20));
        gv = new MyGView(pointToLine);
        gv->setObjectName("gv");
        gv->setGeometry(QRect(10, 20, 381, 231));
        gv->setMouseTracking(false);
        pb4 = new QPushButton(pointToLine);
        pb4->setObjectName("pb4");
        pb4->setGeometry(QRect(410, 130, 111, 24));

        retranslateUi(pointToLine);
        QObject::connect(bt3, SIGNAL(clicked()), pointToLine, SLOT(rb_onClick()));
        QObject::connect(bt2, SIGNAL(clicked()), pointToLine, SLOT(rb_onClick()));
        QObject::connect(bt1, SIGNAL(clicked()), pointToLine, SLOT(rb_onClick()));
        QObject::connect(pb4, SIGNAL(clicked()), pointToLine, SLOT(rb_onClick()));

        QMetaObject::connectSlotsByName(pointToLine);
    } // setupUi

    void retranslateUi(QWidget *pointToLine)
    {
        pointToLine->setWindowTitle(QCoreApplication::translate("pointToLine", "pointToLine", nullptr));
        bt1->setText(QCoreApplication::translate("pointToLine", "\347\202\271\350\277\236\347\272\277", nullptr));
        bt2->setText(QCoreApplication::translate("pointToLine", "\346\213\237\345\220\210\347\233\264\347\272\277", nullptr));
        bt3->setText(QCoreApplication::translate("pointToLine", "\346\213\237\345\220\210\346\233\262\347\272\277", nullptr));
        pb4->setText(QCoreApplication::translate("pointToLine", "\347\273\230\345\210\266\346\233\262\347\272\277\345\271\266\347\255\211\345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pointToLine: public Ui_pointToLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTTOLINE_H
