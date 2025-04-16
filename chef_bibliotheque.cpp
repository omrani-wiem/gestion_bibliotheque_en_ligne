
#include "chef_bibliotheque.h"
#include <iostream>

ChefBibliotheque::ChefBibliotheque(string nom, string prenom, string email, string motDePasse,
                                   int id, int statut_connexion, int niveau_acces,
                                   string CIN, string num_chef)
    :administrateur(nom, prenom, email, motDePasse,id, statut_connexion),gestionnaire(nom, prenom, email, motDePasse, id, niveau_acces, stock),
      CIN(CIN), num_chef(num_chef) {}

ChefBibliotheque::~ChefBibliotheque() {}

void ChefBibliotheque::afficherInfosChef() {
    cout << "Chef Bibliothèque: " << gestionnaire::getnom() << " " << gestionnaire::getprenom() << endl;
    cout << "CIN: " << CIN << ", Numéro Chef: " << num_chef << endl;
}
