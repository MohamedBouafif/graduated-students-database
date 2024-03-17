#ifndef PFE_H_INCLUDED
#define PFE_H_INCLUDED
#include "etudiant.cpp"
#include<vector>
class pfe
{
    string sujet_pfe ;
    string entreprise_de_stage ;
    float note_atribuee ;
    vector <etudiant> resp;
public :
    pfe() ;
    pfe (string , string , float );


    string get_sujet_pfe(){return sujet_pfe;};
    string get_entreprisedestage(){return entreprise_de_stage;};
    float get_note_attribuee(){return note_atribuee;};

    void set_sujet__pfe(string sujet_pfe){this->sujet_pfe=sujet_pfe;};
    void set_entreprise_de_stage(string entreprise_de_stage){this ->entreprise_de_stage=entreprise_de_stage;};
    void set_note_attribuee(float note_atribuee){this->note_atribuee=note_atribuee;};

    void ajouter_etudiant() ;
    void saisir_pfe();
    void afficher_pfe();





};

#endif // PFE_H_INCLUDED
