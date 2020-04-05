#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
using namespace std;

Macierz::Macierz()
{
    Wektor X;
    tabM[0]=X;
    tabM[1]=X;
    tabM[2]=X;   
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
{    
    tabM[0]=A;
    tabM[1]=B;
    tabM[2]=C;
}

Wektor & Macierz::operator [] (int i)
{
    if (i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

const Wektor & Macierz::operator [] (int i) const
{
    if (i<0 || i>=ROZMIAR)
    {
        cerr<<"Blad, wyjscie poza tablice";
        exit (1);
    }
    return tabM[i];
}

const Macierz Macierz::transpozycja () const
{
    Macierz A;
    double tmp1, tmp2;
    A[0]=tabM[0];
    A[1]=tabM[1];
    A[2]=tabM[2];
    tmp1=A[0][1]; /*2*/
    tmp2=A[0][2]; /*3*/
    A[0][1]=A[1][0]; /*4 na 2*/
    A[0][2]=A[2][0]; /*7 na 3*/
    A[1][0]=tmp1; /*2 na 4*/
    tmp1=A[1][2]; /*6*/
    A[1][2]=A[2][1]; /*8 na 6*/
    A[2][0]=tmp2; /*3 na 7*/
    A[2][1]=tmp1; /*6 na 8*/
    return A;
}

std::istream & operator >> (std::istream &Strm, Macierz &Mac)
{   
    Strm>>Mac[0]>>Mac[1]>>Mac[2];
    return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Macierz &Mac)
{
    Strm<<Mac[0]<<endl<<Mac[1]<<endl<<Mac[2]<<endl;
    return Strm;
}

const Wektor Macierz::operator* (const Wektor & W2) const /* Macierz*Wektor */ 
{
    return Wektor(tabM[0]*W2, tabM[1]*W2, tabM[2]*W2); /* Korzystam z wektor*wektor */
}

const Macierz Macierz::operator* (Macierz A) const /* Macierz*Macierz */
{
    Macierz B; 
    A=A.transpozycja();                                 /* Jesli bede mial problem i bede musiał napisac */
    B[0]=tabM[0];                                       /* w nawiasie const Macierz & A, to po prostu podmienie */
    B[1]=tabM[1];                                       /* i stworze sobie nowa zmienna typu Macierz zamiast */
    B[2]=tabM[2];                                       /* pod A podpisywac A=A.transpozycja();. */ 
    Macierz Wynik(B*A[0],B*A[1],B*A[2]);                /* Nie robie tego, bo nie chce aby ta funkcja zmieniala wartosc A */
    return Wynik.transpozycja();
}

const Macierz Macierz::operator * (double l) const
{
    Macierz Wynik;
    Wynik[0]=tabM[0]*l; Wynik[1]=tabM[1]*l; Wynik[2]=tabM[2]*l;
    return Wynik;
}

const Macierz Macierz::operator / (double l) const
{
    Macierz Wynik;
    Wynik[0]=tabM[0]/l; Wynik[1]=tabM[1]/l; Wynik[2]=tabM[2]/l;
    return Wynik;
}

const Macierz Macierz::operator + (const Macierz & A) const
{
    return Macierz(tabM[0]+A[0],tabM[1]+A[1],tabM[2]+A[2]);
}

const Macierz Macierz::operator - (const Macierz & A) const
{
    return Macierz(tabM[0]-A[0],tabM[1]-A[1],tabM[2]-A[2]);
}


