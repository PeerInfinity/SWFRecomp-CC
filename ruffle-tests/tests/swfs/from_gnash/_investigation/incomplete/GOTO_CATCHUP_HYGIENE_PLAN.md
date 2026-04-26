# Goto Catch-Up Hygiene Plan

<!-- TESTS: goto_frame_test, consecutive_goto_frame_test, place_and_remove_object_insane_test -->

<!-- PLAN_META
id: GOTO_CATCHUP_HYGIENE
status: in_progress
phases:
  - id: 1
    name: "Goto-induced RemoveObject2: clear name resolution (var_map / dynamic_props / display lookup)"
    status: partial
  - id: 2
    name: "Catch-up unload event dispatch — fire unload events on MCs removed during catch-up replay"
    status: pending
  - id: 3
    name: "Removed-zone depth arithmetic for goto-induced unloads (-16485 vs -16284)"
    status: pending
  - id: 4
    name: "Sprite script double-fire during catch-up (consecutive_goto_frame_test)"
    status: pending
  - id: 5
    name: "Final-frame DoAction execution — last frame's script not running on forward goto"
    status: pending
  - id: 6
    name: "Sprite scripts trailing after totals — drain ordering with deferred scripts"
    status: pending
-->

## Status (2026-04-25)

| Test | Pre-fix | Current | Δ |
|------|---------|---------|---|
| place_and_remove_object_insane_test | 15/22 | 17/22 | +2 |
| goto_frame_test | 4/15 | 4/15 | 0 |
| consecutive_goto_frame_test | 3/12 | 4/12 | +1 |

### 2026-04-25 fix #2 — eager-init sni=3 distinguishes "scripts queued" (Phase 4 partial)

**Change.** `SWFModernRuntime/src/libswf/tag.c`:
1. `tagPlaceObject2` / `tagPlaceObject2Ratio` sprite eager-init path: set
   `sprite_needs_init` based on `actionGotoCatchupActive()`:
   - `2` (under goto catchup): the recompiler-emitted gate `g1` was false,
     so the sprite's DoAction wasn't queued. Phase 2 must re-run `frame_0`
     in `script_only_mode` to fire scripts inline (gate `g2`).
   - `3` (normal flow): `g1` was true and the script was queued, will fire
     via the SHOW_FRAME drain. Phase 2 must NOT re-run `frame_0`.
2. `process_sprite_init_at_depth` Phase 2: split `was_eager` into
   `was_eager_catchup` (sni==2, run frame_0 in script_only_mode) and
   `was_eager_normal` (sni==3, skip frame_0 — already queued).

**Why this was needed.** Pre-fix, the eager init at frame_1's
`tagPlaceObject2` set `sni=2` regardless of context. The recompiler-emitted
gate `g1 = (!cu || tsm || (eager && !catchup)) && !som` queued
`script_3` because `eager && !catchup` was true. Then Phase 2 (in
`ng_run_deferred_sprite_init_before` after script_2's `gotoFrame(2)`
deferred-script processing) re-ran `sprite_4_frame_0` in
`script_only_mode=1` + `deferred_sprite_init_active=1`, which fired
gate `g2` and ran `script_3` *again* inline. Result: "frm1 of mc_red -
gotoAndStop(2)" printed twice. The new sni=3 marker tells Phase 2 the
script is already in the queue.

**Verification.**
- 43-test AVM1 goto/rewind/unload/lifecycle battery: 43/43 effective pass.
- 20-test misc-ming guardrail (loop_test2-9, simple_loop_test,
  static_vs_dynamic1/2, place_and_remove_object_test,
  new_child_in_unload_test, event_handler_scope_test, instanceNameTest,
  attachMovieTest, DefineEditTextTest/2, shape_test,
  get_frame_number_test, reverse_execute_PlaceObject2_test1/2): 20/20.
