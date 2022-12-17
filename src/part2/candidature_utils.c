/**
 * @file conadidature_utils.c
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (source)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidature_utils.h"
#include "errors.h"


/**
 * @brief Initialise une liste de candidature
 *  
 *  Retourne une structure CandFile avec ses pointeurs initialisé à <NULL>.
 * 
 * @return CandFile -> { NULL, NULL }
 */
CandFile
initCandFile(void)
{
    return (CandFile){ NULL, NULL };
}


/**
 * @brief Test si la file est vide.
 * 
 *  La file est vide si la tête et la queue sont <NULL>.
 *  Renvoie une erreur si un des deux est à autre chose que <NULL> quand l'un l'est.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf la file de candidat
 * @return true si la file es vide
 * @return false si la file contient des éléments
 */
bool
isCandfEmpty(CandFile candf)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, isCandfEmpty);
    return false;
}


/**
 * @brief Recherche si un candidat est présent dans la file
 * 
 *  Recherche la présence d'un candidat dans la file et sa posisiton d'insertion.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf file de candidats
 * @param numCand numéro du candidat à rechercher
 * @param ins position d'insertion du candidat
 * @return true si le candidat est présent dans la file
 * @return false si la candidat n'est pas dans la file
 */
bool
researchCand(CandFile candf, int numCand, int *ins)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, researchCand);
    return false;
}


/**
 * @brief Enfile une candidature à la file
 * 
 *  Enfile une candidature à la file de candidature.
 *  La candidature est ajoutée en queue de file.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf liste de candidature
 * @param cand candidature à ajouter
 * @return le nouveau pointeur de liste de candidature
 */
CandFile
enqueueCand(CandFile candf, Candidature cand)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, enqueueCand);
    return (CandFile){NULL, NULL};
}


/**
 * @brief Défile une candidature à la file
 * 
 *  Défile une candidature à la file de candidature.
 *  La candidature en tête de liste est supprimé.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf liste de candidature
 * @param cand candidature à ajouter
 * @return le nouveau pointeur de liste de candidature
 */
CandFile
dequeueCand(CandFile candf)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, dequeueCand);
    return (CandFile){NULL, NULL};
}


/**
 * @brief Supprime une candidature de la liste
 * 
 *  Recherche une candidature dans la liste de candidature
 *  et la supprime de la liste.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf liste de candidature
 * @param numCand numéro de la candidature à supprimer 
 * @return le pointeur de liste de candidature
 */
CandFile
supprCand(CandFile candf, int numCand)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, supprCand);
    return (CandFile){NULL, NULL};
}


/**
 * @brief Chargement d'une file de candidat à partir d'un fichier .txt
 * 
 *  Ouvre un fichier de type 'txt' et charge les données qui y son renseignés
 *  dans une file de candidats.
 * 
 * ! NOT IMPLEMENTED
 * ? Implémentation du check de format
 * 
 * @param candf la liste de candidat à charger
 * @param filepath le chemin du fichier à charger
 * @param nbCand* le nombre de candidats chargé
 * @return CandFile la liste de candidat chargée
 */
CandFile
chargCand_TXT(CandFile candf, char *filepath, int *nbCand)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, chargCand_TXT);
    return (CandFile){NULL, NULL};
}


/**
 * @brief Chargement d'une file de candidat à partir d'un fichier .don
 * 
 *  Ouvre un fichier de type 'binaire' et charge les données qui y son renseignés
 *  dans une file de candidats.
 * 
 * ! NOT IMPLEMENTED
 * 
 * @param candf la liste de candidat à charger
 * @param binpath le chemin du binaire à charger
 * @param nbCand* le nombre de candidats chargé
 * @return CandFile la liste de candidat chargée
 */
CandFile
chargCand_BIN(CandFile candf, char *binpath, int *nbCand)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, chargCand_BIN);
    return (CandFile){NULL, NULL};
}


/**
 * @brief sauvegarde de la file de candidats dans un fichier binaire
 *
 * @param candf la file de candidat à sauvgarder
 * @param path le chemein où enregistrer le fichier
 * @param nbCand le nombre de candidats à enregistrer
 * @return <ERR_CODE>
 */
int
sauvCand(CandFile candf, char *path, int nbCand)
{
    // TODO
    return err(ERR_NOT_IMPLEMENTED, chargCand_BIN);
}