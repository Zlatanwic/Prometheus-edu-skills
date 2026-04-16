# Graduate Deep Learning — Syllabus

**Level:** Graduate (first-year PhD or advanced MS)
**Duration:** 14 lectures, one per week (one semester)
**Prepared:** April 2026

## Course Overview

This is a research-oriented graduate course in deep learning. It is designed for students who will either do research in ML or build systems that rely on deep models, and who need to be current with the state of the field as of 2026 — not the state of the field as reflected in textbooks written around 2018.

The course is structured around two commitments. First, **no hand-waving on foundations:** students will derive backprop, implement an MLP and a convnet from scratch in NumPy, and understand optimization well enough to debug a training run that isn't converging. This is the 60% of the course where we go slow. Second, **serious engagement with the frontier:** roughly the last third of the course integrates recent work on scaling, alignment, efficient inference, and generative modeling that is standard in industry but absent from textbooks. Papers are primary sources; the textbook is a reference.

## Prerequisites

- Linear algebra and multivariate calculus (at the level of an upper-division math course)
- Probability and statistics (MLE, Bayes, basic estimators)
- Programming fluency in Python; PyTorch will be taught on the fly
- Prior ML exposure (a first course in ML like Stanford CS229, MIT 6.7900, or CMU 10-601) is strongly recommended

## Learning Outcomes

By the end of this course, students will be able to:

1. Derive and implement backpropagation for arbitrary computational graphs from first principles.
2. Diagnose and fix failures in deep network training (vanishing gradients, dead ReLUs, loss plateaus, distribution shift between train and eval).
3. Select, adapt, and evaluate architectures (convolutional, recurrent, attention-based, energy-based) against a task's structure.
4. Read and critically assess a recent paper from NeurIPS/ICML/ICLR and position it against prior work.
5. Reason quantitatively about the compute, memory, and data trade-offs of modern large-scale training.
6. Build a non-trivial deep learning project end-to-end: data pipeline, model, training loop, evaluation, and ablation.

## Required Texts and Resources

- **Primary textbook:** Goodfellow, Bengio, Courville, *Deep Learning* (MIT Press, 2016). Used for Lectures 1–6.
- **Secondary reference:** Prince, *Understanding Deep Learning* (MIT Press, 2023) — more current than Goodfellow; used as supplementary reading throughout.
- **Papers:** Assigned per lecture, all open-access.

## Module Structure

| Module | Lectures | Theme |
|---|---|---|
| 1. Foundations | 1–5 | Neural nets, optimization, and why they work |
| 2. Core Architectures | 6–9 | CNNs, sequence models, Transformers |
| 3. Generative Modeling | 10–11 | Diffusion, autoregressive generation, energy-based models |
| 4. Modern Frontier | 12–14 | Scaling, alignment, efficient inference, reasoning |

## Lecture-by-Lecture Schedule

### Module 1: Foundations

#### Lecture 1 (Week 1) — Introduction and Why Deep Learning Works
**Topics:**
- Course logistics and the last decade of progress
- The representation learning hypothesis
- The "Bitter Lesson" (Sutton) vs. inductive bias — why architecture still matters
- What we can and cannot explain theoretically

**Readings:**
- Goodfellow et al., Chapter 1
- LeCun, Bengio, Hinton, 2015, "Deep Learning", *Nature*

**Why this lecture:** Set the frame. Students leave with a mental map of the whole course and understand why each subsequent topic earns its place.

---

#### Lecture 2 (Week 2) — Neural Networks and Backpropagation
**Topics:**
- MLPs, activation functions, universal approximation
- Reverse-mode automatic differentiation
- Backprop derived by hand on a two-layer net
- Initialization (Xavier, He) and why it matters

**Readings:**
- Goodfellow et al., Chapters 6 and 8 (sections on init)
- Rumelhart, Hinton, Williams, 1986, "Learning representations by back-propagating errors", *Nature*

**Optional:**
- Glorot and Bengio, 2010, "Understanding the difficulty of training deep feedforward neural networks", *AISTATS*

**Why this lecture:** This is where the course earns its reputation. No student leaves without being able to derive backprop. Builds directly on Lecture 1's motivation.

---

#### Lecture 3 (Week 3) — Optimization for Deep Learning
**Topics:**
- SGD and its variants: momentum, Nesterov
- Adam, AdamW, and why Adam outperforms SGD on language models
- Learning rate schedules: cosine, warmup, one-cycle
- Batch size, gradient accumulation, and the linear scaling rule

**Readings:**
- Goodfellow et al., Chapter 8
- Loshchilov and Hutter, 2019, "Decoupled Weight Decay Regularization" (AdamW), *ICLR*

