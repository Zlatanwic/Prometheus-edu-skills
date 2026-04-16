---
name: course-syllabus-architect
description: Generate research-informed, frontier-aware course syllabi for top-tier university CS courses. Use whenever a professor or TA asks to design, plan, create, or outline a CS course — e.g., "help me plan a data structures course," "design a distributed systems syllabus," "what should I teach in deep learning this semester," or any request involving course planning, lecture-by-lecture outlines, reading lists, or curriculum design for a university-level CS topic. Fights the problem of CS courses lagging years behind research by systematically pulling from (1) top-university syllabi (MIT/Stanford/Berkeley/CMU), (2) high-impact recent papers from top venues, and (3) reputable industry sources — while preserving foundational material. Trigger even when the user just names a topic area ("深度学习课程", "compilers course") without explicitly saying "syllabus" — if the context is CS course planning, use this skill.
---

# Course Syllabus Architect

A skill for designing frontier-aware, research-informed course syllabi for top-tier university computer science courses.

## The problem this solves

University CS curricula routinely lag 5–10 years behind the research frontier and industry practice. Textbooks get updated slowly; professors reuse slides from previous years; new subfields emerge faster than courses absorb them. A student taking "Distributed Systems" in 2026 may still be taught as if Raft were novel and never hear about modern consensus work, or take "Deep Learning" without encountering anything past the original Transformer paper.

This skill produces a lecture-by-lecture syllabus that is **grounded in foundational material** (because you cannot teach modern RL without MDPs, or modern systems without Lamport) **while integrating frontier knowledge** from the last ~3 years. The goal is a course top-tier students would respect and graduates would actually use.

## The core workflow

Follow these steps in order. Do not skip the research phase — the research is what makes this skill better than brainstorming from memory.

### Step 1: Capture course parameters

Before researching, confirm with the user:

- **Topic** (e.g., "distributed systems", "deep learning", "compilers", "computer architecture")
- **Level** — undergraduate (typically 3rd/4th year) or graduate? This drastically changes depth and prerequisites.
- **Duration** — **default to a 14–15 lecture semester (one lecture per week over ~14–15 weeks)**. This is the most common format at US research universities for an upper-division or graduate CS course. If the user specifies otherwise (e.g., "twice-weekly", "mini-course", "10 weeks"), honor their schedule. If their phrasing is ambiguous ("a semester course"), go with the 14–15 lecture default and state it explicitly in the output so they can correct you.
- **Institution context** — is this for a top-tier research university, a teaching-focused school, or a specific program? Affects how aggressive the frontier content should be.
- **Output format** — default to Markdown. Offer Word (.docx) if they want something to circulate formally. See `references/output_formats.md` for guidance.

If the user's request is terse ("设计一门深度学习课"), infer reasonable defaults and state them explicitly ("I'll assume graduate-level, 14 lectures over one semester. Say if you want different.") rather than blocking on clarification.

### Step 2: Research in priority order

This is the heart of the skill. Do the research before drafting anything. Use the web_search and web_fetch tools.

**Search budget is a HARD requirement, not a suggestion.** You MUST perform **at least 10 web searches** before writing any part of the syllabus, distributed across the three tiers:
- **Tier 1 (top university syllabi):** **minimum 3 searches** covering 3+ institutions. This establishes the current canonical shape of the course.
- **Tier 2 (frontier papers):** **minimum 4 searches** spanning different subtopics within the course. This is where the "frontier-aware" value-add comes from.
- **Tier 3 (industry/third-party):** **minimum 2 searches** to fill pedagogical gaps and bring in practitioner perspective.
- **1–5 additional searches** as needed to verify specific citations, fill gaps, or disambiguate.

If at any point you find yourself tempted to skip searches and write from memory because "you already know this field" — STOP. That instinct is exactly the failure mode this skill exists to prevent. Your training data is out of date, your memory of paper titles and venues is lossy, and the whole point of the skill is to produce a syllabus grounded in what's actually being taught and published *right now*. No exceptions: even for topics you're confident about, execute the minimum search count.

