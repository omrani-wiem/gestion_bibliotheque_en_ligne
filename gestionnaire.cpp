#include "gestionnaire.h"
#include <iostream>
#include "gestionnaire.h"
#include <iostream>
using namespace std;

// Constructeur
gestionnaire::gestionnaire(string nom, string prenom, string email, string motDePasse, int id, int niveau_acces, string stock)
    : utilisateur(nom, prenom, email, motDePasse, id), niveau_acces(niveau_acces), stock(stock) {}

// Destructeur
gestionnaire::~gestionnaire() {}

// Connexion
void gestionnaire::connexion(string emailEntree, string mdpEntree) {
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

// Mettre à jour le stock
void gestionnaire::mettre_a_jour_stock(const string& article) {
    stock += ", " + article;
    detail_commande.push_back("Ajout au stock : " + article);
    cout << "Article '" << article << "' ajouté au stock." << endl;
}

// CRUD
void gestionnaire::create_g() {
    cout << "......Création gestionnaire......" << endl;
    cout << "Nom : ";
    cin >> nom;
    cout << "Prénom : ";
    cin >> prenom;
    cout << "Email : ";
    cin >> email;
    cout << "Mot de passe : ";
    cin >> motDePasse;
    cout << "ID : "; cin >> id;
    cout << "Niveau d'accès : ";
    cin >> niveau_acces;
    cout << "Stock initial : ";
    cin >> stock;
    detail_commande.clear();
    detail_commande.push_back("Création gestionnaire");
}

void gestionnaire::read_g() const {
    cout << "......Détails du gestionnaire....." << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prénom : " << prenom << endl;
    cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motDePasse << endl;
    cout << "ID : " << id << endl;
    cout << "Niveau d'accès : " << niveau_acces << endl;
    cout << "Stock actuel : " << stock << endl;
    cout << "Historique des commandes :" << endl;
    for (const string& detail : detail_commande) {
        cout << "- " << detail << endl;
    }
}

void gestionnaire::update_g() {
    cout << "......Mise à jour gestionnaire......" << endl;
    cout << "Nouveau nom : ";
    cin >> nom;
    cout << "Nouveau prénom : ";
    cin >> prenom;
    cout << "Nouvel email : ";
    cin >> email;
    cout << "Nouveau mot de passe : ";
    cin >> motDePasse;
    cout << "Nouveau niveau d'accès : ";
    cin >> niveau_acces;
    cout << "Nouveau stock : ";
    cin >> stock;
    detail_commande.push_back("Mise à jour du profil gestionnaire");
    cout << "Mise à jour terminée." << endl;
}

void gestionnaire::supprimer_g() {
    nom = "";
    prenom = "";
    email = "";
    motDePasse = "";
    id = 0;
    niveau_acces = 0;
    stock = "";
    detail_commande.clear();
    cout << "Gestionnaire supprimé de la mémoire." << endl;
}

// Surcharge opérateur <<
ostream& operator<<(ostream& out, const gestionnaire& g) {
    out<<static_cast<const utilisateur&>(g)
       << "Niveau d'accès : " << g.niveau_acces
       << "Stock : " << g.stock;
    return out;
}

// Surcharge opérateur >>
istream& operator>>(istream& in, gestionnaire& g) {
    in>> static_cast<utilisateur&>(g);
    cout << "Niveau d'accès : ";
    in>> g.niveau_acces;
    cout << "Stock : ";
    in>> g.stock;
    return in;
}
