#pragma once
// Lab 1 — wordfreq. DO NOT MODIFY THIS FILE.
// Changing any signature in this header will break the grader.

#include <cstddef>
#include <ostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

namespace wordfreq {

struct Options {
    std::size_t top = 10;
    std::size_t min_length = 1;
    bool ignore_case = false;
};

std::vector<std::string> tokenize(std::string_view text, const Options& opts);

std::unordered_map<std::string, std::size_t>
count(const std::vector<std::string>& words);

std::vector<std::pair<std::string, std::size_t>>
top_k(const std::unordered_map<std::string, std::size_t>& counts,
      std::size_t top);

void render(std::ostream& out,
            const std::vector<std::pair<std::string, std::size_t>>& ranked);

}  // namespace wordfreq
