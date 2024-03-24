#ifndef ETUDIANTS_H_INCLUDED
#define ETUDIANTS_H_INCLUDED
#pragma once
#include "etudiant.h"
class etudiants
{
    friend class pfe;
    friend class entreprises;

    vector<etudiant*> tab;

public:

    vector<etudiant*> getab(){return tab;}

    etudiants();
    etudiants(const etudiants&);
    ~etudiants();

    void remplir();
    void afficher();

    int taille();

    void ajouter(etudiant_ing, int = 0);
    void ajouter(etudiant_master, int = 0);
    void ajouter(etudiant*,int = 0);
    void supprimer(int = 0);



    friend ostream& operator<< (ostream&, etudiants&);
    friend istream& operator>> (istream&, etudiants&);


};


#endif // ETUDIANTS_H_INCLUDED
