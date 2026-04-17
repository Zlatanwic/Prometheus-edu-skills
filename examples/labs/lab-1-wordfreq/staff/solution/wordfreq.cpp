// STAFF SOLUTION — do not distribute to students.
//
// Design notes for course staff:
//  - tokenize uses a single pass with (start, i) indices instead of
//    std::regex for performance and to keep ASan-clean on non-ASCII.
//  - Casting char -> unsigned char before std::isalpha/tolower avoids the
//    classic UB on signed-char platforms. UBSan catches students who forget.
//  - top_k sorts a vector copied from the map; pairs are sorted with a
//    lambda that implements (count desc, word asc).
//  - render computes bar_len with std::lround; clamps to >= 1 only when
//    count > 0 (the empty-ranked fast-path prints nothing at all).

#include "wordfreq.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>

namespace wordfreq {

static char to_lower_char(char c) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
}

static bool is_alpha_char(char c) {
    return std::isalpha(static_cast<unsigned char>(c)) != 0;
}

std::vector<std::string> tokenize(std::string_view text, const Options& opts) {
    std::vector<std::string> out;
    std::size_t i = 0;
    while (i < text.size()) {
        while (i < text.size() && !is_alpha_char(text[i])) ++i;
        std::size_t start = i;
        while (i < text.size() && is_alpha_char(text[i])) ++i;
        if (i > start) {
            std::string word(text.substr(start, i - start));
            if (opts.ignore_case) {
                for (auto& c : word) c = to_lower_char(c);
            }
            if (word.size() >= opts.min_length) {
                out.push_back(std::move(word));
            }
        }
    }
    return out;
}

std::unordered_map<std::string, std::size_t>
count(const std::vector<std::string>& words) {
    std::unordered_map<std::string, std::size_t> m;
    m.reserve(words.size());
    for (const auto& w : words) ++m[w];
    return m;
}

std::vector<std::pair<std::string, std::size_t>>
top_k(const std::unordered_map<std::string, std::size_t>& counts,
      std::size_t top) {
    std::vector<std::pair<std::string, std::size_t>> v(counts.begin(), counts.end());
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    if (v.size() > top) v.resize(top);
    return v;
}

void render(std::ostream& out,
            const std::vector<std::pair<std::string, std::size_t>>& ranked) {
    if (ranked.empty()) return;
    const auto max_count = ranked.front().second;
    for (const auto& [word, cnt] : ranked) {
        std::size_t bar_len = 0;
        if (max_count > 0) {
            bar_len = static_cast<std::size_t>(std::lround(40.0 * cnt / max_count));
            if (cnt > 0 && bar_len == 0) bar_len = 1;
        }
        out << word;
        if (word.size() < 20) out << std::string(20 - word.size(), ' ');
        else                  out << ' ';
        out << cnt << ' ' << std::string(bar_len, '#') << '\n';
    }
}

}  // namespace wordfreq
