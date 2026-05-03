# SwapDepths Rewind Fresh-Placement Plan

<!-- TESTS: displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3 -->

<!-- PLAN_META
id: SWAPDEPTHS_REWIND_FRESH_PLACEMENT
status: incomplete
note: "Phases 1, 1.5, 2 complete. Phase 3 implicit (existing clear_after handles dynamic-zone preservation; static-zone destruction handled by cleanup_unplaced_after). Phase 4 (test2 soft-ref re-binding) still blocked on architectural Option A/B/C. Phase B (deferred CONSTRUCT) blocked on test6 ordering — see 'Phase 2 results (2026-05-03)' below."
phases:
  - id: 1
    name: "Audit: identify all currently-passing tests that depend on tag.c::tagPlaceObject2 depth_swapped re-place block (the load-bearing guardrails)"
    status: completed
  - id: 1.5
    name: "Path-based MOVIECLIP equality (Ruffle Value::PartialEq mirror) — unblocks fresh-placement work"
    status: completed
  - id: 2
    name: "Replace the re-use semantic with fresh placement: empty target slot + non-empty depth_swapped source elsewhere → freshly place new MC at the target depth (CONSTRUCT fires)"
    status: completed
  - id: 3
    name: "Decide fate of the moved MC at the swap-target depth (preserve in dynamic zone, destroy in static zone — Ruffle behavior)"
    status: completed
  - id: 4
    name: "Soft-reference re-binding: AS-level references saved before rewind (`dynRef = static3`) must re-resolve to the freshly-placed MC after rewind"
    status: blocked
  - id: B
    name: "Deferred post-rewind CONSTRUCT firing — likely promotes displaylist_depths_test3 to ruffle_matched standalone"
    status: blocked
  - id: 5
    name: "Verify on guardrail battery (loop_test3, rewind_depth, soft_reference_test1, all displaylist_depths_test*) and target tests"
    status: completed
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

---

## Phase 1 Audit Findings (2026-05-03)

### Guardrail tests run locally (all PASS)

| Test | Suite | Result | Pattern |
|------|-------|--------|---------|
| `rewind_depth` | avm1 | PASS 30/30 | swap to dynamic depth + rewind; `getInstanceAtDepth(swap_target) === getInstanceAtDepth(orig_depth)` (StrictEquals **true**) |
| `goto_rewind1`, `goto_rewind2`, `goto_rewind3` | avm1 | PASS | Backward goto without swapDepths interaction |
| `movieclip_depth_methods` | avm1 | PASS 98/98 | depth queries, no rewind |
| `movieclip_get_instance_at_depth` | avm1 | PASS 28/28 | depth queries, no rewind |
| `placeobject_occupied_depth` | avm1 | PASS 6/6 | re-place at occupied depth |
| `depth_replacement_audio_unloading` | avm1 | PASS 3/3 | unrelated audio path |
| `loop/loop_test2`, `loop_test3` | misc-ming | PASS | swap-within-tag-stream-depth + backward goto (handled by `survives_rewind`, NOT depth_swapped block) |
| `static_vs_dynamic1`, `static_vs_dynamic2` | misc-ming | PASS | swap to dynamic, no rewind interaction |
| `displaylist_depths_test{,8,9,10,11}` | misc-ming | PASS / RM | various depth swap patterns; none assert distinct-MC-after-rewind |
| `duplicate_movie_clip_test{,2}` | misc-ming | PASS / RM | clone path (covered by CLONE_CLIP_EVENT_DISPATCH) |
| `displaylist_depths_test2` | misc-ming | **MISMATCH 15/31** (target) | swap to dynamic depth (10) + rewind, expects FRESH MC at original depth + OLD MC preserved at swap target |
| `displaylist_depths_test3` | misc-ming | **MISMATCH 17/32** (target) | same as test2, but swap to static depth (-10) + rewind |
| `soft_reference_test1` | misc-swfc | MISMATCH 23/45 | name-rebinding via `_name` reassignment + remove/recreate cycle |

### Architectural blocker: name-keyed MovieClip identity

The `depth_swapped` re-use block at `tag.c:4271-4304` is **load-bearing** for `rewind_depth` because of how our system models MovieClip identity:

