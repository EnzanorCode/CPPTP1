
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
    void setid(int id);
    void setdatedebut(Date datedebut);
    void setdatefin(Date datefin);
    void setidhotel(int idhotel);
    void setidchambre(int idchambre);
    int getid() const;
    Date getdatedebut() const;
    Date getdatefin() const;
    int getidhotel() const;
    int getidchambre() const;
    int getprix() const;
    int getidclient() const;
    void ModifierDateSejour(Date datedebut, Date datefin);
    int prix();
    int duresejour();
    int montantsejour();

    private :
    int _idreservation;
    Date _datedebut;
    Date _datefin;
    int _idhotel;
    int _idchambre;
    int _prix;
    int _idclient;
};
ostream& operator << (ostream& os, reservation& r1);

#endif