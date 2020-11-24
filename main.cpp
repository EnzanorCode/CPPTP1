#include <iostream>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"

using namespace std;
using namespace CHAMBRE;

int main(){

/*
//////////////////////////////////////////////////////////////////////TEST DE DATE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Date d1(12,25);
cout << "la date est : " << d1.toString() << endl;
cout << "le mois : " << d1.getMonth() << endl;
cout << "le jour : " << d1.getDay() << endl;

//////////////////////////////////////////////////////////////////////test client/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string nom = "Andres";
string prenom = "Robert";
Client c1(01,nom,prenom,46);
cout << c1.getid() << endl;
cout << c1.getnom() << endl;
cout << c1.getprenom() << endl;
cout << c1.getreservation() << endl;
   
string newnom ="jean";
string newprenom ="claude";
c1.setid(45);
c1.setnom(newprenom);
c1.setprenom(newnom);
c1.setreservation(84);

cout << c1.getid() << endl;
cout << c1.getnom() << endl;
cout << c1.getprenom() << endl;
cout << c1.getreservation() << endl;
/////////////////////////////////////////////////////////////////////Test de Chambre//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chambre c1(52,Type::SIMPLE,19996);
cout << c1.getid() << endl;
cout << c1.gettype() << endl;
cout << c1.getprix() << endl;

c1.setid(56);
c1.settype(Type::DOUBLE);
c1.setprix(999);

cout << c1.getid() << endl;
cout << c1.gettype() << endl;
cout << c1.getprix() << endl;

//////////////////////////////////////////////////////////////////////////////Test de Hotel///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Chambre c1(1,Type::SIMPLE,150);
Chambre c2(2,Type::DOUBLE,174);
vector<Chambre> ChambreDeBase;
ChambreDeBase.push_back(c1);
ChambreDeBase.push_back(c2);
Hotel hotel("hetelid","hotelnom","hotelville",ChambreDeBase);
 
cout << hotel.getid() << endl;
cout << hotel.getnom() << endl;
cout << hotel.getville() << endl;
cout << hotel.getlist().at(1).get() << endl;
*/
 //////////////////////////////////////////////////////////////////////////////Test De l'ajout de year dans date ////////////////////////////////////////////////////////////////////////////////////////////////////

 Date d1(12,25,2004);

 cout << d1.getYear() << endl;
 d1.setYear(2007) ;
cout << d1.getYear() << endl;


}
