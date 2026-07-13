# Session prompt — AVM2 Stage 11: GC enrollment + perf soak

> **STATUS: COMPLETE (2026-07-12).** Self-contained AVM2 mark-sweep collector
> landed (`SWFModernRuntime/src/avm2/avm2_gc.c` + `avm2_gc.h`); collects only
> between ticks (VM quiescent), deterministic 4 MB watermark + `AVM2_GC_STRESS`
> CI gate, precise+conservative marking, per-module ext-free hooks. Soak proves
> flat growth (GC off → 2M live; STRESS → dead-flat 370, 2M swept; ASAN-clean).
> A code-review workflow caught + fixed two pre-commit UAFs (drag roots,
> StyleSheet entry tracing). Details: `avm2/_investigation/CURRENT_STATUS.md`,
> `SWFRecompDocs/plans/avm2-seedling-plan.md` §2, memory `avm2-stage11-gc`.
> Next = Stage 12 (Seedling bring-up).

You are implementing **Stage 11** of the AVM2 Seedling-directed plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md` §2). This is the one mandatory
item invisible to any feature census: AVM2 allocations are currently
**census-invisible and immortal** (a deliberate Stage-2 simplification —
`avm2GcMarkRoots` in `avm2_main.c` is an empty stub, and `avm2_alloc` never
frees). Fine for tests that run seconds; **unbounded growth for a 30fps blitting
game** (Seedling). Enroll AVM2 allocations in the existing object.c mark-sweep
collector before any extended play testing.

Read the plan first, then `avm2/_investigation/CURRENT_STATUS.md`, then the
memories `avm2-stage10-audio` (Stage 10 landing + the immortal-alloc note),
`seedling-avm2-readiness` (remaining-work list — item on real audio OUTPUT is
NOT this stage), and the AVM1 GC cluster memories
[[memory-reclamation-stage3-collector]] / [[memory-reclamation-stage012]] (the
mark-sweep collector, GC-root rules, "N growth flat" methodology — the AVM1
precedent for exactly this work).

Stage 10 landed at commit `8c4e8518e`. CI baseline: **avm2 819 / 1,204 (68.0%)
both modes** (see CURRENT_STATUS.md). Zero regressions expected — GC is a
runtime-lifetime change, not a behavior change; every trace test must stay
byte-identical.

## Goal

Enroll every AVM2 allocation type in the `object.c` mark-sweep collector
(`g_avm2_gc_mark_roots` is already registered but empty), define the root set,
mark reachable AVM2 objects, and sweep the unreachable. Then a long-run soak
(the N-game / native-callgrind methodology from [[wasm-game-performance-profiling]]
and [[profile-game-native-n-is-noisy]]) proving heap growth goes **flat** over a
many-thousand-tick run. **The trace-test suite is the correctness gate**: all
1,204 avm2 tests + every AVM1 suite must stay byte-identical in BOTH CI modes
(GC must never collect a live object).

## Root set (from avm2_main.c comment + the Stage-5/10 structures)

- Domain globals (`ctx->files[i]->script_globals[*]`) + the builtin globals.
- The display tree (`ctx->stage` + `ctx->root` + every render_list/depth_list
  child, recursively) — the Stage-5 display ext holds Avm2Object* edges.
- In-flight activations + scope chains (the interpreter stack — walk the live
  Avm2Activation chain and each activation's scope entries/registers).
- Timers (`g_avm2_timers[*].timer_obj` + `.fn` + `.args` — avm2_display.c) and
  the SharedObject cache (`g_so_cache[*].obj` — avm2_amf.c).
- Class objects / vtables / prototypes / interned strings (likely keep these
  immortal — they never die; the win is in per-frame instances).
- Event listeners (EventDispatcher lists hold Avm2Value fn edges),
  BitmapData pixel buffers (large — but malloc'd, not avm2_alloc; confirm), the
  SoundChannel/SoundTransform/Timer native exts.

## Suggested tranche order

1. **Instrument first**: add an allocation census (count + bytes by kind) and a
   growth probe. Prove the leak: run a synthetic many-tick allocator loop and
   watch N climb. This is the before-picture the soak must flatten.
2. **Mark**: implement `avm2GcMarkRoots` to walk the root set above and mark
   every reachable Avm2Object. Reuse the object.c mark primitives (the same
   aggregator AVM1 enrolls in — see the AVM1 collector memories).
3. **Sweep + enroll**: make `avm2_alloc`'d objects collectable (enroll in the
   census list the collector sweeps). Watch the immortality assumptions in
   avm2_main.c's comment — anything that holds an edge into a collectable object
   must be a root or be marked through.
4. **Soak**: a native long-run (N-game methodology) proving flat growth; guard
   against the PROGRAM-TOTALS noise ([[profile-game-native-n-is-noisy]] — never
   A/B on noisy totals).
5. Full CI BOTH modes (GC touches shared runtime lifetime): confirm zero
   pass→fail and byte-identical traces, wasm-link-smoke green.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI (CLAUDE.md).
  Full pipeline per `.claude/pipeline-handoff.md`; run **both** modes (GC is
  shared runtime lifetime). Confirm zero pass→fail across ALL suites +
  wasm-link-smoke green.
- Conflict boundary: own `SWFModernRuntime/{src,include}/avm2/`; coordinate on
  `object.c` (shared with AVM1 — additive AVM2 enrollment only; never change
  AVM1 collection behavior). Never touch `action.c`.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`.
- Honest-failure property everywhere. A GC bug that collects a live object shows
  up as a use-after-free / wrong trace — the suite is the tripwire.

## Gotchas carried from earlier stages

- AVM2 objects hold edges into each other AND (via SymbolClass/embedded assets)
  into class objects; the display tree is the densest edge graph. Mis-marking
  the activation stack or the timer/listener edges collects live callbacks.
- `ASObject`/`ASArray` (AVM1) already enroll in `g_mt_obj_head`/`g_mt_arr_head`;
  AVM2 objects are a SEPARATE kind — don't conflate the two census lists.
- Determinism: the collector must not change trace output or ordering. Collect
  on a deterministic trigger (alloc-count / heap-watermark), not wall-clock.

## End-of-session bookkeeping

- Stage-11 landing note in `avm2-seedling-plan.md` §2.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline + the soak
  growth-flat evidence).
- New `avm2-stage11-gc` memory; update `seedling-avm2-readiness` (GC done →
  Stage 12 Seedling bring-up is unblocked).
- If complete, mark this prompt COMPLETE and draft the Stage-12 prompt (Seedling
  bring-up via the divergence-harness workflow, `wasm-game-debugging` memory).
