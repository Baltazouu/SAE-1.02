#ifdef GLOBALE_H
#define GLOBALE_H

#include "struct.h"

/// fonctions globales  

/**
 * @brief Fonction globale de l'administrateur
 * @param tiut tableau de pointeurs de villes
 * @param tlog taille logique du tableau
 * @param tphys taille physique du tableau
 * @param NomFich nom du fichier de sauvegarde
*/
void fonctionGlobaleAdmin(VilleIUT **tiut,int *tlog,int *tphys,char *NomFich);

/**
 * @brief Fonction globale de l'étudiant
 * @param tiut tableau de pointeurs de villes
 * @param tlog taille logique du tableau
 * @param size taille physique du tableau
 * @param nomFich nom du fichier de sauvegarde
*/
void fonctionGlobaleEtudiant(VilleIUT **tiut,int *tlog,int *size,char *nomFich);

#endif