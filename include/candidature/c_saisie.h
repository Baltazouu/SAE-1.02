/**
 * @file candidature_saisie.h
 * @author Alexandre Agostinho
 * @brief Header - Fonctions de saisie pour partie 2 : Candidatures
 * @date 2023-01-05
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CANDIDATURE_SAISIE_H
#define CANDIDATURE_SAISIE_H

#include "struct.h"

int saisieMenu(int limit);
int saisieNom(char *nom);
int saisiePrenom(char *prenom);
int saisieMoyennes(Moyenne *moy);


#endif /* define CANDIDATURE_SAISIE_H */