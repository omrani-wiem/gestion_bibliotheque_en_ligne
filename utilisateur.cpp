#include "utilisateur.h"
#include <iostream>
using namespace std;
// Constructeur
utilisateur::utilisateur(string nom, string prenom, string email, string motDePasse, int id)
    : nom(nom), prenom(prenom), email(email), motDePasse(motDePasse), id(id) {}

// Destructeur
utilisateur::~utilisateur()
{}

// CRUD
void utilisateur::create_u() {
    cout << "........Cr�ation d'un utilisateur............" << endl;
    cout << "Nom : ";
    cin >> nom;
    cout << "Pr�nom : ";
    cin >> prenom;
    cout << "Email : ";
    cin >> email;
    cout << "Mot de passe : ";
    cin >> motDePasse;
    cout << "ID : ";
    cin >>id;
}

void utilisateur::read_u() const {
    cout << ".......Lecture des Informations de utilisateur........" << endl;
    cout << "Nom : " << nom << endl;
    cout << "Pr�nom : " << prenom << endl;
    cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motDePasse << endl;
    cout << "ID : " << id << endl;
}

void utilisateur::update_u() {
    cout << "....Mise � jour des informations de utilisateur......." << endl;
    cout << "Nouveau nom : "; cin >> nom;
    cout << "Nouveau pr�nom : "; cin >> prenom;
    cout << "Nouvel email : "; cin >> email;
    cout << "Nouveau mot de passe : "; cin >> motDePasse;
}

void utilisateur::supprimer_u() {
    nom = "";
    prenom = "";
    email = "";
    motDePasse = "";
    id = 0;
}
// Op�rateurs
ostream& operator<<(ostream& out, const utilisateur& u) {
    out << u.nom << " " << u.prenom << " (" << u.email << ")";
    return out;
}

istream& operator>>(istream& in, utilisateur& u) {
    cout << "Nom : ";
    in>>u.nom;
    cout << "Pr�nom : ";
    in>>u.prenom;
    cout << "Email : ";
    in>>u.email;
    cout << "Mot de passe : ";
    in>>u.motDePasse;
    return in;
}

