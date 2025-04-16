#ifndef HISTORIQUE_COMMANDE_H_INCLUDED
#define HISTORIQUE_COMMANDE_H_INCLUDED
#include "commande.h"
#include <vector>

class HistoriqueCommande {
private:
    vector<Commande> commandes;

public:
    void ajouter_commande(const Commande& commande);
    void afficher_historique();
};

#endif

