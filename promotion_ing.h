#ifndef PROMOTION_ING_H_INCLUDED
#define PROMOTION_ING_H_INCLUDED
//#include"date.cpp"
 #include "etudiant_ing.h"
#include<vector>
#include<algorithm>

class promotion_ing
{
    protected:
   int num_promo_ing ;
   date date_graduation_ing ;
   vector <etudiant_ing> etudiants_ing ;
   int nb_etudiants_ing ;
   public :
       promotion_ing (int=0,int=0, int=0,int=0,int=0);
       pomotion_ing(const promotion_ing& );
       ~promotion_ing();

       //getteurs & setteurs
       int get_num_promo_ing (){return num_promo_ing;}
       int get_nb_etudiants(){return nb_etudiants_ing;}
       date get_date_graduation_ing(){return date_graduation_ing;}
       etudiant_ing get_etudiant(int i){return etudiants_ing[i];}

       void set_num_promo (int num_promo_ing){this->num_promo_ing=num_promo_ing;}
       void set_nb_etudiants_ing(int nb_etudiants_ing) {this->nb_etudiants_ing=nb_etudiants_ing;}
       void set_date_graduation_ing (date date_graduation_ing ){this->date_graduation_ing=date_graduation_ing;}


       void ajouter_etudiant_ing(etudiant_ing );
       void saisir_promo_ing();
       void afficher_promo_ing();
       void afficher_promo_ing_triee();
       etudiant_ing majeur_promo_ing();


       friend ostream& operator<<(ostream&,promotion_ing&);
       friend istream& operator>>(istream&,promotion_ing&);


};

#endif // PROMOTION_ING_H_INCLUDED
