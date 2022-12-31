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

#define TEST(cond, msg, ret, expt) {(                       \
    if (!TEST_CHECK_(cond, msg)) {                          \
        TEST_MSG("return: %d, expected: %d", ret, expt);    \
    }                                                       \
)}

void test_chargeCandidaturesTxt(void) {
    Candidature *tcand = NULL;
    int nbCand = 0;

    int ret = chargeCandidaturesTxt(tcand, &nbCand, "data/candidatures.txt");

    TEST_ASSERT_(ret != -ERR_NOT_IMPLEMENTED, "test not implemented");

    // general errors

    TEST_CHECK_(ret != -ERR_INVALID_FILE, "test invalid file");
    TEST_CHECK_(ret != -ERR_INVALID_FILE_FORMAT, "test invalid file format");
    TEST_CHECK_(ret != -ERR_NULL_MALLOC, "test null malloc");
    TEST_CHECK_(ret != -ERR_TAB_FULL, "test tab full");

    TEST_CHECK_(nbCand == ret, "test logic size");

    // specific errors

    TEST_CHECK_(nbCand == 2, "test file logic size"); TEST
    TEST_CHECK_(tcand[0].numCand == 1, "test numCand");
    TEST_CHECK_(!strcmp(tcand[0].nom, "Durand"), "test name");
    TEST_CHECK_(!strcmp(tcand[0].prenom, "Jean Jaques"), "test surname");
    TEST_CHECK_(tcand[0].moy[2] == 12.25, "test moy");
    TEST_CHECK_(tcand[0].nbChoix == 3, "test nbChoix");
    TEST_CHECK_(tcand[0].choix[1].numChoix == 2, "test num choix");
    TEST_CHECK_(!strcmp(tcand[0].choix[1].villeChoisie, "Grenoble"), "test choix");
    TEST_CHECK_(!strcmp(tcand[0].choix[1].dept, "Isere"), "test dept");
    TEST_CHECK_(tcand[0].choix[1].decs == ADMIS, "test decision");
    TEST_CHECK_(tcand[0].choix[1].validation == false, "test validation");
}


TEST_LIST = {
    {NULL, NULL}
};
