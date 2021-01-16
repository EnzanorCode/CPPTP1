#include <iostream>
#include <string>
#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"
#include <vector>

using namespace std;
using namespace date;



void afficherreservation(vector<reservation> listreservation) //11)a
{	
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		cout << listreservation[i] << endl;
	}
}

void afficherreservation(vector<reservation> listreservation, int id_reservation) //11)b
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if(id_reservation == listreservation[i].getid())
		{
			cout << listreservation[i] << endl; 
		}
	}
}

void afficherreservationclient(vector<reservation> listreservation, int id_client)//11)c
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if (id_client == listreservation[i].getidclient())
		{
			cout << listreservation[i] << endl; 
		}
	}
}

void afficherreservationclient(vector<reservation> listreservation, Client c1)//11)c.2
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if (c1.getid() == listreservation[i].getidclient())
		{
				cout << listreservation[i] << endl;
		}
	}
}

Client afficherclient(vector<Client> listeclient) //9)b
{
	vector<Client> nompotentiel;
	string nomclient = ""; 
	cout << "rentrer le nom du client que vous cherchez : " << endl; 
 	cin >> nomclient;
	for (int i=0; i<listeclient.size(); i++)
	{
		if (listeclient[i].getnom() == nomclient)
		{
			nompotentiel.push_back(listeclient[i]);
		}
	}
	int compteur = 0 ;
	for (int i = 0; i < nompotentiel.size() ; i++ )
	{
		cout << nompotentiel[i] << endl;
		compteur++;
	}
	if(compteur == 0)
	{
		cout << "Aucun nom ne correspond veuillez reessayer" << endl;
		return afficherclient(listeclient); 
	}
	else if (compteur == 1 )
	{
		return nompotentiel.at(0);
	}
	else
	{
		int id = 0 ;
		cout << "veuillez choisir l'id du client : " << endl;
		cin >> id;
		for (int i = 0; i < nompotentiel.size() ; i++ )
		{
			if(nompotentiel.at(i).getid() == id )
			{ 
				return nompotentiel.at(i);
			}
		}
	}
	

}

Chambre afficherchambre(vector<Chambre> listechambre) //9)b
{
	vector<Chambre> chambrepotentiel;
	int idchambre = 0; 
	for (int i=0; i<listechambre.size(); i++)
	{
		cout << listechambre[i] << endl;
	}
	cout << "rentrer l'id de la chambre que vous souhaité selectionner : " << endl; 
 	cin >> idchambre;
	for (int i=0; i<listechambre.size(); i++)
	{
		if(idchambre == listechambre[i].getid())
		{
			return listechambre[i];
		}
	}

}


Chambre chambredisponible(Date datedebut,Date datefin,Hotel hotel) //8)a
{	
	Date dateinitiale(0,1,1);
	vector<Date> sejour;
	sejour.push_back(dateinitiale);
	
	for (int i=0; i < (datefin - datedebut) ; i++)  //i parcourt le sejour grace a NextDay
	{
		sejour.push_back(datedebut);
		datedebut.nextDay();
	}

	for (int i = 0; i<hotel.getlist().size() ; i++) //affichage des chambres de hotel
	{
		hotel.getlist().at(i);
	}

	string typechambre = ""; 
	cout << "entrer le type de chambre que vous voulez" << endl; 
	cin >> typechambre;
	for (int i=0 ; i < hotel.getlist().size() ; i++ )
		{
			if(typechambre == hotel.getlist().at(i).gettype())
			{
				for(int k=0 ; k< sejour.size() ; k++)
				{	
					if(hotel.getlist().at(i).getdisponibilite().size() != 0 ) 
					{
						for(int j=0 ; j< hotel.getlist().at(i).getdisponibilite().size(); j++)
						{ 
							if( sejour[k] == hotel.getlist().at(i).getdisponibilite().at(j))
							{		
							}
							else
							{
								cout << "date de sejour est possible, pour ce type de chambre, id : " << hotel.getlist().at(i).getid()  << "/ prix : " <<hotel.getlist().at(i).getprix() << "Euros "<< endl;
								return hotel.getlist().at(i); 
							}
						}
					}
					else
					{
						cout <<" chambre disponible, identifiant : "<< hotel.getlist().at(i).getid()  <<"/ prix : " <<hotel.getlist().at(i).getprix() << "Euros "<< endl; //(cas ou la table reservation de la chambre est vide)
						return  hotel.getlist().at(i);
					}
					
				}
			}
			
		}

	cout << " pas de chambre de ce type disponible " << endl;  //8)c
	return chambredisponible(datedebut,datefin,hotel);
		
	
}

