/**
 * @file conadidature_utils.c
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (source)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidature.h"



Candidature* initCanditature(void) {

    Candidature* cand = (Candidature *)malloc(sizeof(Candidature));
    if (cand == NULL) exit( err(ERR_NULL_MALLOC, initCanditature) );

    strcpy(cand->nomCandidat, "");
    strcpy(cand->prenomCandidat, "");
    cand->moyenneCandidat.maths = .0;
    cand->moyenneCandidat.fran  = .0;
    cand->moyenneCandidat.angl  = .0;
    cand->moyenneCandidat.spe   = .0;
    cand->nbChoix = 0;

    return cand;
}




/**
 * @brief Ajoute une candidature
 * 
 *  Ajoute une candidature à la liste des candidatures
 * 
 * @param tcand tabmleau de candidatures
 * @param nbCand nombre de candidatures 
 * @param cand candidature à ajouter
 * @return int le nouveau nombre de candidatures ou -<ERRCODE> en cas d'erreur
 */
int ajouterCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, Candidature *cand) {
    
    int i = 0, cmp;

    if (*nbCand != 0) {
        do {
            cmp = cmpcand(*cand, *tcand[i]);
            if (cmp == 0) return err(ERR_ALREADY_EXIST, ajouterCandidature);
            if (i == MAX_CANDIDATURES-1) return err(ERR_TAB_FULL, ajouterCandidature);
            i++;
        } while (cmp < 0 && i < *nbCand);
    }

    if (*nbCand == *curralloc) {
        *curralloc += MALLOC_DYN_INC;
        tcand = realloc(tcand, *curralloc);
        if (tcand == NULL) exit( err(ERR_NULL_MALLOC, retirerCandidature) );
    }
    
    int j;
    for (j = *nbCand; j > i; j--) {
        tcand[i] = tcand[i-1];
    }

    tcand[i] = cand;
    (*nbCand)++;

    return OK;
}

/**
 * @brief Retire une candidature
 * 
 *  Retire une candidature du tableau de candidatures
 * 
 * @param tcand tableau de candidatures
 * @param nbCand nombre de candidatures
 * @param numCand numéro de la candidature à retirer
 * @return int le nouveau nombre de candidatures ou -<ERRCODE> en cas d'erreur
 */
int retirerCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, int numCand) {

    int i, ins = rechcand(tcand, *nbCand, numCand);
    if (ins == -1) return err(ERR_DONT_EXIST, retirerCandidature);

    for (i = ins; i < *nbCand-1; i++) {
        tcand[i] = tcand[i+1];
    }

    (*nbCand)--;
    if (*curralloc - *nbCand > 5) {
        *curralloc -= MALLOC_DYN_INC;
        tcand = realloc(tcand, *curralloc);
        if (tcand == NULL) exit( err(ERR_NULL_MALLOC, retirerCandidature) );
    }

    return OK;
}


int cmpcand(Candidature c1, Candidature c2) {

    int cmpnom = strcmp(c1.nomCandidat, c2.nomCandidat);
    int cmpprenom = strcmp(c1.prenomCandidat, c2.prenomCandidat);

    if (cmpnom == 0) return cmpprenom;
    return cmpnom;
}

int rechcand(Candidature *tcand[], size_t nbcand, int numCand) {

    int i = 0;
    while ( tcand[i]->idCandidat != numCand ) {
        if (i == nbcand-1) return -1;
        i++;
    }

    return i;
}