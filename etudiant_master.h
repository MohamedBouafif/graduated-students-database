#ifndef ETUDIANT_MASTER_H_INCLUDED
#define ETUDIANT_MASTER_H_INCLUDED
#include<fstream>
#include"etudiant.h"


class etudiant_master : public etudiant
{
    friend class entreprise;
    string filiere_licence;
    float note_pfe_licence;
    string filiere_master;
    list<float> moyennes;   //durant ces annees detudes
    float moyenne_general;


public:
    /**Const(s) & Dest**/
    etudiant_master(string="",float=0,string="",string="",string="",string="",string="",string="",bool =0,int=0 ,int =0,int =0,int=0,int=0 ,int=0 ,int=0,int =0,int=0);
    ~etudiant_master();
    etudiant_master(const etudiant_master&);


    /**get & set**/
    string getfiliere_licence(){return filiere_licence;}
    float getnote_pfe_licence(){return note_pfe_licence;}
    string getfiliere_master(){return filiere_master;}
    float getmoyenne_general(){return moyenne_general;}

    void setfiliere_licence(string filiere_licence){this->filiere_licence = filiere_licence;}
    void setnote_pfe_licence(float note_pfe_licence){this->note_pfe_licence = note_pfe_licence;}
    void setfiliere_master(string filiere_master){this->filiere_master = filiere_master;}


/*************(CES METHODES SONT REDEFINIES~surchagés)*********************/

    void saisir();
    void afficher();

/********************************************************************/
    float calcul_moyenne_general();

/**************Surcharge des operateurs**************************/

    friend ostream& operator<<(ostream&, etudiant_master&);
    friend istream& operator>> (istream&, etudiant_master&);
    etudiant_master& operator = (const etudiant_master&);

    bool operator < (const etudiant_master&); // tri dans lordre croissant selon le caractere : moyenne general
/*******************gestion de fichier************************/
void enregistrer ( );


};


#endif // ETUDIANT_MASTER_H_INCLUDED
