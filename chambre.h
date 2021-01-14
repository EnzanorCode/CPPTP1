#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>
#include <vector>
#include "date.h"

using namespace std; 
using namespace date;

enum class Type {SIMPLE, DOUBLE, SUITE};

class Chambre{

public:

Chambre(int id,Type type,int prix);
int getid() const;
string gettype() const;
int getprix() const;
vector<Date> getdisponibilite() const;
void ajouterdisponibilite(Date date);
void setid(int id);
void settype(Type type);
void setprix(int prix);



private:

int _id;
Type _type;
int _prix;
vector<Date> _disponibilite;
};

ostream& operator << (ostream& os, Chambre& c1);


#endif 