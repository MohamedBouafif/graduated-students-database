#include "promotion_ing.h"

//constructeurs

promotion_ing::promotion_ing (int num_promo_ing,int nb_etudiants_ing,int jours,int mois ,int annee):
   date_graduation_ing(jours,mois,annee)
{
    this->date_graduation_ing=date_graduation_ing;
    this->num_promo_ing=num_promo_ing ;
    this->nb_etudiants_ing=nb_etudiants_ing;
}
//constructeur par recopie
promotion_ing::pomotion_ing(const promotion_ing& p)
{
    num_promo_ing = p.num_promo_ing;
    nb_etudiants_ing = p.nb_etudiants_ing;
    date_graduation_ing = p.date_graduation_ing;
    for (int i=0 ;i <p.etudiants_ing.size(); i++)
    {
        etudiants_ing[i]=p.etudiants_ing[i];
    }
}
//destructeur
promotion_ing::~promotion_ing()
{
    etudiants_ing.clear();
}



void promotion_ing :: saisir_promo_ing()
{
    int rep =1 ;
    cout << "entrer le numero de promotion: "<<endl ;
    cin >>num_promo_ing;
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
    cout <<"numero de promotion d'ingenieur : "<<num_promo_ing<<endl ;
    cout <<"date de graduation : ";
    date_graduation_ing.afficher() ;
    cout <<"nombres  d'etudiants: "<< nb_etudiants_ing<<endl ;

    for (int i=0 ; i<nb_etudiants_ing;i++)
    {
        etudiants_ing[i].afficher();
    }
}
bool compare (etudiant_ing e1,etudiant_ing e2)
{
    return e1.getmoyenne_general() > e2.getmoyenne_general();
}
void promotion_ing::afficher_promo_ing_triee()
{    //Sort the vector using the compare function
//   sort (etudiants_ing.begin(),etudiants_ing.end(),compare);
    //display the sorted result
    afficher_promo_ing();


}
 etudiant_ing promotion_ing ::majeur_promo_ing()
 {

     return etudiants_ing[0];
 }
 void promotion_ing::ajouter_etudiant_ing(etudiant_ing e )
{
    etudiants_ing.push_back(e);
}

ostream& operator<<(ostream& out,promotion_ing& p)
{
    p.nb_etudiants_ing= p.etudiants_ing.size();
    out <<"***************AFFICHAGE PROMOTION INGENIEURS *************************"<<endl ;
    out <<"numero de promotion d'ingenieur : "<< p.num_promo_ing<<endl ;
    out <<"date de graduation : ";
    p.date_graduation_ing.afficher() ;
    out <<"nombres  d'etudiants: "<< p.nb_etudiants_ing<<endl ;

    for (int i=0 ; i<p.nb_etudiants_ing;i++)
    {
        p.etudiants_ing[i].afficher();
    }
    return out ;

}
istream& operator>>(istream& in,promotion_ing& p)
{
    int rep =1 ;
    cout << "entrer le numero de promotion: "<<endl ;
    in >>p.num_promo_ing;
    cout << "entrer la  date de graduation de cette promo: "<< endl ;
    p.date_graduation_ing.saisir();
    cout <<"saisie des etudiants de cette promotion : "<<endl;
    etudiant_ing e ;
    e.saisir();
    p.etudiants_ing.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    in>>rep;
    while( rep ==1)
    {
    etudiant_ing e ;
    e.saisir();
    p.etudiants_ing.push_back(e);
    cout<<"Voulez-vous rajouter dautres etudiants?\n";
    cout<<"1:Oui\t2:Non\n";
    in>>rep;
    }

    return in;
}


