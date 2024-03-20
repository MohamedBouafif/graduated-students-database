#include <iostream>
using namespace std;
#include "etudiant.cpp"
//#include "etudiant_ing.cpp"
#include "etudiants.cpp"
#include "etudiant_master.cpp"
#include "pfe.cpp"
//#include "promotion_master.cpp"
#include "promotion_ing.cpp"
int main()
{
    /** test de la classe date: **/

    /*date d(10,12,2001);
    d.afficher();
    d.setannee(2002);
    d.afficher();
    date d1;
    d1.saisir();
    d1.afficher();*/



    /**test de la classe etudiant**/

    /*etudiant e("Mohamed","Bouafif","MohamedBouafif2020@gmail.com","14478956","EZF#54B",10.7,12,05,2001,15,03,2022,15,03,2024);
    e.afficher();
    etudiant e2;
    e2.saisir();
    e2.afficher();
    date d = e.getdate_de_naissance();
    d.afficher();*/

    /** test de classe etudiant ing**/
    /*etudiant_ing e;
    e.saisir();
    e.afficher();
    etudiant_ing e1(e);
    e1.afficher();*/
    //ALL good

    /** test de classe etudiant master**/
    /*etudiant_master e;
    e.saisir();
    e.afficher();
    etudiant_master e1(e);
    e1.afficher();*/
    //ALL GOOD;

    /**TEST DE classe etudiantS **/
    /*etudiants e;
    e.remplir();
    e.afficher();
    //ALL GOOD;*/

    
    /**Test de classe pfe**/
   /* pfe p;
    p.saisir();
    p.afficher();
    pfe p1(p);//test de constructeur par recopie
    p1.afficher();

    etudiants e = p1.getetudiants(); //test de getteur des etudiants qui ont travaille dans une pfe donné
    e.afficher();
    //ALL GOOD ! */
       /**Test de classe promotion_mast **/
      /* promotion_master p ;
       p.saisir_promo_mast() ;
       p.afficher_promo_mast_triee() ;
       etudiant_master e ;
       e = p.majeur_promo_mast();
       e.afficher();*/


       /**Test de classe promotion_ing+ **/
       promotion_ing p ;
       p.saisir_promo_ing() ;
       p.afficher_promo_ing_triee() ;
       etudiant_ing e ;
     cout<<"***************affichage majeur promo ****************"<<endl ; 
       e = p.majeur_promo_ing ();
       e.afficher();

}
