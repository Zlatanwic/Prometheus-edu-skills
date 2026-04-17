#pragma once
// Lab 2 — stats interface. DO NOT MODIFY.

#include <cstddef>
#include <string>
#include <utility>
#include <variant>
#include <vector>

namespace csvstat {

struct NumericStats {
    std::size_t count = 0, missing = 0;
    double min = 0, max = 0, mean = 0, stddev = 0;
};

struct TextStats {
    std::size_t count = 0, missing = 0, distinct = 0;
    std::vector<std::pair<std::string, std::size_t>> top;
};

using ColumnStats = std::variant<NumericStats, TextStats>;

ColumnStats summarize_column(const std::vector<std::string>& cells);

}  // namespace csvstat
