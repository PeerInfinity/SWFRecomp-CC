# SwapDepths Rewind Fresh-Placement Plan

<!-- TESTS: displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3 -->

<!-- PLAN_META
id: SWAPDEPTHS_REWIND_FRESH_PLACEMENT
status: incomplete
phases:
  - id: 1
    name: "Audit: identify all currently-passing tests that depend on tag.c::tagPlaceObject2 depth_swapped re-place block (the load-bearing guardrails)"
    status: pending
  - id: 2
    name: "Replace the re-use semantic with fresh placement: empty target slot + non-empty depth_swapped source elsewhere → freshly place new MC at the target depth (CONSTRUCT fires)"
    status: pending
  - id: 3
    name: "Decide fate of the moved MC at the swap-target depth (preserve in dynamic zone, destroy in static zone — Ruffle behavior)"
    status: pending
  - id: 4
    name: "Soft-reference re-binding: AS-level references saved before rewind (`dynRef = static3`) must re-resolve to the freshly-placed MC after rewind"
    status: pending
  - id: 5
    name: "Verify on guardrail battery (loop_test3, rewind_depth, soft_reference_test1, all displaylist_depths_test*) and target tests"
    status: pending
dependencies:
  - "complete/CLONESPRITE_DEPTH_BIAS_PLAN.md (depth-bias unification — prerequisite for clean swapDepths semantics)"
  - "complete/(none yet, see CURRENT_STATUS) loop_test3 backward-rewind survives_rewind work (commit d4ea78fc — established the placed_at_frame-pinned-to-depth contract this plan extends)"
related:
  - "incomplete/CLONE_CLIP_EVENT_DISPATCH_PLAN.md (parent — Phase 6 fixed clones; this plan handles the swapDepths rewind sub-case it left behind)"
  - "incomplete/REMAINING_TAIL_TRIAGE.md (`soft_reference_test1` 23/45 entry — likely shares the soft-reference re-binding work in Phase 4 below)"
-->

## Problem statement

After CLONE_CLIP_EVENT_DISPATCH (commit `4858cdcd`) landed:
- `displaylist_depths/displaylist_depths_test9` → PASS (from 3/23)
- `duplicate_movie_clip_test` → RUFFLE_MATCHED (from 3/33)
- `displaylist_depths/displaylist_depths_test2` → unchanged at 15/31
- `displaylist_depths/displaylist_depths_test3` → unchanged at 17/32

test2/test3 were *part of the same target list* in the parent plan but
fail on a structurally different mechanism: a static MC moved by
`swapDepths()` then re-encountered during backward `gotoAndStop()` is
re-used in place by our depth_swapped block at `tag.c:4271-4304` instead
of being freshly re-placed (which would re-fire CONSTRUCT and create a
new instance at the original depth).

This plan covers the swapDepths-rewind half of the
displaylist_depths series. It does NOT touch the clone path —
clone-replaced behavior was solved in Phase 6 of
`CLONE_CLIP_EVENT_DISPATCH_PLAN.md`.

## Failure shape

### `displaylist_depths/displaylist_depths_test2` (15/31, 48.4%)

Source: `gnash/testsuite/misc-ming.all/displaylist_depths/displaylist_depths_test2.c`.

```
Frame 2: PlaceObject2(static3, depth=3) with SWFACTION_CONSTRUCT
         (clip event increments _root.depth3Constructed and traces
          "_level0.static3 onClipConstruct").
Frame 4-5: PlaceObject2(static3, depth=3, transform_id changes)
Frame 6: AS calls static3.swapDepths(10) — moves to AS depth 10
         (dynamic zone, SWF depth 16394).
Frame 7: AS calls gotoAndStop(4).
```

After `gotoAndStop(4)` the test expects:
- depth -16381 (SWF 3) has a **new** static3 instance — CONSTRUCT
  re-fires (`depth3Constructed == 2`).
- depth 10 (SWF 16394) still has the **old** static3 (preserved —
  dynamic zone is owned by ActionScript, not the tag stream).
