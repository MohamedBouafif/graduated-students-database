#include"etudiants.h"
/**Const**/
etudiants::etudiants()
{
    //Constructeur vide
}

/**Const par recopie**/
etudiants::etudiants(const etudiants& w)
{
    etudiant* e;
    for(int i = 0; i <(int) w.tab.size();i++)
    {
        if(typeid(*w.tab[i])==typeid(etudiant_ing))
            e = new etudiant_ing(static_cast<const etudiant_ing&>(*w.tab[i]));

        else if(typeid(*w.tab[i])==typeid(etudiant_master))
            e = new etudiant_master(static_cast<const etudiant_master&>(*w.tab[i]));

        tab.push_back(e);
    }
}
/**Dest**/
etudiants::~etudiants()
{
    for(int i = 0; i <(int)tab.size();i++)
    {
        delete tab[i];
    }
    tab.clear();
}
void etudiants::afficher()
{
    for(int i = 0;i <(int) tab.size();i++)
    {
        tab[i]->afficher();
    }
}
void etudiants::remplir()
{
    char rep;
    etudiant* e;
    int choix;
    cout<<"\nAjouter:\n";
    do
    {
        cout<<"1:etudiant ingenieur\t2:etudiant master\n";
        cin>>choix;
        if(choix==1)
        {
            e = new etudiant_ing();
        }
        else if(choix==2)
        {
            e = new etudiant_master();
        }
        else break;
        e->saisir();
        tab.push_back(e);
        cout<<"Voulez-vous ajouter?\n";
        cout<<"1:Oui\t2:Non\n";
        cin>>rep;
    }
    while(rep=='1');
}
void etudiants::ajouter(etudiant_ing w,int ind)
{
    etudiant* e = new etudiant_ing(w);
    if(ind>=0&&ind<=(int)tab.size())
    {
        tab.insert(tab.begin()+ind,e);
    }
    else cout<<"Vous ne pouvez pas inserer cette etudiant a cette postion\n";
}
void etudiants::ajouter(etudiant_master w,int ind)
{
    etudiant* e = new etudiant_master(w);
        if(ind>=0&&ind<=(int)tab.size())
    {
        tab.insert(tab.begin()+ind,e);
    }
    else cout<<"Vous ne pouvez pas inserer cette etudiant a cette postion\n";
}

void etudiants::ajouter(etudiant* e,int ind)
{
    tab.insert(tab.begin()+ind,e);
}


void etudiants::supprimer(int ind)
{
    delete tab[ind];
    tab.erase(tab.begin()+ind);
}

int etudiants::taille()
{
    return tab.size();
}





ostream& operator<<(ostream& out,etudiants& etd)
{

    for(int i =0; i<(int)etd.tab.size(); i++)
    {
        etudiant* e = etd.tab[i];
        out<<*e;
    }
    return out;
}

istream& operator>>(istream& in, etudiants& etd)
{

    char rep;
    etudiant* e;
    int choix;
    cout<<"\nAjouter:\n";
    do
    {
        cout<<"1:etudiant ingenieur\t2:etudiant master\n";
        in>>choix;
        if(choix==1)
        {
            e = new etudiant_ing();
        }
        else if(choix==2)
        {
            e = new etudiant_master();
        }
        else break;
        in>>*e;
        etd.tab.push_back(e);
        cout<<"Voulez-vous ajouter?\n";
        cout<<"1:Oui\t2:Non\n";
        in>>rep;
    }
    while(rep=='1');
    return in;
}
