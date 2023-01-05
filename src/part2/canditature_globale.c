/**
 * @file candidature_globale.c
 * @author Alexandre Agostinho
 * @brief Code source - Fonction globale pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "errors.h"

#include "candidature_globale.h"
#include "candidature_affichage.h"
#include "candidature_saisie.h"


int menuCandidature(void)
{
    // TODO: Initialisation des variables

    //Candidature **tcand = (Candidature **)malloc(sizeof(Candidature)*MALLOC_DYN_INC);
    //if (tcand == NULL) return -err(ERR_NULL_MALLOC, menuCandidature);

    int nbCand = 0;
    int menuSelect;

    // TODO: Affichage menu principal
    afficherMenuCandidatureEtu();
    menuSelect = saisieMenu(7);

    printf("\nmenu selection: %d\n\n", menuSelect);


    // TODO: Selection choix

    // TODO: Sortie du menu (retour vers menu principal)

    return 0;
}

int testGlobale(void)
{
    afficherMenuCandidatureEtu();
    afficherMenuCandidatureAdmin();

    Candidature cand = {
        110200,
        "AGOSTINHO",
        "Alexandre",
        { 15.3, 12.9, 11.3, 17.4 },
        2,
        {
            {
                { "Clermont", NULL, 0 },
                "Informatique",
                0,
                false
            },
            {
                { "Grenooble", NULL, 0 },
                "Informatique",
                0,
                false
            }
        }
    };

    Candidature cand2 = {
        100102,
        "Jackie",
        "Michelle",
        { 0.2, 1.3, 3.2, 9.1 },
        0,
        { }
    };

    afficherMenuAjoutCandidature(cand);
    afficherMenuAjoutCandidature(cand2);

    return 0;
}