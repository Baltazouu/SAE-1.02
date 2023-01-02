/**
 * \brief Fonction de lecture des fichiers
 * \file globale.c
 * \author Dudonné Baptiste
 * \date Dec 31
 * \version 1.0
*/


/// fonctions globales  


#include<stdio.h>
#include"part1.h"
#include<string.h>
#include"affichage.h"
#include"config.h"

void FGlobale(void)
{
    
    VilleIUT *tiut[SIZE_TIUT];
    char nomFich[20],nomFichBin[20];
    strcpy(nomFich,"data/IUT.don");
    strcpy(nomFichBin,"data/IUT.bin");
    int size=SIZE_TIUT;
    
    int tlog = fchargementBin(nomFichBin,tiut,size);
    int option=0;
   
    afficheVille(tiut,tlog);
    //printf("%s",CLEAR_CMD);
    //fAffichMenu();
    fscanf(stdin,"%d",&option);
    if (option == 1)
    {
        fonctionGlobaleAdmin(tiut,&tlog,&size,nomFich);
    }
    if (option == 2)
    {
        fonctionGlobaleEtudiant(tiut,&tlog,&size,nomFich);
    }
    if(option == 3)
    {
        fSauvegarde(tiut,tlog,nomFich);
        FsauvegardeBin(tiut,tlog,nomFichBin);
    }
    

}


void fonctionGlobaleAdmin(VilleIUT **tiut,int *tlog,int *tphys,char *NomFich)
{   
    
    int option=0;
    printf("%s",CLEAR_CMD);
    fAffichAdmin();
    fscanf(stdin,"%d",&option);
    while(option!=10)
    {
        if(option==1)
        {
            //Modifier le nombre de places dans un département
            VilleIUT ville;
            int nbp;
            char Departement[LONGDEP];
            printf("Entrez le nom de la ville : ");
            scanf("%s",ville.VilleDep);
            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';
            printf("Entrez le nouveau nombre de places : ");
            scanf("%d",&nbp);
            modifNbpDepartement(tiut,*tlog,ville,Departement,nbp);
        }

        if (option ==2)
        {
            //Ajouter un département dans une ville
            char ville[LONGVILLE];
            char Departement[LONGDEP];
            char resp[LONGRESP];
            int nbp;

            printf("Entrez le nom de la ville : ");
            scanf("%s",ville);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            printf("Entrez le nom du responsable : ");
            fgets(resp,LONGRESP,stdin);
            resp[strlen(resp)-1]='\0';

            printf("Entrez le nombre de places : ");
            scanf("%d",&nbp);
            InsertionDepartement(tiut,*tlog,ville,Departement,nbp,resp);
        }

        if (option==3)
        {
            //suppression d'un département
            char ville[LONGVILLE];
            char Departement[LONGDEP];

            printf("Entrez le nom de la ville : ");
            fscanf(stdin,"%s",ville);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            fSuppressionDept(tiut,*tlog,ville,Departement);
        }

        if ( option == 4)
        {
            // Modifier le nom d'un responsabled de département
            char ville[LONGVILLE];
            char Departement[LONGDEP];
            char resp[LONGRESP];

            printf("Entrez le nom de la ville : ");
            fscanf(stdin,"%s",ville);

            printf("Entrez le nom du département : ");
            fgets(Departement,LONGDEP,stdin);
            Departement[strlen(Departement)-1]='\0';

            printf("Entrez le nom du responsable : ");
            fgets(resp,LONGRESP,stdin);
            resp[strlen(resp)-1]='\0';

            FmodifResp(tiut,*tlog,Departement,resp);
        }

        if (option == 5)
        {
            // lancer et arrêter la procédure d'admission
        }
    }
}


void fonctionGlobaleEtudiant(VilleIUT **tiut,int *tlog,int *size,char *nomFich)
{
    printf("A faire !\n");
}
