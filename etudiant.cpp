#include "etudiant.h"

etudiant::etudiant(string nom,string prenom,string mail,string CIN,string matricule_E,float moyenne,bool travaille)
{
    this->nom = nom;
    this->prenom = prenom;
    this->mail=mail;
    this->CIN = CIN;
    this->matricule_E = matricule_E;
    this->moyenne = moyenne;
    this->travaille = travaille;

    cout<<"Saisir la date de naissance de letudiant\n";
    date_de_naissance.saisir();

    cout<<"Saisir la date de debut d'etude:\n";
    date_debut.saisir();

    cout<<"Saisir la date de fin d'etude:\n";
    date_fin.saisir();
}

void etudiant::afficher()
{
    cout<<"Nom: "<<nom<<endl;
    cout<<"Prenom: "<<prenom<<endl;
    cout<<"Mail: "<<mail<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"Matricule de l'etudiant: "<<matricule_E<<endl;
    cout<<"La moyenne de l'etudiant durant ces 3 annees: \n"<<moyenne<<endl;
    if(travaille)
        cout<<"L'etudiant travaille \n";
    else cout<<"l'etudiant ne travaille pas encore \n";
    cout<<"La date de naissance de letudiant est:\n";
    date_de_naissance.afficher();
    cout<<"La date de debut d'etude: \n";
    date_debut.afficher();
    cout<<"La date de fin d'etude: \n";
    date_fin.afficher();
}
void etudiant::saisir()
{
    cout<<"Saisir les donees de letudiant selon l'ordre suivant: \n";
    cout<<"Nom: ";cin>>nom;
    cout<<"Prenom: ";cin>>prenom;
    cout<<"Mail: ";cin>>mail;
    cout<<"CIN: ";cin>>CIN;
    cout<<"Matricule: ";cin>>matricule_E;
    cout<<"Moyanne: ";cin>>moyenne;

    cout<<"Saisir la date de naissance de letudiant\n";
    date_de_naissance.saisir();

    cout<<"Saisir la date de debut d'etude:\n";
    date_debut.saisir();

    cout<<"Saisir la date de fin d'etude:\n";
    date_fin.saisir();
}
