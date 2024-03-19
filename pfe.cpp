#include "pfe.h"
pfe::pfe(string sujet_pfe, string entreprise_stage_pfe, float note_attribue)
{
    this->sujet_pfe = sujet_pfe;
    this->entreprise_stage_pfe = entreprise_stage_pfe;
    this->note_attribue = note_attribue;
}

pfe::pfe(const pfe& p)
{
    sujet_pfe = p.sujet_pfe;
    entreprise_stage_pfe = p.entreprise_stage_pfe;
    note_attribue  = p.note_attribue;
    Etudiants = p.Etudiants;
}

pfe::~pfe()
{
    //Destructeur vide
}

void pfe::saisir()
{
    cout<<"Saisir les donnees de pfe selon l'ordre suivant:\n";
    cout<<"Sujet pfe: "<<endl;
    getline(cin,sujet_pfe);
    cout<<"Entreprise de stage de pfe: "<<endl;
    getline(cin,entreprise_stage_pfe);

    cout<<"Note attribue a la pfe: "<<endl;
    cin>>note_attribue;
    cout<<"Saisir les Etudiants qui ont travaille sur cette PFE: ";
    Etudiants.remplir();
}

void pfe::afficher()
{
    cout<<"\n***************************************"<<endl;
    cout<<"Sujet pfe: "<<sujet_pfe<<endl;
    cout<<"Entreprise de stage de pfe: "<<entreprise_stage_pfe<<endl;
    cout<<"Note attribue  a la pfe: "<<note_attribue<<endl;
    cout<<"Les etudiants qui ont travaille  sur cette pfe\n";
    for(int i = 0; i < (int)Etudiants.tab.size(); i++)
    {
        cout<<i+1<<": "<<Etudiants.tab[i]->getnom()<<" "<<Etudiants.tab[i]->getprenom()<<" son identifiant est: "<<Etudiants.tab[i]->getmatricule_E()<<endl;
    }
}
