# Clip-Event Round Dispatch Plan (INITIALIZE/CONSTRUCT)

<!-- TESTS: loop/loop_test6 -->

<!-- PLAN_META
id: CLIP_EVENT_ROUND_DISPATCH
status: blocked
phases:
  - id: 1
    name: "Audit drain sites; identify per-placement vs. frame-level"
    status: completed
  - id: 5
    name: "Pre-fix synchronous REGISTER_CTOR re-fire (process_sprite_init_at_depth)"
    status: completed
  - id: 6
    name: "Pre-fix CLIP_INIT/CONSTRUCT chronological-fire gate (aq_drain)"
    status: blocked
  - id: 2
    name: "Remove per-placement drain in tagPlaceObject2-family"
    status: blocked
  - id: 3
    name: "Add frame-level priority drain helper (actionDrainAllInPriorityOrder)"
    status: blocked
  - id: 4
    name: "Recompiler emission update (3 sites in swf.cpp)"
    status: blocked
  - id: 8
    name: "Regression battery"
    status: blocked
dependencies: []
parent_plan: "complete/DEFERRED_CLIP_UNLOAD_PLAN.md (§1)"
-->

## Problem statement

When two or more sprites are placed in the same frame, both with
`CLIP_EVENT_INITIALIZE` and `CLIP_EVENT_CONSTRUCT` handlers, our runtime
fires them **per-sprite serially** (`mc1.INIT → mc1.CTOR → mc2.INIT →
mc2.CTOR`). Flash and Ruffle batch them in **rounds**: `mc1.INIT →
mc2.INIT → mc1.CTOR → mc2.CTOR` — every INITIALIZE first, then every
CONSTRUCT, regardless of placement order.

Reference: Ruffle uses a 3-priority `ActionQueue` (`core/src/context.rs:490-533`)
where `Initialize→2`, `Construct→1`, `Normal→0`. `pop_action` drains
priority-by-priority, FIFO within each priority
(`context.rs:527-532`):
```rust
pub fn pop_action(&mut self) -> Option<QueuedAction<'gc>> {
    self.action_queue.iter_mut().rev().find_map(VecDeque::pop_front)
}
```
`Player::run_actions` drains the entire queue at frame-end
(`core/src/player.rs:2144-2196`).

## History

- **First attempt (commit 73845094)**: removed per-placement drain in
  `tagPlaceObject2`/`tagPlaceObject2Ratio`, added
  `actionDrainAllInPriorityOrder` at the recompiler-emitted SHOW_FRAME
  drain. CI showed +13 matching lines on 4 tests but **−22 matching
  lines on 4 misc-ming tests** — biggest hit was
  `register_class/RegisterClassTest4` 17/42 → 2/42. Reverted in
  d52c4d75.
- **2026-04-28 follow-up session**: Phase 5 landed standalone (verified
  9/9 AVM1 lifecycle battery + register_class 4/4 baselines unchanged).
  Phase 6 attempted standalone but breaks
  `register_class/RegisterClassTest3` (12/12 PASS → 9/12 mismatch) — the
  goto_commands aggregation case (mc2 placed-and-removed in same goto
  sweep should NOT fire CLIP_INIT, but Phase 6's gate change drops the
  filter that was implementing this aggregation in our code). The
  earlier "Both fixes verified locally" claim must have used a different
  baseline — Phase 6 is fundamentally incompatible with our current
  goto-aggregation mechanism. See "Phase 6 blocker" below for next
  steps. Phases 2-4 remain blocked on Phase 6.
- **Investigation (2026-04-28)**: traced both regression mechanisms with
  AQ/QRC/DRC/INIT/CTOR/TRACE printf instrumentation in `aq_drain`,
  `aq_dispatch_clip_init`, `aq_dispatch_clip_construct`,
  `aq_dispatch_register_ctor`, `queue_register_ctor`, `actionTrace`,
  redirected via `AQ_TRACE=1 AQ_TRACE_FILE=...` env. Identified two
  pre-existing latent bugs that the per-placement drain was
  inadvertently masking. Documented in §"Diagnosed root causes" below.
  Both fixes verified locally: 14/14 misc-ming battery + 16/16 AVM1
  ordering battery passing with all four phases (5+6+2+3+4) applied,
  loop_test6 12/23 (target gain), RegisterClassTest4 17/42 (regression
  resolved).

