#include <iostream>
#include <string>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

using namespace std;
using namespace date;



reservation ajouterreservation(int idreservation,Hotel hotel, Chambre chambre, Client client){
	int jourdebut;
	int moisdebut;
	int annedebut;
	int jourfin;
	int moisfin;	
	int annefin;		
	cout << "entrer le jour du debut du sejour" << endl;
	cin >> jourdebut;
	cout << "entrer le mois du debut du sejour" << endl;
	cin >> moisdebut;
	cout << "entrer l'année du debut du sejour" << endl;
	cin >> annedebut;
	cout << "entrer le jour de fin du sejour" << endl;
	cin >> jourfin;
	cout << "entrer le mois de fin du sejour" << endl;
	cin >> moisfin;
	cout << "entrer l'année de fin du sejour" << endl;
	cin >> annefin;
	
	Date datedebut(annedebut,moisdebut,jourdebut);
	Date datefin(annefin,moisfin,jourfin);
	if ((datefin.dayindate() - datedebut.dayindate()) > 0 ){
	reservation reservation(idreservation,datedebut,datefin,hotel,chambre,client);
	return reservation;
	}
	else{
		Chambre chambre(0, Type::SIMPLE, 100);
		reservation reservation(-1,datedebut,datefin,hotel,chambre,client);
		return reservation;
	}
	
}
 int nombrenuitsejour(reservation reserv){
	Date d1 = reserv.getdatedebut();
	Date d2 = reserv.getdatefin();
	int c = d2.dayindate() - d1.dayindate();  
	if(c <=0 ){

	}
	else
	{
		return c;
	}
	
 }





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

 //////////////////////////////////////////////////////////////////////////////Test De l'ajout de date ////////////////////////////////////////////////////////////////////////////////////////////////////

 Date d1(2004,12,25);

 cout << d1.year() << endl;
 cout << d1.toString()<< endl;
//////////////////////////////////////////////////////////////////////////////Classe reservation ////////////////////////////////////////////////////////////////////////////////////////////////////

	Client client0(1,"nom1","prenom1",0);
	Chambre ChambreSimple10(100, Type::SIMPLE, 100);
	vector<Chambre> list;
	list.push_back(ChambreSimple10);
	Hotel hotel1(1,"hotel1","ville1",list);
	Date d1(2015,7,10);
	Date d2(2015,8,9);
	reservation reservation1(1,d1,d2,hotel1, ChambreSimple10,client0);
	
	cout << "duree du sejour : " << reservation1.duresejour() << endl;
	cout << "montant du sejour : " << reservation1.montantsejour() << endl;
	


*/


	//Question 6/a)
	Chambre ChambreSimple1(100, Type::SIMPLE, 100);
	Chambre ChambreSimple2(101, Type::SIMPLE, 100);
	Chambre ChambreSimple3(102, Type::SIMPLE, 100);
	
	Chambre ChambreDouble1(103, Type::DOUBLE, 125);
	Chambre ChambreDouble2(104, Type::DOUBLE, 125);
	Chambre ChambreDouble3(105, Type::DOUBLE, 125);
	Chambre ChambreDouble4(106, Type::DOUBLE, 125);
	Chambre ChambreDouble5(107, Type::DOUBLE, 125);

	Chambre ChambreSuite1(108, Type::SUITE, 210);
	Chambre ChambreSuite2(109, Type::SUITE, 210);

	vector<Chambre> ListChambre;

	Hotel hotel(1,"hotel1","ville1",ListChambre);
	
	hotel.ajouterChambre(ChambreSimple1);
	hotel.ajouterChambre(ChambreSimple2);
	hotel.ajouterChambre(ChambreSimple3);
	hotel.ajouterChambre(ChambreDouble1);
	hotel.ajouterChambre(ChambreDouble2);
	hotel.ajouterChambre(ChambreDouble3);
	hotel.ajouterChambre(ChambreDouble4);
	hotel.ajouterChambre(ChambreDouble5);
	hotel.ajouterChambre(ChambreSuite1);
	hotel.ajouterChambre(ChambreSuite2);

	//Question 6.b)
	
	//cout << ChambreSimple1;
	//cout << hotel;

	//Questtion 6.c)
	vector<Client> listClient;
	Client client1(1,"nom1","prenom1",0);
	Client client2(2,"nom2","prenom2",0);
	Client client3(3,"nom3","prenom3",0);
	Client client4(4,"nom4","prenom4",0);
	Client client5(5,"nom5","prenom5",0);
	Client client6(6,"nom6","prenom6",0);
	Client client7(7,"nom7","prenom7",0);
	Client client8(8,"nom8","prenom8",0);
	Client client9(9,"nom9","prenom9",0);
	Client client10(10,"nom10","prenom10",0);

	listClient.push_back(client1);
	listClient.push_back(client2);
	listClient.push_back(client3);
	listClient.push_back(client4);
	listClient.push_back(client5);
	listClient.push_back(client6);
	listClient.push_back(client7);
	listClient.push_back(client8);
	listClient.push_back(client9);
	listClient.push_back(client10);
	
	/* cout << client1;

	for(int i = 0 ; i < listClient.size() ; i++){                                                 6d
    cout << listClient[i];
    }
	*/
	//7 a)
	vector<reservation> listreservation;
	reservation newreserv = ajouterreservation(1,hotel,ChambreSimple1,client1);
	if (newreserv.getidchambre() == 0){ // si l'id de la chambre est 0 alors on n'ajoute pas la reservation a la liste des reservation, car aucune chambre ne peut avoir 0 en id dans mon progamme, de cette maniere si la date n'est pas valide, je place dans la reservation un 0 en id chambre qui me premet de detecter l'ereur
		
	}
	else {
		listreservation.push_back(newreserv);
		// cout << listreservation[0].getid();   verification de l'ajout de la reservation dans le vect 
	}
	/*
	cout << "nombre de nuit de la reservation" << endl;
	cout << nombrenuitsejour(newreserv);
	*/
cout << newreserv.getdatedebut().dayindate() << endl;
}
