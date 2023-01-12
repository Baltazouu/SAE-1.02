/**
 * @file part3.c
 * @author Dudonné Baptiste
 * @brief Gestion des admissions 
 * @version 0.1
 * @date 2023-01-05
 */

#include<stdio.h>
#include<stdlib.h>
#include"config.h"
#include"struct.h"
#include"string.h"
#include"part3_utilitaire.h"
#include"utilitaire.h"


void ecrireMaillonAdmis(FILE *fe,ListAdmis list)
{
    if(list==NULL)
    {
        return;
    }
    fprintf(fe,"%d %s %s %f %f %f %f %d ",list->candidat.idCandidat,list->candidat.nomCandidat,list->candidat.prenomCandidat,list->candidat.moyenneCandidat.maths,list->candidat.moyenneCandidat.fran,list->candidat.moyenneCandidat.angl,list->candidat.moyenneCandidat.spe,list->candidat.nbChoix);
    ecrireMaillonAdmis(fe,list->suivant);
}

void FsauvegardeLadmis(char *nomFich,ListAdmis list)
{
    FILE *fe;
    fe=fopen(nomFich,"w");
    if(fe==NULL)
    {
        fprintf(stderr,"%sError Open File !!\n",STY_FRED);
        exit(2);
    }
    ecrireMaillonAdmis(fe,list);
    fclose(fe);
}

void ecrireMaillonLatt(FILE *fe,ListAttente list)
{
    if (list==NULL)
    {
        return;
    }
    fprintf(fe,"%d %s %s %f %f %f %f %d ",list->candidat.idCandidat,list->candidat.nomCandidat,list->candidat.prenomCandidat,list->candidat.moyenneCandidat.maths,list->candidat.moyenneCandidat.fran,list->candidat.moyenneCandidat.angl,list->candidat.moyenneCandidat.spe,list->candidat.nbChoix);
    ecrireMaillonLatt(fe,list->suivant);
    fclose(fe);
}

void FsauvegardeLatt(char *nomFich,ListAttente list)
{
    FILE *fe;
    fe=fopen(nomFich,"w");
    if(fe==NULL)
    {
        fprintf(stderr,"%sError Open File !!\n",STY_FRED);
        exit(2);
    }
    ecrireMaillonLatt(fe,list);
}



int AlgorithmeParcoursup(Candidature **tcand,int tlog,VilleIUT ville)
{   
    int noteAttente;
    printf("Entrez la note pallier pour la mise en attente :");
    scanf("%d",&noteAttente);

    int i=0;
    ListAdmis listAdmis;
    ListAttente listAttente;
    

    listAdmis=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));

    if(listAdmis==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    listAttente=(MaillonCandidatatt*)malloc(sizeof(MaillonCandidatatt));
    if(listAttente==NULL)
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
                    listAdmis=FonctionInsertionCroissante(listAdmis,*tcand[i],listAttente,noteAttente);
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


    FsauvegardeLadmis("ListeAdmis.don",listAdmis);
    FsauvegardeLatt("ListeAttente.don",listAttente);
}