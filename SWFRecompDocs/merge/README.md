# Merge Documentation

This directory holds the record of how SWFRecomp-CC relates to the upstream
SWFRecomp org repositories: the merge plans from the period when a code-level
sync was still the goal, and the July 2026 decision that ended it.

## Current

- **[upstream-relationship-2026-07.md](upstream-relationship-2026-07.md)** — the
  relationship decision (July 2, 2026) and its running status.
  - Verdict: **permanent friendly fork, knowledge exchange only, no code-level
    merge in either direction**. Confirmed by LittleCube July 4 (§6).
  - §5: what we offer upstream (investigation docs, the AVM1 trap map, tests,
    targeted PRs). Deliverable: [`../upstream-comparison/warnings-for-upstream.md`](../upstream-comparison/warnings-for-upstream.md).
  - §6: reporting channel = GitHub issues on the org repo, discussion on Discord.
  - **§7: September 22, 2026 status check** — delivery record, what upstream did
    since (nothing on master; a `mavlink` SITL branch), what we did since (AVM2,
    full corpus), and the corrected repository map below.

## Historical

- **[upstream-downstream-merge-plan-2024-12.md](upstream-downstream-merge-plan-2024-12.md)** — the
  December 2025 plan for syncing with upstream (superseded July 2026; every item
  is dispositioned in the relationship doc §3).
- `SWFRecomp-objects-and-functions*.md`, `SWFModernRuntime-objects-and-functions*.md` —
  December 2025 / January 2026 reviews of LittleCube's `feature/objects-and-functions`
  PR branches, written while they were open. Merged upstream July 2, 2026.
- [`../deprecated/merge/`](../deprecated/merge/) — the October–November 2025
  records of the original fork creation and the `wasm-support` branch merges.

## Repository map (as of September 2026)

| Repository | Role |
|---|---|
| [PeerInfinity/SWFRecomp-CC](https://github.com/PeerInfinity/SWFRecomp-CC) | **This repo.** The living fork; recompiler, runtime, docs, tests and demos in one tree, all work on `master`. |
| [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp), [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) | Upstream recompiler and runtime (LittleCube). Tracked read-only in `upstream/` (gitignored local clones, log in `upstream/MERGE-ANALYSIS.md`); never merged. |
| [SWFRecomp/AS2Runtime](https://github.com/SWFRecomp/AS2Runtime), [SWFRecomp/mtasc](https://github.com/SWFRecomp/mtasc) | Upstream's ActionScript-2 prelude standard library and the MTASC fork that compiles it. Design reference only. |
| [SWFRecomp/RecompTemplate](https://github.com/SWFRecomp/RecompTemplate), [SWFRecomp/RhythmPlanetsRecompiled](https://github.com/SWFRecomp/RhythmPlanetsRecompiled) | Upstream's game-recompilation template and first game target. |
| [SWFRecomp/libtess2](https://github.com/SWFRecomp/libtess2) | Upstream's tessellator fork (runtime-side). We vendor libtess2 independently, at recompile time. |
| [PeerInfinity/SWFRecomp](https://github.com/PeerInfinity/SWFRecomp), [PeerInfinity/SWFModernRuntime](https://github.com/PeerInfinity/SWFModernRuntime) | **Historical.** Carried the 2025 `wasm-support` branches, then LittleCube's PR branches (#4 / #3). Last push July 3, 2026; kept only because they hold the unsquashed PR history. |
| [SWFRecomp/SWFRecompDocs](https://github.com/SWFRecomp/SWFRecompDocs) | **Frozen** since November 5, 2025. Flattened into this repo's `SWFRecompDocs/` that day and maintained here since. |

## Related Documentation

- **[../upstream-comparison/](../upstream-comparison/)** — the living comparison
  analyses (what each architecture does better, "what would X buy us?"
  evaluations, the warnings doc for upstream)
- **[../status/](../status/)** — implementation status and summaries
