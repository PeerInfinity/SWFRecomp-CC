# Merge Documentation

This directory contains merge analysis and planning documents for synchronizing SWFRecomp-CC with upstream repositories.

## Current Merge Plans

### Active

- **[upstream-relationship-2026-07.md](upstream-relationship-2026-07.md)** - Relationship reassessment after upstream merged the objects-and-functions PRs to master (July 2, 2026)
  - Verdict: no code-level merge in either direction; permanent friendly fork with knowledge exchange
  - What we offer upstream: investigation docs, AVM1 edge-case maps, tests, targeted PRs
  - Written to be shareable — starting point for a conversation with LittleCube

### Historical

- **[upstream-downstream-merge-plan-2024-12.md](upstream-downstream-merge-plan-2024-12.md)** - Comprehensive plan for syncing with upstream SWFRecomp repositories (December 2025; superseded July 2026)
  - Upstream merges: object system, extended action.c, 100+ tests
  - Downstream merges: recent memory leak and Linux fixes

## Upstream Repositories

- [SWFRecomp/SWFRecomp](https://github.com/SWFRecomp/SWFRecomp) - Main recompiler
- [SWFRecomp/SWFModernRuntime](https://github.com/SWFRecomp/SWFModernRuntime) - Runtime library

## Historical Documentation

Older merge documents from the initial fork creation (Oct-Nov 2025) have been moved to:
- [`../deprecated/merge/`](../deprecated/merge/) - Historical records of wasm-support branch merges

## Related Documentation

- **[../upstream-comparison/](../upstream-comparison/)** - Ongoing comparison analyses (upstream vs downstream architecture advantages, "what would X buy us?" evaluations, warnings for upstream)

- **[../status/](../status/)** - Implementation status and summaries
- **[../../branch-merge-history.md](../../branch-merge-history.md)** - History of Claude-created branches merged into this repo
