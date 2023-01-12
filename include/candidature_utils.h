/**
 * @file conadidature_utils.h
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (header)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CANDIDATURE_UTILS_H
#define CANDIDATURE_UTILS_H

#include <stdbool.h>

#include "config.h"
#include "struct.h"


Candidature* initCanditature(uint id);

int ajouterCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, Candidature *cand);
int retirerCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, int numCand);




#endif /* CANDIDATURE_UTILS_H */