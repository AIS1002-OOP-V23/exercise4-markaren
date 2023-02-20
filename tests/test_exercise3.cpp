
#include "ais1002/exercise3.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE("1: Memory consumer") {

    unsigned int maxCacheSize = 5;
    ais1002::URLFetcher crawler(maxCacheSize);

    int gets = 10;
    for (int i = 0; i < gets; i++) {
        crawler.getContent(std::to_string(i));
    }
    for (int i = gets-1; 0 <= i; --i) {
        crawler.getContent(std::to_string(i));
    }

    CHECK(maxCacheSize == crawler.actualCacheSize());
    CHECK(maxCacheSize == crawler.numCacheHits());

}
