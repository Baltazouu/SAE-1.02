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
 * @brief Affiche une candidature
 * 
 *  Affiche les informations d'une candidature
 *  !NOT IMPLEMENTED
 * @param cand candidature à afficher
 */
void afficherCandidature(Candidature cand) {
    err(ERR_NOT_IMPLEMENTED, afficherCandidature);
    return;
}


/**
 * @brief Affiche toutes les candidatures
 * 
 *  Affiche les informations de toutes les candidatures
 *  !NOT IMPLEMENTED
 * @param tcand tableau de candidatures à afficher
 * @param nbCand nombre de candidatures
 */
void afficherToutesCandidatures(Candidature *tcand, int nbCand) {
    err(ERR_NOT_IMPLEMENTED, afficherToutesCandidatures);
    return;
}


/**
 * @brief Créé et remplie une candidature
 * 
 *  Création d'une nouvelle candidature
 *  et remplissage des informations la concernant.
 * !NOT IMPLEMENTED
 * 
 * @return Candidature remplie
 */
Candidature remplireCandidature(void) {
    err(ERR_NOT_IMPLEMENTED, remplireCandidature);
    return (Candidature){0};
}


/**
 * @brief Ajoute une candidature
 * 
 *  Ajoute une candidature à la liste des candidatures
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tabmleau de candidatures
 * @param nbCand nombre de candidatures 
 * @param cand candidature à ajouter
 * @return int le nouveau nombre de candidatures ou -<ERRCODE> en cas d'erreur
 */
int ajouterCandidature(Candidature *tcand, int nbCand, Candidature cand) {
    return err(ERR_NOT_IMPLEMENTED, ajouterCandidature);
}

/**
 * @brief Retire une candidature
 * 
 *  Retire une candidature du tableau de candidatures
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param nbCand nombre de candidatures
 * @param numCand numéro de la candidature à retirer
 * @return int le nouveau nombre de candidatures ou -<ERRCODE> en cas d'erreur
 */
int retirerCandidature(Candidature *tcand, int nbCand, int numCand) {
    return err(ERR_NOT_IMPLEMENTED, retirerCandidature);
}


/**
 * @brief Ajoute un choix
 * 
 *  Ajoute un choix à la liste des choix d'une candidature
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param nbCand nombre de candidatures
 * @param numCand numéro de la candidature à laquelle ajouter le choix
 * @param choix choix à ajouter
 * @return int le nouveau nombre de choix ou -<ERRCODE> en cas d'erreur
 */
int ajouterChoix(Candidature *tcand, int nbCand, int numCand, Choix choix) {
    return err(ERR_NOT_IMPLEMENTED, ajouterChoix);
}

/**
 * @brief Retire un choix
 * 
 *  Retire un choix de la liste des choix d'une candidature
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param nbCand nombre de candidatures
 * @param numCand numéro de la candidature à laquelle retirer le choix
 * @param numChoix numéro du choix à retirer
 * @return int le nouveau nombre de choix ou -<ERRCODE> en cas d'erreur
 */
int retirerChoix(Candidature *tcand, int nbCand, int numCand, int numChoix) {
    return err(ERR_NOT_IMPLEMENTED, retirerChoix);
}


/**
 * @brief Charge les candidatures depuis un fichier texte
 * 
 *  Charge les candidatures depuis un fichier texte
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param filename nom du fichier
 * @return int le nombre de candidatures chargées ou -<ERRCODE> en cas d'erreur
 */
int chargerCandidaturesTxt(Candidature *tcand, char *filename) {
    return err(ERR_NOT_IMPLEMENTED, chargerCandidaturesTxt);
}

/**
 * @brief Charge les candidatures depuis un fichier binaire
 * 
 *  Charge les candidatures depuis un fichier binaire
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param filename nom du fichier
 * @return int le nombre de candidatures chargées ou -<ERRCODE> en cas d'erreur
 */
int chargerCandidaturesBin(Candidature *tcand, char *filename) {
    return err(ERR_NOT_IMPLEMENTED, chargerCandidaturesBin);
}

/**
 * @brief Sauvegarde les candidatures dans un fichier texte
 * 
 *  Sauvegarde les candidatures dans un fichier texte
 *  !NOT IMPLEMENTED
 * 
 * @param tcand tableau de candidatures
 * @param nbCand nombre de candidatures
 * @param filename nom du fichier
 * @return int le nombre de candidatures sauvegardées ou -<ERRCODE> en cas d'erreur
 */
int sauvegarderCandidatures(Candidature *tcand, int nbCand, char *filename) {
    return err(ERR_NOT_IMPLEMENTED, sauvegarderCandidaturesTxt);
}
