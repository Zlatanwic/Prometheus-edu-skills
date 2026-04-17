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

After writing the Motivation paragraph, verify: **does this paragraph introduce any technical concept that a student would not yet have encountered?** If yes, either (a) move it to the Prerequisites or New Concepts section, or (b) rewrite it to be accessible to a student who has only attended prior lectures. The Motivation should inspire, not intimidate.

## Learning outcomes

After completing this lab, you will be able to:
1. <Outcome 1 — verbs like "implement", "analyze", "debug", "explain">
2. ...
4. ...

## Prerequisites and knowledge map

**Critical: this section maps every concept used in this lab to where it was taught in the course.** If a concept does not appear here, you have not encountered it before — and if this lab requires it, that is a bug in the lab design. Report it to course staff.

| Concept | Where it was taught | What you need to know |
|---|---|---|
| <concept A> | Lecture N: <title> | <specific recall — e.g., "you know how to implement a goroutine and use channels"> |
| <concept B> | Lecture M: <title> | <specific recall> |
| <new concept C> | **Not in course** — see "New concepts" below | — |

If any row above references a lecture you have not yet attended, <b>do not start this lab</b>. Come back after that lecture, or speak with course staff.

### New concepts introduced by this lab

This lab teaches concepts that do not appear in any prior lecture. You will learn them as part of this lab:

- **<New Concept 1>** — <one-sentence description>. <Beginner-friendly resource: e.g., [Link to relevant tutorial, official docs, or section of a popular learning resource]>
- **<New Concept 2>** — <one-sentence description>. <Beginner-friendly resource:>

> **Why this is intentional:** Good labs sometimes introduce small, focused new tools or patterns — a new standard library module, a language feature, a small algorithmic technique — that are best learned in context. We keep these small and provide clear pointers so they do not block you.

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

Break the lab into 3–5 numbered parts. Each part is a checkpoint with its own tests passing. **Parts must be ordered so that each one depends only on concepts from earlier lectures or from a previous part of this lab.** If you find yourself writing "for this part you will also need to understand X, which we have not covered yet" — that is a signal to reorder the parts or reconsider the scope.

### Part 1: <Sub-title>

<Describe what the student implements in this part. Be specific about
the interface contract (function signatures, CLI behavior, file format)
but leave implementation choice to them.>

**What you need:** Only concepts from Lecture(s) <N, M> or the "New concepts" section above.

**Interface contract:**
\`\`\`<language>
<Function/class signature the student must implement exactly as shown>
\`\`\`

**What success looks like:** When Part 1 is done, \`<specific test command>\` should show all tests in \`test_part1.<ext>\` passing.

**Step-by-step guidance:**
1. <First concrete step — what to do before writing any code>
2. <Second step — e.g., "read the docstring on function X">
3. <Third step — e.g., "implement the straightforward case first, handle the edge case in step N">

**Common sticking points:**
- <Stuck point 1 — here's the conceptual key without giving the answer>
- <Stuck point 2>

### Part 2: <Sub-title>

**What you need:** Everything from Part 1, plus <specific new lecture or concept>. If you have not attended that lecture yet, finish Part 1 and return later.

<Same structure as Part 1>

### Part 3: <Sub-title>
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

- **Motivation**: reference the actual system or paper the lab mirrors. "You'll implement a simplified version of the MapReduce system from Dean and Ghemawat 2004" is better than "You'll implement a distributed processing system." Every technical term in this paragraph must either appear in a prior lecture or in the Prerequisites table above — not introduce new terms that students have not seen.
- **Prerequisites and knowledge map**: This is the most critical new section. For every non-trivial identifier, library call, language construct, or algorithmic concept used in the lab code, map it to where in the course syllabus it was introduced. If no such mapping exists, that concept is either (a) a "new concept" that this lab teaches, or (b) a bug — do not silently assume students know it. The "New concepts" subsection should contain no more than 2–3 items per lab and each must have a concrete learning resource.
- **Learning outcomes**: limit to 3–5 items. More than that and none of them land.
- **Interface contract**: use code blocks with the actual signature. Do not describe the signature in prose only.
- **The lab in parts — "What you need"**: Explicitly state which lectures or prior lab parts each section depends on. This is the progressive disclosure in action — students know exactly what they need before starting each part.
- **Step-by-step guidance**: Each part should include 3–5 numbered steps that are concrete actions, not conceptual nudges. "Read the docstring for `func Merge` in `raft.go`" is a good step. "Think carefully about the invariants" is a bad step.
- **Common sticking points**: These are not hints — they are the top 2–3 places where a prepared student still gets derailed. Write them from the perspective of "I watched 30 students get stuck here last semester." Each should name the symptom ("your test hangs after 10 seconds") and the conceptual key to unblocking, not the answer.
- **Hidden tests section**: students hate surprise tests. Describing the *categories* without the contents is the right balance — it lets them defend against the right failure modes.
- **Extensions**: always include. Strong students will do them; it's also a hook for course reputation.

## What to leave OUT of the student doc

- Anything about the reference solution
- Hidden test contents
- Staff-only grading notes or edge-case taxonomies
- The prof's own reflections on "what students usually get wrong" (those go in staff notes, not here)
- Any technical term that has not been introduced in a prior lecture AND is not listed in the Prerequisites table
- Code patterns, library calls, or language features not mapped in the Prerequisites table
