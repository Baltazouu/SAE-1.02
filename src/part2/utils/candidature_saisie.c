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

#include "candidature_saisie.h"
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
    scanf( "%d", &menu);

    if (menu > limit) return -err(ERR_INVALID_MENU_SELECT, saisieMenu);
    return menu;
}