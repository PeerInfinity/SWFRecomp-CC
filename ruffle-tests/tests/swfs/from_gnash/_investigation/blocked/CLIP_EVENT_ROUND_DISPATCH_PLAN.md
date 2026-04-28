# Clip-Event Round Dispatch Plan (INITIALIZE/CONSTRUCT)

<!-- TESTS: loop/loop_test6 -->

<!-- PLAN_META
id: CLIP_EVENT_ROUND_DISPATCH
status: blocked
phases:
  - id: 1
    name: "Audit drain sites; identify per-placement vs. frame-level"
    status: completed
  - id: 2
    name: "Remove per-placement drain in tagPlaceObject2-family"
    status: completed
  - id: 3
    name: "Move INIT/CONSTRUCT/REGISTER_CTOR drain to frame-level, before DoAction drain"
    status: completed
  - id: 4
    name: "Recompiler emission update"
    status: completed
  - id: 5
    name: "Regression battery"
    status: blocked
dependencies: []
parent_plan: "complete/DEFERRED_CLIP_UNLOAD_PLAN.md (§1)"
-->

## Blocker (2026-04-28, attempt reverted at d52c4d75)

The straightforward Option A implementation (commit 73845094) was
implemented in full and pushed to CI; per-suite diff vs CI baseline
3c8bd226 → 73845094 showed +13 matching lines on 4 tests but **−22
matching lines on 4 misc-ming tests**, the largest being
`register_class/RegisterClassTest4` 17/42 → 2/42 (-15 lines). Net
delta: +9 mismatched lines overall (avm1 -8 / misc-ming +17). Reverted
in d52c4d75.

### Test impact summary (CI 3c8bd226 → 73845094)

Gains:
- `avm1/global_instance_decls`: 15/758 → 23/758 (+8)
- `misc-ming/loop/loop_test6`: 10/23 → 12/23 (+2, target test)
- `misc-ming/init_action/InitActionTest`: 9/17 → 11/17 (+2)
- `misc-ming/action_order/ActionOrderTest4`: 7/64 → 8/64 (+1)

Regressions:
- `misc-ming/register_class/RegisterClassTest4`: 17/42 → 2/42 (**-15**)
- `misc-ming/place_object_test2`: 4/19 → 0/19 (-4)
- `misc-ming/loop/loop_test10`: 3/28 → 1/28 (-2)
- `misc-ming/action_order/ActionOrderTest3`: 6/62 → 5/62 (-1)

### Root cause of regressions

The plan moved `REGISTER_CTOR` drain from per-placement (synchronous
inside `tagPlaceObject2` at sprite-advance time) to frame-end (in the
recompiler-emitted `actionDrainAllInPriorityOrder` of the next root
frame). `register_class/RegisterClassTest4` (and similar tests with
sprites that loop and re-place registered classes) is sensitive to
this timing shift:

- The test has a 2-frame inner sprite `mc3` that places mc1 (registered
  as `Bug`) at its frame 2, with the root timeline doing
  `gotoAndPlay(1)` 5 times. Expected `_global.ctorcalls == 3` —
  Flash's "survives_rewind" / preserve-across-loop semantics mean only
  3 of the 5+ loop iterations re-place mc1 (and re-fire `Bug ctor`).
- Pre-fix: `Bug ctor: N` fires synchronously inside
  `advance_sprite_frames` → `mc3.frame_1` → `tagPlaceObject2(mc1)`.
- Post-fix: `Bug ctor: N` queued, drains at next funcs[i] call's
  `actionDrainAllInPriorityOrder`. **But on subsequent iterations the
  queue accumulates 2+ REGISTER_CTOR entries between drains** (one
  from this tick's advance, one from somewhere else — investigation
  incomplete) → ctor fires too many times, reaching 8 total instead
  of 3.

The simple gate `actionGotoCatchupActive()` added during investigation
did NOT fix this (the regression happens in the non-catchup path —
gotoAndPlay-from-script triggers the older inline catchup loop in
`swf_core.c:1133-1202` which does its own `funcs[target]` call without
drain-suppress).

### Tension this exposes

- `loop_test6` (target) needs **CLIP_INIT round dispatch BEFORE DoAction
  scripts** in the same frame.
- `RegisterClassTest4` (regression) needs **REGISTER_CTOR firing INSIDE
  `advance_sprite_frames` per-placement** so subsequent ticks see the
  correct constructed state without the second-tick drain re-firing
  pending entries.

