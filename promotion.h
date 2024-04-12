#ifndef PROMOTION_H_INCLUDED
#define PROMOTION_H_INCLUDED
#include"etudiants.h"
#include"promotion_master.h"
#include"promotion_ing.h"

using namespace std ;

 class promotion :public promotion_master , promotion_ing
 {
     int nb_etudiants_total ;


   public :
    //constructeurs & destructeurs
   promotion (int =0,int=0,int=0, int=0,int=0,int=0,int=0,int=0, int=0,int=0,int=0);
   promotion (const promotion& );
   ~promotion (){}

   int get_nb_etudiants_total(){return nb_etudiants_total;}
   void saisir_promo();
   void afficher_promo();
   float pourcentage () ;





 };

#endif
