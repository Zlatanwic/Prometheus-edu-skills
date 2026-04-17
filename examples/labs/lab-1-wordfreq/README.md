# Lab 1 — Word Frequency Histogram (`wordfreq`)

> Course: 高级语言程序设计（C++）· Week 3 · Due Week 4, 23:59 Friday
> Estimated time: 10–15 hours over one week
> Concepts exercised: `std::string`, `std::vector`, `std::unordered_map`, range-`for`, `std::sort`, lambdas, command-line arguments

## 1 · Why this lab exists

Real programs almost always begin with the same question: "what's in this data?" Before you train a model, index a search engine, or tune a database, you count things. The Unix utilities `wc`, `uniq -c`, and `sort | head` are pipelines every working programmer reaches for daily.

In this lab you will build a single-binary clone of that pipeline: a program called `wordfreq` that reads text from a file (or stdin), computes the frequency of every distinct word, and prints a histogram of the top-*K* most frequent words. By the time you finish you will have used the three most important tools in modern C++ — `std::string`, `std::vector`, and an associative container — to solve a problem you will recognize for the rest of your career.

Concretely, after this lab you will be able to:

- Read text input of unknown size without overflowing a fixed buffer.
- Use `std::unordered_map<K, V>` to count occurrences.
- Use `std::sort` with a lambda comparator to produce a ranked list.
- Use command-line flags to parameterize a program.
- Write programs that compile cleanly under `-Wall -Wextra -Wpedantic -fsanitize=address,undefined`.

## 2 · Problem statement

Build a command-line program `wordfreq` with the following contract:

```
wordfreq [--top N] [--min-length L] [--ignore-case] [FILE]
```

- If `FILE` is given, read from it; otherwise read from `stdin`.
- Split input into **words** — maximal runs of alphabetic characters (`isalpha`). Punctuation, digits, and whitespace separate words and are discarded.
- `--top N` (default 10): print only the top N most frequent words.
- `--min-length L` (default 1): ignore words shorter than L characters.
- `--ignore-case`: fold all words to lowercase before counting.
- Tie-breaking: when two words have the same frequency, the **lexicographically smaller** word appears first.

### Output format

For each of the top N words, print one line:

```
<word><space padding to column 20><count><space><bar>
```

The bar is made of `#` characters. Its length is proportional to the count:

```
bar_length = round(40 * count / max_count)
```

where `max_count` is the frequency of the #1 most-frequent word among the ones you print. (Always at least 1 `#` for non-zero counts.)

### Example

Given `data/gettysburg.txt` and the command:

```
$ wordfreq --top 5 --ignore-case data/gettysburg.txt
```

Your program should print:

```
the                 11 ########################################
that                10 ####################################
we                   8 #############################
here                 8 #############################
a                    7 #########################
```

(Your exact counts will match; bar lengths will match within ±1.)

## 3 · What you are given

```
lab-1-wordfreq/
├── README.md              # this file
├── RUBRIC.md
├── CMakeLists.txt         # build config (do not modify)
├── src/
│   ├── main.cpp           # entry point (you extend)
│   ├── wordfreq.hpp       # function declarations (signatures are fixed)
│   └── wordfreq.cpp       # your implementation goes here (TODOs)
├── tests/
│   ├── CMakeLists.txt
│   └── test_wordfreq.cpp  # public Catch2 tests
└── data/
    ├── gettysburg.txt
    └── small.txt
```

The **only** files you may modify are `src/main.cpp` and `src/wordfreq.cpp`. The signatures in `wordfreq.hpp` are part of the grading contract — do not change them.

## 4 · The three-hour onramp

1. Install a recent C++ toolchain (g++ ≥ 11 or clang ≥ 14) and CMake ≥ 3.16. Verify: `g++ --version`.
2. Build the project:
   ```
   cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
   cmake --build build -j
   ```
3. Run the (failing) test suite:
   ```
   ctest --test-dir build --output-on-failure
   ```
   You should see all tests fail with `UNIMPLEMENTED`. That is expected.
4. Open `src/wordfreq.cpp` in your editor. Read every `TODO` comment top-to-bottom before writing any code.
5. Implement `tokenize` first; make `TEST_CASE("tokenize")` pass; commit.

If step 1–4 take more than 3 hours, come to office hours — your setup is the problem, not you.

## 5 · Required interface

From `wordfreq.hpp`:

```cpp
namespace wordfreq {

struct Options {
    std::size_t top = 10;
    std::size_t min_length = 1;
    bool ignore_case = false;
};

// Split `text` into words — maximal runs of alphabetic characters.
// If opts.ignore_case is true, fold each word to lowercase.
// Words shorter than opts.min_length are omitted from the result.
std::vector<std::string> tokenize(std::string_view text, const Options& opts);

// Count the occurrences of each distinct word in `words`.
std::unordered_map<std::string, std::size_t>
count(const std::vector<std::string>& words);

// Produce a sorted vector of (word, count), longest-count first,
// breaking ties lexicographically. Returns at most `top` entries.
std::vector<std::pair<std::string, std::size_t>>
top_k(const std::unordered_map<std::string, std::size_t>& counts,
      std::size_t top);

// Render the histogram to `out` per the format in README §2.
void render(std::ostream& out,
            const std::vector<std::pair<std::string, std::size_t>>& ranked);

}  // namespace wordfreq
```

## 6 · Required build hygiene

Your submission must compile with the provided `CMakeLists.txt` **unmodified**, using:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_FLAGS="-Wall -Wextra -Wpedantic -fsanitize=address,undefined"
```

Every warning is an error for grading. AddressSanitizer must not report any leak, use-after-free, or out-of-bounds. UBSan must not fire on any test input.

## 7 · Testing

The public test suite in `tests/test_wordfreq.cpp` has 8 tests covering the four functions above. Run them:

```
ctest --test-dir build --output-on-failure
```

There is also a **hidden test suite** used for grading. It tests the same functions with adversarial inputs (empty input, 1 MB input, input that is entirely punctuation, Unicode bytes outside ASCII — your code should not crash on any byte sequence). The hidden tests are not shown to you, but the rubric describes their intent.

## 8 · Submission

Submit a zip of the entire `lab-1-wordfreq/` directory minus the `build/` directory. Your submission must include:

- Your modified `src/main.cpp` and `src/wordfreq.cpp`
- A `git log --oneline` output with at least **3 distinct commits** — use branches or commits corresponding to tokenize → count → top_k → render as natural milestones.
- A one-paragraph `REFLECTION.md` at the top level: what was the hardest bug, and how did you find it?

## 9 · Academic honesty

You may discuss the problem at a whiteboard level with classmates. You may not share code. You may read cppreference, the C++ Core Guidelines, and Stack Overflow for language questions, but you must not search for "CS-XYZ word frequency solution" or use any LLM to generate your `wordfreq.cpp`. The hidden test suite includes specific adversarial inputs that trivially-copied solutions fail.

If you used an LLM for language-level questions (e.g., "how does `std::unordered_map::emplace` differ from `insert`?"), disclose it in `REFLECTION.md`. Disclosure is not a penalty; non-disclosure detected after the fact is.
