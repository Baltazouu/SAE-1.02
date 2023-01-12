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
    //Maillon->candidat.choix[MAX_CHOIX];
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


MaillonCandidatatt* copieMaillonAtt(Candidature cand)
{   
    int i;
    MaillonCandidatatt *Maillon;
    Maillon=(MaillonCandidatatt*)malloc(sizeof(MaillonCandidatatt));
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
    //Maillon->candidat.choix[MAX_CHOIX];
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


ListAttente FonctionInsertionCroissanteAtt(ListAttente list,Candidature cand)
{
    MaillonCandidatatt *Maillon;
    Maillon=(MaillonCandidatatt*)malloc(sizeof(MaillonCandidatatt));
    if(Maillon==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    Maillon=copieMaillonAtt(cand);

    if(list==NULL)
    {
        return Maillon;
    }
    else
    {
        if(FcalculMoyenne(cand)>FcalculMoyenne(list->candidat))
        {
            MaillonCandidatatt *tmp;
            tmp=(MaillonCandidatatt*)malloc(sizeof(MaillonCandidatatt));
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
                    MaillonCandidatatt *tmp;
                    tmp=(MaillonCandidatatt*)malloc(sizeof(MaillonCandidatatt));
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

        return list->suivant=FonctionInsertionCroissanteAtt(list->suivant,cand);
    }
}

ListAdmis FonctionInsertionCroissante(ListAdmis list,Candidature cand,ListAttente listatt,int noteAttente)
{   
    MaillonCandidat *Maillon;
    Maillon=(MaillonCandidat*)malloc(sizeof(MaillonCandidat));
    if(Maillon==NULL)
    {
        fprintf(stderr,"%sError Dynamic Allocation !!\n",STY_FRED);
        exit(2);
    }
    Maillon=copieMaillon(cand);

    if(FcalculMoyenne(cand)<noteAttente)
    {
        listatt=FonctionInsertionCroissanteAtt(listatt,cand);
    }

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

        return list->suivant=FonctionInsertionCroissante(list->suivant,cand,listatt,noteAttente);
    }
}