- AS reference `static3` resolves to the new instance.
- AS reference `dynRef` (saved before goto) re-resolves to the new
  instance (Gnash "soft reference" semantics — see
  https://www.gnashdev.org/wiki/index.php/SoftReferences).

What we produce: depth 3 is re-populated by re-using the moved MC from
SWF 16394 (depth_swapped block at tag.c:4271). CONSTRUCT does not
re-fire. `static3.myThing == 'guess'` (carried over from pre-goto
state) instead of `undefined` (which it would be on a fresh instance).

| Expected line | Actual line | Diagnosis |
|---|---|---|
| `_level0.static3 onClipConstruct` (2nd) | (missing) | CONSTRUCT not re-fired |
| `_root.depth3Constructed set to 2` | (missing) | side-effect of missing CONSTRUCT |
| `PASSED: undefined == undefined` (typeof static3.myThing) | `FAILED: expected: undefined, obtained: string` | reused MC carries pre-goto property |
| `PASSED: -16381 == -16381` (static3.getDepth) | `FAILED: expected: -16381, obtained: 10` | static3 still resolves to old MC at depth 10 — soft reference not re-bound |
| `PASSED: 2 == 2` (depth3Constructed) | `FAILED: expected: 2, obtained: 1` | counter never incremented |

### `displaylist_depths/displaylist_depths_test3` (17/32, 53.1%)

Same shape as test2 except the swap target is a **static** depth
(`swapDepths(-10)`, AS depth -10 = SWF depth 16374). Expected behavior
differs only in this regard:
- `getInstanceAtDepth(-10) == 'undefined'` after rewind (the moved MC
  IS destroyed when its slot is in the static range and not in the
  rewind tag stream).

Same CONSTRUCT-not-firing + soft-reference-not-re-binding failures.

## Root cause analysis

### Block under suspicion: tag.c:4271-4304

```c
// During backward catch-up, if this depth is empty but a depth_swapped entry
// with the same char_id exists elsewhere, the character was moved by swapDepths.
// Treat as re-placing the same character (update transform, suppress re-init)
// to avoid creating a duplicate MovieClip.
if (catch_up_backward && display_list[depth].char_id == 0 && char_id != 0)
{
    for (size_t _sd = 1; _sd <= max_depth; _sd++) {
        if (_sd == depth) continue;
        if (display_list[_sd].char_id == char_id && display_list[_sd].depth_swapped) {
            // Found the swapped entry — place a fresh entry at this depth
            // but suppress sprite init (the MC already exists in cache).
            display_list[depth].char_id = char_id;
            // ... copies transform, etc ...
            display_list[depth].sprite_needs_init = 0;  // suppress re-init
            display_list[depth].depth_swapped = 0;
            // ...
            ng_on_place_object2(app_context, depth, char_id);
            display_list[depth].sprite_needs_init = 0;  // ensure no init
            return;
        }
    }
}
```

Added in commit `e28a1321` (2026-02-26) to fix `rewind_depth` (which
expected the same MC pointer to be referenced from both the original
and the swap-target depth after rewind). The "suppress re-init"
semantic is what blocks CONSTRUCT from firing in test2/test3.

### Why test2/test3 want the opposite behavior

The test source explicitly comments:

```c
// this repopulates depth -16381 with a *new* instance
"gotoAndStop(4);"

// static3 doesn't refer to the dynamic object anymore !
"check_equals(typeof(static3.myThing), 'undefined');"
```

Per Ruffle's `MovieClip::run_goto`
(`core/src/display_object/movie_clip.rs`), the rewind walks tag stream
from frame 0:
1. For each `PlaceObject2(char_id, depth)` tag: look up current child
   at `depth`.
2. If empty, **freshly instantiate** the character and place it.
3. The pre-existing instance at the swap-target depth is unrelated to
   this slot — it stays where script-set `swapDepths` put it (subject
   to dynamic-vs-static-zone destruction rules).

Our depth_swapped block conflates "depth has matching char_id elsewhere"
with "this is the same conceptual instance" — true for `rewind_depth`
(where the test asserts identity-equality across the two depths) but
false for test2/test3 (where the test asserts a fresh instance with
fresh CONSTRUCT side-effects).

### Why this block is currently load-bearing

`rewind_depth` (avm1 suite, currently PASS 30/30) explicitly asserts:

```
this.getInstanceAtDepth(2).getDepth(): 2
this.getInstanceAtDepth(-16383).getDepth(): -16383
Clips are equal: true
```

After backward goto, both depths reference the same MC instance, AND
the MC's `getDepth()` returns whichever slot was used for the lookup.
Removing the depth_swapped block would break this. Phase 1 below must
trace **why Ruffle produces this exact output** — the working
hypothesis is that Ruffle emits the dual-depth presentation via a
different mechanism (a "depth alias" or two display-list slots
referencing one underlying MC), and the depth_swapped block in our
code is a (wrong) approximation of that mechanism.

## Currently-passing tests that exercise the depth_swapped block

Identified via grep for tests calling `swapDepths` followed by a
backward `gotoAndStop` / `gotoAndPlay`. Phase 1 must run each one
locally and confirm — these are the guardrails that any fix must not
regress.

- `avm1/rewind_depth` — PASS 30/30 (the test that motivated the block,
  added in commit `e28a1321`)
- `from_gnash/misc-ming.all/loop/loop_test2` — PASS (per commit
  `d4ea78fc` notes); tests swapDepths within tag-stream depths +
  backward goto where the survives_rewind branch (NOT the
  depth_swapped block) handles it
- `from_gnash/misc-ming.all/loop/loop_test3` — PASS (commit
  `d4ea78fc`); same pattern as loop_test2
- `from_gnash/misc-ming.all/static_vs_dynamic1`, `_2` — PASS (verified
  in CLONE_CLIP_EVENT_DISPATCH Phase 7); test swap to dynamic-zone
  with subsequent rewind interaction
- `avm1/swap_depths`, `swap_depths2`, etc. — to enumerate in Phase 1

## Proposed phases

### Phase 1 — Audit guardrails (read-only, no code)

For each candidate test in the "currently passing" list above:
1. Run locally and capture the diff (should be PASS).
2. Identify which AVM1 lines exercise the swapDepths-then-backward-goto
   path.
3. Document the expected post-goto state: does the test expect "same
   MC at both depths" (rewind_depth pattern) or "two distinct MCs"
   (test2/3 pattern) or "swap preserved across goto" (loop_test3
   pattern)?
4. Identify the **distinguishing signal**: what makes Ruffle pick
   "re-use" vs "fresh place" for a given (depth, char_id, swapDepths)
   combination?

**Hypothesis to confirm or refute in Phase 1:** Ruffle's run_goto
clears the swap-target slot only when (a) the slot is in the static
zone (negative AS depth), (b) the MC at that slot has no PlaceObject2
tag in the rewind range. Otherwise the swap state is preserved. The
target slot's PlaceObject2 always freshly instantiates (regardless of
where the same character lives elsewhere in the display list).

