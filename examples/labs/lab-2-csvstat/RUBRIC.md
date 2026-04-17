# Lab 2 — Grading Rubric (100 pts)

| Area | Points | Criterion |
|------|-------:|-----------|
| Correctness — parser public tests | 20 | 7 tests in `test_parser.cpp` |
| Correctness — stats public tests | 15 | 7 tests in `test_stats.cpp` |
| Correctness — hidden tests | 25 | See intents below |
| Build hygiene | 10 | warn-clean, ASan/UBSan clean |
| Code quality | 10 | multi-file organization, no functions > 50 lines, proper `const&` parameters, `std::variant` used as intended (not `if (type == "numeric")` string-typing) |
| Error handling | 10 | parser throws `CsvError` on every malformed input the hidden suite throws at it; does not segfault |
| Git + reflection | 10 | ≥ 4 commits, `REFLECTION.md` specific |

## Hidden test intents

- **H1** — Unterminated quoted field mid-file: `CsvError` with correct line number.
- **H2** — Row with wrong column count: `CsvError`.
- **H3** — File without trailing newline: still produces all rows.
- **H4** — CRLF line endings: same result as LF.
- **H5** — Column that starts numeric but becomes text halfway down: final classification = text.
- **H6** — Column with one unique text value: `distinct=1 top=<value>(n)`.
- **H7** — Empty CSV body (header only): all columns reported with count=0.
- **H8** — Memory cleanliness on a 500k-row file: no ASan hits.
