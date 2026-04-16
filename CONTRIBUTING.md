# Contributing to Prometheus

Thank you for your interest in improving AI-powered education! Here's how to contribute.

## Ways to Contribute

### 1. Add Example Outputs

Generate a syllabus + lab package for a CS topic not yet covered and submit it as a PR to the `examples/` directory.

**High-value topics we'd love to see:**
- Compilers / Programming Languages
- Distributed Systems
- Computer Security
- Database Systems
- Computer Architecture
- Reinforcement Learning
- Computer Graphics

**How to submit:**
1. Install both skills in Claude.ai
2. Generate a syllabus and at least one lab package
3. Review the output for quality — fix any hallucinated citations, adjust the balance
4. Create `examples/<topic>/syllabus.md` and `examples/<topic>/labs/`
5. Open a PR with a brief note on what you changed from the raw output

### 2. Improve the Skills

The skills themselves are in `course-syllabus-architect/SKILL.md` and `lab-designer/SKILL.md`. Common improvements:

- **Add missing courses to the reference cheat-sheets** (new courses at top universities, courses in under-covered areas)
- **Improve the search query templates** (better queries → better research)
- **Tighten the templates** (if you notice a structural issue in generated output, fix the template)
- **Add topic-specific guidance** (e.g., "for compilers courses, always include a register allocation lab")

### 3. Build Agent 3 (Tutor)

This is the big one. We need a skill that can:
- Take a generated syllabus as context
- Act as a Socratic tutor for the material in that syllabus
- Help students work through labs without giving away answers
- Adapt explanation depth to the student's level

If you're interested, open an issue to discuss the design before writing code.

### 4. Translations

The skills currently work in English and Chinese. We'd welcome:
- Spanish, Portuguese, French, German, Japanese, Korean translations of the reference files
- Testing with non-English prompts and fixing any issues

## Development Setup

1. Clone the repo
2. The skills are plain Markdown — no build step needed
3. To test changes, upload the modified `.skill` file (or the whole skill folder) to Claude.ai
4. To package a skill after changes:
   - Use the `skill-creator` skill's packaging script, or
   - Manually zip the skill directory and rename to `.skill`

## PR Guidelines

- One PR per logical change (don't mix a new example with a skill improvement)
- If changing a skill, describe what you changed and why
- If adding an example, include a brief quality note (what you reviewed, what you fixed)
- Keep commit messages clear

## Code of Conduct

Be kind. This project aims to make education more accessible — let's make the community accessible too.

## Questions?

Open an issue. We're friendly.
