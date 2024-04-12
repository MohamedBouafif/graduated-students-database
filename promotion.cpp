#include "promotion.h"
//constructeur
promotion :: promotion (int nb_etudiants_total ,int nb_etudiants_ing,int nb_etudiants_master, int jm,int mm,int am,int ji,int mi, int ai,int num_promo_ing,int num_promo_master):
    promotion_master(num_promo_master, nb_etudiants_master, jm, mm , am),promotion_ing(num_promo_ing, nb_etudiants_ing, ji,mi,ai)
{
    this->nb_etudiants_total=nb_etudiants_total;

}
//constructeur par recopie
 promotion::promotion (const promotion& p) :promotion_master(p) ,promotion_ing(p)
 {
    this->nb_etudiants_total=nb_etudiants_total;
 }

void promotion::saisir_promo()
{
    cout<<"*************saisie de la promotion master*****************"<<endl;
    saisir_promo_mast();
    cout<<"*************saisie de la promotion ingenieur**************"<<endl;
    saisir_promo_ing();
    nb_etudiants_total=nb_etudiants_ing+nb_etudiants_master;

}


void promotion::afficher_promo()
{

    cout <<"***********************AFFICHAGE DE LA PROMOTION************"<<endl ;
    cout <<" nombre total des etudiants: "<<nb_etudiants_total<<endl ;
    afficher_promo_ing();
    afficher_promo_mast();


}
float promotion:: pourcentage ()
  {
    int e;
    cout <<"Vous voulez obtenir le pourcenatge de \n1:etudiants master\t2:etudiants ingenieurs";
    cin>>e;
    while((e==1)||(e==2))
    {
        if (nb_etudiants_total==0)
            return 0;
        else
        {if (e==2)
            return (nb_etudiants_ing*100)/nb_etudiants_total;
        else
          return (nb_etudiants_master*100)/nb_etudiants_total;}

    }
  }