**Optional:**
- Kunstner et al., 2024, "Heavy-Tailed Class Imbalance and Why Adam Outperforms Gradient Descent on Language Models", *NeurIPS* — worth reading to understand why this choice isn't arbitrary

**Why this lecture:** Optimization is where most training failures happen. Follows naturally from backprop: now that you can compute gradients, what do you do with them?

---

#### Lecture 4 (Week 4) — Regularization, Generalization, and the Bias-Variance Puzzle
**Topics:**
- Classical regularization: L2, dropout, early stopping
- Batch normalization, layer normalization, RMSNorm
- Double descent and why overparameterization sometimes helps
- Data augmentation as implicit regularization

**Readings:**
- Goodfellow et al., Chapter 7
- Srivastava et al., 2014, "Dropout: A Simple Way to Prevent Neural Networks from Overfitting", *JMLR*
- Nakkiran et al., 2020, "Deep Double Descent: Where Bigger Models and More Data Hurt", *ICLR*

**Why this lecture:** Connects optimization to generalization. Double descent is included because any modern student should know the classical bias-variance story is incomplete.

---

#### Lecture 5 (Week 5) — Practical Training: Debugging, Logging, Evaluation
**Topics:**
- Reading loss curves like an experimentalist
- The train/val/test protocol done right; data leakage
- Hyperparameter search: grid, random, Bayesian, population-based
- Reproducibility and the replication crisis in ML

**Readings:**
- Karpathy, "A Recipe for Training Neural Networks" (blog post, 2019)
- Henderson et al., 2018, "Deep Reinforcement Learning That Matters", *AAAI* — the locus classicus on reproducibility problems

**Why this lecture:** Transitions the course from theory to practice. Students will do Assignment 2 (first nontrivial training run) after this lecture.

---

### Module 2: Core Architectures

#### Lecture 6 (Week 6) — Convolutional Networks and Computer Vision
**Topics:**
- Convolution as a structural prior: translation equivariance
- The ResNet revolution: skip connections and depth
- Modern CNN ingredients: group conv, depthwise separable, squeeze-and-excitation
- The current CNN-vs-Transformer debate in vision

**Readings:**
- Goodfellow et al., Chapter 9
- He et al., 2016, "Deep Residual Learning for Image Recognition" (ResNet), *CVPR*
- Liu et al., 2022, "A ConvNet for the 2020s" (ConvNeXt), *CVPR*

**Why this lecture:** CNNs remain the best-understood success case of learned inductive bias, and they remain state-of-the-art for many vision tasks despite the ViT hype.

---

#### Lecture 7 (Week 7) — Sequence Models: RNNs, LSTMs, and the Attention Revolution
**Topics:**
- RNNs and why they're hard to train (exploding/vanishing gradients in depth *and* time)
- LSTMs and GRUs: gating as a hack that worked
- Attention mechanisms as content-based addressing
- The Transformer: attention is all you need

**Readings:**
- Goodfellow et al., Chapter 10
- Hochreiter and Schmidhuber, 1997, "Long Short-Term Memory", *Neural Computation*
- Vaswani et al., 2017, "Attention Is All You Need", *NeurIPS*

**Optional:**
- Jay Alammar, "The Illustrated Transformer" (blog post)

**Why this lecture:** The Transformer is the single most important architecture of the past decade. It is taught with full context: the RNN problems it solved, not in isolation.

---

#### Lecture 8 (Week 8) — Transformer Internals and Modern Variants
**Topics:**
- Self-attention, multi-head attention, positional encodings
- Rotary position embeddings (RoPE) and why they generalize better
- FlashAttention: what changes when you think about memory, not FLOPs
- Mixture-of-Experts: sparse activation as a scaling lever

**Readings:**
- Su et al., 2021, "RoFormer: Enhanced Transformer with Rotary Position Embedding", arXiv (later *Neurocomputing*)
- Dao et al., 2022, "FlashAttention: Fast and Memory-Efficient Exact Attention with IO-Awareness", *NeurIPS*
- Fedus et al., 2022, "Switch Transformer: Scaling to Trillion Parameter Models with Simple and Efficient Sparsity", *JMLR*

**Frontier:** All three papers are post-Goodfellow and define how modern Transformers are actually built and run. Without them, a graduate can't read a 2025 architecture paper.

**Why this lecture:** Takes the Transformer from "textbook object" to "what people actually train in 2026".

---

