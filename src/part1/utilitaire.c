/**
 * \file utilitaire.c
 * \brief Fichier des fonctions utilitaires
 * \date Dec 30
 * \author Dudonné Baptiste
*/
#include"utilitaire.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"config.h"
#include"affichage.h"


/*

int frechDicho(VilleIUT **tiut,int taille,VilleIUT ville)
{
    int debut=0;
    int fin=taille-1;
    int milieu;
    while(debut<=fin)
    {
        milieu=(debut+fin)/2;

        if(strcmp(tiut[milieu]->VilleDep,ville.VilleDep)==0)
        {
            return milieu;
        }
        if(strcmp(ville.VilleDep,tiut[milieu]->VilleDep)<0)
        {   
            fin=milieu-1;
        }
        else
        {
            debut=milieu+1;
        }
    }
    printf("%s\n",tiut[debut-1]->VilleDep);
    if (strcmp(tiut[debut-1]->VilleDep,ville.VilleDep)==0)
    {
        return debut-1;
    }
    return -1;
}*/


int modifnbPlist(ListDep ldept,char *Departement,int nbp)
{
    if(ldept==NULL)
    {
        return 0;
        printf("%sErreur Département Introuvable !!\n",STY_FRED);
    }
    if (strcmp(ldept->departement,Departement)==0)
    {   
        if(ldept->nbP==nbp)
        {
            printf("%sLe nombre de places du Département %s est déjà à %d\n",STY_FYELLOW,ldept->departement,nbp);
            return 0;
        }

        ldept->nbP=nbp;
        printf("%sModification effectuée avec succès !!\n",STY_FGREEN);
        return 1;
    }
    return modifnbPlist(ldept->suivant,Departement,nbp);
}


void modifNbpDepartement(VilleIUT **tiut,int taille,VilleIUT ville,char *Departement,int nbp)
{
 
    int i;
    for(i=0;i<taille;i++)
    {
        if(strcmp(tiut[i]->VilleDep,ville.VilleDep)==0)
        {
            if(FrechList(tiut[i]->ldept,Departement)==1)
            {
                modifnbPlist(tiut[i]->ldept,Departement,nbp);
                return; 
            }
            else
            {
                printf("%sErreur Département Introuvable !!\n",STY_FRED);
            }
            return;
        }
    }
    printf("%sErreur Ville Introuvable !!\n",STY_FRED);
}

ListDep insertionMaillonCroissant(ListDep ldept, MaillonDept *maillon)
{
    if(ldept==NULL)
    {
        ldept=maillon;
        return ldept;
    }
    if(strcmp(ldept->departement,maillon->departement)>0)
    {
        maillon->suivant=ldept;
        ldept=maillon;
        return ldept;
    }
    return insertionMaillonCroissant(ldept->suivant,maillon);
}


void InsertionDepartement(VilleIUT **tiut,int taille,char *Ville,char *Departement,int nbp,char *resp)
{
    int i;
    MaillonDept *maillon;
    maillon=(MaillonDept*)malloc(sizeof(MaillonDept));
    if(maillon==NULL)
    {
        printf("Error Dynamic Allocation !!\n");
        exit(2);
    }
    strcpy(maillon->departement,Departement);
    strcpy(maillon->resp,resp);
    maillon->nbP=nbp;
    for(i=0;i<taille;i++)
    {
        if(strcmp(tiut[i]->VilleDep,Ville)==0)
        {
            if(FrechList(tiut[i]->ldept,Departement)==1)
            {
                printf("%sErreur Département Existant !!\n",STY_FRED);
                return;
            }
            else
            {
                tiut[i]->ldept=insertionMaillonCroissant(tiut[i]->ldept,maillon);
                //afficherDepartementsRecursif(tiut[i]->ldept);
                tiut[i]->nbDept++;
                printf("%sInsertion effectuée avec succès !!\n",STY_FGREEN);
                return;
                
            }
        }
    }
    printf("%sErreur Ville Introuvable !!\n",STY_FRED);
    return;
}

ListDep suppressionMaillonDept(ListDep ldept,char *Departement)
{
    if(ldept==NULL)
    {
        return NULL;
    }
    if(strcmp(ldept->departement,Departement)==0)
    {
        ListDep temp=ldept;
        ldept=ldept->suivant;
        free(temp);
        return ldept;
    }
    return suppressionMaillonDept(ldept->suivant,Departement);
}


int fSuppressionDept(VilleIUT **tiut,int taille,char *ville,char *Departement)
{
    int i;
    for(i=0;i<taille;i++)
    {
        if(strcmp(tiut[i]->VilleDep,ville)==0)
        {
            if(FrechList(tiut[i]->ldept,Departement)==1)
            {
                tiut[i]->ldept=suppressionMaillonDept(tiut[i]->ldept,Departement);
                tiut[i]->nbDept--;
                printf("%sSuppression effectuée avec succès !!\n",STY_FGREEN);
                return 1;
            }
            else
            {
                printf("%sErreur Département Introuvable !!\n",STY_FRED);
                return 0;
            }
        }
    }
    printf("%sErreur Ville Introuvable !!\n",STY_FRED);
    return 0;
}


int FrechnbP(VilleIUT **tiut,int taille,char *Ville,char *Departement)
{
    int i;
    for(i=0;i<taille;i++)
    {
        if(strcmp(tiut[i]->VilleDep,Ville)==0)
        {
            if(FrechList(tiut[i]->ldept,Departement)==1)
            {
                fAffichNbp(tiut[i]->ldept,Departement);
                return 1;
            }
            else
            {
                printf("%sErreur Département Introuvable !!\n",STY_FRED);
                return 0;
            }
        }
    }
    printf("%sErreur Ville Introuvable !!\n",STY_FRED);
    return 0;
}

int fModifRespDept(ListDep ldept,char *Departement,char *resp)
{
    if(ldept==NULL)
    {
        return 0;
        
    }
    if(strcmp(ldept->departement,Departement)==0)
    {   
        if(strcmp(ldept->resp,resp)==0)
        {
            printf("%sNote Responsable Existant !!\n",STY_FYELLOW);
            return 0;
        }
        strcpy(ldept->resp,resp);
        printf("%sModification effectuée avec succès !!\n",STY_FGREEN);
        return 1;
    }
    return fModifRespDept(ldept->suivant,Departement,resp);
}


int FmodifResp(VilleIUT **tiut,int taille,char *Departement,char *Responsable)
{
    int i;
    for(i=0;i<taille;i++)
    {
        if(FrechList(tiut[i]->ldept,Departement)==1)
        {
            fModifRespDept(tiut[i]->ldept,Departement,Responsable);
            return 1;
        }
    }
    printf("%sErreur Département Introuvable !!\n",STY_FRED);
    return -1;
}

int FrechList(ListDep ldept,char *Departement)
{   
    if(ldept==NULL)
    {
        return 0;
    }
    if (strcmp(ldept->departement,Departement)==0)
    {
        return 1;
    }
    return FrechList(ldept->suivant,Departement);
}