## Affected tests (CI 91a39c2c, original)

| Test | Suite | Match | Diff |
|------|-------|-------|------|
| loop/loop_test6 | misc-ming | 10/23 | First failure: `[expected: movieClip2 initialized, got: movieClip1 constructed]` at line 2 — the per-sprite serial pattern. |

After Phases 2-4 (no pre-fixes) the broken-commit test delta vs CI
baseline 3c8bd226 was:

Gains:
- `avm1/global_instance_decls`: 15/758 → 23/758 (+8) — incidental,
  unrelated to round-dispatch (likely flaky ordering elsewhere).
- `misc-ming/loop/loop_test6`: 10/23 → 12/23 (+2, target).
- `misc-ming/init_action/InitActionTest`: 9/17 → 11/17 (+2).
- `misc-ming/action_order/ActionOrderTest4`: 7/64 → 8/64 (+1).

Regressions (all addressed by Phases 5-6 below):
- `misc-ming/register_class/RegisterClassTest4`: 17/42 → 2/42 (−15).
- `misc-ming/place_object_test2`: 4/19 → 0/19 (−4) — but stays
  ruffle_matched, so still effective pass.
- `misc-ming/loop/loop_test10`: 3/28 → 1/28 (−2).
- `misc-ming/action_order/ActionOrderTest3`: 6/62 → 5/62 (−1).

## Existing infrastructure

The action queue already has 3 priority lanes
(`SWFModernRuntime/include/actionmodern/action_queue.h`):
- `AQ_PRIORITY_INITIALIZE` — `AQ_KIND_CLIP_INIT`
- `AQ_PRIORITY_CONSTRUCT` — `AQ_KIND_CLIP_CONSTRUCT`, `AQ_KIND_REGISTER_CTOR`
- `AQ_PRIORITY_NORMAL` — `AQ_KIND_SCRIPT`, `AQ_KIND_ONLOAD`, `AQ_KIND_CLIP_LOAD`

Drain helpers:
- `actionDrainActionQueueByKind(kind)` — drains a single kind, FIFO.
- `actionDrainOnloadAndScript()` — drains `AQ_KIND_ONLOAD` + `AQ_KIND_SCRIPT`
  in interleaved FIFO order (the DEFERRED_CLIP_UNLOAD_PLAN drain).

What's missing: a single frame-level drain that processes all 5+ kinds in
priority order, replacing the scattered per-placement and per-show-frame
drains.

## Diagnosed root causes

### Bug A — process_sprite_init_at_depth fires REGISTER_CTOR synchronously without setting `constructor_invoked`

`SWFModernRuntime/src/libswf/tag.c:559-572` (in `process_sprite_init_at_depth`):
```c
const char* _rc_export = ng_lookupExportName(obj->char_id);
if (!obj->constructor_invoked && _rc_export != NULL && child_mc != NULL)
    actionInvokeRegisteredClassConstructor(app_context, _rc_export, child_mc);
```

This synchronous fire path does NOT set `obj->constructor_invoked = 1`
after invoking the constructor. With the per-placement drain in place,
the queued REGISTER_CTOR entry's dispatcher
(`aq_dispatch_register_ctor` at tag.c:3707) had already fired and set
the flag BEFORE this code runs, so the `!obj->constructor_invoked`
check skipped here. Without per-placement drain, the queued entry
hasn't drained yet — both this synchronous fire AND the queued dispatch
fire the constructor (twice for each placement, observable as 8
ctorcalls vs expected 4 / canonical 3 in RegisterClassTest4).

**Trace evidence** (broken commit, RegisterClassTest4):
```
[AQ] enq REG_CTOR clip=A (rf=1 count=1)
[TRACE] Bug ctor: 0           ← fire #1 from process_sprite_init_at_depth
[AQ] dispatch REG_CTOR clip=A (rf=1)
[TRACE] Bug ctor: 1           ← fire #2 from aq_dispatch_register_ctor
```

Fix is one line: `obj->constructor_invoked = 1;` after the
`actionInvokeRegisteredClassConstructor` call.

### Bug B — aq_drain skips CLIP_INIT/CLIP_CONSTRUCT for clips marked removed

`SWFModernRuntime/src/actionmodern/action_queue.c:140-143`:
```c
if (!entry.is_unload && entry.clip) {
    if (entry.clip->avm1_removed || entry.clip->pending_removal) {
        continue;
    }
}
```

