#ifndef PFE_H_INCLUDED
#define PFE_H_INCLUDED
#include "etudiants.h"
#pragma once
class pfe
{

    string sujet_pfe;
    string entreprise_stage_pfe;
    float note_attribue;
    etudiants Etudiants;
public:
    /**Const(s) & Dest**/
    pfe(string="",string="",float=0);
    ~pfe();
    pfe(const pfe&);

    /**Getteur(s) & setteur(s)**/
    string getsujet_pfe(){return sujet_pfe;}
    string getentreprise_stage_pfe(){return entreprise_stage_pfe;}
    float getnote_attribue(){return note_attribue;}
    etudiants getetudiants(){return Etudiants;}

    void setsuhet_pfe(string sujet_pfe){this->sujet_pfe = sujet_pfe;}
    void setentreprise_stage_pfe(string entreprise_stage_pfe){this->entreprise_stage_pfe = entreprise_stage_pfe;}
    void setnote_attribue(float note_attribue){this->note_attribue = note_attribue;}
    

    /**Afficher & saisir**/
    void afficher();
    void saisir();

};


#endif // PFE_H_INCLUDED
