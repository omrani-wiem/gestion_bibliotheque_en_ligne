#ifndef CHEFBIBLIOTHEQUE_H_INCLUDED
#define CHEFBIBLIOTHEQUE_H_INCLUDED
#include "administrateur.h"
#include "gestionnaire.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class ChefBibliotheque : public administrateur, public gestionnaire {
private:
    string CIN;
    string num_chef;
    vector<string> notificationscritique;
public:
    // Constructeur
    ChefBibliotheque(string nom, string prenom, string email, string motDePasse,
                     int id, int statut_connexion, int niveau_acces,
                     string CIN, string num_chef);
    // Destructeur
    virtual ~ChefBibliotheque();
    // Méthodes spécifiques
    void afficherInfosChef();
    // Fonctions CRUD
    virtual void create_c() override;
    virtual void read_c() const override;
    virtual void update_c() override;
    virtual void supprimer_c() override;
    // Surcharge des opérateurs << et >>
    friend ostream &operator<<(ostream&, const ChefBibliotheque&);
    friend istream &operator>>(istream&, ChefBibliotheque&);
};
#endif
