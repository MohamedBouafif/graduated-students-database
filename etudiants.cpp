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
    cout<<"Ajouter:\n";
    do
    {
        cout<<"1:etudiant ingenieur\tou\t2:etudiant master\n";
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
    delete tab[ind];  //free memory

    tab.erase(tab.begin()+ind);
}


ostream& operator<<(ostream& out,etudiants& etd)
{

    for(int i =0; i<(int)etd.tab.size(); i++)
    {
        etudiant* e = etd.tab[i];
        e->afficher(); // ici il appelle le surcharge de classe etudiant
    }
    return out;
}

istream& operator>>(istream& in, etudiants& etd)
{

    char rep;
    etudiant* e;
    int choix;
    cout<<"Ajouter\n";
    do
    {
        cout<<"1:etudiant ingenieur\t\t2:etudiant master\n";
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
        e->saisir();//hedhy normalement in>>*e;
        etd.tab.push_back(e);
        cout<<"Voulez-vous ajouter un etudiant?\n";
        cout<<"1:Oui\t2:Non\n";
        in>>rep;
    }
    while(rep=='1');
    return in;
}

etudiants& etudiants::operator = (const etudiants& w)
{
    if(this!= &w)
    {
        /** suppression des parties dynamiques**/
        for(int i = 0 ;i < (int)tab.size();i++)
            delete tab[i];
        tab.clear();


        /**Sa ressemble au constructeur par recopie **/
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
    return *this;
}
etudiants& etudiants::operator + (const etudiants& w)
{
    for(int i = 0 ; i <(int) w.tab.size(); i++)
    {
        this->ajouter(w.tab[i],tab.size());
    }
    return *this;
}


void etudiants::afficher_tri_croissant()
{
    sort(tab.begin(), tab.end());

    cout<<*this;

}

float etudiants::pourcentage_reussite()
{
    int n  = tab.size();
    int s = 0;
    for(int i = 0; i < n ; i++)
    {
        etudiant* e = tab[i];
        if(typeid(*e) == typeid(etudiant_ing)){
            etudiant_ing* ing_ptr = dynamic_cast<etudiant_ing*>(e);
            if(ing_ptr && ing_ptr->getmoyenne_general() >= 10) s++;
        }
        else if(typeid(*e) == typeid(etudiant_master)){
            etudiant_master* master_ptr = dynamic_cast<etudiant_master*>(e);
            if(master_ptr && master_ptr->getmoyenne_general() >= 10) s++;
        }
    }
    return (float)s / n * 100;
}

float etudiants::pourcentage_redouble()
{
    float x = this->pourcentage_reussite();
    return 100 - x;
}
float etudiants::pourcentage_chommage()
{
    float x=0;
    for(int i = 0; i < (int)tab.size(); i++)
    {
        if(tab[i]->getsocietes().size()==0) x++;
    }
    return x/tab.size();
}
