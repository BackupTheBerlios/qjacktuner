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
