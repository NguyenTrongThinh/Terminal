#include "terminal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Terminal w;



    w.showFullScreen();
    return a.exec();
}
