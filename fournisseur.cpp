#include "fournisseur.h"
#include <iostream>
fournisseur::fournisseur(int id_four, string nom_four) : id_four(id_four), nom_four(nom_four) {}

fournisseur::~fournisseur() {}

void fournisseur::ajouter_fournisseur() {
    cout << "Fournisseur ajouté: " << nom_four << " (ID: " << id_four << ")" << endl;
}
