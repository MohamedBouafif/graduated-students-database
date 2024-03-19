#include <iostream>
using namespace std;
#include "date.cpp"
#include "etudiant.cpp"
#include "etudinat_ing.cpp"
#include "etudiant_master.cpp"
#include "etudiants.cpp"
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
    
    
    /**test de classe etudaints qui englobe TOUT!!**/
    /**Vous pouvez tester seullement ca**/
    etudiants e;
    e.remplir();
    e.afficher();
//ALL GOOD!

}
