# Syllabus Output Template

Use this exact structure for the final deliverable. Section ordering matters; don't rearrange.

```markdown
# <Course Title>
**Level:** <Undergraduate / Graduate>
**Duration:** <N weeks, M lectures per week, ~T total lectures>
**Prepared:** <Month Year>

## Course Overview

<1–2 paragraphs. State what the course is about, what makes this version timely
in <current year>, and the philosophy behind the syllabus. This is where you
briefly justify the foundations-vs-frontier balance.>

## Prerequisites

- <Prereq 1, ideally with the typical course name at a US university>
- <Prereq 2>
- ...

## Learning Outcomes

By the end of this course, students will be able to:
1. <Outcome 1 — start with a verb: design, analyze, implement, evaluate, etc.>
2. ...
6. ...

## Required Texts and Resources

- **Primary textbook:** <Author, Title, Edition, Year> — used for chapters X, Y, Z
- **Secondary references:** <list as needed>
- **Papers:** Distributed throughout the schedule below

## Module Structure

| Module | Lectures | Theme |
|---|---|---|
| 1. Foundations | 1–5 | <theme> |
| 2. Core Techniques | 6–9 | <theme> |
| 3. Scaling and Systems | 10–12 | <theme> |
| 4. Frontier Topics | 13–14 | <theme> |

(Adjust module boundaries based on topic; the 14-lecture breakdown is a starting point, not a constraint. A fast-moving field like deep learning may compress foundations into 3 lectures; a foundations-heavy field like compilers may push module 4 down to a single lecture.)

## Lecture-by-Lecture Schedule

### Module 1: Foundations

#### Lecture 1 (Week 1) — <Title>
**Topics:**
- <Topic 1>
- <Topic 2>
- <Topic 3>

**Readings:**
- <Textbook>, Chapter X
- <Foundational paper, e.g., Lamport 1978, "Time, Clocks, and the Ordering of Events in a Distributed System", CACM>

**Optional:**
- <Optional reading>

**Why this lecture:** <One sentence on its role in the arc.>

---

#### Lecture 2 (Week 2) — <Title>
... (same structure)

---

[continue for all lectures — one lecture per week for a standard 14-lecture semester]

---

### Module 4: Frontier Topics

#### Lecture 13 (Week 13) — <Title>
**Topics:**
- ...

**Readings:**
- <Recent paper: First Author et al., Year, "Paper Title", Venue>

**Frontier:** <One sentence on what makes this material recent and why
it earns a slot. E.g., "Speculative decoding (Leviathan et al., 2023, ICML)
is now standard in production LLM serving and should be taught alongside
classical inference optimization.">

**Why this lecture:** ...

---

## Assignments

### Assignment 1: <Name> (due Week X)
<2–3 sentence description. What students build, what they learn, what's evaluated.>

### Assignment 2: ...

### Final Project
<Description, scope, group size, milestones, suggested topic areas. The
final project should ideally have a frontier-leaning option for ambitious students.>

## Grading

| Component | Weight |
|---|---|
| Assignments | X% |
| Midterm | Y% |
| Final project | Z% |
| Participation | W% |

## What's Been Added vs. a Traditional Course

This is a candid note from the syllabus designer. List 3–6 specific additions
(or omissions) compared to a textbook-driven version of this course from
~5 years ago. This helps the instructor explain choices to colleagues and
to students.

Examples:
- **Added:** A full lecture on <recent technique>, drawn from <paper>. This is
  now standard in industry but absent from <classic textbook>.
- **Cut:** <Older topic> reduced from a full lecture to a half lecture, since
  modern practice has largely subsumed it under <newer abstraction>.
- **Reordered:** <Topic> moved earlier because students now encounter it via
  <common modern context> before they take this course.

## References by Lecture (Bibliography)

A consolidated list of every paper and resource cited above, in citation
format suitable for a course webpage.

```

## Formatting notes

- Use `---` between lectures for visual separation.
- Bold the labels (`**Topics:**`, `**Readings:**`, `**Frontier:**`, `**Why this lecture:**`) consistently.
- Paper citations: `First Author et al., Year, "Title", Venue` — keep this exact form.
- Don't use emoji. This is a formal academic document.
- If output is in Chinese, translate section headings and prose, but keep paper titles, venue names, course numbers, and author names in English.
