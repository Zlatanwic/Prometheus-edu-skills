---
name: lab-designer
description: Generate professional lab/assignment documents and code scaffolds for top-tier university CS courses, modeled on the best MIT/Stanford/Berkeley/CMU labs. Use whenever a professor or TA asks to design, build, write, or flesh out labs, assignments, homework, problem sets, coding projects, or starter code for a university CS course — e.g., "design a lab for my distributed systems class", "write the MapReduce assignment", "generate starter code for my neural network homework", "flesh out the labs from my syllabus", or "design the labs" / "generate lab N" after a syllabus has been produced. Also trigger when the user uploads a syllabus and asks for its labs. By default produces a menu of all lab summaries for selection, then for each chosen lab a full deep-dive package — a student-facing lab doc, starter code scaffold (notebook for ML/data, project structure for systems/compilers, auto-selected), test harness, and staff reference solution. Often chained after course-syllabus-architect but works standalone.
---

# Lab Designer

A skill for generating professional, MIT/Stanford-quality lab packages — instruction docs, starter code scaffolds, test harnesses, and staff solutions — for university CS courses.

## The problem this solves

A good syllabus is only half of a course. The other half is the lab sequence, and that's where most courses fail students: assignments that are either too vague (a one-paragraph prompt) or too boilerplate (autograded toy problems). The best labs in CS education — MIT 6.5840's Raft implementation, Stanford CS144's TCP project, CMU 15-445's database internals, Berkeley CS61C's numc — share a specific structure: a narrative lab document that motivates the problem, clearly stated deliverables with a precise interface contract, a starter scaffold that handles boilerplate so students focus on the intellectual core, a public test suite they can self-check against, and a staff-only reference solution that stays private.

This skill produces that kind of package. It is heavy on structure and light on shortcuts — labs like this take course staff weeks to build from scratch; this skill produces a solid first draft that a professor can then refine.

## When this skill runs

Three entry points, all valid:

1. **Chained from course-syllabus-architect.** The user generated a syllabus and now wants the labs built out. They'll say something like "design the labs" or "generate the labs from that syllabus".
2. **Standalone with a syllabus.** The user brings an existing syllabus (maybe from another source) and wants labs generated.
3. **Ad-hoc for a single lab.** The user wants one specific lab built, e.g., "design a MapReduce lab for a distributed systems course" — no syllabus context.

In all three cases, follow the same core workflow; adapt only what context you start with.

## The core workflow

### Step 1: Establish context

Figure out what you have and what you need:

- **A syllabus is present** (either from an earlier course-syllabus-architect run in this conversation, or uploaded as a file): extract the list of assignments/labs mentioned. These are your candidate labs.
- **No syllabus, but the user named a course topic**: ask briefly for the 3–5 labs they want, or propose a default set based on the course topic (4 labs is a good default for a semester).
- **No syllabus, single lab request**: skip the menu phase (Step 2) and go straight to deep-dive mode (Step 4) for that one lab.

Also confirm:

- **Level** (undergrad / graduate) — same as syllabus skill, affects expected difficulty.
- **Target completion time per lab** — default: 1–2 weeks of part-time work, ~15–25 student hours. Ask if uncertain.
- **Code format override** — default is auto-detected by topic (see Step 3b). User can override.

### Step 2: Two-phase generation — Phase 1 (menu)

**Default behavior: produce a lab menu, then wait for user selection.**

Generate a concise menu of all labs in the syllabus/course. For each lab, show:

- **Lab number and working title**
- **One-sentence goal** (what the student builds and what they learn)
- **Estimated time** (e.g., "~15 hours over 1 week")
- **Code format that will be used** (notebook vs. project — see Step 3b)
- **Key deliverable** (e.g., "A working Raft leader-election implementation passing the provided test suite")

Present this as a clean numbered list in chat. Then ask explicitly:

> Which labs would you like me to build out in full? You can say "all of them", "lab 3", "labs 1 and 4", or "start with lab 1 and we'll iterate".

**Do not proceed to Phase 2 until the user chooses.** Generating all 4 deep-dive packages upfront is a lot of output, and the user may want to iterate on the menu before committing.

**When to skip Phase 1:** If the user explicitly says "just generate all of them" or the request is for a single specific lab ("design lab 3"), go straight to Phase 2.

### Step 3: Before Phase 2 — research the reference labs

Once the user selects labs to build out, research before writing. Top university labs are the best structural references.

**Search budget: at least 3–5 searches per lab being built.** Look for:

- The actual lab pages at top universities for similar topics. E.g., for a MapReduce lab: search `MIT 6.5840 lab 1 MapReduce`, `Berkeley CS162 MapReduce project`. These are public and show the exact level of detail used.
- Publicly available starter code repositories on GitHub for similar labs (the top university labs are often open-source).
- For frontier-topic labs (e.g., "implement DPO"), search for tutorial notebooks or reference implementations from reputable sources (HuggingFace, official paper repos).

See `references/reference_labs.md` for a cheat-sheet of the most frequently-cited MIT/Stanford/Berkeley/CMU labs by topic.

### Step 3b: Auto-select code format

Detect from the course topic (lab-designer does this without asking):

