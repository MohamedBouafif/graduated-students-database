#include "etudiant_master.h"
etudiant_master::etudiant_master(string filier_licence,float note_pfe_licence,string filiere_master,string nom,string prenom,string mail,string CIN,string matricule_E,bool travaille,int jn,int mn,int an,int jd,int md,int ad,int jf,int mf,int af):
    etudiant(nom,prenom,mail,CIN,matricule_E,travaille,jn,mn,an,jd,md,ad,jf,mf,af)
{

    this->filiere_licence = filiere_licence;
    this->filiere_master = filiere_master;
    this->note_pfe_licence =  note_pfe_licence;
    moyenne_general = calcul_moyenne_general();
}

etudiant_master::etudiant_master(const etudiant_master &e):etudiant(e)
{
    filiere_licence = e.filiere_licence;
    filiere_master = e.filiere_master;
    note_pfe_licence = e.note_pfe_licence;

    for(int i = 0;i<(int)e.moyennes.size(); i++)
    {
        moyennes.push_back(e.moyennes[i]);
    }
    moyenne_general = calcul_moyenne_general();
}
etudiant_master::~etudiant_master()
{
    /*for(int i = 0;i < (int)moyennes.size(); i++)
    {
        delete moyennes[i];
    }*/
    moyennes.clear();
}

void etudiant_master:: saisir()
{
    etudiant::saisir();
    cout<<"Filiere licence: "<<endl;
    cin.ignore();
    getline(cin,filiere_licence);
    cout<<"Filiere master: \n";
    cin>>filiere_master;
    cout<<"Note pfe licence: \n";
    cin.ignore();
    cin>>note_pfe_licence;

    int periode = dure_etude();
    cout<<"Notes durant ces annees d'etudes:\n";
    for(int i = 0; i < periode;i++)
    {
        float moy;
        cin>>moy;
        moyennes.push_back(moy);
    }
    moyenne_general = calcul_moyenne_general();
}

void etudiant_master::afficher()
{
    etudiant::afficher();
    cout<<"Filiere licence: ";
    cout<<filiere_licence<<endl;
    cout<<"Filiere master: ";
    cout<<filiere_master<<endl;
    cout<<"Note pfe licence: ";
    cout<<note_pfe_licence<<endl;

    cout<<"Moyennes durant ses annees detudes:\n";
    for(int i = 0; i<(int)moyennes.size(); i++)
    {
        cout<<moyennes[i]<<"\t";
    }
    cout<<endl;
    cout<<"Moyenne general de cycle = "<<moyenne_general<<endl;
}
float etudiant_master::calcul_moyenne_general()
{
    float moyenne = 0;
    for(int i = 0;i<(int)moyennes.size();i++)
    {
        moyenne += moyennes[i];
    }
    return moyenne/moyennes.size();
}
