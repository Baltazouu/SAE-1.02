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
#include "candidature_menu.h"
#include "candidature_affichage.h"
#include "candidature_saisie.h"


int menuCandidature(void)
{
    // TODO: Initialisation des variables

    Candidature *tcand[] = (Candidature **)malloc(sizeof(Candidature)*MALLOC_DYN_INC);
    if (tcand == NULL) exit( err(ERR_NULL_MALLOC, menuCandidature) );

    size_t nbCand = 0;
    size_t curralloc = MALLOC_DYN_INC;
    int menuSelect;

    bool sortie = false;

    //! Boucle principale
    while ( !sortie ) {

        // TODO: Affichage menu principal
        afficherMenuCandidatureEtu();
        do {
            menuSelect = saisieMenu(7);
        } while (menuSelect == -ERR_INVALID_MENU_SELECT);

        // TODO: Selection choix
        switch (menuSelect) {
            case 1:     // menu: AJOUT CANDIDATURE
                menuAjoutCandidature(tcand, &nbCand, &curralloc);
                break;

            case 2:     // menu: SUPPRESSION CANDIDATURE
                men
                break;

            case 3:     // menu: MODIFICATION CANDIDATURE
                exit( err(ERR_NOT_IMPLEMENTED, menuCandidature) );
                break;

            case 4:     // menu: AFFICHAGE DES CANDIDATURES
                exit( err(ERR_NOT_IMPLEMENTED, menuCandidature) );
                break;

            case 5:     // menu: SAUVGARDE DES CANDIDATURES
                exit( err(ERR_NOT_IMPLEMENTED, menuCandidature) );
                break;

            case 6:     // menu: ANNULER
                exit( err(ERR_NOT_IMPLEMENTED, menuCandidature) );
                break;

            case 7:     // menu: QUITTER
                sortie = true;
                break;

            default:    // erreur d'argument (-> regarder saisie menu)
                exit(err(ERR_INVALID_ARG, menuCandidature));
        }
    }

    // TODO: Sortie du menu (retour vers menu principal)

    return OK;
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