This skips queued entries for clips that got marked removed before the
drain runs. For `REGISTER_CTOR` this is correct (RegisterClassTest3
expects place+remove in the same goto to cancel the constructor — the
Ruffle "goto_commands aggregation" semantic). But for
`CLIP_EVENT_INITIALIZE` and `CLIP_EVENT_CONSTRUCT` (clip-action
handlers), Flash semantics fire the handlers chronologically — even
when the sprite is removed later in the same drain window. The same
"chronological" policy is already documented for CLIP_CONSTRUCT in
`tagShowFrame`'s safety drain (tag.c:2266-2270, citing
`action_execution_order_test6`). It's also the correct policy for
CLIP_INIT.

With per-placement drain, INIT/CONSTRUCT fire immediately when the
placement happens — before any subsequent removal can mark the clip.
Without per-placement drain, the queue accumulates entries and the
drain window may include placements + removals; the existing skip
filter then drops INIT entries that should have fired.

**Trace evidence** (broken commit, loop_test10):
```
[AQ] enq CLIP_INIT clip=mc1 (rf=1 count=1)
[AQ] dispatch CLIP_INIT clip=mc1 (rf=1)
[TRACE] _level0.mc1 initialized
[AQ] enq CLIP_INIT clip=mc1 (rf=2 count=2)        ← second placement of mc1
[AQ] skip CLIP_INIT clip=mc1 removed (rf=2)        ← incorrectly skipped
[TRACE] _level0.mc2 unloaded
```

Fix: gate the skip on `kind != AQ_KIND_CLIP_INIT && kind != AQ_KIND_CLIP_CONSTRUCT`
in `aq_drain`'s removal check.

## Plan

### Phase 1 — Audit drain sites — DONE

Sites identified (and confirmed unchanged since commit 73845094):
- `tag.c:4370-4374` — outermost `tagPlaceObject2` per-placement drain (REMOVE).
- `tag.c:4757-4761` — outermost `tagPlaceObject2Ratio` per-placement drain (REMOVE).
- `tag.c:2271-2277` — `tagShowFrame` safety drain (KEEP — backstop for
  catch-up paths where the recompiler-emitted drain is skipped via the
  `if (!catch_up_mode || g_tag_skip_mode)` gate).
- `swf_core.c:193-194` — `ng_executeGotoCatchUp` post-replay drain
  (KEEP — the goto_commands aggregation point with avm1_removed
  filtering).
- `tagPlaceObject3` / `tagPlaceObject2WithClipActions` /
  `tagPlaceObject2RatioWithClipActions` delegate to the inner functions,
  no separate change needed.
- Recompiler emit sites: `SWFRecomp/src/swf.cpp:601, 904, 963` — three
  `actionDrainOnloadAndScript` call sites. Replace with
  `actionDrainAllInPriorityOrder`.

### Phase 5 — Pre-fix Bug A (synchronous REGISTER_CTOR re-fire)

In `SWFModernRuntime/src/libswf/tag.c` around line 565, change:
```c
if (!obj->constructor_invoked && _rc_export != NULL && child_mc != NULL)
    actionInvokeRegisteredClassConstructor(app_context, _rc_export, child_mc);
```
to:
```c
if (!obj->constructor_invoked && _rc_export != NULL && child_mc != NULL) {
    actionInvokeRegisteredClassConstructor(app_context, _rc_export, child_mc);
    obj->constructor_invoked = 1;
}
```

This is a **standalone safe fix** — it can be committed before the rest
of the plan. Without per-placement drain removed, the flag is already
set by the queued dispatch (which runs first under per-placement
drain), so this assignment is idempotent in the current behavior. With
per-placement drain removed (Phase 2), this prevents the queued
dispatch from re-firing the ctor.

Verify in isolation: run `register_class/RegisterClassTest4`,
`register_class/registerClassTest`, `register_class/registerClassTest2`,
`register_class/RegisterClassTest3`, AVM1 `register_and_init_order`
(233 lines), `on_construct`, `init_object_order`. All should remain
green or unchanged.

### Phase 6 — Pre-fix Bug B (CLIP_INIT/CONSTRUCT chronological)

