#include "promotion.h"
promotion :: promotion (date date_graduation , int num_promo , int nb_etudiants)
{
    this -> date_graduation = date_graduation ;
    this->num_promo = num_promo;
    this->nb_etudiants=nb_etudiants ;
}
void promotion ::ajouter_etudiant(etudiant e)
{
    etud_de_promo.push_back(e);
}
void promotion::saisir_promo()
{
    cout << "entrer le numero de promotion: "<<endl ;
    cin >>num_promo;
    cout << "entrer la  date de graduation de cette promo: "<< endl ;
    date_graduation.saisir();
    cout <<"entrer le nombres d'etudiants: "<<endl ;
    cin >> nb_etudiants ;

    for (int i=0 ; i< nb_etudiants; i++)
    {
        etudiant e ;
        e.saisir();
        ajouter_etudiant(e);
    }
}
void promotion::afficher_promo()
{
    cout <<"*************Affichage de promotion***********"<<endl ;
    cout <<"le numero de promotion est: " << num_promo<<endl ;
    cout <<"la date de graduation est: ";
    date_graduation.afficher();
    cout << "le nombres d'etudiants dans cette promotion est: "<< nb_etudiants<<endl ;
    for (int i=0 ; i<nb_etudiants;i++)
    {
        etud_de_promo[i].afficher();
    }

}
etudiant  promotion::majeur_promo()
{    etudiant e ;
    float maxi ;
    e= etud_de_promo[0];
    maxi = etud_de_promo[0].getmoyenne();
    for (int i=1; i<nb_etudiants ; i++)
    {
        if( maxi < etud_de_promo[i].getmoyenne())
            {maxi = etud_de_promo[i].getmoyenne();
            e=etud_de_promo[i];}
    }
 return e ;

}
etudiant promotion:: pire_moyenne()
{
    etudiant e ;
    float mini ;
    e= etud_de_promo[0];
    mini= etud_de_promo[0].getmoyenne();
    for (int i=1; i<nb_etudiants ; i++)
    {
        if( mini > etud_de_promo[i].getmoyenne())
            {mini = etud_de_promo[i].getmoyenne();
            e=etud_de_promo[i];}
    }
 return e ;
}