These two requirements are not satisfied by a single drain location.
A working fix likely needs:
1. Keep round dispatch for **CLIP_INIT / CLIP_CONSTRUCT** at frame-end
   (these are clip-event handlers fired at placement, FIFO across
   placements).
2. Restore per-placement drain for **REGISTER_CTOR** (registered-class
   constructor, fires inside `tagPlaceObject2`'s sprite-advance
   path, synchronous).

i.e. split AQ_KIND_CLIP_INIT/CONSTRUCT (frame-level) from
AQ_KIND_REGISTER_CTOR (per-placement). The plan's current design treats
all three uniformly via priority order, which doesn't match the
existing code's behavior for REGISTER_CTOR.

### Suggested next steps

- Revisit Phase 2: keep per-placement drain for REGISTER_CTOR only
  (drain `AQ_KIND_REGISTER_CTOR` inside `tagPlaceObject2` /
  `tagPlaceObject2Ratio` after queueing CLIP_INIT/CLIP_CONSTRUCT but
  BEFORE returning).
- Phase 3: `actionDrainAllInPriorityOrder` drains only CLIP_INIT and
  CLIP_CONSTRUCT (plus ONLOAD+SCRIPT), not REGISTER_CTOR.
- Re-run regression battery focused on RegisterClassTest3 / 4 / 5 /
  registerclassTest, place_object_test2, loop_test10, and
  ActionOrderTest3.

Alternative: investigate the "queue accumulates 2+ REGISTER_CTOR
entries between drains" specifically — if that's caused by an
unintended re-queue (e.g. a placement tag firing twice during goto
catch-up), fixing the root cause would let the priority-drain design
work as originally specified.

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

## Affected tests (CI 91a39c2c)

| Test | Suite | Match | Diff |
|------|-------|-------|------|
| loop/loop_test6 | misc-ming | 10/23 | First failure: `[expected: movieClip2 initialized, got: movieClip1 constructed]` at line 2 — the per-sprite serial pattern. |

The other 6 still-failing tests in DEFERRED_CLIP_UNLOAD_PLAN's §1/§3 are
addressed elsewhere — round dispatch alone fixes the head of loop_test6,
but loop_test6 also depends on `INTER_TAG_UNLOAD_PLAN` (TBD) for the goto
catch-up portion (lines 12-23). So this plan flips loop_test6 from 10/23
to ~14/23 (the head 4 lines) — not a full pass, but a verifiable wedge.

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

## Root cause

`tagPlaceObject2WithClipActions` (and siblings `tagPlaceObject2`,
`tagPlaceObject2Ratio`, `tagPlaceObject3`) ends with a per-call drain
(`SWFModernRuntime/src/libswf/tag.c:4370-4374`):
```c
if (!catch_up_mode) {
    actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_INIT);
    actionDrainActionQueueByKind(app_context, AQ_KIND_CLIP_CONSTRUCT);
    actionDrainActionQueueByKind(app_context, AQ_KIND_REGISTER_CTOR);
}
```

Each top-level `tagPlaceObject2*` call fires this drain. With two
same-frame placements (`PlaceObject2(mc1); PlaceObject2(mc2)`), the
drain runs twice — once per placement — locking in the serial order.

## Required ordering at the frame boundary

For loop_test6 frame 1:
```
Tag stream:    actionQueueScript(s3..s6); place(mc1); place(mc2); flush_ef; drainOnloadAndScript; ShowFrame
Expected drain order:
    1. CLIP_INIT       (FIFO)  → mc1.INIT, mc2.INIT
    2. CLIP_CONSTRUCT  (FIFO)  → mc1.CTOR, mc2.CTOR
    3. REGISTER_CTOR   (FIFO)  → (none here, but sequenced after CTOR per existing semantics)
    4. SCRIPT/ONLOAD   (FIFO)  → check_equals(...) traces
```

Currently we get:
```
    1. mc1.INIT, mc1.CTOR    (per-placement drain inside tagPlaceObject2(mc1))
    2. mc2.INIT, mc2.CTOR    (per-placement drain inside tagPlaceObject2(mc2))
    3. flush_ef + drainOnloadAndScript → check_equals
    4. ShowFrame safety drain (no-op — queue empty)
```

The serial INIT/CTOR pairing is the only divergence — DoAction position
is correct.

## Plan

### Phase 1 — Audit drain sites

Map all `actionDrainActionQueueByKind(*, AQ_KIND_CLIP_INIT|CLIP_CONSTRUCT|REGISTER_CTOR)`
call sites and classify each as:
- **Per-placement** (drain after each top-level placement) — REMOVE in Phase 2.
- **Frame-level** (drain once per frame at ShowFrame or recompiler emit) —
  KEEP, possibly relocate.
