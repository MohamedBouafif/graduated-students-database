#include "promotion_ing.h"
promotion_ing ::promotion_ing()
{
    num_promo =0 ;
    nb_etudiants_ing=0;
}
promotion_ing :: promotion_ing(date date_graduation_ing, int num_promo, int nb_etudiants_ing)
{
    this->date_graduation_ing=date_graduation_ing;
    this->num_promo=num_promo ;
    this->nb_etudiants_ing=nb_etudiants_ing;
}
void promotion_ing :: saisir_promo_ing()
{
    int rep =1 ;
    cout << "entrer le numero de promotion: "<<endl ;
    cin >>num_promo;
    cout << "entrer la  date de graduation de cette promo: "<< endl ;
    date_graduation_ing.saisir();
    cout <<"saisie des etudiants de cette promotion : "<<endl;
    etudiant_ing e ;
    e.saisir();
    etudiants_ing.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    cin>>rep;
    while( rep ==1)
    {
    etudiant_ing e ;
    e.saisir();
    etudiants_ing.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    cin>>rep;
    }
    }

void promotion_ing::afficher_promo_ing()
{   nb_etudiants_ing= etudiants_ing.size();
    cout <<"***************AFFICHAGE PROMOTION INGENIEURS *************************"<<endl ;
    for (int i=0 ; i<nb_etudiants_ing;i++)
    {
        etudiants_ing[i].afficher();
    }
}
void insertionSort(vector<etudiant_ing>& v) {

    for (int i = 1; i < v.size() ; ++i)
        {
        etudiant_ing e ;
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
void promotion_ing::afficher_promo_ing_triee()
{
    insertionSort(etudiants_ing);
    afficher_promo_ing();

}
 etudiant_ing promotion_ing ::majeur_promo_ing()
 {
     cout <<"**********affichage_majeur_promo_ing***************"<<endl;
     return etudiants_ing[(etudiants_ing.size()-1)];
 }
