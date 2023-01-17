/**
 * @file candidature_affichage.c
 * @author Alexandre Agostinho
 * @brief Code source - Fonctions d'affichages pour partie 2 : Candidatures
 * @date 2023-01-04
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */


#include <stdio.h>
#include <string.h>

#include "candidature.h"


/* AFFICHAGE DES MENUS */

void afficherMenuCandidatureEtu(void)
{
    const char menu[] =
        STY_BOLD STY_FCYAN "\tMenu Candidature\t\t[ ETU ]\n\n" STY_FYELLOW
        STY_BOLD "\t[ 1 ] " STY_NULL STY_FYELLOW " Ajouter une candidature\n"
        STY_BOLD "\t[ 2 ] " STY_NULL STY_FYELLOW " Supprimer une candidature\n"
        STY_BOLD "\t[ 3 ] " STY_NULL STY_FYELLOW " Modifier une candidature\n" STY_FMAGEN
        STY_BOLD "\t[ 4 ] " STY_NULL STY_FMAGEN " Afficher les candidatures\n"
        STY_BOLD "\t[ 5 ] " STY_NULL STY_FMAGEN " Sauvegarder les candidatures\n" STY_FBLUE
        STY_BOLD "\t[ 6 ] " STY_NULL STY_FBLUE " Traitement des dossiers de candidatures\n"
        STY_BOLD "\t[ 7 ] " STY_NULL STY_FBLUE " Quitter\n\n"
        STY_NULL;

    printf( menu );
}

void afficherMenuCandidatureAdmin(void)
{
    const char menu[] =
        "\tMenu Candidature\t\t[ ADMIN ]\n\n"
        "\t[ 1 ]  Voir toutes les candidatures\n"
        "\t[ 2 ]  Stopper la phase d'admission\n\n";

    printf( menu );
}

void afficherMenuAjoutCandidature(Candidature cand, const char *fin)
{
    const char menu[] =
        "\tEdition d'une candidature\t\t[ ETU ]\n\n"
        "\t[ 1 ]  Modifier 'Nom'\n"
        "\t[ 2 ]  Modifier 'Prenom'\n"
        "\t[ 3 ]  Modifier 'Moyennes'\n"
        "\t[ 4 ]  Ajouter une candidature\n"
        "\t[ 5 ]  Enregistrer\n"
        "\t[ 6 ]  %s\n"
        "\n"
        "Informations candidature :\n\n";

    printf( menu, fin );
    affichageInfoCandidat(cand);
    affichageCandidatureSaisie(cand);
}


/* AFFICHAGES UTILITAIRES (avec des infos en plus) */

void affichageInfoCandidat(Candidature cand)
{
    const char info[] =
        "       ID:   %d\n"
        "      Nom:   %s\n"
        "   Prenom:   %s\n"
        " Moyennes: [ maths, français, anglais, spé ]\n"
        "           [ %.2f,  %.2f,  %.2f,  %.2f ]\n\n";

    printf( info, cand.idCandidat,
        cand.nomCandidat, cand.prenomCandidat,
        cand.moyenneCandidat.maths,
        cand.moyenneCandidat.fran,
        cand.moyenneCandidat.angl,
        cand.moyenneCandidat.spe);
}

void affichageCandidatureSaisie(Candidature cand)
{
    const char info[] =
        "[ Choix n°%d ]\n"
        "       Ville:  %s\n"
        " Département:  %s\n\n";

    if (cand.nbChoix == 0) {
        printf("( Aucun choix encore fait... )\n\n");
        return;
    }

    for (int i; i < cand.nbChoix; i++) {
        printf( info, i+1,
            cand.choix[i].ville.VilleDep,
            cand.choix[i].departement );
    }
}

int affichageToutCandidats(Candidature *tcand[], size_t nbCand)
{
    const char entete[] = "\n[ Liste candidats ]\n\n";
    const char ligne[]  = " -  [ %d ] %s %s \t\t(NC: %ld)\n";

    printf( entete );

    int i;
    for (i = 0; i < nbCand; i++) {
        printf( ligne,
            tcand[i]->idCandidat,
            tcand[i]->nomCandidat,
            tcand[i]->prenomCandidat,
            tcand[i]->nbChoix );
    }

    printf("\n\n");
    return i;
}