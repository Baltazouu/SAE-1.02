/**
 * @file candidature_affichage.h
 * @author Alexandre Agostinho
 * @brief Header - Fonctions d'affichages pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CANDIDATURE_AFFICHAGE_H
#define CANDIDATURE_AFFICHAGE_H

#include "struct.h"


void afficherMenuCandidatureAdmin(void);
void afficherMenuCandidatureEtu(void);

void afficherMenuAjoutCandidature(Candidature cand, const char *fin);
void affichageInfoCandidat(Candidature cand);
void affichageCandidatureSaisie(Candidature cand);
int affichageToutCandidats(Candidature *tcand[], size_t nbCand);


#endif // { ifndef CANDIDATURE_AFFICHAGE_H }