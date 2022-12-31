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


/**
 * @struct Choix
 * @brief Represente un choix d'un étudiant
 * 
 *  Un choix est définie par la ville choisie, le département
 *  et la décision du département.
 */
typedef struct {
    int numChoix; /*!< numéro du choix */
    Ville villeChoisie; /*!< ville choisie */
    Departement dept; /*!< département */
    Decision decs; /*!< décision du département */
    bool validation; /*!< validation du choix */
} Choix;


/*! @struct Candidature
 *  @brief Candidature d'un étudiant
 * 
 *  Une candidature est définie par le nom de l'étudiant, son prénom
 *  et ses notes en Maths, Français, Anglais et de Spécialité.
 */
typedef struct {
    int numCand; /*!< numéro du candidat */
    Nom nom; /*!< nom du candidat */
    Prenom prenom; /*!< prénom du candidat */
    Moyennes moy; /*!< Tableau des moyennes [Maths, Franç, Angl, Spé] */
    int nbChoix; /*!< nombre de choix */
    Choix choix[MAX_CHOIX]; /*!< tableau des choix */
} Candidature;



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