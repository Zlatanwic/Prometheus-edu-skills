// Lab 1 — CLI entry point. You may edit this file to parse flags.
//
// Minimum required behaviour (see README §2):
//   wordfreq [--top N] [--min-length L] [--ignore-case] [FILE]
//
// Default: --top 10 --min-length 1, read stdin.

#include "wordfreq.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

namespace {

wordfreq::Options parse_args(int argc, char** argv, std::string& infile) {
    wordfreq::Options opts;
    for (int i = 1; i < argc; ++i) {
        std::string_view arg = argv[i];
        if (arg == "--top" && i + 1 < argc) {
            opts.top = std::stoul(argv[++i]);
        } else if (arg == "--min-length" && i + 1 < argc) {
            opts.min_length = std::stoul(argv[++i]);
        } else if (arg == "--ignore-case") {
            opts.ignore_case = true;
        } else if (!arg.empty() && arg[0] != '-') {
            infile = std::string(arg);
        } else {
            std::cerr << "unknown argument: " << arg << '\n';
            std::exit(2);
        }
    }
    return opts;
}

std::string slurp(std::istream& in) {
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

}  // namespace

int main(int argc, char** argv) {
    std::string infile;
    auto opts = parse_args(argc, argv, infile);

    std::string text;
    if (infile.empty()) {
        text = slurp(std::cin);
    } else {
        std::ifstream f(infile);
        if (!f) {
            std::cerr << "cannot open " << infile << '\n';
            return 1;
        }
        text = slurp(f);
    }

    auto words = wordfreq::tokenize(text, opts);
    auto counts = wordfreq::count(words);
    auto ranked = wordfreq::top_k(counts, opts.top);
    wordfreq::render(std::cout, ranked);
    return 0;
}
