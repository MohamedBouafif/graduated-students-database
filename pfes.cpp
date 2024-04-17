#include"pfes.h"
#include <set>
#include "vector"



pfes::pfes(const pfes& p)
{
    for(int i  = 0; i <(int) p.tab_pfe.size(); i++)
    {
        tab_pfe.push_back(p.tab_pfe[i]);
    }
}

pfes::~pfes()
{

    tab_pfe.clear();
}

void pfes::afficher()
{
    cout<<"Affichage des PFE: \n";
    for(int i = 0; i <(int)tab_pfe.size();i++)
    {
        tab_pfe[i].afficher();
    }
    cout<<endl;
}



void pfes::remplir()
{
    char rep;

    cout<<"\nAjouter pfe:\n";
    do
    {
        pfe e;
        //e.saisir();
        cin>>e;
        tab_pfe.push_back(e);
        cout<<"Voulez-vous ajouter un autre PFE ?\n";
        cout<<"1:Oui\t2:Non\n";
        cin>>rep;
    }
    while(rep=='1');
}





void pfes::remplir(etudiants etds)
{
    vector<etudiant*> v = etds.getab();
    cout<<"Saisir les sujet de pfe des etudiants\n";

    vector<pair<string,etudiant*>> w;     //Ce vecteur contient le sujetde pfe de chaque etudiant
    set <string> sujet;                            //cet ensemble contient les different sujet de pfe

    for(int i = 0; i < (int)v.size(); i++)
    {
        cout<<"PFE de :\n\t";
        cout<<"Nom: "<<v[i]->getnom()<<"Prenom: "<<v[i]->getprenom();
        cout<<"Identifiant: "<<v[i]->getmatricule_E()<<endl;
        cout<<"Saisir le sujet de pfe\n";
        string s;
        cin>>s;

        w.push_back({s,v[i]});
        sujet.insert(s);
    }


    vector<pair<string, etudiants>> res;   // chaque element de ce vecteur contient un tuple de
                                            // sujet et les etudiants qui ont realiser ce sujet

    // jaurait pu utiliser un map mais ce nest pas necessaire car elle gaspille de la memoire sans besoin (j'ai pas besoin doptimiser la complexité temporelle ici)
    for(auto it = sujet.begin();it!=sujet.end(); it++)
    {

        //pour chaque sujet on cherche les etudiants qui ont realiser ce sujet
        etudiants etds;
        for(int i =0;i<(int)w.size();i++)
        {
            if(*it==w[i].first)
            {
                etds.ajouter(w[i].second,etds.taille());
            }

        }
        res.push_back({*it,etds});
    }

    int nb_sujet = sujet.size();
    /*cout<<"taille resultat = "<<res.size()<<endl;
    cout<<"nb sujet = "<<nb_sujet<<endl;*/
    for(int i = 0; i < nb_sujet; i++)
    {
        string sujet_pfe = res[i].first;
        etudiants etds  = res[i].second;
        cout<<"Saisir les donnes de pfe de sujet: "<<sujet_pfe<<endl;
        cout<<"Field de sujet de pfe: "<<endl;
        string f;
        cin>>f;

        cout<<"L'entreprise de pfe: "<<endl;
        string entreprise;
        cin>>entreprise;

        float n;
        cout<<"Saisir la note: "<<endl;
        cin>>n;
        pfe p(etds, sujet_pfe,f, entreprise,n); // creation de notre pfe
        //cout<<p<<endl;
        this->ajouter(p,this->taille()); // linsetion se fait avec succes
    }
}

int pfes::taille()
{
    return tab_pfe.size();
}


void pfes::ajouter(pfe p,int ind)
{
    if(ind>=0 && ind<=(int)tab_pfe.size())
    {
        tab_pfe.insert(tab_pfe.begin() + ind, p);
        cout<<"Insertion avec succes\n";
    }
    else cout<<"Impossible dajouter la pfe a la position desiree"<<endl;
}


void pfes::supprimer(int ind)
{
    if(ind>=0 && ind<=(int)tab_pfe.size())
    {
       tab_pfe.erase(tab_pfe.begin()+ind);
       cout<<"Suppression avec succes\n";
    }
    else cout<<"position inexistante!"<<endl;

}
void pfes::enregistrer()
{
     ofstream fichier ("c:pfes.txt",ios::app);
    if (!fichier)
        cout << "erreur"<<endl ;
    fichier<<*this ;
    fichier.close();

}
/*********************surcharge des operateurs ***********************/
 ostream& operator<<(ostream& out,pfes& p)
 {
        out<<"Affichage des PFE: \n";
    for(int i = 0; i <(int)p.tab_pfe.size();i++)
    {
       out << p.tab_pfe[i];
    }
    cout<<endl;
    return out;
 }
