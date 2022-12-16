#include <string.h>

#include "acutest.h"
#include "candidature_utils.h"


void test_initCand(void)
{
    Candidature* res = initCand("test", "pretest", { 12.2, 14.8, 11.6, 9.2 });

    TEST_CHECK_(res != NULL, "test nullptr");
    TEST_MSG("initCand return NULL ptr");

    TEST_CHECK_(strcmp(res->nom, "test"), "test nom");
    TEST_MSG("returned: %s", res->nom);
    TEST_MSG("expected: %s", "test");

    TEST_CHECK_(strcmp(res->prenom, "pretest"), "test prenom");
    TEST_MSG("returned: %s", res->prenom);
    TEST_MSG("expected: %s", "pretest");

    free(res);
}

void test_addCand(void)
{
    Candidature* cand = initCand("test", "pretest", { 12.2, 14.8, 11.6, 9.2 });
    cand->nom = "test";
    cand->prenom = "retest";
    int moy[4] = { 12.2, 14.8, 11.6, 9.2 };
    for (int i = 0; i < 4; i++) cand->moy[i] = moy[i];
}

void test_chargCand_TXT(void)
{
    Can
    CandListe = chargCand_TXT()
}


TEST_LIST = {
    { "Candidature initCand(void);", test_initCand },
    {NULL, NULL}
};
