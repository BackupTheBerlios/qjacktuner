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
#include <iostream>
#include <qevent.h>
#include <queue> 

using namespace std;

class ValueEvent: public QCustomEvent
{
#define VALUES 4
	struct Value {
		float Freq;
		float A;
		bool operator < (const Value& Other) const {
			return Other.A < A;
		}
	};
	typedef priority_queue<Value> Co;
	Co *data() {
		return (Co*)QCustomEvent::data();
	}
 public:
	ValueEvent():QCustomEvent(User) {
		Value V = {0.0, 0.0};
		setData(new Co());
		int i = VALUES + 1;
		while (i--)
			data()->push(V);
		data()->pop();
	}
	~ValueEvent() {
		delete data();
	}

	void Try(float Freq, float Amp) {
		Value V = {Freq, Amp};
		data()->push(V);
		data()->pop();
	}

	void Dump() {
		int i;
		for (i = 0; i < VALUES; i++) {
			cout << data()->top().A << "@" << data()->top().Freq << "Hz ";
			data()->pop();
		}
		cout << endl;
	}

	void DumpF() {
		int i = 0;
		struct Value V = data()->top(), V0;
		data()->pop();
		if (data()->top().Freq > 0.0)
			if (V.Freq / data()->top().Freq > 1.1) {
				V0 = V;
				V = data()->top();
				i = 1;
			}
		data()->pop();
		if (data()->top().Freq > 0.0)
			if (V.Freq / data()->top().Freq > 1.1) {
				V = data()->top();
				i = 2;
			}
		cout << i << " " << V.Freq << "Hz ";
		if (1 == i)
			cout << V0.Freq << "Hz ";
		cout << endl;
	}

	float GetF() {
		int i = 0;
		struct Value V = data()->top(), V0;
		data()->pop();
		if (data()->top().Freq > 0.0)
			if (V.Freq / data()->top().Freq > 1.1) {
				V0 = V;
				V = data()->top();
				i = 1;
			}
		data()->pop();
		if (data()->top().Freq > 0.0)
			if (V.Freq / data()->top().Freq > 1.1) {
				V = data()->top();
				i = 2;
			}
		return V.Freq;
	}

	static ValueEvent * volatile TheValueEvent;
 
};
