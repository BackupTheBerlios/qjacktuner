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
















void MainWindow::helpAbout()
{

}

void MainWindow::customEvent(QCustomEvent *E)
{
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
}



