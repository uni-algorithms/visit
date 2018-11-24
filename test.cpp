#define CATCH_CONFIG_MAIN

#include <catch.hpp>
#include "visit.hpp"

TEST_CASE("circular graph") {
    graph g = {{0, {1}},
               {1, {2}},
               {2, {3}},
               {3, {4}},
               {4, {0}},};

    std::unordered_set<node> expected = {0, 1, 2, 3, 4};

    REQUIRE(dfs(g, 0) == expected.size());
}

TEST_CASE("test provided") {
    graph g = {{0, {2, 4}},
               {1, {4}},
               {2, {4}},
               {3, {2}},
               {4, {3}},};

    std::unordered_set<node> expected = {1, 2, 3, 4};

    REQUIRE(dfs(g, 1) == expected.size());
}

TEST_CASE("from_stream should work") {
    graph expected = {{0, {2, 4}},
                      {1, {4}},
                      {2, {4}},
                      {3, {2}},
                      {4, {3}},};

    std::stringstream in("0 2\n"
                         "0 4\n"
                         "1 4\n"
                         "3 2\n"
                         "2 4\n"
                         "4 3");

    graph actual;
    from_stream(actual, in, 5, 6);

    REQUIRE(actual == expected);
}