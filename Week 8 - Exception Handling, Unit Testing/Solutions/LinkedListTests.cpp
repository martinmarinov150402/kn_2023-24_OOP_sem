#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <LinkedList.cpp>

TEST_CASE("Test add in linked list")
{
    SUBCASE("Add 5 and get it")
    {
        LinkedList<int> a;
        a.add(5);
        CHECK_EQ(a.getHead(), 5);
    }
    SUBCASE("Add 6 and get it")
    {
        LinkedList<int> a;
        a.add(6);
        CHECK_EQ(a.getHead(), 6);
    }
}
TEST_CASE("Test get node on index in linked list")
{
    LinkedList<int> a;
    for(int i = 1; i <= 6; i++)
    {
        a.add(i);
    }

    SUBCASE("Get element on index 0")
    {
        CHECK_EQ(a.getAt(0), 1);
    }
    SUBCASE("Get element on index 4")
    {
        CHECK_EQ(a.getAt(4), 5);
    }
    SUBCASE("Get element on index 2")
    {
        CHECK_EQ(a.getAt(2), 3);
    }
}
TEST_CASE("Test remove first")
{
    LinkedList<int> a;
    for(int i = 1; i <= 6; i++)
    {
        a.add(i);
    }
    a.removeFirst();
    CHECK_EQ(a.getAt(0), 2);
}
TEST_CASE("Test remove last")
{
    LinkedList<int> a;
    for(int i = 1; i <= 6; i++)
    {
        a.add(i);
    }
    a.removeLast();
    for(int i = 0; i < 5; i++)
    {
        CHECK_EQ(a.getAt(i), i + 1);
    }
    CHECK_THROWS(a.getAt(5));
}
