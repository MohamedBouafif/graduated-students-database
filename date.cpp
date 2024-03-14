#include "date.h"
void date::afficher()
{
    cout<<"La date est: \n";
    cout<<"Jour: "<<jour;
    cout<<endl;
    cout<<"Mois: "<<mois;
    cout<<endl;
    cout<<"Annee: "<<annee;
    cout<<endl;
}
void date::saisir()
{
    //cout<<"saisir la Date: "<<endl;

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
