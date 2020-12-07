#include "reservation.h"
#include <iostream>



reservation::reservation(int idreservation, Date datedebut, Date datefin, Hotel hotel, Chambre chambre, Client client) {
    _idreservation = idreservation;
    _datedebut = datedebut;
    _datefin = datefin;
    _idhotel = hotel.getid();
    _idchambre = chambre.getid();
    _prix = chambre.getprix();
    _idclient = client.getid();
    

}
void reservation::setid(int idreservation){
    _idreservation = idreservation;
}
void reservation::setdatedebut(Date datedebut){
    _datedebut = datedebut;
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
int a = _datefin.dayindate() - _datedebut.dayindate();
return a;
}
int reservation::montantsejour(){
    int a = _datefin.dayindate() - _datedebut.dayindate();
    a = a*_prix;
    return a;
}
