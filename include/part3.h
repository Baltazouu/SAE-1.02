#ifndef PART3_H
#define PART3_H

#include"struct.h"


/**
 * @brief fonction qui permet d'ecrire un maillon de candidat admis
 * dasn un fichier fe
 * @param fe fichier de destination
 * @param list list a ecrire
 */
void ecrireMaillonAdmis(FILE *fe,ListAdmis list);

/**
 * @brief Fonction qui permet de sauvegarder une liste de candidats admis 
 * dans un fichier
 * @param nomFich nom du fichier 
 * @param list list des candidats a ecrire
 */
void FsauvegardeLadmis(char *nomFich,ListAdmis list);

/**
 * @brief Fonction qui permet d'ecrire un maillon
 *  candidat en attente dans un fichier
 * @param fe fichier de destination
 * @param list list a ecrire
 */
void ecrireMaillonLatt(FILE *fe,ListAttente list);

/**
 * @brief Fonction qui sauvegarde la liste des candidats en attente
 *  dans un fichier 
 * @param nomFich nom du fichier
 * @param list list des candidats
 */
void FsauvegardeLatt(char *nomFich,ListAttente list);

/**
 * @brief Fonction globale partie 3
 * @param tcand tableau de pointeur des candidatures
 * @param tlog taille logique du tableau
 * @param tphys taille physique du tableau
 */
void globalePart3(Candidature **tcand,int tlog,int tphys,VilleIUT ville);

/**
 * @brief fonction qui permet de trier les candidatures par ordre croissant de rang
 * 
 * @param tcand tableau des candidatures 
 * @param tlog taille du tableau
 * @param ville ville de l'IUT dans lequel on veut admettre les etudiants 
 * @return int
 */
int AlgorithmeParcoursup(Candidature **tcand,int tlog,VilleIUT ville);


#endif