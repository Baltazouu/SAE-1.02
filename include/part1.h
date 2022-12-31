#ifndef PART1_H
#define PART1_H

#include"struct.h"
#include<stdio.h>
/**
 * \brief Initialise une liste à NULL
*/
ListDep init();


/**
 * \brief Fonction d'insertion croissante d'un maillon dans une liste
 * \brief en fonction du nom de département
 * \param list liste d'entrée
 * \param maillon maillon à inserer
 * \return void mais la liste est triée par ordre alphabétique
*/
//void insertioncroissante(ListDep list,MaillonDept *maillon);

/**
 * \brief Fonction de lecture d'une liste 
 * \brief de départements
 * \param fe fichier source de lecture
 * \param nbDept Nombre de départements à lire
 * \return Listdep une liste de départements
*/
ListDep LireDept(FILE *fe, int nbDept);


/**
 * \brief Fonction qui lit une structure de donnée type ville
 * \param fe fichier où lire la ville
 * \return un pointeur sur la ville
*/
VilleIUT* lireVille(FILE *fe);

/**
 * \brief fonction de chargement d'un tableau de pointeur
 * de type ville iut
 * \param tiut tableau de pointeurs à remplir
 * \param taille taille initiale du tableau de pointeurs
 * \param nomFich string du nom du fichier où extraire
 * \return le nombre de villes chargées
*/
int fChargement(char *nomFich, VilleIUT **tiut, int *taille);

/**
 * \brief Affiche une liste de départements
*/

/**
 * \brief Fonction de sauvegarde des éléments d'une liste
 * \param fe Fichier de sauvegarde
 * \param list liste à sauvegarder
*/
void fSauvegardeList(FILE *fe,ListDep list);

/**
 * \brief Fonction de sauvegarde d'un tableau de pointeurs
 * \param tiut tableau de pointeurs à sauvegarder
 * \param size taille du tableau de pointeurs
 * \param nomFich Nom du fichier où sauver
*/
void fSauvegarde(VilleIUT **tiut,int size,char *nomFich);

#endif