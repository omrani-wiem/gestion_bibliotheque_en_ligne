#ifndef ADMINISTRATEUR_H_INCLUDED
#define ADMINISTRATEUR_H_INCLUDED
#include "utilisateur.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class administrateur : public utilisateur {
protected:
    int statut_connexion;
    vector<string> historiquesActions;
public:
    // Constructeur
    administrateur(string nom, string prenom, string email, string motDePasse, int id, int statut_connexion);
    // Destructeur
    virtual ~administrateur(void);
    // Fonctions
    void ajouter_adherent();
    void supprimer_adherent();
    virtual void connexion(string emailEntree, string mdpEntree) override;
    // Fonctions CRUD
    virtual void create_a() override;
    virtual void read_a() const override;
    virtual void update_a() override;
    virtual void supprimer_a() override;
    // Surcharge des opérateurs << et >>
    friend ostream &operator<<(ostream&, const administrateur&);
    friend istream &operator>>(istream&, administrateur&);
};
#endif
