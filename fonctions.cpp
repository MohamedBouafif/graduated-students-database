#include<fstream>
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











void afficherPromotion() {
    int choix;
    promotion p ;


    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Promotion :\n";
        cout << "1 - Saisir les informations de la promotion\n";
        cout << "2 - Afficher les informations de la promotion\n";
        cout << "3 - Afficher les statistiques de la promotion\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
              cin>>p ;
                break;
            case 2:
                cout<<p;
                break;
            case 3:
              {float  b= p.pourcentage();
              cout <<b<<endl ;
              break;}
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 3.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}


void afficherMenu_promomast() {
    int choix,i;
    promotion_master p ;
     etudiant_master e ;
     string donne;

    do {
        cout << "\n=== Menu du promotion master  ===\n";
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


void affichermenuetudiants()
{
    etudiants e;
     int choix;

    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Etudiant :\n";
        cout << "1 - Remplir les informations des etudiants\n";
        cout << "2 - Afficher les informations des etudiants\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
               cin >> e;
                break;
            case 2:
                cout <<e;
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 2.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}


void afficherSousMenuPromotion(){


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
             afficherPromotion();
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 3.\n";
        }}

     while(choix != 0);







}
 void afficherSousMenuEtudiantIng() {
    int choix;
    etudiant_ing e;
    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Etudiant Ingenieur :\n";
        cout << "1 - saisie etudiant: \n";
        cout << "2 - afficher l'etudiant: \n";
        cout << "3 - Calculer la moyenne generale\n";
        cout << "4 - Enregistrer les informations\n";
        cout << "5 - Recuperer les informations des etudiants dans le fichier\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                cin>> e;
                break;
            case 2:
                cout << e;
                break;
            case 3:
              {float b= e.calcul_moyenne_general();
               cout <<"la moyenne general de cet etudiant est: "<<b <<endl  ;
                break;}
            case 4:
                e.enregistrer();
                break;
            case 5:
                 recuperer_fichier("C:etudiants ingenieurs.txt");
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}
void afficherSousMenuEtudiantmast() {
    int choix;
    etudiant_master e;
    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Etudiant Ingenieur :\n";
        cout << "1 - saisie etudiant: \n";
        cout << "2 - afficher l'etudiant: \n";
        cout << "3 - verifier si l'etudiant a redouble \n";
        cout << "4 - verifier si l'etudiant a travaille dans une societe\n";
        cout << "5 - Enregistrer les informations\n";
        cout << "6 - Recuperer les informations des etudiants dans le fichier\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                cin>> e;
                break;
            case 2:
                cout << e;
                break;
            case 3:
              e.redouble();
              break;
            case 4:
              {string s ;
               cout<< "entrer le nom de societe: ";
               cin >> s;
               e.chercher_Societe(s);
               }
               break ;
            case 5:
                 e.enregistrer();
                break;
            case 6:
                recuperer_fichier("C:etudiants master.txt");
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}
 void afficherSousMenuEtudiant(){
 int choix;

    do {
        // Affichage du sous-menu
        cout << "Sous-Menu Etudiant :\n";
        cout << "1 - Etudiant Master\n";
        cout << "2 - Etudiant Ingenieur\n";
        cout << "3 - etudiant\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                 afficherSousMenuEtudiantmast();
                break;
            case 2:
               afficherSousMenuEtudiantIng();
                break;
            case 3:
                affichermenuetudiants();
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 2.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}

void afficherSousMenuPFE() {
    int choix;
    pfes p ;

    do {
        // Affichage du sous-menu
        cout << "Sous-Menu PFE :\n";
        cout << "1 - Saisir les informations du PFE\n";
        cout << "2 - Afficher les informations du PFE\n";
        cout << "3 - Enregistrer les informations du PFE\n";
        cout << "4 - Récupérer les informations du PFE\n";
        cout << "0 - Retour au menu principal\n";
        cout << "Entrez votre choix : ";

        // Lecture du choix de l'utilisateur
        cin >> choix;

        // Appel de la fonction correspondante selon le choix de l'utilisateur
        switch(choix) {
            case 1:
                cin >> p;
                break;
            case 2:
                cout<< p;
                break;
            case 3:
                p.enregistrer();
                break;
            case 4:
                recuperer_fichier("c:pfes.txt");
                break;
            case 0:
                cout << "Retour au menu principal.\n";
                break;
            default:
                cout << "Choix invalide. Veuillez entrer un nombre entre 0 et 4.\n";
        }

    } while(choix != 0); // Répéter le sous-menu tant que l'utilisateur ne choisit pas de retourner au menu principal
}

