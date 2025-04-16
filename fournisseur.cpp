#include "fournisseur.h"

// Constructeur
fournisseur::fournisseur(int id_four, string nom_four) : id_four(id_four), nom_four(nom_four) {}

// Destructeur
fournisseur::~fournisseur()
{}

//fonction
void fournisseur::envoyer_demande_approvisionnement() {
    cout << "Le fournisseur " << nom_four << " a envoyé une demande d’approvisionnement." << endl;
}

//fonctions CRUD
void fournisseur::create_f() {
    cout << "......Création d'un Fournisseur....." << endl;
    cout << "Entrez l'ID du fournisseur : ";
    cin >> id_four;
    cout << "Entrez le nom du fournisseur : ";
    cin >> nom_four;
}

void fournisseur::read_f() const {
    cout << "....lecture des Détails du Fournisseur....." << endl;
    cout << "ID Fournisseur : " << id_four << endl;
    cout << "Nom du Fournisseur : " << nom_four << endl;
}
void fournisseur::update_f() {
    cout << ".......Mise à jour du Fournisseur........" << endl;
    cout << "Entrez le nouvel ID du fournisseur : ";
    cin >> id_four;
    cout << "Entrez le nouveau nom du fournisseur : ";
    cin >> nom_four;
    cout << "Fournisseur mis à jour avec succès !" << endl;
}

void fournisseur::supprimer_f() {
    id_four = 0;
    nom_four = "";
}

// Surcharge << et >>
ostream& operator<<(ostream& out, const fournisseur& f) {
    out<< "ID Fournisseur : " << f.id_four << " Nom : " << f.nom_four;
    return out;
}

istream& operator>>(istream& in, fournisseur& f) {
    cout << "Entrez l'ID du fournisseur : ";
    in>> f.id_four;
    cout << "Entrez le nom du fournisseur : ";
    in>> f.nom_four;
    return in;
}

