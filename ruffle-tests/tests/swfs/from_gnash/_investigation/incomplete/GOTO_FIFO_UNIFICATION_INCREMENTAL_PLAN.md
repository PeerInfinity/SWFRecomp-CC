# Goto FIFO Unification — Incremental Plan

<!-- TESTS: consecutive_goto_frame_test -->

<!-- PLAN_META
id: GOTO_FIFO_UNIFICATION_INCREMENTAL
status: pending
phases:
  - id: A
    name: "Side table: recompiler emits (char_id, frame) → script_func* mapping"
    status: complete
  - id: B
    name: "ng_gotoFrameCurrentSprite records target into a deferred-script-queue (no dispatch)"
    status: pending
  - id: C
    name: "Drain hook for deferred-script-queue, gated behind g_unify_sprite_drain (default 0)"
    status: pending
  - id: D
    name: "Flip g_unify_sprite_drain=1 — sprite goto from inside sprite scripts dispatches in FIFO"
    status: pending
  - id: E
    name: "ng_executeGotoCatchUp: inline funcs[target] with drain-suppress (was Phase 2 of original plan)"
    status: pending
  - id: F
    name: "Phase 4 gate simplification + sprite eager-init force-queue during catch-up"
    status: pending
  - id: G
    name: "Retire g_deferred_goto_queue + outer drain loop (was Phase 3 of original plan)"
    status: pending
  - id: H
    name: "swf_headless.c parity (was Phase 5 of original plan)"
    status: pending
dependencies:
  - "Reframes: GOTO_FIFO_UNIFICATION_PLAN.md (blocked/) — same problem, atomic-commit framing was untractable. The original plan stays as the architectural reference (problem statement, FIFO-order trace, related docs). This plan is the shippable rollout."
  - "Foundation: DRAIN_SUPPRESS_PRIMITIVE_PLAN.md (complete/, commit d1cd1d1f) — used by Phase E."
target_test:
  - "consecutive_goto_frame_test (4/12 baseline → 12/12 once Phase F lands)"
-->

## Why this plan exists

The original `GOTO_FIFO_UNIFICATION_PLAN.md` (now in `blocked/`) framed the
work as "Phases 1+2+3 in a single atomic commit, Phase 4 as cleanup."
Detailed dispatch tracing (see that plan's "Updated finding 2026-04-26b"
section) showed:

1. Phase 4 (recompiler gate simplification) is **required atomically**, not
   cleanup — without it, sprite-script sync-fire through gate g2 cascades
   under Phase 1's inline-fire and breaks the test worse than baseline.
2. The combined scope (4+ runtime changes + 1 recompiler change + headless
   parity + regression triage on `loop_test*` / `goto_rewind*` / `unload*`)
   exceeds a single working session and requires CI roundtrips per
   iteration that can't be locally pre-screened.

The fix is to **separate primitives from semantics**. Each session adds a
piece of infrastructure that doesn't change behavior, then a single
opt-in flag flips semantics atomically. Regressions concentrate in the
flip-day session (Phase D / Phase F), and infrastructure sessions (A, B,
C, G, H) are zero-risk.

## Session map (one phase per session)

Sessions are ordered so each one either has zero behavioral impact OR
has its impact bounded by a runtime flag. Land them strictly in order;
later sessions assume earlier infrastructure.

### Phase A — Sprite frame script side table — COMPLETE 2026-04-26

**Scope.** Recompiler emits a side table mapping
`(sprite_char_id, frame_idx) → script_func*`. Runtime exposes
`actionGetSpriteFrameScript(char_id, frame_idx) → script_func*`. Nothing
uses the table yet.

**Files changed.**
- `SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h` (new)
- `SWFModernRuntime/src/actionmodern/sprite_frame_scripts.c` (new)
- `SWFModernRuntime/CMakeLists.txt` (new source in CORE_SOURCES)
- `ruffle-tests/verify_output.py` (new source in both core_sources lists)
- `SWFRecomp/include/swf.hpp` (`sprite_frame_scripts_table` + `_count` fields)
- `SWFRecomp/src/swf.cpp` (table accumulation at sprite DoAction site
  ~line 4940; emission in tag_main + `tagInitSpriteFrameScripts` call
  at start of tagInit)

**Behavior delta.** None. Verified on `consecutive_goto_frame_test`
(unchanged 4/12 baseline) plus 18 guardrail tests (all pass): 8 AVM1
goto/init/clip-events tests + 10 misc-ming loop/init tests.

**Sample emission.** `consecutive_goto_frame_test`'s tagMain.c now
contains a 5-entry table (`{ 1, 0, script_0 }`, `{ 1, 0, script_1 }`,
`{ 4, 0, script_3 }`, `{ 4, 1, script_4 }`, `{ 4, 2, script_5 }`)
registered via `tagInitSpriteFrameScripts(...)` at the start of
`tagInit`. Multiple scripts at the same `(char_id, frame_idx)` are
preserved (sprite 1 has 2 DoActions in frame 0); the accessor returns
the first match — later phases will refine if multi-DoAction-per-frame
ordering matters.

