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
void test_initCandListe(void)
{
    CandListe candl = initCandListe();
    TEST_CHECK_(candl == NULL, "test initCandListe return NULL");
    TEST_MSG("initCandListe need to return NULL");
}

/**
 * @brief Test de la fonction addCand
 */
void test_addCand(void)
{
    CandListe candl = initCandListe();
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

    candl = addCand(candl, cand);

    // Tests returns NULL ptr
    TEST_CHECK_(candl != NULL, "test candl != NULL");
    TEST_MSG("addCand candl can't return NULL");

    TEST_CHECK_(candl->suiv == NULL, "test ->suiv == NULL");
    TEST_MSG("addCand candl->suiv need to return NULL");

    // Tests acces correct
    TEST_CHECK_(!strcmp(candl->cand.nom, "test"), "test acess correct");
    TEST_MSG("returned: %s", candl->cand.nom);
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
    candl = addCand(candl, cand2);

    TEST_CHECK_(candl->suiv != NULL, "test candl->suiv->suiv != NULL");
    TEST_MSG("addCand candl->suiv can't return NULL");

    TEST_CHECK_(candl->suiv->suiv == NULL, "test ->suiv->suiv == NULL");
    TEST_MSG("addCand candl->suiv->suiv need to return NULL");

    // Tests order
    TEST_CHECK_(candl->suiv->cand.numCand == 1, "test order");
    TEST_MSG("returned: %d", candl->suiv->cand.numCand);
    TEST_MSG("expected: %d", 1);
}

/**
 * @brief Test de la fonction suppCand
 */
void test_suppCand(void)
{
    // Create list
    CandListe candl = initCandListe();
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

    candl = addCand(candl, cand1);
    
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

    candl = addCand(candl, cand2);
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

    candl = addCand(candl, cand3);

    // Test delete cand2
    supprCand(candl, 2);

    TEST_CHECK_(candl->suiv->cand.numCand == 1, "test delete cand2");
    TEST_MSG("returned: %d", candl->suiv->cand.numCand);
    TEST_MSG("expected: %d", 1);

    // Test delete cand1
    supprCand(candl, 1);

    TEST_CHECK_(candl->cand.numCand == 1, "test delete cand1");
    TEST_MSG("returned: %d", candl->cand.numCand);
    TEST_MSG("expected: %d", 1);

    // Test cand3->suiv == NULL
    TEST_CHECK_(candl->suiv == NULL, "test cand3->suiv == NULL");
    TEST_MSG("returned: %p", candl->suiv);
    TEST_MSG("expected: %p", NULL);

    // Test delete cand3
    supprCand(candl, 3);

    TEST_CHECK_(candl->cand.numCand == 3, "test delete cand1");
    TEST_MSG("returned: %d", candl->cand.numCand);
    TEST_MSG("expected: %d", 3);

    // Test candl == NULL
    TEST_CHECK_(candl == NULL, "test candl == NULL");
    TEST_MSG("returned: %p", candl);
    TEST_MSG("expected: %p", NULL);
}

/**
 * @brief Test de la fonction chargCand_TXT
 */
void test_chargCand_TXT(void)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, "test_chargCand_TXT");
    TEST_ASSERT_(0, "test_chargCand_TXT");
}

/**
 * @brief Test de la fonction chargCand_BIN
 */
void test_chargCand_BIN(void)
{
    // TODO
    err(ERR_NOT_IMPLEMENTED, "test_chargCand_BIN");
    TEST_ASSERT_(0, "test_chargCand_BIN");
}


TEST_LIST = {
    { "initCandListe", test_initCandListe },
    { "addCand", test_addCand },
    { "suppCand", test_suppCand },
    { "chargCand_TXT", test_chargCand_TXT },
    { "chargCand_BIN", test_chargCand_BIN },
    {NULL, NULL}
};
