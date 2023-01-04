/**tiut[i]tiut[i]
 * \file part1.c
 * \brief Fonctons Essentielles (chargement, déchargement, lecture et globale)
 * \date Dec 30
 * \author Dudonné Baptiste
 * 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"part1.h"
#include"config.h"
#include"affichage.h"
/**
 * \brief Foncton d'initialisation d'une liste
 * \return NULL
*/
ListDep init()
{
    return NULL;
}


ListDep LireDept(FILE *fe, int nbDept)
{
    //printf("Nombre Dept : %d\n",nbDept);
    if (nbDept == 0)
    {
        return NULL;
    }
    
    MaillonDept *maillon;
    maillon = (MaillonDept *)malloc(sizeof(MaillonDept));
    if (maillon == NULL)
    {
        printf("Error Dynamic Allocation !!\n");
        exit(2);
    }
   
    fgets(maillon->departement, 30, fe);
    maillon->departement[strlen(maillon->departement) - 1] = '\0';


    fscanf(fe,"%d\n",&maillon->nbP);

    fgets(maillon->resp, LONGRESP, fe);
    maillon->resp[strlen(maillon->resp) - 1] = '\0';
    fscanf(fe,"\n");
   
    //affichemaillon(maillon);
    maillon->suivant = LireDept(fe, nbDept - 1);
    
    //tri par insertion ordre alphabétique
    MaillonDept *current = maillon;
    MaillonDept *next = maillon->suivant;
    while (next != NULL)
    {
        if (strcmp(current->departement, next->departement) > 0)
        {
            char temp[30];
            strcpy(temp, current->departement);
            strcpy(current->departement, next->departement);
            strcpy(next->departement, temp);
            
            int tempInt = current->nbP;
            current->nbP = next->nbP;
            next->nbP = tempInt;
            
            char tempChar[LONGRESP];
            strcpy(tempChar, current->resp);
            strcpy(current->resp, next->resp);
            strcpy(next->resp, tempChar);
        }
        current = current->suivant;
        next = current->suivant;
    }
    
    //printf("Maillon Actuel %s\n",maillon->departement);
    //printf("maillon suivant : %s\n",maillon->suivant->departement);
    return maillon;
}

VilleIUT* lireVille(FILE *fe)
{
    VilleIUT *ville;
    ville = (VilleIUT *)malloc(sizeof(VilleIUT));
    if (ville == NULL)
    {
        printf("Error Dynamic Allocation !!\n");
    }

    fscanf(fe, "%s %d\n", ville->VilleDep, &ville->nbDept);
    //printf("Ville : %s \nNombre de départements : %d\n",ville.VilleDep,ville.nbDept);

    return ville;
}

int fChargement(char *nomFich, VilleIUT **tiut, int *taille)
    {
        FILE *fe;
        int i=0;
        fe=fopen(nomFich,"r");
        if (fe==NULL)
        {
            printf("Error Opening File !!\n");
            return -1;
        }
        VilleIUT *ville;
        ville=(VilleIUT*)malloc(sizeof(VilleIUT));
        if(ville==NULL)
        {
            printf("Error Dynamic Allocation !!\n");
            exit(2);
        }
       
        ville=lireVille(fe);

        while(!feof(fe))
        {
            if(i==*taille)
            {
                tiut=realloc(tiut, *taille+10 * sizeof(VilleIUT*));
                *taille+=10;
            }
            tiut[i]=(VilleIUT*)malloc(sizeof(VilleIUT));
            if(tiut[i]==NULL)
            {
                printf("Error Dynamic Allocation !!\n");
                exit(2);
            }
            ListDep list=LireDept(fe,ville->nbDept);
            
            //printf("On arrive ici\n");
            ville->ldept=list;
            tiut[i]=ville;
            ville=lireVille(fe);
            i++;
        }
        fclose(fe);
        return i;
        
    }


void fSauvegardeList(FILE *fe,ListDep list)
{
    if(list==NULL)
    {
        return;
    }
    fprintf(fe,"%s\n",list->departement);
    fprintf(fe,"%d\n",list->nbP);
    fprintf(fe,"%s\n",list->resp);
    fSauvegardeList(fe,list->suivant);
}



void fSauvegarde(VilleIUT **tiut,int size,char *nomFich)
{
    FILE *fe;   int i;
    fe=fopen(nomFich,"w");
    if(fe==NULL)
    {
        printf("Error Opening File !");
        exit(2);
    }
    for(i=0;i<size;i++)
    {
        fprintf(fe,"%s\n",tiut[i]->VilleDep);
        fprintf(fe,"%d\n",tiut[i]->nbDept);
        fSauvegardeList(fe,tiut[i]->ldept);
    }

    fclose(fe);
}


void fsauvegardeListBin(FILE *fe,ListDep List)
{
    if(List==NULL)
    {
        return;
    }
    fwrite(List,sizeof(ListDep),1,fe);
    fsauvegardeListBin(fe,List->suivant);
}

void FsauvegardeBin(VilleIUT **tiut,int tlog,char *nomFich)
{
    FILE *fe;    int i;
    fe=fopen(nomFich,"wb");
    if(fe==NULL)
    {
        printf("Error Opening File !");
        exit(2);
    }
    
    fwrite(&tlog,sizeof(int),1,fe);
    for (i=0;i<tlog;i++)
    {
        fwrite(tiut[i],sizeof(VilleIUT),1,fe);
        fsauvegardeListBin(fe,tiut[i]->ldept);
    }
    printf("%s saved successfully !\n",STY_FGREEN);
    fclose(fe);
}

ListDep LectureBin(FILE *fe,int nbDept)
{
    if(nbDept==0)
    {
        return NULL;
    }
    MaillonDept *maillon;
    maillon=(MaillonDept*)malloc(sizeof(MaillonDept));
    if(maillon==NULL)
    {
        printf("Error Dynamic Allocation !!\n");
        exit(2);
    }
        fread(maillon,sizeof(maillon),1,fe);
        return maillon->suivant=LectureBin(fe,nbDept-1);
}

int fchargementBin(char *nomFich, VilleIUT **tiut, int *taille)
{
    FILE *fe;
    int i = 0;
    fe = fopen(nomFich, "rb");
    if (fe == NULL)
    {
        printf("Error Opening File !!\n");
        return -1;
    }
    tiut[i] = (VilleIUT*)malloc(sizeof(VilleIUT));
    if (tiut[i] == NULL)
    {
        printf("Error Dynamic Allocation !!\n");
        exit(2);
    }
    fread(tiut[i], sizeof(VilleIUT), 1, fe);
    while (!feof(fe))
    {
        if (i == *taille)
        {
            tiut = realloc(tiut, (*taille + 10) * sizeof(VilleIUT*));
            if (tiut == NULL)
            {
                printf("Error Dynamic Reallocation !!\n");
                exit(2);
            }
            *taille += 10;
        }
        tiut[i]->ldept = LectureBin(fe, tiut[i]->nbDept);

        tiut[i + 1] = (VilleIUT*)malloc(sizeof(VilleIUT));
        if (tiut[i + 1] == NULL)
        {
            printf("Error Dynamic Allocation !!\n");
            exit(2);
        }

        fread(tiut[i + 1], sizeof(VilleIUT), 1, fe);
        i++;
    }
    fclose(fe);
    return i;
}
