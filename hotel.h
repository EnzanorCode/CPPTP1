#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include "chambre.h"
#include <vector>

using namespace std;
using namespace CHAMBRE;

class Hotel{

public:
Hotel(string id, string nom, string ville, vector<Chambre> list);
string getid();
string getnom();
string getville();
vector<Chambre> getlist();
void ajouterChambre(Chambre chambre);


private:

string _id;
string _nom;
string _ville;
vector<Chambre> _list;


};

#endif 