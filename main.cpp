#include <iostream>
using namespace std;
//#include "date.cpp"
//#include "etudiant.cpp"
//#include"promotion.cpp"
#include"pfe.cpp"
int main()
{
    /** test de la classe date: **/
    /*
    date d(10,12,2001);
    d.afficher();
    d.setannee(2002);
    d.afficher();
    date d1;
    d1.saisir();
    d1.afficher();*/



    /**test de la classe etudiant**/
    /*etudiant e("Mohamed","Bouafif","MohamedBouafif2020@gmail.com","14478956","EZF#54B",10.7);
    e.afficher();
    etudiant e2;
    e2.saisir();
    e2.afficher();
    date d = e.getdate_de_naissance();
    d.afficher();*/
    
     /**test de la classe promotion **/
   /* promotion promo ;
    promo.saisir_promo();
    promo.afficher_promo();
    etudiant  a;
    a=promo.majeur_promo();
    a.afficher();*/
     /**test de la classe pfe **/
    pfe pf ;
    pf.saisir_pfe();
    pf.afficher_pfe();


}
