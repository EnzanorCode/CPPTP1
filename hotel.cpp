#include <iostream>
#include "hotel.h"
#include <string>


Hotel::Hotel(int id, string nom, string ville, vector<Chambre> list){
    _id = id;
    _nom = nom;
    _ville = ville;
    _list = list;
}

int Hotel::getid()
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

ostream& operator << (ostream& os, Hotel& h1){
    string b ="info hotel => | id : " + to_string(h1.getid()) + " | Nom : " + h1.getnom() + " | ville : " + h1.getville() + " | list chambre : ";
    os << b << endl;
     for(int i = 0 ; i < h1.getlist().size() ; i++){
        os << h1.getlist()[i];
    }
    return os;
}