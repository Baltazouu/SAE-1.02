/**
 * @file candidature_menu.h
 * @author Alexandre Agostinho
 * @brief Header - Fonctions des menus pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CANDIDATURE_MENU_H
#define CANDIDATURE_MENU_H

#include "candidature.h"


int menuAjoutCandidature(Candidature *tcand[], size_t *nbcand, size_t *curralloc, uint *idmax, const char mode);
int menuSuppCandidature(Candidature *tcand[], size_t *nbcand, size_t *curralloc);

int menuAjoutChoix(Candidature *cand);

#endif