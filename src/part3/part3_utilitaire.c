/**
 * @file part3_utilitaire.c
 * @author dudonné Baptiste
 * @brief 
 * @version 0.1
 * @date 2023-01-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"utilitaire.h"
#include"struct.h"


int FrechChoix(Choix choix[],int nbchoix,char *ville,char *dept)
{   
    for (int i=0;i<nbchoix;i++)
    {
        if(strcmp(choix[i].ville.VilleDep,ville)==0 && strcmp(choix[i].departement,dept)==0)
        {
            return 1;
        }
    }
    return 0;
    
}

MaillonCandidat* copieMaillon(Candidature cand)
{   
    int i;
    MaillonCandidat *Maillon;
    Maillon=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
    if(Maillon==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    Maillon->candidat.idCandidat=cand.idCandidat;
    strcpy(Maillon->candidat.nomCandidat,cand.nomCandidat);
    strcpy(Maillon->candidat.prenomCandidat,cand.prenomCandidat);
    Maillon->candidat.moyenneCandidat.maths=cand.moyenneCandidat.maths;
    Maillon->candidat.moyenneCandidat.fran=cand.moyenneCandidat.fran;
    Maillon->candidat.moyenneCandidat.angl=cand.moyenneCandidat.angl;
    Maillon->candidat.moyenneCandidat.spe=cand.moyenneCandidat.spe;
    Maillon->candidat.nbChoix=cand.nbChoix;
    Maillon->candidat.choix[MAX_CHOIX];
    for(i=0;i<cand.nbChoix;i++)
    {   
        Maillon->candidat.choix[i]=cand.choix[i];
        //Maillon->candidat.choix[i].ville=cand->choix[i].ville;
        //strcpy(Maillon->candidat.choix[i].departement,cand->choix[i].departement);
        //Maillon->candidat.choix[i].decision=cand->choix[i].decision;
        //Maillon->candidat.choix[i].validation=cand->choix[i].validation;
    }
    return Maillon;
}

float FcalculMoyenne(Candidature cand)
{   
    float moyenne;
    moyenne=(cand.moyenneCandidat.maths+cand.moyenneCandidat.fran+cand.moyenneCandidat.angl+cand.moyenneCandidat.spe)/4;
    return moyenne;
}


ListAdmis FonctionInsertionCroissante(ListAdmis list,Candidature cand)
{   
    MaillonCandidat *Maillon;
    Maillon=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
    if(Maillon==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    Maillon=copieMaillon(cand);

    if(list==NULL)
    {
        return Maillon;
    }
    else
    {
        if(FcalculMoyenne(cand)>FcalculMoyenne(list->candidat))
        {
            MaillonCandidat *tmp;
            tmp=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
            if (tmp==NULL)
            {
                fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
                exit(2);
            }
            tmp=list;
            list=Maillon;
            list->suivant=tmp;
            return list;
        }
        if(FcalculMoyenne(cand)==FcalculMoyenne(list->candidat))
            {
                if(cand.moyenneCandidat.spe>list->candidat.moyenneCandidat.spe)
                {
                    MaillonCandidat *tmp;
                    tmp=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
                    if (tmp==NULL)
                    {
                        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
                        exit(2);
                    }
                    tmp=list;
                    list=Maillon;
                    list->suivant=tmp;
                    return list;
                }
                {
                    MaillonCandidat *tmp;
                    tmp=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
                    if (tmp==NULL)
                    {
                        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
                        exit(2);
                    }
                    tmp=list;
                    list=Maillon;
                    list->suivant=tmp;
                    return list;
                }
            
            }

        return list->suivant=FonctionInsertionCroissante(list->suivant,cand);
    }
}



int AlgorithmeParcoursup(Candidature **tcand,int tlog,VilleIUT ville)
{   
    int i=0;
    ListAdmis list;
    list=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
    if(list==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    if(strcmp(ville.VilleDep,VILLECANDID)==0)
    {
        if(FrechList(ville.ldept,DEPTCANDID)==0)
        {
          for (i=0;i<tlog;i++)
          {
            if (FrechChoix(tcand[i]->choix,tcand[i]->nbChoix,VILLECANDID,DEPTCANDID)==1)
                {
                    list=FonctionInsertionCroissante(list,*tcand[i]);
                }
          }
        }
        else
        {
            fprintf(stderr,"%sErreur La ville spécifiée en paramètre ne contient pas le département !%s\n",STY_FRED,STY_NULL);
            return -1;
        }
    }
    fprintf(stderr,"%sErreur La ville spécifiée en paramètre n'est pas la bonne !%s\n",STY_FRED,STY_NULL);
    return -1;
}