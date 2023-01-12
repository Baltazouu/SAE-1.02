#ifndef PART3_UTILITAIRE_H
#define PART3_UTILITAIRE_H
/**
 * @file part3_utilitaire.h
 * @author Dudonné Baptiste
 * @brief fonctions utilitaires partie 3
 * @version 0.1
 * @date 2023-01-05
 */

#include"struct.h"

/**
 * @brief fonction qui verifie si un candidat a candidate dans la ville et le departement recherche
 * @param choix tableau des choix du candidat
 * @param nbchoix nombre de choix du candidat
 * @param ville ville recherchee
 * @param dept departement recherche
 * @return int 1 si le candidat a candidate dans la ville et le departement recherche, 0 sinon
 */
int FrechChoix(Choix *choix,int nbchoix,char *ville,char *dept);

/**
 * @brief fonction qui permet de copier un maillon de la liste des candidats
 * @param cand maillon de la liste des candidats
 * @return le nouveau maillon cree 
 */
MaillonCandidat* copieMaillon(Candidature cand);

/**
 * @brief FOnction qui calcule la moyenne d'un candidat
 * @param cand candidature du candidat
 * @return la moyenne du candidat
 */
float FcalculMoyenne(Candidature cand);


/**
 * @brief fonction qui permet de trier les candidats par ordre croissant de rang
 * @param list liste des candidats en attente
 * @param cand candidature du candidat
 * @return la liste des candidats triee par ordre croissant de moyenne
 */
ListAttente FonctionInsertionCroissanteAtt(ListAttente list,Candidature cand);

/**
 * @brief fonction qui permet de trier les candidats par ordre croissant de rang
 * @param list liste des candidats
 * @param cand candidature du candidat
 * @return la liste des candidats triee par ordre croissant de moyenne
 */
ListAdmis FonctionInsertionCroissante(ListAdmis list,Candidature cand,ListAttente listatt,int noteAttente);



#endif