### Phase B — Record sprite goto target into a deferred-script queue

**Scope.** Add a small runtime queue (`g_pending_sprite_script_queue` or
similar — separate from `g_aq` and `g_deferred_goto_queue`).
`ng_gotoFrameCurrentSprite` looks up the target script via Phase A's
accessor and pushes onto this queue. **Nothing dispatches it yet.**

**Files.**
- `SWFModernRuntime/src/libswf/tag_stubs.c` (`ng_gotoFrameCurrentSprite`)
- New runtime queue (alongside or in `actionmodern/action_queue.c`)

**Behavior delta.** None visible. The script is queued but never
dispatched, so the existing `sprite_manual_next_frame=1` path still
drives sprite advancement.

**Verification.** Same guardrail as A. Add an internal assert that the
deferred-script queue is empty at end of frame (since nothing drains
it yet — anything left over is a leak).

**Risk.** Zero functionally. Risk of memory leak if queue grows
unboundedly without drain — bounded with a small fixed-size array
(MAX_PENDING_SPRITE_SCRIPTS=16) + drop-on-overflow with a debug log.

### Phase C — Drain hook gated behind a runtime flag

**Scope.** Add a runtime flag `g_unify_sprite_drain` (default 0). When
set, `actionDrainOnloadAndScript` consults the deferred-script queue
between drain pops and queues entries into `AQ_KIND_SCRIPT` for FIFO
dispatch. Default 0 → queue stays unused.

**Files.**
- `SWFModernRuntime/src/actionmodern/action_queue.c`
  (`actionDrainOnloadAndScript`)

**Behavior delta.** None when `g_unify_sprite_drain=0`. Flag is not
set anywhere in this phase.

**Verification.** Same guardrail. Plus a unit-style test: manually set
`g_unify_sprite_drain=1` in a single test (e.g., a new
`SWFRecomp/tests` opcode test) and confirm sprite gotos dispatch via
the new path.

**Risk.** Zero in the default-off path.

### Phase D — Flip g_unify_sprite_drain=1

**Scope.** Set `g_unify_sprite_drain=1` globally (or version-gate to
SWF6+ if regressions concentrate in SWF5). This activates the unified
sprite-script dispatch path.

**Behavior delta.** Sprite gotos from inside sprite scripts now
dispatch the next sprite frame's script via FIFO. Likely fixes a
subset of `consecutive_goto_frame_test`'s failing lines (the trailing
sprite-DoAction-after-totals symptom). Likely regresses tests that
relied on the deferred-to-next-tick ordering — predicted regressions:
`loop_test*` cluster, `goto_rewind1/2/3`, `clip_events`,
`register_and_init_order`.

**Verification.** Full local guardrail (15-20 tests). Push to CI;
expect 1-3 iterations to triage regressions.

**Risk.** High — first behavior change. Mitigation: version-gate to
SWF6+ if SWF5 regressions are unmanageable.

**Stop criterion.** If regressions exceed, say, 5 unrelated tests,
revert the flip and document; that pivots back to investigating a
narrower flag scope.

### Phase E — ng_executeGotoCatchUp: inline funcs[target] with drain-suppress

**Scope.** Same as Phase 2 of the original plan. After catch-up tags,
wrap `funcs[target](app_context)` in
`actionDrainSuppressEnter/Leave` with `g_tag_skip_mode=1`. Don't push
into `g_deferred_goto_queue`. Target script lands in `AQ_KIND_SCRIPT`,
drains via the outer recompiler-emitted drain in FIFO order.

**Behavior delta.** Root goto target script drains FIFO with sprite
scripts queued during the same script body. May fix the
`consecutive_goto_frame_test` interleave (depends on whether sprite
eager init has been adjusted yet — see Phase F).

**Verification.** Full local guardrail + CI. Predicted regressions:
`goto_rewind*`, `goto_methods`, `goto_label`, `execution_order2/3` —
tests that exercise the deferred-goto-queue drain ordering.

**Risk.** Medium-high. The drain-suppress primitive (foundation) is in
place, so re-entry is bounded. Risk concentrates in tests that rely on
"all root-deferred scripts drain before sprite scripts" ordering.

### Phase F — Phase 4 gate simplification + sprite eager-init force-queue

**Scope.** Two coupled changes:

1. Recompiler gate at `swf.cpp:4985-4999` simplifies to:
   ```c
   if (!catch_up_mode || g_tag_skip_mode)
       actionQueueSpriteScript(app_context, script_name);
   ```
   Removes gate g2's `script_only_mode + deferred_sprite_init` sync-fire
   path.
2. Sprite eager init in `tagPlaceObject2` (and friends) sets
   `g_tag_skip_mode=1` for the duration of `sprite_X_frame_0(app_context)`
   call — so the gate fires QUEUE during catch-up replay (lands script_3
   in queue at the right FIFO position).

**Behavior delta.** Sprite scripts that currently sync-fire from
`process_sprite_init_at_depth`'s Phase 2 path now queue. Trace order
shifts on init-order tests. Combined with Phase E, this should land
`consecutive_goto_frame_test` at 12/12 (the target).