- 4-test Shumway duplicateMovieClip suite: 4/4.
- 18-test AVM1 OOP/super/event/init/selection battery (as2_super_*,
  extends_chain, swf5_no_closure, execution_order2, goto_rewind3,
  movieclip_in_removed_button, clip_events, button_children, button_order,
  on_construct, init_object_order, register_class_return_value, selection,
  goto_frame, set_interval, stage_object_properties): 18/18.
- 18-test misc-swfc.all full suite: no changes vs prior baseline.
- 8 already-failing misc-ming tests (same set as fix #1): line counts
  unchanged.

**Remaining diff for `consecutive_goto_frame_test` (8 lines).**
Without the double-fire, the next divergence is around line 5-9. Looking
at expected vs actual:
- expected line 5: `frm2 of mc_red - gotoAndStop(3)` (sprite_4 frame 1 fires).
- expected line 6: `PASSED: as_in_frm2_of_mc_red == as_in_frm2_of_mc_red`
  (script_7 reads `mc_red.x`).
- actual line 5: `FAILED: expected: as_in_frm2_of_mc_red, obtained: as_in_frm3_of_root`.
After the double-fire fix, sprite_4 still doesn't advance to frame 1
to fire `script_4` ("frm2 of mc_red"). Instead `script_7` (root frame 3)
runs and reads `mc_red.x = "as_in_frm3_of_root"` (set by script_6 at root
frame 2). This is Phase 6 (drain ordering — sprite scripts must fire
between root frame deferred drains) and/or sprite-level goto handling
during root catch-up. Out of scope for this fix.

### 2026-04-25 fix — natural backward wrap-back cleanup (Phase 1, partial)

**Change.** `SWFModernRuntime/src/libswf/swf_core.c` natural advance
branch: when `manual_next_frame=1` and `next_frame < current_frame`
(end-of-movie loopback to an earlier frame), invalidate cached
MovieClips and clear display entries whose `placed_at_frame > target`,
mirroring Ruffle's wrap-as-implicit-goto cleanup. Gated on
`!goto_from_action` so this only handles the recompiler-emitted natural
wrap (goto-from-action paths already go through `ng_executeGotoCatchUp`
which has its own `ng_display_clear_after`/`ng_display_cleanup_unplaced_after`
calls).

**Why this was needed.** `place_and_remove_object_insane_test` is a
3-frame movie that loops 10× (30 ticks). Frame 2 places `mc_green` at
depth 4. Frame 0 places `mc_red`/`mc_blue`/`mc_black` at other depths,
never touching depth 4. Without the wrap-back cleanup, depth 4's
`mc_green` entry persisted across the loop boundary, so
`_root.mc_green` resolved to the stale MC instead of `undefined`.

**Verification.**
- 43-test AVM1 goto/rewind/unload/lifecycle/placement battery: 43/43 pass.
- 20-test misc-ming.all guardrail (loop_test2-9, simple_loop_test,
  static_vs_dynamic1/2, place_and_remove_object_test,
  new_child_in_unload_test, event_handler_scope_test, instanceNameTest,
  attachMovieTest, DefineEditTextTest/2, shape_test,
  get_frame_number_test, reverse_execute_PlaceObject2_test1/2): 20/20
  pass.
- 4-test Shumway duplicateMovieClip suite (duplicateMovieClip,
  samedepth, name-coercion, dontremove): 4/4 pass.
- 8-test actionscript.all Selection/LoadVars-vN spot: 8/8 effective pass.
- Other plan target tests (goto_frame_test, consecutive_goto_frame_test)
  unchanged at baseline (their failures are not from natural wrap; they
  exercise explicit gotoFrame2 calls).
- 8 already-failing misc-ming tests (DefineEditTextVariableNameTest,
  attachImported, attachMovieLoopingTest, loop/loop_test10,
  loop/loop_test6) line counts unchanged from pre-fix baseline.

**Remaining diff for `place_and_remove_object_insane_test` (3 lines).**
Lines 10-12 of the diff: `60 == 60` got `60 == 0`,
`undefined == undefined` got `undefined == movieclip`,
`movieclip == movieclip` got `movieclip == undefined`. These look like
order-of-evaluation issues across the 10 loops — likely a stale value
captured into a variable on one iteration that doesn't get updated on
the next, OR a different timing issue not related to wrap-back cleanup.
Not investigated further this session.

## Problem statement

Three tests in `misc-ming.all` share a single coherent root cause:
**catch-up replay during `gotoAndPlay`/`gotoAndStop` doesn't fully
clean up state from frames it skipped or replayed**. The result is
stale MC name resolutions, missing unload events, double-fired sprite
scripts, and wrong-scope variable reads.

| Test | Match | Symptom cluster |
|------|-------|-----------------|
| `goto_frame_test` | 4/15 (26.7%) | Missing final-frame DoAction trace, missing unload events on goto-induced removal, mc1 name lost, depth arithmetic wrong (-16485 expected, -16284 obtained) |
| `consecutive_goto_frame_test` | 3/12 (25.0%) | Sprite frame scripts double-fire during catch-up, sprite scripts trail after `printtotals()`, variable scope confusion (`mc_red.x` reads from root scope) |
| `place_and_remove_object_insane_test` | 15/22 (68.2%) | Removed MC names still resolve (`_root.mc_green == undefined` expected, gets MC ref); `_x` reads from wrong placement; typeof returns 'movieclip' for removed MC |

**Estimated impact:** All 3 tests with a coherent multi-phase fix.
Phase 1 (cleanup of name resolution on goto-induced removal) likely
has the largest single-fix impact across all three tests.

## Concrete diff symptoms

### goto_frame_test (4/15 lines match)

The test does a forward `gotoAndPlay` past frames containing
PlaceObject2/RemoveObject2 sequences. Expected output:

```
PASSED: 1 == 1
PASSED: 3 == 3
PASSED: _root.asOrder  ==  '0+1+2+3+4+5+6+'         ← passes
- PASSED: _root.asOrder  ==  '0+1+2+3+4+5+6+7+'     ← MISSING the 7+
+ FAILED: expected '0+1+2+3+4+5+6+7+' got '0+1+2+3+4+5+6+'  ← actual

PASSED: mc1._target  ==  '/mc1'                     ← mc1 still alive here
- PASSED: mc1._target  ==  '/mc1'                   ← in actual:
+ FAILED: expected '/mc1' got ''                    ← mc1 lost early

- _level0.mc1 unloaded                              ← unload events
- _level0.mc2 unloaded                              ← MISSING entirely

- PASSED: mc1.getDepth()  ==  -16485                ← removed-zone depth
+ FAILED: expected -16485 got ''                    ← mc1 unreachable
- PASSED: mc1._name  ==  'mc1'
+ FAILED: ...

- PASSED: mc2.getDepth()  ==  -16485                ← expected -16485
+ FAILED: expected -16485 got -16284                ← off by 201 (= 16485-16284)
```

**Three distinct bugs surfaced:**

1. **Missing 7+ trace.** Frame 7's DoAction (which appends `7+` to
   asOrder and runs subsequent assertions) doesn't execute. This
   shifts every subsequent assertion line so we lose 5 lines of trace
   before the totals.
