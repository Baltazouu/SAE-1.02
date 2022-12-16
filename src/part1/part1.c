#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"part1.h"

/*

int ListeVide(ListDept liste)
{
    if (list==NULL)
    {
        return 1;
    }
    return 0;
}

void InsertionCroissante(ListDept liste,char *departement,int nbP,char *resp)
{   
    if(ListeVide(liste))
    {
        strcmp(liste->departement,departement);
        strcmp(liste->resp,resp);
        liste->nbP=nbP;
    }

    if(strcmp(liste->departement,departement)<0)
    {

    }
}




void LireIUT(FILE * fe,int nb,ListDept ldept,int index)
{   
    if(index==nb)
    {
        return;
    }

    ldept=(MaillonDept*)malloc(sizeof(MaillonDept));
    if(ldept==NULL)
    {
        printf("Problème Allocation Dynamique !!\n");
        exit(2);
    }

    int i;
    for (i=0;i<nb;i++)
    {
        fscanf(fe,"%s",ldept->departement);
        fscanf(fe,"%d",ldept->nbP);
        fscanf(fe,"%s",ldept->resp);
    }
    LireIUT(fe,nb,ldept->suivant,index+1);

}


int Chargement(char *NomFich,VilleIUT **tiut)
{   
    VilleIUT **tiut; int i=0;
    tiut=(VilleIUT*)malloc(sizeof(VilleIUT)*SIZE_TIUT);
    if(tiut==NULL)
    {
        printf("Erreur Allocation Dynamique !!\n");
    }
    FILE *fe;
    fe=feopen(NomFich,"r");
    if (fe==NULL) { printf("Pb. Ouverture Fichier !!"); return -1;}
    while(!feof(fe))
    {   
        tiut[i]=(VilleIUT*)malloc(sizeof(VilleIUT));
        if(tiut[i]==NULL)
        {
            printf("Erreur Allocation Dynamique !!\n");
            exit(2);
        }
        fcanf(fe,"%s",tiut[i]->VilleDep);
        fscanf(fe,"%d",tiut[i]->nbDept);
        LireIUT(fe,tiut[i]->nbDept,tiut[i]->ldept,0);

        
    }
    

}


liste Initialiser(void)
{
    return NULL;
}


int main(void)
{
    //tests
    Ville **tiut;
    tiut=(Ville*)malloc(sizeof(Ville)*20);
    if(tiut=NULL)
    {
        printf("Problème Allocation dynamique !!\n");
        exit(2);
    }
    strcmp(tiut[0]->NomVille,"Bordeaux");
    

    tiut[0].list->VilleDep=0;  

    strcmp(tiut[1]->NomVille,"Toulouse");
    strcmp(tiut[2]->NomVille,"Marseille");
    strcmp(tiut[3]->NomVille,"Orléans");


*/
}
