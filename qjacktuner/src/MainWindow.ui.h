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
/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
#include "value.h"
#include "scala.h"
#include "jack.h"















void MainWindow::helpAbout()
{
    
}

void MainWindow::customEvent(QCustomEvent *E)
{
    switch (E->type() - QCustomEvent::User) {
    case 0: {
	    ValueEvent::TheValueEvent = new ValueEvent;
	    ValueEvent &V(*(ValueEvent*)E);
	    static QString *Name;
	    QString *NewName;
	    int OktavOffset;
	    double Deviation;
	    TheScala.ComputeTone(NewName, OktavOffset, Deviation, V.GetF());
	    slider1->setValue(50 + (int)(100*Deviation));
	    if (Name != NewName) {
		textLabel1->setText(*NewName);
		Name = NewName;
	    }
	}break;
    case 1: {
	    const char ** C = (const char **)E->data();
	    int i;
	    QString CS;
	    if (C) {
		for (i=0; C[i]; i++) {
		    if (CS.isEmpty())
			CS += " @ ";
		    else
			CS += " + ";
		    CS += C[i];
		    free((void*)C[i]);
		}
		free(C);
	    }
	    
	    setCaption(QString("qjacktuner") += CS);
	}break;
    }
}





void MainWindow::menubar_activated(int i)
{
    QString w = PortBase;
    w += ":";
    w += Input->text(i);
    //cout  << __FUNCTION__ << " "<< w << endl;
    jackConnect(w);
    //cout << name() << endl;
    //setCaption(QString("qjacktuner @ ") += w);
}


void MainWindow::menubar_highlighted( int i)
{
    //cout << __FUNCTION__ << i << endl;
    if (1 == i)
	fillInputDropdown();
    else
	if (Input->itemParameter(i))
	    PortBase = Input->text(i);
}


void MainWindow::fillInputDropdown()
{
    Input->clear();
    jackGetPorts(*Input);
}
