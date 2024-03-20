#ifndef PROMOTION_ING_H_INCLUDED
#define PROMOTION_ING_H_INCLUDED

#include<vector>
#include "date.cpp"
#include "etudiant_ing.cpp"
class promotion_ing
{
   int num_promo ;
   date date_graduation_ing ;
   vector <etudiant_ing> etudiants_ing ;
   int nb_etudiants_ing ;
   public :
       promotion_ing ();
       promotion_ing (date,int ,int);
       ~promotion_ing(){};
       void saisir_promo_ing();
       void afficher_promo_ing();
       void afficher_promo_ing_triee();
       etudiant_ing majeur_promo_ing();



};

#endif // PROMOTION_ING_H_INCLUDED
