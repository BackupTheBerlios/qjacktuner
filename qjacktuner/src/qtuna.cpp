#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <qapplication.h>

#include "MainWindow.h"
#include "jack.h"
#include "value.h"

MainWindow *PW;

ValueEvent * volatile ValueEvent::TheValueEvent = new ValueEvent;

int initMeasurement();

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    MainWindow W;
    PW = &W;
    initMeasurement();
    W.show();
    a.setMainWidget(&W);
   
    jackUp();
    int r = a.exec();
    jackDown();
    return r;
}
