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

#include"utilitaire.h"
#include"struct.h"


ListAdmis FonctionInsertionCroissante()


int AlgorithmeParcoursup(Candidature **tcand,int tlog,VilleIUT ville)
{   
    int i=0;
    ListAdmis *list;
    list=(ListAdmis*)malloc(sizeof(ListAdmis));
    if(ListAdmis==NULL)
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
            if (strcmp(tcand[i]->choix->ville,VILLECANDID)==0 &&
                strcmp(tcand[i]->choix->departement,DEPTCANDID)==0)
                // insertion croissante
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