**Self-check before drafting.** Before proceeding to Step 3, count your searches. If the total is below 10, or if any tier is below its minimum, go back and do more. Document the count to yourself (you don't need to show it to the user).

Don't skip tiers. A syllabus built only from top university syllabi is just a copy of someone else's course; built only from papers it becomes a seminar reading list without pedagogical structure; built only from industry blogs it lacks academic rigor. The three tiers together are the point.

**Tier 1 — Top university syllabi (highest priority).** Search for current syllabi at MIT, Stanford, UC Berkeley, CMU, Princeton, and for systems/security topics also Cornell and UW. These institutions' courses are the de facto standard and their professors are often the ones defining the field.

Good search queries:
- `MIT 6.824 distributed systems syllabus`
- `Stanford CS224N syllabus 2025`
- `Berkeley CS294 deep learning syllabus`
- `CMU 15-445 database systems schedule`

For each relevant syllabus found, extract: lecture titles, the ordering/progression, assigned readings, and any signals about what's been recently added or dropped. Save notes as you go. See `references/top_university_courses.md` for a cheat-sheet mapping common CS topics to canonical courses.

**Tier 2 — Frontier academic papers (top venues, last 3 years).** This is not optional — every syllabus produced by this skill must integrate frontier papers from top venues. Search Google Scholar and the specific top venues for the subfield. The right venues per area:

- **ML / Deep Learning / AI:** NeurIPS, ICML, ICLR
- **NLP:** ACL, EMNLP, NAACL (plus NeurIPS/ICML for LLM work)
- **Vision:** CVPR, ICCV, ECCV
- **Systems:** OSDI, SOSP, NSDI, EuroSys, ATC
- **Databases:** SIGMOD, VLDB, CIDR
- **Networks:** SIGCOMM, NSDI
- **Security:** USENIX Security, CCS, S&P (Oakland), NDSS
- **PL / Compilers:** PLDI, POPL, OOPSLA, ICFP
- **Architecture:** ISCA, MICRO, ASPLOS, HPCA
- **HCI:** CHI, UIST, CSCW
- **Graphics:** SIGGRAPH, SIGGRAPH Asia
- **Theory:** STOC, FOCS, SODA

Good search queries:
- `site:scholar.google.com <subtopic> 2024 2025`
- `<subtopic> survey paper 2024`
- `best papers OSDI 2024`
- `NeurIPS 2024 outstanding paper <subtopic>`
- `<foundational concept> recent advances`

Prioritize: (a) survey papers that already did the synthesis work, (b) papers with unusually high citations given their recency, (c) papers from the top labs in the field (DeepMind, FAIR, OpenAI, Anthropic, MSR, Google Research, Berkeley RISE/Sky, Stanford AI Lab, MIT CSAIL, etc.), (d) "best paper" or "outstanding paper" award winners at top venues.

**Tier 3 — Reputable industry sources and third-party media.** Include these to fill gaps and improve pedagogical clarity. Useful categories:

- **Engineering blogs from first-tier companies:** Google Research, Meta AI/Engineering, Netflix Tech Blog, Cloudflare Blog, Uber Engineering, Stripe Engineering, Discord Engineering. Also Anthropic, OpenAI, and DeepMind research pages for ML.
- **High-quality technical talks:** Strange Loop, QCon, ACM conferences' recorded keynotes, YouTube channels of top labs.
- **Reputable independent technical writers:** For ML — Lilian Weng (OpenAI), Chip Huyen, Jay Alammar, Sebastian Raschka, Andrej Karpathy's posts/videos. For systems — Murat Demirbas, Marc Brooker (AWS), Kyle Kingsbury (Jepsen). For databases — Andy Pavlo's writings, Alex Petrov.
- **Authoritative aggregators:** The Morning Paper (adrianco's archive), Papers We Love, ACM Queue.

Industry sources are especially valuable for topics where **practice leads academia** (large-scale distributed systems, ML infrastructure, security), and for pedagogically clear explanations of papers that are themselves dense. Use them — but always prefer a primary paper when one exists.

**On foundations — this is non-negotiable.** The skill must NOT produce a syllabus that is all frontier and no bedrock. Every course needs its canonical foundations, taught early, because frontier work is incomprehensible without them. Examples:

- Distributed systems → must include Lamport's logical clocks, FLP impossibility, CAP, Paxos/Raft, 2PC — before anything about modern blockchain consensus or geo-distributed databases.
- Deep learning → must include backprop, SGD, regularization, CNNs, RNNs, the original Transformer — before anything about RLHF, mixture-of-experts, or reasoning models.
- Databases → must include relational model, B-trees, query optimization, ACID, MVCC — before anything about vector DBs or learned indexes.
- OS → must include processes, virtual memory, file systems, scheduling — before anything about unikernels or serverless runtimes.

A rough rule: **roughly 60–70% of the course should be foundational, 30–40% frontier**, but this varies by subject. Fast-moving fields like deep learning tilt more toward frontier; slow-moving fields like algorithms tilt more toward foundations.

### Step 3: Synthesize into a lecture plan

Now combine the research into a concrete lecture-by-lecture plan. Structure:

1. **Course overview** — 1–2 paragraphs on what students will learn and why it matters in 2026.
2. **Prerequisites** — what students must know coming in.
3. **Learning outcomes** — 4–6 bullet points of what a student can do after the course.
4. **Module structure** — group lectures into 3–5 modules (e.g., "Foundations", "Core Techniques", "Scaling & Systems", "Frontier Topics").
5. **Lecture-by-lecture outline** — for each lecture include:
   - Lecture number and title
   - Week number
   - Core topics (bullet list, 3–5 items)
   - Primary readings — mix of foundational and recent (cite full paper titles + year + venue; cite textbook chapters by chapter number and book)
   - Optional/advanced readings
   - A one-sentence note on **why this lecture exists** and how it connects to the one before and after (this forces coherence)
   - For frontier lectures, explicitly flag "**Frontier:**" and note the recent paper/development being integrated
6. **Assignments and projects** — 3–5 assignments that build on each other, plus a final project suggestion.
7. **A short "What's been added vs. a traditional course" section** — explicitly call out what's newer than what students would find in a standard textbook. This is a unique value-add and helps the instructor explain their choices.

See `references/syllabus_template.md` for the exact layout to follow.

### Step 4: Cite everything

Every paper mentioned in readings must have: title, first author, year, venue. Every textbook must have: book name, chapter, author. Every blog/talk must have: title, author, URL. Sloppy citations destroy the credibility of the output. Top-tier professors will notice.

### Step 5: Citation verification — every paper must be grounded in a search

This is where most failure modes show up in practice, so it gets its own step.

**The rule:** before any paper appears in the final syllabus, it must have been surfaced or confirmed by a web search in this same conversation. No paper goes into the output from memory alone.

**Why this matters.** Claude's memory of the literature is lossy: titles get near-miss wrong ("Attention Is All You Need" is a hit; "Attention is What You Need" is a hallucination), authors get confused, years drift, venues get swapped. A syllabus handed to a top-tier professor with a single phantom citation is dead on arrival. It's not merely embarrassing — it signals the whole document wasn't researched.

**How to verify:**
1. After drafting the lecture-by-lecture plan, make a list of every paper cited (including the "canonical" ones you feel certain of — Vaswani 2017, He 2016, Kingma 2014, etc.).
2. For each paper, either (a) it was already returned in one of your Tier 1/2/3 searches — fine, verified, move on; or (b) it was not — run a specific search for it now, e.g., `"Attention Is All You Need" Vaswani 2017`.
3. If a search fails to turn up a clear match for the exact title/author/year/venue you wrote, **either find the correct citation or remove the reference**. Do not keep an unverified citation.
4. For textbooks (Goodfellow-Bengio-Courville, Russell-Norvig, etc.), verify the edition and year via search if you haven't already.
5. For blog posts (Karpathy, Lilian Weng, Jay Alammar), verify the post actually exists by searching for its title — these are the easiest category to hallucinate.

This verification phase typically adds 2–5 searches beyond the 10 minimum from Step 2 — budget for them.

**Do not tell the user about this verification step** in the final output; they just expect citations to be correct. But do not skip it.

### Step 6: Pre-delivery self-check

Before writing the file, confirm:

- [ ] Did you perform at least 10 web searches across the three tiers?
- [ ] Is every paper citation grounded in an actual search result (not just memory)?
- [ ] Does the first 40–50% of the course cover foundational material? (If the first five lectures are all about frontier topics, you've failed the foundations test.)
- [ ] Does every frontier lecture have a `**Frontier:**` note explaining why the recent material earns its slot?
- [ ] Does every lecture have a `**Why this lecture:**` note connecting it to neighbors?
- [ ] Is there a "What's Been Added vs. a Traditional Course" section?
- [ ] Does the lecture count match what the user asked for (default: 14–15)?
- [ ] Are all venue names and years on paper citations correct and spelled consistently?

If any check fails, fix it before delivering.

### Step 7: Deliver

Write the syllabus to a file at `/mnt/user-data/outputs/<topic>-syllabus.md` (or `.docx` if requested). Use the `present_files` tool to make it accessible. Include a brief summary in chat of: (1) total lectures planned, (2) 2–3 highlights of frontier material integrated, (3) key design trade-offs you made (e.g., "I gave RLHF a full lecture rather than a half because it's essential for understanding modern LLMs").

**Finally, prompt the user about the companion skill.** End the response with a short note offering to generate detailed lab/assignment packages for this course. Phrase it simply, for example:

> If you'd like, I can also generate full lab documents and code scaffolds for the assignments above — complete with instructions, starter code, test harnesses, and staff solutions, in the style of the best MIT/Stanford/Berkeley labs. Just say "design the labs" or "generate lab N" and I'll switch to the `lab-designer` skill.

This is a soft handoff: the user decides whether to invoke it. Don't automatically spawn lab generation — that's a major piece of work and deserves an explicit go-ahead.

## Common pitfalls to avoid

- **All frontier, no foundations.** Tempting because frontier material is exciting, but makes a course that doesn't work. Check: does the first third of the course look like a "classical" version of this course? It should.
- **Shallow research — doing fewer than the required 10 searches.** Producing a syllabus from memory without actually searching is the failure mode this skill exists to prevent. If you find yourself about to draft the syllabus and you've run fewer than 10 searches, stop and search more. Skipping searches to "save time" destroys the entire value proposition of the skill.
- **Cargo-culting MIT/Stanford.** Don't just copy a top school's syllabus verbatim. Understand why each lecture is where it is, then adapt.
- **Overstuffing lectures.** Each 75-minute lecture can realistically cover 3–5 concepts well. Cutting is harder than adding — be willing to cut.
- **Ignoring pedagogical flow.** Lecture N+1 should build on lecture N. Don't introduce an advanced topic before its prerequisites.
- **HALLUCINATED citations — the single most fatal failure mode.** Never write a paper title, author name, year, or venue from memory. Even papers you're "sure about" (Attention Is All You Need, ResNet, DDPM) should be verified against a search in this conversation, because your memory of exact titles and metadata is lossy. One phantom reference destroys the credibility of the entire document. See Step 5 for the verification protocol — it is not optional.
- **Ignoring the request's scope.** If they asked for a 10-week short course, don't produce a 28-lecture plan.

## Tone and voice

The user is a top-tier CS professor or TA. Write for that audience: technical, precise, no hand-holding, no apologizing for the depth. Assume they know the field. Your value-add is the synthesis and the frontier integration, not explaining what a B-tree is.

Chinese-speaking users may request output in Chinese — produce the syllabus in Chinese in that case, but keep English paper titles and venue names in their original form (don't translate "NeurIPS" or paper titles).

## Reference files

- `references/top_university_courses.md` — Mapping of common CS course topics to the canonical courses at MIT, Stanford, Berkeley, CMU. Consult this before Tier 1 research to know where to look.
- `references/syllabus_template.md` — The exact output template for the final deliverable.
- `references/output_formats.md` — Guidance on choosing and producing Markdown vs. Word vs. PDF output.