- **Notebook format (`.ipynb`)** for ML, Deep Learning, Data Science, NLP, Vision, RL, Statistics, Scientific Computing, Information Retrieval. These courses benefit from the exploratory narrative a notebook supports: inline visualizations, intermediate outputs, math in markdown.
- **Project format (`src/` + `tests/` directory structure)** for Operating Systems, Distributed Systems, Databases, Compilers, Networking, Security, Computer Architecture, Programming Languages, Systems Programming. These courses need multi-file code, Makefiles, and a realistic dev environment.
- **Hybrid** (rare) for courses that genuinely span both — e.g., an ML systems course that has both modeling labs and serving-infrastructure labs. In this case, use the format that matches the specific lab's focus.

If the user explicitly requested a format, honor that.

### Step 4: Two-phase generation — Phase 2 (deep dive)

For each lab the user selected, produce a complete package. See `references/lab_document_template.md` and `references/scaffold_patterns.md` for the exact structure.

**The package per lab consists of:**

1. **A student-facing lab document** (`lab-N-<slug>.md`) — the "front of the room" material.
2. **A starter code scaffold** (format per Step 3b) — what the student downloads and edits.
3. **A test harness** — public tests the student runs to self-check.
4. **A staff-only reference solution** — clearly marked, goes in a separate file students don't receive.
5. **A grading rubric** — what counts for what % of the lab grade.

Each of these follows a specific layout detailed in the reference files. **Before writing, read `references/lab_document_template.md` and `references/scaffold_patterns.md`.**

### Step 5: Deliver

Write all files to `/mnt/user-data/outputs/`. For a single lab, one directory like `/mnt/user-data/outputs/lab-1-mapreduce/`. For multiple labs, one directory per lab. Use `present_files` to share them.

In the chat response, include:

- A one-sentence summary of what was produced.
- A list of the files in each lab package.
- **One targeted piece of iteration feedback you're genuinely unsure about** — e.g., "The test harness for lab 1 checks for determinism via a fixed seed; let me know if you'd rather test probabilistically." Resist the urge to list five vague questions — pick the one a thoughtful professor would actually care to answer.

## Important design principles

**Motivation first.** Every lab document opens with a paragraph explaining why this exercise exists — what intellectual skill it builds, what real-world system it mirrors, what a student who completes it can now do. MIT and CMU labs always do this. It's the difference between an exercise and an experience.

**The 3-hour onramp rule.** A student should be able to read the lab doc, clone the starter code, run the initial tests (which should all fail in informative ways), and understand what to do in under 3 hours. If the onramp takes longer, the lab is badly scaffolded — simplify the initial step.

**Interface contracts, not implementation contracts.** Specify what the student's code must expose (function signatures, file names, CLI behavior) but do not over-prescribe how they get there. Leaving implementation freedom is where the learning happens. The test suite defines what "done" means.

**Public tests + hidden tests.** Give students a public test suite they run locally and can reason about. Hold back a hidden test suite for grading that catches the common wrong shortcuts (e.g., a student who hardcodes expected outputs). Describe the hidden tests' *purpose* in the rubric but not their contents.

**Staff solution is real code, not pseudocode.** The reference solution should be a clean, working implementation that passes all public and hidden tests. A professor should be able to drop it in and use it for their own debugging. If you cannot produce a real working solution for a task, the task is probably either too hard for a student lab or requires resources (specific datasets, compute) that should be flagged.

**Academic honesty by design.** Include a section in the lab doc on what constitutes collaboration vs. cheating, and point the student to the university's honor code format. Good labs are structured so that copying a solution is easy to detect (via hidden tests or specific output formats).

## Tone and voice

The student-facing lab doc is a technical document for smart, motivated undergraduates or grad students. Be precise and concrete. No hand-holding, no cheerleading, no emoji. Assume they can google things. But also — no condescension. MIT's 6.5840 Raft lab is a good model: it assumes readers are serious, respects their time, and is funny in a dry way when appropriate.

The staff solution file is for course staff. Heavy comments are fine; explain the *why*, not the *what*, of every non-obvious design choice.

Chinese-speaking users can request output in Chinese. Translate prose, but keep: code identifiers, error messages, file names, library/tool names, and paper titles in English.

## Common pitfalls to avoid

- **Toy problems dressed as labs.** A lab where the student writes `def add(a, b): return a + b` under scaffolding is not a lab, it's a unit test. Every lab should produce an artifact the student could show off — a working MapReduce, a diffusion model they trained, a shell they built.
- **Infinite test suites.** Students will spend hours chasing down why test_case_47 fails. Keep the public test suite small (5–15 tests), each checking a distinct property. More tests belong in the hidden grading suite.
- **Dataset or environment dependencies you don't specify.** If the lab needs CUDA, specify it. If it needs a 10GB dataset, link it and state the disk requirement. If it only runs on Linux, say so.
- **Unverified claims about external tools or libraries.** Don't state that a particular library function behaves a certain way without being sure — search it if unsure. Wrong claims in lab docs are catastrophic because students trust them.
- **Mismatched difficulty.** A 1-week lab that actually takes 40 hours is a broken lab. If you're drafting something and it feels like it might blow up the time budget, note that in the rubric and suggest a simplification.
- **Skipping the reference solution.** A lab without a working staff solution is an untested hypothesis. Always produce one.

## Reference files

- `references/reference_labs.md` — Cheat-sheet mapping common CS course topics to the canonical labs at top universities. Consult before searching.
- `references/lab_document_template.md` — The exact structure for the student-facing lab document (the `.md` file students read).
- `references/scaffold_patterns.md` — Starter code layout patterns for both notebook format and project format, plus guidance on test harness design.
