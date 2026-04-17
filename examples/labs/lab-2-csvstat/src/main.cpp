#include "parser.hpp"
#include "stats.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace csvstat {
void print_report(std::ostream&, const std::vector<std::string>&,
                  const std::vector<ColumnStats>&);
}

int main(int argc, char** argv) {
    bool has_header = true;
    std::string file;
    for (int i = 1; i < argc; ++i) {
        std::string_view a = argv[i];
        if (a == "--no-header") has_header = false;
        else if (!a.empty() && a[0] != '-') file = std::string(a);
    }
    if (file.empty()) { std::cerr << "usage: csvstat [--no-header] FILE\n"; return 2; }

    std::ifstream f(file);
    if (!f) { std::cerr << "cannot open " << file << '\n'; return 1; }

    try {
        auto csv = csvstat::parse(f, has_header);
        if (csv.rows.empty() && csv.header.empty()) { return 0; }

        std::size_t ncols = csv.header.empty()
            ? (csv.rows.empty() ? 0 : csv.rows.front().fields.size())
            : csv.header.size();

        std::vector<csvstat::ColumnStats> stats;
        stats.reserve(ncols);
        for (std::size_t c = 0; c < ncols; ++c) {
            std::vector<std::string> col;
            col.reserve(csv.rows.size());
            for (const auto& r : csv.rows) {
                col.push_back(c < r.fields.size() ? r.fields[c] : std::string());
            }
            stats.push_back(csvstat::summarize_column(col));
        }

        std::vector<std::string> names = csv.header;
        if (names.empty()) {
            for (std::size_t c = 0; c < ncols; ++c) names.push_back("col" + std::to_string(c));
        }
        csvstat::print_report(std::cout, names, stats);
    } catch (const csvstat::CsvError& e) {
        std::cerr << "csv error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
