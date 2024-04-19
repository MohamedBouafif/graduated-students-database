#include"etudinat_ing.h"
/**Const**/
etudiant_ing::etudiant_ing(string section,string nom,string prenom,string mail,string CIN,string matricule_E,bool travaille,int jn,int mn,int an,int jd,int md,int ad,int jf,int mf,int af):etudiant(nom,prenom,mail,CIN,matricule_E,travaille,jn,mn,an,jd,md,ad,jf,mf,af)
{
    this->section = section;
    moyenne_general = calcul_moyenne_general();

}

/**CONST PAR RECOPIE**/
etudiant_ing::etudiant_ing(const etudiant_ing& e):etudiant(e)
{
    section = e.section;

    for(int i = 0; i < (int) e.classes.size(); i++)
    {
        classes.push_back(e.classes[i]);
    }
    for(int i = 0;i < (int) e.moyennes.size(); i++)
    {
        moyennes.push_back(e.moyennes[i]);
    }
    moyenne_general = calcul_moyenne_general();
}

/**DES**/
etudiant_ing::~etudiant_ing()
{
    for(int i = 0; i < (int)moyennes.size(); i++)
    {
        delete &moyennes[i];
    }
    moyennes.clear();

    for(int i = 0;i < (int)classes.size(); i++)
    {
        delete &classes[i];
    }
    classes.clear();
}


/**Les fonctions redefinies**/
void etudiant_ing::afficher()
{
    etudiant::afficher();

    cout<<"Section: "<<section<<endl;


    cout<<"Affichage des classes durant ses annees detudes:\n";
    for(int i = 0;i < (int)classes.size();i++)
    {
        cout<<classes[i]<<"\t";
    }

    cout<<endl;


    cout<<"Affichage des moyennes durant ses annees detudes:\n";
    for(int i = 0; i<(int)moyennes.size(); i++)
    {
        cout<<moyennes[i]<<"\t";
    }

    cout<<endl;
    cout<<"Moyenne general du cycle = "<<moyenne_general<<endl;
}


void etudiant_ing::saisir()
{

    etudiant::saisir();
    cout<<"Saisir la section: "<<endl;
    cin.ignore();
    getline(cin,section);

    int periode = dure_etude();

    cout<<"Saisir les classes durant ces annes detudes\n";
    for(int i = 0;i<periode;i++)
    {
        string c;
        getline(cin,c);
        classes.push_back(c);
    }

    cout<<"Saisir les moyennes durant ces annes detudes\n";
    for(int i = 0; i < periode;i++)
    {
        float moy;
        cin>>moy;
        moyennes.push_back(moy);
    }
    moyenne_general = calcul_moyenne_general();
}


/**NV FNC**/
void etudiant_ing::afficher_classes()
{
    cout<<"Affichage des classes durant ses annees detudes:\n";
    for(int i = 0;i < (int)classes.size();i++)
    {
        cout<<classes[i]<<"\t";
    }

    cout<<endl;
}

void etudiant_ing::afficher_moyennes()
{

    cout<<"Moyennes durant ses annees detudes:\n";
    for(int i = 0; i<(int)moyennes.size(); i++)
    {
        cout<<moyennes[i]<<"\t";
    }

    cout<<endl;
}

void etudiant_ing::chercher_classe(string c)
{
    for(int i = 0; i <(int)classes.size(); i++)
    {
        if(classes[i]==c)
        {
            cout<<"Classe trouvee\n";
            return;
        }
    }
    cout<<"Classe non trouve!\n";
    return ;
}

float etudiant_ing::calcul_moyenne_general()
{
    float moyenne = 0;
    for(int i = 0;i<(int)moyennes.size();i++)
    {
        moyenne += moyennes[i];
    }
    return moyenne/moyennes.size();
}


ostream& operator<<(ostream& out, etudiant_ing& etd)
{
    etudiant* e = &etd;
    out<<*e;
    out<<"Section: "<<etd.section<<endl;


    out<<"Affichage des classes durant ses annees detudes:\n";
    for(int i = 0;i < (int)etd.classes.size();i++)
    {
        out<<etd.classes[i]<<"\t";
    }

    out<<endl;


    out<<"Affichage des moyennes durant ses annees detudes:\n";
    for(int i = 0; i<(int)etd.moyennes.size(); i++)
    {
        out<<etd.moyennes[i]<<"\t";
    }

    out<<endl;
    out<<"Moyenne general du cycle dans la filiere "<<etd.section<<" = "<<etd.moyenne_general<<endl;
    return out;
}

istream& operator>>(istream& in, etudiant_ing& etd)
{
    etudiant* e = &etd;
    in>>*e;
    cout<<"Saisir la section: "<<endl;
    in.ignore();
    getline(in,etd.section);

    int periode = etd.dure_etude();

    cout<<"Saisir les classes durant ces annes detudes\n";
    for(int i = 0;i<periode;i++)
    {
        string c;
        getline(in,c);
        etd.classes.push_back(c);
    }

    cout<<"Saisir les moyennes durant ces annes detudes\n";
    for(int i = 0; i < periode;i++)
    {
        float moy;
        in>>moy;
        etd.moyennes.push_back(moy);
    }
    etd.moyenne_general = etd.calcul_moyenne_general();
    return in;
}


etudiant_ing& etudiant_ing::operator = (const etudiant_ing& w)
{
    if(this!=&w)
    {
        etudiant* ad1 = this;
        const etudiant* ad2 = &w;
        *ad1 = *ad2;

        /**Copie des parties statiques**/
        section = w.section;
        moyenne_general = w.moyenne_general;


        /**Liberation des parties dynamique**/
        for(int i = 0; i < (int)moyennes.size(); i++)
        {
        delete &moyennes[i];
        }
        moyennes.clear();

        for(int i = 0;i < (int)classes.size(); i++)
        {
            delete &classes[i];
        }
        classes.clear();



        for(int i = 0; i <(int) w.moyennes.size(); i++)
        {
            moyennes.push_back(w.moyennes[i]);
        }


        for(int i = 0; i < (int) w.classes.size(); i++)
        {
            classes.push_back(w.classes[i]);
        }
    }
    return *this;
}

bool etudiant_ing::operator < (const etudiant_ing&w)
{
    return moyenne_general < w.moyenne_general;
}
