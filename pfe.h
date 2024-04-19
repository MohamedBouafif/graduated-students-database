#ifndef PFE_H_INCLUDED
#define PFE_H_INCLUDED
#include "etudiants.h"
#pragma once
class pfe
{

    friend class entreprises;
    friend class etudiants;

    string sujet_pfe;                       //Le titre de rapport de pfe
    string field;                           // Exemple : developpement, IA , machine learning etc....
    string entreprise_stage_pfe;
    float note_attribue;
    etudiants Etudiants;                    // un sujet peut etre traité par plusieurs eleves

public:
    /**Const(s) & Dest**/
    pfe(etudiants,string="",string="",string="",float=0);/**les sujet de pfe seront remplis a partir
                                                                    de la liste detudiants qui est deja
                                                                    disponible dans la base de donne**/

    pfe(string="",string ="",string="",float=0);
    ~pfe();





/**Getteur(s) & setteur(s)**/
    string getsujet_pfe(){return sujet_pfe;}
    string getentreprise_stage_pfe(){return entreprise_stage_pfe;}
    string getfield(){return field;}
    float getnote_attribue(){return note_attribue;}
    etudiants getetudiants(){return Etudiants;}


    void setsuhet_pfe(string sujet_pfe){this->sujet_pfe = sujet_pfe;}
    void setentreprise_stage_pfe(string entreprise_stage_pfe){this->entreprise_stage_pfe = entreprise_stage_pfe;}
    void setnote_attribue(float note_attribue){this->note_attribue = note_attribue;}
    void set_field(string field){this->field = field;}


/**Afficher & saisir**/
    void afficher();
    void saisir();
    void saisir(etudiants);   //A etuliser si jai saisi un pfe dont les etudiants sont deja saisit!
    void saisir(etudiants, string );
/**Surcharge des operateurs**/
    friend ostream& operator << (ostream&,pfe&);
    friend istream& operator >> (istream&,pfe&);
    pfe& operator = (const pfe&);


};


#endif // PFE_H_INCLUDED
