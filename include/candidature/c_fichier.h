/**
 * @file candidature_fichier.h
 * @author Alexandre Agostinho
 * @brief Header - Fonctions de gestion des fichiers pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CANDIDATURE_FICHIER_H
#define CANDIDATURE_FICHIER_H

#include "struct.h"

Candidature lireCand(FILE *fe);
void ecrireCand(FILE *fe, Candidature cand);

int chargementCand(Candidature *tcand[], size_t *nbcand, size_t *curralloc, uint *idmax, const char *nomfichier);
int sauvegardeCand(Candidature *tcand[], size_t nbcand, const char *nomfichier);

#endif