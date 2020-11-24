#ifndef CLIENT_H
#define CLIENT_H
#include <string>

using namespace std; 

class Client{

    public:

    Client(int id, string nom, string prenom, int reservation);
    

    int getid() const;
    void setid(int id);
    string getnom() const;
    void setnom(string nom);
    string getprenom() const;
    void setprenom(string prenom);
    int getreservation() const;
    void setreservation(int reservation);


    private:
    
    int _reservation;
    string _nom;
    string _prenom;
    int _id;

};

#endif 