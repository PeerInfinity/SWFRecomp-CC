# Upstream Comparison Analyses

Analyses comparing SWFRecomp-CC ("downstream") with the upstream SWFRecomp org
repositories, now that the two projects have settled into a permanent-friendly-fork
relationship (see [`../merge/upstream-relationship-2026-07.md`](../merge/upstream-relationship-2026-07.md);
its §7 is the September 2026 status check — what was delivered, what upstream did
since, and the corrected repository map).

**Status at a glance (September 22, 2026):** upstream master has not moved since
the July 3 merges; all new upstream work is a `mavlink` branch (ArduPilot SITL
front-end). SWFRecomp-CC added a full AVM2 runtime and mirrored the whole
upstream test corpus (98.2% effective of 4,437). The living docs below were
refreshed for both facts; the AVM2 work is where upstream's interning and
single-call-convention ideas were adopted.

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
  likely to hit as its coverage grows, with what we learned the hard way, plus a
  short AVM2 section (§12) for whenever upstream gets there. Kept as a
  **separate document** (rather than folded into the advantages docs) because its
  audience is different: it is written to be shared with LittleCube (delivered
  July 4, 2026, acknowledged), and it grows over time — from upstream tracking
  (`upstream/MERGE-ANALYSIS.md`) when upstream enters territory we have maps of,
  and from our own arcs otherwise (the September 2026 revision).
