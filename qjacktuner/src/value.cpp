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
#include "value.h"

//#define DO_TRACE


bool ValueEvent::Value::operator < (const Value& Other) const
{
  return Other.A < A;
}

ValueEvent::Value &ValueEvent::Co::operator [] (int i)
{
  return c[i];
}

void ValueEvent::Co::Sort()
{
  container_type::iterator a = c.begin(), z = c.end();
  sort(a, z);

#ifdef DO_TRACE
  int i = VALUES - 1;
  while (i >= 0) {
    cout << i << "sss" << c[i].A << "@" << c[i].Freq << "Hz ";
    --i;
  }
  cout << endl;
#endif
}


ValueEvent::ValueEvent():QCustomEvent(User)
{
  Value V = {0.0, 0.0};
  setData(new Co());
  int i = VALUES + 1;
  while (i--)
    data()->push(V);
  data()->pop();
}

ValueEvent::~ValueEvent()
{
  delete data();
}


void ValueEvent::Try(float Freq, float Amp) {
  if (Freq > 0.0  &&  Amp > data()->top().A) {
    Value V = {Freq, Amp};
    data()->push(V);
    data()->pop();
  }
}

void ValueEvent::Dump() {
  int i;
  for (i = 0; i < VALUES; i++) {
    cout << data()->top().A << "@" << data()->top().Freq << "Hz ";
    data()->pop();
  }
  cout << endl;
}


float ValueEvent::GetF() {
  struct Value V;
  data()->Sort();
  int i = 0;
  do {
    V = (*data())[i];
#ifdef DO_TRACE
    cout << i << "set" << V.A << "@" << V.Freq << "Hz ";
#endif
  } while (++i < VALUES  &&  (*data())[i].Freq > 0.0  &&  V.Freq / (*data())[i].Freq > 2.5);
#ifdef DO_TRACE
  while (i < VALUES) {
    cout << i << "---" << (*data())[i].A << "@" << (*data())[i].Freq << "Hz ";
    ++i;
  }
  cout << endl;
#endif

  return V.Freq;
}

