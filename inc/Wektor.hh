#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

class Wektor {
  double tabW[ROZMIAR];

  public:
  double & operator [] (int i); 
  const double & operator[](int i) const;
  Wektor ();
  Wektor (double ,double ,double);
  void wpisz();
  void wypisz();
  friend std::istream& operator >> (std::istream &Strm, Wektor &Wek);
  friend std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);
  const Wektor operator + (const Wektor & W2) const;
  const Wektor operator - (const Wektor & W2) const;
  const double operator * (const Wektor & W2) const; /* Iloczyn skalarny */
  const Wektor operator * (double l) const; /* Wektor * liczba */ /*const x2*/
  const Wektor operator / (double l) const; /* Wektor / liczba */ /*const x2*/
  const bool operator == (const Wektor & W2) const;
  const bool operator != (const Wektor & W2) const;
  const double dlugosc () const;
};

  
#endif
