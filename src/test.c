#include "acutest.h"
#include "add.h"

void test_add(void)
{
    TEST_CHECK_(add(2, 2)==(2+2), "add(%d,%d)==%d", 2, 2, (2+2));
}

void test_supp(void)
{
    TEST_CHECK_(supp(3, 2)==(3-2), "supp(%d,%d)==%d", 3, 2, (3-2));
}


TEST_LIST = {
    { "int add(int, int);", test_add },
    { "int supp(int, int);", test_supp },
    {0}
};
