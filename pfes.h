#ifndef PFES_H_INCLUDED
#define PFES_H_INCLUDED
#include "pfe.h"
class pfes
{
    vector<pfe> tab_pfe;
public:
    
    pfes(){};
    pfes(const pfes&);
    ~pfes();
    
/**get**/
    vector<pfe> gettab_pfe(){return tab_pfe;}

    

    void remplir(etudiants); //Remplir les pfe des etudiants presant dans la base de donne
    void remplir();
    void afficher();
    int taille();

    void ajouter(pfe,int = 0);
    void supprimer(int = 0);

};


#endif // PFES_H_INCLUDED