2. **Missing unload events.** Goto-induced RemoveObject2 of mc1 and
   mc2 should fire their `onUnload` traces. They don't.
3. **Wrong removed-zone depth for mc2.** Expected `-16485`, got
   `-16284`. The "removed depth zone" formula is
   `-(swf_depth) - 1 - 16384`, so `-16485 = -(100) - 1 - 16384` (mc2
   was placed at SWF depth 100). We return `-16284`, which is
   off by 201 — likely an off-by-one in the formula, or we're using
   AS depth instead of SWF depth.

### consecutive_goto_frame_test (3/12 lines match)

The test uses `gotoAndStop` from inside a sprite's frame DoAction
(nested goto pattern). Expected:

```
frm2 of root - gotoAndStop(3)
frm1 of mc_red - gotoAndStop(2)         ← sprite frame, fires once
PASSED: as_in_frm1_of_mc_red == ...
frm3 of root
frm2 of mc_red - gotoAndStop(3)
PASSED: as_in_frm2_of_mc_red == ...
frm4 of root
frm3 of mc_red - gotoAndStop(4)
PASSED: mc_red.x  ==  'as_in_frm3_of_mc_red'
```

Actual:

```
frm2 of root - gotoAndStop(3)
frm1 of mc_red - gotoAndStop(2)         ← first fire
frm1 of mc_red - gotoAndStop(2)         ← DOUBLE-FIRE
PASSED: ...
frm3 of root
FAILED: expected 'as_in_frm2_of_mc_red' obtained 'as_in_frm3_of_root'  ← scope confused
frm4 of root
FAILED: expected 'as_in_frm3_of_mc_red' obtained 'as_in_frm4_of_root'
#passed: 1, #failed: 2, #total: 3        ← totals fire here
frm1 of mc_red - gotoAndStop(2)          ← sprite scripts AFTER totals
frm2 of mc_red - gotoAndStop(3)
frm3 of mc_red - gotoAndStop(4)
```

