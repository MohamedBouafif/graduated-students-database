#ifndef ETUDIANTS_H_INCLUDED
#define ETUDIANTS_H_INCLUDED
#pragma once


#include "etudiant.h"
#include "etudiant_master.h"
#include "etudinat_ing.h"


class etudiants
{
    friend class pfe;
    friend class entreprises;


    vector<etudiant*> tab;

public:

/**Const(s) & Dest**/


    etudiants();
    etudiants(const etudiants&);
    ~etudiants();

/**Get & set**/
    vector<etudiant*> gettab(){return tab;}

    int taille(){return tab.size();}


    void ajouter(etudiant_ing, int = 0);
    void ajouter(etudiant_master, int = 0);
    void ajouter(etudiant*,int = 0);
    void supprimer(int = 0); //indice


/*************(CES METHODES SONT REDEFINIES~surchagés)*********************/
    void remplir();
    void afficher();


/********************************************/



/**************Surcharge des operateurs**************************/
    friend ostream& operator << (ostream&, etudiants&);
    friend istream& operator >> (istream&, etudiants&);
    etudiants& operator = (const etudiants&);
    etudiants& operator + (const etudiants&);

    void afficher_tri_croissant();
    float pourcentage_reussite();
    float pourcentage_redouble();
    float pourcentage_chommage();


};


#endif // ETUDIANTS_H_INCLUDED
