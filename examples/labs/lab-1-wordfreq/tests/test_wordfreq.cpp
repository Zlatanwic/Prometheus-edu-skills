#include <catch2/catch_test_macros.hpp>

#include "wordfreq.hpp"

#include <sstream>

using namespace wordfreq;

TEST_CASE("tokenize splits on non-alpha", "[tokenize]") {
    Options opts;
    auto w = tokenize("The quick, brown fox!", opts);
    REQUIRE(w == std::vector<std::string>{"The", "quick", "brown", "fox"});
}

TEST_CASE("tokenize respects min_length", "[tokenize]") {
    Options opts; opts.min_length = 4;
    auto w = tokenize("a bb ccc dddd eeeee", opts);
    REQUIRE(w == std::vector<std::string>{"dddd", "eeeee"});
}

TEST_CASE("tokenize respects ignore_case", "[tokenize]") {
    Options opts; opts.ignore_case = true;
    auto w = tokenize("The THE the", opts);
    REQUIRE(w == std::vector<std::string>{"the", "the", "the"});
}

TEST_CASE("tokenize handles empty and pure punctuation", "[tokenize]") {
    Options opts;
    REQUIRE(tokenize("", opts).empty());
    REQUIRE(tokenize("... !!! ???", opts).empty());
}

TEST_CASE("count counts occurrences", "[count]") {
    auto c = count({"a", "b", "a", "c", "b", "a"});
    REQUIRE(c["a"] == 3);
    REQUIRE(c["b"] == 2);
    REQUIRE(c["c"] == 1);
}

TEST_CASE("top_k orders by count desc then lex asc", "[topk]") {
    std::unordered_map<std::string, std::size_t> c{
        {"apple", 3}, {"banana", 5}, {"cherry", 3}, {"date", 5}
    };
    auto r = top_k(c, 4);
    REQUIRE(r.size() == 4);
    REQUIRE(r[0] == std::pair<std::string, std::size_t>{"banana", 5});
    REQUIRE(r[1] == std::pair<std::string, std::size_t>{"date", 5});
    REQUIRE(r[2] == std::pair<std::string, std::size_t>{"apple", 3});
    REQUIRE(r[3] == std::pair<std::string, std::size_t>{"cherry", 3});
}

TEST_CASE("top_k truncates to k", "[topk]") {
    std::unordered_map<std::string, std::size_t> c{
        {"a", 1}, {"b", 2}, {"c", 3}
    };
    auto r = top_k(c, 2);
    REQUIRE(r.size() == 2);
    REQUIRE(r[0].first == "c");
    REQUIRE(r[1].first == "b");
}

TEST_CASE("render produces expected histogram", "[render]") {
    std::vector<std::pair<std::string, std::size_t>> r{{"the", 4}, {"a", 2}};
    std::ostringstream out;
    render(out, r);
    auto text = out.str();
    REQUIRE(text.find("the") == 0);
    REQUIRE(text.find("4") != std::string::npos);
    REQUIRE(text.find("########################################") != std::string::npos);
    // second line's bar is half (20 #)
    REQUIRE(text.find("####################\n") != std::string::npos);
}
