/**
 * \brief Fonction de lecture des fichiers
 * \file globale.c
 * \author Dudonné Baptiste
 * \date Dec 31
 * \version 1.0
*/


/// fonctions globales  


#include<stdio.h>
#include<string.h>
#include"part1.h"
#include"globale.h"
#include"affichage.h"
#include"config.h"
#include"utilitaire.h"
#include"unistd.h"
#include"stdlib.h"

void FGlobale(void)
{
    
    VilleIUT *tiut[SIZE_TIUT];
    char nomFich[20],nomFichBin[20];
    strcpy(nomFich,"data/IUT.don");
    strcpy(nomFichBin,"data/IUT.bin");
    int size=SIZE_TIUT;
    
    int tlog = fChargement(nomFich,tiut,&size);

    //printf("Taille ; %d\n",tlog);

    int option=0;
   
    //afficheVille(tiut,tlog);
    //printf("%s",CLEAR_CMD);
    fAffichMenu();
    fscanf(stdin,"%d",&option);
    switch (option)
    {
        case 1:
        fonctionGlobaleAdmin(tiut,&tlog,&size,nomFich);
        break;

    case 2:
    
        fonctionGlobaleEtudiant(tiut,&tlog,&size,nomFich);
        break;
    
    case 3:
        fSauvegarde(tiut,tlog,nomFich);
        //FsauvegardeBin(tiut,tlog,nomFichBin);
    break;
    }
}


void fonctionGlobaleAdmin(VilleIUT **tiut,int *tlog,int *tphys,char *NomFich)
{   
    
    int option=0;
    printf("%s",CLEAR_CMD);
    fAffichAdmin();
    fscanf(stdin,"%d",&option);

    char Departement[LONGDEP];
    char resp[LONGRESP];
    int nbp;
    VilleIUT ville;

    while(option!=6)
    {   
        switch (option)
        {
        
        case 1:
            //Modifier le nombre de places dans un département
            
            printf("Entrez le nom de la ville : ");
            scanf("%s%*c",ville.VilleDep);
            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            printf("Entrez le nouveau nombre de places : ");
            scanf("%d",&nbp);
            modifNbpDepartement(tiut,*tlog,ville,Departement,nbp);

            break;
        
        case 2:
            
            //Ajouter un département dans une ville
            
            printf("Entrez le nom de la ville : ");
            scanf("%s%*c",ville.VilleDep);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            printf("Entrez le nom du responsable : ");
            fgets(resp,LONGRESP,stdin);
            resp[strlen(resp)-1]='\0';

            printf("Entrez le nombre de places : ");
            scanf("%d",&nbp);
            InsertionDepartement(tiut,*tlog,ville.VilleDep,Departement,nbp,resp);
            break;

        case 3:
            //suppression d'un département

            printf("Entrez le nom de la ville : ");
            fscanf(stdin,"%s%*c",ville.VilleDep);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            fSuppressionDept(tiut,*tlog,ville.VilleDep,Departement);
            break;

        case 4:
            // Modifier le nom d'un responsable de département

            printf("Entrez le nom de la ville : ");
            fscanf(stdin,"%s%*c",ville.VilleDep);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            printf("Entrez le nom du responsable : ");
            fgets(resp,LONGRESP,stdin);
            resp[strlen(resp)-1]='\0';

            FmodifResp(tiut,*tlog,Departement,resp);

            break;

        case 5:   
            printf("a faire\n");
            // lancer et arrêter la procédure d'admission
            break;
        }

        sleep(3);
        printf("%s",CLEAR_CMD);
        fAffichAdmin();
        fscanf(stdin,"%d%*c",&option);
    }
    fSauvegarde(tiut,*tlog,NomFich);
    printf("\n%s     Sauvegarde Effectuee avec succes !\n",STY_FGREEN);
    exit(0);
}


void fonctionGlobaleEtudiant(VilleIUT **tiut,int *tlog,int *size,char *nomFich)
{   
    printf("%s",CLEAR_CMD);
    AffichEtu();
    int option=0;
    char dept[LONGDEP];

    fscanf(stdin,"%d%*c",&option);
    while(option!=5)
    {
        switch (option)
        {
        
        case 1:
            // Afficher la liste des villes
            //printf("%s",CLEAR_CMD);
            FaffichListIUT(tiut,*tlog);
            break;
        

        case 2:
            printf("%s",CLEAR_CMD);
            // Afficher la liste des départements d'un IUT
            fAffichListDept(tiut,*tlog);
            
            break;
        

        case 3:
            // Afficher le nombre de places en premiere annee
            affichePlace(tiut,*tlog);
            
            break;
        
        case 4:
            // Afficher Un département parmi les IUT
            printf("Entrez le nom du département : ");
            fscanf(stdin,"%s%*c",dept);

            //fAffichListDept(tiut,*tlog);
            FaffichDept(tiut,*tlog,dept);
            
            break;
        }
    sleep(3);
    printf("%s",CLEAR_CMD);
    AffichEtu();
    fscanf(stdin,"%d%*c",&option);
    }
    exit(0);    
}