- **Catch-up specific** (drain inside `ng_executeGotoCatchUp` /
  `goto_commands`) — KEEP, these have their own ordering invariants.

Known sites (from grep):
- `tag.c:4370-4374` — outermost-tagPlaceObject2 drain (per-placement, REMOVE).
- `tag.c:4759-4761` — `tagPlaceObject3` analogous drain (REMOVE).
- `tag.c:4372` — same as 4370, in `tagPlaceObject2WithClipActions` (REMOVE).
- `tag.c:2271-2277` — `tagShowFrame` safety drain (KEEP, but elevate from
  "safety" to "primary" — see Phase 3).
- `ng_executeGotoCatchUp` post-replay drain — KEEP (catch-up semantics).

### Phase 2 — Remove per-placement drain

Delete the `if (!catch_up_mode) { drain INIT; drain CONSTRUCT; drain
REGISTER_CTOR; }` block from each `tagPlaceObject2*` function. The
queued entries will accumulate until the frame-level drain in Phase 3.

This change alone is **insufficient** — it would shift INIT/CTOR firing
to AFTER `actionDrainOnloadAndScript` (since the recompiler emits that
drain BEFORE `tagShowFrame`, and tagShowFrame is where the safety drain
fires). loop_test6 expects INIT/CTOR BEFORE check_equals — so we must
also reorder the frame-level drain (Phase 3+4).

### Phase 3 — Frame-level drain ordering

Two equivalent approaches:

**Option A (preferred): unified drain helper**

Add `actionDrainAllInPriorityOrder(app_context)` to
`SWFModernRuntime/src/actionmodern/action_queue.c` that drains in this
exact order:
1. `AQ_KIND_CLIP_INIT`
2. `AQ_KIND_CLIP_CONSTRUCT`
3. `AQ_KIND_REGISTER_CTOR`
4. (interleaved FIFO) `AQ_KIND_ONLOAD` + `AQ_KIND_SCRIPT`

Replace `actionDrainOnloadAndScript` call sites in the recompiler emit
(`SWFRecomp/src/swf.cpp:601, 904, 963`) with
`actionDrainAllInPriorityOrder`. The new helper subsumes the old
behavior — when no INIT/CTOR/REGISTER_CTOR entries exist, it falls
through to the same OnloadAndScript drain.

In `tagShowFrame` (`tag.c:2271-2277`), keep the existing INIT/CTOR
safety drain as a true backstop — it becomes a no-op in the common
path because the recompiler-emitted drain already cleared the queue.

**Option B: split emit**

Have the recompiler emit:
```c
actionDrainActionQueueByKind(AQ_KIND_CLIP_INIT);
actionDrainActionQueueByKind(AQ_KIND_CLIP_CONSTRUCT);
actionDrainActionQueueByKind(AQ_KIND_REGISTER_CTOR);
actionDrainOnloadAndScript(app_context);
tagShowFrame(app_context);
```

This is more lines per emission but keeps individual drain semantics
visible. Reject Option B — cluttered, harder to keep in sync if a
future kind is added.

Pick **Option A**.

### Phase 4 — Recompiler emission update

`SWFRecomp/src/swf.cpp` has three sites that emit
`actionDrainOnloadAndScript`:
- Line 601 — root frame end (after RemoveObject + DoAction interleave).
- Line 904 — sprite frame end.
- Line 963 — final frame fallback.

Replace each with `actionDrainAllInPriorityOrder`.

Also audit `tagDoInitActionGuarded` (`tag.c:5312`) — DoInitAction tags
fire pre-frame (before the first PlaceObject). They should NOT trigger
the priority drain mid-frame; they queue Normal priority. The unified
drain runs at SHOW_FRAME emission only. ✓ no change needed.

### Phase 5 — Regression battery

**Required-pass tests (must remain green):**

