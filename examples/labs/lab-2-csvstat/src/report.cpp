// Rendering. You may edit this freely as long as the output matches README §2.

#include "parser.hpp"
#include "stats.hpp"

#include <format>
#include <iostream>
#include <string>
#include <vector>

namespace csvstat {

void print_report(std::ostream& out,
                  const std::vector<std::string>& names,
                  const std::vector<ColumnStats>& stats) {
    out << std::format("{:<12}{:<10}{:>5}  {:>7}  {}\n",
                       "column", "type", "count", "missing", "summary");
    out << std::string(72, '-') << '\n';
    for (std::size_t i = 0; i < names.size(); ++i) {
        const auto& name = names[i];
        std::visit([&](auto&& s) {
            using T = std::decay_t<decltype(s)>;
            if constexpr (std::is_same_v<T, NumericStats>) {
                out << std::format(
                    "{:<12}{:<10}{:>5}  {:>7}  min={:.2f} max={:.2f} mean={:.2f} stddev={:.2f}\n",
                    name, "numeric", s.count, s.missing, s.min, s.max, s.mean, s.stddev);
            } else {
                std::string top_str;
                for (std::size_t j = 0; j < s.top.size(); ++j) {
                    if (j) top_str += ",";
                    top_str += std::format("{}({})", s.top[j].first, s.top[j].second);
                }
                out << std::format(
                    "{:<12}{:<10}{:>5}  {:>7}  distinct={} top={}\n",
                    name, "text", s.count, s.missing, s.distinct, top_str);
            }
        }, stats[i]);
    }
}

}  // namespace csvstat
