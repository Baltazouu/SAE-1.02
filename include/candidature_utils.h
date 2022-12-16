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


/**
 * @struct Choix
 * @brief Represente un choix d'un étudiant
 * 
 *  Un choix est définie par la ville choisie, le département
 *  et la décision du département.
 */
typedef struct {
    Ville villeChoisie; /*!< ville choisie */
    Departement dept; /*!< département */
    Decision decs; /*!< décision du département */
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


/*! @struct CandMaillon
 *  @brief Maillon de liste de Candidature
 *
 *  Définie un maillon d'une liste de candidature.
 *  Définie aussi un pointeur sur le premier maillon.
 */
typedef struct liste {
    Candidature cand; /*!< pointeur sur struct Candidature */
    struct liste *suiv; /*!< pointeur sur le maillon suivant */
} CandMaillon, *CandListe;



// Déclaration de fonctions

CandListe initCandListe(void);
CandListe addCand(CandListe candl, Candidature cand);
CandListe supprCand(CandListe candl, int numCand);

//CandListe chargCand_TXT(CandListe candl, char *filepath, int *nbCand);
//CandListe chargCand_BIN(CandListe candl, char *binepath, int *nbCand);
//int sauvCand(CandListe candl, int nbCand);


#endif /* CANDIDATURE_UTILS_H */