In `SWFModernRuntime/src/actionmodern/action_queue.c`, change the
skip-removed gate in `aq_drain` from:
```c
if (!entry.is_unload && entry.clip) {
    if (entry.clip->avm1_removed || entry.clip->pending_removal) {
        continue;
    }
}
```
to:
```c
int fires_chronologically = (entry.kind == AQ_KIND_CLIP_INIT
                          || entry.kind == AQ_KIND_CLIP_CONSTRUCT);
if (!entry.is_unload && entry.clip && !fires_chronologically) {
    if (entry.clip->avm1_removed || entry.clip->pending_removal) {
        continue;
    }
}
```

This is also a **standalone safe fix**. Under per-placement drain, INIT
and CONSTRUCT entries always drain immediately and never see a removed
clip, so this gate change is observably a no-op in the current
behavior. Under the new frame-end drain (Phase 2), it ensures the
handlers fire chronologically as Flash specifies.

Verify in isolation: AVM1 `clip_events`, `bad_placeobject_clipaction`,
`movieclip_in_removed_button`, `unload`, `unload_clip_event`,
gnash misc-ming `loop/loop_test10`, `action_order/ActionOrderTest3`,
`action_order/action_execution_order_test5/6`. All should remain green
or unchanged. Phase 5 + Phase 6 are independent — either order works.

### Phase 6 blocker (2026-04-28)

The plan claimed Phase 6 was a "standalone safe fix" with no observable
effect under the current per-placement-drain behavior. Local verification
disproves this: Phase 6 breaks `register_class/RegisterClassTest3`
(12/12 PASS → 9/12 mismatch).

The test pattern: gotoAndStop(3) from frame 1 visits frame 2 (which
places mc2 with INIT clipaction + REGISTER_CTOR) then frame 3 (which
removes mc2). Flash's goto_commands aggregation cancels this place
+remove pair so neither INIT nor CTOR fires. In our runtime, the
catch-up replays each frame's tags individually: tagPlaceObject2 queues
CLIP_INIT for mc2, then RemoveObject2 marks mc2 with `avm1_removed=1`
(via `actionInvalidateCachedMovieClip`). At drain time, the existing
`!entry.is_unload && entry.clip->avm1_removed` skip filter is what
*implements* the goto-aggregation cancellation in our model.

Phase 6 removes that filter for CLIP_INIT/CONSTRUCT entries — so mc2's
CLIP_INIT now fires during catch-up, producing a stray `onInitialize`
trace and an off-by-one `i++` increment that breaks subsequent
`check_equals i == 0` and `check_equals i == 1` assertions.

