//#include <math.h>
#include <iostream>

#include "halbbanddezimator.h"

using namespace std;

//#define M_PI 3.14159265358979323846


HalbbandDezimator::HalbbandDezimator()
{
  T0 = T10 = T11 = T12 = 0.0;
  int k;
  RechenTyp h[N+1];
  for (k = 0; k <= N; k++) {
    RechenTyp T = ((RechenTyp)M_PI_4) * (2*k -N);
    h[k] = 0.5;
    if (0.0 != T)
      h[k] *= sin(T) / T;
    //    cout << "h[" << k << "]=" << (h[k] == 0.0 ? 0.0 : h[k]) << endl;
  }
  h1 = h[1];
  h3 = h[3];
  h4 = h[4];
}


// int main()
// {
//   Dezimat8 D(256);
// }
