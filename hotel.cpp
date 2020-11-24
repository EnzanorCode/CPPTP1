#include <iostream>
#include "hotel.h"
#include <string>


Hotel::Hotel(string id, string nom, string ville, vector<Chambre> list){
    _id = id;
    _nom = nom;
    _ville = ville;
    _list = list;
}

string Hotel::getid()
{
return _id;
}

string Hotel::getnom()
{
return _nom;
}

string Hotel::getville()
{
return _ville;
}

vector<Chambre> Hotel::getlist()
{
return _list;
}
void Hotel::ajouterChambre(Chambre chambre)
{
    _list.push_back(chambre);
}
