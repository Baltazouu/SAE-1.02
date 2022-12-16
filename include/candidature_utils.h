/**
 * @file conadidature_utils.h
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (header)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include "config.h"



/*! @struct Candidature
 *  @brief Candidature d'un étudiant
 * 
 *  Une candidature est définie par le nom de l'étudiant, son prénom
 *  et ses notes en Maths, Français, Anglais et de Spécialité.
 */
typedef struct {
    Nom nom; /*!< nom du candidat */
    Prenom prenom; /*!< prénom du candidat */
    Moyennes moy; /*!< Tableau des moyennes [Maths, Franç, Angl, Spé] */
} Candidature;


/*! @struct CandMaillon
 *  @brief Maillon de liste de Candidature
 *
 *  Définie un maillon d'une liste de candidature.
 *  Définie aussi un pointeur sur le premier maillon.
 */
typedef struct liste {
    Candidature *cand; /*!< pointeur sur struct Candidature */
    struct liste *suiv; /*!< pointeur sur le maillon suivant */
} CandMaillon, *CandListe;



// Déclaration de fonctions

Candidature* initCand(void);
CandListe chargCand_TXT(CandListe candl, char *filepath, int *nbCand);
CandListe chargCand_BIN(CandListe candl, char *binepath, int *nbCand);
int sauvCand(CandListe candl, int nbCand);