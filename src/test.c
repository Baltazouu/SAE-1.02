#include "acutest.h"
#include "add.h"

void test_add(void)
{
    int expected[] = { 2, 4, 7, -2, 0 };
    int returned[] = {
        add(1, 1),
        add(2, 2),
        add(1, 2),
        add(-4, 3),
        add(-4, 4)
    };

    for (int i = 0; i < 5; i++) {
        TEST_CHECK_(returned[i] == expected[i], "add(%d)", i);
        TEST_MSG("Expected: %d", expected[i]);
        TEST_MSG("Returned: %d", returned[i]);
    }
}

void test_supp(void)
{
    int expected = 1;
    int returned = supp(3, 2);
    TEST_CHECK_(returned==1, "supp(3, 2)");

    TEST_MSG("Expected: %d", expected);
    TEST_MSG("Returned: %d", returned);
}


TEST_LIST = {
    { "int add(int, int);", test_add },
    { "int supp(int, int);", test_supp },
    {0}
};
