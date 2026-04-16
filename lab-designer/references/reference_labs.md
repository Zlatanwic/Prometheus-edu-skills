# Reference Labs Cheat-Sheet

This maps common CS course topics to the canonical labs at top universities. These labs are the structural references to emulate. Always **search for the current versions** before designing — course labs are updated frequently, and GitHub repos may have newer releases than the course page.

## Systems

### Operating Systems
- **MIT 6.1810 (6.S081)** — xv6 labs (booting, syscalls, paging, copy-on-write, locks, file system). Probably the gold standard for OS labs in the world.
- **Stanford CS140** — Pintos labs (threads, userprog, VM, file systems).
- **Berkeley CS162** — Pintos-based with variations.

### Distributed Systems
- **MIT 6.5840 (6.824)** — Labs 1–4: MapReduce, Raft (leader election, log, persistence, snapshot), fault-tolerant KV store, sharded KV store. The Raft lab in particular is the reference for how to scaffold a hard systems implementation.
- **Princeton COS-418** — Similar structure, different problem set.
- **CMU 15-440** — DFS, MapReduce variants.

### Databases
- **CMU 15-445/645 (Andy Pavlo)** — BusTub labs: buffer pool, B+ tree, query execution, concurrency control, logging/recovery. Extremely well-scaffolded with clear grading rubrics.
- **Berkeley CS186** — Project 1–6 covering B+ tree, joins, transactions, recovery, query optimization.
- **MIT 6.5830** — SimpleDB labs.

### Networks
- **Stanford CS144** — Build a TCP-in-userspace. One of the most celebrated systems labs anywhere.
- **MIT 6.829** — Networks lab sequence.

### Compilers
- **Stanford CS143** — Cool compiler (lexer, parser, semantic analysis, codegen).
- **CMU 15-411** — C0 compiler in 5 stages over the semester.
- **Cornell CS 4120** — Xi compiler.

### Computer Architecture
- **Berkeley CS61C** — numc (SIMD-accelerated matrix operations), venus (RISC-V assembly).
- **CMU 18-447** — pipelined processor projects.

### Programming Languages
- **CMU 15-312** — interpreter/compiler for functional language progressions.
- **Penn CIS 1200** — OCaml-based assignments.

## ML / AI

### Intro ML
- **Stanford CS229** — mostly problem sets, but strong math-heavy coding homework.
- **CMU 10-601/701** — programming homework in specific algorithms (decision trees, neural nets, HMMs).

### Deep Learning
- **Stanford CS230** — project-focused; less prescriptive labs.
- **Stanford CS231N** — the reference for vision labs: assignment 1 (kNN, SVM, softmax, two-layer net), assignment 2 (fully connected + conv nets + batch norm + dropout), assignment 3 (RNN/LSTM, transformer, GANs). Well-scaffolded Jupyter notebooks; a great template.
- **MIT 6.S191** — mostly tutorial notebooks rather than graded labs, but polished.

### NLP / LLMs
- **Stanford CS224N** — assignment 1 (exploring word vectors), assignment 2 (word2vec), assignment 3 (dependency parser), assignment 4 (NMT with attention), assignment 5 (self-attention/transformers/pretraining). The assignment 5 scaffold is a great reference for "teach Transformers from scratch" labs.
- **CMU 11-711/737** — coding assignments tied to specific architectures.

### Computer Vision
- **Stanford CS231N** — see deep learning above.
- **CMU 16-385** — classical CV labs (SIFT, stitching, epipolar).

### Reinforcement Learning
- **Berkeley CS285** (Sergey Levine) — homework 1 (behavior cloning), 2 (policy gradients), 3 (Q-learning and actor-critic), 4 (model-based RL), 5 (exploration). Excellent progression.
- **Stanford CS234** — RL homework.

## Theory & Algorithms
- **MIT 6.1220 / 6.5210** — problem sets, usually paper-based. Labs rare.
- **Stanford CS161 / CS261** — problem sets with optional coding.

## Security
- **MIT 6.5660 (6.858)** — labs: buffer overflows, symbolic execution, privsep, web security, Tor. Classic hands-on offensive/defensive sequence.
- **Stanford CS155** — ctf-style projects.

## Graphics
- **Stanford CS148/248** — rasterization, ray tracing, animation labs.
- **CMU 15-462** — Scotty3D labs.

## Where to look things up

- **Top university course pages** almost always link to their lab/assignment sequence. Search `<institution> <course number> labs` or `<institution> <course number> assignments`.
- **Public GitHub repos**: e.g., `github.com/mit-pdos/xv6-riscv-fall19` (MIT xv6), `github.com/cmu-db/bustub` (CMU DB), `github.com/stanford-cs221/` etc. Many courses release their scaffolds publicly.
- **Archive.org** for older versions if the current site has changed.

## When the topic isn't in this list

This list is non-exhaustive. Search `<institution> <topic> lab site:.edu` or `<topic> course project starter code github`. For very new topics (alignment, inference systems), look at HuggingFace Learn courses, official paper repos, or recent tutorial collections from Anthropic/OpenAI.
