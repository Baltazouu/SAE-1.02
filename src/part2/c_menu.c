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




int menuAjoutCandidature(Candidature *tcand[], size_t *nbcand, size_t *curralloc, uint *idmax, const char mode) {

    Candidature *cand; uint id; size_t ins; char fin[9];
    switch (mode) {
        case 'a':
            cand = initCanditature();
            cand->idCandidat = *idmax+1; (*idmax)++;
            strcpy(fin, "ANULLER");
            break;
        case 'm':
            affichageToutCandidats(tcand, *nbcand);
            printf("[ MODIF CANDIDAT ]\n- id:  "); scanf("%d%*c", &id);
            ins = rechcand(tcand, *nbcand, id);
            cand = tcand[ins];
            strcpy(fin, "TERMINER");
            break;
        default:
            exit( err(ERR_INVALID_ARG, menuAjoutCandidature) );
    }

    bool sortie = false;
    int menuSelect;
    
    while ( !sortie )
    {
        clrscrcmd();
        afficherMenuAjoutCandidature(*cand, fin);
        int out;

        do {
            menuSelect = saisieMenu(6);
        } while (menuSelect == -ERR_INVALID_MENU_SELECT);

        switch ( menuSelect ) {

            case 1:     // menu: MODIFICATION NOM
                do {
                    out = saisieNom(cand->nomCandidat);
                    switch (out) {
                        case OK:
                            break;
                        case ERR_INVALID_STR_FORMAT:
                            printf("(err) Format de nom invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                } while (out != OK);
                clrscrcmd();
                break;

            case 2:     // menu: MODIFICATION PRENOM
                do {
                    out = saisiePrenom(cand->prenomCandidat);
                    switch (out) {
                        case OK:
                            break;
                        case ERR_INVALID_STR_FORMAT:
                            printf("(err) Format de prenom invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                } while (out != OK);
                clrscrcmd();
                break;

            case 3:     // menu: MODIFICATION MOYENNE
                do {
                    out = saisieMoyennes(&cand->moyenneCandidat);
                    switch (out) {
                        case OK:
                            break;
                        case ERR_INVALID_NUM_FORMAT:
                            printf("(err) nombre invalide, retaper...\n");
                            break;
                        default:
                            printf("(err) erreur...\n");
                    }
                } while (out != OK);
                clrscrcmd();
                break;
            
            case 4:     // menu: AJOUTER CANDIDATURE
                switch (menuAjoutChoix(cand)) {
                    case OK:
                        break;
                    case ERR_TAB_FULL:
                        printf("(err) nombre de choix maximum attein...\n");
                        break;
                    default:
                        printf("(err) erreur...\n");
                }
                clrscrcmd();
                break;

            case 5:     // menu: ENREGISTRER
                switch ( ajouterCandidature(tcand, nbcand, curralloc, cand) ) {
                    case OK:
                        printf("(ok) Ajout de candidature réussi !\n");
                        sortie = true;
                        break;
                    case ERR_ALREADY_EXIST:
                        printf("(err) candidature déjà existante...\n");
                        break;
                    case ERR_TAB_FULL:
                        printf("(err) nombre de candidatures maximal atteint...\n");
                        break;
                    default:
                        printf("(err) erreur...\n");
                }
                sleep(2);
                clrscrcmd();
                break;

            case 6:     // menu: ANNULER
                printf("%s...\n", fin);
                sortie = true;
                if (mode == 'a')
                    free(cand);
                sleep(2);
                clrscrcmd();
                break;

            default:    // erreur d'argument (-> regarder saisie menu)
                err(ERR_INVALID_ARG, menuCandidature);
                scanf("%*s");
                sleep(2);
                clrscrcmd();
        }
    }

    return OK;
}

int menuAjoutChoix(Candidature *cand) {

    if (cand->nbChoix >= MAX_CHOIX) {
        return err(ERR_TAB_FULL, menuAjoutChoix);
    }
    
    printf("\n[ CHOIX ECOLE ]\n");
    printf("- VILLE:        "); scanf("%s%*c", cand->choix[cand->nbChoix].ville.VilleDep);
    printf("- DEPARTEMENT:  "); scanf("%s%*c", cand->choix[cand->nbChoix].departement);
    cand->choix[cand->nbChoix].decision = LISTE_ATTENTE;
    cand->choix[cand->nbChoix].validation = false;

    cand->nbChoix++;
    return OK;
}

int menuSuppCandidature(Candidature *tcand[], size_t *nbcand, size_t *curralloc) {

    affichageToutCandidats(tcand, *nbcand);

    const char menutext[] =
        " [ SUPPRESSION CANDIDATURE ]\n"
        "\n"
        "    n° candidat:  ";

    int idCand;
    printf(menutext); scanf("%d%*c", &idCand);

    const char confirmtext[] =
        STY_FRED "\n\nETES-VOUS SUR DE VOULOIR SUPPRIMER LE CANDIDAT (%d) ? (y/N)" STY_NULL;
    
    printf(confirmtext, idCand);
    char confirm = getchar();
    if (confirm == 'y') {
        retirerCandidature(tcand, nbcand, curralloc, idCand);
        return 1;
    }

    sleep(2);
    clrscrcmd();
    return 0;
}