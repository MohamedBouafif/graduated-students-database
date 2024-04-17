#include <iostream>
using namespace std;
#include "date.cpp"
#include "etudiant.cpp"
#include "etudinat_ing.cpp"
#include "etudiant_master.cpp"
#include "etudiants.cpp"
#include "pfe.cpp"

#include "pfes.cpp"
//#include "entreprise.cpp"
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
        /**test de surcharge de la classe date**/
            /*date d1;
            cin>>d1;
            cout<<d1;
            date d2 =d1;
            cout<<d2;
            if(d2==d1)cout<<"ok";
            date d3;
            cin>>d3;
            vector<date> v(3);
            v[0]=d1;
            v[1]=d2;
            v[2] = d3;
            for(int i = 0; i < v.size(); i++) cout<<v[i];
            sort(v.begin(),v.end());
            cout<<endl;
            for(int i = 0; i < v.size(); i++) cout<<v[i];*/
            //ALL GOOD



    /**test de la classe etudiant**/

    /*etudiant e;
    e.afficher();
    etudiant e2;
    e2.saisir();
    e2.afficher();
    date d = e.getdate_de_naissance();
    d.afficher();*/
            /**test de surcharge de la classe etudiant**/
            /*etudiant e1;
            etudiant e2;
            cin>>e1;
            cout<<endl;
            cin>>e2;
            cout<<endl;
            if(e1==e2)cout<<"y\n";else cout<<"no\n";
            etudiant e3 = e2;
            cout<<e3<<endl;
            e3 = e1;
            cout<<e3;    // la partie dynamique est bien modifié
            //ALL GOOD*/





    /** test de classe etudiant ing**/
    /*etudiant_ing e;
    e.saisir();
    e.afficher();
    etudiant_ing e1(e);
    e1.afficher();*/
            /**Test de surcharge de classe etudiant ing**/
                /*etudiant_ing e;
                cin>>e;
                cout<<e;
                etudiant_ing e2;
                cin>>e2;
                //e2=e; //la partie dynamique est bien modifié
                cout<<e2;
                vector<etudiant_ing> v(2);
                v[0] = e;
                v[1] = e2;
                sort(v.begin(),v.end());
                cout<<v[0]<<endl<<v[1];*/
    //ALL good




    /** test de classe etudiant master**/
    /*etudiant_master e;
    e.saisir();
    e.afficher();
    etudiant_master e1(e);
    e1.afficher();*/
        /**Test de surcharge de classe etudiant master**/
            /*etudiant_master e;
            cin>>e;
            etudiant_master e1;
            cin>>e1;
            cout<<"e : \n";
            cout<<e<<endl<<"e1 : \n"<<e1<<endl;
            e1 = e;
            cout<<e1;*/
    //ALL GOOD;



    /**TEST DE classe etudiantS **/
    /*e.remplir();
    e.afficher();*/
        /**Test de surcharge de classe etudiants**/
            /*etudiants e;
            cin>>e;
            cout<<e<<endl;
            etudiants e1;
            cin>>e1;
            //e1= e;
            //cout<<e1;
            e = e+e1;
            cout<<e;

            etudiants e;
            cin>>e;
            e.afficher_tri_croissant();//TRI marche ok*/
    //ALL GOOOD!


    /**Test de classe pfe**/
    /*etudiants e;
    cin>>e;
    pfe p(e);
    p.saisir();
    cout<<"pfe p=\n"<<p<<endl;
    pfe g;
    cin>>g;

    pfe p1(p);//test de constructeur par recopie
    p1.afficher();
    p.saisir(e);
    cout<<g;*/

    /*etudiants e1 = p1.getetudiants(); //test de getteur des etudiants qui ont travaille dans une pfe donné
    cout<<e1*/
    /*pfe e;
    cin>>e;
    cout<<e<<endl;*/
    //ALL GOOD !

    /** Test classe pfes**/
    /*pfes p;
    p.remplir();
    p.afficher();    -> creation de pfes sans etudiants marche ok !
    //ALL GOOD!*/
    /*etudiants e;
    cin>>e;
    pfes p;
    p.remplir(e);
    //Le programme sarrette ici !!!!
    cout<<endl<<p.taille()<<endl;
    p.afficher();*/

    /*entreprises en;
    en.remplir(e,p);
    en.afficher_par_etudiant();*/

}
