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


void MainWindow::fileNew()
{

}


void MainWindow::fileOpen()
{

}


void MainWindow::fileSave()
{

}


void MainWindow::fileSaveAs()
{

}


void MainWindow::filePrint()
{

}


void MainWindow::fileExit()
{
    close();
}


void MainWindow::editUndo()
{

}


void MainWindow::editRedo()
{

}


void MainWindow::editCut()
{

}


void MainWindow::editCopy()
{

}


void MainWindow::editPaste()
{

}


void MainWindow::editFind()
{

}


void MainWindow::helpIndex()
{

}


void MainWindow::helpContents()
{

}


void MainWindow::helpAbout()
{

}

void MainWindow::customEvent(QCustomEvent *E)
{
	ValueEvent::TheValueEvent = new ValueEvent;
	ValueEvent &V(*(ValueEvent*)E);
//	V.DumpF();
	QString *Name;
	int OktavOffset;
	double Deviation;
	TheScala.ComputeTone(Name, OktavOffset, Deviation, V.GetF());
	slider1->setValue(50 + (int)(100*Deviation));
	textLabel1->setText(*Name);
}



