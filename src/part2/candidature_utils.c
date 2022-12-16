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

#include "candidature_utils.h"
#include "errors.h"


/**
 * @brief Initialise une liste de candidature
 * 
 * @return CandListe -> NULL
 */
CandListe
initCandListe(void)
{
    return NULL;
}


/**
 * @brief Ajoute une candidature à la liste
 * 
 *  Ajoute une candidature à la liste de candidature.
 *  La candidature est ajoutée en tête de liste.
 * 
 * @param candl liste de candidature
 * @param cand candidature à ajouter
 * @return le nouveau pointeur de liste de candidature
 */
CandListe
addCand(CandListe candl, Candidature cand)
{
    CandListe newCand = (Candidature *) malloc(sizeof(Candidature));
    if (newCand == NULL) {
        exit( err(ERR_NULL_MALLOC, "on addCand") );
    }

    newCand->cand = cand;
    newCand->suiv = candl;

    return newCand;
}


/**
 * @brief Supprime une candidature de la liste
 * 
 *  Recherche une candidature dans la liste de candidature
 *  et la supprime de la liste.
 * 
 * @param candl liste de candidature
 * @param numCand numéro de la candidature à supprimer 
 * @return le pointeur de liste de candidature
 */
CandListe
supprCand(CandListe candl, int numCand)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, "on supprCand");
    return NULL;
}