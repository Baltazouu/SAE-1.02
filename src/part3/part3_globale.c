/**
 * @file part3_globale.c
 * @author Dudonne Baptiste
 * @brief fonction globale de la partie 3
 * @version 0.1
 * @date 2023-01-12
 */

#include<stdio.h>
#include<string.h>

#include "part3_globale.h"
#include"struct.h"
#include"part3_utilitaire.h"
#include"config.h"
#include"part3.h"


void globalePart3(Candidature **tcand,int tlog,int tphys,VilleIUT ville)
{
    char Login[LONGRESPLOGIN], Password[LONGRESPPASSWD];
    strcpy(Login,"login");
    strcpy(Password,"password");

    printf("%s",CLEAR_CMD);
    printf("%sTraitement des dossiers de candidature\n%s",STY_BOLD,STY_NULL);

    printf("Entrez le login administrateur : ");
    scanf("%s",Login);

    printf("Entrez le mot de passe administrateur :");
    scanf("%s",Password);

    if (strcmp(Login,LOGIN)==0 && strcmp(Password,PASSWD)==0)
    {
        AlgorithmeParcoursup(tcand,tlog,ville);
    }
    else{

        fprintf(stderr,"%sLogin/Password Incorrect !!\n%s",STY_FRED,STY_NULL);
    }

}