int nombrenuitsejour(reservation reserv) //7)b
{ 
	Date d1 = reserv.getdatedebut();
	Date d2 = reserv.getdatefin();
	int c = d2 - d1;  
	return c;
}

reservation ajouterreservation(int idreservation,Hotel hotel, Chambre chambre, Client client) //7)a
{ 
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
	cout << "entrer l'annee du debut du sejour" << endl;
	cin >> annedebut;
	cout << "entrer le jour de fin du sejour" << endl;
	cin >> jourfin;
	cout << "entrer le mois de fin du sejour" << endl;
	cin >> moisfin;
	cout << "entrer l'annee de fin du sejour" << endl;
	cin >> annefin;
	Date datedebut(annedebut,moisdebut,jourdebut);
	Date datefin(annefin,moisfin,jourfin);
	if ((datefin.dayindate() - datedebut.dayindate()) > 0 )
		{
		reservation reservation(idreservation,datedebut,datefin,hotel,chambre,client);
		cout << "reservation bien enregistree, nombre de nuit reservee : " <<  nombrenuitsejour(reservation) <<endl;
		return reservation;
		}
	else
		{
		Chambre chambre(0, Type::SIMPLE, 100);
		reservation reservation(-1,datedebut,datefin,hotel,chambre,client); // si id vaut -1 alors erreur
		return reservation;
		}
	
}
void modifierreservation(vector<reservation> listreservation,vector<Client> listeclient, vector<Chambre> listechambre) //11.d
{
	string choixmodif ="";
	int idreservation = 0;
	reservation reserv; 
	cout << "vous souhaitez modifier quelle reservation ? (entre l'id) : " << endl;
	afficherreservation(listreservation);
	cin >> idreservation;	
	for(int i =0 ; i< listreservation.size() ; i++)
	{
		if(idreservation == listreservation[i].getid())
		{
			cout << "Vous souhaitez modifier : " << listreservation[i] << endl;
			reserv = listreservation[i];
			cout << "que souhaitez vous modifier dans votre reservation : (client/chambre/date) "<< endl;
			cin >> choixmodif;
			if(choixmodif == "client") 
			{
				cout << "vous souhaitez modifier le client" << endl;  
				Client c1 = afficherclient(listeclient);
				reserv.setclient(c1);
				cout << "reservation mise a jour" << endl;
				cout << reserv << endl;
			}
			else if (choixmodif == "date")
			{	
				reserv = listreservation[i];
				int annee1, mois1, jour1, annee2, mois2, jour2;
				cout <<" sur quelle periode voulez vous votre nouvelle chambre pour votre reservation" << endl;
				cout << "entrer l'annee de la nouvelle date de debut : " << endl; 
				cin >> annee1;
				cout << "entrer le mois de la nouvelle date de debut : " << endl; 
				cin >> mois1;
				cout << "entrer le jours de la nouvelle date de debut : " << endl;                                
				cin >> jour1; 
				Date datedebut(annee1,mois1,jour1);
				Date copy = datedebut;
				cout << "entrer l'annee de la nouvelle date de fin : " << endl; 
				cin >> annee2;
				cout << "entrer le mois de la nouvelle date de fin : " << endl; 
				cin >> mois2;
				cout << "entrer le jours de la nouvelle date de fin : " << endl;                                
				cin >> jour2; 
				Date datefin(annee2,mois2,jour2);
				Date dateinitiale(0,1,1);
				vector<Date> sejour;
				sejour.push_back(dateinitiale);
				for (int i=0; i < (datefin - datedebut) ; i++)
				{
					sejour.push_back(copy);
					copy.nextDay();
				}
				for(int k=0 ; k< sejour.size() ; k++)
				{	
					if(reserv.getchambre().getdisponibilite().size() != 0 ) 
					{
						for(int j=0 ; j<reserv.getchambre().getdisponibilite().size(); j++)                 //verif disponibilité des dates pour la chambre en question ! 
						{ 
							if( sejour[k] == reserv.getchambre().getdisponibilite().at(j))
							{		
							}
							else
							{
								cout << "date de sejour est possible: " << endl;
								reserv.setdatedebut(datedebut);
								reserv.setdatefin(datefin);
							}
						}
					}
					else
					{
						reserv.setdatedebut(datedebut);
						reserv.setdatefin(datefin);
					}
				}
		
				cout << "reservation mise a jour" << endl;
				cout << reserv << endl;
			}
		
			else if (choixmodif == "chambre")
			{
				int annee1, mois1, jour1, annee2, mois2, jour2;
				cout <<" sur quelle periode voulez vous votre nouvelle chambre pour votre reservation" << endl;
				cout << "entrer l'annee de la nouvelle date de debut : " << endl; 
				cin >> annee1;
				cout << "entrer le mois de la nouvelle date de debut : " << endl; 
				cin >> mois1;
				cout << "entrer le jours de la nouvelle date de debut : " << endl;                                
				cin >> jour1; 
				Date datedebut(annee1,mois1,jour1);
				Date copy = datedebut;
				cout << "entrer l'annee de la nouvelle date de fin : " << endl; 
				cin >> annee2;
				cout << "entrer le mois de la nouvelle date de fin : " << endl; 
				cin >> mois2;
				cout << "entrer le jours de la nouvelle date de fin : " << endl;                                
				cin >> jour2; 
				Date datefin(annee2,mois2,jour2);
				Date dateinitiale(0,1,1);
				vector<Date> sejour;
				sejour.push_back(dateinitiale);
				for (int i=0; i < (datefin - datedebut) ; i++)
				{
					sejour.push_back(copy);
					copy.nextDay();
				}
				cout << "vous souhaitez choisir quelle chambre ? " << endl;     
				Chambre chambre1 = afficherchambre(listechambre);	//selection de la chambre 
				for(int k=0 ; k< sejour.size() ; k++)
					{	
						if(chambre1.getdisponibilite().size() != 0 ) 
						{
							for(int j=0 ; j<chambre1.getdisponibilite().size(); j++)      //verif disponibilité pour la chambre selectionner 
							{ 
								if( sejour[k] == chambre1.getdisponibilite().at(j))
								{		
								}
								else
								{
									cout << "date de sejour est possible, pour ce type de chambre, id : " << chambre1.getid()  << "/ prix : " << chambre1.getprix() << "Euros "<< endl;
									reserv.setchambre(chambre1);
									reserv.setdatedebut(datedebut);
									reserv.setdatefin(datefin);
								}
							}
						}
				
						else
						{
							reserv.setchambre(chambre1);	
							reserv.setdatedebut(datedebut);
							reserv.setdatefin(datefin);
						}
					}
		
				cout << "reservation mise a jour" << endl;
				cout << reserv << endl;
			}
		}
	}
}
/*
void annulerreservation(vector<reservation> listereservation){

	int idsupp;
	for(int i =0; i < listereservation.size() ;i++) 
	{
		cout << listereservation[i] << endl;
	}
	cout << "veuillez choisir l'id de la reservation que vous souhaité supprimer " << endl;
	cin >> idsupp;
	for(int i = 0 ; i<listereservation.size(); i++)
	{
		if(idsupp == listereservation[i].getid())
		{
			for(int y = 0; y < listereservation[i].getchambre().getdisponibilite().size(); y++)
			if(listereservation[i].getdatedebut() == listereservation[i].getchambre().getdisponibilite().at(y))
			{
				Date removedate = listereservation[i].getdatedebut();
				Date datefinplus1 = listereservation[i].getdatefin();
				datefinplus1.nextDay();
				while(removedate != datefinplus1);
				{
					auto it = remove(listereservation[i].getchambre().getdisponibilite().begin(), listereservation[i].getchambre().getdisponibilite().end(), removedate)
					listereservation[i].getchambre().getdisponibilite().erase(it , listereservation[i].getchambre().getdisponibilite().end()); //date de fin
					removedate.nextDay();
				}
				
			}
				
		}
	}
}
*/


