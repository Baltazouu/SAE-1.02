#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include"struct.h"

/**
 * \brief Affiche le contenu d'un maillon de la liste des départements
 * \param maillon Le maillon à afficher
*/
void affichemaillon(MaillonDept *maillon);

/**
 * \brief Affiche la liste des départements
 * \param ldept La liste des départements
*/
void afficherDepartementsRecursif(ListDep ldept);

/**
 * \brief Affiche la liste des départements
 * \param ldept La liste des départements
 * \param nbDept Le nombre de départements
 * \param nbVille Le nombre de villes
*/
void afficheVille(VilleIUT **tiut,int nbVille);

/**
 * \brief Affiche le nombre de départements
 * \param list La liste des départements
 * \param Departement Le département recherché
 * \return Le nombre de départements
*/
int  fAffichNbp(ListDep list, char *Departement);

/**
 * \brief Affiche le menu
*/
void fAffichMenu(void);

/**
 * \brief Affiche le menu administrateur
*/
void fAffichAdmin(void);

#endif