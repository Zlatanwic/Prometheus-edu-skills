#include <catch2/catch_test_macros.hpp>
#include "parser.hpp"
#include <sstream>

using namespace csvstat;

static CsvFile parse_str(const std::string& s, bool h = true) {
    std::istringstream in(s);
    return parse(in, h);
}

TEST_CASE("simple csv", "[parser]") {
    auto f = parse_str("a,b,c\n1,2,3\n4,5,6\n");
    REQUIRE(f.header == std::vector<std::string>{"a","b","c"});
    REQUIRE(f.rows.size() == 2);
    REQUIRE(f.rows[0].fields == std::vector<std::string>{"1","2","3"});
}

TEST_CASE("no trailing newline", "[parser]") {
    auto f = parse_str("a,b\n1,2");
    REQUIRE(f.rows.size() == 1);
    REQUIRE(f.rows[0].fields[1] == "2");
}

TEST_CASE("quoted fields with commas", "[parser]") {
    auto f = parse_str("a,b\n\"hello, world\",2\n");
    REQUIRE(f.rows[0].fields[0] == "hello, world");
    REQUIRE(f.rows[0].fields[1] == "2");
}

TEST_CASE("escaped quote inside quoted field", "[parser]") {
    auto f = parse_str("a\n\"she said \"\"hi\"\"\"\n");
    REQUIRE(f.rows[0].fields[0] == "she said \"hi\"");
}

TEST_CASE("crlf line endings", "[parser]") {
    auto f = parse_str("a,b\r\n1,2\r\n");
    REQUIRE(f.rows.size() == 1);
    REQUIRE(f.rows[0].fields[1] == "2");
}

TEST_CASE("no-header mode", "[parser]") {
    auto f = parse_str("1,2\n3,4\n", false);
    REQUIRE(f.header.empty());
    REQUIRE(f.rows.size() == 2);
}

TEST_CASE("unterminated quote throws", "[parser]") {
    REQUIRE_THROWS_AS(parse_str("a\n\"oops\n"), CsvError);
}
