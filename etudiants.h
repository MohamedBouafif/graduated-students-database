#ifndef ETUDIANTS_H_INCLUDED
#define ETUDIANTS_H_INCLUDED
#pragma once
#include "etudiant.h"
class etudiants
{
    vector<etudiant*> tab;
public:
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


};


#endif // ETUDIANTS_H_INCLUDED
