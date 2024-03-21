#include "promotion_master.h"
#include<algorithm>
//constructeurs

promotion_master::promotion_master (int num_promo,int nb_etudiants_master,int jours,int mois ,int annee):
   date_graduation_master(jours,mois,annee)
{
    this->date_graduation_master=date_graduation_master;
    this->num_promo=num_promo ;
    this->nb_etudiants_master=nb_etudiants_master;
}
//constructeur par recopie
promotion_master ::promotion_master (const promotion_master& p)
{
    num_promo = p.num_promo;
    nb_etudiants_master = p.nb_etudiants_master;
    date_graduation_master = p.date_graduation_master;
    for (int i=0 ;i <p.etudiants_master.size(); i++)
    {
        etudiants_master[i]=p.etudiants_master[i];
    }
}
//destructeur
promotion_master::~promotion_master()
     {
         etudiants_master.clear();
     }
void promotion_master :: saisir_promo_mast()
{
    int rep =1 ;
    cout << "entrer le numero de promotion: "<<endl ;
    cin >>num_promo;
    cout << "entrer la  date de graduation de cette promo: "<< endl ;
    date_graduation_master.saisir();
    cout <<"saisie des etudiants de cette promotion : "<<endl;
    etudiant_master e ;
    e.saisir();
    etudiants_master.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    cin>>rep;
    while( rep ==1)
    {
    etudiant_master e ;
    e.saisir();
    etudiants_master.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    cin>>rep;
    }
    }

void promotion_master::afficher_promo_mast()
{   nb_etudiants_master= etudiants_master.size();
    cout <<"***************AFFICHAGE PROMOTION MASTER*************************"<<endl ;
    for (int i=0 ; i<nb_etudiants_master;i++)
    {
        etudiants_master[i].afficher();
    }
}
/*void insertionSort(vector<etudiant_master>& v) {

    for (int i = 1; i < v.size() ; ++i)
        {
        etudiant_master e ;
        e=v[i];
        int key = v[i].getmoyenne_general();
        int j = i ;

        while (j > 0 && v[j-1].getmoyenne_general() > key)
            {
            v[j ] = v[j-1];
            j = j - 1;
        }
        v[j] = e;
    }
}*/

bool compare (etudiant_master e1,etudiant_master e2)
{
    return e1.getmoyenne_general() > e2.getmoyenne_general();
}
void promotion_master::afficher_promo_mast_triee()
{
    sort (etudiants_master.begin(),etudiants_master.end(),compare);
    afficher_promo_mast();

}
 etudiant_master promotion_master ::majeur_promo_mast()
 {

     return etudiants_master[0];
 }
