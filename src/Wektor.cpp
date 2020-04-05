#include <iostream>
#include <cmath>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"

using namespace std;

Wektor::Wektor(double x, double y, double z)
{
    tabW[0]=x;
    tabW[1]=y;
    tabW[2]=z;
}

Wektor::Wektor()
{
    tabW[0]=0;
    tabW[1]=0;
    tabW[2]=0;
}

double & Wektor::operator[](int i) 
{
    if(i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

const double & Wektor::operator[](int i) const
{
    if(i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad-jestes poza tablica!";
        exit(1);
    }
    return tabW[i];
}

void Wektor::wpisz()
{
    for (int i=0; i<ROZMIAR; i++)
    {
        cout<<"Wpisz wartosc:";
        cin>>tabW[i];
    }
}

void Wektor::wypisz ()
{
    cout<<"1 wartosc:"<<tabW[0]<<endl;
    cout<<"2 wartosc:"<<tabW[1]<<endl;
    cout<<"3 wartosc:"<<tabW[2]<<endl;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    Strm>>Wek[0]>>Wek[1]>>Wek[2];
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    cout<<"["<<Wek[0]<<" "<<Wek[1]<<" "<<Wek[2]<<"]";
    return Strm;
}

const Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor wynik(tabW[0]+W2[0], tabW[1]+W2[1], tabW[2]+W2[2]);
    return wynik;
}

const Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor wynik(tabW[0]-W2[0], tabW[1]-W2[1], tabW[2]-W2[2]);
    return wynik;
}

const double Wektor::operator * (const Wektor & W2) const /* Iloczyn skalarny */
{
    double wynik=tabW[0]*W2[0]+tabW[1]*W2[1]+tabW[2]*W2[2];
    return wynik;
}

const Wektor Wektor::operator * (double l) const /* Wektor razy liczba */ /*const x2*/
{
    Wektor wynik(tabW[0]*l,tabW[1]*l,tabW[2]*l);
    return wynik;
}

const Wektor Wektor::operator / (double l) const /* Wektor / liczba */ /*const x2*/
{
    Wektor wynik(tabW[0]/l,tabW[1]/l,tabW[2]/l);
    return wynik;
}

const bool Wektor::operator == (const Wektor & W2) const
{
    if (tabW[0]!=W2[0] || tabW[1]!=W2[1] || tabW[2]!=W2[2])
    return false;
    return true;
}

const bool Wektor::operator != (const Wektor & W2) const
{      
    if (tabW[0]==W2[0] && tabW[1]==W2[1] && tabW[2]==W2[2])
    return false;
    return true;
}

const double Wektor::dlugosc () const
{
    double wynik=sqrt(pow(tabW[0],2)+pow(tabW[1],2)+pow(tabW[2],2));
    return wynik;
}




