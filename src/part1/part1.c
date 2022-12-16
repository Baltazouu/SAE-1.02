/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"part1.h"


int LireIUT(FILE * fe,VilleIUT Ville)
{   
    VilleIUT Ville;
    int i,nbdept;
    
    fread(&Ville,sizeof(VilleIUT),1,fe);
    fread(&nbdept,sizeof(int),1,fe);
    for(i=0;i<nbdept;i++)
    {
            
    }

}


int LireIut(char *NomFich,VilleIUT **tiut)
{   
    FILE *fe;
    fe=feopen(NomFich,"rb");
    if (fe==NULL) { printf("Pb. Ouverture Fichier !!"); return -1;}
    while(!feof(fe))
    {
        
    }
    

}
*/