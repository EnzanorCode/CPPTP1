#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

using namespace std; 


enum class Type {SIMPLE, DOUBLE, SUITE};

class Chambre{

public:

Chambre(int id,Type type,int prix);
int getid() const;
string gettype() const;
int getprix() const;
void setid(int id);
void settype(Type type);
void setprix(int prix);



private:

int _id;
Type _type;
int _prix;

};

ostream& operator << (ostream& os, Chambre& c1);


#endif 