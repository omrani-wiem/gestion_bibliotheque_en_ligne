#ifndef FOURNISSEUR_H_INCLUDED
#define FOURNISSEUR_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;
class fournisseur {
private:
    int id_four;
    string nom_four;

public:
    // Constructeur
    fournisseur(int id_four, string nom_four);
    // Destructeur
    ~fournisseur();
    //fonction
    void envoyer_demande_approvisionnement();
    //fonctions CRUD
    void create_f();
    void read_f() const;
    void update_f();
    void supprimer_f();
    // Surcharge des opérateurs << et >>
    friend ostream& operator<<(ostream& os, const fournisseur& f);
    friend istream& operator>>(istream& is, fournisseur& f);
};
#endif
