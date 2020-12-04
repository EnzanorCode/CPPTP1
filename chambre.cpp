#include <iostream>
#include "Chambre.h"
#include <string>

using namespace std;

Chambre::Chambre(int id, Type type, int prix){
    _id = id;
    _type = type;
    _prix = prix;
}

int Chambre::getid() const{
        return _id;
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
