#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#include <string>
using namespace std;

class commande {
private:
    int id_commande;
    string statut_commande;
    string date_commande;

public:
    commande(int id_commande, string statut_commande, string date_commande);  // Constructeur
    ~commande();  // Destructeur
    void confirmer_commande();  // M�thode pour confirmer la commande
    void afficher_commande();  // M�thode pour afficher la commande
};

#endif // COMMANDE_H_INCLUDED
