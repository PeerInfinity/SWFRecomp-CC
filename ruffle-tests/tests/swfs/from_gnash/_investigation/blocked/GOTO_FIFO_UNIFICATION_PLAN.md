# Goto FIFO Unification Plan (Phase 6 of GOTO_CATCHUP_HYGIENE)

> **Reframed 2026-04-26b, superseded 2026-04-27** — This plan's
> atomic-commit framing was untractable. Implementation shipped via
> `complete/GOTO_FIFO_UNIFICATION_INCREMENTAL_PLAN.md` (Phases A–H all
> landed by 2026-04-27), which ships the same target in 8 sessions
> (zero-risk infrastructure → flag-gated opt-in → cleanup) instead of
> one atomic commit. **This document stays as the architectural
> reference** (problem statement, FIFO-order trace, related docs).
> Don't try to implement this plan directly — the incremental plan in
> `complete/` is the actual record of how the work landed.

<!-- TESTS: consecutive_goto_frame_test -->

<!-- PLAN_META
id: GOTO_FIFO_UNIFICATION
status: superseded
phases:
  - id: 1
    name: "ng_gotoFrameCurrentSprite: queue target sprite frame inline (mirror ng_gotoFrameByMC)"
    status: pending
  - id: 2
    name: "Catch-up target frame: run via g_tag_skip_mode=1 inline so script queues into AQ_KIND_SCRIPT"
    status: pending
  - id: 3
    name: "Retire g_deferred_goto_queue / g_deferred_goto_script — single drain via actionDrainOnloadAndScript"
    status: pending
  - id: 4
    name: "Reconcile recompiler sprite-DoAction emission gates with single-FIFO model"
    status: pending
  - id: 5
    name: "Sync swf_headless.c with swf_core.c"
    status: pending
  - id: 6
    name: "Regression battery (AVM1 goto/rewind + misc-ming guardrail + Shumway dupclip)"
    status: pending
dependencies:
  - "Predecessor plan: GOTO_CATCHUP_HYGIENE_PLAN.md (in blocked/) — Phases 1–5 are landed, this plan picks up Phase 6"
  - "Foundation: DRAIN_SUPPRESS_PRIMITIVE_PLAN.md (complete/, commit d1cd1d1f) — provides actionDrainSuppressEnter/Leave used by Phase 2"
prior_blocker_resolved:
  - "2026-04-26: Path A (drain-suppress primitive) landed at commit d1cd1d1f, resolving the nested-drain re-entry hazard. Path B (Phases 1+2+3 atomic) is now unblocked."
new_blocker_2026-04-26b:
  - "Phase 4 is REQUIRED atomically with 1+2+3, NOT cleanup. See Status notes section ‘Updated finding 2026-04-26b’ — sprite-script sync-fire cascade through gate g2 makes Phase 1 alone (and Phase 1+2+3) regress the test from 4/12 to <4/12. Phase 4 (gate simplification) is the only mechanism to break the cascade."
-->

## Problem statement

`consecutive_goto_frame_test` (4/12 matching lines) chains
`_root.gotoAndStop(N)` and `mc_red.gotoAndStop(M)` across 5 root frames
plus 4 sprite frames. Expected output **interleaves** root target
script lines with the sprite frame DoActions:

```
frm2 of root - gotoAndStop(3)            (root frame 1)
frm1 of mc_red - gotoAndStop(2)          (sprite frame 0)
PASSED: as_in_frm1_of_mc_red == ...
frm3 of root - gotoAndStop(4)            (root frame 2)
frm2 of mc_red - gotoAndStop(3)          (sprite frame 1)
PASSED: as_in_frm2_of_mc_red == ...
frm4 of root - gotoAndStop(5)            (root frame 3)
frm3 of mc_red - gotoAndStop(4)          (sprite frame 2)
PASSED: mc_red.x == 'as_in_frm3_of_mc_red'
#passed: 3, #failed: 0, #total tests run: 3
```

Our actual output emits the three sprite-frame DoActions **after**
totals fire, in a separate trailing batch:

