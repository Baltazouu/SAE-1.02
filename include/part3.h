#ifndef PART3_H
#define PART3_H

#include"struct.h"


/**
 * @brief fonction qui permet d'ecrire un maillon de candidat admis
 * dasn un fichier fe
 * @param fe fichier de destination
 * @param list list a ecrire
 */
void ecrireMaillonCandid(FILE *fe,ListCandidat list);

/**
 * @brief Fonction qui permet de sauvegarder une liste de candidats admis 
 * dans un fichier
 * @param nomFich nom du fichier 
 * @param list list des candidats a ecrire
 */
void FsauvegardeLcandid(char *nomFich,ListCandidat list);



/**
 * @brief fonction qui permet de trier les candidatures par ordre croissant de rang
 * 
 * @param tcand tableau des candidatures 
 * @param tlog taille du tableau
 * @param ville ville de l'IUT dans lequel on veut admettre les etudiants 
 * @return int
 */
int AlgorithmeParcoursup(Candidature **tcand,int tlog);


#endif