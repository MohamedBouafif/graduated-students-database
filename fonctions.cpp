#include<fstream>
void afficherMenu_promomast() {
    int choix,i;
    promotion_master p ;
     etudiant_master e ;
     string donne;

    do {
        cout << "\n=== Menu de la promotion ing  ===\n";
        cout << "1. Saisie\n";
        cout << "2. Afficher aleatoirement \n";
        cout << "3. Afficher triee \n";
        cout << "4. Ajouter etudiant a une promotion \n";
        cout << "5. Chercher l'étudiant majeur dans une promotion\n";
        cout << "6. Chercher un etudiant dans une promotion\n";
        cout << "0. Quitter\n";
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
               cin >> p ;
                break;
            case 2:
                cout << p ;
                break;
            case 3:
               p.afficher_promo_mast_triee();
                break;
            case 4:

              cin >> e ;
              p.ajouter_etudiant_master(e);
              cout <<"etudiant ajoute avec succe"<<endl ;
                break;
            case 5:
               p.majeur_promo_mast();
                break;
            case 6:

              cout << "donner le matricule ou le numero de cin de l'etudiant"<< endl ;
               cin >> donne;
               i=p.chercher_etudiant(donne);
               if (i==-1)
                    cout <<"pas d'etudiant avec ce matricule ou ce numero de cin"<<endl;
               else
               {
                   e=p.get_etudiant(i);
                   cout <<e;
               }

                break;
            case 0:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix != 0);
}

void afficherMenu_promoing() {
    int choix,i;
    promotion_ing p ;
     etudiant_ing e ;
     string donne;

    do {
        cout << "\n=== Menu de la promotion ing  ===\n";
        cout << "1. Saisie\n";
        cout << "2. Afficher aleatoirement \n";
        cout << "3. Afficher triee \n";
        cout << "4. Ajouter etudiant a une promotion \n";
        cout << "5. Chercher l'étudiant majeur dans une promotion\n";
        cout << "6. Chercher un etudiant dans une promotion\n";
        cout << "0. Quitter\n";
        cout << "Choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
               cin >> p ;
                break;
            case 2:
                cout << p ;
                break;
            case 3:
               p.afficher_promo_ing_triee();
                break;
            case 4:

              cin >> e ;
              p.ajouter_etudiant_ing(e);
              cout <<"etudiant ajoute avec succe"<<endl ;
                break;
            case 5:
               p.majeur_promo_ing();
                break;
            case 6:

              cout << "donner le matricule ou le numero de cin de l'etudiant"<< endl ;
               cin >> donne;
               i=p.chercher_etudiant(donne);
               if (i==-1)
                    cout <<"pas d'etudiant avec ce matricule ou ce numero de cin"<<endl;
               else
               {
                   e=p.get_etudiant(i);
                   cout <<e;
               }

                break;
            case 0:
                cout << "Au revoir !\n";
                break;
            default:
                cout << "Choix invalide. Veuillez réessayer.\n";
        }
    } while (choix != 0);
}
void afficherSousMenuPromotion() {

    int choix;

    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Promotion :\n";
        cout << "1 - Promotion Ingenieur\n";
        cout << "2 - Promotion Master\n";
        cout << "3 - Promotion Rassemblant Ingenieurs et Masters\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                afficherMenu_promoing();
                break;
            case 2:
                afficherMenu_promomast();
                break;
            case 3:
                cout <<"promoo"<<endl ;
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 3.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}
 afficherSousMenuEtudiant()
 {int choix;

    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Etudiant :\n";
        cout << "1 - Etudiant Master\n";
        cout << "2 - Etudiant Ingénieur\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                //
                break;
            case 2:
               //
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 2.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}


void recuperer_fichier(string txt)
  {
      ifstream fichier (txt,ios::app);
       if (!fichier)
        cout << "erreur"<<endl ;
    cout <<"***********affichage de contenu de fichier*************"<<endl ;
    char ch ;
    while (fichier.get(ch))
        cout <<ch;

    fichier.close();
  }
void vider_fichier (string txt)
{
   ofstream fichier(txt,ofstream::out |ofstream::trunc )      ;
   fichier.close();
   cout<<"contenu de fichier supprimer avec succee"<<endl ;
}