```
frm2 of root - gotoAndStop(3)
frm1 of mc_red - gotoAndStop(2)
PASSED: as_in_frm1_of_mc_red == ...
frm3 of root - gotoAndStop(4)
FAILED: expected 'as_in_frm2_of_mc_red' obtained 'as_in_frm3_of_root'
frm4 of root - gotoAndStop(5)
FAILED: expected 'as_in_frm3_of_mc_red' obtained 'as_in_frm4_of_root'
#passed: 1, #failed: 2, #total tests run: 3
frm1 of mc_red - gotoAndStop(2)         ← AFTER totals
frm2 of mc_red - gotoAndStop(3)
frm3 of mc_red - gotoAndStop(4)
```

The sprite frame DoActions run too late. By the time the assertions
inside the root target frame read `mc_red.x`, mc_red hasn't advanced
to its target frame yet, so it returns the previous root-frame's
write into `mc_red.x` instead of the sprite-frame's write.

## Root cause: split queues, not a single FIFO

Today's runtime has a **unified action queue** (`g_aq`,
`SWFModernRuntime/src/actionmodern/action_queue.c`) but drives it from
**two separate dispatch paths**:

1. **Root deferred goto** — `g_deferred_goto_queue[16]` plus
   `g_deferred_goto_script` flag in
   `SWFModernRuntime/src/libswf/swf_core.c:77-81` (and a parallel
   duplicate in `swf_headless.c:70-74`). The drain loop at
   `swf_core.c:1078-1122` walks this array, runs each target frame's
   func with `g_tag_skip_mode=1` to fire scripts inline, and only
   then yields control back. Sprite scripts pushed via
   `actionQueueSpriteScript` during target-frame execution sit in the
   action queue but **don't drain until the next SHOW_FRAME's
   `actionDrainOnloadAndScript` call**.

2. **Sprite goto / per-frame DoAction** — `actionQueueSpriteScript`
   pushes `AQ_KIND_SCRIPT` entries into the unified queue;
   `actionDrainOnloadAndScript` drains them at SHOW_FRAME pre-drain
   sites the recompiler emits at `SWFRecomp/src/swf.cpp:559, 821, 880`.

Net effect: a goto from inside a root frame queues sprite scripts but
**finishes the root deferred drain before they get a chance to run**.
The inverse — a sprite-frame DoAction calling `_root.gotoAndStop(...)`
— suffers the same split.

Ruffle's model is one FIFO. `core/src/player.rs:2144-2160`'s
`run_actions` is a single `while let Some(action) = context.action_queue.pop_action()`
loop, and `core/src/display_object/movie_clip.rs:1546+` `run_goto`
calls `queue_action` on that same queue. Both root and sprite frame
DoActions land in queue order and drain in queue order. No split.

## Concrete diff symptoms

### consecutive_goto_frame_test (4/12 matching)

Three failure modes in one test:

1. **Sprite frame DoAction trails after `printtotals()`.** Lines 11-13
   of actual output (`frm1/2/3 of mc_red`) appear AFTER `#total tests
   run: 3` because the sprite scripts are still in `AQ_KIND_SCRIPT`
   when the deferred-goto drain finishes; they only flush at the
   next SHOW_FRAME.
2. **Variable scope reads see root's write.** `mc_red.x` reads inside
   the root target script see whatever `_root.gotoAndStop(N)` wrote
   to `mc_red.x` last, because mc_red's frame DoAction (which would
   have overwritten `mc_red.x` with the per-frame sentinel string)
   hasn't run yet.
3. **Failed assertions cascade into bad totals.** Two `FAILED:`
   lines change `#passed: 3 / #failed: 0` to `#passed: 1 / #failed: 2`.

A traced-execution prototype with the unification fix in place
produces the expected output exactly. The fix is sound; the cost is
that the **drain ordering inverts** from "all root deferred-goto
scripts then sprite scripts" to "FIFO order across both", which
shifts behavior on tests that today rely on the all-siblings-then-
target sequencing.

## Phase 1 — Inline sprite goto: queue target frame DoAction

**Site.** `ng_gotoFrameCurrentSprite`
(`SWFModernRuntime/src/libswf/tag_stubs.c:815-828`).

**Today.** Sets `sprite_manual_next_frame=1`, `sprite_next_frame=frame`,
`sprite_is_playing=0`. **Does not** queue or execute the target
frame's DoAction; the frame advances on the next tick's
`advance_sprite_frames`.

