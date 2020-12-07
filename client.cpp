#include <iostream>
#include "client.h"
#include <string>

using namespace std;


    Client::Client(int id, string nom, string prenom, int reservation){
    _id = id;
    _nom = nom;
    _prenom = prenom;
    _reservation = reservation;
    }

    int Client::getid() const{
        return _id;
    }
    void Client::setid(int id){
        _id = id;
    }

    string Client::getnom() const{
    return _nom;
    }
    void Client::setnom(string nom){
        _nom = nom;
    }
   
   string Client::getprenom() const{
    return _prenom;
    }
   void Client::setprenom(string prenom){
        _prenom = prenom;
    }
    int Client::getreservation() const{
        return _reservation;
    }
    void Client::setreservation(int reservation){
        _reservation = reservation;
    }
    ostream& operator << (ostream& os, Client& c1) {
    string b ="info client => | id : " + to_string(c1.getid()) + " | nom : " + c1.getnom() + " | prenom : " + c1.getprenom() + " | Nombre de reservation : " + to_string(c1.getreservation());
    os << b << endl; 
    return os;
    }
