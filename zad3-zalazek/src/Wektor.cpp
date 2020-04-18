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
    for (int i=0; i<ROZMIAR; i++)
    {
        tabW[i]=0;
    }
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
    for (int i=0; i<ROZMIAR; i++)
    {
        cout<<i+1<<" wartosc:"<<tabW[i]<<endl;
    }
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm>>Wek[i];
    }
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    cout<<"[";
    for (int i=0; i<ROZMIAR-1; i++)
    {
        cout<<Wek[i]<<" ";
    }
    cout<<Wek[ROZMIAR-1]<<"]";
    return Strm;
}

const Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=tabW[i]+W2[i];   
    }
    return wynik;
}

const Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=tabW[i]-W2[i];   
    }
    return wynik;
}

const double Wektor::operator * (const Wektor & W2) const /* Iloczyn skalarny */
{
    double wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik+=tabW[i]*W2[i];
    }
    return wynik;
}

const Wektor Wektor::operator * (double l) const /* Wektor razy liczba */ /*const x2*/
{
    Wektor wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[0]=tabW[i]*l;
    }
    return wynik;
}

const Wektor Wektor::operator / (double l) const /* Wektor / liczba */ /*const x2*/
{
    Wektor wynik;
    if (l==0)
    {
        cerr<<"Blad, dzielenie przez 0";
        exit (1);
    }
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik[i]=tabW[i]/l;
    }
    return wynik;
}

bool Wektor::operator == (const Wektor & W2) const
{
    double epsilon=0.000000000000001; int i;
    for (i=0; i<ROZMIAR; i++)
    {
        if(this->tabW[i]-W2[i]>epsilon)
        return false;
    }
    return true;
}

bool Wektor::operator != (const Wektor & W2) const
{      
    return !(*this==W2);
}

const double Wektor::dlugosc () const
{
    double wynik;
    for (int i=0; i<ROZMIAR; i++)
    {
        wynik+=pow(tabW[i],2);
    }
    return sqrt(wynik);
}




