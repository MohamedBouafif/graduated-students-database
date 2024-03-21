#ifndef PROMOTION_MASTER_H_INCLUDED
#define PROMOTION_MASTER_H_INCLUDED
#include<vector>
#include "date.cpp"
#include "etudiant_master.cpp"
class promotion_master
{
   int num_promo ;
   date date_graduation_master ;
   vector <etudiant_master> etudiants_master ;
   int nb_etudiants_master ;
   public :
       promotion_master (int=0,int=0,int=0,int=0,int=0);
       promotion_master (const promotion_master& );
       ~promotion_master ();
       void saisir_promo_mast();
       void afficher_promo_mast();
       void afficher_promo_mast_triee();
       etudiant_master majeur_promo_mast();



};



#endif // PROMOTION_MASTER_H_INCLUDED
