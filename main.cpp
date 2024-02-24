#include <QApplication>
#include <QPushButton>
#include "pointtoline.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    pointToLine p;
    p.show();
/*    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();*/
    return QApplication::exec();
}
