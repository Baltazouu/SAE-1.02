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

#include "config.h"
#include <stdbool.h>
#include "struct.h"


// Fonction d'affichage

void afficherCandidature(Candidature);
void afficherToutesCandidatures(Candidature *, int);

// Fonctionns utilitaires

Candidature remplireCandidature(void);
int ajouterCandidature(Candidature *, int, Candidature);
int retirerCandidature(Candidature *, int, int);

int ajouterChoix(Candidature *, int, int, Choix);
int retirerChoix(Candidature *, int, int, int);

// Fonction de gestion de fichiers

int chargerCandidaturesTxt(Candidature *, char *);
int chargerCandidaturesBin(Candidature *, char *);
int sauvegarderCandidatures(Candidature *, int, char *);


#endif /* CANDIDATURE_UTILS_H */