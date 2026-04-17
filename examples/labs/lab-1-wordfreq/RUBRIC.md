# Lab 1 — Grading Rubric (100 pts)

| Area | Points | Criterion |
|------|-------:|-----------|
| **Correctness (public tests)** | 30 | All 8 public tests in `tests/test_wordfreq.cpp` pass. |
| **Correctness (hidden tests)** | 30 | Hidden suite covers: empty input (5), single-word input (5), input with only punctuation (5), 1 MB generated input (5), non-ASCII bytes that must not crash (5), tie-breaking correctness (5). |
| **Build hygiene** | 15 | Compiles with `-Wall -Wextra -Wpedantic -Werror` and passes under `-fsanitize=address,undefined` with no diagnostic. |
| **Code quality** | 10 | Uses `std::string_view` where reading, `const&` for large parameters, range-`for` over indexed loops, no raw `new`/`delete`. No function > 40 lines. No file > 250 lines. |
| **Git hygiene** | 5 | ≥ 3 meaningful commits with informative messages. |
| **Reflection** | 10 | `REFLECTION.md` is specific, honest, and names a concrete debugging technique used (GDB, ASan output, print-debugging, rubber-ducking, etc.). |

## Hidden test intents (shown for transparency; inputs not disclosed)

1. **H1 — Empty input.** `tokenize("", opts)` must return an empty vector; `top_k({}, 10)` must return an empty vector; `render` must not print anything (or print a single newline, grader accepts both).
2. **H2 — Case folding across the boundary.** `The` and `THE` and `the` must collapse to one entry under `--ignore-case`.
3. **H3 — Ties.** When five words have count 3, they must appear in lexicographic order. A student who used only `std::sort` by count (no tiebreaker) fails this.
4. **H4 — Large input.** A 1 MB file with 100,000 unique words must complete in < 2 seconds on the reference grader. Students who wrote O(n²) counting fail.
5. **H5 — Non-ASCII bytes.** Bytes ≥ 128 must be treated as non-alphabetic (they terminate a word). Program must not crash. Students who passed `char` directly to `isalpha` without casting to `unsigned char` will hit UB here and be caught by UBSan.
6. **H6 — Bar rendering when all counts equal.** All bars should have length 40.

## Time budget sanity check

A well-scaffolded student with average prep should spend:

- ~2 h reading + setup + first compile
- ~2 h on `tokenize` (the trickiest: off-by-one and non-ASCII edge cases)
- ~1 h on `count` and `top_k` (straightforward)
- ~2 h on `render` and CLI parsing
- ~2 h on debugging, sanitizer cleanup, writing tests
- ~1 h on reflection, final build check

Total: ~10 hours. If a student is spending 25+ hours, direct them to office hours.
