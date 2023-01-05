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

#include "candidature_affichage.h"


/* AFFICHAGE DES MENUS */

void afficherMenuCandidatureEtu(void)
{
    const char menu[] =
        "\tMenu Candidature\t\t[ ETU ]\n\n"
        "\t[ 1 ]  Ajouter une candidature\n"
        "\t[ 2 ]  Supprimer une candidature\n"
        "\t[ 3 ]  Modifier une candidature\n"
        "\t[ 4 ]  Afficher les candidatures\n"
        "\t[ 5 ]  Sauvegarder les candidatures\n"
        "\t[ 6 ]  Annuler\n"
        "\t[ 7 ]  Quitter\n";

    printf( menu );
}

void afficherMenuCandidatureAdmin(void)
{
    const char menu[] =
        "\tMenu Candidature\t\t[ ADMIN ]\n\n"
        "\t[ 1 ]  Voir toutes les candidatures\n"
        "\t[ 2 ]  Stopper la phase d'admission\n";

    printf( menu );
}

void afficherMenuAjoutCandidature(Candidature cand, size_t nbchoix)
{
    const char menu[] =
        "\tAjout d'une candidature\t\t[ ETU ]\n\n"
        "\t[ 1 ]  Modifier 'Nom'\n"
        "\t[ 2 ]  Modifier 'Prenom'\n"
        "\t[ 3 ]  Modifier 'Moyennes'\n"
        "\t[ 4 ]  Ajouter une candidature\n"
        "\n"
        "Informations candidature :\n\n";

    printf( menu );
    affichageInfoCandidat(cand);
    affichageCandidatureSaisie(cand, nbchoix);
}


/* AFFICHAGES UTILITAIRES */

void affichageInfoCandidat(Candidature cand)
{
    const char info[] =
        " Nom:\t%s\n"
        " Prenom:\t%s\n"
        " Moyennes [maths,français,anglais,spé]: [ %f, %f, %f, %f ]\n\n";

    printf( info,
        cand.nomCandidat, cand.prenomCandidat,
        cand.moyenneCandidat.maths,
        cand.moyenneCandidat.fran,
        cand.moyenneCandidat.angl,
        cand.moyenneCandidat.spe);
}

void affichageCandidatureSaisie(Candidature cand, size_t nbchoix)
{
    const char info[] =
        "[ Choix n°%d ]"
        " Ville:\t%s\n"
        " Département:\t%s\n\n";

    for (int i; i < nbchoix; i++) {
        printf( info, i,
            cand.choix[i].ville.VilleDep,
            cand.choix[i].departement );
    }
}