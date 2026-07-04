# Session prompt: Memory-reclamation Stages 0+1 — instrument, then fix the two deterministic leaks

Execute **Stage 0 and Stage 1** of `SWFRecompDocs/plans/memory-reclamation-plan.md`.
Read that plan first — it has the ownership-survey findings and file:line anchors.
Do NOT start Stage 3 (the collector) in this session; Stage 2 is just recording a
verdict from the measurements.

## Order of work

**Stage 0 first, and capture baseline numbers before touching any leak.** The
before/after delta is the deliverable that justifies (or kills) the rest of the
plan.

### Stage 0 — instrumentation

- Live/total alloc+free counters and an intrusive doubly-linked all-objects list
  at the two chokepoints: `allocObject` (`object.c:284`), `allocArray`
  (`object.c:1166`); unlink in the two release-at-zero blocks (`object.c:427`,
  `object.c:1288`). Two pointer fields per object; O(1) link/unlink.
- Surfacing: env-gated stderr summary at exit for native builds (CI-invisible
  when the env var is unset → byte-identical CI), and a line in the existing
  browser perf HUD (`swf_perf_report` in swf.c, `__EMSCRIPTEN__`-gated — follow
  the `762a51550` pattern, which was graphics-CI clean).
- Attribution: a build-time-gated tag (or a debug walk of the live list) that
  classifies leaked objects at exit into (a) detached `dynamic_props`,
  (b) arrays reachable only as unreleased object-property values, (c) other
  (candidate cycles). A crude classifier is fine — it only needs to rank the
  three classes.
- **Baselines** (record actual numbers): N title demo long run, Minesweeper
  menu→game, DJ — native `MAX_FRAMES` runs via the
  `profile_game_native.sh`-style build (no full test suites locally; single
  tests only, per CLAUDE.md).

### Stage 1 — the two deterministic leak fixes

1. **Release `dynamic_props` on detach** at the four raw-NULL sites
   (`action.c:23044, 23076, 23130, 23176`). Traps (see plan §Stage 1): the
   finalize/pending-removal ordering, soft-ref re-resolution, and confirming no
   consumer reads a detached `dynamic_props` afterwards. Note this must NOT
   touch `var_map` semantics (`user-vars-survive-mc-removal` memory — that rule
   is about var_map, which stays untouched).
2. **Balance ARRAY-valued object properties** — retain on store / release on
   overwrite, delete, and destroy, mirroring the OBJECT arms in `setProperty`,
   `setPropertyWithFlags`, `deleteProperty`, `releaseObject` (+ overwrite path).
   **Mandatory pre-audit first:** enumerate every `releaseArray` call site and
   check none is manually compensating for today's borrowed convention — any
   such site double-releases after this change. FUNCTION values stay borrowed
   (functions are immortal; see plan §1.1).

Land the two fixes as separate commits.

## Verification (the plan's §3, concretely)

- **Byte-identical trace output** on the game runs and on a smoke set of single
  tests before/after each fix — destruction is unobservable, so ANY output diff
  is a bug, full stop.
- **Full CI both modes** per landed fix (shared runtime code). Zero pass→fail.
- **ASAN runs** of the repro games after each fix — this work is exactly
  UAF/double-free shaped; the `graphics-sigabrt-real-heap-bugs` memory has the
  ASAN-pin playbook.
- **Re-measure the Stage 0 baselines after both fixes.** Success = live-object
  count goes flat (or near-flat) on the clip-churn workloads.

## Close-out

- Record baseline + post-fix numbers in the plan doc (or a results doc next to
  it) and write the **Stage 2 verdict**: is residual growth ≈0 → collector not
  needed (say so explicitly), or is there a measurable cyclic residual →
  Stage 3 stays live. Update the plan's Status line and `plans/README.md`.
- Memory entry with the verdict and any traps discovered (especially
  double-release compensations found in the pre-audit).
- Pipeline end-to-end per `.claude/pipeline-handoff.md`; report regressions by
  name. `.pipeline-state` done.

## Success criteria

Baseline leak rates measured and recorded; both deterministic leaks fixed with
byte-identical output, both-modes CI green, ASAN clean; Stage 2 verdict written
down with numbers behind it.
