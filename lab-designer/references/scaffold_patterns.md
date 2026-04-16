# Code Scaffold Patterns

This file specifies how the starter code, test harness, and staff solution are laid out. There are two main patterns — **notebook** and **project** — with guidance on when to use each and what each must include.

## Choosing the format (if not already set)

Decide once at the start of Phase 2 for each lab. Default heuristic:

**Notebook format (`.ipynb`)** — use for:
- ML, deep learning, data science, statistics
- Any lab centered on modeling, training loops, or data exploration
- Labs where inline plots, LaTeX math, and narrative explanation interleave with code
- Short labs (under ~400 lines of student code)

**Project format** (`src/` + `tests/` directory) — use for:
- OS, distributed systems, databases, compilers, networking
- Multi-file implementations requiring modularity
- Anything involving a build system (Makefile, Cargo, Go modules)
- Labs where the student runs their code against a CLI or service, not inside a notebook
- Long labs (>400 lines, multi-week)

If a lab straddles both (e.g., "build a small DL framework"), prefer project format — notebooks break down badly past a few hundred lines.

---

## Pattern A: Notebook format

### File layout

```
lab-N-<slug>/
├── README.md                    # Brief: how to open, run tests
├── lab-N-<slug>.md              # The full student-facing doc (copy from lab_document_template output)
├── requirements.txt             # Python deps with pinned versions
├── starter.ipynb                # What the student fills in
├── tests/
│   ├── test_public.py           # The tests the student sees and runs
│   └── utils.py                 # Helpers for tests (fixtures, data loaders)
├── data/                        # (if applicable) small datasets or download script
│   └── download.sh
└── staff/                       # NOT distributed to students
    ├── solution.ipynb           # Reference solution — the filled-in starter
    ├── test_hidden.py           # Grading tests beyond the public set
    └── NOTES.md                 # Staff-only rubric notes, common mistakes
```

### Starter notebook structure

The `.ipynb` file is the core of the lab experience. Structure each notebook as follows:

1. **Title cell (markdown)** — lab title, due date, quick-link to the full lab doc
2. **Motivation cell (markdown)** — brief recap of what the student is doing here and why
3. **Imports cell (code)** — all imports pre-filled, so setup errors surface early
4. **Section headers (markdown) that match Parts 1-N in the lab doc**
5. **For each part:**
   - Markdown cell: short problem restatement
   - Code cell(s) with function stubs:
     ```python
     def student_function(args):
         """
         TODO: Implement <what it should do>.
         
         Args:
             ...
         Returns:
             ...
         """
         raise NotImplementedError("Implement me in Part 1")
     ```
   - Code cell with a quick smoke test the student can run:
     ```python
     # Sanity check — should return <expected simple case>
     assert student_function(...) == ...
     ```
6. **Final cell**: a cell that runs the test suite: `!pytest tests/test_public.py -v`

**Important:** the notebook must be fully runnable top-to-bottom, even with all stubs raising NotImplementedError. Students should be able to "Run All" and see clear, localized errors — not import failures or cascading exceptions from cell 1.

### Test harness (notebooks)

Use `pytest` even for notebook labs — it's more robust than notebook-internal asserts for grading. The tests import from the notebook (via `nbformat` + `%run`, or by extracting functions to a `.py` file the notebook imports back from).

Simplest pattern: have the student write their functions in both the notebook and a companion `solution.py` that the notebook imports; tests target `solution.py`. Document this clearly so they don't confuse themselves.

---

## Pattern B: Project format

### File layout (generic)

```
lab-N-<slug>/
├── README.md                    # How to build, run, test
├── lab-N-<slug>.md              # Full student-facing doc
├── Makefile                     # or build.sh / Cargo.toml / go.mod depending on language
├── src/                         # Student code goes here
│   ├── <module1>.{c,go,rs,py}
│   └── <module2>.{c,go,rs,py}
├── include/                     # (C/C++) headers with function signatures pre-declared
├── tests/
│   ├── test_public_<aspect>.{c,go,rs,py}
│   └── run_tests.sh             # A script that runs all public tests and produces a pass/fail summary
├── scripts/                     # (if needed) helper scripts for setup, benchmarking
└── staff/                       # NOT distributed to students
    ├── solution/                # A full working reference implementation
    │   └── src/
    ├── tests/
    │   └── test_hidden_<aspect>.<ext>
    └── NOTES.md
```

### Language-specific notes

**C/C++ (e.g., OS, low-level systems):**
- Provide a `Makefile` with `all`, `test`, `clean` targets. Students hate fighting a build system.
- Put function declarations in `include/*.h` and leave the `.c` files as stubs. This enforces the interface contract at compile time.
- Provide sanitizers in the default build (`-fsanitize=address,undefined` for debug builds).

**Go (e.g., distributed systems, à la MIT 6.5840):**
- Use `go test` natively. Each test file `xxx_test.go` next to the source.
- `go test -race` should be part of the expected test command — concurrency bugs show up here.
- Interface declarations go in the `.go` files with `// TODO: implement` for the bodies.

**Rust (e.g., systems courses that use Rust):**
- `cargo test` works out of the box.
- Use `todo!()` macros in stubs — they crash loudly and are idiomatic.

**Python (e.g., compilers, DB labs that use Python):**
- Use `pytest`. Pin versions in `requirements.txt`.
- Use type hints on stub signatures — this doubly documents the interface.

### Test harness (projects)

Two test tiers, always:

1. **Public smoke tests** — fast, run in seconds, catch obvious bugs. 5–10 tests max.
2. **Public correctness tests** — exercise interesting cases. 10–20 tests. Should take under a minute total.

Plus a **hidden test suite** in `staff/tests/` with:

3. **Edge cases** — empty inputs, max sizes, error conditions
4. **Adversarial tests** — things that specifically catch common wrong shortcuts (students who hardcode, students who pass by reference instead of deep copy, etc.)
5. **Performance tests** — if the lab has performance requirements, test them here with time limits

The public/hidden split is essential: without hidden tests, every student writes to pass the publicly visible tests and learns less.

---

## Staff solution — universal guidance

Regardless of format:

- The staff solution **must actually run** and pass all public + hidden tests. Do not ship pseudocode.
- Heavily commented with *why*, not just *what*. Future course staff will use it for debugging student submissions.
- Include a `staff/NOTES.md` file with:
  - Typical completion time for a strong student vs. struggling student
  - Common mistakes and how to recognize them in submitted code
  - Rubric details beyond the student-visible one (e.g., "deduct 2pts if they use a global lock where fine-grained was expected")
  - Any changes needed if reusing the lab next semester

## The 3-hour onramp test (for both formats)

Before finalizing a lab package, mentally simulate a student's first 3 hours:

1. Clone the repo → should work first try, README should be clear
2. Install deps → should work on stated OS/Python/Go version
3. Run initial tests → should see clearly-formatted failures pointing at what to implement first
4. Read the lab doc → should know what Part 1 asks after one pass
5. Start coding Part 1 → should be able to write first lines within 30 min of starting

If any of these would stumble a motivated student, fix it before shipping.

## Files that ALWAYS exist (checklist)

For either format, the final package includes at minimum:

- [ ] `README.md` — quick-start
- [ ] `lab-N-<slug>.md` — full student doc
- [ ] Starter code (notebook or src/)
- [ ] Public test suite
- [ ] Dependency spec (requirements.txt / Makefile / Cargo.toml / go.mod)
- [ ] `staff/solution.*` — working reference
- [ ] `staff/test_hidden.*` — grading tests
- [ ] `staff/NOTES.md` — staff-only guidance

If any of these is missing, the package is incomplete.
