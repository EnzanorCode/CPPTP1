#include <iostream>
#include "Chambre.h"
#include <string>

using namespace std;

Chambre::Chambre(int id, Type type, int prix){
    _id = id;
    _type = type;
    _prix = prix;
}
Chambre::Chambre(){
    _id = 0;
    _type = Type::SIMPLE;
    _prix = 0 ;
}

int Chambre::getid() const{
        return _id;
    }

vector<Date> Chambre::getdisponibilite() const{
        return _disponibilite;
    }
void Chambre::ajouterdisponibilite(Date date){
    _disponibilite.push_back(date);
}

void Chambre::setid(int id){
    _id = id;
}

string Chambre::gettype() const{ 
        
        switch(_type){
            case Type::SIMPLE : return "simple"; break;
            case Type::DOUBLE : return "double"; break;
            case Type::SUITE : return "suite"; break;
            default : return "erreur"; break;
        }
    }
void Chambre::settype(Type type){
    _type = type;
}

int Chambre::getprix() const{
        return _prix;
    }

void Chambre::setprix(int prix){
    _prix = prix;

}

ostream& operator << (ostream& os, Chambre& c1) {
    string b ="info chambre => | id : " + to_string(c1.getid()) + " | Type : " + c1.gettype() + " | prix : " + to_string(c1.getprix());
    os << b << endl; 
    return os;
}