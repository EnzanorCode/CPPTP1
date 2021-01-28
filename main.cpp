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
		cout << listreservation[i];
	}
}

void afficherreservation(vector<reservation> listreservation, int id_reservation) //11)b
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if(id_reservation == listreservation[i].getid())
		{
			cout << listreservation[i]; 
		}
	}
}

void afficherreservationclient(vector<reservation> listreservation, int id_client)//11)c
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if (id_client == listreservation[i].getidclient())
		{
			cout << listreservation[i]; 
		}
	}
}

void afficherreservationclient(vector<reservation> listreservation, Client c1)//11)c.2
{
	for(int i = 0 ; i<listreservation.size() ; i++)
	{
		if (c1.getid() == listreservation[i].getidclient())
		{
				cout << listreservation[i];
		}
		
	}
}

Client afficherclient(vector<Client> listeclient) //9)b
{
	vector<Client> nompotentiel;
	string nomclient = ""; 
	cout << "Rentrer le nom du client que vous cherchez : (Liste des clients Q6) : ";  //(parmi la liste de client mise en parametre de la fonction) 
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


Chambre chambredisponible(Date datedebut,Date datefin,Hotel hotel) //8-a)-b)
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
	cout << "entrer le type de chambre que vous voulez : (simple/double/suite) " << endl; 
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
								cout << "date de sejour possible pour ce type de chambre, id : " << hotel.getlist().at(i).getid()  << " au prix de : " <<hotel.getlist().at(i).getprix() << " Euros "<< endl;
								return hotel.getlist().at(i); 
							}
						}
					}
					else
					{
						cout <<"La chambre de type "<< hotel.getlist().at(i).gettype()  << " n'"<< hotel.getlist().at(i).getid()  <<" au prix de : " <<hotel.getlist().at(i).getprix() << "Euros est disponible.  "<< endl; //(cas ou la table reservation de la chambre est vide)
						return  hotel.getlist().at(i);
					}
					
				}
			}
			
		}

	cout << " pas de chambre de ce type disponible " << endl;  //8-c)
	return chambredisponible(datedebut,datefin,hotel);
		
	
}

int nombrenuitsejour(reservation reserv) //7-b)
{ 
	Date d1 = reserv.getdatedebut();
	Date d2 = reserv.getdatefin();
	int c = d2 - d1;  
	return c;
}

