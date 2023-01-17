/**
 * @file conadidature_utils.c
 * @author Alexandre Agostinho
 * @brief Fonctions utilitaire pour partie 2 : Candidatures (source)
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidature.h"
#include "struct.h"



/*! @brief Initialise une candidature
 *
 *  Initialise une candidature dans la mémoire.
 *  Les valeurs par défaut sont nulles.
 * 
 *  @return Candidature* pointeur vers la candidature initialisée
 */
Candidature* initCanditature(void) {

    Candidature* cand = (Candidature *)malloc(sizeof(Candidature));
    if (cand == NULL) exit( err(ERR_NULL_MALLOC, initCanditature) );

    strcpy(cand->nomCandidat, "");
    strcpy(cand->prenomCandidat, "");
    cand->moyenneCandidat.maths = .0;
    cand->moyenneCandidat.fran  = .0;
    cand->moyenneCandidat.angl  = .0;
    cand->moyenneCandidat.spe   = .0;
    cand->nbChoix = 0;

    return cand;
}



/*! @brief Ajoute une candidature dans un tableau
 *
 *  Ajoute un pointeur vers une candidature dans un tableau de pointeurs de candidatures.
 *  Le tableau est trié par ordre alphabétique croissant du nom, puis du prénom des candidats.
 * 
 *  @note La réallocation du tableau est gérée ici (dans cette version, elle ne fonctionne pas).
 * 
 *  @param tcand tableau de pointeurs de candidatures
 *  @param nbCand nombre de candidatures dans le tableau
 *  @param curralloc taille physique du tableau (nombre d'éléments alloués actuellement)
 *  @param cand pointeur vers la candidature à ajouter
 * 
 *  @return int code d'erreur
 */
int ajouterCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, Candidature *cand) {
 
    int i = 0, cmp = 1;

    if (*nbCand == (*curralloc)) {
        *curralloc += MALLOC_DYN_INC;
        tcand = (Candidature **)realloc(tcand, sizeof(Candidature *) * (*curralloc));
        if (tcand == NULL) exit( err(ERR_NULL_MALLOC, retirerCandidature) );
    }

    while (cmp > 0 && i < *nbCand) {
        cmp = cmpcand(*cand, *tcand[i]);
        if (cmp == 0) return err(ERR_ALREADY_EXIST, ajouterCandidature);
        if (i == MAX_CANDIDATURES-1) return err(ERR_TAB_FULL, ajouterCandidature);
        i++;
    } 
    
    int j;
    for (j = *nbCand; j > i; j--) {
        tcand[j] = tcand[j-1];
    }

    tcand[i] = cand;
    (*nbCand)++;

    return OK;
}



/*! @brief Retire une candidature d'un tableau
 *
 *  Retire une candidature d'un tableau de pointeurs de candidatures.
 *  
 *  Demande le numéro de la candidature à retirer, utilise la fonction de recherche pour trouver
 *  la candidature dans le tableau, puis décale toutes les candidatures suivantes d'une case vers
 *  la gauche.
 * 
 *  @note La réallocation du tableau est aussi gérée ici (dans cette version, elle ne fonctionne pas).
 * 
 *  @param tcand tableau de pointeurs de candidatures
 *  @param nbCand nombre de candidatures dans le tableau
 *  @param curralloc taille physique du tableau (nombre d'éléments alloués actuellement)
 *  @param numCand numéro de la candidature à retirer
 * 
 *  @return int code d'erreur
 */
int retirerCandidature(Candidature *tcand[], size_t *nbCand, size_t *curralloc, int numCand) {

    int i, ins = rechcand(tcand, *nbCand, numCand);
    if (ins == -1) return err(ERR_DONT_EXIST, retirerCandidature);

    for (i = ins; i < *nbCand-1; i++) {
        tcand[i] = tcand[i+1];
    }

    (*nbCand)--;
    if (*curralloc - *nbCand > 5) {
        *curralloc -= MALLOC_DYN_INC;
        tcand = (Candidature **)realloc(tcand, sizeof(Candidature *) * (*curralloc));
        if (tcand == NULL) exit( err(ERR_NULL_MALLOC, retirerCandidature) );
    }

    return OK;
}



/*! @brief Compare deux candidatures
 *
 *  Compare deux candidatures par ordre alphabétique croissant du nom,
 *  puis du prénom des candidats, si les noms sont identiques.
 * 
 *  @param c1 première candidature à comparer
 *  @param c2 deuxième candidature à comparer
 * 
 *  @return int code de comparaison (identique à strcmp)
 */
int cmpcand(Candidature c1, Candidature c2) {

    int cmpnom = strcmp(c1.nomCandidat, c2.nomCandidat);
    int cmpprenom = strcmp(c1.prenomCandidat, c2.prenomCandidat);

    if (cmpnom == 0) return cmpprenom;
    return cmpnom;
}



/*! @brief Recherche une candidature dans un tableau
 *
 *  Recherche une candidature dans un tableau de pointeurs de candidatures.
 *  Recherche faite par le numéro de candidature.
 * 
 *  @param tcand tableau de pointeurs de candidatures
 *  @param nbcand nombre de candidatures dans le tableau
 *  @param numCand numéro de la candidature à rechercher
 * 
 *  @return int indice de la candidature dans le tableau, -1 si non trouvée
 */
int rechcand(Candidature *tcand[], size_t nbcand, int numCand) {

    int i = 0;
    while ( tcand[i]->idCandidat != numCand ) {
        if (i == nbcand-1) return -1;
        i++;
    }

    return i;
}
