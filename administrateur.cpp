#include "administrateur.h"
#include <iostream>
using namespace std;
// Constructeur
administrateur::administrateur(string nom, string prenom, string email, string motDePasse, int id, int statut_connexion)
    : utilisateur(nom, prenom, email, motDePasse, id), statut_connexion(statut_connexion) {}

// Destructeur
administrateur::~administrateur() {}

// Ajouter un adhérent
void administrateur::ajouter_adherent() {
    cout << "Entrez le nom de l'adhérent à ajouter : ";
    string nom_adherent;
    cin >> nom_adherent;
    historiquesActions.push_back("Ajout adhérent : "  nom_adherent);
    cout << "Adhérent '" << nom_adherent << "' ajouté." << endl;
}

// Supprimer un adhérent
void administrateur::supprimer_adherent() {
    cout << "Entrez le nom de l'adhérent à supprimer : ";
    string nom_adherent;
    cin >> nom_adherent;
    historiquesActions.push_back("Suppression adhérent : "  nom_adherent);
    cout << "Adhérent '" << nom_adherent << "' supprimé." << endl;
}

// Connexion
void administrateur::connexion(string emailEntree, string mdpEntree) {
    int compteur = 0;
    do {
        if (emailEntree == email && mdpEntree == motDePasse) {
            cout << "Connexion réussie. Bienvenue, " << nom << " !" << endl;
            return;
        } else {
            cout << "Échec de la connexion. Vérifiez vos identifiants." << endl;
            compteur++;
            if (compteur < 3) {
                cout << "Essai " << compteur + 1 << "/3. Entrez à nouveau l'email et le mot de passe." << endl;
                cout << "Entrez l'email : ";
                cin >> emailEntree;
                cout << "Entrez le mot de passe : ";
                cin >> mdpEntree;
            }
        }
    } while (compteur < 3);

    cout << "Vous avez dépassé le nombre d'essais autorisés. Essayez une autre méthode." << endl;
}
// CRUD
void administrateur::create_a() {
    cout << "..........Création d’un administrateur........" << endl;
    cout << "Nom : ";
    cin >> nom;
    cout << "Prénom : ";
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
    historiquesActions.push_back("Création du compte administrateur");
}

void administrateur::read_a() const {
    cout << ".....Lecture des Informations de l'administrateur......" << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
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
    cout << "......Mise à jour administrateur...." << endl;
    cout << "Nouveau nom : ";
    cin >> nom;
    cout << "Nouveau prénom : ";
    cin >> prenom;
    cout << "Nouvel email : ";
    cin >> email;
    cout << "Nouveau mot de passe : ";
    cin >> motDePasse;
    cout << "Nouveau statut de connexion (0/1) : ";
    cin >> statut_connexion;
    historiquesActions.push_back("Mise à jour du profil administrateur");
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

// Surcharge opérateur <<
ostream& operator<<(ostream& out, const administrateur& a) {
    out << static_cast<const utilisateur&>(a)
       << " | Statut connexion : " << a.statut_connexion;
    return out;
}

// Surcharge opérateur >>
istream& operator>>(istream& in, administrateur& a) {
    in >> static_cast<utilisateur&>(a);
    cout << "Statut de connexion : ";
    in >> a.statut_connexion;
    return in;
}
