#ifndef PROMOTION_MASTER_H_INCLUDED
#define PROMOTION_MASTER_H_INCLUDED
#include<vector>
#include "date.cpp"
#include "etudiant_master.h"
class promotion_master
{
   protected :
       int num_promo_master ;
       date date_graduation_master ;
       vector <etudiant_master> etudiants_master ;
       int nb_etudiants_master ;
   public :
       promotion_master (int=0,int=0,int=0,int=0,int=0);
       promotion_master (const promotion_master& );
       ~promotion_master ();
       //setteurs et getteurs
       int get_num_promo_master (){return num_promo_master;}
       int get_nb_etudiants(){return nb_etudiants_master;}
       date get_date_graduation_master(){return date_graduation_master;}
       etudiant_master get_etudiant(int i){return etudiants_master[i];}

       void set_num_promo (int num_promo_master){this->num_promo_master=num_promo_master;}
       void set_nb_etudiants(int nb_etudiants_master) {this->nb_etudiants_master=nb_etudiants_master;}
       void set_date_graduation_master (date date_graduation_master ){this->date_graduation_master=date_graduation_master;}


       void ajouter_etudiant_master(etudiant_master );
       void saisir_promo_mast();
       void afficher_promo_mast();
       void afficher_promo_mast_triee();
       etudiant_master majeur_promo_mast();



       friend ostream& operator<<(ostream&,promotion_master&);
       friend istream& operator>>(istream&,promotion_master&);




};


#endif // PROMOTION_MASTER_H_INCLUDED
