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

// Mettre � jour le stock
void gestionnaire::mettre_a_jour_stock(const string& article) {
    stock += ", " + article;
    detail_commande.push_back("Ajout au stock : " + article);
    cout << "Article '" << article << "' ajout� au stock." << endl;
}

// CRUD
void gestionnaire::create_g() {
    cout << "......Cr�ation gestionnaire......" << endl;
    cout << "Nom : ";
    cin >> nom;
    cout << "Pr�nom : ";
    cin >> prenom;
    cout << "Email : ";
    cin >> email;
    cout << "Mot de passe : ";
    cin >> motDePasse;
    cout << "ID : "; cin >> id;
    cout << "Niveau d'acc�s : ";
    cin >> niveau_acces;
    cout << "Stock initial : ";
    cin >> stock;
    detail_commande.clear();
    detail_commande.push_back("Cr�ation gestionnaire");
}

void gestionnaire::read_g() const {
    cout << "......D�tails du gestionnaire....." << endl;
    cout << "Nom : " << nom << endl;
    cout << "Pr�nom : " << prenom << endl;
    cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motDePasse << endl;
    cout << "ID : " << id << endl;
    cout << "Niveau d'acc�s : " << niveau_acces << endl;
    cout << "Stock actuel : " << stock << endl;
    cout << "Historique des commandes :" << endl;
    for (const string& detail : detail_commande) {
        cout << "- " << detail << endl;
    }
}

void gestionnaire::update_g() {
    cout << "......Mise � jour gestionnaire......" << endl;
    cout << "Nouveau nom : ";
    cin >> nom;
    cout << "Nouveau pr�nom : ";
    cin >> prenom;
    cout << "Nouvel email : ";
    cin >> email;
    cout << "Nouveau mot de passe : ";
    cin >> motDePasse;
    cout << "Nouveau niveau d'acc�s : ";
    cin >> niveau_acces;
    cout << "Nouveau stock : ";
    cin >> stock;
    detail_commande.push_back("Mise � jour du profil gestionnaire");
    cout << "Mise � jour termin�e." << endl;
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
    cout << "Gestionnaire supprim� de la m�moire." << endl;
}

// Surcharge op�rateur <<
ostream& operator<<(ostream& out, const gestionnaire& g) {
    out<<static_cast<const utilisateur&>(g)
       << "Niveau d'acc�s : " << g.niveau_acces
       << "Stock : " << g.stock;
    return out;
}

// Surcharge op�rateur >>
istream& operator>>(istream& in, gestionnaire& g) {
    in>> static_cast<utilisateur&>(g);
    cout << "Niveau d'acc�s : ";
    in>> g.niveau_acces;
    cout << "Stock : ";
    in>> g.stock;
    return in;
}
