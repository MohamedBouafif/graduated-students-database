#include "pfe.h"
pfe::pfe(string sujet_pfe, string entreprise_stage_pfe,string field, float note_attribue)
{
    this->sujet_pfe = sujet_pfe;
    this->entreprise_stage_pfe = entreprise_stage_pfe;
    this->note_attribue = note_attribue;
    this->field = field;

}

pfe::pfe(etudiants etds,string sujet_pfe, string entreprise_stage_pfe,string field, float note_attribue)
{
    this->sujet_pfe = sujet_pfe;
    this->entreprise_stage_pfe = entreprise_stage_pfe;
    this->note_attribue = note_attribue;
    this->field = field;
    Etudiants = etds;
}


pfe::~pfe()
{
    //Destructeur vide
}

void pfe::saisir()
{

    cout<<"Saisir les donnees de pfe selon l'ordre suivant:\n";
    cout<<"Sujet pfe: "<<endl;
    cin>>sujet_pfe;
    cout<<"Le field de sujet de pfe: "<<endl;
    cin>>field;
    cout<<"Entreprise de stage de pfe: "<<endl;
    cin>>entreprise_stage_pfe;
    cout<<"Note attribue a la pfe: "<<endl;
    cin>>note_attribue;
    vector<etudiant*> v = Etudiants.gettab();
    if(v.size()==0){
    cout<<"saisir les etudiant qui ont realise ce sujet de pfe:\n";
    cin>>Etudiants;}
}
void pfe::saisir(etudiants etds)
{
    cout<<"Saisir les donnees de pfe selon l'ordre suivant:\n";
    cout<<"Sujet pfe: "<<endl;
    cin>>sujet_pfe;
    cout<<"Le field de sujet de pfe: "<<endl;
    cin>>field;
    cout<<"Entreprise de stage de pfe: "<<endl;
    cin>>entreprise_stage_pfe;
    cout<<"Note attribue a la pfe: "<<endl;
    cin>>note_attribue;
}
void pfe::afficher()
{
    cout<<"\n***************************************"<<endl;
    cout<<"Sujet pfe: "<<sujet_pfe<<endl;
    cout<<"Field de sujet de pfe: "<<field<<endl;
    cout<<"Entreprise de stage de pfe: "<<entreprise_stage_pfe<<endl;
    cout<<"Note attribue  a la pfe: "<<note_attribue<<endl;
    cout<<"Les etudiants qui ont travaille  sur cette pfe\n";
    cout<<Etudiants.tab.size()<<endl;
    for(int i = 0; i < (int)Etudiants.tab.size(); i++)
    {
        cout<<i+1<<": "<<Etudiants.tab[i]->getnom()<<" "<<Etudiants.tab[i]->getprenom()<<" son identifiant est: "<<Etudiants.tab[i]->getmatricule_E()<<endl;
    }
}

ostream& operator << (ostream& out,pfe& p)
{
    out<<"\n***************************************"<<endl;
    out<<"Sujet pfe: "<<p.sujet_pfe<<endl;
    out<<"Field de sujet de pfe: "<<p.field<<endl;
    out<<"Entreprise de stage de pfe: "<<p.entreprise_stage_pfe<<endl;
    out<<"Note attribue  a la pfe: "<<p.note_attribue<<endl;
    out<<"Les etudiants qui ont travaille  sur cette pfe\n";
    out<<p.Etudiants.taille()<<endl;
    vector<etudiant*> v = p.Etudiants.gettab();

    for(int i = 0; i < (int)v.size(); i++)
    {
        out<<i+1<<"/\tNom: "<<v[i]->getnom()<<"\tprenom: "<<v[i]->getprenom()<<"\tson identifiant est: "<<v[i]->getmatricule_E()<<endl;
    }
    return out;
}
 istream& operator >> (istream& in,pfe& p)
{
    cout<<"Saisir les donnees de pfe selon l'ordre suivant:\n";
    cout<<"Sujet pfe: "<<endl;
    in>>p.sujet_pfe;
    cout<<"Le field de sujet de pfe: "<<endl;
    in>>p.field;
    cout<<"Entreprise de stage de pfe: "<<endl;
    in>>p.entreprise_stage_pfe;
    cout<<"Note attribue a la pfe: "<<endl;
    in>>p.note_attribue;
    cout<<"Saisir les etudiants qui ont realiser ce sujet de fpe\n";
    in>>p.Etudiants;
    return in;
}


void pfe::saisir(etudiants es, string sujet)
{
    cout<<"Saisir les donnees de pfe selon l'ordre suivant:\n";
    cout<<"Le field de sujet de pfe: "<<endl;
    cin>>field;
    cout<<"Entreprise de stage de pfe: "<<endl;
    cin>>entreprise_stage_pfe;
    cout<<"Note attribue a la pfe: "<<endl;
    cin>>note_attribue;
    this->Etudiants = es;
    this->sujet_pfe = sujet;
}
pfe& pfe::operator = (const pfe& p)
{
    if(this!=&p)
    {
        sujet_pfe = p.sujet_pfe;
        field = p.field;
        entreprise_stage_pfe = p.entreprise_stage_pfe;
        note_attribue = p.note_attribue;
        Etudiants = p.Etudiants;
    }
    return *this;
}
