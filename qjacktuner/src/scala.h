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
// Scala.h: interface for the Scala class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCALA_H__CC37E7E4_27E4_11D2_BDCA_00C0D109365D__INCLUDED_)
#define AFX_SCALA_H__CC37E7E4_27E4_11D2_BDCA_00C0D109365D__INCLUDED_

#include <math.h>
#include <qstring.h>

class Scala  
{
public:
	Scala(){
		BaseTone = 440.0;
		BaseToneLog = log(BaseTone);
		Interval = pow(2, 1.0 / 12);
		Names = new QString*[Steps=12];
		Names[0] = new QString("A");
		Names[1] = new QString("A#");
		Names[2] = new QString("B");
		Names[3] = new QString("C");
		Names[4] = new QString("C#");
		Names[5] = new QString("D");
		Names[6] = new QString("D#");
		Names[7] = new QString("E");
		Names[8] = new QString("F");
		Names[9] = new QString("F#");
		Names[10] = new QString("G");
		Names[11] = new QString("G#");
	}
	virtual ~Scala();

	double	BaseTone,
			BaseToneLog,
			Interval;
	int		OktavOffset,
			Tone,
			Steps;

	QString ** Names;

	int ComputeTone(QString *& pName, int & OktavOffset, double& Deviation, double Tone){
	double Scale = log(Tone / BaseTone) / log(Interval);
	int IScale = (int)Scale;
		Scale = fmod(Scale, 1);
		if (Scale >= 0.5) {
			IScale++;
			Scale = Scale - 1.0;
		} else
			if (Scale <= -0.5) {
				IScale--;
				Scale = Scale + 1.0;
			}

			OktavOffset = (IScale+1) / 12;
			if (IScale > -1)
				OktavOffset++;
		if ((IScale %= 12) < 0)
			IScale += 12;
		pName = Names[IScale];
		Deviation = Scale;
	return IScale;
	}


};
extern Scala TheScala;
#endif // !defined(AFX_SCALA_H__CC37E7E4_27E4_11D2_BDCA_00C0D109365D__INCLUDED_)
