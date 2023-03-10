#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdbool.h>
#include "config.h"

#define LONGVILLE 12
#define LONGDEP 31
#define LONGRESP 31
#define SIZE_TIUT 15
#define MAX_LONGFICH 15

#define MAX_LEN_STRNOM 21
#define MAX_LEN_STRPRENOM 51

/* < typdef simples > */

typedef unsigned int ID;
typedef char Nom[MAX_LEN_STRNOM];
typedef char Prenom[MAX_LEN_STRPRENOM];
typedef float Note;
typedef enum { ADMIS,   LISTE_ATTENTE, REFUSE } Decision;


/* < partie 1 > */

typedef struct list
{
    char departement[LONGDEP];
    int nbP;
    char resp[LONGRESP];
    struct list *suivant;

}MaillonDept,*ListDep;


typedef struct 
{
    char VilleDep[LONGVILLE];
    ListDep ldept;
    int nbDept;
} VilleIUT;


/* < partie 2 > */

/*! @struct Moyenne
 *  @brief Moyennes du candidat
 *
 *  Structure composé de 4 moyennes.
 */
typedef struct {
    Note maths;     /*!< moyenne maths */
    Note fran;      /*!< moyenne français */
    Note angl;      /*!< moyenne anglais */
    Note spe;       /*!< moyenne spécialité */
} Moyenne;

/*! @struct Choix
 *  @brief Represente un choix d'un étudiant
 * 
 *  Un choix est définie par la ville choisie, le département,
 *  la décision du département et enfin l'acceptation par le candidat
 *  de ce choix.
 */
typedef struct {
    VilleIUT ville;             /*!< ville où se situe le département */
    char departement[LONGDEP];  /*!< nom du département */
    Decision decision;          /*!< décision du département [-1,0,1] */
    bool validation;            /*!< validation du choix */
} Choix;

/*! @struct Candidature
 *  @brief Candidature d'un étudiant
 * 
 *  Une candidature est définie par le nom de l'étudiant, son prénom
 *  et ses notes en Maths, Français, Anglais et de Spécialité.
 *  Elle se définie aussi avec les choix des differentes écoles que
 *  l'autheur de la candidature souhaite intégrer.
 */
typedef struct {
    ID idCandidat;              /*!< numiéro d'identification */
    Nom nomCandidat;            /*!< nom du candidat */
    Prenom prenomCandidat;      /*!< prenom du candidat */
    Moyenne moyenneCandidat;    /*!< moyennes du candidat [Maths,Fr,Ang,Spé] */
    size_t nbChoix;                /*!< nombre de choix choisi */
    Choix choix[MAX_CHOIX];     /*!< tableau des ecoles choisies */
} Candidature;


// PARTIE 3 

#define LONGRESPLOGIN 10
#define LONGRESPPASSWD 10

#define LOGIN "login"
#define PASSWD "password"

// Fonction algorithme candidature
#define VILLECANDID "Clermont-Ferrand"
#define DEPTCANDID "Informatique"
#define PLACES 100

/**
 * @brief Liste des candidats
 */
typedef struct listcandidats
{
    Candidature candidat;
    struct listcandidats *suivant;
}MaillonCandidat,*ListCandidat;


#endif