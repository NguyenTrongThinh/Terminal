#include "terminal.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Terminal w;
    QDesktopWidget desktop;

    int desktopHeight=desktop.geometry().height();
    int desktopWidth=desktop.geometry().width();
    w.setGeometry(0, 0, desktopWidth, desktopHeight);
    w.show();
    return a.exec();
}
