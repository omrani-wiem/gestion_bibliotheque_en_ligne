#include "historique_commande.h"
#include <iostream>
#include "HistoriqueCommande.h"
#include <iostream>
void HistoriqueCommande::ajouter_commande(const Commande& commande) {
    commandes.push_back(commande);

void HistoriqueCommande::afficher_historique() const {
    if (commandes.empty()) {
        cout << "Aucune commande dans l'historique." << endl;
        return;
    }

    cout << "Historique des commandes : " << endl;

    for (int i = 0; i < commandes.size(); ++i) {

        commandes[i].afficher_commande();
    }
}

