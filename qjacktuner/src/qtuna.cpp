/***************************************************************************
 *   Copyright (C) 2004 by Karsten Wiese                                   *
 *   annabellesgarden@yahoo.de                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
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
