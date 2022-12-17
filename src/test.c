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
 * @brief Test de la fonction initCandListe
 */
void test_initCandFile(void)
{
    CandFile candf = initCandFile();
    TEST_CHECK_(candf.head == NULL, "test initCandFile candf.head return NULL");
    TEST_MSG("candf.head need to return NULL");
    TEST_CHECK_(candf.tail == NULL, "test initCandFile candf.tail return NULL");
    TEST_MSG("candf.tail need to return NULL");
}

/**
 * @brief Test de la fonction addCand
 */
void test_enqueueCand(void)
{
    CandFile candf = initCandFile();
    Candidature cand = {
        1,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    candf = enqueueCand(candf, cand);

    // Tests returns NULL ptr
    TEST_CHECK_(candf.head != NULL, "test candf != NULL");
    TEST_MSG("enqueue candf.head can't return NULL");

    TEST_CHECK_(candf.tail != NULL, "test ->suiv == NULL");
    TEST_MSG("enqueue candf.tail cant' return NULL");

    // Tests acces correct
    TEST_CHECK_(!strcmp(candf.head->cand.nom, "test"), "test acess correct");
    TEST_MSG("returned: %s", candf.head->cand.nom);
    TEST_MSG("expected: %s", "test");

    // Tests returns NULL ptr of new element
    Candidature cand2 = {
        2,
        "test2",
        "pretest2",
        { 13.2, 15.8, 12.6, 10.2 },
        3,
        {
            { "testVille1", "testDept2", REFUSE },
            { "testVille2", "testDept2", ADMIS},
            { "testVille3", "testDept3", LISTE_ATTENTE }
        }
    };
    candf = enqueueCand(candf, cand2);

    TEST_CHECK_(candf.head->suiv != NULL, "test candf.head->suiv != NULL");
    TEST_MSG("enqueue candf.head->suiv can't return NULL");

    TEST_CHECK_(candf.head->suiv->suiv == NULL, "test candf.head->suiv->suiv == NULL");
    TEST_MSG("enqueue candf.head->suiv->suiv need to return NULL");

    TEST_CHECK_(candf.tail != candf.head->suiv, "test candf.tail != canf.head->suiv");
    TEST_MSG("enqueue candf.tail can't be the same as candf.head->suiv");

    // Tests order
    TEST_CHECK_(candf.head->cand.numCand == 1, "test order");
    TEST_MSG("returned: %d", candf.head->cand.numCand);
    TEST_MSG("expected: %d", 1);
}


/**
 * @brief Test de la fonction dequeueCand
 */
void test_dequeueCand(void)
{
    // Create list
    CandFile candf = initCandFile();
    Candidature cand1 = {
        1,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    candf = enqueueCand(candf, cand1);
    
    Candidature cand2 = {
        2,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    // Test null ptr
    TEST_CHECK_(candf.head->suiv->suiv == NULL, "test candf.head->suiv->suiv == NULL");
    TEST_MSG("candf.head->suiv->suiv must be NULL");

    // Test order
    TEST_CHECK_(candf.head->cand.numCand == 2, "test order");
    TEST_MSG("returned: %d", candf.head->cand.numCand);
    TEST_MSG("expected: %d", 1);
}

/**
 * @brief Test de la fonction suppCand
 */
void test_suppCand(void)
{
    // Create list
    CandFile candf = initCandFile();
    Candidature cand1 = {
        1,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    candf = enqueueCand(candf, cand1);
    
    Candidature cand2 = {
        2,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    candf = enqueueCand(candf, cand2);
    Candidature cand3 = {
        3,
        "test",
        "pretest",
        { 12.2, 14.8, 11.6, 9.2 },
        2,
        {
            { "testVille1", "testDept1", ADMIS },
            { "testVille2", "testDept2", LISTE_ATTENTE }
        }
    };

    candf = enqueueCand(candf, cand3);

    // TODO
    err(ERR_NOT_IMPLEMENTED, "test_suppCand");
    TEST_ASSERT_(0, "suppCand not implemented");
}

/**
 * @brief Test de la fonction chargCand_TXT
 */
void test_chargCand_TXT(void)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, "test_chargCand_TXT");
    TEST_ASSERT_(0, "chargCand_TXT not implemented");
}

/**
 * @brief Test de la fonction chargCand_BIN
 */
void test_chargCand_BIN(void)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, "test_chargCand_BIN");
    TEST_ASSERT_(0, "chargCand_BIN not implemented");
}


TEST_LIST = {
    { "initCandFile", test_initCandFile },
    { "enqueueCand", test_enqueueCand },
    { "dequeueCand", test_dequeueCand },
    { "suppCand", test_suppCand },
    { "chargCand_TXT", test_chargCand_TXT },
    { "chargCand_BIN", test_chargCand_BIN },
    {NULL, NULL}
};