#### Lecture 9 (Week 9) — Pretraining, Fine-tuning, and the Paradigm of Foundation Models
**Topics:**
- Self-supervised learning: masked LM (BERT), autoregressive LM (GPT), contrastive (SimCLR, CLIP)
- The pretrain-then-fine-tune paradigm
- In-context learning and few-shot prompting
- Scaling laws (Kaplan, Chinchilla) and their practical consequences

**Readings:**
- Devlin et al., 2019, "BERT: Pre-training of Deep Bidirectional Transformers", *NAACL*
- Radford et al., 2019, "Language Models are Unsupervised Multitask Learners" (GPT-2, tech report)
- Hoffmann et al., 2022, "Training Compute-Optimal Large Language Models" (Chinchilla), *NeurIPS*
- Radford et al., 2021, "Learning Transferable Visual Models From Natural Language Supervision" (CLIP), *ICML*

**Frontier:** Scaling laws as a design tool, not a scientific curiosity. Chinchilla changed the economics of training.

**Why this lecture:** Foundation models are the unit of work in ML as of 2026. Students must understand the pretrain/fine-tune decomposition from both a research and an engineering standpoint.

---

### Module 3: Generative Modeling

#### Lecture 10 (Week 10) — Generative Models I: VAEs, GANs, and Autoregressive Generation
**Topics:**
- Likelihood-based vs. implicit generative models
- VAEs: variational lower bound, reparameterization
- GANs: the minimax game and its pathologies (mode collapse, training instability)
- Autoregressive image generation: from PixelRNN to VAR

**Readings:**
- Kingma and Welling, 2014, "Auto-Encoding Variational Bayes", *ICLR*
- Goodfellow et al., 2014, "Generative Adversarial Networks", *NeurIPS*
- Tian et al., 2024, "Visual Autoregressive Modeling: Scalable Image Generation via Next-Scale Prediction" (VAR), *NeurIPS* (Best Paper)

**Frontier:** VAR (NeurIPS 2024 Best Paper) showed that autoregressive image modeling done right can match diffusion. Too new to be in any textbook; essential for anyone working in generative vision now.

**Why this lecture:** Establishes the taxonomy of generative models before we devote the next lecture to the currently dominant family (diffusion).

---