1. `findOrCreateMovieClip(name, parent)` is the single source of truth for "MC pointer for a given name+parent". Stored in `child_mc_cache` (action.c:18919-18980).
2. `getInstanceAtDepth(depth)` first scans `child_mc_cache` by depth, then falls back to `display_list[depth].instance_name` → `findOrCreateMovieClip(name, parent)` (action.c:58530-58555). Side-effect: it **mutates** `_sprite_mc->depth = _target_depth` after every lookup (line 58540).
3. After our depth_swapped block fires, both `display_list[orig_depth]` and `display_list[swap_target_depth]` carry the same `instance_name = "static3"`. Successive `getInstanceAtDepth()` calls oscillate the MC's `depth` field but always return the **same** `MovieClip*`. That's how `rewind_depth`'s `Clips are equal: true` assertion holds: both lookups return the same pointer, which `StrictEquals` true.

`displaylist_depths_test2` requires the **opposite** invariant:
- `static3` (variable lookup) must resolve to a **fresh MC** with `myThing == undefined`, `getDepth() == -16381`, `_x == 50`.
- `dynRef` (saved before goto) must keep pointing at the **OLD MC** with `myThing == 'guess'`, `getDepth() == 10`.
- `getInstanceAtDepth(-16381)` and `getInstanceAtDepth(10)` must return the two distinct MCs.
- CONSTRUCT clip event must fire on the fresh placement (`depth3Constructed == 2`).

This is **structurally incompatible** with single-instance-per-(name,parent) caching. To support test2/3 we would need one of:

- **Option A: Depth-keyed identity.** Change `findOrCreateMovieClip` (and every caller) to use `(name, parent, depth)` as the cache key. Two MCs with the same name at different depths become distinct objects. **Risk:** breaks `getInstanceAtDepth`'s mutation of `depth` (line 58540) and breaks every existing caller that assumes name uniqueness. Scope: ~50+ call sites across action.c (50K LOC), tag.c, swf_core.c.
- **Option B: Per-display-list-slot MC pointer.** Store `MovieClip*` directly on `DisplayObject` (display_list slot) rather than re-resolving by name. Two slots can hold distinct pointers even with the same `instance_name`. **Risk:** name resolution logic (`actionGetVariable`, scope walks, `_root.foo` paths) needs new "find by name across all DL slots" logic with depth-ordering tiebreak.
- **Option C: "Displaced" flag.** Add `MovieClip.is_displaced` flag. When the depth_swapped block fires, mark the OLD MC as displaced (excluded from `findOrCreateMovieClip`) and create a NEW MC at the original depth. dynRef holds direct pointer (still works). `getInstanceAtDepth(swap_target)` would need to find the displaced MC via display_list[swap_target_swfdepth].instance_name + a displaced-MC scan. **Risk:** complex new code path; rewind_depth's `Clips are equal: true` becomes false (regression), which we'd need to re-engineer.

None of these options is single-session work. Each represents a substantial refactor with cross-cutting test risk.

### Why `rewind_depth` and `displaylist_depths_test2` are structurally opposed

- `rewind_depth`: explicit AS assertion `getInstanceAtDepth(2) === getInstanceAtDepth(-16383)` → **must alias** (one MC, two slots).
- `displaylist_depths_test2`: explicit AS assertions `static3.myThing === undefined` AND `dynRef.myThing === 'guess'` → **must be distinct** (two MCs).

Ruffle handles both because its display tree models DisplayObjects as Gc-cell identities owned by display-list slots; name lookup walks the display list at resolution time and ties broken by lowest-depth-wins. Our system collapses identity at the cache layer.

### `soft_reference_test1` is a *related but distinct* problem

This test exercises name-rebinding under `_name` reassignment + removeMovieClip/recreate cycles. Failures (`mcRef.getDepth()` returns empty string instead of "30") suggest our `mcRef` MOVIECLIP value loses validity when the MC is renamed. This is a **separate** code path from rewind, but shares the broader theme of "MC identity vs. AS variable binding". Phase 4 of the original plan mentioned this overlap; the fix likely shares Option B/C.

### Distinguishing signal Ruffle uses for re-use vs fresh-place

