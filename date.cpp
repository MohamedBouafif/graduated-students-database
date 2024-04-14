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


/**function tri**/
bool date:: compare(date d1, date d2)
{
    if(d1.annee == d2.annee)
        if(d1.mois==d2.mois)
            return d1.jour<=d2.jour;
        else
            return d1.mois<d2.mois;
    else
        return d1.annee<d2.annee;
}
bool operator < (date d1, date d2)
{
    if(d1.annee == d2.annee)
        if(d1.mois==d2.mois)
            return d1.jour<=d2.jour;
        else
            return d1.mois<d2.mois;
    else
        return d1.annee<d2.annee;

}
bool operator > (date d1, date d2)
{
    if(d1.annee == d2.annee)
        if(d1.mois==d2.mois)
            return d1.jour>=d2.jour;
        else
            return d1.mois>d2.mois;
    else
        return d1.annee>d2.annee;

}
