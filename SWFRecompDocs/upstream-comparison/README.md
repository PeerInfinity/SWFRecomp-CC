# Upstream Comparison Analyses

Analyses comparing SWFRecomp-CC ("downstream") with the upstream SWFRecomp org
repositories, now that the two projects have settled into a permanent-friendly-fork
relationship (see [`../merge/upstream-relationship-2026-07.md`](../merge/upstream-relationship-2026-07.md)).

This directory answers questions of the form *"what would X buy us?"*, *"what does
upstream do better?"*, *"what do we do better?"* — analysis, not merge planning.
Merge planning history lives in [`../merge/`](../merge/); commit-level upstream
tracking lives in `upstream/MERGE-ANALYSIS.md` (local-only, gitignored).

## Conventions

- **Dated files** (`2026-07-*.md`) are point-in-time Q&A analyses. They snapshot
  measurements (line counts, pass rates) as of their date and are not maintained
  afterward.
- **Undated files** are living reference documents, updated as either codebase evolves.

## Documents

### Point-in-time analyses

- [`2026-07-thread-safety-benefits.md`](2026-07-thread-safety-benefits.md) — If we
  implemented upstream's thread-safety features (app_context, locks, concurrent GC)
  in this repo, what would we practically gain? (Answer: much less than it sounds —
  the term bundles three separable things, and the valuable outcomes are mostly
  already obtained via process/WASM-module isolation.)

### Living references

- [`upstream-architecture-advantages.md`](upstream-architecture-advantages.md) —
  What upstream's architecture does better, including problems we demonstrably still
  carry that their design solves. (This absorbs the category "issues in downstream
  that upstream has already fixed" — each such issue *is* an upstream advantage, so
  a separate document would duplicate this one.)
- [`downstream-architecture-advantages.md`](downstream-architecture-advantages.md) —
  What this fork's architecture and process do better.
- [`warnings-for-upstream.md`](warnings-for-upstream.md) — AVM1 traps upstream is
  likely to hit as its coverage grows, with what we learned the hard way. Kept as a
  **separate document** (rather than folded into the advantages docs) because its
  audience is different: it is written to be shared with LittleCube, and it grows
  over time as upstream tracking (`upstream/MERGE-ANALYSIS.md`) shows upstream
  entering territory we have maps of.
