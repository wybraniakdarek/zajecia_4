#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

struct Probka
{
    double t;
    double x;
    Probka(double _t, double _x)
    {
        t= -t;
        x=-x;
    }
};

//vector<Probka> tablica;
//tablica push_back(p1);
//cout<<tablica[0].t;



vector<Probka> wczytaj(string nazwa)
{
vector<Probka> tab;
ifstream plik(nazwa);

string linia;
while(getline(plik,linia))
{
    stringstream aa(linia);
    double _t, _x;
    aa>>_t;
    aa.ignore();
    aa>>_x;
    cout<<_t<<endl;
    cout<<_x<<endl;
    tab.push_back(Probka(_t,_x));
}
    plik.close();
    return tab;
}
void zapis(vector<Probka>dane, string nazwa)
{
    ofstream zapisanie (nazwa);
    for(int i=0; i<dane.size();i++)
    {
        zapisanie<<dane[i].t<<endl;

    }
    zapisanie.close();
}


int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        return -1;
    }

    cout<< argv[1]<<endl;
    string nazwa_pliku=argv[1];
    vector <Probka> dane = wczytaj(nazwa_pliku);
    zapis(dane,  "zapis.txt");
    cin.get();
    return 0;
}