**Verification.** Full local guardrail. Predicted regressions:
`register_and_init_order`, `on_construct`, `init_object_order`,
`clip_events`, `execution_order2/3`, `goto_execution_order/2`. CI
roundtrip mandatory.

**Risk.** High. This is the original plan's "atomic" risk concentrated
into one session, but with the Phase A-E infrastructure already in
place so the only new variable is the gate change.

**Stop criterion.** If guardrail regressions exceed ~5 tests with
unclear fix paths, revert and treat as a separate plan.

### Phase G — Retire g_deferred_goto_queue + outer drain loop

**Scope.** Same as Phase 3 of the original plan. Remove the
`g_deferred_goto_queue` array, the count, the
`g_deferred_goto_script` flag, and the manual while loop in
`swf_core.c:1090-1134`. Loop-exit conditions update from
`g_deferred_goto_queue_count > 0` to "any AQ_KIND_SCRIPT pending"
checks.

**Behavior delta.** None functionally if Phase E worked (the queue is
already empty in the unified-FIFO path).

**Verification.** Same guardrail; should be neutral.

**Risk.** Low — pure cleanup.

### Phase H — swf_headless.c parity

**Scope.** Apply Phase E + G changes to `swf_headless.c`'s mirror of
`ng_executeGotoCatchUp` + outer drain loop.

**Behavior delta.** None unless `--headless` mode is in use.

**Verification.** Run `python3 ruffle-tests/run_image_tests.py` if Dawn
+ lavapipe set up locally; otherwise rely on CI's headless image-test
suite.

**Risk.** Low — symmetric with E + G.

## Required-pass guardrail (any session that flips behavior)

These tests must not regress after Phases D, E, or F. List from the
original plan's Phase 6:

- AVM1 goto/rewind: `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `goto_frame`, `goto_frame_test`, `goto_frame2`, `goto_label`,
  `goto_methods`, `goto_methods_to_label`.
- AVM1 unload: `unload`, `unloadmovie`, `unload_clip_event`,
  `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`.
- Misc-ming: `loop/loop_test2/3/5/8/9`, `simple_loop_test`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `new_child_in_unload_test`,
  `event_handler_scope_test`, `instanceNameTest`, `attachMovieTest`,
  `DefineEditTextTest`, `DefineEditTextVariableNameTest2`,
  `shape_test`, `get_frame_number_test`,
  `reverse_execute_PlaceObject2_test1/2`,
  `action_execution_order_test8-v5/v6`.
- Shumway duplicateMovieClip: `dontremove`, `duplicateMovieClip`,
  `samedepth`, `name-coercion`.
- Misc-swfc: `movieclip_destruction_test2` (50/52 baseline),
  `stackscope`, `submoviegetvar`, `edittext_test1`.
- Init-order: `register_and_init_order`, `on_construct`,
  `init_object_order`, `clip_events`.

## Estimated session budget

| Phase | Effort | CI roundtrip needed? |
|-------|--------|----------------------|
| A | 1-2 hr | Optional (zero-risk) |
| B | 1-2 hr | Optional |
| C | 1 hr | Optional |
| D | 2-3 hr | **Yes** — first behavior change |
| E | 2-3 hr | **Yes** |
| F | 3-4 hr | **Yes** — highest regression risk |
| G | 1 hr | Yes (cleanup) |
| H | 30 min | Yes (headless suite) |

Total: 12-17 hours across 6-8 sessions. Each session has a clean
stopping point (commit + push or revert).

## Open questions (carried over from original plan)

1. **Eager-init timing under unified FIFO** — see original plan's open
   question 1.
2. **Nested goto: sprite-frame calling `_root.gotoAndStop`** — see
   original plan's open question 2.
3. **Drain reentry during catch-up tag replay** — addressed by
   `actionDrainSuppressEnter/Leave`; verify no new re-entry sites in
   Phase E.
4. **Loop-exit conditions** — addressed in Phase G.

## Why this is the right shape

The original plan tried to land everything atomically because the FIFO
order is a global invariant — partial implementations don't preserve it.
The reframe trades one atomic commit for two atomic commits (Phase D
flip and Phase F gate change), but separates them with infrastructure
sessions that build the necessary primitives **without** committing to
the new behavior. That makes regressions traceable to a single change
rather than a tangled atomic.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `blocked/GOTO_FIFO_UNIFICATION_PLAN.md` | Architectural reference. Don't implement it directly — implement THIS plan, which preserves its FIFO-order analysis but ships in shippable units. |
| `complete/DRAIN_SUPPRESS_PRIMITIVE_PLAN.md` | Foundation for Phase E's drain-suppress wrap. |
| `incomplete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Sensitive to Phase D/E/F drain-timing changes. Cross-check after each behavior phase. |
| `incomplete/TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN.md` | Independent code paths but shares catch-up machinery. Spot-check during Phase E. |
| `PLAN_DEPENDENCIES.md` | Index — update when this plan moves buckets. |
