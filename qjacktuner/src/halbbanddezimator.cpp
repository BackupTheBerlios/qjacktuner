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
#include <math.h>

#include "halbbanddezimator.h"

using namespace std;



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
