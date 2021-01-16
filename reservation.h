
#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"


using namespace date;

class reservation {

    public :
    reservation(int idreservation, Date datedebut, Date datefin, Hotel hotel, Chambre chambre, Client client);
    reservation();
    void setid(int id);
    void setdatedebut(Date datedebut);
    void setdatefin(Date datefin);
    void setidhotel(int idhotel);
    void setidchambre(int idchambre);
    void setchambre(Chambre chambre);
    void setclient(Client client);
    int getid() const;
    Date getdatedebut() const;
    Date getdatefin() const;
    int getidhotel() const;
    int getidchambre() const;
    Chambre getchambre();
    string getnomclient() const;
    int getprix() const;
    int getidclient() const;
    void ModifierDateSejour(Date datedebut, Date datefin);
    int prix();
    int duresejour();
    int montantsejour();

    private :
    Client _client;
    Chambre _chambre;
    int _idreservation;
    Date _datedebut;
    Date _datefin;
    int _idhotel;
    int _idchambre;
    int _prix;
    int _idclient;
    string _nomclient;
};
ostream& operator << (ostream& os, reservation& r1);

#endif