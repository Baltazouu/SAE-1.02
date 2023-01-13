# Compte Rendu

* Dudonne Baptiste
* Agostinho Alexandre

## Partie 1 : 

Dans la partie 1 du programme, nous pouvons gerer les IUT de France, ces IUT sont stockes dans leur ordre de creation, dans le dossier data/IUT.don, on retrouve toutes les informations relatives a ces IUT tel que les IUT, leurs departements triees dans l'ordre croissant en fonction de leur nom, le nombre de places en premiere annee ainsi que le nom du responsable du departement.

Les algorithmes de recherche sont de simples algorithmes parcourant la totalitee des tableau ou des listes : un for pour les tableaux (ceux-ci n'etant pas triees par ordre croissant) et de maniere recursive pour les listes.

#### Structures Utilisees :

```c
#define LONGVILLE 12
#define LONGDEP 31
#define LONGRESP 31

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
```

## Partie 2

Speech alex : ce vnbek be beo 

#### Strucutures Utilisees :

```c
/* < partie 2 > */

  

/*! @struct Moyenne

* @brief Moyennes du candidat

*/* < partie 2 > */

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

* Structure composé de 4 moyennes.

*/

typedef struct {

Note maths; /*!< moyenne maths */

Note fran; /*!< moyenne français */

Note angl; /*!< moyenne anglais */

Note spe; /*!< moyenne spécialité */

} Moyenne;

  

/*! @struct Choix

* @brief Represente un choix d'un étudiant

*

* Un choix est définie par la ville choisie, le département,

* la décision du département et enfin l'acceptation par le candidat

* de ce choix.

*/

typedef struct {

VilleIUT ville; /*!< ville où se situe le département */

char departement[LONGDEP]; /*!< nom du département */

Decision decision; /*!< décision du département [-1,0,1] */

bool validation; /*!< validation du choix */

} Choix;

  

/*! @struct Candidature

* @brief Candidature d'un étudiant

*

* Une candidature est définie par le nom de l'étudiant, son prénom

* et ses notes en Maths, Français, Anglais et de Spécialité.

* Elle se définie aussi avec les choix des differentes écoles que

* l'autheur de la candidature souhaite intégrer.

*/

typedef struct {

ID idCandidat; /*!< numiéro d'identification */

Nom nomCandidat; /*!< nom du candidat */

Prenom prenomCandidat; /*!< prenom du candidat */

Moyenne moyenneCandidat; /*!< moyennes du candidat [Maths,Fr,Ang,Spé] */

size_t nbChoix; /*!< nombre de choix choisi */

Choix choix[MAX_CHOIX]; /*!< tableau des ecoles choisies */

} Candidature;
```


## Partie 3 :

Dans la 3 eme partie du programme, j'ai choisi de recuperer le tableau de pointeurs de candidatures utilise dans la partie 2 afin de selectionner parmi les candidatures pour l'IUT de Clermont-Ferrand dans le departement informatique.
Les candidatures sont donc envoyees dans la fonction ''Algorithme Parcoursup''
De cette fonction ressort deux Listes classees par ordre croissant des notes de Type ListCandidats les admis et ceux places en attente. Les candidats places en attentes ne sont pas comme dans l'enonce places en attente a partir d'une moyenne mais lorsque le nombre maximal de places est atteint.

Etant donne qu'il etat demande de simplifier la chose pour se concentrer sur le departement de Clermont-Ferrand, les informations de L'IUT sont stockees en #define

Les scripts sont realises de maniere recursive pour la manipulation des listes.

#### Structures utilisees :

```c
#define LONGRESPLOGIN 10
#define LONGRESPPASSWD 10
#define LOGIN "login"
#define PASSWD "password"
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
```