reservation ajouterreservation(int idreservation,Hotel hotel, Chambre chambre, Client client) //7-a)
{ 
	int jourdebut;
	int moisdebut;
	int annedebut;
	int jourfin;
	int moisfin;	
	int annefin;		
	cout << "entrer le jour du debut de votre sejour :" << endl;
	cin >> jourdebut;
	cout << "entrer le mois du debut de votre sejour :" << endl;
	cin >> moisdebut;
	cout << "entrer l'annee du debut de votre sejour :" << endl;
	cin >> annedebut;
	cout << "entrer le jour de fin de votre sejour :" << endl;
	cin >> jourfin;
	cout << "entrer le mois de fin de votre sejour :" << endl;
	cin >> moisfin;
	cout << "entrer l'annee de fin de votre sejour :" << endl;
	cin >> annefin;
	Date datedebut(annedebut,moisdebut,jourdebut);
	Date datefin(annefin,moisfin,jourfin);
	if ((datefin - datedebut) > 0) 
		{
		reservation reservation(idreservation,datedebut,datefin,hotel,chambre,client);
		cout << "reservation bien enregistree, nombre de nuit reservee : " <<  nombrenuitsejour(reservation) <<endl; //7-b)
		return reservation;
		}
	else
	{
		reservation reservation(-1,datedebut,datefin,hotel,chambre,client);
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
						for(int j=0 ; j<reserv.getchambre().getdisponibilite().size(); j++) //verif disponibilité des dates pour la chambre en question ! 
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

//PARTIE 1
//Question 1 : verification du bon focntionnement de la classe Date (avec surcharge "-" rajouter) 

cout << "Question 1 : test de la classe Date" << endl << endl; 
Date d1(2019,12,24);
Date d2(2019,12,5);
cout << "la date 1 est : " << d1.toString() << endl;
cout << "la date 2 est : "<< d2.day() << " / " << d2.month()  << " / " << d2.year() << endl;
cout << "la difference entre la date 1, et la date 2 est de " << d1-d2 << " jours." <<  endl << endl; //surchage de "-".

//Question 2 : verification du bon focntionnement de la classe Client. 

cout << "Question 2 : test de la classe Client : " << endl << endl;
string nom = "Villaverde";
string prenom = "Lucas";
Client client1(01,nom,prenom,46); //creation du client1 
//test des getters
cout << "l'id du client n'1 est : " << client1.getid() << endl;   
cout << "le nom du client n'1 est : " << client1.getnom() << endl;  
cout << "le prenom du client n'1 est : " <<  client1.getprenom() << endl;
cout << "le nombre de reservation du client n'1 est : "<< client1.getreservation() << endl;
cout << client1 << endl << endl;
//test des setters
string newnom ="Flantier";
string newprenom ="jean";
client1.setid(45);
client1.setnom(newprenom);
client1.setprenom(newnom);
client1.setreservation(84);
cout << "le nouvelle id du client n'1 est : " <<client1.getid() << endl;
cout << "le nouveau nom du client n'1 est : " << client1.getnom() << endl;
cout << "le nouveau prenom du client n'1 est : " << client1.getprenom() << endl;
cout << "le nouveau nombre de reservation du client n'1 est : "<< client1.getreservation() << endl << endl;

//Question 3 : verification du bon focntionnement de la classe Chambre. 

//test des getters
cout << "Question 3 : test de la classe Client : " << endl << endl;
Chambre chambre1(89,Type::SIMPLE,135);
cout << "L'id de la chambre n'1 est : " << chambre1.getid() << endl;
cout << "Le type de la chambre n'1 est : " << chambre1.gettype() << endl;
cout << "Le prix de la chambre n'1 est : " << chambre1.getprix() << endl;
//test des setters
chambre1.setid(1);
chambre1.settype(Type::DOUBLE);
chambre1.setprix(145);
cout << "le nouvelle id de la chambre n'1 est : " <<chambre1.getid() << endl;
cout << "Le nouveau type de la chambre n'1 est : " <<chambre1.gettype() << endl;
cout << "Le nouevau prix de la chambre n'1 est : " <<chambre1.getprix() << endl;
cout << chambre1 << endl << endl;

//Question 4 : verification du bon fonctionnement de la classe Hotel.

cout << "Question 4 : test de la classe Hotel :  " << endl << endl;
Chambre chambre2(2,Type::SIMPLE,150);
Chambre chambre3(3,Type::DOUBLE,174);
Chambre chambre4(4,Type::SUITE,195);
vector<Chambre> ChambreDeBase;
ChambreDeBase.push_back(chambre1);
ChambreDeBase.push_back(chambre2);
ChambreDeBase.push_back(chambre3);
Hotel hotel_1(1,"nom_hotel","ville_hotel",ChambreDeBase);
cout << "L'id de l'hotel_1 est : " << hotel_1.getid() << endl;
cout << "Le nom de l'hotel_1 est : " << hotel_1.getnom() << endl;
cout << "La ville de l'hotel_1 est : " << hotel_1.getville() << endl;
cout << "La chambre renter en premier dans le tableau des chambres possede l'id : " << hotel_1.getlist().at(0).getid() << endl;
//b)
hotel_1.ajouterChambre(chambre4);
cout << "Le Type de la chambre n'4 rajouter dans le tableau de chambre : " << hotel_1.getlist().at(3).gettype() << endl << endl;


//Question 5 : verification du bon fonctionnement de la classe Reservation.

cout << "Question 5 : test de classe reservation : " << endl << endl;
Client client0(1,"nom1","prenom1",0);
reservation reservation1(95,d2,d1,hotel_1,chambre1,client1); // creation de la reservation  	
cout << reservation1;
cout << "La duree du sejour : " << reservation1.duresejour() << endl;
cout << "Le montant du sejour : " << reservation1.montantsejour() << endl;
Date d3(2020,2,16);
Date d4(2020,2,24);
reservation1.setdatedebut(d3);
reservation1.setdatefin(d4);
reservation1.setidchambre(5);
cout << reservation1 << endl;
	
//PARTIE 2 
//Question 6 : Creation d'un hôtel et de clients

//a)
cout << "Question 6 : Creation d'un hotel et clients : " << endl << endl;
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
Hotel hotel(1,"hotel_1","ville_1",ListChambre);
//b)
cout << "Voici les informations de la chambre simple 1 : " << endl;
cout << ChambreSimple1 << endl;
cout << "Voici les informations de l'hotel : ";
cout << hotel;
//c)
vector<Client> listClient;
Client client10(1,"nom1","prenom1",1);
Client client11(2,"nom2","prenom2",1);
Client client12(3,"nom3","prenom3",2);
Client client13(4,"nom4","prenom4",0);
Client client14(5,"nom5","prenom5",0);
Client client15(6,"nom6","prenom6",0);
Client client16(7,"nom9","prenom7",0);
Client client17(8,"nom9","prenom8",0);
Client client18(9,"nom9","prenom9",0);
Client client19(10,"nom10","prenom10",0);
listClient.push_back(client10);
listClient.push_back(client11);
listClient.push_back(client12);
listClient.push_back(client13);
listClient.push_back(client14);
listClient.push_back(client15);
listClient.push_back(client16);
listClient.push_back(client17);
listClient.push_back(client18);
listClient.push_back(client19);
//d)
cout << endl <<"voici les info du client n'12 : " << endl << client12 << endl;
cout << "Voici les informations de tout les clients : " << endl;
for(int i = 0 ; i < listClient.size() ; i++)
{                                                 
	cout << listClient[i];
}
cout << endl; 
//Question 7 : Validation des dates de reservations 

//a)
cout << "Question 7 : Validation des dates de reservations : " << endl << endl; 
cout << "Saisissez les dates de votre reservation : " << endl;
vector<reservation> listreservation;
reservation newreserv = ajouterreservation(1,hotel,ChambreSimple1,client1);
if (newreserv.getid() == -1) //controle d'erreur (-1 est la valeur attribué si les dates ne sont pas corrects)
{ 
	return 0;
}
else 
{
	listreservation.push_back(newreserv); //ajout de la reservation a la chambre
	cout << "La chambre avec l'id " <<  listreservation[0].getid() << " a bien ete reserverve ";   //verification de l'ajout de la reservation dans le vect 
}
//b) Test de la fonction Nombre nuit sejour (a été inseré dans la fonction ajouterreservation précédemment realisé)
if (nombrenuitsejour(newreserv)==0){return 0;}
cout << "voici le nombre de nuit votre reservation : " << nombrenuitsejour(newreserv) <<" nuit(s)" << endl << endl;


//Question 8 : Choix d'une chambre 

cout << "Question 8 : Choix d'une chambre :" << endl << endl;
Date datedebut(2020,1,14);
Date datefin(2020,1,17);
cout << "Verification de la disponibilite d'une chambre (sur une periode precise dans un hotel precis) : " << endl;
Chambre chambreQ8 = chambredisponible(datedebut,datefin,hotel);
cout << "Verification de l'attribution de la chambre : " << endl;
cout << "La chambre de type \"" << chambreQ8.gettype() << "\" a bien ete reservee " << endl << endl;

//Question 9 : Choix du client 

cout << "Question 9 : Choix du client :" << endl << endl;
Client c1 = afficherclient(listClient);
cout <<"le client selectionne est : "<< c1 << endl << endl;

//Question 10 : Validation de la réservation

//creation de 4 reservations 
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
reservation reserv10(1,datedebut1,datefin1,hotel,ChambreDouble1,client10);
reservation reserv20(2,datedebut2,datefin2,hotel,ChambreSimple2,client11);
reservation reserv30(3,datedebut3,datefin3,hotel,ChambreSuite2,client12);
reservation reserv40(4,datedebut4,datefin4,hotel,ChambreSimple3,client12); //Deux reservation pour le client numero 3 
vector<reservation> listreservation2;
//b)
listreservation2.push_back(reserv10);
listreservation2.push_back(reserv20);
listreservation2.push_back(reserv30);
listreservation2.push_back(reserv40);

cout << "Question 10 : Validation de la reservation" << endl << endl;
//a)
cout << "Montant de la reservation n'1 : "<< reserv10.montantsejour() <<" Euros. "<<endl; 
//b)
cout << "Test de l'affichage de la reservation (situe dans le tableau de reservation en premiere position )  : "<< endl << listreservation2[0] << endl << endl; //afficher la nouvelle reservation  b)


//Question 11 : Gestion des réservations

cout << "Question 11 : Gestion des reservations :" << endl << endl;
//a)
cout << "a) Affichage de la liste des reservations : " << endl; 
afficherreservation(listreservation2);
cout << endl;
//b)
cout << "b) affichage de la reservation qui possede l'id n'2 :" << endl;
afficherreservation(listreservation2,2);
cout << endl; 
//c)
cout << "c) voici la listes des reservations faites par le client posssedant l'identifiant n'1 : " << endl;
afficherreservationclient(listreservation2,1);
cout << endl <<"choix du client afin d'afficher sa liste de de reservation " << endl;
Client c11 = afficherclient(listClient); // Choix du client
afficherreservationclient(listreservation2,c11);	//Affichage de sa liste de reservation 	 //si par exemple on entre "nom3" on remarque que nom est associé au client 12 (Q6) et que le client 12 a bien fait deux reservation, les reservations qui possede l'id2 et 3(Q10) 
//d)
cout <<"d)" <<endl;
modifierreservation(listreservation2,listClient,ListChambre);
/*
//11)e
annulerreservation(listreservation);
cout << "verfication de l'annulation de la reservation " << endl;
for(int i=0; i<listreservation.size(); i++)
{
	cout << listreservation[i] <<endl;
}
*/
}
	
