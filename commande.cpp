#include "commande.h"
#include <iostream>

commande::commande(int id_commande, string statut_commande, string date_commande)
    : id_commande(id_commande), statut_commande(statut_commande), date_commande(date_commande) {}

commande::~commande() {}

void commande::confirmer_commande() {
    statut_commande = "Confirmée";  // Change le statut de la commande
    std::cout << "La commande " << id_commande << " a été confirmée." << std::endl;
}

void commande::afficher_commande() {
    std::cout << "Commande ID: " << id_commande << std::endl;
    std::cout << "Statut: " << statut_commande << std::endl;
    std::cout << "Date: " << date_commande << std::endl;
}
