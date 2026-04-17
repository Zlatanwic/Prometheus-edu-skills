#pragma once
// Lab 2 — CSV parser public interface. DO NOT MODIFY.

#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

namespace csvstat {

struct CsvError : std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct CsvRow { std::vector<std::string> fields; };
struct CsvFile {
    std::vector<std::string> header;
    std::vector<CsvRow>      rows;
};

CsvFile parse(std::istream& in, bool has_header);

}  // namespace csvstat
