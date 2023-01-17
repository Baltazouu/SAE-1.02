/**
 * @file candidature_saisie.c
 * @author Alexandre Agostinho
 * @brief Code source - Fonctions de saisie pour partie 2 : Candidatures
 * @date 2023-01-05
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <string.h> 

#include "candidature.h"
#include "errors.h"




/*! @brief saisie d'un choix dans un menu
 *
 *  Affiche un prompt et lis un entier sur l'entrée standard.
 *  Envoie un code d'erreur si l'entier saisie sort du champ du menu.
 *
 *  @param limit limite du champ du menu
 *  @return l'entier saisie ou (-)<ERR_INVALID_MENU_SELECT>
 */
int saisieMenu(int limit)
{
    int menu;

    printf( "[ MENU SELECTION ]:\t" );
    scanf( "%d%*c", &menu);

    if (menu > limit) {
        printf("(err) Choix invalide, retapez...\n");
        return -err(ERR_INVALID_MENU_SELECT, saisieMenu);
    }
    return menu;
}



/*! @brief saisie d'un nom
 *
 *  Affiche un prompt et lis une chaîne de caractères sur l'entrée standard.
 *  Le nom y est demandé.
 *  Met la première lettre en majuscule automatiquement.
 *  Test si le nom contient des chiffres.
 * 
 *  @param nom pointeur vers la chaîne de caractères correspondant au nom
 *  @return int code d'erreur
 */
int saisieNom(char *nom) {

    printf("[ Saisie nom ]:  ");
    fgets(nom, MAX_LEN_STRNOM, stdin);
    nom[strlen(nom)-1] = '\0';

    if (nom[0] >= 'a') nom[0] -= 32;

    for (int i = 0; nom[i] != '\0'; i++) {
        if ( nom[i] >= '0' && nom[i] <= '9' )    
            return err(ERR_INVALID_STR_FORMAT, saisieNom);
    }

    return OK;
}



/*! @brief saisie d'un prenom
 *
 *  Affiche un prompt et lis une chaîne de caractères sur l'entrée standard.
 *  Le prenom y est demandé.
 *  Met la première lettre en majuscule automatiquement.
 *  Test si le prenom contient des chiffres.
 * 
 *  @param nom pointeur vers la chaîne de caractères correspondant au prenom
 *  @return int code d'erreur
 */
int saisiePrenom(char *prenom) {

    printf("[ Saisie prenom ]:  ");
    fgets(prenom, MAX_LEN_STRPRENOM, stdin);
    prenom[strlen(prenom)-1] = '\0';

    if (prenom[0] >= 'a') prenom[0] -= 32;

    for (int i = 0; prenom[i] != '\0'; i++) {
        if ( prenom[i] >= '0' && prenom[i] <= '9' )    
            return err(ERR_INVALID_STR_FORMAT, saisiePrenom);
    }

    return OK;
}



/*! @brief saisie des moyennes d'un candidat
 *
 *  Affiche un prompt et lis des flottants sur l'entrée standard.
 *  Les moyennes de certaines matières y sont demandées.
 * 
 *  @param moy pointeur vers la structure Moyenne
 *  @return int code d'erreur
 */
int saisieMoyennes(Moyenne *moy) {

    printf("[ Saisie moyennes ]\n");

    printf("  - MATHEMATIQUES:  "); scanf("%f%*c", &moy->maths);
    if (moy->maths < 0) return err(ERR_INVALID_NUM_FORMAT, saisieMoyennes);
    printf("  - ANGLAIS:        "); scanf("%f%*c", &moy->angl);
    if (moy->angl < 0) return err(ERR_INVALID_NUM_FORMAT, saisieMoyennes);
    printf("  - FRANCAIS:       "); scanf("%f%*c", &moy->fran);
    if (moy->fran < 0) return err(ERR_INVALID_NUM_FORMAT, saisieMoyennes);
    printf("  - SPECIALITE:     "); scanf("%f%*c", &moy->spe);
    if (moy->spe < 0) return err(ERR_INVALID_NUM_FORMAT, saisieMoyennes);
    
    return OK;
}