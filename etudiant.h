#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
using namespace std;
#include <iostream>
#include <string>
#pragma once
//#include "date.cpp"
class etudiant
{
    string nom,prenom,mail,CIN,matricule_E;
    float moyenne;
    date date_de_naissance;
    bool travaille;
    date date_debut,date_fin;
public:
    etudiant(string="",string="",string="",string="",string="",float=0,bool =0);
    ~etudiant(){}

    string getnom(){return nom;}
    string getprenom(){return prenom;}
    string getmail(){return mail;}
    string getCIN(){return CIN;}
    string getmatricule_E(){return matricule_E;}


    float getmoyenne(){return moyenne;}


    date getdate_de_naissance(){return date_de_naissance;}
    date getdate_debut(){return date_debut;}
    date getdate_fin(){return date_fin;}


    void setnom(string nom){this->nom=nom;}
    void setprenom(string prenom){this->prenom = prenom;}
    void setmail(string mail){this->mail=mail;}
    void setCIN(string CIN){this->CIN=CIN;}
    void setmatricule_E(string matricule_E){this->matricule_E=matricule_E;}
    void setdate_de_naissance(date d){this->date_de_naissance.setjour(d.getjour());this->date_de_naissance.setmois(d.getmois());this->date_de_naissance.setannee(d.getannee());}
    void settravaille(bool travaille){this->travaille=travaille;}
    void setmoyenne(float moyenne){this->moyenne=moyenne;}
    void setdate_debut(date d){this->date_debut.setjour(d.getjour());this->date_debut.setmois(d.getmois());this->date_debut.setannee(d.getannee());}
    void setdate_fin(date d){this->date_fin.setjour(d.getjour());this->date_fin.setmois(d.getmois());this->date_fin.setannee(d.getannee());}

    void afficher();
    void saisir();
};


#endif // ETUDIANT_H_INCLUDED
