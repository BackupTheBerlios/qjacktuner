class HalbbandDezimator {

	#define N 8
//	typedef float RechenTyp;
	typedef double RechenTyp;

	RechenTyp h1, h3, h4;
	RechenTyp T0, T10, T11, T12;
 public:
	HalbbandDezimator();
	float Dezimiere(const float * const Wert) {
		float Ergebnis = h1 * (Wert[1] + T12) +
			h3 * (T10 + T11) +
			h4 * T0;
		T12 = T11;
		T11 = T10;
		T10 = Wert[1];
		T0 = Wert[0];
		return Ergebnis;
	}
};

class Dezimat8 {
	HalbbandDezimator D2, D4, D8;
	float *Puffer;
 public:
	Dezimat8(size_t l) {
		Puffer = new float[l+8];
	}
	~Dezimat8() {
		delete Puffer;
	}

	float *Dezimiere( const float * const Werte, int const n) {
		int i;
		for (i = 0; i < n/2; i++)
			Puffer[i+2] = D2.Dezimiere(Werte + 2*i);
		for (i = 0; i < n/4; i++)
			Puffer[i+1] = D4.Dezimiere(Puffer + 2 + 2*i);
		for (i = 0; i < n/8; i++)
			Puffer[i] = D8.Dezimiere(Puffer + 1 + 2*i);

		return Puffer;
	}
};
