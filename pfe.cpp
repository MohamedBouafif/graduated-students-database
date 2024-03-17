#include "pfe.h"
pfe::pfe()
{
    sujet_pfe="";
    entreprise_de_stage="";
    note_atribuee=0.0;


}
pfe::pfe(string sujet_pfe ,string entreprise_de_stage ,float note_atribuee)
{
 this->sujet_pfe=sujet_pfe;
 this->entreprise_de_stage=entreprise_de_stage;
 this->note_atribuee=note_atribuee;

}
void pfe::ajouter_etudiant()
{   int n ;
    cout <<"entrer le nombre des etudiants responslabes de pfe"<<endl;
    cin >>n ;
    while (n>2)
        {cout <<"le nombre d'etudiants doit etre egal 1 ou 2 "<<endl ;
        cout << "veuillez reentrer le nombre d'etudiants "<<endl ;
        cin >> n ; }
    for (int i=0 ; i<n ;i++)
        {
             etudiant e ;
             e.saisir();
             resp.push_back(e);

        }

    }
void pfe::saisir_pfe()
{
    cout <<"entrer le sujet de pfe" << endl;
    cin>>sujet_pfe;
    cout <<"entrer l'entreprise du stage de pfe " <<endl ;
    cin>> entreprise_de_stage;
    cout<<"entrer la note atribuee au pfe " <<endl ;
    cin >> note_atribuee ;
    ajouter_etudiant();
}
void pfe::afficher_pfe()
{
    cout<<"************affichage pfe****************"<<endl ;
    cout << "le sujet de pfe est: "<<sujet_pfe<<endl ;
    cout <<"l'entreprise de stage est: "<<entreprise_de_stage<<endl;
    cout <<"la note attribuee est: "<<note_atribuee<<endl ;
    for (int i=0 ; i<resp.size(); i++)
    {
        resp[i].afficher();
    }
}