Re-reading Ruffle `MovieClip::run_goto` (`core/src/display_object/movie_clip.rs`):
- Walks tag stream from frame 0 forward.
- For each `PlaceObject2(char_id, depth)`: looks up `child_at_depth(depth)`.
- If empty → **freshly instantiate** the character (new identity, fires CONSTRUCT).
- If occupied with same `char_id` → calls `replace_with` which is a no-op for MovieClip → preserves identity.
- The "what happens to the swapped-away MC" is governed by `survives_rewind` per-instance; for MovieClip the override returns `avm1_clone_target.is_none()` (clones don't survive; non-clones do unless explicitly removed). Static-zone MCs without a covering PlaceObject2 in the rewind range are destroyed via `remove_child`.

Ruffle's logic does **not** consider "is the same char_id alive at a different depth?" — that's our depth_swapped re-use heuristic, which has no Ruffle counterpart. Our heuristic was a workaround for the name-keyed-identity limitation, not a model of Ruffle behavior. To match Ruffle we need to remove the heuristic AND fix the underlying identity model — and rewind_depth's "Clips are equal: true" only happens to pass because of our heuristic, not because Ruffle aliases two depths.

Investigation: a quick check of what Ruffle actually outputs for rewind_depth would clarify whether our `Clips are equal: true` is a Ruffle-original assertion or whether Ruffle's expected output already says `false` and we're matching by accident. The `output.txt` is from Ruffle's own runner so it should reflect Ruffle behavior. **Hypothesis (untested):** Ruffle's `rewind_depth` test instead asserts `getInstanceAtDepth(-16383) === <originally-saved reference>` rather than the cross-depth comparison I assumed. Re-reading bytecode confirmed it's the cross-depth comparison. Ruffle must therefore also be aliasing, or `getInstanceAtDepth(2)` returns the swap-target MC and `getInstanceAtDepth(-16383)` returns... the same swap-target MC if the rewind doesn't fresh-place when the same character is alive elsewhere. **This is itself a contradiction with Ruffle's run_goto** that needs deeper inspection. Possible answer: Ruffle's `run_goto` short-circuits when the character is alive elsewhere via the `find_existing_child` path, and only fresh-places when the character is gone. **This would mean the depth_swapped re-use block is correct for Ruffle's behavior, and `displaylist_depths_test2/3` are testing a *Gnash*-specific (Flash Player) behavior that Ruffle does not implement.**

If true, test2/test3 may belong in `RUFFLE_VS_FLASH_DIFFERENCES.md` rather than being fixable. Verifying this would require running Ruffle on test2's SWF locally and comparing its actual output to ours and to the gnash-expected output. Out of scope for this audit.

### Conclusion

**Action:** Mark plan blocked. The proposed implementation in Phases 2-4 is architecturally too risky for incremental fixes — would require either a multi-session refactor of MovieClip identity (Options A/B/C above) or first verifying whether Ruffle even implements the test2/3 expected behavior (in which case the tests would move to `RUFFLE_VS_FLASH_DIFFERENCES.md` and the plan becomes obsolete).

**Recommended next step (separate task):**
1. Build Ruffle locally and run it against `displaylist_depths_test2.swf` + `displaylist_depths_test3.swf` to capture its actual trace output.
2. If Ruffle output matches the gnash-expected output: implement Option A/B/C in a follow-up plan.
3. If Ruffle output diverges from gnash-expected (matching ours instead): document in `RUFFLE_VS_FLASH_DIFFERENCES.md` and close this plan as won't-fix.

---

## Followup investigation (2026-05-03 evening)

### Pre-captured Ruffle output exists (`output.ruffle.txt`)

Both tests already ship `output.ruffle.txt` alongside `output.txt`. No need to build Ruffle locally. Comparing:

**`displaylist_depths_test2`** (swap to dynamic depth 10): Ruffle's actual output has 19/21 internal assertions PASS (`#passed: 19, #failed: 1`). The single failure is `depth3Constructed == 2` (Ruffle reports 1) — Ruffle defers the post-rewind CONSTRUCT to the next frame, so the trace lines `_level0.static3 onClipConstruct` and `_root.depth3Constructed set to 2` appear AFTER `totals()`. All other test2 assertions (`static3.myThing == undefined`, `static3.getDepth() == -16381`, `dynRef.myThing == 'guess'`, `dynRef.getDepth() == 10`) pass in Ruffle. The test does test real Ruffle behavior — it is **not** a `RUFFLE_VS_FLASH_DIFFERENCES.md` candidate.

**`displaylist_depths_test3`** (swap to static depth -10): same shape. Ruffle's actual output has 21/22 assertions PASS, fails the same `depth3Constructed == 2` line for the same deferred-CONSTRUCT reason. All `dynRef === static3`, `dynRef._x == 50`, `getInstanceAtDepth(-16381) == movieclip`, `getInstanceAtDepth(-10) == undefined` assertions pass.

### Resolution of the rewind_depth puzzle: Ruffle compares MovieClip values **by path**, not pointer

Ruffle source `core/src/avm1/value.rs:117-130`:

```rust
impl PartialEq for Value<'_> {
    fn eq(&self, other: &Self) -> bool {
        match (self, other) {
            ...
            (Value::Object(a), Value::Object(b)) => Object::ptr_eq(*a, *b),
            (Value::MovieClip(a), Value::MovieClip(b)) => a.path() == b.path(),
            ...
        }
    }
}
```

`Value::Object` uses pointer equality, but `Value::MovieClip` uses **path equality** (full dot-path like `_level0.static3`). This is what makes:
- `rewind_depth`'s `Clips are equal: true` work — both `getInstanceAtDepth(2)` and `getInstanceAtDepth(-16383)` return MCs with path `_level0.timeline_child` (different MovieClip instances, but same name).
- `displaylist_depths_test3`'s `dynRef === static3` work — dynRef points at the OLD (renamed-displaced) MC and static3 resolves to the NEW MC, both with path `_level0.static3`.

Our system was using pointer equality for MOVIECLIP, which is **wrong** for AVM1.

### Implementation: path-based MOVIECLIP equality

`actionStrictEquals` and `actionEquals2` in `action.c` updated to compare `MovieClip*->target` (slash notation, dead MCs use `original_target`) when both operands are MOVIECLIP. Helper `mc_path_equal` mirrors Ruffle's `a.path() == b.path()`.

Regression battery (52 tests across avm1, gnash misc-ming, gnash actionscript): **all PASS**. No regressions.

### What path equality unlocks

For `displaylist_depths_test3` (swap to static depth):
- Was: `matched=17/32 (status=output_mismatch)` — `dynRef === static3` failed on pointer mismatch.
- After path eq: `matched=21/32` (4-line gain). Status remains `output_mismatch` because we still don't fire the deferred CONSTRUCT trace lines after `totals()` (Ruffle does), so our 3 trailing-missing lines aren't a subset of Ruffle's 1 trailing-missing line. Phase B work (deferred CONSTRUCT) would close this gap and likely promote to `ruffle_matched`.

For `displaylist_depths_test2` (swap to dynamic depth):
- No change. Test2's failures (`static3.myThing == undefined`, `static3.getDepth() == -16381`) require `static3` variable lookup to resolve to a fresh MC distinct from the swap-moved one. Path equality doesn't fix the *resolution*, only the *comparison*. Test2 still needs the architectural Option A/B/C work.

For `soft_reference_test1`:
- No change. The failures (`mcRef.getDepth()` returns `""` empty string) are about MOVIECLIP→string coercion of dead/renamed MCs, not about MC equality. Different code path.

### Revised blocker statement

The original blocker (architectural identity refactor) still applies for **test2** and the broader Option B/C work. But:

1. The `rewind_depth` aliasing requirement was a **misdiagnosis** — it doesn't require shared pointers, only equal paths. Path equality is now in place, so the depth_swapped re-place block is no longer load-bearing for that test.
2. **Phase 2 of the original plan (replace re-use with fresh placement) is now safe to attempt** — `rewind_depth` would still pass via path equality of two distinct MovieClip instances both named `timeline_child`. Plan should be re-opened for Phase 2 once a session is allocated to it.
3. **Phase B (deferred CONSTRUCT after totals())** is a separate, independently-implementable task that would promote `displaylist_depths_test3` to `ruffle_matched`.
4. **Test2 still requires Option A/B/C** for the architectural multi-MC-per-name support — that's the only remaining hard blocker.

### Unblock recommendation

Move plan back to `incomplete/` with revised phases:

- Phase 1: COMPLETE (audit + path-eq investigation)
- Phase 1.5 (NEW, COMPLETE): Path-based MOVIECLIP equality
- Phase 2 (READY): Replace depth_swapped re-use with fresh placement (formerly blocked, now unblocked by path eq)
- Phase 3 (READY): Fate of moved MC (per Ruffle semantics)
- Phase 4 (BLOCKED on Option A/B/C): Soft-reference re-binding for test2
- Phase B (NEW, READY): Deferred post-rewind CONSTRUCT firing — likely promotes test3 to ruffle_matched standalone

Phases 2, 3, B can land independently as small commits. Phase 4 still requires architectural work.

---

## Phase 2 results (2026-05-03)

### Implementation

`SWFModernRuntime/src/libswf/tag.c` — removed the depth_swapped re-use block at lines 4271-4304. The block was a workaround for pointer-equality of MovieClip values; Phase 1.5 (path-based MovieClip equality) made it unnecessary. Falling through to standard fresh placement now mirrors Ruffle's `run_goto`: the rewind tag stream freshly instantiates the character at its tag-defined depth, and `ng_display_clear_after` / `ng_display_cleanup_unplaced_after` handle the moved MC at the swap-target depth (Phase 3 — preserved in dynamic zone, destroyed in static zone with `actionInvalidateCachedMovieClip`).

### Test impact

| Test | Before | After | Δ |
|------|--------|-------|---|
| `displaylist_depths_test2` (swap to dynamic) | 15/31 | 22/31 | +7 |
| `displaylist_depths_test3` (swap to static) | 17/32 | 28/32 | +11 |
| `loop/loop_test6` | 12/23 | 12/23 | 0 (no regression) |
| `loop/loop_test10` | 3/28 | 3/28 | 0 (no regression) |

Verified guardrail battery (47 tests across avm1/misc-ming): 25 AVM1 PASS, 19/22 misc-ming pass/ruffle_matched (3 unrelated failures: gotoFrame2Test timeout new test; loop_test6/loop_test10 unchanged from CI baseline).

### Phase 3 — implicit (already handled)

The "fate of moved MC" semantics described in Phase 3 are already implemented by existing infrastructure:

- **Dynamic-zone target (test2 swap to AS depth 10):** `ng_display_clear_after` has `if (i >= 16384) break;` so dynamic-range entries are NOT cleared during catch-up. The OLD MC at SWF depth 16394 stays alive with its dynamic_props intact. `dynRef.myThing == 'guess'` works correctly.
- **Static-zone target (test3 swap to AS depth -10):** `ng_display_clear_after` clears static-range entries with `placed_at_frame > target_frame`, except sprite-bearing ones (preserved via `continue`). After catch-up replay, `ng_display_cleanup_unplaced_after` invalidates surviving entries' cached MCs via `actionInvalidateCachedMovieClip`. `getInstanceAtDepth(-10) == undefined` works correctly.

### Phase 4 — still blocked (test2 only)

For `displaylist_depths_test2` to fully pass, the AS variable lookup `static3` must resolve to the FRESH MC at depth -16381 instead of the OLD MC preserved at depth 10. Both MCs are named "static3" with the same parent (`_root`). Our `findOrCreateMovieClip(name, parent)` cache returns the first match, which is the OLD MC. This is the architectural identity blocker (Option A/B/C in the original plan).

Phase 2 didn't unblock this — it improved test2 only on the static3-now-undefined cases (the OLD MC cache path returns `myThing='guess'` which is wrong; expected is undefined for the fresh MC). The remaining 9-line gap to test2 PASS is all in the soft-reference re-binding category.

### Phase B — incompatible with action_execution_order_test6

Investigated deferring CLIP_CONSTRUCT firing during backward goto catch-up so it lands AFTER the calling script (matching Ruffle's actual output for test3). This would promote test3 to `ruffle_matched`.

**Blocker:** `action_execution_order_test6` (gnash misc-ming) explicitly expects CONSTRUCT clip events to fire CHRONOLOGICALLY during backward goto catch-up, interleaved with LOAD events from the same catch-up. Source comment:

```
* At frame5 go backward to frame4:
*   mc1.Construct
*   mc2.Construct
*   mc1.Load
*     actions in 1st frame of mc1
*   mc2.Load 
*     actions in 1st frame of mc2
```

Deferring CLIP_CONSTRUCT past the calling script would break this ordering. The actual Flash semantics appear to involve per-AS-statement yield points (CONSTRUCT drains between AS statements within the calling script), which is a significant runtime refactor.

For test3 specifically, expected output has CONSTRUCT trace at lines 16-18 — between line 15 (typeof check, first AS statement after gotoAndStop) and line 19 (typeof(dynRef.myThing), second AS statement). This requires inter-statement event drain, beyond simple post-script deferral.

**Disposition:** Phase B requires a bytecode-level event yield mechanism. Not feasible as a small commit. Status changed to BLOCKED.

### Final status

Phases 1, 1.5, 2, 3, 5: COMPLETE. Phases 4 and B: BLOCKED on architectural changes. Plan stays in `incomplete/` since work is not fully done. Net gain this phase: +7 lines on test2, +11 lines on test3, no regressions.
