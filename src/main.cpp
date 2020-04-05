#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/UkladRownanLiniowych.hh"


using namespace std;

int main()
{ 
  cout << endl << " Start programu " << endl << endl;
  Wektor D;
  cout<<"Wpisz wektor"<<endl;
  cin>>D;
  Wektor E;
  cout<<"Wpisz wektor"<<endl;
  cin>>E;
  ///double WynikD= D*E;
  cout<<"Iloczyn skalarny:"<<D*E<<endl;
  ///Wektor WynikW= D*2;
  cout<<"Wektor1 * 2:"<<D*2<<endl;
  cout<<"Dodane wektory:"<<D+E<<endl;
  cout<<"Odjete wektory:"<<D-E<<endl;
  double dl;
  dl=D.dlugosc();
  cout<<"Dlugosc wektora1:"<<dl<<endl;
  if(D==E)
  cout<<"wektor1=wektor2"<<endl;
  if(D!=E)
  cout<<"Wektor1!=Wektor2"<<endl;

  Macierz A;
  cout<<"Wpisz macierz:"<<endl;
  cin>>A;
  cout<<"Pierwszy wiersz:"<<A[0]<<endl;
  cout<<"Pierwszy wyraz:"<<A[0][0]<<endl;
  cout<<"Macierz normalna:"<<endl<<A<<endl;
  Macierz AT=A.transpozycja();
  cout<<"Macierz transponowana:"<<endl<<AT<<endl;
  Macierz B;
  cout<<"Wpisz macierz:"<<endl;
  cin>>B;
  cout<<"Macierz normalna:"<<endl<<B<<endl;
  Macierz BT=B.transpozycja();
  cout<<"Macierz transponowana:"<<endl<<BT<<endl;
  cout<<"Macierz1*Wektor1: "<<A*D<<endl<<endl;
  cout<<"Macierz1*Macierz2: "<<endl<<A*B<<endl;
  cout<<"Macierz1+Macierz2: "<<endl<<A+B<<endl;
  cout<<"Macierz1-Macierz2: "<<endl<<A-B<<endl;

  
}
