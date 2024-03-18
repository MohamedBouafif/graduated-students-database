#include "etudiant.h"
#include <algorithm>
/**Constructeur**/
etudiant::etudiant(string nom,string prenom,string mail,string CIN,string matricule_E,bool travaille,int jn,int mn,int an,int jd,int md,int ad,int jf,int mf,int af):
    date_de_naissance(jn,mn,an),date_debut(jd,md,ad),date_fin(jf,mf,af)
{
    this->nom = nom;
    this->prenom = prenom;
    this->mail=mail;
    this->CIN = CIN;
    this->matricule_E = matricule_E;
    //this->moyenne = moyenne;
    this->travaille = travaille;
    if(travaille)
    {
        char e;
        do
        {

            cout<<"Saisir le nom de l'entreprise que letudiant travaille\n";
            string nomE;
            cin>>nomE;
            societes.push_back(nomE);
            cout<<"Vous voulez ajouter d'autre(s)\n1:OUI\t2:NON";
            cin>>e;

        }while(e=='1');
    }

}

/**Constructeur par recopie**/
etudiant::etudiant(const etudiant& e)
{
    nom = e.nom;
    prenom = e.prenom;
    mail = e.mail;
    CIN = e.CIN;
    matricule_E = e.matricule_E;

    //moyenne = e.moyenne;

    travaille = e.travaille;

    for(int i = 0; i < (int)e.societes.size() ; i++)
    {
        societes.push_back(e.societes[i]);
    }

    date_debut = e.date_debut;
    date_fin = e.date_fin;
    date_de_naissance = e.date_de_naissance;

}


/**AFFICHER: (ba3d bch na3mloulha surcharche ta3 cin>> ) **/
void etudiant::afficher()
{
    cout<<"Nom: "<<nom<<endl;
    cout<<"Prenom: "<<prenom<<endl;
    cout<<"Mail: "<<mail<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"Matricule de l'etudiant: "<<matricule_E<<endl;
    //cout<<"La moyenne de l'etudiant durant ces 3 annees: \n"<<moyenne<<endl;
    if(travaille)
    {
        cout<<"L'etudiant travaille \n";
        cout<<"Il a travaille recamment dans ces entreprises: \n";

        sort(societes.begin(),societes.end());

        for(int i = 0; i < (int) societes.size() ;i++)
        {
            cout<<societes[i]<<"\t";
        }
        cout<<endl;
    }
    else cout<<"l'etudiant ne travaille pas encore \n";

    date_de_naissance.afficher("La date de naissance de letudiant est: \n");
    date_debut.afficher("La date de debut d'etude: \n");
    date_fin.afficher("La date de fin d'etude: \n");



}


/**METHODE SAISIR (ba3d bch na3mloulha surcharge par cout<<) **/
void etudiant::saisir()
{
    cout<<"Saisir les donnes de letudiant selon l'ordre suivant: \n";
    cout<<"Nom: ";
    cin>>nom;
    cout<<"Prenom: ";
    cin>>prenom;
    cout<<"Mail: ";
    cin>>mail;
    cout<<"CIN: ";
    cin>>CIN;
    cout<<"Matricule: ";
    cin>>matricule_E;
    //cout<<"Moyenne: ";
    //cin>>moyenne;

    cout<<"A il travaille ?\n1-OUI\t2-NON\n";
    char e;
    cin>>e;
    if(e=='1')
    {
        travaille = 1;
        cout<<"Saisir les entreprises que l'etudiant a travaille\n";
        char x;
        do
        {
            cout<<"Nom entreprise: ";
            string s;
            cin>>s;
            societes.push_back(s);
            cout<<"Voulez_vous ajouter d'autre(s)";
            cout<<"\n1-OUI\t2-NON\n";
            cin>>x;
        }while(x=='1');
    }
    else travaille = 0;


    date_de_naissance.saisir("Saisir la date de naissance de letudiant\n");
    date_debut.saisir("Saisir la date de debut d'etude:\n");
    date_fin.saisir("Saisir la date de fin d'etude:\n");

}

/**Destructeur**/
etudiant::~etudiant()
{
    societes.clear();
}

int etudiant::taille()
{
    return societes.size();
}

void etudiant::chercher_Societe(string societe)
{
    for(int  i = 0; i<(int)societes.size(); i++)
    {
        if(societes[i] == societe)
        {
            cout<<"Socite trouvee!";
            return;
        }
    }
    cout<<"Societe non trouvee\n";
    return;
}


int etudiant::dure_etude()
{

    int x = date_fin.getannee() - date_debut.getannee();

    if(x==0||x==1)
    {
        return 1;
    }
    else return x;
}

void etudiant::redouble()
{
    int periode = dure_etude();
    if(periode>3)
    {
        int annes_redouble = periode - 3;
        cout<<"L'etudiant a redouble "<<annes_redouble<<" annee(s)\n";
    }
    else
    {
        cout<<"L'etudiant n'a pas redouble aucune annee a notre universite\n";
    }
}