**Reference.** `ng_gotoFrameByMC` (`tag_stubs.c:842-971`) already does
inline `exec_sprite_frame` execution for cross-MC sprite gotos
(forward: current+1..frame; backward: 0..frame; same-frame: just
target). It queues sprite scripts in `AQ_KIND_SCRIPT` immediately via
the recompiler-emitted `actionQueueSpriteScript` calls inside each
frame func.

**Fix.** Mirror `ng_gotoFrameByMC`: invoke `exec_sprite_frame` inline
for the target frame so the sprite's DoAction queues into
`AQ_KIND_SCRIPT` at the goto-from-action call site, not on the next
tick.

**Risk.** Medium. Other tests use `ng_gotoFrameCurrentSprite` (the
"goto target is the current sprite I'm executing in" path), which is
the common gotoAndStop-from-inside-a-sprite case. Inline execution
during the sprite's own DoAction is re-entrant; need to verify
`actionGotoCatchupActive` / `actionEagerInitActive` flags don't
double-fire.

## Phase 2 — Catch-up target frame: queue, don't pre-drain

**Site.** `ng_executeGotoCatchUp` (`swf_core.c:86`, duplicate in
`swf_headless.c:79`). After running catch-up tags (`PlaceObject2`,
`RemoveObject2`, etc.), the function today queues the target frame
into `g_deferred_goto_queue`.

