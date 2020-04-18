#include <iostream>
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Wektor.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/Macierz.hh"
#include "/home/rafaeldali/Pulpit/Dane do programów/zad3-zalazek/inc/UkladRownanLiniowych.hh"


using namespace std;

int main()
{ 
  UkladRownanLiniowych X;
  cout<<"Wpisz macierz i wektor:"<<endl;
  cin>>X;
  cout<<"Reprezentacja ukladu rownan:"<<endl;
  cout<<X;
  Wektor wynik=X.Cramer(X);
  X.blad(X,wynik); 
  cout<<"Rozwiazanie ukladu rownan:"<<wynik<<endl;
}
