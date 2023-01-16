/**
 * @file candidature_fichier.c
 * @author Alexandre Agostinho
 * @brief Source - Fonctions de gestion des fichiers pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "candidature.h"


Candidature lireCand(FILE *fe)
{
    Candidature cand;

    fscanf(fe, "%d%*c", &cand.idCandidat);
    fgets(cand.nomCandidat, MAX_LEN_STRNOM, fe); cand.nomCandidat[strlen(cand.nomCandidat)-1] = '\0';
    fgets(cand.prenomCandidat, MAX_LEN_STRPRENOM, fe); cand.prenomCandidat[strlen(cand.prenomCandidat)-1] = '\0';
    fscanf(fe, "%f%*c%f%*c%f%*c%f%*c",
        &cand.moyenneCandidat.maths,
        &cand.moyenneCandidat.fran,
        &cand.moyenneCandidat.angl,
        &cand.moyenneCandidat.spe);
    fscanf(fe, "%ld%*c", &cand.nbChoix);
    for (int i = 0; i < cand.nbChoix; i++) {
        fscanf(fe, "%s%*c", cand.choix[i].ville.VilleDep);
        fscanf(fe, "%s%*c", cand.choix[i].departement);
        fscanf(fe, "%d%*c", (int *)&cand.choix[i].decision);
        fscanf(fe, "%d%*c", (int *)&cand.choix[i].validation);
    }

    return cand;
}

void ecrireCand(FILE *fe, Candidature cand)
{
    fprintf(fe, "\n%d\n", cand.idCandidat);
    fprintf(fe, "%s\n", cand.nomCandidat);
    fprintf(fe, "%s\n", cand.prenomCandidat);
    fprintf(fe, "%.2f %.2f %.2f %.2f\n",
        cand.moyenneCandidat.maths,
        cand.moyenneCandidat.fran,
        cand.moyenneCandidat.angl,
        cand.moyenneCandidat.spe);
    fprintf(fe, "%d\n", (int)cand.nbChoix);
    for (int i = 0; i < cand.nbChoix; i++) {
        fprintf(fe, "%s\n", cand.choix[i].ville.VilleDep);
        fprintf(fe, "%s\n", cand.choix[i].departement);
        fprintf(fe, "%d\n", (int)cand.choix[i].decision);
        fprintf(fe, "%d\n", (int)cand.choix[i].validation);
    }
}

int chargementCand(Candidature *tcand[], size_t *nbcand, size_t *curralloc, uint *idmax, const char *nomfichier)
{
    FILE *fe = fopen(nomfichier, "r");
    if (fe == NULL) exit( err(ERR_INVALID_FILE, chargementCand) );
    Candidature *cand;

    size_t nbcandfichier; *nbcand = 0;
    fscanf(fe, "%ld%*c", &nbcandfichier);
    if (nbcandfichier > MAX_CANDIDATURES) {
        exit( err(ERR_TAB_FULL, chargementCand) );
    }
    if (nbcandfichier > *curralloc) {
        *curralloc = (nbcandfichier/MALLOC_DYN_INC +1) * MALLOC_DYN_INC;
        tcand = realloc(tcand, sizeof(Candidature) * (*curralloc));
        if (tcand == NULL) exit( err(ERR_NULL_MALLOC, chargementCand) );
    }

    int i;
    for (i = 0; i < nbcandfichier; i++) {
        cand = initCanditature();
        *cand = lireCand(fe);
        ajouterCandidature(tcand, nbcand, curralloc, cand);
        *idmax = max(*idmax, cand->idCandidat);
    }

    if (!feof(fe) || *nbcand != nbcandfichier) {
        fclose(fe);
        return err(ERR_NB_ELEM, chargementCand);
    }

    fclose(fe);
    return OK;
}

int sauvegardeCand(Candidature *tcand[], size_t nbcand, const char *nomfichier)
{
    FILE *fe = fopen(nomfichier, "w");
    if (fe == NULL) exit( err(ERR_INVALID_FILE, chargementCand) );

    fprintf(fe, "%ld", nbcand);

    int i;
    for (i = 0; i < nbcand; i++) {
        ecrireCand(fe, *tcand[i]);  
    }

    fclose(fe);
    return OK;
}