# Student-Facing Lab Document Template

This is the structure for the `.md` file students read. Section ordering matters — it mirrors the MIT/Stanford/CMU conventions and is optimized for a student trying to get started fast.

## Filename convention

`lab-<N>-<slug>.md` — e.g., `lab-1-mapreduce.md`, `lab-3-raft-leader-election.md`.

## Template

```markdown
# Lab <N>: <Title>

**Course:** <Course title>
**Due:** <Week N / date placeholder>
**Estimated time:** <X hours over Y weeks>
**Submission:** <what they hand in — a repo tag, a zip, a specific file set>

## Motivation

<One to two paragraphs. Why this lab exists. What real-world problem
or system it mirrors. What intellectual skill the student builds. This
is the "front matter" that makes students care. Do not skip it — MIT
and CMU labs always open with this and for good reason.>

## Learning outcomes

After completing this lab, you will be able to:
1. <Outcome 1 — verbs like "implement", "analyze", "debug", "explain">
2. ...
4. ...

## Background and reading

Before starting, you should understand the concepts from:
- Lecture N on <topic>
- <Paper or textbook chapter, properly cited>

If any of the following feel unfamiliar, review them first:
- <Concept 1>
- <Concept 2>

## Task overview

<One paragraph: in concrete terms, what does the student implement?
"You will implement X, which takes Y as input and produces Z, with the
following properties...">

## Environment setup

- **Language/runtime:** <Python 3.11, Go 1.22, C with gcc, etc.>
- **Dependencies:** <list; include install commands>
- **Hardware requirements:** <RAM, GPU, disk — if any>
- **OS compatibility:** <Linux-only / cross-platform / etc.>

Clone the starter repo and run the initial test suite:

\`\`\`bash
git clone <url>
cd <repo>
<setup command — e.g., pip install -r requirements.txt>
<test command — e.g., pytest tests/ -v>
\`\`\`

You should see all tests currently failing (that's expected — your job is to make them pass).

## The lab in parts

Break the lab into 2–5 numbered parts. Each part is a checkpoint with
its own tests passing.

### Part 1: <Sub-title>

<Describe what the student implements in this part. Be specific about
the interface contract (function signatures, CLI behavior, file format)
but leave implementation choice to them.>

**Interface contract:**
\`\`\`<language>
<Function/class signature the student must implement exactly as shown>
\`\`\`

**What success looks like:** When Part 1 is done, \`<specific test command>\` should show all tests in \`test_part1.<ext>\` passing.

**Hints:**
- <A hint that saves students hours without giving away the solution>
- <Another one>

### Part 2: <Sub-title>
...

## Testing

**Public tests (run locally):**
\`\`\`bash
<command>
\`\`\`

These cover the main correctness properties. They do NOT exhaust
everything we check at grading time.

**Hidden tests (for grading):**
We additionally run hidden tests that check:
- <High-level description of what they check, e.g., "Performance under load">
- <Another category, e.g., "Correctness with adversarial inputs">

We describe the *categories* of hidden tests so you know what to
defensively test against. We do not publish their contents.

## Grading rubric

| Component | Points | Notes |
|---|---|---|
| Part 1 public tests | <X> | All must pass |
| Part 2 public tests | <Y> | ... |
| Hidden correctness tests | <Z> | ... |
| Code quality / comments | <W> | Judgment-based |

Total: <sum> points

## Submission

<Precisely specify what and how to submit. Filename, format, any tags
or repo conventions. Deadline and late policy.>

## Collaboration and academic honesty

Discussion of the lab concepts with classmates is encouraged. However:
- You must write all code you submit yourself.
- Do not look at another student's code, code from prior semesters, or online solutions to this lab.
- Use of AI coding assistants is <permitted / restricted / prohibited — state course policy>.

If in doubt, ask the course staff. Violations are reported per the university's honor code.

## Common pitfalls

A short list of things that trip up students every semester:
- <Pitfall 1 with a hint on how to avoid>
- <Pitfall 2>
- <Pitfall 3>

## Extensions (optional, ungraded)

If you finish early and want to explore further:
- <Open-ended extension 1>
- <Extension 2 — good for building a portfolio piece>
```

## Notes on writing each section well

- **Motivation**: reference the actual system or paper the lab mirrors. "You'll implement a simplified version of the MapReduce system from Dean and Ghemawat 2004" is better than "You'll implement a distributed processing system."
- **Learning outcomes**: limit to 3–5 items. More than that and none of them land.
- **Interface contract**: use code blocks with the actual signature. Do not describe the signature in prose only.
- **Hints**: the good ones acknowledge where students get stuck, without solving it for them. Example (from 6.5840 Raft): "You might find it useful to run `go test -race`." Example of a bad hint: "Think carefully about the invariants." (too vague to help)
- **Hidden tests section**: students hate surprise tests. Describing the *categories* without the contents is the right balance — it lets them defend against the right failure modes.
- **Extensions**: always include. Strong students will do them; it's also a hook for course reputation.

## What to leave OUT of the student doc

- Anything about the reference solution
- Hidden test contents
- Staff-only grading notes or edge-case taxonomies
- The prof's own reflections on "what students usually get wrong" (those go in staff notes, not here)
