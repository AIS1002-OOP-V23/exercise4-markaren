
#include "ais1002/exercise1.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("1: Shared string") {
    std::string original{"Hei"};
    auto str = std::make_unique<std::string>(original);

    REQUIRE_NOTHROW([&] {
        auto [str1, str2] = ais1002::shareMe(str);

        CHECK(original == str1.str());
        CHECK(original == str2.str());

        std::string update{"Heihei"};
        str1.update(update);

        CHECK(update == str1.str());
        CHECK(update == str2.str());
    }());
}
