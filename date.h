#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#pragma once
using namespace std;
#include <iostream>
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

    /**surcharge des operateurs**/
    friend bool operator < (date,date);
    friend bool operator > (date,date);

    /**Methode tri des dates**/
    bool compare(date,date);

};



#endif // DATE_H_INCLUDED