**Deliverable:** Phase 1 audit notes appended to this plan with a
table of test → expected (depth_X state, depth_Y state, AS-ref
re-binding required) → currently-passing-via-which-code-path. **No
code changes.**

### Phase 2 — Fresh placement at target depth

Once Phase 1 confirms the rule: replace the "re-use" branch with
"fresh placement". The code path:

```c
if (catch_up_backward && display_list[depth].char_id == 0 && char_id != 0)
{
    // Old depth_swapped re-use block: REMOVE.
    // Fall through to standard fresh placement (which fires CONSTRUCT
    // via queue_clip_construct_events at tag.c:4464).
}
```

Two sub-questions to answer in Phase 2:
- **2a.** Does the existing depth_swapped MC at `_sd` need to be
  cleared to zero, OR converted into a "removed" state with an
  intervening tagShowFrame, OR left alone? The decision feeds Phase 3.
- **2b.** How does the rewind_depth assertion `Clips are equal: true`
  get satisfied if both depths now have *different* MCs after our
  change? Phase 1 audit must surface this.

### Phase 3 — Fate of the moved MC at the swap-target depth

Per Ruffle (and per the test outputs):

- **Dynamic zone target (positive AS depth, e.g., test2's
  `swapDepths(10)`):** moved MC stays at the swap-target depth. AS
  references resolved by name lookup find the *new* instance at the
  original depth (because both have the same `name` field but the
  freshly-placed one was registered last). `getInstanceAtDepth(10)`
  returns the moved MC.
- **Static zone target (negative AS depth, e.g., test3's
  `swapDepths(-10)`):** moved MC is destroyed if there's no
  PlaceObject2 tag at that depth in the rewind range.
  `getInstanceAtDepth(-10)` returns undefined.

Implementation: extend the existing `ng_display_clear_after`
(or a new `ng_destroy_unrooted_static_swapped_after`) to scan for
depth_swapped slots in the static range without a corresponding
PlaceObject2 in [0, target_frame] and clear them.

### Phase 4 — Soft-reference re-binding

Test2 line: `check_equals(typeof(static3.myThing), 'undefined');` —
expects the AS variable `static3` to resolve to the freshly-placed MC
(which has no `myThing` property), not the moved MC at depth 10
(which still has `myThing == 'guess'`).

Per Gnash's "soft reference" docs and Ruffle's behavior: AS variable
lookups for a name that matches multiple display-list entries return
the most-recently-placed one. After Phase 2 places a new static3 at
depth -16381 (after the moved-static3 at depth 10), `getVariable("static3")`
should return the new instance.

Implementation:
- `setGlobalVariableByName("static3", new_mc)` after the fresh
  placement re-binds the global to the new instance.
