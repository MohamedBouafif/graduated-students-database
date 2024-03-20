#include "promotion_master.h"
promotion_master ::promotion_master()
{
    num_promo =0 ;
    nb_etudiants_master=0;
}
promotion_master :: promotion_master (date date_graduation_master, int num_promo, int nb_etudiants_master)
{
    this->date_graduation_master=date_graduation_master;
    this->num_promo=num_promo ;
    this->nb_etudiants_master=nb_etudiants_master;
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
void insertionSort(vector<etudiant_master>& v) {

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
}
void promotion_master::afficher_promo_mast_triee()
{
    insertionSort(etudiants_master);
    afficher_promo_mast();

}
 etudiant_master promotion_master ::majeur_promo_mast()
 {

     return etudiants_master[(etudiants_master.size()-1)];
 }
