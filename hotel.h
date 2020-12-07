#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include "chambre.h"
#include <vector>

using namespace std;


class Hotel{

public:
Hotel(int id, string nom, string ville, vector<Chambre> list);
int getid();
string getnom();
string getville();
vector<Chambre> getlist();
void ajouterChambre(Chambre chambre);


private:

int _id;
string _nom;
string _ville;
vector<Chambre> _list;


};

ostream& operator << (ostream& os, Hotel& h1);

#endif 