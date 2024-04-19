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

    cout<<"La date de naissance de letudiant est: \n";
    cout<<date_de_naissance<<endl;

    cout<<"La date de debut d'etude: \n";
    cout<<date_debut<<endl;

    cout<<"La date de fin d'etude: \n";
    cout<<date_fin<<endl;



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

    cout<<"Saisir la date de naissance de letudiant\n";
    cin>>date_de_naissance;

    cout<<"Saisir la date de debut d'etude:\n";
    cin>>date_debut;

    cout<<"Saisir la date de fin d'etude:\n";
    cin>>date_fin;

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

bool etudiant::chercher_Societe(string societe)
{
    for(int  i = 0; i<(int)societes.size(); i++)
    {
        if(societes[i] == societe)
        {
            cout<<"Socite trouvee!";
            return 1;
        }
    }
    cout<<"Societe non trouvee\n";
    return 0;
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
ostream& operator<< (ostream& out, etudiant& etd)
{
    out<<"Nom: "<<etd.nom<<endl;
    out<<"Prenom: "<<etd.prenom<<endl;
    out<<"Mail: "<<etd.mail<<endl;
    out<<"CIN: "<<etd.CIN<<endl;
    out<<"Matricule de l'etudiant: "<<etd.matricule_E<<endl;

    if(etd.travaille)
    {
        out<<"L'etudiant travaille \n";
        out<<"Il a travaille recamment dans ces entreprises: \n";

        sort(etd.societes.begin(),etd.societes.end());    //On a volu juste afficher les societes par ordre lexecographique

        for(int i = 0; i < (int) etd.societes.size() ;i++)
        {
            out<<etd.societes[i]<<"\t";
        }
        out<<endl;

    }
    else out<<"l'etudiant ne travaille pas encore \n";

    cout<<"La date de naissance de letudiant est: \n";
    cout<<etd.date_de_naissance<<endl;

    cout<<"La date de debut d'etude: \n";
    cout<<etd.date_debut<<endl;

    cout<<"La date de fin d'etude: \n";
    cout<<etd.date_fin<<endl;
    return out;
}

istream& operator>> (istream& in, etudiant& etd)
{
    cout<<"Saisir les donnes de letudiant selon l'ordre suivant: \n";
    cout<<"Nom: ";
    in>>etd.nom;
    cout<<"Prenom: ";
    in>>etd.prenom;
    cout<<"Mail: ";
    in>>etd.mail;
    cout<<"CIN: ";
    in>>etd.CIN;
    cout<<"Matricule: ";
    in>>etd.matricule_E;
    cout<<"A il travaille ?\n1-OUI\t2-NON\n";
    char e;
    in>>e;
    if(e=='1')
    {
        etd.travaille = 1;
        cout<<"Saisir les entreprises que l'etudiant a travaille\n";
        char x;
        do
        {
            cout<<"Nom entreprise: ";
            string s;
            in>>s;
            etd.societes.push_back(s);
            cout<<"Voulez_vous ajouter d'autre(s) entreprises";
            cout<<"\n1-OUI\t2-NON\n";
            in>>x;
        }while(x=='1');
    }
    else etd.travaille = 0;


    cout<<"Saisir la date de naissance de letudiant\n";
    in>>etd.date_de_naissance;

    cout<<"Saisir la date de debut d'etude:\n";
    in>>etd.date_debut;

    cout<<"Saisir la date de fin d'etude:\n";
    in>>etd.date_fin;
    return in;
}



etudiant& etudiant::operator = (const etudiant& e)
{
    if(this!=&e)
    {
        nom=e.nom;
        prenom=e.prenom;
        mail=e.mail;
        CIN=e.CIN;
        matricule_E = e.matricule_E;
        travaille = e.travaille;
        /**Supprimer le vecteur qui contients les societes de this   <=> supprimer ma partie dynamique de this**/
        societes.clear();
        for(int i = 0; i < (int) e.societes.size(); i++)
        {
            societes.push_back(e.societes[i]);
        }

        date_de_naissance = e.date_de_naissance;
        date_debut = e.date_debut;
        date_fin = e.date_fin;

    }
    return *this;
}

bool etudiant::operator == (const etudiant& e)
{
    if(CIN!=e.CIN||matricule_E!=e.matricule_E) return false;
    return true;
}


