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
