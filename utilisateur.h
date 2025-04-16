#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
using namespace std;
class utilisateur {
protected:
    int id;
    string nom, prenom, email, motDePasse;
public:
    // Constructeur
    utilisateur(string nom = "", string prenom = "", string email = "", string motDePasse = "", int id = 0);
    // Destructeur
    virtual ~utilisateur(void);
    // Fonctions CRUD
    virtual void create_u();
    virtual void read_u() const;
    virtual void update_u();
    virtual void supprimer_u();
    // Fonction pour la connexion
    virtual void connexion(string emailEntree, string mdpEntree) = 0;
    // Surcharge des opérateurs << et >>
    friend ostream &operator<<(ostream&, const utilisateur&);
    friend istream &operator>>(istream&, utilisateur&);
};

#endif
