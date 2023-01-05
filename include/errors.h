/**
 * @file errors.h
 * @author Alexandre Agostinho
 * @brief Fonction et Macros utilitaire pour la gestion des erreurs
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#ifndef ERRORS_H
#define ERRORS_H

/**
 * @brief Enumération des codes d'erreurs
 */
typedef enum {
    OK = 0,                  /*!< OK */
    ERR_NULL_MALLOC,         /*!< Erreur d'allocation mémoire */
    ERR_NULL_LIST,           /*!< Liste vide */
    ERR_TAB_FULL,            /*!< Tableau plein */
    ERR_NOT_IMPLEMENTED,     /*!< Fonctionnalité non implémentée */
    ERR_INVALID_ARG,         /*!< Argument invalide */
    ERR_INVALID_FILE,        /*!< Fichier invalide */
    ERR_INVALID_FILE_FORMAT, /*!< Format de fichier invalide */
    ERR_INVALID_MENU_SELECT  /*!< Choix de menu invalid */
} ERR_CODE;

/**
 * @brief Affiche un message d'erreur
 *  (macro de fprintf sur la sortie d'erreur)
 *
 * @param errmsg message d'erreur
 */
#define eprintf(errmsg) fprintf(stderr, "\e[31m" errmsg "\e[0m\n")

/**
 * @brief Affiche un message d'erreur avec son code d'erreur re retourne le code d'erreur
 *
 * @param errcode code d'erreur
 * @param msg message d'erreur (optionnel) 
 */
#define err(errcode, fun) ({                            \
    if (errcode != OK)                                  \
        eprintf("error: " #errcode " on (" #fun ")");   \
    -errcode;                                           \
})


#endif /* ERRORS_H */