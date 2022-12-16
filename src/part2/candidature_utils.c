/**
 * @file conadidature_utils.c
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (source)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdlib.h>
#include "candidature_utils.h"
#include "errors.h"

/**
 * @brief Initialisation d'un candidat
 * 
 *  Allocation mémoire d'une structure Candidature.
 * 
 * @return Candidature* - l'addresse de l'allocation
 */
Candidature*
initCand(void)
{
    Candidature *cand = (Candidature *)malloc(sizeof(Candidature));
    if (cand == NULL) { eprintf("malloc error on line __LINE__"); exit(1); }
    return cand;
}
