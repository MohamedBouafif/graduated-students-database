#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#pragma once


#include <iostream>

using namespace std;

class date
{
    int jour,mois,annee;
public:

    date(int jour=0,int mois=0,int annee=0){this->jour=jour;this->mois=mois;this->annee=annee;}
    ~date(){}


    int getjour(){return jour;}
    int getmois(){return mois;}
    int getannee(){return annee;}
    void setjour(int jour){this->jour=jour;}
    void setmois(int mois){this->mois=mois;}
    void setannee(int annee){this->annee=annee;}
    void afficher(string ="");
    void saisir(string="");

/**Surcharge des operateurs**/
    friend ostream& operator<<(ostream&,date&);
    friend istream& operator>>(istream&,date&);
    date& operator = (const date&);
    bool operator == (const date&);
    bool operator < (const date&); //Pour pouvoir utiliser la fonction sort




};



#endif // DATE_H_INCLUDED
