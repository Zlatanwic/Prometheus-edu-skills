// STAFF SOLUTION for stats.cpp.

#include "stats.hpp"
#include <algorithm>
#include <charconv>
#include <cmath>
#include <unordered_map>

namespace csvstat {

static bool try_parse_double(const std::string& s, double& out) {
    if (s.empty()) return false;
    const char* b = s.data();
    const char* e = b + s.size();
    auto r = std::from_chars(b, e, out);
    return r.ec == std::errc{} && r.ptr == e;
}

ColumnStats summarize_column(const std::vector<std::string>& cells) {
    bool numeric = true;
    std::size_t missing = 0;
    for (const auto& c : cells) {
        if (c.empty()) { ++missing; continue; }
        double d;
        if (!try_parse_double(c, d)) { numeric = false; break; }
    }

    if (numeric) {
        NumericStats n;
        std::vector<double> vals;
        vals.reserve(cells.size());
        for (const auto& c : cells) {
            if (c.empty()) { ++n.missing; continue; }
            double d; try_parse_double(c, d);
            vals.push_back(d);
        }
        n.count = vals.size();
        if (!vals.empty()) {
            n.min = *std::min_element(vals.begin(), vals.end());
            n.max = *std::max_element(vals.begin(), vals.end());
            double sum = 0;
            for (double v : vals) sum += v;
            n.mean = sum / vals.size();
            double sq = 0;
            for (double v : vals) sq += (v - n.mean) * (v - n.mean);
            n.stddev = std::sqrt(sq / vals.size());
        }
        return n;
    }

    TextStats t;
    t.missing = missing;
    std::unordered_map<std::string, std::size_t> freq;
    for (const auto& c : cells) {
        if (!c.empty()) { ++freq[c]; ++t.count; }
    }
    t.distinct = freq.size();
    std::vector<std::pair<std::string, std::size_t>> v(freq.begin(), freq.end());
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    if (v.size() > 3) v.resize(3);
    t.top = std::move(v);
    return t;
}

}  // namespace csvstat
