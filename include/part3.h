#ifndef PART3_H
#define PART3_H

#include"struct.h"

/**
 * @brief Fonction de chargement du responsable des admissions
 * @param Nom nom du responsable (login)
 * @param Passwd password du responsable
 * @param longNom longeur de nom
 * @param longPasswd longueur passwd
 * @return -1 si pb durant chargement 0 sinon
 */
int FchargementRespBin(char *Nom,char *Passwd);

/**
 * @brief Fonction de sauvegarde des données du responsable d'admissions
 * @param Nom nom du responsable (login)
 * @param Passwd mot de passe du responsable
 * @param longNom longeur tableau nom
 * @param longPasswd longueur tableua password
 */
void FsauvegardeRespBin(char *Nom,char *Passwd,int longNom,int longPasswd);

/**
 * @brief Fonction globale partie 3
 * @param tcand tableau de pointeur des candidatures
 * @param tlog taille logique du tableau
 * @param tphys taille physique du tableau
 */
void globalePart3(Candidature **tcand,int tlog,int tphys,VilleIUT ville);



#endif