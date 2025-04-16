#include "chef_bibliotheque.h"
#include <iostream>
#include "ChefBibliotheque.h"
#include <iostream>
using namespace std;

// Constructeur
ChefBibliotheque::ChefBibliotheque(string nom, string prenom, string email, string motDePasse,
                                   int id, int statut_connexion, int niveau_acces,
                                   string CIN, string num_chef)
    : administrateur(nom, prenom, email, motDePasse, id, statut_connexion),
      gestionnaire(nom, prenom, email, motDePasse, id, niveau_acces, ""),
      CIN(CIN), num_chef(num_chef) {}

// Destructeur
ChefBibliotheque::~ChefBibliotheque()
{}

// Connexion
void ChefBibliotheque::connexion(string emailEntree, string mdpEntree) {
    int compteur = 0;
    do {
        if (emailEntree == email && mdpEntree == motDePasse) {
            cout << "Connexion r�ussie. Bienvenue Chef de Biblioth�que, " << nom << " !" << endl;
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
void ChefBibliotheque::create_c() {
    cout << "......Cr�ation Chef Biblioth�que....." << endl;
    cout << "Nom : "; cin >> nom;
    cout << "Pr�nom : "; cin >> prenom;
    cout << "Email : "; cin >> email;
    cout << "Mot de passe : "; cin >> motDePasse;
    cout << "ID : "; cin >> id;
    cout << "Statut de connexion: "; cin >> statut_connexion;
    cout << "Niveau d'acc�s : "; cin >> niveau_acces;
    cout << "CIN : "; cin >> CIN;
    cout << "Num�ro chef : "; cin >> num_chef;
    notificationscritique.clear();
    notificationscritique.push_back("Cr�ation du chef de biblioth�que");
}

void ChefBibliotheque::read_c() const {
    cout << "......D�tails du Chef Biblioth�que...." << endl;
    cout << "Nom : " << nom << endl;
    cout << "Pr�nom : " << prenom << endl;
    cout << "Email : " << email << endl;
    cout << "Mot de passe : " << motDePasse << endl;
    cout << "ID : " << id << endl;
    cout << "Statut de connexion : " << statut_connexion << endl;
    cout << "Niveau d'acc�s : " << niveau_acces << endl;
    cout << "CIN : " << CIN << endl;
    cout << "Num�ro Chef : " << num_chef << endl;
    cout << "Notifications critiques : " << endl;
    for (const string& notif : notificationscritique) {
        cout << "- " << notif << endl;
    }
}

void ChefBibliotheque::update_c() {
    cout << ".....Mise � jour Chef Biblioth�que....." << endl;
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
    cout << "Nouveau niveau d'acc�s : ";
    cin >> niveau_acces;
    cout << "Nouveau CIN : ";
    cin >> CIN;
    cout << "Nouveau num�ro chef : ";
    cin >> num_chef;
    notificationscritique.push_back("Mise � jour du profil chef");
}

void ChefBibliotheque::supprimer_c() {
    nom = "";
    prenom = "";
    email = "";
    motDePasse = "";
    id = 0;
    statut_connexion = 0;
    niveau_acces = 0;
    CIN = "";
    num_chef = "";
    notificationscritique.clear();
}

// Fonction sp�cifique
void ChefBibliotheque::afficherInfosChef() {
    read_c();
}

// Surcharge op�rateur <<
ostream& operator<<(ostream& out, const ChefBibliotheque& cb) {
    out << "Nom : " << cb.nom
       << "Pr�nom : " << cb.prenom
       << "Email : " << cb.email
       << "Statut connexion : " << cb.statut_connexion
       << "Niveau d'acc�s : " << cb.niveau_acces
       << "CIN : " << cb.CIN
       << "Num�ro Chef : " << cb.num_chef;
    return out;
}

// Surcharge op�rateur >>
istream& operator>>(istream& in, ChefBibliotheque& cb) {
    cout << "Nom : ";
    in >> cb.nom;
    cout << "Pr�nom : ";
    in >> cb.prenom;
    cout << "Email : ";
    in >> cb.email;
    cout << "Statut de connexion : ";
    in >> cb.statut_connexion;
    cout << "Niveau d'acc�s : ";
    in >> cb.niveau_acces;
    cout << "CIN : ";
    in >> cb.CIN;
    cout << "Num�ro chef : ";
    in >> cb.num_chef;
    return in;
}
