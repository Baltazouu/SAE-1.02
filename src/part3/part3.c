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


int FchargementRespBin(char *Nom,char *Passwd)
{
    FILE *fl;
    fl=fopen("data/reponsable.bin","rb");
    if(fl==NULL)
    {
        printf("Erreur de chargement du fichier");
        return -1;
    }
    else
    {
        fread(Nom,sizeof(Nom),1,fl);
        fread(Passwd,sizeof(Passwd),1,fl);
        fclose(fl);
        return 1;
    }

}

void FsauvegardeRespBin(char *Nom,char *Passwd,int longNom,int longPasswd)
{
    FILE *fe;
    fe=fopen("data/responsable.bin","wb");
    if(fe==NULL)
    {
        printf("Erreur d'ouverture du fichier sauvegarde !\n");
        exit(1);
   }
    fwrite(Nom,sizeof(strlen(Nom)),longNom,fe);
    fwrite(Passwd,sizeof(strlen(Passwd)),longPasswd,fe);
    fclose(fe);

}




void globalePart3(Candidature **tcand,int tlog,int tphys,VilleIUT ville)
{
    char Login[LONGRESPLOGIN], Password[LONGRESPPASSWD];
    
    printf("%s",CLEAR_CMD);
    printf("%sTraitement des dossiers de candidature\n%s",STY_BOLD,STY_NULL);

    printf("Entrez le login administrateur : ");
    scanf("%s",Login);

    printf("Entrez le mot de passe administrateur :");
    scanf("%s",Password);

    if (strcmp(Login,LOGIN)==0 && strcmp(Password,PASSWD)==0)
    {

    }
    else{

        fprintf(stderr,"%sLogin/Password Incorrect !!\n%s",STY_FRED,STY_NULL);
    }

}

