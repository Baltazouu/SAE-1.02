/**
 * @file config.h
 * @author Alexandre Agostinho / Baptiste Dudonne
 * @brief fichier de configuration du programme
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef CONFIG_H
#define CONFIG_H

// -- PARTIE 2 - Candidatures

// constantes
#define MAX_CANDIDATURES 100
#define MAX_CHOIX 10

// definition des variable
typedef char Nom[21];
typedef char Prenom[21];
typedef float Moyennes[4];
typedef char Ville[31];
typedef char Departement[31];
typedef enum { ADMIS, LISTE_ATTENTE, REFUSE } Decision ;


#endif /* CONFIG_H */