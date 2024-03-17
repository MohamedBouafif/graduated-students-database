#ifndef PROMOTION_H_INCLUDED
#define PROMOTION_H_INCLUDED
#pragma once
#include "etudiant.cpp"
#include <vector>
using namespace std ;

 class promotion
 {
   date date_graduation ;
   int num_promo ;
   int nb_etudiants ;
   vector <etudiant> etud_de_promo;
   public :
   promotion (date ,int , int );
   promotion (int = 0, int = 0){};
   ~promotion() {};
   int get_num_promo (){return num_promo ; };
   int get_nb_etudiants (){return nb_etudiants;};
   date get_date_graduation(){return date_graduation ;};


   void set_date (date date_graduation) {this->date_graduation = date_graduation ;};
   void set_num_promo (int num_promo){this-> num_promo= num_promo;};
   void set_nb_etudiants (int nb_etudiants){this -> nb_etudiants= nb_etudiants;};

   void afficher_promo() ;
   void ajouter_etudiant(etudiant);
   void saisir_promo() ;
   etudiant majeur_promo();
   etudiant pire_moyenne();



 };











#endif
