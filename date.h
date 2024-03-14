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
    void afficher();
    void saisir();


};



#endif // DATE_H_INCLUDED