- For locally-saved references like `dynRef = static3` (where
  `dynRef`'s slot holds a MOVIECLIP ActionVar pointing at the old MC):
  Ruffle re-resolves on dereference. Our system needs the old MC's
  `display_obj` cleared and the AS resolution path to fall through to
  global lookup. Audit `actionGetMember` for the dereference path.

This phase overlaps with `REMAINING_TAIL_TRIAGE.md`'s
`soft_reference_test1` (23/45) entry — fixes here likely move that
test up too.

### Phase 5 — Verify

Battery (each with stale-cache clear `rm -rf RecompiledScripts
RecompiledTags`):

**Must-not-regress (currently PASS):**
- `avm1/rewind_depth`
- `avm1/swap_depths*` (enumerate in Phase 1)
- `from_gnash/misc-ming.all/loop/loop_test2`, `loop_test3`,
  `loop_test4..10` (all currently PASS)
- `from_gnash/misc-ming.all/static_vs_dynamic1`, `_2`
- `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test`,
  `_test8`, `_test9`, `_test10`, `_test11` (currently PASS or
  RUFFLE_MATCHED)
- `from_gnash/misc-ming.all/duplicate_movie_clip_test`,
  `_test2` (currently PASS or RUFFLE_MATCHED — Phase 6 of
  CLONE_CLIP_EVENT_DISPATCH)

**Target gains:**
- `displaylist_depths/displaylist_depths_test2` (15/31 → ~30/31 after
  Phases 2+3+4)
- `displaylist_depths/displaylist_depths_test3` (17/32 → ~31/32 after
  Phases 2+3+4)
- `soft_reference_test1` (23/45 → likely 30+/45 from Phase 4 alone)

## Risks and guardrails

**High-risk:**

1. **rewind_depth dual-depth presentation.** This test asserts the
   exact opposite of test2/3 (same MC at both depths post-rewind).
   Phase 1 MUST identify the load-bearing assertion mechanism. If the
   answer is "Ruffle's display tree allows two display-list slots to
   reference one MC", we may need a small refactor to model that
   directly (e.g., a "depth alias" field on DisplayObject) instead of
   the current re-place hack.

2. **Soft-reference late-binding.** ActionScript's `getMember`
   resolution for MOVIECLIP-typed locals is normally direct pointer
   dereference. Re-binding requires either (a) clearing the old MC's
   `display_obj` so AS lookups fall through to global re-resolution,
   or (b) routing all MC pointer access through a name-keyed lookup
   layer. Option (a) is less invasive.

3. **Forward-goto interaction.** Phase 2's fresh-placement branch must
   not fire on **forward** catch-up (only backward). Forward catch-up
   already runs script-only-mode for intermediate frames, but a
   PlaceObject2 in the target frame at a depth where a swap moved
   something away should NOT freshly place — the swap is preserved by
   forward catch-up. The existing `catch_up_backward` gate covers this
   but should be re-verified.

**Low-risk:**

4. **Phase 4 soft-reference binding** is additive — only kicks in
   when an AS variable points at an MC that's been "rewind-replaced".
   Should not affect tests that don't save MC references across
   rewinds.

## Estimated session budget

- Phase 1 (audit, no code): 1-2 sessions. The dual-mechanism question
  (re-use vs fresh-place per Ruffle) is the load-bearing investigation.
- Phase 2 (fresh placement): 0.5-1 session, gated by Phase 1.
- Phase 3 (moved-MC fate): 0.5-1 session.
- Phase 4 (soft-reference re-binding): 1-2 sessions; could spill into
  shared work with `soft_reference_test1`.
- Phase 5 (CI + iterate): 1-2 sessions.

Total: 4-7 sessions, multi-commit. Sized similarly to the parent
CLONE_CLIP_EVENT_DISPATCH plan.

## Why this is a separate plan (not a CLONE_CLIP_EVENT_DISPATCH addendum)

The parent plan addressed clone-specific lifecycle (clones inherit
clip events, dispatch ENTER_FRAME, fire UNLOAD on AS removal). The
swapDepths-rewind work touches a structurally different code path —
the `depth_swapped` re-place block was added years before clones got
real display-list slots, and it interacts with `rewind_depth` and
`loop_test3` which have nothing to do with clones. Bundling them
would conflate two independent mechanisms and risk regressing a
broader test set than necessary.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `incomplete/CLONE_CLIP_EVENT_DISPATCH_PLAN.md` | Parent plan — Phase 6's "clone-replaced never survives" gate handles the *clone* case; this plan handles the *swap-then-rewind* case the parent left behind. |
| `incomplete/REMAINING_TAIL_TRIAGE.md` | Contains `soft_reference_test1` 23/45 entry — Phase 4 work likely shared. |
| `complete/CLONESPRITE_DEPTH_BIAS_PLAN.md` | Established AVM_DEPTH_BIAS / depth-zone semantics this plan builds on. |
| `complete/(commit d4ea78fc)` "loop_test3 backward-rewind survives_rewind" | Established the placed_at_frame-pinned-to-depth contract Phase 3 will extend. |
| Ruffle source: `core/src/display_object/movie_clip.rs::run_goto` | Reference implementation — fresh placement at depth, with separate destroy-or-preserve logic for the moved MC. |
| Ruffle source: `core/src/display_object/movie_clip.rs::survives_rewind` | The MovieClip override (`avm1_clone_target.is_none()`) Phase 6 of the parent plan already mirrors. |
