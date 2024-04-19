#ifndef ENTREPRISE_H_INCLUDED
#define ENTREPRISE_H_INCLUDED


#include <map>
#include <set>
#include <bits/stdc++.h>
#pragma once
class entreprises
{

// Le remplissage des ces attribut ce fait automatiquement lors de creation de chaque etudiant (puisque il a fait au moin un pfe ou il a travaillé)

    set<string> nom_entreprises;
    map<etudiant*, vector < pair < string,string>>> poste_etd;  //vector contient la poste de chaque etudiant et lentreprise associee a cette poste
    map<etudiant*, pair<string,string>> stage;              //pair contient sujet stage et lentreprise correspondante a ce stage

public:

    /**Const(s) & Des**/
    entreprises();
    entreprises(const entreprises&);
    ~entreprises();

    /** setters & getters**/

    void setnom_entreprise(set<string>);
    void setposte_etd(map<etudiant*,vector<pair<string,string>>>);
    void setstage(map<etudiant*,pair<string,string>>);

    set<string> getnom_entreprises(){return nom_entreprises;}

    map<etudiant*,vector<pair<string,string>>> getpost_etd(){return poste_etd;}

    map<etudiant*,pair<string,string>>getstage(){return stage;}

/**afficher(s)**/

    void afficher_par_etudiant();

/**Remplir**/

    void remplirnom_entreprises(etudiants);
    void remplirposte_etd(etudiants);
    void remplirstage(pfes);

    void remplir(etudiants etds,pfes p){remplirnom_entreprises(etds);remplirposte_etd(etds);remplirstage(p);}


/**Surcharge des operator**/
    friend ostream& operator<<(ostream&, entreprises&);
    friend istream& operator>>(istream&, entreprises&);    // les objet de ce classe ne peuvent exister que lorsque un objet etudiant et pfes existe.
    entreprises& operator = (const entreprises& e);

};

#endif // ENTREPRISE_H_INCLUDED
