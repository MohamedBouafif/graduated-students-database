#include "etudiant_master.h"


etudiant_master :: etudiant_master(string filier_licence,float note_pfe_licence,string filiere_master,string nom,string prenom,string mail,string CIN,string matricule_E,bool travaille,int jn,int mn,int an,int jd,int md,int ad,int jf,int mf,int af):
    etudiant(nom,prenom,mail,CIN,matricule_E,travaille,jn,mn,an,jd,md,ad,jf,mf,af)

{

    this->filiere_licence = filiere_licence;
    this->filiere_master = filiere_master;
    this->note_pfe_licence =  note_pfe_licence;


    moyenne_general = calcul_moyenne_general();

}

/**Const par recopie**/

etudiant_master :: etudiant_master(const etudiant_master &e):etudiant(e)
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
    for(int i = 0;i < (int)moyennes.size(); i++)
    {
        delete &moyennes[i];
    }
    /**le dernier boucle genere un erreur lors de COMPILATION **/

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

ostream& operator<<(ostream& out, etudiant_master& etd)
{
    etudiant* e = &etd;
    out<<*e;
    out<<"Filiere licence: ";
    out<<etd.filiere_licence<<endl;
    out<<"Filiere master: ";
    out<<etd.filiere_master<<endl;
    out<<"Note pfe licence: ";
    out<<etd.note_pfe_licence<<endl;

    out<<"Moyennes durant ses annees detudes:\n";
    for(int i = 0; i<(int)etd.moyennes.size(); i++)
    {
        out<<etd.moyennes[i]<<"\t";
    }
    out<<endl;
    out<<"Moyenne general de cycle = "<<etd.moyenne_general<<endl;
    return out;
}

istream& operator>>(istream& in, etudiant_master& etd)
{
    etudiant*e = &etd;
    in>>*e;
    cout<<"Filiere licence: "<<endl;
    in.ignore();
    getline(cin,etd.filiere_licence);
    cout<<"Filiere master: \n";
    in>>etd.filiere_master;
    cout<<"Note pfe licence: \n";
    in.ignore();
    in>>etd.note_pfe_licence;

    int periode = etd.dure_etude();
    cout<<"Notes durant ces annees d'etudes:\n";
    for(int i = 0; i < periode;i++)
    {
        float moy;
        in>>moy;
        etd.moyennes.push_back(moy);
    }
    etd.moyenne_general = etd.calcul_moyenne_general();
    return in;
}

etudiant_master& etudiant_master:: operator = (const etudiant_master& w)
{
    if(this!=&w)
    {
        etudiant* ad1 = this;
        const etudiant* ad2 = &w;
        *ad1 = *ad2;

        /**Liberation des parties dynamiques**/
        for(int i = 0;i < (int)moyennes.size(); i++)
        {
            delete &moyennes[i];
        }
        moyennes.clear();
        for(int i = 0; i < (int)w.moyennes.size(); i++)
            moyennes.push_back(w.moyennes[i]);


        /**Copie des parties statiques**/

        filiere_licence = w.filiere_licence;
        note_pfe_licence = w.note_pfe_licence;
        filiere_master = w.filiere_master;
        moyenne_general = w.moyenne_general;

    }
    return  *this;
}
bool etudiant_master::operator < (const etudiant_master& w)
{
    return moyenne_general < w.moyenne_general;
}