int main(){


//  QUESTION 1 //////////////////////////////////////////////////////////////TEST DE DATE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Date d1(2019,12,24);
cout << "la date est : " << d1.toString() << endl;
cout << "la date  : "<< d1.day() << " / " << d1.month()  << " / " << d1.year() << endl;


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
	

//Question 6/a)
	*/
vector<Chambre> ListChambre;
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
ListChambre.push_back(ChambreSimple1);
ListChambre.push_back(ChambreSimple2);
ListChambre.push_back(ChambreSimple3);
ListChambre.push_back(ChambreDouble1);
ListChambre.push_back(ChambreDouble2);
ListChambre.push_back(ChambreDouble3);
ListChambre.push_back(ChambreDouble3);
ListChambre.push_back(ChambreDouble4);
ListChambre.push_back(ChambreDouble5);
ListChambre.push_back(ChambreSuite1);
ListChambre.push_back(ChambreSuite2);

Hotel hotel(1,"hotel1","ville1",ListChambre);
	
//Question 6.b)
	
//cout << ChambreSimple1;
//cout << hotel;

//Questtion 6.c)
vector<Client> listClient;
	
Client client1(1,"nom1","prenom1",1);
Client client2(2,"nom2","prenom2",1);
Client client3(3,"nom3","prenom3",2);
Client client4(4,"nom4","prenom4",0);
Client client5(5,"nom5","prenom5",0);
Client client6(6,"nom6","prenom6",0);
Client client7(7,"nom9","prenom7",0);
Client client8(8,"nom9","prenom8",0);
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
	
// << client1;

/*
//Question 6.b)
for(int i = 0 ; i < listClient.size() ; i++)
	{                                                 
cout << listClient[i];
    }
	
*/
//7 a)
/*
vector<reservation> listreservation;
reservation newreserv = ajouterreservation(1,hotel,ChambreSimple1,client1);

if (newreserv.getidchambre() == -1)
	{ // si l'id de la chambre est 0 alors on n'ajoute pas la reservation a la liste des reservation, car aucune chambre ne peut avoir -1 en id dans mon progamme, de cette maniere si la date n'est pas valide, je place dans la reservation un -1 en id chambre qui me premet de detecter l'ereur
		return 0;
	}
	else {
		listreservation.push_back(newreserv);
		cout << "La chambre avec l'id " <<  listreservation[0].getid() << " a bien ete ajoute ";   //verification de l'ajout de la reservation dans le vect 
	}

	
	//7 b) Test de la fonction Nombre nuit sejour 
if (nombrenuitsejour(newreserv)==0){return 0;}
cout << "Voici le nombre de nuit votre reservation : " << endl;
cout << nombrenuitsejour(newreserv) << endl;


*/

	//8.a,b,c) verif
Date datedebut(2020,1,14);
Date datefin(2020,1,17);
cout << "QUESTION 8 : Verification de la disponibilite d'une chambre (sur une periode donnee dans un hotel donne) : " << endl;
Chambre chambreQ8 = chambredisponible(datedebut,datefin,hotel);
cout << chambreQ8 << endl;
	
   //9a,b,c) verif

Client c1 = afficherclient(listClient);
cout <<"le client selectionne est : "<< c1 << endl;

	//10
	Date datedebut1(2021,1,1);
	Date datedebut2(2021,2,1);
	Date datedebut3(2021,3,1); 
	Date datedebut4(2021,4,1);
	Date datedebut5(2021,5,1);
	Date datefin1(2021,1,3);
	Date datefin2(2021,2,3);
	Date datefin3(2021,3,3);
	Date datefin4(2021,4,3);
	Date datefin5(2021,5,3);
	
	reservation reserv10(1,datedebut1,datefin1,hotel,ChambreDouble1,client1);
	reservation reserv20(2,datedebut2,datefin2,hotel,ChambreSimple2,client2);
	reservation reserv30(3,datedebut3,datefin3,hotel,ChambreSuite2,client3);
	reservation reserv40(4,datedebut4,datefin4,hotel,ChambreSimple3,client3); //Deux reservation pour le client numero 3 
	vector<reservation> listreservation;
	listreservation.push_back(reserv10);
	listreservation.push_back(reserv20);
	listreservation.push_back(reserv30);
	listreservation.push_back(reserv40);

	cout << "Montant de la reservation n°10 "<<reserv10.montantsejour() << endl; // calculer le prix exact du sejour a)
	cout << "Test de l'affichage de la reservation : "<< reserv10 << endl; //afficher la nouvelle reservation  b)

	//11)a
	cout << "liste des reservations : " << endl; 
	afficherreservation(listreservation);
	//11)b
	cout << "affichage de la reservation qui possede l'id n'2 :" << endl;
	afficherreservation(listreservation,2);
	//11)c
	cout << "voici la liste des reservation faite par le client posssedant l'identifiant n'3 : " << endl;
	afficherreservationclient(listreservation,3);
	cout << "choix du client afin d'afficher sa liste de de reservation " << endl;
	Client c11 = afficherclient(listClient); // Choix du client
	afficherreservationclient(listreservation,c11);	//Affichage de sa liste de reservation 	 
	//11)d
	modifierreservation(listreservation,listClient,ListChambre);
	//11)e
	
	/*
	annulerreservation(listreservation);
	cout << "verfication de l'annulation de la reservation " << endl;
	for(int i=0; i<listreservation.size(); i++)
	{
		cout << listreservation[i] <<endl;
	}
	*/
}
	
