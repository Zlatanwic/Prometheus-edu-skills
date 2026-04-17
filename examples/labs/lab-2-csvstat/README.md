# Lab 2 — CSV Log Analyzer (`csvstat`)

> Course: 高级语言程序设计（C++）· Week 6 · Due Week 8, 23:59 Friday
> Estimated time: 15–20 hours over two weeks
> Concepts: functions, `std::ifstream`, `std::format` (C++20), exceptions, multi-file projects, `std::variant`

## 1 · Why this lab exists

Every engineer who has ever touched a production system has, at 3am, typed some variation of `awk -F, '{sum+=$3} END {print sum}'` into a terminal. The CSV-as-lingua-franca of data interchange is older than you are, and will outlive your career. In this lab you write the C++ version of that 3am one-liner, properly — with a real parser that handles quoted fields, a real aggregator that knows the difference between a number and a string, and an error path that helps the user instead of crashing.

By the end you will:

- Split a program across multiple `.hpp`/`.cpp` files with a clean public interface.
- Use `std::variant` to represent "a column is either numeric or textual".
- Throw and catch exceptions at system boundaries without peppering your code with `try/catch`.
- Use `std::format` (C++20) to produce neatly-aligned tabular output.
- Write a CSV parser that does **not** crash on quoted commas, escaped quotes, or files without a trailing newline — the three canonical gotchas.

## 2 · Problem statement

Build a CLI named `csvstat` that reads a CSV file and prints a per-column report:

```
csvstat [--no-header] [--columns a,b,c] FILE
```

Input CSV grammar (RFC 4180, subset):

- First line is a header unless `--no-header` is passed.
- Fields separated by `,`. Rows separated by `\n` (or `\r\n`).
- A field that contains `,`, `"`, or `\n` must be quoted with `"..."`.
- Inside quotes, `""` denotes a literal `"`.

For each selected column, detect its type:

- **Numeric** — every non-empty value parses as a `double` via `std::from_chars` (ints count).
- **Text** — otherwise.

For numeric columns print: count, missing, min, max, mean, stddev (population).
For text columns print: count, missing, distinct values, top-3 most frequent values with counts.

### Example

Given `data/sales.csv`:
```
date,product,qty,revenue
2026-01-01,Widget,4,39.80
2026-01-02,Gadget,2,49.98
2026-01-02,Widget,,20.00
2026-01-03,Widget,6,59.70
```
Running `csvstat data/sales.csv` should print:

```
column      type      count  missing  summary
----------  --------  -----  -------  ----------------------------------------
date        text          4        0  distinct=3 top=2026-01-02(2),2026-01-01(1),2026-01-03(1)
product     text          4        0  distinct=2 top=Widget(3),Gadget(1)
qty         numeric       3        1  min=2 max=6 mean=4.00 stddev=1.63
revenue     numeric       4        0  min=20.00 max=59.70 mean=42.37 stddev=14.68
```

## 3 · What you are given

```
lab-2-csvstat/
├── README.md
├── RUBRIC.md
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── parser.hpp        # public CSV parser interface (FIXED)
│   ├── parser.cpp        # TODO
│   ├── stats.hpp         # public stats interface (FIXED)
│   ├── stats.cpp         # TODO
│   └── report.cpp        # rendering (you may edit freely)
├── tests/
│   ├── CMakeLists.txt
│   └── test_parser.cpp
│   └── test_stats.cpp
└── data/
    ├── sales.csv
    ├── quoted.csv
    └── empty.csv
```

## 4 · Required interfaces (do not change)

```cpp
// parser.hpp
namespace csvstat {
struct CsvError : std::runtime_error { using std::runtime_error::runtime_error; };

struct CsvRow  { std::vector<std::string> fields; };
struct CsvFile {
    std::vector<std::string> header;   // empty if --no-header was passed
    std::vector<CsvRow>      rows;
};

// Parse a complete CSV input. If `has_header` is true, consume the first row
// as the header. Throws CsvError with a line number on malformed input.
CsvFile parse(std::istream& in, bool has_header);
}  // namespace csvstat
```

```cpp
// stats.hpp
namespace csvstat {
struct NumericStats {
    std::size_t count = 0, missing = 0;
    double min = 0, max = 0, mean = 0, stddev = 0;
};
struct TextStats {
    std::size_t count = 0, missing = 0, distinct = 0;
    std::vector<std::pair<std::string, std::size_t>> top;  // up to 3
};
using ColumnStats = std::variant<NumericStats, TextStats>;

// Given a vector of cell strings for one column, classify and summarize.
// A cell is "missing" iff it is the empty string.
ColumnStats summarize_column(const std::vector<std::string>& cells);
}  // namespace csvstat
```

## 5 · Three-hour onramp

1. `cmake -S . -B build && cmake --build build`
2. `ctest --test-dir build --output-on-failure` — expect 0 / 14 passing.
3. Open `data/sales.csv` in your editor. Open `parser.cpp`. Implement `parse` for the unquoted case first. Make `TEST_CASE("simple csv")` pass.
4. Add quoted-field handling. Make `TEST_CASE("quoted fields")` pass.
5. Move on to stats.

## 6 · Specific requirements

- Your `parse` must detect and throw `CsvError` with a line number on: unterminated quoted field, inconsistent row lengths, malformed escapes. Do **not** crash.
- Your numeric detection in `summarize_column` must treat empty strings as "missing", not as "zero". A column of `["1", "2", ""]` has count=2, missing=1, mean=1.5.
- Population stddev: `sqrt(sum((x - mean)^2) / count)`. Single-value column → stddev = 0.
- Text "top" list: up to 3 entries, sorted by count desc then value asc (same tie-breaker as Lab 1).
- All floating-point in output: 2 decimal places via `std::format("{:.2f}", x)`.

## 7 · Build hygiene

Identical to Lab 1: `-Wall -Wextra -Wpedantic`, clean under `-fsanitize=address,undefined`.

## 8 · Submission

- Source tree + `REFLECTION.md` (1 paragraph).
- At least **4 commits** — suggested: parser unquoted, parser quoted, stats numeric, stats text.
- Public tests passing: 14/14. Hidden tests: see rubric.