**Three bugs:**

1. Sprite frame DoAction `frm1 of mc_red` fires twice — once during
   catch-up replay and once during the deferred drain (which already
   has `g_defer_sprite_init` machinery to prevent exactly this; it's
   not catching this scenario).
2. Variable scope confusion: when sprite's DoAction does `mc_red.x =
   "as_in_frm2_of_mc_red"` then assertions on `mc_red.x` read the
   ROOT's `mc_red.x` write instead. Likely the assignment lands on
   the wrong context (root instead of mc_red dynamic_props).
3. Sprite scripts `frm1/2/3 of mc_red` trail after `#total tests run:
   3` — they should have fired before. Suggests the deferred sprite
   init drain runs AFTER `printtotals()` instead of synchronously
   before the next assertion.

### place_and_remove_object_insane_test (15/22 lines match, 7 failing)

Expected state after a sequence of placements and removals:

```
PASSED: typeof(_root.mc_red) == 'movieclip'
PASSED: typeof(_root.mc_blue) == 'movieclip'
- PASSED: _root.mc_green  ==  undefined         ← mc_green removed earlier
+ FAILED: expected undefined got _level0.mc_green
PASSED: 60 == 60
- PASSED: undefined == undefined                ← typeof check
+ FAILED: expected undefined got movieclip
- PASSED: movieclip == movieclip
+ FAILED: expected movieclip got undefined
- PASSED:  _root.mc_red._x  ==  10              ← mc_red at x=10
+ FAILED: expected 10 got 70                    ← reads wrong placement's x
PASSED: typeof(_root.mc_red) == 'undefined'    ← (after second removal)
... (matches)
- PASSED: typeof(_root.mc_green) == 'undefined'
+ FAILED: expected 'undefined' got movieclip
```

**Same family:** removed MC names continue to resolve. Stale state
from prior placements bleeds into current name lookups.

## Root cause analysis

The three tests stress different paths but share one underlying
problem: **the catch-up replay machinery and post-replay finalization
don't fully purge state from skipped/superseded frames.**

Specifically:

### Cause 1 — RemoveObject2 during catch-up doesn't propagate name removal

When `tagRemoveObject2` runs during catch-up (`catch_up_mode=1`,
`catch_up_backward=1`), the existing code at `tag.c:4453+` defers
the actual removal in some paths (the
`if (catch_up_mode) { ... return; }` branch at line 4473–4495). But
the `child_mc_cache` and `var_map` entries for the named MC remain
live across the catch-up, so `_root.mc_green` still resolves after
the test's logic believes mc_green has been removed.

The 2026-04-22 fix `actionInvalidateMCAtASDepth` covers the
empty-DL-slot case (`tag.c:4554-4564`) but only for
`tagRemoveObject2`'s post-catch-up path on root level. The
goto-target-frame case isn't covered: when a goto target frame's
PlaceObject2 places a different char_id at the same depth that
previously held mc_green, mc_green's child_mc_cache entry should be
invalidated as part of the replacement, but we let it persist.

### Cause 2 — Catch-up doesn't fire unload events

`ng_executeGotoCatchUp` (`swf_core.c:86`) sets `catch_up_mode = 1`
which is honored by `tagRemoveObject2` to suppress inline unload
firing (lines 4473–4495 of tag.c). The intent is that unload events
fire later when the live frame processes the removal. But for
goto-induced removals (where the live frame is the goto target), no
"live frame" RemoveObject2 ever fires — the replacement is part of
the catch-up replay itself.

The 2026-04-24 deferred-onUnload work (`actionFireOnUnload` +
`actionMarkMCPendingRemoval`) is gated on the same `catch_up_mode`
flag and so also gets bypassed during catch-up. Goto-induced unloads
need an explicit drain pass after catch-up that fires the unload
events for all clips removed during the catch-up window.

### Cause 3 — `g_defer_sprite_init` doesn't prevent all double-fires

The existing `g_defer_sprite_init` flag (`tag.c:157`) suppresses
`process_sprite_needs_init` during catch-up, queuing it for after
the deferred root script. But for `consecutive_goto_frame_test`'s
nested-goto pattern (sprite frame DoAction calls
`_root.gotoAndStop(...)` from inside a sprite frame), the inner
goto's catch-up replay re-fires the sprite's frame DoAction even
though it already fired in the outer goto's replay. The
`g_sprite_init_filter_active` / `g_sprite_init_target_frame` flags
(lines 197–230) filter by `placed_at_frame` but don't track "this
sprite already fired its DoAction in an outer goto's replay."

### Cause 4 — Last-frame DoAction lost on forward goto

`goto_frame_test` does a forward `gotoAndPlay(7)`. The catch-up
replays frames 1..7 with `catch_up_mode=1`. The target frame 7 is
re-processed by the main loop with `g_tag_skip_mode=1` (per
`swf_core.c:181-192`'s deferred-script queue). But the recompiler
emits this gate on root frame DoActions
(`tagMain.c:17 if (!catch_up_mode || g_tag_skip_mode) actionQueueScript(...)`).

If frame 7's DoAction is the LAST frame and the frame func has the
shape `frame_N { ... actionQueueScript(...); tagFlushPendingEnterFrame; ... }`
without a `tagShowFrame` to anchor the SHOW_FRAME-time drain, the
queued script may be missed entirely. Or the recompiler emission
for the last frame uses a different gate than non-last frames.

### Cause 5 — Removed-zone depth arithmetic off-by-201 for some MCs

`goto_frame_test` mc1 expected `-16485`, mc2 expected `-16485`. We
return `-16284` for mc2. `-16485 - (-16284) = -201`. The formula
`-(swf_depth) - 1 - 16384` produces `-16485` for `swf_depth=100`.
We're computing `-16284` which works out to: `-(swf_depth) - 1 -
16284 + (-201)` — doesn't match a clean swf_depth.

Or: `-16284 = -(swf_depth) - 1 - 16384 + 201`. That puts swf_depth at
`-201 - 100 + 201 = -100` (negative). Or: we're using AS depth
instead of SWF depth: `mc2 AS depth = -16284`? Computing from
expected: `expected = -16485, swf_depth = 100, AS depth = -16284`.
So we're returning AS depth verbatim — i.e. **we're not applying the
removed-zone shift formula at all** for mc2 in this scenario,
returning the bare AS depth `-16284`.

mc1 returns empty — so for mc1, the lookup didn't even find a MC.
For mc2, the lookup found something but at the un-shifted depth.

## Phase 1 — Goto-induced RemoveObject2: clear name resolution

**Fix.** When `tagRemoveObject2` runs during catch-up and the
goto target frame doesn't re-place a same-named MC at the same
depth, mark the named MC for invalidation. Add a "pending invalidation
list" populated during catch-up replay and drained after the deferred
root script runs:

```c
// In tagRemoveObject2's catch_up_mode branch:
if (catch_up_mode) {
    if (display_list[depth].instance_name != NULL) {
        // Remember this name for post-catch-up invalidation;
        // if the catch-up replay later places the same name+depth,
        // remove from the list. Otherwise drain at finalize.
        ng_register_pending_catchup_invalidation(
            display_list[depth].instance_name, depth);
    }
    return;
}
```

The drain runs after the deferred-script queue empties and before
the next user script can read MC state. It mirrors the existing
`actionInvalidateMCAtASDepth` empty-slot path but extends it to
named MCs.

**Risk.** Medium. Need to confirm the invalidation doesn't
prematurely kill MCs that the goto replay later legitimately
re-places (mc_red removed at frame 5 then placed back at frame 6
during catch-up should NOT be invalidated).

## Phase 2 — Catch-up unload event dispatch

**Fix.** Extend Phase 1's pending list with metadata about what
unload events should fire (clip-event UNLOAD bits, AS-level
onUnload presence). After catch-up finalize, fire those events
synchronously — at the same point existing
`actionFirePendingUnloads` (`tag.c:2176`) drains the queue, but
specifically for catch-up-deferred entries.

Goto-induced unloads in Flash fire:

1. After the catch-up replay completes (all PlaceObject/RemoveObject
   tags processed for the goto).
2. Before the target frame's DoAction fires.

This is the ordering goto_frame_test expects:

```
PASSED: mc1._target == '/mc1'        ← mc1 still live during DoAction
                                        (because RemoveObject2 ran but
                                         unload hasn't fired yet)
_level0.mc1 unloaded                  ← unload AFTER DoAction
_level0.mc2 unloaded
PASSED: mc1.getDepth() == -16485      ← post-unload, in removed zone
```

The DoAction is what runs the assertions; mc1/mc2 are still live
when the assertions begin (so `mc1._target == '/mc1'` passes), then
unload fires, then post-unload assertions check `getDepth() == -16485`.

This ordering matches the existing `DEFERRED_CLIP_UNLOAD_PLAN.md`
proposal structurally but specifically for catch-up-deferred unloads.

## Phase 3 — Removed-zone depth arithmetic

**Fix.** The depth shift formula `-(swf_depth) - 1 - 16384` must
use the MC's PRE-shift SWF depth (i.e. the depth from the
just-removed PlaceObject2 entry), not the cached `mc->depth` (which
may already have been mutated by swapDepths or other side effects
before the unload).

Audit `actionFireOnUnload` (`action.c:18730`) — it computes
`shifted_depth = -(int)swf_depth - 1 - 16384`. The `swf_depth`
param comes from the call site in `ng_on_remove_object`
(`tag_stubs.c:781`), which passes the depth slot index — that IS
the SWF depth. So the formula should be correct...

The mc2 actual `-16284` decoded: maybe we're returning the
AS depth (`mc->depth = -16284`) instead of computing the shift.
Trace `mc2.getDepth()`'s code path:

```bash
grep -n "getDepth\b\|builtin_mc_getDepth\|mc.*getDepth" SWFModernRuntime/src/actionmodern/action.c
```

The getDepth handler likely returns `mc->depth + 16384` or similar
to convert from AS to SWF. If `mc->depth` is already in the removed
zone (`-16485`), but our impl never executed the depth shift for
mc2 (because Phase 2's unload firing was missing — see Phase 2),
then `mc->depth` is still `-16284 - 16384 = ?` and `getDepth()`
returns `-16284 + 0 = -16284`.

So Phase 3 may resolve automatically once Phase 2 lands: the unload
firing path includes the depth shift. If unload doesn't fire, the
shift never happens.

## Phase 4 — Sprite script double-fire during catch-up

**Fix.** Extend the existing `g_sprite_init_filter_active` flag set
to include "this sprite has already had its frame_N DoAction fired
during this catch-up cycle." Track per-MC-per-frame. When the
inner goto from a sprite frame triggers a nested catch-up, the
already-fired sprite frames should not re-fire.

Site: `tag.c:312` `process_sprite_needs_init` — add a guard:

```c
if (display_list[i].sprite_frame_already_fired_in_catchup) continue;
```

Set the flag in the existing dispatch site at line ~416/500, clear
between distinct goto operations (in `ng_executeGotoCatchUp` setup).

**Risk.** Medium. Adding state to MCs has wide blast radius;
required-pass guardrail covers `goto_rewind1/2/3`,
`execution_order1/2/3`, `goto_execution_order/2`,
`goto_both_ways1/2`, `loop_test*`.

## Phase 5 — Final-frame DoAction execution

**Fix.** Audit recompiler emission in `SWFRecomp/src/swf.cpp` for
the LAST frame's DoAction tag. The recompiler may emit
`actionQueueScript` for non-last frames (which drains at SHOW_FRAME)
but skip emission for last-frame DoActions placed AFTER the last
SHOW_FRAME tag (a SWF can have trailing DoAction tags after the
final ShowFrame).

Cross-reference with `misc-swfmill/tags_after_last_showframe`
(blocked test mentioned earlier): "DoInitAction order vs
post-ShowFrame DoAction order" — likely the same issue.

**Risk.** Low. Either the recompiler emits the call or it doesn't;
adding it is purely additive.

## Phase 6 — Sprite script ordering relative to deferred drain

**Fix.** When the deferred-script drain (`g_deferred_goto_queue`)
empties, ensure all queued sprite scripts (`AQ_KIND_SCRIPT`) drain
BEFORE the totals/printtotals call. Currently sprite scripts
queued during catch-up may drain after the user script returns
control to the runtime, which is after `printtotals()`.

Examine the drain order at `swf_core.c:1078+` (the
`while (g_deferred_goto_queue_count > 0 || g_deferred_goto_script)`
loop). It handles deferred root scripts but may not drain sprite
DoAction queue entries before letting control return.

**Risk.** Medium. Affects the tagShowFrame drain order which is
load-bearing across many tests.

## Verification battery

**Required-pass guardrail (all phases):**

- AVM1: `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `goto_frame`, `goto_frame2`, `goto_label`, `goto_methods`. All pass
  today; the catch-up fixes have heavy interaction risk.
- AVM1 unload: `unload`, `unloadmovie`, `unload_clip_event`,
  `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`. The Phase 2 fixes interact
  with these.
- Gnash misc-ming recently-fixed: `loop_test2/3/5/8/9`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `new_child_in_unload_test`,
  `event_handler_scope_test`, `action_execution_order_test8-v5/v6`.
  These all involve goto/catch-up interaction.
- Shumway: `duplicateMovieClip/dontremove`, `duplicateMovieClip`,
  `samedepth`, `name-coercion`.

**Target tests:**

- Phase 1: place_and_remove_object_insane_test recovers ~5 lines
  (15/22 → 20/22). goto_frame_test recovers mc1 access lines.
- Phase 2: goto_frame_test recovers `_level0.mc1 unloaded` and
  `_level0.mc2 unloaded` lines plus subsequent depth assertions.
- Phase 3: subsumed by Phase 2 (depth shift happens during unload
  firing).
- Phase 4: consecutive_goto_frame_test recovers 2-3 lines (no
  duplicate sprite traces).
- Phase 5: goto_frame_test recovers the `7+` line and subsequent
  assertions (5+ lines).
- Phase 6: consecutive_goto_frame_test recovers final ordering
  (sprite scripts before totals).

After all phases:
- goto_frame_test: 4/15 → potentially full PASS (small test).
- consecutive_goto_frame_test: 3/12 → potentially full PASS.
- place_and_remove_object_insane_test: 15/22 → potentially full PASS.

## Open questions

1. **Phase 5 vs `misc-swfmill/tags_after_last_showframe`.** Are
   both blocked on the same recompiler emission gap? If yes, fix
   once for both; if not, treat separately.
2. **Phase 4's "already-fired" tracking granularity.** Per-MC,
   per-frame, per-goto-operation — pick the smallest unit that
   prevents the regression. Likely per-MC-per-frame, reset at the
   start of each `ng_executeGotoCatchUp` call.
3. **Phase 1 vs `actionInvalidateMCAtASDepth` (the 2026-04-22 fix).**
   That fix targets the empty-slot RemoveObject2 path. Phase 1
   should integrate with it, not duplicate. Determine whether
   Phase 1 is a generalization of the existing fix or an orthogonal
   new path.
4. **Goto from within sprite DoAction's nested goto.** The
   consecutive_goto_frame_test pattern is sprite_frame_2 calls
   `_root.gotoAndStop(3)` during its execution. Does our
   `actionGotoCatchupActive` flag stack properly across nested
   gotos? Audit `actionGotoCatchupEnter`/`actionGotoCatchupLeave`
   pairing.

## Estimated session budget

- Phase 1: 2–3 hours (state design + integration with existing
  invalidation paths).
- Phase 2: 2–3 hours (likely overlaps DEFERRED_CLIP_UNLOAD_PLAN; can
  share design).
- Phase 3: 0–30 min (likely subsumed by Phase 2).
- Phase 4: 2 hours (per-MC tracking + battery).
- Phase 5: 1–2 hours (recompiler audit + last-frame emission fix).
- Phase 6: 2 hours (drain order audit; high battery risk).

Total: 9–12 hours. Recommended order: 1 → 5 → 4 → 2 → 3 → 6.
Phase 5 is independent and cheap; do it second to bank a quick win.

## Why this is the right shape

The three tests look unrelated at first glance (goto_frame_test
reads like a removal test, consecutive_goto_frame_test reads like a
sprite/scope test, place_and_remove_object_insane_test reads like a
placement test) but their failure patterns all trace to one
question: **after the goto catch-up replay finishes, is the runtime
state consistent with what the live frame expects to see?**

Today's catch-up suppresses certain actions (unload, sprite init,
display cleanup) to defer them until the deferred root script
drains. But the deferral plumbing has gaps:

