#include <catch2/catch_test_macros.hpp>
#include "stats.hpp"
#include <cmath>

using namespace csvstat;

TEST_CASE("numeric classification basic", "[stats]") {
    auto s = summarize_column({"1","2","3","4"});
    auto* n = std::get_if<NumericStats>(&s);
    REQUIRE(n != nullptr);
    REQUIRE(n->count == 4);
    REQUIRE(n->missing == 0);
    REQUIRE(n->min == 1);
    REQUIRE(n->max == 4);
    REQUIRE(n->mean == 2.5);
}

TEST_CASE("numeric with missing", "[stats]") {
    auto s = summarize_column({"1","","2"});
    auto* n = std::get_if<NumericStats>(&s);
    REQUIRE(n != nullptr);
    REQUIRE(n->count == 2);
    REQUIRE(n->missing == 1);
    REQUIRE(n->mean == 1.5);
}

TEST_CASE("text when any non-empty is non-numeric", "[stats]") {
    auto s = summarize_column({"1","2","hello"});
    REQUIRE(std::holds_alternative<TextStats>(s));
}

TEST_CASE("text distinct and top", "[stats]") {
    auto s = summarize_column({"a","b","a","c","a","b"});
    auto* t = std::get_if<TextStats>(&s);
    REQUIRE(t != nullptr);
    REQUIRE(t->distinct == 3);
    REQUIRE(t->top[0].first == "a");
    REQUIRE(t->top[0].second == 3);
    REQUIRE(t->top[1].first == "b");
}

TEST_CASE("text top caps at 3", "[stats]") {
    auto s = summarize_column({"a","b","c","d","e"});
    auto* t = std::get_if<TextStats>(&s);
    REQUIRE(t != nullptr);
    REQUIRE(t->top.size() == 3);
}

TEST_CASE("stddev single value is zero", "[stats]") {
    auto s = summarize_column({"5"});
    auto* n = std::get_if<NumericStats>(&s);
    REQUIRE(n != nullptr);
    REQUIRE(n->stddev == 0.0);
}

TEST_CASE("all missing is text with zero count", "[stats]") {
    auto s = summarize_column({"","",""});
    auto* t = std::get_if<TextStats>(&s);
    REQUIRE(t != nullptr);
    REQUIRE(t->count == 0);
    REQUIRE(t->missing == 3);
}
