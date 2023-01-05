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


/** DEFINE STYLES */

//! Bordures d'affichage
// UTF-8 char
#define BOX_HORI    "\u2501"
#define BOX_VERT    "\u2503"
#define BOX_TOPL    "\u250f"
#define BOX_TOPR    "\u2513"
#define BOX_BOTL    "\u2517"
#define BOX_BOTR    "\u251b"
#define BOX_VERR    "\u2523"
#define BOX_VERL    "\u252b"
#define BOX_UPHO    "\u253b"
#define BOX_VERH    "\u254b"
#define BOX_DOWH    "\u2533"

//! Styles  
//  (ANSI Escape Sequances) - https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
#define STY_NULL    "\e[0m"
#define STY_BOLD    "\e[1m"
#define STY_FCYAN   "\e[1;36m"
#define STY_FGREEN  "\e[1;32m"
#define STY_FRED    "\e[1;31m"
#define STY_FMAGEN  "\e[1;35m"
#define STY_FBLUE   "\e[1;34m"
#define STY_FYELLOW "\e[1;33m"
#define STY_BWHITE  "\e[1;30;47m"

//! Clear screen
#define CLEAR_CMD "\e[1;1H\e[2J"


// PARTIE 3 - Options des admissions




#endif /* CONFIG_H */