- Some suppressed actions are never re-fired (Phase 2: unloads).
- Some are re-fired at the wrong time (Phase 6: sprite scripts
  after totals).
- Some leave name resolution in stale state (Phase 1: removed MCs
  still resolvable).
- The depth-shift bookkeeping skips when unload firing skips
  (Phase 3).
- Nested gotos confuse the catch-up replay's "already done" tracking
  (Phase 4).
- Forward gotos don't capture all the post-catch-up DoActions
  (Phase 5).

Each phase is a narrow extension to the existing deferral
infrastructure. None require redesigning the catch-up model.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Phase 2 here is structurally the same problem (deferred unload firing) but specifically for catch-up replay rather than RemoveObject2 in normal flow. Land the unload plan first; Phase 2 here may simplify or merge with it. |
| `MISC_MING_SWFC_PLAN.md` "consecutive_goto_frame_test, goto_frame_test, place_and_remove_object_insane_test" | This plan's three tests, previously listed as "adjacent goto+placement+removal sequencing; may overlap deferred-unload cluster but each has unique diff." Confirmed: shared catch-up hygiene root cause. |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | Independent. |
| `CLONESPRITE_DEPTH_BIAS_PLAN.md` | Independent. |
| Existing `actionInvalidateMCAtASDepth` (2026-04-22 fix) | Phase 1 generalizes this pattern. |
| Existing `g_defer_sprite_init` machinery (tag.c:157) | Phase 4 extends. |
| Existing `g_deferred_goto_queue` (swf_core.c:80) | Phase 6 audits the drain. |
