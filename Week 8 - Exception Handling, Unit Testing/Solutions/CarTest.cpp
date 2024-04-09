#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <Car.cpp>
#include <doctest.h>
#include <cstring>

TEST_CASE("Test constructor")
{
    Car a("Renault", "Scenic", 200);
    CHECK(strcmp(a.getBrand(), "Renault") == 0);
    CHECK(strcmp(a.getModel(), "Scenic") == 0);
    CHECK_EQ(a.getAvgSpeed(), 200);
    CHECK_EQ(a.getDistance(), 0);
}
TEST_CASE("Test Drive")
{

    Car a("Renault", "Scenic", 50);
    int res = a.drive(50);
    CHECK_EQ(res, 1);
    CHECK_EQ(a.getDistance(), 50);
    a.drive(50);
    int res2 = a.drive(98);
    CHECK_EQ(res2, 2);
}
TEST_CASE("operator==")
{
    Car a("Renault", "Scenic", 200);
    Car b("Renault", "Scenic", 300);
    Car c("Opel", "Vectra", 20);
    CHECK_EQ(a,b);
    CHECK(!(a == c));
}