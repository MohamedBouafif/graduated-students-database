#include "entreprise.h"
entreprises::entreprises()
{
    //Constructeur vide
}
/**Constructeur par recopie**/
entreprises::entreprises(const entreprises& e)
{
    /**Remplissage de set**/
    for(set<string>::iterator it = e.nom_entreprises.begin();it!=e.nom_entreprises.end(); it++)
    {
        nom_entreprises.insert(*it);
    }


    /**Remplissage des map**/
    for(auto it = e.poste_etd.begin() ; it!= e.poste_etd.end(); it++)
    {
        poste_etd[it->first] = it->second;
    }


    for(auto it = e.stage.begin(); it!=e.stage.end(); it++)
    {
        stage[it->first] = it->second;
    }
}
/**Dest**/
entreprises::~entreprises()
{
    /** Destruction de set**/
    for(set<string>::iterator it = nom_entreprises.begin();it!=nom_entreprises.end(); it++ )
    {
        delete &(*it);
    }
    nom_entreprises.clear();

    /**Destruction  des map**/
    for(auto it = poste_etd.begin() ; it!= poste_etd.end(); it++)
    {
        delete &(it->second);   //il suffit de supprimer le pointeur associé a la valeur
    }
    poste_etd.clear();
    for(auto it = stage.begin(); it!=stage.end(); it++)
    {
        delete &it->second;
    }
    stage.clear();
}
/**Remplissage**/


void entreprises::remplirnom_entreprises(etudiants e)
{
    for (etudiant* f : e.gettab())
    {
        vector<string> v = f->getsocietes();

        for (const string& entreprise : v)
        {
            nom_entreprises.insert(entreprise);
        }
    }
    cout << "appelle remplir nom\n";
}

void entreprises::remplirposte_etd(etudiants e)
{
    for(int i = 0; i <(int) e.tab.size(); i++)
    {
        etudiant* f = e.tab[i];
        vector<pair<string,string>> poste; //vecteur contient <poste  , nom entreprise>

        vector<string> v=f->getsocietes();

        for(int j = 0; j<(int)v.size();j++)
        {
            cout<<"Saisir les Postes de lancien etudiant dans la societe: "<<v[j]<<endl;
            string p;
            cin>>p;
            poste.push_back({p,v[j]});
        }
        poste_etd[f] = poste;   //O(log(n))
    }
    cout<<"remplir poste\n";
}
void entreprises::remplirstage(pfes p)
{
    vector<pfe> v = p.gettab_pfe();

    for(int i = 0; i < (int) v.size(); i++)
    {
        string sujetpfe = v[i].getsujet_pfe();
        string entreprise = v[i].getentreprise_stage_pfe();
        etudiants etds = v[i].getetudiants();

        for(int j =0; j <(int)etds.tab.size(); j++)
        {
            etudiant* e = etds.tab[j];

            stage[e] ={sujetpfe,entreprise};
        }
    }
    cout<<"remplir stage";
}



void entreprises::afficher_par_etudiant()
{
    cout<<"*****************Affichage des etudiant qui ont travalle*************************\n";
    int cnt = 0;
    cout<<cnt<<endl;
    for(auto it:poste_etd)
    {
        cnt++;
        etudiant* e = it.first;
        vector<pair<string,string>> poste = it.second;

        cout<<"Informations de ";

        if(cnt==1)cout<<"1er etudiant:\n";
        else cout<<cnt<<"eme etudiant:\n";

        cout<<"Nom & Prenom: "<< e->getnom() <<" "<< e->getprenom() <<endl;
        cout<<"Mail: "<<e->getmail()<<endl;

        cout<<"Postes de l'etudiant:\n";
        for(int i = 0; i<(int)poste.size(); i++)
        {
            cout<<i+1<<"-Poste: "<<poste[i].first<<" "<<"Entreprise: "<<poste[i].second<<endl;
        }

        cout<<"stage de pfe:\n";
        pair<string,string> s = stage[it.first];
        cout<<"\tSujet: "<<s.first<<endl;
        cout<<"\tEntreprise: "<<s.second<<endl;
    }
}


ostream& operator<<(ostream& out, entreprises& es)
{
    out<<"*****************Affichage des etudiant qui ont travalle*************************\n";
    int cnt = 0;
    out<<cnt<<endl;
    for(auto it:es.poste_etd)
    {
        cnt++;
        etudiant* e = it.first;
        vector<pair<string,string>> poste = it.second;

        out<<"Informations de ";

        if(cnt==1)out<<"1er etudiant:\n";
        else out<<cnt<<"eme etudiant:\n";

        out<<"Nom & Prenom: "<< e->getnom() <<" "<< e->getprenom() <<endl;
        out<<"Mail: "<<e->getmail()<<endl;

        out<<"Postes de l'etudiant:\n";
        for(int i = 0; i<(int)poste.size(); i++)
        {
            out<<i+1<<"-Poste: "<<poste[i].first<<" "<<"Entreprise: "<<poste[i].second<<endl;
        }

        out<<"stage de pfe:\n";
        pair<string,string> s = es.stage[it.first];
        out<<"\tSujet: "<<s.first<<endl;
        out<<"\tEntreprise: "<<s.second<<endl;
    }
    return out;
}


istream& operator>>(istream& in , entreprises&e){return in;}

entreprises&  entreprises:: operator = (const entreprises& es)
{
    if(this!=&es)
    {
        /**suppression des parties dynamiqe**/
        for(set<string>::iterator it = nom_entreprises.begin();it!=nom_entreprises.end(); it++ )
        {
            delete &(*it);
        }
        nom_entreprises.clear();
        for(auto it = poste_etd.begin() ; it!= poste_etd.end(); it++)
        {
            delete &(it->second);   //il suffit de supprimer le pointeur associé a la valeur
        }
        poste_etd.clear();
        for(auto it = stage.begin(); it!=stage.end(); it++)
        {
            delete &it->second;
        }
        stage.clear();


        /**Recopiage**/
        for(set<string>::iterator it = es.nom_entreprises.begin();it!=es.nom_entreprises.end(); it++)
        {
            nom_entreprises.insert(*it);
        }


        for(auto it = es.poste_etd.begin() ; it!= es.poste_etd.end(); it++)
        {
            poste_etd[it->first] = it->second;
        }


        for(auto it = es.stage.begin(); it!=es.stage.end(); it++)
        {
            stage[it->first] = it->second;
        }
    }
    return *this;
}

