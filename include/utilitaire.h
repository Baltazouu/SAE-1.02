#ifndef UTILITAIRE_H
#define UTILITAIRE_H

#include"struct.h"


/**
 * //// NOT WORKING (car tableau pas trié)
 * @brief Fonction de recherche Dichotomique
 * d'une ville dans un tableau
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à rechercher
 * @return -1 si la ville n'est pas trouvée, l'emplacement de la ville sinon
 */
int frechDicho(VilleIUT **tiut,int taille,VilleIUT ville);

/**
 * @brief modifie le nombre de places dans un département
 * @param ldept liste des departements
 * @param Departement nom du departement
 * @param nbp nombre de places
 * @return 1 si le département est trouvé, 0 sinon
*/
int modifnbPlist(ListDep ldept,char *Departement,int nbp);

/**
 * @brief modifie le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @param nbp nombre de places
*/
void modifNbpDepartement(VilleIUT **tiut,int taille,VilleIUT ville,char *Departement,int nbp);

/**
 * @brief modifie le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @param nbp nombre de places
 * @return la liste mise à jour
*/
ListDep insertionMaillonCroissant(ListDep ldept, MaillonDept *maillon);

/**
 * @brief modifie le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @param nbp nombre de places
*/
void InsertionDepartement(VilleIUT **tiut,int taille,char *Ville,char *Departement,int nbp,char *resp);

/**
 * @brief modifie le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @param nbp nombre de places
 * @return la liste mise à jour
*/
ListDep suppressionMaillonDept(ListDep ldept,char *Departement);

/**
 * @brief modifie le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @param nbp nombre de places
 * @return 1 si le département est supprimé, 0 sinon
*/
int fSuppressionDept(VilleIUT **tiut,int taille,char *ville,char *Departement);

/**
 * @brief Modifie le responsable d'un département
 * @param ldept liste des departements
 * @param Departement nom du departement
 * @param resp nom du responsable
 * @return 1 si le responsable est modifie, 0 sinon
*/
int fModifRespDept(ListDep ldept,char *Departement,char *resp);

/**
 * @brief Modifie le responsable d'un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param Departement nom du departement
 * @param resp nom du responsable
 * @return 1 si le responsable est modifie, -1 sinon
*/
int FmodifResp(VilleIUT **tiut,int taille,char *Departement,char *Responsable);

/**
 * @brief modifie le nombre de places dans un département
 * @param ld liste des departements
 * @param Departement nom du departement
 * @return 1 si le département est trouvé, 0 sinon
*/
int FrechList(ListDep ldept,char *Departement);

#endif