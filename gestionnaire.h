#ifndef GESTIONNAIRE_H_INCLUDED
#define GESTIONNAIRE_H_INCLUDED
#include "utilisateur.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class gestionnaire : public utilisateur {
protected:
    int niveau_acces;
    string stock;
    vector<string> detail_commande;
public:
    // Constructeur
    gestionnaire(string nom, string prenom, string email, string motDePasse, int id, int niveau_acces, string stock);
    // Destructeur
    virtual ~gestionnaire(void);
    // Fonctions
    void mettre_a_jour_stock(const string& article);
    virtual void connexion(string emailEntree, string mdpEntree) override;
    // Fonctions CRUD
    virtual void create_g() override;
    virtual void read_g() const override;
    virtual void update_g() override;
    virtual void supprimer_g() override;
    // Surcharge des opérateurs << et >>
    friend ostream &operator<<(ostream&, const gestionnaire&);
    friend istream &operator>>(istream&, gestionnaire&);
    //surchage d'un operateur + et d'un operateur = et j'ai choisie ce class pour les implementer puisque c'est demande un seul class suffisant
    gestionnaire& operator=(const gestionnaire& other);
    gestionnaire operator+(const gestionnaire& other);
};
#endif