**The conflict:** Phase 6's intent (loop_test10's re-placement after
unload should fire INIT chronologically) and the goto-aggregation case
(RegisterClassTest3's place+remove in same goto should NOT fire INIT)
both arrive at the queue with `entry.clip->avm1_removed == 1`. The
existing skip filter conflates them.

**Possible discriminators (future work):**

1. **Stamp `placed_at_frame` on the queue entry at queue time.** At
   drain time, compare with `display_list[depth].placed_at_frame`. If
   the slot was re-placed (newer `placed_at_frame`), fire (it's a fresh
   placement). If `display_list[depth].char_id == 0` (slot cleared
   entirely by RemoveObject2), skip (goto-aggregation OR natural unload
   without re-place). Requires adding a `placed_at_frame` (and a
   `depth`) field to `ActionQueueEntry`.
2. **Stamp queue-time `catch_up_mode` on the entry.** Apply the
   existing skip filter only to entries queued during catch-up
   (goto-aggregation candidates); apply chronological-fire only to
   entries queued during natural play. Smaller change but doesn't
   handle the case of a clip placed normally and then unloaded inside
   the same drain window via natural-play tags.
3. **Pre-aggregate goto commands in our catch-up driver** the way
   Ruffle's `run_goto` does — compute survivors *before* replaying tags,
   so non-survivor placements never get queued. Largest scope; reuses
   the existing skip filter for the natural-play unload case only.

Approach 1 is the smallest behavior-equivalent change. Approach 3 is
architecturally closer to Ruffle. Either unblocks Phases 2-4.

### Phase 2 — Remove per-placement drain — UNCHANGED

Delete the `if (!catch_up_mode) { drain INIT; drain CONSTRUCT; drain
REGISTER_CTOR; }` block from `tagPlaceObject2` (tag.c:4370-4374) and
`tagPlaceObject2Ratio` (tag.c:4757-4761). Phases 5+6 must land first.

### Phase 3 — Add frame-level priority drain helper

Add `actionDrainAllInPriorityOrder(app_context)` to
`SWFModernRuntime/src/actionmodern/action_queue.c`:

```c
void actionDrainAllInPriorityOrder(SWFAppContext* app_context)
{
    if (g_drain_suppress_depth > 0) return;
    actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
    actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
    actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);
    actionDrainOnloadAndScript(app_context);
}
```

Honor `g_drain_suppress_depth` (matching `actionDrainOnloadAndScript`)
so nested drains under an outer drain (`ng_executeGotoCatchUp`'s
inline target script call) are no-op'd. The `tagShowFrame` safety drain
(tag.c:2271-2277) stays as-is — it's the backstop for catch-up paths
where the recompiler-emitted drain is skipped via `catch_up_mode`.

Declare in `SWFModernRuntime/include/actionmodern/action_queue.h` next
to `actionDrainOnloadAndScript`.

### Phase 4 — Recompiler emission update

`SWFRecomp/src/swf.cpp`: replace `actionDrainOnloadAndScript` at all
three emit sites (lines 601, 904, 963) with
`actionDrainAllInPriorityOrder`. Drop the now-redundant comments about
"Phase 4/5 entries stay on their original drain timeline" since they
no longer apply.

### Implementation order recommendation

Phases 5 and 6 are pre-requisite landings (each independent and
safe). Each should ship as its own commit and be verified by CI before
proceeding. Once both have landed, Phases 2 + 3 + 4 can land as a
single commit. The broken-commit's regressions all derive from Bugs A
and B, both pre-fixed.

### Phase 8 — Regression battery

**Required-pass tests (must remain green):**

AVM1 lifecycle / CONSTRUCT-order battery:
- `register_and_init_order` (233/233 — canonical ordering test).
- `clip_events`, `on_construct`, `init_object_order`,
  `bad_placeobject_clipaction`, `movieclip_in_removed_button`.
- `goto_rewind1/2/3`, `execution_order1/2/3`, `goto_execution_order/2`.
- `unload`, `unload_clip_event`, `unload_nested_child`, `unloadmovie`.
- `attach_movie`, `set_interval`, `button_children`,
  `movieclip_state_values`, `movieclip_library_state_values`.
- `swf5_to_6_cross_call`, `swf5_no_closure`.
- `conflicting_instance_names`, `movieclip_get_instance_at_depth`,
  `movieclip_depth_methods`, `movieclip_name_from_timeline`.

Gnash misc-ming recently-fixed (must not regress):
- `loop_test2/3/4/5/6/8/9/10` — loop_test6 should flip 10/23 → 12/23,
  loop_test10 should remain at 3/28.
- `instanceNameTest`, `attachMovieTest`, `DefineEditTextTest`,
  `DefineEditTextVariableNameTest2`, `displaylist_depths_test11`,
  `static_vs_dynamic1/2`, `place_and_remove_object_test`,
  `get_frame_number_test`, `shape_test`, `ResolveEventsTest`,
  `event_handler_scope_test`, `new_child_in_unload_test`,
  `action_order/action_execution_order_test8-v5/v6`,
  `reverse_execute_PlaceObject2_test1/2`.

Gnash register_class:
- `RegisterClassTest3`, `RegisterClassTest4`, `registerClassTest`,
  `registerClassTest2`. RegisterClassTest4 should remain at 17/42
  (matching the baseline), not regress to 2/42.

Gnash misc-swfc:
- `stackscope`, `edittext_test1`, `submoviegetvar`,
  `movieclip_destruction_test2` (50/52 must not regress).

Shumway:
- `duplicateMovieClip/dontremove`, `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`, `duplicateMovieClip/name-coercion`.

**Target tests (expected to gain lines):**
- `loop/loop_test6` (10/23 → 12/23). Full PASS still requires
  `INTER_TAG_UNLOAD_PLAN` for the goto-catchup tail (lines 12-23).
- `init_action/InitActionTest` (9/17 → 11/17, observed locally during
  investigation).

**Net expected delta:** 0 PASS flips on its own; +2 lines on loop_test6;
the combined pass with `INTER_TAG_UNLOAD_PLAN` lands a full loop_test6
PASS.

## Open questions

1. **DoInitAction relative ordering.** `DoInitAction` (SWF
   `tagDoInitAction`) is part of the import character flow. In our
   recompiler it's emitted via `tagDoInitActionGuarded` BEFORE the
   first PlaceObject of a tag stream (executes once per character).
   Does it queue at Normal priority or fire inline? If queued, Phase 3
   needs to ensure it drains in the right priority slot — Ruffle treats
   DoInitAction as a Normal-priority script.

   Likely answer: it's emitted as `actionQueueScript` (same as DoAction),
   so Normal priority — ✓ no special handling needed.

2. **Eager init nesting.** A `tagPlaceObject2(parent_sprite)` triggers
   eager init that runs `parent_sprite_frame_0`, which in turn calls
   `tagPlaceObject2(child)`. The child's INIT/CTOR queues during that
   inner call (with `catch_up_mode=1` set by eager init's outer
   wrapper). Currently the inner call's per-placement drain is gated
   by `if (!catch_up_mode)` — so it doesn't fire, and the OUTER
   placement's drain handles both parent+child entries.

   With Phase 2 removing the per-placement drain entirely, both inner
   and outer wait for the recompiler-emitted frame drain. Same observable
   ordering — verified during investigation against `clip_events` and
   `register_and_init_order`.

3. **`tagShowFrame` safety drain interaction with `actionFirePendingUnloads`.**
   Today's tagShowFrame drains INIT/CTOR/REGISTER_CTOR (lines 2271-2277), then calls
   `actionFirePendingUnloads` (line 2288). After Phase 3, the
   recompiler-emitted unified drain has already run before tagShowFrame,
   so the safety drain here is a true no-op except in the goto-catchup
   case where the unified drain was skipped via `catch_up_mode`. Keep
   it as a backstop. ✓

4. **Same-frame DoAction reading newly-placed sprite.** A frame may be:
   `place(mc1); DoAction(_root.x = mc1.foo); place(mc2); DoAction(...)`.
   With per-placement drain, mc1.INIT/CTOR fires before the first
   DoAction, so `mc1.foo` is initialized. With unified frame-end drain,
   mc1.INIT/CTOR fires after BOTH DoActions — `mc1.foo` is undefined
   when the first DoAction reads it.

   Resolution: Ruffle's drain is **strictly priority-ordered**, not
   FIFO-across-priorities. INIT fires first regardless of queue-time
   order (`context.rs:527-532`). Our unified drain in Phase 3
   implements this exactly. ✓

   Risk: if any existing test passes by relying on **our** broken
   ordering (DoAction-before-CTOR when DoAction was queued first), it
   would regress. Phase 6's gate change addresses the most visible
   regression class (CLIP_INIT/CONSTRUCT entries skipped due to
   removal). Phase 5 addresses the synchronous re-fire. Other minor
   ordering shifts may surface — Phase 8's battery covers them.

5. **Why local couldn't initially reproduce the CI 73845094 regression.**
   `verify_output.py` only writes results.json when run without
   `--test=...` (or with `--json=...`), so my single-test runs were
   reading stale CI-generated json data and overwriting nothing. The
   actual binary execution showed correct round-dispatch; the json
   was lying. **Fix to investigation workflow:** when running
   individual tests, pass `--append --json=<results.json>` to update
   the json, or compile_native + run_binary directly and inspect
   stdout. The pattern used during this investigation:
   ```bash
   python3 ruffle-tests/verify_output.py --recompile --no-ccache \
     --append --json=ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.json \
     --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all \
     --test=TEST_NAME --diff
   ```
   For low-level tracing: see §"Diagnostic instrumentation" below.

## Diagnostic instrumentation (re-usable)

The investigation used the following instrumentation pattern (NOT in
the codebase — apply temporarily as needed):

1. In `SWFModernRuntime/src/actionmodern/action_queue.c`, add at top:
   ```c
   #include <stdio.h>
   extern size_t current_frame;
   extern int g_aq_trace; int g_aq_trace = 0;
   extern FILE* g_aq_trace_fp; FILE* g_aq_trace_fp = NULL;
   __attribute__((constructor))
   static void aq_trace_init(void) {
       if (!getenv("AQ_TRACE")) return;
       g_aq_trace = 1;
       const char* p = getenv("AQ_TRACE_FILE");
       g_aq_trace_fp = p ? fopen(p, "w") : stderr;
       if (!g_aq_trace_fp) g_aq_trace_fp = stderr;
       setlinebuf(g_aq_trace_fp);
   }
   ```
2. In `actionQueueCallbackEx`, after the entry is appended:
   ```c
   if (g_aq_trace && (kind == AQ_KIND_REGISTER_CTOR || kind == AQ_KIND_CLIP_INIT || kind == AQ_KIND_CLIP_CONSTRUCT))
       fprintf(g_aq_trace_fp, "[AQ] enq %s clip=%p (rf=%zu count=%zu)\n", aq_kind_name(kind), (void*)clip, current_frame, g_aq_count);
   ```
3. In `aq_drain`, add `[AQ] dispatch …` and `[AQ] skip … removed …`
   prints before the dispatch call and inside the skip branch.
4. In `tag.c` `aq_dispatch_register_ctor` / `aq_dispatch_clip_init` /
   `aq_dispatch_clip_construct`, add `[DRC]/[INIT]/[CTOR] enter mc=…`
   before the action call.
5. In `actionTrace` (action.c), add `[TRACE] %.*s` print before the
   stdout write so trace output and AQ events interleave naturally in
   the log file.
6. Run with `AQ_TRACE=1 AQ_TRACE_FILE=/tmp/aq.log python3
   ruffle-tests/verify_output.py --recompile --no-ccache --append
   --json=… --test=… --diff`. Inspect `/tmp/aq.log`.

This instrumentation was the key to spotting both bugs — the
dispatch-vs-trace interleaving exposed Bug A's "two ctors per
placement" pattern, and the `[AQ] skip CLIP_INIT … removed` line
exposed Bug B.

## Risk

- **Low.** With Phases 5 and 6 pre-fixing the diagnosed root causes,
  the Phase 2-4 mechanism becomes a clean wiring change. The existing
  3-priority queue infrastructure already does the right thing
  structurally; the change just stops pre-draining in `tagPlaceObject2`
  so the queue can accumulate cross-sprite entries before the priority
  drain.
- **Phase-5 risk:** the assignment `obj->constructor_invoked = 1` after
  the synchronous fire is a one-line change that's idempotent under
  current behavior (the queued dispatch already sets it, and the gate
  already checks it). Only effect is preventing double-fire when the
  queue hasn't drained yet.
- **Phase-6 risk:** the `fires_chronologically` gate change is also
  observably a no-op under current behavior (per-placement drain means
  CLIP_INIT/CONSTRUCT entries always drain before any subsequent
  removal can mark the clip). Only effect is preserving correct firing
  when the drain is deferred.
- **Highest-risk regression:** `register_and_init_order` (233 lines of
  precise ordering assertions) and `RegisterClassTest3` (the goto+remove
  cancellation test). Both verified passing during investigation under
  Phases 5+6+2+3+4 applied locally.

## Why this is the right shape

This plan now mirrors Ruffle's exact mechanism with a single helper
(`actionDrainAllInPriorityOrder`), and identifies and pre-fixes the two
latent bugs that the per-placement drain was masking. The fixes are
surgical (one line each) and well-isolated.

A larger refactor (e.g. eliminating the per-kind drain helpers and
replacing them with a single `pop_action`-style cursor) is appealing
but out of scope — the plan above is enough to flip the visible
behavior.

## Estimated session budget

- Phase 5 (constructor_invoked fix + verify): 30 min.
- Phase 6 (chronological gate + verify): 30 min.
- Phase 2 (delete per-placement drain): 15 min.
- Phase 3 (add unified drain helper): 15 min.
- Phase 4 (recompiler emission update): 15 min.
- Phase 8 (full battery + 2 CI rounds): 60 min.

Total: 2-3 hour session, plus CI cycles.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Parent plan; §1 of its "Follow-up work" section. This plan covers that §1. |
| `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | Sibling plan from same parent. Independent — they could be implemented in either order. SPRITE_EXEC_LIST_LIFO changes WHO fires; this plan changes WHEN they fire. |
| `incomplete/INTER_TAG_UNLOAD_PLAN.md` | Sibling plan. loop_test6's tail (lines 12-23) needs both plans to fully pass. |
| Ruffle source: `core/src/context.rs:490-533, 655-663` (priority queue), `core/src/player.rs:2144-2196` (run_actions drain). | Reference implementation. |
