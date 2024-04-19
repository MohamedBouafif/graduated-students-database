#include"pfes.h"
#include <set>
#include "vector"
#include <map>


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
    //cout<<endl;
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





void pfes::remplir(etudiants etds) {
    vector<etudiant*> v = etds.gettab();
    cout << "Saisir les sujets de PFE des étudiants\n";

    vector<pair<string, etudiant*>> w; // Ce vecteur contient le sujet de PFE de chaque étudiant
    set<string> sujet;                  // Cet ensemble contient les différents sujets de PFE

    for (int i = 0; i < (int)v.size(); i++) {
        cout << "PFE de :\n\t";
        cout << "Nom: " << v[i]->getnom() << "\tPrenom: " << v[i]->getprenom();
        cout << "\tIdentifiant: " << v[i]->getmatricule_E() << endl;
        cout << "Saisir le sujet de PFE\n";
        string s;
        cin >> s;

        w.push_back({s, v[i]});
        sujet.insert(s);
    }

    // Utilisation d'une map pour stocker les étudiants par sujet de PFE
    map<string, etudiants> res; // Chaque élément de cette map contient un sujet et les étudiants qui ont réalisé ce sujet

    for (auto it = sujet.begin(); it != sujet.end(); it++) {
        // Pour chaque sujet, on cherche les étudiants qui ont réalisé ce sujet
        etudiants etds;
        for (int i = 0; i < (int)w.size(); i++) {
            if (*it == w[i].first) {
                etds.ajouter(w[i].second, etds.taille());
            }
        }
        res[*it] = etds; // Stocker les étudiants dans la map avec le sujet comme clé
    }

    // Saisie des données de PFE pour chaque sujet
    for (auto it = res.begin(); it != res.end(); it++) {
        string sujet_pfe = it->first;
        etudiants etds = it->second;

        cout << "Saisir les données de PFE de sujet: " << sujet_pfe << endl;
        cout << "Field de sujet de PFE: " << endl;
        string f;
        cin >> f;

        cout << "L'entreprise de PFE: " << endl;
        string entreprise;
        cin >> entreprise;

        float n;
        cout << "Saisir la note: " << endl;
        cin >> n;
        pfe p(etds, sujet_pfe, f, entreprise, n); // création de notre PFE
        cout << "PFE: " << p << endl;
        this->ajouter(p, this->taille()); // Insertion réussie
    }

    cout << "Nombre de PFE: " << this->taille() << endl;
    this->afficher();
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
void pfes::enregistrer()
{
     ofstream fichier ("c:pfes.txt",ios::app);
    if (!fichier)
        cout << "erreur"<<endl ;
    fichier<<*this ;
    fichier.close();
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

pfes& pfes::operator = (const pfes& ps)
{
    if(this != &ps)
    {
        /**Liberation de la partie dynamique**/
        for(int i = 0; i <(int) tab_pfe.size(); i++)
        {
            delete &tab_pfe[i];
        }
        tab_pfe.clear();

        /**Copie**/
        for(int i  = 0; i<(int)ps.tab_pfe.size();i++)
            tab_pfe.push_back(ps.tab_pfe[i]);
    }
    return *this;
}
ostream& operator<<(ostream& out,pfes& p)
{
    out<<"Affichage des PFE: \n";
    for(int i = 0; i <(int)p.tab_pfe.size();i++)
    {
        p.tab_pfe[i].afficher();
    }
    return out;
}
istream& operator>>(istream& in,pfes& p)
{
    char rep;

    cout<<"\nAjouter pfe:\n";
    do
    {
        pfe e;
        //e.saisir();
        in>>e;
        p.tab_pfe.push_back(e);
        cout<<"Voulez-vous ajouter un autre PFE ?\n";
        cout<<"1:Oui\t2:Non\n";
        in>>rep;
    }
    while(rep=='1');
    return in;
}
