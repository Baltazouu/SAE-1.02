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

#### Généralités
Dans cette seconde partie, nous nous interressont à une phase de candidature
pour rejoindre les departements des differents campus.  

Au lancement de la procédure de cette phase de candidature, nous pouvons :
  - Ajouter une nouvelle candidature,
  - Supprimer une candidature déjà existante,
  - Modifier une candidature déjà existante,
  - Affichier toutes les candidatures,
  - Sauvgarder les candidature dans un fichier,
  - Terminer la phase de candidature,
  - Quitter le menu des candidatures.  

Notons que le menu d'ajout et de modification des candidatures est le même, à la
différance qu'il n'ont pas les même textes d'affichage, et que nous avons pas le
besoin d'enregistrer les modifications (pour celui des modifications).  

Depuis le menu d'ajout ou de modifications, nous pouvons :
  - Editer le nom du candidat,
  - Editer le prenom du candidat,
  - Editer les moyennes demandés,
  - Ajouter un nouveau voeu pour un département
  - Enregistrer la candidature,
  - Anuller.  

Le menu de suppression des candidature et le menu de modification affiche la
liste des candidatures déjà existante pour pouvoir récupérer plus facilement
l'id de la candidature visée par les fonctions.  

Comme dit plus haut, nous avons un affichage de type tableau, affichant toutes
les candidatures enregistrés ainsi que celles qui ont été rentrées. L'affichage,
aussi bien que le stockage dans le fichier de sauvegarde, se fait par ordre
alphabethique en triant d'abord par le nom, puis par le prénom de la personne.  

#### Technicités
Voyons maintenent plus en détails comment cette partie à été implémentée.  

###### `lancement`
Tout d'abord, à l'arrivé sur le menu par l'appel de la fonction `menuCandidature`,
un chargement du fichier de sauvegarde est effectué automatiquement. Ensuite le
menu repose sur une lecture d'entier pour accéder aux fonctionnalités. Le menu
et le reste du programe peuvent donc après commencer correctement.

###### `menu`
Un système de `switch` assure le choix du menu et aussi que tous les types d'erreurs
rencontrés soit traitées correctement. Ces erreurs possibles sont lister dans le
fichier `erreurs.h`.  
Les menus ont tous la fonctionnalité de "`clear`" le terminal, pour garder un
affichage simple et lisible.

###### `stokage des données`
Toutes les condidatures sont enregistrées dans un tableau de pointeur de
structure `Candidature`. Ce tableau a une taille dynamique. La taille phisique
du tableau s'incrémente d'une certaine valeur quand elle ateint sa taille
maximale. La valeur d'incrémentation se trouve et peut être modifier dans le
header `config.h`.  

Toutes les données sont insérés dans ce tableau triées par ordre alphabetique
sur le nom du candidat, puis sur son prénom si des nom sont identique. Deux nom
et prénom identique ne peuvent pas être enregistré ensemble dans le tableau.

###### `ajout, modification, suppression`
L'ajout insert un élément à la bonne place dans le tableau de `Candidature` en
respectant le tri par ordre aplhabethique cité plus haut.  

La suppression supprime un élément du tableau et réarange le tableau pour
combler le trou créé. La candidature supprimée est ensuite libérée de la mémoire
vive de l'ordinateur.

La modification est sensiblement la même que l'ajout, à la diférence que cette
fonction ne réinsère pas l'élément, mais se contente de modifier les valeurs
directement depuis le tableau.

###### `chargement`
Le chargement du fichier de suvegarde récupère d'abord le nombre de
`Candidatures` à enregistrer, et ré-alloue l'espace nécessaire à ce tableau pour
pouvoir les récupérer.  

La lecture dans le fichier de sauvegarde n'a pas besoin de s'effectuer dans
l'ordre du tri alphabetique utilisé dans le stockage à court terme du programme.




#### Strucutures Utilisees :

```c
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
