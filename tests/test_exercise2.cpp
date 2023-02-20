
#include "ais1002/exercise2.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("1: Leaky object") {

    int a = 5;
    int b = 2;

    int add = ais1002::testWillCallThisFunction(a, b);

    REQUIRE(a+b == add);

    REQUIRE(0 == ais1002::MyClass::useCount);

}
