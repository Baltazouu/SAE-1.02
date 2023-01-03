#ifndef UTILITAIRE_H
#define UTILITAIRE_H

#include"struct.h"

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
int fSuppressionDept(VilleIUT **tiut,int taille,char *VilleIUT,char *Departement);

/**
 * @brief modifie le nombre de places dans un département
 * @param ld liste des departements
 * @param Departement nom du departement
 * @return 1 si le département est trouvé, 0 sinon
*/
int FrechList(ListDep ldept,char *Departement);


/**
 * @brief recherche le nombre de places dans un département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param ville ville à modifier
 * @param Departement nom du departement
 * @return 1 si le département est trouvé, 0 sinon
 */
int FrechnbP(VilleIUT **tiut,int taille,char *Ville,char *Departement);

/**
 * @brief modifie le nom du responsable de département
 * @param ldept liste des departements
 * @param Departement nom du departement
 * @param resp nom du responsable
 * @return 1 si le département est trouvé, 0 sinon
 */
int fModifRespDept(ListDep ldept,char *Departement,char *resp);


/**
 * @brief modifie le nom du responsable de département
 * @param tiut tableau des villes
 * @param taille taille du tableau
 * @param Departement nom du departement
 * @param Responsable nom du responsable
 * @return 1 si le département est trouvé, -1 sinon
 */
int FmodifResp(VilleIUT **tiut,int taille,char *Departement,char *Responsable);

/**
 * @brief recherche la présence d'un département dans une liste
 * @param ldept liste des departements
 * @param Departement nom du departement
 * @return 1 si le département est trouvé, 0 sinon
 */
int FrechList(ListDep ldept,char *Departement);


#endif