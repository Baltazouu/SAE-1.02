/**
 * @file test.c
 * @author Alexandre Agostinho
 * @brief tests unitaires
 * @version 0.1
 * @date 2022-12-16
 * 
 *  SAE 1.02 - Comparaison d'approches algorithmiques
 */

#include <string.h>

#include "acutest.h"
#include "config.h"
#include "errors.h"
#include "candidature_utils.h"

/**
 * @brief Macro de test
 * 
 *  Permet de racourcir la syntaxe des tests unitaires.
 *  Renvoie le message d'expectation si la condition n'est pas vérifiée.
 *
 * @param cond condition à tester
 * @param msg message d'erreur
 * @param ret valeur de retour
 * @param expt valeur attendue
 */
#define TEST(cond, msg, ret, expt) ({                       \
    TEST_CHECK_(cond, msg);                                 \
    TEST_MSG("return: " #ret "", expected: %d");        \
})

void test_chargeCandidaturesTxt(void) {
    Candidature *tcand = NULL;
    int nbCand = 0;

    int ret = chargeCandidaturesTxt(tcand, &nbCand, "data/candidatures.txt");

    TEST_ASSERT_(ret != -ERR_NOT_IMPLEMENTED, "test not implemented");

    // general errors

    TEST(ret != -ERR_INVALID_FILE, "test invalid file", ret, ERR_INVALID_FILE);
    TEST(ret != -ERR_INVALID_FILE_FORMAT, "test invalid file format", ret, ERR_INVALID_FILE_FORMAT);
    TEST(ret != -ERR_NULL_MALLOC, "test null malloc", ret, ERR_NULL_MALLOC);
    TEST(ret != -ERR_TAB_FULL, "test tab full", ret, ERR_TAB_FULL);

    TEST(nbCand == ret, "test logic size", nbCand, ret);

    // specific errors

    TEST(nbCand == 2, "test file logic size", nbCand, 2);
    TEST(tcand[0].numCand == 1, "test numCand", tcand[0].numCand, 1);
    TEST(!strcmp(tcand[0].nom, "Durand"), "test name", tcand[0].nom, "Durand");
    TEST(!strcmp(tcand[0].prenom, "Jean Jaques"), "test surname", tcand[0].prenom, "Jean Jaques");
    TEST(tcand[0].moy[2] == 12.25, "test moy", tcand[0].moy[2], 12.25);
    TEST(tcand[0].nbChoix == 3, "test nbChoix", tcand[0].nbChoix, 3);
    TEST(tcand[0].choix[1].numChoix == 2, "test num choix", tcand[0].choix[1].numChoix, 2);
    TEST(!strcmp(tcand[0].choix[1].villeChoisie, "Grenoble"), "test choix", tcand[0].choix[1].villeChoisie, "Grenoble");
    TEST(!strcmp(tcand[0].choix[1].dept, "Isere"), "test dept", tcand[0].choix[1].dept, "Isere");
    TEST(tcand[0].choix[1].decs == ADMIS, "test decision", tcand[0].choix[1].decs, ADMIS);

    TEST(tcand[0].choix[1].validation == false, "test validation", tcand[0].choix[1].validation, false);
}


TEST_LIST = {
    { "test chargeCandidaturesTxt", test_chargeCandidaturesTxt },
    { NULL, NULL }
};
