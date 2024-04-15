#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#pragma once


#include <iostream>
#include <vector>
#include <string>
#include "date.h"


using namespace std;


class etudiant
{
    friend class entreprise;

protected:

    string nom,prenom,mail,CIN,matricule_E;

    bool travaille;

    vector<string> societes;   //Partie dynamique contient les nom des societés que lutidiant a travailler dedans

    date date_de_naissance;
    date date_debut;   //debut detude 
    date date_fin;      // fin etude 

public:

    /** Const(s) & Dest**/
    etudiant(string="",string="",string="",string="",string="",bool =0,int=0 ,int =0,int =0,int=0,int=0 ,int=0 ,int=0,int =0,int=0 );
    virtual ~etudiant();
    etudiant(const etudiant&);


/**getteurs**/
    string getnom(){return nom;}
    string getprenom(){return prenom;}
    string getmail(){return mail;}
    string getCIN(){return CIN;}
    string getmatricule_E(){return matricule_E;}
    vector<string> getsocietes(){return societes;}


    date getdate_de_naissance(){return date_de_naissance;}
    date getdate_debut(){return date_debut;}
    date getdate_fin(){return date_fin;}


/**setteurs**/
    void setnom(string nom){this->nom=nom;}
    void setprenom(string prenom){this->prenom = prenom;}
    void setmail(string mail){this->mail=mail;}
    void setCIN(string CIN){this->CIN=CIN;}
    void setmatricule_E(string matricule_E){this->matricule_E=matricule_E;}
    void setdate_de_naissance(date d){this->date_de_naissance.setjour(d.getjour());this->date_de_naissance.setmois(d.getmois());this->date_de_naissance.setannee(d.getannee());}
    void settravaille(bool travaille){this->travaille=travaille;}

    void setdate_debut(date d){this->date_debut.setjour(d.getjour());this->date_debut.setmois(d.getmois());this->date_debut.setannee(d.getannee());}
    void setdate_fin(date d){this->date_fin.setjour(d.getjour());this->date_fin.setmois(d.getmois());this->date_fin.setannee(d.getannee());}


/*****************************************************/


    bool chercher_Societe(string);

    int taille();

    int dure_etude();//calculer la dure detude dans luniversite

    void redouble();//afficher si letudiant a redoublé au moins une annee ou non dans luniversité


/*************(CES METHODES SONT REDEFINIES~surchagés)*********************/

    virtual void afficher()=0; //La classe etudiant est VIRTUELLE
    virtual void saisir()=0;

    
/**************Surcharge des operateurs**************************/

    friend ostream& operator << (ostream&,etudiant&);
    friend istream& operator >> (istream&,etudiant&);
    
    etudiant& operator = (const etudiant&);
    bool operator == (const etudiant&);


};


#endif // ETUDIANT_H_INCLUDED
