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

#include "candidature_utils.h"


void afficherMenuCandidatureAdmin(void);
void afficherMenuCandidatureEtu(void);

void affichageInfoCandidat(Candidature);
void afficherMenuAjoutCandidature(Candidature);
void affichageCandidatureSaisie(Candidature);
int affichageToutCandidats(Candidature **, size_t);

#endif // { ifndef CANDIDATURE_AFFICHAGE_H }