#### Lecture 11 (Week 11) — Generative Models II: Diffusion and Energy-Based Models
**Topics:**
- Score-based generative modeling; the SDE formulation
- DDPM and the denoising objective
- Classifier-free guidance (CFG) and its successor, autoguidance
- Energy-based models: a unifying perspective (LeCun's framing)

**Readings:**
- Ho et al., 2020, "Denoising Diffusion Probabilistic Models" (DDPM), *NeurIPS*
- Song et al., 2021, "Score-Based Generative Modeling through Stochastic Differential Equations", *ICLR*
- Karras et al., 2024, "Guiding a Diffusion Model with a Bad Version of Itself" (Autoguidance), *NeurIPS* (Best Paper Runner-up)

**Optional:**
- LeCun, "A Path Towards Autonomous Machine Intelligence" (2022 position paper) — for the EBM framing

**Frontier:** Autoguidance replaces CFG, the technique powering essentially every deployed text-to-image model. Teaching CFG alone is already out of date.

**Why this lecture:** Diffusion is where generation lives in 2026. Students who don't understand the score-based view are locked out of most current vision/audio research.

---

### Module 4: Modern Frontier

#### Lecture 12 (Week 12) — Alignment, RLHF, and Preference Learning
**Topics:**
- The alignment problem: what do we optimize for, and according to whom?
- Instruction tuning (SFT)
- RLHF: reward modeling plus PPO
- DPO and the simpler-is-better trend
- Evaluation: why benchmarks lie and the PRISM lesson

**Readings:**
- Ouyang et al., 2022, "Training Language Models to Follow Instructions with Human Feedback" (InstructGPT), *NeurIPS*
- Rafailov et al., 2023, "Direct Preference Optimization: Your Language Model Is Secretly a Reward Model" (DPO), *NeurIPS*
- Kirk et al., 2024, "The PRISM Alignment Dataset", *NeurIPS* (Best Paper, Datasets & Benchmarks)

**Optional:**
- Lilian Weng, "LLM-powered Autonomous Agents" (blog post, 2023)

**Frontier:** DPO replaced PPO-based RLHF in the open-source stack within 18 months of publication; PRISM reframes what "aligned" even means. Neither is in any textbook.

**Why this lecture:** Students building LLM-based systems in 2026 cannot avoid the alignment stack. It is taught here as engineering, not philosophy, but with the philosophical caveats surfaced.

---

#### Lecture 13 (Week 13) — Scaling Up: Distributed Training and Efficient Inference
**Topics:**
- Why training is memory-bound: activations, optimizer state, gradients
- Data parallelism; ZeRO (stages 1/2/3) and FSDP
- Tensor parallelism, pipeline parallelism, sequence parallelism
- Inference-side: KV caching, quantization, speculative decoding

**Readings:**
- Rajbhandari et al., 2020, "ZeRO: Memory Optimizations Toward Training Trillion Parameter Models", *SC*
- Leviathan et al., 2023, "Fast Inference from Transformers via Speculative Decoding", *ICML*
- PyTorch FSDP documentation (primary source, required)

**Optional:**
- Chip Huyen, "Designing Machine Learning Systems" (O'Reilly, 2022), Chapter on deployment
- Murat Demirbas or Marc Brooker on operational characteristics of large training jobs (blog posts)

**Frontier:** This is the lecture that most deep-learning courses still skip. In 2026 no graduate going to industry or to serious research can avoid it. Speculative decoding, in particular, is now standard in every production LLM serving stack and should sit alongside classical inference methods.

**Why this lecture:** Closes the gap between "I can train a model on one GPU" and "I can read a Llama-scale training paper". Connects directly to Lecture 9 (scaling laws) — this lecture is the how to Lecture 9's what.

---

#### Lecture 14 (Week 14) — Reasoning, Agents, and Open Problems
**Topics:**
- Chain-of-thought prompting and inference-time compute
- Tool use and agent loops (ReAct, Toolformer)
- Reasoning models (o1-style, DeepSeek-R1-style): RL on verifiable rewards
- What we still cannot do: continual learning, robust OOD generalization, causality
- Course retrospective: what will look obvious in 5 years, what won't

**Readings:**
- Wei et al., 2022, "Chain-of-Thought Prompting Elicits Reasoning in Large Language Models", *NeurIPS*
- Yao et al., 2023, "ReAct: Synergizing Reasoning and Acting in Language Models", *ICLR*
- A recent reasoning-model technical report (DeepSeek-R1, OpenAI o1, or equivalent) — selected based on what's current in the semester

**Frontier:** Inference-time compute as a new scaling axis is the single biggest shift in the field since this course was last redesigned; it gets a capstone lecture.

**Why this lecture:** Leaves students with a current map of the field, including where the edges are. The open-problems section is explicit so they understand this is not a solved science.

---

## Assignments

### Assignment 1: MLP from scratch (due Week 3)
Implement a two-layer MLP in NumPy with manual backprop. Train it on MNIST. Submit: code, a short report on your learning curves, and a comparison to a PyTorch implementation of the same model.

### Assignment 2: CNN for vision (due Week 7)
In PyTorch, train a CNN on CIFAR-10. Report must include an ablation of: optimizer choice, batch normalization on/off, data augmentation on/off, and depth. Grade is based on the rigor of the ablation, not the absolute accuracy.

### Assignment 3: Transformer language model (due Week 10)
Implement a decoder-only Transformer (GPT-style) and train it on a small corpus (TinyStories or similar). Required: report perplexity and one interesting attention-pattern visualization.

### Assignment 4: Paper replication (due Week 13)
Pick a paper from the reading list in Modules 3–4. Reproduce the central result (or a meaningful subset of it) and write a 4-page report in the style of a conference review. This is the intellectual capstone of the coursework.

### Final Project (due end of semester)
Open-ended research project done in pairs. Must include a problem statement, related work, method, experiments, and a reflection on what didn't work. Ambitious students are encouraged to pick topics that touch Module 4 material (alignment, efficient inference, reasoning); more conservative options (improving a Module 2 architecture on a specific task) are equally accepted.

## Grading

| Component | Weight |
|---|---|
| Assignments 1–4 | 40% (10% each) |
| Midterm (Week 8) | 15% |
| Final project | 35% |
| Participation (including paper presentations) | 10% |

## What's Been Added vs. a Traditional Course

Compared to a deep learning syllabus from ~2020 (for example, the CS230 / Goodfellow-textbook-driven version), this course makes the following deliberate choices:

- **Added Lecture 8 (Transformer internals — RoPE, FlashAttention, MoE).** Standard Transformers in deployment look very different from the 2017 paper. A 2026 graduate who can't discuss FlashAttention is unprepared for industry.
- **Added Lecture 12 (Alignment / RLHF / DPO).** This subfield essentially did not exist in the 2020 syllabus. It is now unavoidable.
- **Added Lecture 13 (Distributed training and efficient inference).** This material used to be treated as "systems, not ML". That distinction no longer holds — Chinchilla, FSDP, and speculative decoding are all ML papers with ML ideas, and leaving them out produces graduates who cannot operate on modern models.
- **Added Lecture 14 (Reasoning and agents).** Inference-time compute as a scaling axis is the most recent major shift; it earns a capstone treatment rather than a footnote.
- **Reduced:** The RNN/LSTM lecture is now a half-lecture embedded in Lecture 7 rather than two full lectures. Historical context is preserved; mechanics that no one uses in 2026 are cut.
- **Reframed:** Generative models get two lectures (diffusion is its own topic), replacing the old single lecture that treated GANs as the dominant family.
- **Preserved:** Modules 1 and 2 (Lectures 1–7, foundations + CNN + RNN/attention) are deliberately conservative. A student should not leave this course without being able to derive backprop by hand. The first third of the course looks more like 2018 than 2026 on purpose.

## References by Lecture (Bibliography)

- LeCun, Bengio, Hinton, 2015, "Deep Learning", *Nature*. [L1]
- Rumelhart, Hinton, Williams, 1986, "Learning representations by back-propagating errors", *Nature*. [L2]
- Glorot, Bengio, 2010, "Understanding the difficulty of training deep feedforward neural networks", *AISTATS*. [L2]
- Loshchilov, Hutter, 2019, "Decoupled Weight Decay Regularization", *ICLR*. [L3]
- Kunstner et al., 2024, "Heavy-Tailed Class Imbalance and Why Adam Outperforms Gradient Descent on Language Models", *NeurIPS*. [L3]
- Srivastava et al., 2014, "Dropout", *JMLR*. [L4]
- Nakkiran et al., 2020, "Deep Double Descent", *ICLR*. [L4]
- Karpathy, "A Recipe for Training Neural Networks", 2019 (blog). [L5]
- Henderson et al., 2018, "Deep Reinforcement Learning That Matters", *AAAI*. [L5]
- He et al., 2016, "Deep Residual Learning for Image Recognition", *CVPR*. [L6]
- Liu et al., 2022, "A ConvNet for the 2020s" (ConvNeXt), *CVPR*. [L6]
- Hochreiter, Schmidhuber, 1997, "Long Short-Term Memory", *Neural Computation*. [L7]
- Vaswani et al., 2017, "Attention Is All You Need", *NeurIPS*. [L7]
- Alammar, "The Illustrated Transformer", blog. [L7]
- Su et al., 2021, "RoFormer: Enhanced Transformer with Rotary Position Embedding". [L8]
- Dao et al., 2022, "FlashAttention", *NeurIPS*. [L8]
- Fedus et al., 2022, "Switch Transformer", *JMLR*. [L8]
- Devlin et al., 2019, "BERT", *NAACL*. [L9]
- Radford et al., 2019, "Language Models are Unsupervised Multitask Learners" (GPT-2). [L9]
- Hoffmann et al., 2022, "Training Compute-Optimal Large Language Models" (Chinchilla), *NeurIPS*. [L9]
- Radford et al., 2021, "Learning Transferable Visual Models From Natural Language Supervision" (CLIP), *ICML*. [L9]
- Kingma, Welling, 2014, "Auto-Encoding Variational Bayes", *ICLR*. [L10]
- Goodfellow et al., 2014, "Generative Adversarial Networks", *NeurIPS*. [L10]
- Tian et al., 2024, "Visual Autoregressive Modeling" (VAR), *NeurIPS*. [L10]
- Ho et al., 2020, "DDPM", *NeurIPS*. [L11]
- Song et al., 2021, "Score-Based Generative Modeling through SDEs", *ICLR*. [L11]
- Karras et al., 2024, "Guiding a Diffusion Model with a Bad Version of Itself", *NeurIPS*. [L11]
- LeCun, 2022, "A Path Towards Autonomous Machine Intelligence", position paper. [L11]
- Ouyang et al., 2022, "InstructGPT", *NeurIPS*. [L12]
- Rafailov et al., 2023, "Direct Preference Optimization", *NeurIPS*. [L12]
- Kirk et al., 2024, "The PRISM Alignment Dataset", *NeurIPS*. [L12]
- Weng, "LLM-powered Autonomous Agents", 2023 (blog). [L12]
- Rajbhandari et al., 2020, "ZeRO", *SC*. [L13]
- Leviathan et al., 2023, "Fast Inference from Transformers via Speculative Decoding", *ICML*. [L13]
- Wei et al., 2022, "Chain-of-Thought Prompting", *NeurIPS*. [L14]
- Yao et al., 2023, "ReAct", *ICLR*. [L14]
