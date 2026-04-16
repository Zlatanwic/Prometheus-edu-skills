<div align="center">

# 🔥 Prometheus

**AI-Powered Course Design System for the Age of Frontier Knowledge**

*Three agents. One classroom. Zero lag behind the research frontier.*

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Claude Skills](https://img.shields.io/badge/Claude-Skills-blueviolet)](https://claude.ai)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md)

[English](#english) · [中文](#中文)

</div>

---

## The Problem

University CS courses are **5–10 years behind** the research frontier. A student taking "Deep Learning" in 2026 might never hear about RLHF, FlashAttention, or speculative decoding — concepts that are already standard in industry. Textbooks update slowly, professors reuse old slides, and new subfields emerge faster than curricula absorb them.

Meanwhile, the best course materials in the world — MIT's 6.5840 Raft labs, Stanford's CS231N notebooks, CMU's database internals projects — are publicly available but scattered across dozens of `.edu` sites, and synthesizing them into a coherent course is still a manual, weeks-long process.

## The Vision

**Prometheus** is a set of Claude AI skills that automate the hardest parts of course design, while keeping the professor (or self-learner) in the driver's seat.

The core idea is a **three-agent paradigm** for AI-native education:

```
┌─────────────────────────────────────────────────────────┐
│                   Prometheus                        │
│                                                         │
│  ┌─────────────┐  ┌──────────────┐  ┌───────────────┐  │
│  │   Agent 1    │  │   Agent 2    │  │   Agent 3     │  │
│  │  Architect   │→ │  Lab Master  │→ │   Tutor       │  │
│  │             │  │              │  │  (coming soon) │  │
│  │ Designs the │  │ Builds the   │  │ Teaches the   │  │
│  │ syllabus    │  │ labs & code  │  │ material      │  │
│  └─────────────┘  └──────────────┘  └───────────────┘  │
│        │                │                    │          │
│        ▼                ▼                    ▼          │
│   Lecture-by-      Starter code,       Interactive     │
│   lecture plan     test harness,       Q&A, concept    │
│   with readings    staff solution      explanation     │
└─────────────────────────────────────────────────────────┘
```

**Agent 1 — Architect** (`course-syllabus-architect`): Designs frontier-aware, research-grounded syllabi by systematically pulling from MIT/Stanford/Berkeley/CMU course pages, recent top-venue papers, and reputable industry sources. Every citation is web-search-verified. Every lecture has a reason for existing.

**Agent 2 — Lab Master** (`lab-designer`): Generates MIT/Stanford-quality lab packages — student-facing docs, starter code scaffolds (Jupyter notebooks for ML, `src/tests/` projects for systems), public test harnesses, hidden grading tests, and working staff solutions. Auto-detects the right code format from the course topic.

**Agent 3 — Tutor** *(coming soon)*: An AI teaching assistant that can explain concepts from the generated syllabus, walk students through lab problems with Socratic questioning, and adapt to individual learning pace. The missing piece that turns static materials into a living classroom.

## Who Is This For?

### 🎓 For Professors and TAs

You have deep domain expertise but limited time. You know what the frontier looks like but turning that into 14 polished lectures with readings, labs, and grading rubrics takes weeks. Prometheus gives you a **solid first draft in minutes** that you then refine with your judgment.

*"I used it to redesign my graduate distributed systems course. It found three papers from OSDI 2024 that I hadn't seen yet and suggested restructuring the Raft module — both changes I kept."*

### 📚 For Self-Learners

You want to teach yourself a CS topic **the way it's taught at MIT**, not from a random YouTube playlist. Prometheus generates a structured learning path with the same readings, the same progression, and the same caliber of labs — but adapted to self-study pace.

*"I wanted to learn deep learning properly. It gave me a 14-lecture plan with papers, a notebook lab sequence, and even told me which MIT lectures to watch in what order."*

### 🏫 For Universities in Developing Regions

The gap between MIT and a typical university isn't talent — it's access to current course design. A professor in Chengdu, São Paulo, or Lagos should be able to offer a course as current as one at Stanford. Prometheus makes that possible by democratizing the synthesis work that top-university course staff do every semester.

## Quick Start

### Installation

1. Go to [claude.ai](https://claude.ai) → Settings → Feature Preview → Skills
2. Upload both `.skill` files:
   - `course-syllabus-architect.skill`
   - `lab-designer.skill`
3. Start a new conversation.

### Usage

**Design a course:**
```
帮我设计一门研究生深度学习课程
```
or
```
Design a graduate-level distributed systems course, 14 weeks
```

The Architect agent will:
- Search 10+ sources across top-university syllabi, frontier papers, and industry blogs
- Produce a lecture-by-lecture plan with verified citations
- Balance ~60% foundational material with ~40% frontier content
- Suggest labs/assignments
- Offer to hand off to the Lab Master

**Design the labs:**
```
Design the labs
```
or
```
详细做 Lab 2 (Raft) 的实验包
```

The Lab Master agent will:
- Show a menu of all labs with summaries
- Let you pick which to build out
- Generate a full package per lab: student doc, starter code, tests, staff solution

## What Makes This Different

| Feature | Traditional approach | Prometheus |
|---|---|---|
| **Freshness** | Reuse last year's slides | Web-searches 10+ current sources per run |
| **Citations** | Memory-based, error-prone | Every paper verified by live search |
| **Lab quality** | One-paragraph prompts | MIT-style packages with scaffold + tests + solution |
| **Code format** | One-size-fits-all | Auto-detects: notebooks for ML, projects for systems |
| **Foundation-frontier balance** | Ad hoc | Enforced ~60/40 split with explicit justification |
| **Iteration** | Start from scratch | Modular: fix one lecture without regenerating all 14 |

## Architecture

```
Prometheus/
├── course-syllabus-architect/          # Agent 1: Syllabus design
│   ├── SKILL.md                        # Core workflow (7 steps)
│   └── references/
│       ├── top_university_courses.md   # MIT/Stanford/Berkeley/CMU course mapping
│       ├── syllabus_template.md        # Output format template
│       └── output_formats.md           # Markdown / Word / PDF guidance
│
├── lab-designer/                       # Agent 2: Lab generation
│   ├── SKILL.md                        # Core workflow (5 steps, two-phase)
│   └── references/
│       ├── reference_labs.md           # Top-university lab cheat-sheet
│       ├── lab_document_template.md    # Student-facing doc template
│       └── scaffold_patterns.md        # Notebook vs. project patterns
│
├── README.md
├── LICENSE
└── examples/
    └── graduate-deep-learning/         # Example output
        ├── syllabus.md                 # Generated syllabus (14 lectures)
        └── labs/                       # Generated lab packages
```

## The Three-Tier Research Method

The Architect agent doesn't just brainstorm — it follows a rigorous, enforced research protocol:

**Tier 1 — Top University Syllabi** *(highest priority, minimum 3 searches)*
Search MIT, Stanford, Berkeley, CMU for the canonical version of this course. Extract: lecture ordering, readings, what's been recently added or dropped.

**Tier 2 — Frontier Papers** *(minimum 4 searches)*
Search Google Scholar and top venues (NeurIPS, OSDI, SIGMOD, etc.) for high-impact recent work. Prioritize: survey papers, best-paper winners, papers from top labs.

**Tier 3 — Industry Sources** *(minimum 2 searches)*
Google Research blogs, Lilian Weng, Chip Huyen, engineering blogs from Meta/Netflix/Cloudflare. Fills pedagogical gaps where practice leads academia.

**Hard rules:**
- Minimum **10 web searches** per syllabus — enforced, not suggested
- Every citation **verified by search** in the same session (Step 5)
- **60–70% foundational, 30–40% frontier** content ratio
- A **pre-delivery checklist** of 7 items must pass before output

## Lab Design Philosophy

The Lab Master follows principles distilled from the best CS labs in the world:

- **The 3-hour onramp rule**: Clone → install → run failing tests → understand Part 1 in under 3 hours
- **Interface contracts, not implementation contracts**: Specify *what*, not *how*
- **Public + hidden tests**: Students self-check locally; grading catches shortcuts
- **Staff solutions are real code**: Not pseudocode — a working implementation that passes all tests
- **Auto-format detection**: ML/DL/data → Jupyter notebooks; systems/compilers/OS → `src/tests/` projects

## Roadmap

- [x] **Agent 1: Architect** — Frontier-aware syllabus generation
- [x] **Agent 2: Lab Master** — Professional lab package generation
- [ ] **Agent 3: Tutor** — AI TA for interactive concept explanation and lab help
- [ ] **Multi-language support** — Full Chinese/Spanish/Portuguese UI (currently: Chinese supported in output, English in skill instructions)
- [ ] **Exam generator** — Midterm and final exam design with rubrics
- [ ] **Course website generator** — Auto-generate a static course site from the syllabus

## Examples

See the [`examples/`](examples/) directory for full generated outputs:

- **Graduate Deep Learning** (14 lectures) — includes FlashAttention, DPO, speculative decoding, VAR
- *(more coming soon — PRs welcome!)*

## Contributing

We welcome contributions! Some high-impact areas:

- **New example outputs** for different CS topics (compilers, databases, security, etc.)
- **Agent 3 (Tutor)** — help us design the Socratic questioning workflow
- **Translations** — localize the skill instructions for non-English users
- **Topic-specific reference files** — add top-university course mappings for under-covered areas (HCI, graphics, quantum computing)

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## License

MIT License. See [LICENSE](LICENSE) for details.

## Acknowledgments

This project stands on the shoulders of the world's best CS educators. The course designs referenced herein belong to their respective institutions and instructors:

- MIT (6.5840, 6.1810, 6.S191), Stanford (CS231N, CS224N, CS144, CS230), UC Berkeley (CS182, CS285, CS162, CS186), CMU (15-445, 15-411, 10-701), NYU (DS-GA 1008), Princeton (COS-418), and many others.

We don't copy their courses — we learn from their structure, then synthesize something new. If you're an instructor at one of these institutions and have feedback, we'd love to hear from you.

---

<div align="center">

**Built with [Claude](https://claude.ai) · Powered by frontier research · Open for everyone**

*"The best time to update a CS curriculum was last year. The second best time is now."*

</div>

---

<a name="中文"></a>

## 中文说明

### 问题

大学CS课程普遍落后研究前沿5-10年。2026年修"深度学习"的学生可能从未听说过RLHF、FlashAttention或推测解码——这些在工业界早已是标配。教科书更新慢，教授复用老幻灯片，新子领域的涌现速度远超课程吸收的速度。

### 解决方案

**Prometheus** 是一套Claude AI技能(Skills)，自动化课程设计中最费时的部分，同时把控制权留给教授（或自学者）。

核心理念是 **三Agent教育范式**：

- **Agent 1 — 架构师**：设计前沿感知的课程大纲。从MIT/Stanford/Berkeley/CMU的课程页面、顶会论文、业界博客三层信号源中系统调研，每条引用都经过web搜索验证。
- **Agent 2 — 实验大师**：生成MIT/Stanford级别的实验包——学生文档、起始代码脚手架（ML选Jupyter notebook，系统课选`src/tests/`项目结构）、公开测试套件、隐藏评分测试、教师参考解。
- **Agent 3 — 导师**（即将推出）：AI助教，能围绕生成的大纲讲解概念，用苏格拉底式提问引导学生完成实验，适应个人学习节奏。

### 适用人群

- **高校教师/助教**：有深厚领域知识但时间有限。Prometheus在几分钟内给出一个坚实的初稿，你再用专业判断打磨。
- **自学者**：想按MIT/Stanford的方式系统学一个CS领域。Prometheus生成结构化学习路径，含论文、教材章节、实验，进度可自定。
- **发展中地区高校**：MIT和一所普通大学之间的差距不是人才，是获取当前课程设计的渠道。Prometheus让成都、圣保罗或拉各斯的教授也能开出和Stanford同样前沿的课程。

### 快速开始

1. 到 [claude.ai](https://claude.ai) → 设置 → Skills → 上传 `.skill` 文件
2. 新建对话，输入："帮我设计一门研究生深度学习课程"
3. 架构师Agent会搜索10+来源，生成14讲课程大纲
4. 输入"设计实验"，实验大师Agent接力生成实验包

### 许可

MIT License。详见 [LICENSE](LICENSE)。