AVM1 lifecycle / CONSTRUCT-order battery:
- `on_construct` (25/25 — depends on registerClass CONSTRUCT timing
  vs INITIALIZE; verify the reordered drain doesn't shift anything).
- `register_and_init_order` (233/233 — the canonical ordering test;
  if this regresses by ANY line, this plan is wrong).
- `init_object_order` (15/15).
- `clip_events` (18/18 — clip-event INIT/LOAD/CONSTRUCT ordering for
  a single sprite; should be unaffected since one-sprite case is
  identical under per-placement-drain or unified-drain).
- `bad_placeobject_clipaction` (must remain green).
- `movieclip_in_removed_button`.

Gnash misc-ming recently-fixed (must not regress):
- `loop_test2/3/4/5/8/9` — multi-sprite-in-frame tests; highest-risk
  for ordering shifts. Run these first after Phase 2.
- `instanceNameTest`, `attachMovieTest` (attachMovie path is
  unaffected — synchronous, not via this drain).
- `event_handler_scope_test`, `ResolveEventsTest`,
  `displaylist_depths_test11`, `place_and_remove_object_test`,
  `static_vs_dynamic1/2`, `new_child_in_unload_test`,
  `action_execution_order_test8-v5/v6`.

Gnash misc-swfc:
- `stackscope`, `edittext_test1`, `submoviegetvar`,
  `movieclip_destruction_test2` (50/52 — must not regress).

Shumway:
- `duplicateMovieClip/dontremove`,
  `duplicateMovieClip/duplicateMovieClip`,
  `duplicateMovieClip/samedepth`,
  `duplicateMovieClip/name-coercion`.

**Target tests (expected to gain lines):**
- `loop_test6` (10/23 → ~14/23). Full PASS requires INTER_TAG_UNLOAD_PLAN.

**Net expected delta:** 0 PASS flips on its own; +4 lines on loop_test6;
combined with INTER_TAG_UNLOAD_PLAN it lands a full pass.

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
   ordering — verify with `clip_events` and `register_and_init_order`.

3. **`tagShowFrame` safety drain interaction with `actionFirePendingUnloads`.**
   Today's tagShowFrame drains INIT/CTOR (lines 2271-2277), then calls
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

   Two responses:
   1. This is the Ruffle / Flash behavior. In Ruffle, all DoAction queues
      Normal priority and drains AFTER INIT/CTOR. So DoAction-after-Place
      sees the post-CTOR state.
   2. ...wait, that's the opposite of what I just said. Let me re-check.
      Actually Ruffle's `pop_action` returns priority 2 (Initialize) FIRST,
      so INIT fires before Normal DoAction even when DoAction was QUEUED
      LATER. Confirmed at `context.rs:527-532`.

   Conclusion: Ruffle's drain is **strictly priority-ordered**, not
   FIFO-across-priorities. INIT fires first regardless of queue-time
   order. Our unified drain in Phase 3 implements this exactly. ✓

   Risk: if any existing test passes by relying on **our** broken
   ordering (DoAction-before-CTOR when DoAction was queued first), it
   would regress. The regression battery in Phase 5 should catch it.

## Risk

- **Low-medium.** The existing infrastructure already supports priority
  drain — the change is wiring. Phase 2 + 4 are mechanical replacements.
- **Highest-risk regression:** `register_and_init_order` (233 lines of
  precise ordering assertions). The test was designed around our current
  per-placement drain semantics. If it regresses, the fix is to enforce
  Ruffle-strict priority drain (INIT > CTOR > REGISTER_CTOR > Normal),
  which should match Ruffle and Flash but may diverge from this test's
  internal expectations if it was authored against our previous behavior.

## Why this is the right shape

This plan mirrors Ruffle's exact mechanism with a single helper
(`actionDrainAllInPriorityOrder`). The existing 3-priority queue already
does the right thing structurally; we just stop pre-draining in
`tagPlaceObject2` so the queue can accumulate cross-sprite entries before
the priority drain kicks in.

This is the minimum-surface-area change that achieves round dispatch.
A larger refactor (e.g. eliminating the per-kind drain helpers and
replacing them with a single `pop_action`-style cursor) is appealing
but out of scope — the plan above is enough to flip the visible
behavior.

## Estimated session budget

- Phase 1 (audit): 30 min reading.
- Phase 2 (delete per-placement drain): 15 min.
- Phase 3 (add unified drain helper): 30 min.
- Phase 4 (recompiler emission update): 30 min — three sites, mechanical.
- Phase 5 (battery): 30 min per re-run, plan for 2 re-runs minimum.

A single 2-3 hour session is realistic.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Parent plan; §1 of its "Follow-up work" section. This plan covers that §1. |
| `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | Sibling plan from same parent. Independent — they could be implemented in either order. SPRITE_EXEC_LIST_LIFO changes WHO fires; this plan changes WHEN they fire. |
| `incomplete/INTER_TAG_UNLOAD_PLAN.md` (TBD) | Sibling plan. loop_test6's tail (lines 12-23) needs both plans to fully pass. |
| Ruffle source: `core/src/context.rs:490-533, 655-663` (priority queue), `core/src/player.rs:2144-2196` (run_actions drain). | Reference implementation. |
