# Output Formats

The default output format is **Markdown**, because:
- It's the easiest to iterate on (the user can edit freely)
- It renders well on GitHub, course wikis, Notion, etc.
- Conversion to Word/PDF is trivial if needed later

Offer alternatives when the user signals they want a different format.

## Signals and what to do

| User signal | Output format | Path |
|---|---|---|
| Default / unspecified | Markdown | `/mnt/user-data/outputs/<topic>-syllabus.md` |
| "send to colleagues", "formal document", "Word doc", ".docx" | Word (.docx) | `/mnt/user-data/outputs/<topic>-syllabus.docx` |
| "for printing", "PDF", "archive" | PDF | `/mnt/user-data/outputs/<topic>-syllabus.pdf` |
| User explicitly picks | Honor their choice | — |

## Producing Word or PDF output

For .docx: follow the `docx` skill's SKILL.md (located at `/mnt/skills/public/docx/SKILL.md`). Read it first before generating.

For .pdf: follow the `pdf` skill's SKILL.md (located at `/mnt/skills/public/pdf/SKILL.md`).

For both, the approach is: write the Markdown first (it's the canonical form), then convert. This way the content is identical across formats and easier to verify.

## File naming

Use slugs derived from the topic:
- "Distributed Systems" → `distributed-systems-syllabus.md`
- "深度学习" → `deep-learning-syllabus.md` (translate to English slug)
- "Compilers (Graduate)" → `compilers-graduate-syllabus.md`

Always lower-case, hyphen-separated, ASCII only.

## Sharing

After writing the file, use the `present_files` tool so the user can open and download it.
