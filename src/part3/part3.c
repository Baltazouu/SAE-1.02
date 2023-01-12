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


void ecrireMaillonCandid(FILE *fe,ListCandidat list)
{
    if(list==NULL)
    {
        return;
    }
    fprintf(fe,"%d %s %s %f %f %f %f %ld\n",list->candidat.idCandidat,list->candidat.nomCandidat,list->candidat.prenomCandidat,list->candidat.moyenneCandidat.maths,list->candidat.moyenneCandidat.fran,list->candidat.moyenneCandidat.angl,list->candidat.moyenneCandidat.spe,list->candidat.nbChoix);
    ecrireMaillonCandid(fe,list->suivant);
}

void FsauvegardeLcandid(char *nomFich,ListCandidat list)
{
    FILE *fe;
    fe=fopen(nomFich,"w");
    if(fe==NULL)
    {
        fprintf(stderr,"%sError Open File !!\n",STY_FRED);
        exit(2);
    }
    ecrireMaillonCandid(fe,list);
    fclose(fe);
}


int AlgorithmeParcoursup(Candidature **tcand,int tlog)
{   
    int noteAttente;
    printf("Entrez la note pallier pour la mise en attente :");
    scanf("%d",&noteAttente);
    // inutile ?? on prend les meilleurs jusqu'au nombre de place
    // atteintes apres, on mets les autres en attente
    int i,j;
    ListCandidat listAdmis;
    ListCandidat listAttente;
    

    listAdmis=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));

    if(listAdmis==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    listAttente=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
    if(listAttente==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    for(i=0;i<tlog;i++)
    {
        
        for(j=0;j<tcand[i]->nbChoix;j++)
        {
            if(strcmp(tcand[i]->choix[j].ville.VilleDep,VILLECANDID)==0
                && strcmp(tcand[i]->choix[j].departement,DEPTCANDID)==0)
            {
                listAdmis=FonctionInsertionCroissante(listAdmis,*tcand[i]); 
            }
        }
    }
    // on arrive ici

    listAdmis=fonctionSelection(listAdmis,listAttente,PLACES);
    
    FsauvegardeLcandid("data/ListeAdmis.don",listAdmis);
    FsauvegardeLcandid("data/ListeAttente.don",listAttente);
    return 0;
}