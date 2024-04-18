#ifndef ETUDINAT_ING_H_INCLUDED
#define ETUDINAT_ING_H_INCLUDED
#include"etudiant.h"


class etudiant_ing : public etudiant
{
    friend class entreprise;


    vector<string> classes;
    string section;
    list<float> moyennes;
    float moyenne_general;


public:

    /**Con(s)& Des**/
    etudiant_ing(string="",string="",string="",string="",string="",string="",bool =0,int=0 ,int =0,int =0,int=0,int=0 ,int=0 ,int=0,int =0,int=0);
    ~etudiant_ing();
    etudiant_ing(const etudiant_ing&);

    /**get&set**/
    void setSection(string section){this->section = section;}
    string getsection(void){return section;}
    float getmoyenne_general(){return moyenne_general;}

    void chercher_classe(string);
    void afficher_moyennes();
    void afficher_classes();


/*************(CES METHODES SONT REDEFINIES~surchagés)*********************/
    void afficher();
    void saisir();

/*************************************/
    float calcul_moyenne_general();

/**************Surcharge des operateurs**************************/

    friend ostream& operator<<(ostream&, etudiant_ing&);
    friend istream& operator>>(istream&, etudiant_ing&);
    etudiant_ing& operator = (const etudiant_ing&);

    bool operator < (const etudiant_ing&);   //Tri selon la moyenne general (ordre croissant);
    /**************gestion de fichier***************/
    void enregistrer();
};


#endif // ETUDINAT_ING_H_INCLUDED
