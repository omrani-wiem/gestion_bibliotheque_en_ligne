#include "administrateur.h"
#include <iostream>
using namespace std;
// Constructeur
administrateur::administrateur(string nom, string prenom, string email, string motDePasse, int id, int statut_connexion)
    : utilisateur(nom, prenom, email, motDePasse, id), statut_connexion(statut_connexion) {}

// Destructeur
administrateur::~administrateur() {}

// Ajouter un adh�rent
void administrateur::ajouter_adherent() {
    cout << "Entrez le nom de l'adh�rent � ajouter : ";
    string nom_adherent;
    cin >> nom_adherent;
    historiquesActions.push_back("Ajout adh�rent : "  nom_adherent);
    cout << "Adh�rent '" << nom_adherent << "' ajout�." << endl;
}

// Supprimer un adh�rent
void administrateur::supprimer_adherent() {
    cout << "Entrez le nom de l'adh�rent � supprimer : ";
    string nom_adherent;
    cin >> nom_adherent;
    historiquesActions.push_back("Suppression adh�rent : "  nom_adherent);
    cout << "Adh�rent '" << nom_adherent << "' supprim�." << endl;
}

// Connexion
void administrateur::connexion(string emailEntree, string mdpEntree) {
    int compteur = 0;
    do {
        if (emailEntree == email && mdpEntree == motDePasse) {
            cout << "Connexion r�ussie. Bienvenue, " << nom << " !" << endl;
            return;
        } else {
            cout << "�chec de la connexion. V�rifiez vos identifiants." << endl;
            compteur++;
            if (compteur < 3) {
                cout << "Essai " << compteur + 1 << "/3. Entrez � nouveau l'email et le mot de passe." << endl;
                cout << "Entrez l'email : ";
                cin >> emailEntree;
                cout << "Entrez le mot de passe : ";
                cin >> mdpEntree;
            }
        }
    } while (compteur < 3);

    cout << "Vous avez d�pass� le nombre d'essais autoris�s. Essayez une autre m�thode." << endl;
}
// CRUD
void administrateur::create_a() {
    cout << "..........Cr�ation d�un administrateur........" << endl;
    cout << "Nom : ";
    cin >> nom;
    cout << "Pr�nom : ";
    cin >> prenom;
    cout << "Email : ";
    cin >> email;
    cout << "Mot de passe : ";
    cin >> motDePasse;
    cout << "ID : ";
    cin >> id;
    cout << "Statut de connexion: ";
    cin >> statut_connexion;
    historiquesActions.clear();
    historiquesActions.push_back("Cr�ation du compte administrateur");
}

void administrateur::read_a() const {
    cout << ".....Lecture des Informations de l'administrateur......" << endl;
    cout << "Nom : " << nom << endl;
    cout << "Pr�nom : " << prenom << endl;
    cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motDePasse << endl;
    cout << "ID : " << id << endl;
    cout << "Statut de connexion : " << statut_connexion << endl;
    cout << "Historique des actions :" << endl;
    for (const string& action : historiquesActions) {
        cout << "- " << action << endl;
    }
}

void administrateur::update_a() {
    cout << "......Mise � jour administrateur...." << endl;
    cout << "Nouveau nom : ";
    cin >> nom;
    cout << "Nouveau pr�nom : ";
    cin >> prenom;
    cout << "Nouvel email : ";
    cin >> email;
    cout << "Nouveau mot de passe : ";
    cin >> motDePasse;
    cout << "Nouveau statut de connexion (0/1) : ";
    cin >> statut_connexion;
    historiquesActions.push_back("Mise � jour du profil administrateur");
}

void administrateur::supprimer_a() {
    nom = "";
    prenom = "";
    email = "";
    motDePasse = "";
    id = 0;
    statut_connexion = 0;
    historiquesActions.clear();
}

// Surcharge op�rateur <<
ostream& operator<<(ostream& out, const administrateur& a) {
    out << static_cast<const utilisateur&>(a)
       << " | Statut connexion : " << a.statut_connexion;
    return out;
}

// Surcharge op�rateur >>
istream& operator>>(istream& in, administrateur& a) {
    in >> static_cast<utilisateur&>(a);
    cout << "Statut de connexion : ";
    in >> a.statut_connexion;
    return in;
}
