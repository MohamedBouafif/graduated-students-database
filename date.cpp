#include "date.h"
void date::afficher(string msg)
{
    cout<<msg;
    cout<<"Jour: "<<jour;
    cout<<endl;
    cout<<"Mois: "<<mois;
    cout<<endl;
    cout<<"Annee: "<<annee;
    cout<<endl;
}
void date::saisir(string msg)
{
    cout<<msg;

    do
    {
        cout<<"Jour: ";
        cin>>jour;

        if(!(jour>=1&&jour<=31)) cout<<"Vous avez entrer une date invalide, ressayez:\n";

    }while(!(jour>=1&&jour<=31));


    do
    {
        cout<<"Mois: ";cin>>mois;

        if(!(mois>=1&&mois<=12))cout<<"Vous avez entrer une date invalide, ressayez:\n";

    }while(!(mois>=1&&mois<=12));

    cout<<"Annee: ";cin>>annee;
    cout<<endl;
}


ostream& operator<< (ostream& out, date& d)
{
    out<<"Jour: "<<d.jour;
    out<<endl;
    out<<"Mois: "<<d.mois;
    out<<endl;
    out<<"Annee: "<<d.annee;
    return out;
}

istream& operator>> (istream& in, date& d)
{
    do
    {
        cout<<"Jour: ";
        in>>d.jour;

        if(!(d.jour>=1&&d.jour<=31)) cout<<"Vous avez entrer une date invalide, ressayez:\n";

    }while(!(d.jour>=1&&d.jour<=31));


    do
    {
        cout<<"Mois: ";in>>d.mois;

        if(!(d.mois>=1&&d.mois<=12))cout<<"Vous avez entrer une date invalide, ressayez:\n";

    }while(!(d.mois>=1&&d.mois<=12));

    cout<<"Annee: ";in>>d.annee;

    return in;
}
bool date::operator==(const date& d)
{
    if(jour!=d.jour||mois!=d.mois||annee!=d.annee) return false;
    return true;
}

date& date::operator= (const date& d)
{
    if(this!=&d)
    {
        jour = d.jour;
        mois = d.mois;
        annee = d.annee;
    }
    return *this;
}
bool date::operator < (const date& d)
{
    if(annee == d.annee)
        if(mois == d.mois)
            return jour <= d.jour;
        else
            return mois < d.mois;
    else
        return annee < d.annee;
}

