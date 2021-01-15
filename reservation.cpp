#include "reservation.h"
#include <iostream>




reservation::reservation(int idreservation, Date datedebut, Date datefin, Hotel hotel, Chambre chambre, Client client) 
{
    _idreservation = idreservation;
    _datedebut = datedebut;
    _datefin = datefin;
    _idhotel = hotel.getid();
    _idchambre = chambre.getid();
    _prix = chambre.getprix();
    _idclient = client.getid();
    _nomclient = client.getnom(); 
    
   
        
    for(int i=0; i < (datefin - datedebut);i++ ) 
    {
        chambre.ajouterdisponibilite(datedebut);
        datedebut.nextDay();
    }
    
}
reservation::reservation(){ //par default
    Date dateini(0000,1,1);
    Date dateini2(0000,1,2);
    _idreservation = 0;
    _datedebut = dateini;
    _datefin = dateini2;
    _idhotel =  0;
    _idclient = 0; 
    _nomclient = "jean";
    _client = Client();
    _chambre = Chambre();
}
void reservation::setid(int idreservation){
    _idreservation = idreservation;
}
void reservation::setdatedebut(Date datedebut){
    _datedebut = datedebut;
}
void reservation::setclient(Client client){
    _client = client;
    _idclient = client.getid();
 }
void reservation::setchambre(Chambre chambre){
    _chambre = chambre;
    _idchambre = chambre.getid();
 }
void reservation::setdatefin(Date datefin){
    _datefin = datefin;
}
void reservation::setidhotel(int idhotel) {
    _idhotel = idhotel;
}
void reservation::setidchambre(int idchambre){
    _idchambre = idchambre;
}
int reservation::getid() const{
    return _idreservation;
}
Date reservation::getdatedebut() const{
    return _datedebut;
}
Date reservation::getdatefin() const{
    return _datefin;
}
int reservation::getidhotel() const{
    return _idhotel;
}
int reservation::getidchambre() const{
    return _idchambre;
}
int reservation::getprix() const{
    return _prix;
}
string reservation::getnomclient() const{
    return _nomclient;
}
int reservation::getidclient() const{
    return _idclient;
}
void reservation::ModifierDateSejour(Date datedebut, Date datefin){
    //si la chambre est vide 
    _datedebut = datedebut;
    _datefin = datefin;
}
int reservation::prix(){
int nombrejour = _datedebut - _datefin;
return (nombrejour*_prix);
}
int reservation::duresejour(){
int a = _datefin - _datedebut;
return a;
}
int reservation::montantsejour(){
    int a = _datefin - _datedebut;
    a = a*_prix;
    return a;
}
  ostream& operator << (ostream& os, reservation& r1) {
    string b ="info reservation => | id : " + to_string(r1.getid()) + " | date de debut de sejour : " + r1.getdatedebut().toString() + " | date de fin de sejour : " + r1.getdatefin().toString() + " | id Hotel : " + to_string(r1.getidhotel()) + " | id Chambre : " + to_string(r1.getidchambre()) + " | id Client : " +  to_string(r1.getidclient()) + " | Montant sejour : " + to_string(r1.montantsejour()) ;
    os << b << endl; 
    return os;
}

 
