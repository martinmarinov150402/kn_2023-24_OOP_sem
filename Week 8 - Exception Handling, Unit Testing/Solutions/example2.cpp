#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

int factorial(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

TEST_CASE("Test factorial")
{
    SUBCASE("Test with 0 factorial")
    {
        CHECK_EQ(factorial(0), 1);
    }
    SUBCASE("Test with 1")
    {
        CHECK_EQ(factorial(1), 1);
    }
    SUBCASE("Test with 5")
    {
        CHECK_EQ(factorial(5), 120);
    }
    SUBCASE("Test with 6")
    {
        CHECK_EQ(factorial(6), 720);
    }
}