/**
 * @file candidature_menu.c
 * @author Alexandre Agostinho
 * @brief Header - Fonctions des menus pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "errors.h"
#include "candidature.h"

int menuAjoutCandidature(Candidature *tcand[], size_t *nbcand, size_t *curralloc) {

    Candidature *cand = initCanditature(tcand[*nbcand-1]->idCandidat+1);
    bool sortie = false;
    int menuSelect;
    
    while ( !sortie )
    {
        afficherMenuAjoutCandidature(*cand);
        int out;
        
        do {
            menuSelect = saisieMenu(5);
        } while (menuSelect == -ERR_INVALID_MENU_SELECT);

        switch ( menuSelect ) {

            case 1:     // menu: MODIFICATION NOM
                while ( !(out = saisieNom(cand->nomCandidat)) ) {
                    switch (out) {
                        case ERR_INVALID_STR_FORMAT:
                            printf("(err) Format de nom invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                    sleep(3);
                    clrscrcmd();
                }
                break;

            case 2:     // menu: MODIFICATION PRENOM
                while ( !(out = saisiePrenom(cand->prenomCandidat)) ) {
                    switch (out) {
                        case ERR_INVALID_STR_FORMAT:
                            printf("(err) Format de prenom invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                    sleep(3);
                    clrscrcmd();
                }
                break;

            case 3:     // menu: MODIFICATION MOYENNE
                while ( !(out = saisieMoyennes(&cand->moyenneCandidat)) ) {
                    switch (out) {
                        case ERR_INVALID_NUM_FORMAT:
                            printf("(err) nombre invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                    sleep(3);
                    clrscrcmd();
                }
                break;

            case 4:     // menu: AJOUTER CANDIDATURE
                switch ( ajouterCandidature(tcand, nbcand, curralloc, cand) ) {
                    case OK:
                        printf("(ok) Ajout de candidature réussi !\n");
                        sortie = true;
                    case ERR_ALREADY_EXIST:
                        printf("(err) candidature déjà existante...\n");
                        break;
                    case ERR_TAB_FULL:
                        printf("(err) nombre de candidatures maximal atteint...\n");
                        break;
                    default:
                        printf("(err) erreur...\n");
                }
                sleep(3);
                clrscrcmd();
                break;

            case 5:     // menu: ANNULER
                printf("ANULLATION...\n");
                sortie = true;
                free(cand);
                sleep(3);
                clrscrcmd();
                break;

            default:    // erreur d'argument (-> regarder saisie menu)
                exit( err(ERR_INVALID_ARG, menuCandidature) );
                sleep(3);
                clrscrcmd();
        }
    }
    
    return OK;
}

