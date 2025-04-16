#ifndef FOURNISSEUR_H_INCLUDED
#define FOURNISSEUR_H_INCLUDED
#include <string>
using namespace std;

class fournisseur {
private:
    int id_four;
    string nom_four;

public:
    fournisseur(int id_four, string nom_four);
    ~fournisseur();
    void ajouter_fournisseur();
};

#endif
