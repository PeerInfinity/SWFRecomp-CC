# Planning Documents

Index established by the 2026-07-04 audit. Conventions:

- **Finished or superseded plans move to [`completed/`](completed/)** with an
  `AUDIT OUTCOME` (or equivalent) banner at the top stating what landed and the
  key commit(s). Negative results (executed-but-refuted) also go there — the
  refutation is the value.
- How-to documentation is not a plan — it lives in [`../guides/`](../guides/).
- Point-in-time measurement snapshots stay next to their plan, listed under
  *Results & playbooks* below.
- When adding a plan, add it to this index; when finishing one, banner it and
  move it.

## Active — current planning thread (July 2026, post-upstream-merge)

Grounded in the [upstream comparison analyses](../upstream-comparison/):

- [string-id-interning-plan.md](string-id-interning-plan.md) — umbrella, 3 stages
  (MC-builtin id-memo dispatch → per-id name cache → full key interning, gated).
  - [wasm-game-performance-step3-string-interning.md](wasm-game-performance-step3-string-interning.md) — its Stage 2 (pre-existing plan).
- [function-dispatch-consolidation-plan.md](function-dispatch-consolidation-plan.md) —
  one `invokeFunctionValue()` core for ~129 invocation points / ~38 dispatchers.
  **Stage 0 done 2026-07-04**: 3 real bugs fixed (EI type-1 arg reversal, MC
  event type-1 args dropped, timer version switch), 1 suspect stale
  (LC/NS/NC captured scope was fine); 4 permanent tests added.
- [memory-reclamation-plan.md](memory-reclamation-plan.md) — deterministic leak
  fixes (detached `dynamic_props`, unreleased array-valued properties) + a
  measurement-gated root-traced cycle collector.

## Active — feature/game threads

- [archipelago-randomizer-integration.md](archipelago-randomizer-integration.md) —
  umbrella; Phases 1 (native) + 2 (WASM bridge) done, Phase 3 next:
  [archipelago-phase3-substrate-and-item-application.md](archipelago-phase3-substrate-and-item-application.md).
- N (Metanet) procgen substrate:
  [n-level-generator-plan.md](n-level-generator-plan.md) (P0–P2 done, vertical/serpentine next),
  [n-portals-plan.md](n-portals-plan.md) (future session),
  [n-physics-js-reimplementation-plan.md](n-physics-js-reimplementation-plan.md) (future session).
- [graphics-native-test-mode-plan.md](graphics-native-test-mode-plan.md) —
  Phase 2 in progress (948/1125 as of 2026-05-11; 2 strict parity gaps remain).
  Operational companion: [graphics-native-test-mode-playbook.md](graphics-native-test-mode-playbook.md).
- Video: [video-codec-support-plan.md](video-codec-support-plan.md) (Phase A done;
  B–F = VP6/H.264/multi-frame/WASM/FLV-audio remain),
  [video-display-flash-parity-plan.md](video-display-flash-parity-plan.md) (Phase 1 pending).

## Backlog — valid, unscheduled

- [text-bind-runtime-followup-plan.md](text-bind-runtime-followup-plan.md) — two
  binding-path bugs; re-verify against later textfield fixes (`b5e9f3e9c` era)
  before starting.
- [dj-platform-followups.md](dj-platform-followups.md) — residual DJ platform
  bugs as of `be332528c`; re-verify which still reproduce.
- [browser-wasm-testing-plan.md](browser-wasm-testing-plan.md) — third
  verify_output mode (browser); partially overtaken by the ad-hoc Playwright
  probe tooling (`tools/divergence/game_drive/`, guides/browser-test-harness-usage.md).
- [wasm-probe-suite.md](wasm-probe-suite.md) — draft probe suite; overlaps the above.
- [shape-test-remaining-plan.md](shape-test-remaining-plan.md) — partially
  obsolete (tessellation parts superseded by libtess2); residual items only.
- [split-action-c-math-first.md](split-action-c-math-first.md) — draft; see
  upstream-comparison advantage #8 for the current "not yet worth the churn" verdict.

## Deferred — explicit decisions not to proceed (for now)

- [test-suite-unification.md](test-suite-unification.md) — deferred while Ruffle
  pass rate is the focus.
- In-browser recompilation initiative (Feb–Mar 2026, not pursued):
  [IN_BROWSER_RECOMPILATION_FEASIBILITY.md](IN_BROWSER_RECOMPILATION_FEASIBILITY.md),
  [BROWSER_COMPILATION_RESEARCH.md](BROWSER_COMPILATION_RESEARCH.md),
  [PHASE1_RECOMPILER_TO_WASM.md](PHASE1_RECOMPILER_TO_WASM.md),
  [PHASE2_IN_BROWSER_COMPILATION.md](PHASE2_IN_BROWSER_COMPILATION.md).

## Results & playbooks (reference, not plans)

- [wasm-game-performance-profiling-results-2026-06-01.md](wasm-game-performance-profiling-results-2026-06-01.md)
- [graphics-native-test-mode-baseline-2026-05-09.md](graphics-native-test-mode-baseline-2026-05-09.md),
  [graphics-native-test-mode-fullsuite-baseline-2026-05-09.md](graphics-native-test-mode-fullsuite-baseline-2026-05-09.md),
  [graphics-native-test-mode-phase2-results-2026-05-09.md](graphics-native-test-mode-phase2-results-2026-05-09.md)

## Completed

30 finished/superseded plans in [`completed/`](completed/), each with an outcome
banner (what landed, key commits). Highlights: WASM + WebGPU project plans,
bounds-engine unification, device fonts, textfield variable binding, input-event
injection, audio, demo system, the display editors, Archipelago Phases 0–2, and
the wasm-game performance profiling plan (whose continuation is the active
string-id-interning plan).