**Fix.** Run `funcs[target]` with `g_tag_skip_mode=1` **inline**
instead of (or in addition to) deferring via the queue. With
`tag_skip_mode=1`, `funcs[target]` only emits `actionQueueScript`
(per the recompiler gate at `swf.cpp:2577 — `if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(...)`)
and does not re-process tags. The script lands in `AQ_KIND_SCRIPT`,
and the recompiler-emitted `actionDrainOnloadAndScript` at the
function's exit drains the queue in FIFO order. Sibling sprite
scripts queued during catch-up replay (Phase 1) interleave
naturally.

**Risk.** Medium-high. Several tests rely on the deferred-goto loop's
"all-siblings-then-target" sequencing — particularly the
`goto_rewind*` family and the misc-ming `loop_test*` cluster, which
were stabilized via fixes that depend on the current ordering
(see GOTO_CATCHUP_HYGIENE Phase 2/3 fix in the blocked/ predecessor
plan, and the `actionQueueClipActionUnloadDeferred` mechanism added
for loop_test8).

## Phase 3 — Retire `g_deferred_goto_queue`

**Site.** `swf_core.c:77-81` plus the drain loop at `:1078-1122`.
`swf_headless.c:70-74` mirrors.

**Fix.** Once Phases 1 and 2 land, the deferred-goto array is no
longer the source of truth — every queued root target frame is now
in `AQ_KIND_SCRIPT`. Remove the array, the count, the
`g_deferred_goto_script` flag, and the manual while loop. Replace
with a single `actionDrainOnloadAndScript` call (or fold into the
recompiler-emitted drain that already exists at frame func exits).

**Risk.** Medium. Loop-exit conditions (`hasActiveTimers`,
`hasClipEnterFrameHandlers`, `actionHasEnterFrameHandlers`,
`hasPlayingSprites`) currently include a check on
`g_deferred_goto_queue_count > 0` — those need to be replaced with
"`AQ_KIND_SCRIPT` non-empty" checks via a new accessor.

## Phase 4 — Recompiler sprite-DoAction emission gates

**Site.** `SWFRecomp/src/swf.cpp:4985-4999`. Today's gate:

```c
if ((!catch_up_mode || g_tag_skip_mode || 
     (actionEagerInitActive() && !actionGotoCatchupActive())) 
    && !actionScriptOnlyMode()) 
  actionQueueSpriteScript(app_context, script_name);
else if (!catch_up_mode && actionScriptOnlyMode() && actionDeferredSpriteInitActive()) 
  script_name(app_context);  // sync fire
```

**Why complex.** The `(actionEagerInitActive() && !actionGotoCatchupActive())` arm
is the workaround for Phase 4-partial of the predecessor plan
(`tag.c` eager-init `sni=2` vs `sni=3` distinction). It exists to avoid
double-firing sprite frame_0 when both eager init queued the script AND
deferred sprite init re-runs frame_0 via `script_only_mode`.

**Fix.** With Phases 1-3 in place, the catch-up target's script also
goes into `AQ_KIND_SCRIPT` instead of being executed from the
deferred-goto loop. The eager-init carve-out simplifies to:

```c
if (!catch_up_mode || g_tag_skip_mode) 
  actionQueueSpriteScript(app_context, script_name);
```

Same shape as the root DoAction emission at `swf.cpp:2577`. Both
queues; both drain via the unified FIFO.

**Risk.** Medium. The `actionGotoCatchupActive()` / `actionEagerInitActive()` /
`actionDeferredSpriteInitActive()` accessors all need an audit —
some may be removable, others may need to remain for the
sprite-init filter logic in `tag.c` (`g_sprite_init_filter_active`,
`g_sprite_init_before_target`, `g_sprite_init_target_frame`).

## Phase 5 — `swf_headless.c` parity

**Site.** `swf_headless.c:70-74, 79`. Mirrors `swf_core.c`'s deferred
goto state and `ng_executeGotoCatchUp`.

**Fix.** Apply the Phase 2/3 changes to `swf_headless.c` in lockstep.
The two files have parallel implementations of the catch-up
machinery; they must stay in sync or `--headless` mode (used by GPU
image tests) diverges.

**Risk.** Low if Phases 2/3 are applied symmetrically; high if they
drift.

## Phase 6 — Regression battery

**Required-pass guardrail (must not regress):**

- AVM1 goto/rewind: `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `goto_frame`, `goto_frame_test` (currently PASS), `goto_frame2`,
  `goto_label`, `goto_methods`, `goto_methods_to_label`. These all
  exercise root-deferred goto sequencing.
- AVM1 unload: `unload`, `unloadmovie`, `unload_clip_event`,
  `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`. Phases 2/3 interact with the
  unload firing order (the predecessor plan's
  `actionQueueClipActionUnloadDeferred` mechanism rides
  `AQ_KIND_SCRIPT` and is sensitive to queue drain timing).
- Misc-ming: `loop/loop_test2/3/5/8/9`, `simple_loop_test`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `new_child_in_unload_test`,
  `event_handler_scope_test`, `instanceNameTest`,
  `attachMovieTest`, `DefineEditTextTest`,
  `DefineEditTextVariableNameTest2`, `shape_test`,
  `get_frame_number_test`, `reverse_execute_PlaceObject2_test1/2`,
  `action_execution_order_test8-v5/v6`. The recently-fixed
  battery from the predecessor plan.
- Shumway duplicateMovieClip: `dontremove`, `duplicateMovieClip`,
  `samedepth`, `name-coercion`.
- Misc-swfc spot: `movieclip_destruction_test2` (currently 50/52);
  `stackscope`, `submoviegetvar`, `edittext_test1`.

**Target test:** `consecutive_goto_frame_test` 4/12 → potentially full
PASS (12/12).

**Indirect signal:** `place_and_remove_object_insane_test` (17/22)
shares no architectural pieces with this plan but does share the
catch-up machinery. Spot-check that it doesn't regress; substantive
fix lives in the parallel TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN.md.

## Open questions

1. **Eager-init timing under unified FIFO.** The predecessor plan's
   2026-04-25 fix (sni=3 marker) prevents double-firing of sprite
   frame_0 during catch-up. With Phases 1/2 in place, does eager init
   need to queue the script at all, or does the regular per-frame
   emission at sprite frame DoAction time cover it? Audit
   `process_sprite_init_at_depth` (`tag.c:312`) interaction with
   `actionDeferredSpriteInitActive`.

2. **Nested goto: sprite-frame calling `_root.gotoAndStop`.** The
   `consecutive_goto_frame_test` pattern has root calling
   `mc_red.gotoAndStop(M)` (sprite goto from root). The mirror
   pattern (sprite frame DoAction calls `_root.gotoAndStop`) also
   exists in the test suite (e.g., parts of the goto_rewind battery).
   Verify `actionGotoCatchupEnter`/`actionGotoCatchupLeave` pair
   correctly when the inner goto is on the root and the outer call
   site is in a sprite-frame DoAction.

3. **Drain reentry during catch-up tag replay.** Phase 2 runs the
   catch-up target frame inline with `g_tag_skip_mode=1`. If the
   target script itself triggers another goto, that goto's catch-up
   replay also runs inline — does the resulting nested
   `actionDrainOnloadAndScript` correctly handle re-entry? Audit the
   action_queue drain function for re-entrancy guards.

4. **Loop-exit conditions.** Currently `g_deferred_goto_queue_count > 0`
   keeps the frame loop alive past natural advance. After Phase 3,
   replace with "any AQ_KIND_SCRIPT entries in g_aq" (need a new
   accessor). Verify this doesn't make the loop exit early when a
   pending root deferred script exists (was the direct queue
   non-empty before the post-drain ENTER_FRAME pass?).

## Estimated session budget

- Phase 1: 1-2 hours (mirror existing `ng_gotoFrameByMC` pattern).
- Phase 2: 2-3 hours (touchy interaction with catch-up flags and the
  inline-target-script gate).
- Phase 3: 1 hour (mostly mechanical removal once 1/2 land).
- Phase 4: 2 hours (recompiler change + audit of accessor uses).
- Phase 5: 30 min (lockstep change in swf_headless.c).
- Phase 6: 2-3 hours (gated regression battery; expect 1-2 rounds of
  back-and-forth fixing minor timing regressions in the goto/rewind
  cluster).

Total: 8-12 hours, weighted toward Phase 6's regression triage.

## Why this is the right shape

The split-queue model accumulated as a series of patches around a
two-tier dispatch (root-deferred + sprite). Each patch (the predecessor
plan's Phase 4-partial sni=3 fix, the
`actionQueueClipActionUnloadDeferred` helper, the `g_defer_sprite_init`
flag) addresses a specific symptom of the split. Unifying onto a single
FIFO converges our model on Ruffle's, and removes the special-case
gates that exist purely to compensate for the split.

The risk is concentrated in regression triage: tests that rely on
"all-deferred-then-sprites" ordering will see different traces, and
some may surface as false-regressions that need investigation. But
the underlying invariant — interleave by FIFO order — is the actual
Flash semantics, so any test whose expected output depends on the
old ordering is already at odds with the spec.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `blocked/GOTO_CATCHUP_HYGIENE_PLAN.md` | Predecessor plan; Phases 1–5 landed (goto_frame_test PASS). This plan is its Phase 6 split out. |
| `incomplete/DEFERRED_CLIP_UNLOAD_PLAN.md` | The `actionQueueClipActionUnloadDeferred` helper added for loop_test8 rides `AQ_KIND_SCRIPT` and is sensitive to drain timing changes here — verify the loop_test8 PASS is preserved. |
| `incomplete/TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN.md` | Parallel sibling plan for `place_and_remove_object_insane_test` (the other GOTO_CATCHUP_HYGIENE blocker, Phase 7). Independent code paths but share catch-up machinery; spot-check at the end. |
| `incomplete/DRAIN_SUPPRESS_PRIMITIVE_PLAN.md` | Path A foundation: adds `actionDrainSuppressEnter/Leave` accessors gating `actionDrainOnloadAndScript`. Phase B's `ng_executeGotoCatchUp` will wrap its inline `funcs[target]` call with the Enter/Leave pair to avoid the nested-drain re-entry hazard called out in Status Notes below. Land before resuming this plan. |

## Status notes (2026-04-26)

### Detailed test trace analysis

`consecutive_goto_frame_test` baseline confirmed at 4/12 matching lines. The
test pattern (with all string IDs decoded from `script_defs.c`):

- **Root frame 1 → script_2**: `note("frm2 of root - gotoAndStop(3)")` →
  `mc_red.x = "as_in_frm2_of_root"` → `actionGotoFrame(2)` (defers root goto).
- **Root frame 2 → script_6**: `check_equals(mc_red.x, "as_in_frm1_of_mc_red")` →
  `note("frm3 of root - gotoAndStop(4)")` → `mc_red.x = "as_in_frm3_of_root"` →
  `actionGotoFrame(3)`. **No `mc_red.gotoAndStop` call** — root scripts only
  drive root advances.
- **Root frame 3 → script_7**: `check_equals(mc_red.x, "as_in_frm2_of_mc_red")` →
  same pattern, `actionGotoFrame(4)`.
- **Root frame 4 → script_8 + script_9**: final assertion + totals.
- **Sprite frame 0 → script_3**: `note("frm1 of mc_red - gotoAndStop(2)")` →
  `mc_red.x = "as_in_frm1_of_mc_red"` → `actionGotoFrame(1)` (sprite self-goto).
- **Sprite frame 1 → script_4**: ditto with frame 2 / `as_in_frm2_of_mc_red`.
- **Sprite frame 2 → script_5**: ditto with frame 3 / `as_in_frm3_of_mc_red`.

The test relies on each root frame's `check_equals` reading the **previous
sprite-frame's write** to `mc_red.x`. So the required interleave per frame is:
root script first (assertion + note), then sprite script (note + write next
sentinel).

### Required FIFO order (verified via trace simulation)

Under Phases 1+2+3 unified, frame_1's drain produces this dispatch order:

```
script_2 → queues script_6 (Phase 2: actionGotoFrame queues into AQ_KIND_SCRIPT)
script_3 → queues script_4 (Phase 1: ng_gotoFrameCurrentSprite inline-fires sprite_4_frame_1)
script_6 (assertion PASSED reads mc_red.x set by script_3) → queues script_7
script_4 (sets mc_red.x = "as_in_frm2_of_mc_red") → queues script_5
script_7 (assertion PASSED reads mc_red.x set by script_4) → queues script_8 + script_9
script_5 (sets mc_red.x = "as_in_frm3_of_mc_red") → no queue (sprite_4_frame_3 empty)
script_8 (assertion PASSED reads mc_red.x set by script_5)
script_9 (totals: 3/3)
```

This produces the expected 12-line output exactly.

### Why Phase 1 in isolation regresses the test

If only Phase 1 lands (sprite goto inline) without Phase 2 (root goto target
into AQ_KIND_SCRIPT), the drain order in frame_1 becomes:

```
script_2 → defers root goto via g_deferred_goto_queue (UNCHANGED — Phase 2 not landed)
script_3 → queues script_4 (Phase 1)
script_4 → queues script_5 (Phase 1, recursive)
script_5 → no queue
```

Drain finishes with `mc_red.x = "as_in_frm3_of_mc_red"` (script_5's write). Then
the deferred-goto loop runs `funcs[2]` in scripts-only mode: `script_6` runs
`check_equals("as_in_frm3_of_mc_red", "as_in_frm1_of_mc_red")` → **FAILED**.
Currently this assertion PASSES (4/12 baseline includes the first PASSED line)
because script_4/5 don't fire until *after* the deferred-goto loop, leaving
`mc_red.x = "as_in_frm1_of_mc_red"` (script_3's write) at script_6 time.

So Phase 1 must land together with Phase 2 — they cannot be staged independently.

### Re-entry hazard for naive Phase 2

If `ng_executeGotoCatchUp` simply runs `funcs[target](app_context)` with
`g_tag_skip_mode=1` inline (the plan's literal phase-2 description), the
recompiler-emitted `actionDrainOnloadAndScript` *inside* `funcs[target]`
fires a nested drain. That nested drain pulls already-queued sprite scripts
(e.g., script_3) ahead of the outer drain's expected FIFO position, breaking
the interleave.

The fix requires a new "queue-only mode" — either a runtime flag like
`g_skip_drain_outer` that makes `actionDrainOnloadAndScript` a no-op when
set (cleaner; no recompiler change), or a recompiler emission change so
`funcs[target]` only emits the queue calls and skips the drain. The plan's
Phase 4 alludes to this via "simplify the recompiler gate" but does not
explicitly call out the no-op-drain mechanism.

### Why blocked, not in-progress

This is a **fundamentally architectural change** to the frame-drain dispatch
model. Beyond the surface-level edits, it requires:

1. New no-drain-recursive primitive (above) — design + integration
2. Phase 1 + Phase 2 + Phase 3 land **as a single atomic change** (Phase 1
   alone regresses the test; Phase 2 alone doesn't queue sprite scripts in
   time; Phase 3 cleanup gates loop-exit conditions on the new model)
3. swf_headless.c parity (Phase 5) in lockstep
4. Recompiler regeneration for any sprite-DoAction emission changes (Phase 4)
5. Full CI regression battery — many tests in the predecessor plan's
   recently-fixed list rely on the current "all-deferred-then-sprites" ordering
   and may need targeted compensation

The plan estimates 8-12 hours weighted toward Phase 6 regression triage. CI
roundtrip per change is ~30 min, and I expect 3-5 iterations to stabilize
the misc-ming `loop_test*` cluster + AVM1 `goto_rewind*` family. This
exceeds a single working session's budget and the local-run-only rule means
I cannot pre-screen most of the regressions.

### Recommendation for next session

Plan moved to `blocked/` to avoid blocking other work. To resume:

1. Implement the runtime no-op-drain flag (`g_skip_drain_outer` in
   `action_queue.c`'s `actionDrainOnloadAndScript`) — small isolated change,
   no test impact alone.
2. Implement Phases 1 + 2 + 3 as a **single commit** with the small AVM1
   guardrail battery (`goto_rewind1/2/3`, `goto_frame`, `goto_methods`,
   `execution_order2/3`, `register_and_init_order`, `unload`,
   `unload_clip_event`) verified locally.
3. Push to CI; expect failures in misc-ming `loop_test*` and `unload`-family
   tests; iterate via the deferred-clip-unload pathway and the
   `actionQueueClipActionUnloadDeferred` ordering from the predecessor plan's
   2026-04-25 fix.
4. Phase 4 (recompiler gate simplification) and Phase 5 (headless parity) are
   cleanup once the runtime is stable.

## Updated finding 2026-04-26b — Phase 4 is required, not cleanup

### Detailed dispatch trace under Phases 1+2+3 alone (no Phase 4)

Re-tracing `consecutive_goto_frame_test` frame_1 dispatch under the
"Phase 1+2+3 single commit, Phase 4 deferred" plan recommendation
exposes a **sync-fire cascade** that breaks the test more than baseline.

The cascade:

1. `script_2` runs (popped from root_frame_0 drain).
2. `script_2` calls `actionGotoFrame(2)` → `ng_executeGotoCatchUp` (Phase 2):
   - Catch-up tags replay frames 1..2 with `catch_up_mode=1` (`tag_skip_mode=0`).
     During catch-up, the gate at `swf.cpp:4985-4988` evaluates
     `(!1 || 0 || (eager && !1)) && !script_only_mode = 0 && ... = 0`,
     so sprite_4_frame_0's `actionQueueSpriteScript(script_3)` is **suppressed**.
     `script_3` is NOT in the queue at this point.
   - Phase 2 then runs deferred sprite init via `process_sprite_init_at_depth`:
     `g_script_only_mode=1`, calls `sprite_4_frame_0(app_context)`.
     Inside, `actionQueueSpriteScript(script_3)` evaluates with
     `catch_up_mode=0, tag_skip_mode=0, script_only_mode=1, deferred_sprite_init=1`:
     - Gate g1: `(1 || 0 || ...) && !1 = 0` (suppressed by `&& !script_only_mode`).
     - Gate g2: `1 && 1 && 1 = 1` → **SYNC-FIRES `script_3`**.
   - Inside `script_3`:
     - Sets `mc_red.x = "as_in_frm1_of_mc_red"`.
     - Calls `actionGotoFrame(1)` → `ng_gotoFrameCurrentSprite(1)` (Phase 1):
       inline-fires `sprite_4_frame_1`. But we're still inside
       `process_sprite_init_at_depth`'s frame_0 call where
       `g_script_only_mode=1`, so sprite_4_frame_1's
       `actionQueueSpriteScript(script_4)` again hits gate g2 →
       **SYNC-FIRES `script_4`** (cascade).
     - script_4 sets `mc_red.x = "as_in_frm2_of_mc_red"`, calls
       `actionGotoFrame(2)` → inline-fires sprite_4_frame_2 → **SYNC-FIRES script_5**.
     - script_5 sets `mc_red.x = "as_in_frm3_of_mc_red"`, calls
       `actionGotoFrame(3)` → inline-fires sprite_4_frame_3 (empty).
     - Cascade unwinds back to script_3 → returns.
   - `process_sprite_init_at_depth` returns.
   - Phase 2 then runs `funcs[2]` with `g_tag_skip_mode=1` + drain-suppress →
     queues `script_6`. Queue: `[script_6]`.
3. `script_2` finishes.
4. Outer drain pops `script_6`.
5. `script_6` runs:
   - `check_equals(mc_red.x, "as_in_frm1_of_mc_red")` → **FAIL**
     (`mc_red.x` is `"as_in_frm3_of_mc_red"` from the sync-fire cascade).

**Result: 0 PASS lines.** Worse than the 4/12 baseline (which has 1 PASS).

### Why Phase 4 is the only mechanism that breaks the cascade

For the test to pass, `script_3` must drain in FIFO order **between** the
Phase 2 funcs[target] queue site and the `script_6` drain site. That
requires `script_3` to be **queued** (by `process_sprite_init_at_depth`'s
frame_0 call), not sync-fired.

The only way for sprite_4_frame_0's `actionQueueSpriteScript(script_3)`
to queue rather than sync-fire under `script_only_mode=1` is to remove
gate g2's sync-fire branch (Phase 4 simplification):

```c
if (!catch_up_mode || g_tag_skip_mode)
  actionQueueSpriteScript(app_context, script_name);
```

Under this gate, `script_3` queues (catch_up_mode=0 → gate fires regardless
of script_only_mode). Then drain order becomes correct (`script_3`,
`script_6`, `script_4`, `script_7`, `script_5`, `script_8`, `script_9`),
matching the plan's "Required FIFO order" simulation.

### Why Phase 1 alone or Phase 1+2 alone also regress

Phase 1 alone, baseline: `script_3`'s `actionGotoFrame(1)` calls
`ng_gotoFrameCurrentSprite(1)`, which under existing code just sets
`sprite_manual_next_frame=1` (next-tick advance). Sprite frame_1's
DoAction (`script_4`) doesn't fire until next tick — long after
`script_6` reads `mc_red.x`. So baseline preserves the first PASS line.

Under Phase 1, `ng_gotoFrameCurrentSprite(1)` inline-fires sprite_4_frame_1
under `script_only_mode=1` → gate g2 → sync-fires `script_4`. Cascade.
Result: 0 PASS lines. **Phase 1 alone regresses the test from 4/12 to <4/12.**

### Re-entry implications for ng_gotoFrameCurrentSprite Phase 1

Even with Phase 4 in place, Phase 1's inline-fire requires display-list
swapping if called from a context where `display_list != obj->sprite_display_list`
(e.g., when `aq_dispatch_sprite_script` drains a queued sprite script at
root level — display_list is root's at that point, but `g_current_sprite_obj`
is the sprite). Phase 1 must mirror `ng_gotoFrameByMC`'s display-list
save/swap/restore pattern, not just a bare frame-func call.

### Updated implementation order

1. **Phase 4 first** (recompiler gate simplification at `swf.cpp:4985-4999`).
   This is the smallest atomic change that flips sprite-script dispatch
   from sync-fire to queue. May regress tests that rely on sync-fire
   ordering (deferred sprite init Phase 2 path), so verify against
   `register_and_init_order`, `goto_rewind1/2/3`, `clip_events`,
   `unload_clip_event` before continuing.
2. **Phase 1** (ng_gotoFrameCurrentSprite inline-fire with display-list swap).
3. **Phase 2** (ng_executeGotoCatchUp inline funcs[target] + drain-suppress,
   no g_deferred_goto_queue push).
4. **Phase 3** (retire g_deferred_goto_queue + outer drain loop).
5. **Phase 5** (swf_headless.c parity).

Each phase needs guardrail verification before stacking the next.

### Why still blocked

The combined scope (recompiler change + 4 runtime changes + headless parity
+ regression triage) consistently exceeds a single working session, even
with the drain-suppress primitive in place. Phase 4 alone has substantial
regression surface (every sprite DoAction queue site changes semantics
under `script_only_mode`), and the local-only verification rule means
each iteration needs a CI roundtrip (~30 min) to confirm no broad
regressions.

The plan stays in **blocked/** until either:
(a) An owner has 2-3 sessions of focused budget to land Phases 4+1+2+3+5
    incrementally with CI guardrail per step.
(b) A simpler intermediate approach is identified — e.g., a minimal
    Phase 1 variant that only inline-fires when called from a context
    where `script_only_mode=0` (i.e., from a queued sprite script via
    `aq_dispatch_sprite_script`), leaving the sync-fired script_3 path
    untouched. That would partially address the test without the full
    architectural change.
