//// fichier affichage.c 
/**
 * \file affichage.c
 * \brief Fichier des fonctions d'affichages
 * \date Dec 30
 * \author Dudonné Baptiste
*/

#include"affichage.h"
#include<stdio.h>
#include"config.h"
#include"string.h"

void affichemaillon(MaillonDept *maillon)
{
    printf("Département : %s\n",maillon->departement);
    printf("Nb de places : %d\n",maillon->nbP);
    printf("Nom Responsable : %s\n",maillon->resp);
}


void afficherDepartementsRecursif(ListDep ldept)
{
    if (ldept == NULL)
    {
        return;
    }
    printf("Département : %s \n\n", ldept->departement);
    printf("Nombre de places : %d \n", ldept->nbP);
    printf("Responsable : %s \n", ldept->resp);
    printf("\n");
    afficherDepartementsRecursif(ldept->suivant);
}


void afficheVille(VilleIUT **tiut,int nbVille)
{
    int i;
    for(i=0;i<nbVille;i++)
    {
        printf("--------------------------------------------\n");
        printf("Ville : %s\n\n",tiut[i]->VilleDep);
        printf("Nombre de Départements : %d\n",tiut[i]->nbDept);
        afficherDepartementsRecursif(tiut[i]->ldept);  
    }
    printf("--------------------------------------------\n"); 
}

int  fAffichNbp(ListDep list, char *Departement)
{
    if(list==NULL)
    {
        return 0;
    }
    if(strcmp(list->departement,Departement)==0)
    {
        printf("Département : %s\nNombre de places : %d\n",list->departement,list->nbP);
        return 1;
    }
    return fAffichNbp(list->suivant,Departement);
}




void fAffichMenu(void)
{
    printf("\n");
    printf("%s  INFORMATIONS IUT DE FRANCE  %s\n",STY_FBLUE,STY_NULL);
    for(int i=0;i<30;i++)printf("%s",BOX_HORI);
    printf("\n\n");
    printf("%s",BOX_TOPL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_TOPR);
    printf("\n%s    %s     Connexion          %s%s\n",BOX_VERT,STY_FMAGEN,STY_NULL,BOX_VERT);
    printf("%s",BOX_BOTL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_BOTR);


    printf("\n\n");

    printf("%s      1. Administrateur\n",STY_FYELLOW);
    printf("\n");
    printf("%s      2. Etudiant\n",STY_FGREEN);
    printf("\n");
    printf("%s      3. Quitter\n\n",STY_FGREEN);
    printf("%s    Entrez Votre Choix : ",STY_FBLUE);
    
}


void fAffichAdmin(void)
{
    printf("\n");
    printf("%s    GESTION IUT DE FRANCE  %s\n",STY_FBLUE,STY_NULL);
    for(int i=0;i<30;i++)printf("%s",BOX_HORI);
    printf("\n\n");
    printf("%s",BOX_TOPL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_TOPR);
    printf("\n%s    %s Mode Administrateur    %s%s\n",BOX_VERT,STY_FMAGEN,STY_NULL,BOX_VERT);
    printf("%s",BOX_BOTL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_BOTR);


    printf("\n\n");

    printf("%s  1. Modifier Le Nombre de places d'un département\n",STY_FGREEN);
    printf("\n");
    printf("%s  2. Ajouter Un Département Dans un IUT\n",STY_FYELLOW);
    printf("\n");
    printf("%s  3. Suppression d'un département\n",STY_FGREEN);
    printf("\n");
    printf("%s  4. Modification de responsable de département\n",STY_FYELLOW);
    printf("\n");
    printf("%s  5. Lancer la procédure d'admission\n",STY_FGREEN);
    printf("\n");
    printf("%s  6. Sauvegarder et quitter\n",STY_FYELLOW);
    printf("\n");

    printf("%s     Entrez Votre Choix : ",STY_FBLUE);

}


void AffichEtu(void)
{
    printf("\n");
    printf("%s    GESTION IUT DE FRANCE  %s\n",STY_FBLUE,STY_NULL);
    for(int i=0;i<30;i++)printf("%s",BOX_HORI);
    printf("\n\n");
    printf("%s",BOX_TOPL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_TOPR);
    printf("\n%s    %s    Mode Etudiant       %s%s\n",BOX_VERT,STY_FMAGEN,STY_NULL,BOX_VERT);
    printf("%s",BOX_BOTL);
    for(int i=0;i<28;i++)printf("%s",BOX_HORI);
    printf("%s",BOX_BOTR);
    printf("\n");

    printf("\n\n");

    printf("%s  1. Afficher La Liste Des IUT\n",STY_FGREEN);
    printf("\n");
    printf("%s  2. Afficher Les Departements de chaque IUT\n",STY_FYELLOW);
    printf("\n");
    printf("%s  3. Afficher le nombre de places en premiere annee\n",STY_FGREEN);
    printf("\n");
    printf("%s  4. Rechercher un departement parmi tous les IUT\n",STY_FYELLOW);
    printf("\n");
    printf("%s  5. Quitter\n",STY_FYELLOW);
    printf("\n");

    printf("%s     Entrez Votre Choix : ",STY_FBLUE);
}


void FaffichListIUT(VilleIUT **tiut,int taille)
{
    int i;
    //printf("taille : %d\n",taille);
    printf("Liste des IUT :\n");
    for (i=0;i<taille;i++)
    {
        printf("%s%s\n",STY_NULL,tiut[i]->VilleDep);
    }
    
}


void fAffichListDept(VilleIUT **tiut,int taille)
{
    int i;
    printf("Liste des départements :\n");
    for (i=0;i<taille;i++)
    {   
        printf("Ville : %s\n",tiut[i]->VilleDep);
        printf("Départements :\n");
        afficherDepartementsRecursif(tiut[i]->ldept);
    }
}

void affichePlace(VilleIUT **tiut,int taille)
{
    int i;
    printf("\n");
    printf("Liste des départements :\n");
    for (i=0;i<taille;i++)
    {   
        printf("Ville : %s\n",tiut[i]->VilleDep);
        printf("Départements :\n");
        afficherDepartementsRecursif(tiut[i]->ldept);
    }
}