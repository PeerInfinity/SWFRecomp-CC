# Sprite Rewind Identity Plan (per-sprite final_placements + MC isolation)

<!-- TESTS: action_order/ActionOrderTest3, action_order/ActionOrderTest4, action_order/ActionOrderTest5, loop/loop_test6, register_class/RegisterClassTest4 -->

<!-- PLAN_META
id: SPRITE_REWIND_IDENTITY
status: pending
phases:
  - id: 1
    name: "Recompiler emits per-sprite per-frame placements table"
    status: pending
  - id: 2
    name: "Runtime: replace silent-clear with survives_rewind iteration"
    status: pending
  - id: 3
    name: "Runtime: per-placement MC identity for non-survivors"
    status: pending
  - id: 4
    name: "Regression battery"
    status: pending
dependencies:
  - "blocked/INTER_TAG_UNLOAD_PLAN.md"
parent_plan: "blocked/INTER_TAG_UNLOAD_PLAN.md"
-->

## Background

This plan supersedes `blocked/INTER_TAG_UNLOAD_PLAN.md`, which tried four
narrow fixes for sprite loop-back UNLOAD events and ran into the same
trade family every time: every fix that activated the deferred UNLOAD
path on the plan-target tests (Test3/Test4/Test5/loop_test6) regressed
RegisterClassTest4 by suppressing/redirecting the cross-context clear in
ways that exposed the `cached MovieClip*` reuse bug in
`findOrCreateMovieClip`.

The blocker analysis identified three structurally-distinct
path-forward candidates. This plan investigates each and recommends a
concrete approach for the next attempt.

## Two intertwined root causes

These tests fail because of **two** independent bugs that interact:

**Bug A — silent loop-back loses UNLOAD lifecycle.** When a sprite
naturally advances past its last frame (or wraps via gotoAndPlay), the
silent-clear at `tag.c:872-885` (`advance_sprite_frames` `frame == 0
&& max_depth > 0`) zeros `char_id` and frees `sprite_display_list`
without firing `CLIP_EVENT_UNLOAD` clip-actions or AS-level `onUnload`
handlers. Mismatches Ruffle's `MovieClip::run_goto` rewind path
(`core/src/display_object/movie_clip.rs:1546-1696`), which builds a
`final_placements: HashMap<Depth, &GotoPlaceObject>` for the rewind
range, iterates current children, calls `remove_child` (full UNLOAD
lifecycle) for non-survivors via `survives_rewind`.

**Bug B — cached `MovieClip*` reuse on placement.**
`findOrCreateMovieClip` returns one `MovieClip*` per `(name, parent)`
pair from `child_mc_cache`. Same name+parent → same pointer → same
`dynamic_props` ASObject. When a NEW Bug ctor runs `this.c =
_global.c++` on the cached pointer, it overwrites OLD's `c=N-1` with
`c=N`. OLD's deferred `onUnload` then reads `this.c=N` instead of the
expected `c=N-1`.

Ruffle doesn't have this bug because each placement creates a fresh
`DisplayObject` (different ARC pointer). The `<MovieClip as
DisplayObject>::name` returns a string for lookup but each instance
has its own `Avm1Property` storage.

**The interaction.** If Bug A is fixed without Bug B, the deferred
UNLOAD now fires (good!) but reads the wrong `c` value (bad — visible
in our 2026-05-03 attempt as `dynamic unload: 1` instead of `dynamic
unload: 0`). If Bug B is fixed without Bug A, no UNLOAD events fire at
all (the silent-clear still drops them). Both must be fixed together.

## Candidate path-forward analysis

### Option 1: Per-placement MC identity (sub-options A and B)

**Premise.** Each placement that doesn't survive rewind allocates a
NEW `MovieClip*` with NEW `dynamic_props`. OLD remains reachable by
direct pointer (e.g. via `PendingTimelineUnload->mc`) until its
deferred handler drains.

**Sub-option 1A — multi-MC-per-(name,parent) cache.**
`child_mc_cache` becomes a list of MCs per name+parent. New
placements push a new MC; lookups return the most recent. Removed/
displaced MCs stay in the list but are skipped by future lookups.

- Pros: cleanest semantic fit with Flash/Ruffle.
- Cons: large surgery to `findOrCreateMovieClip` and every cache
  consumer (~40+ sites in `action.c`/`tag.c`). High blast radius.
  Memory: every placement leaks an MC until its handler drains.
- Estimate: 6-10 hours, very high risk of breaking unrelated tests.

**Sub-option 1B — shadow MC at queue time.** When
`queue_pending_finalize_mc` runs, allocate a new MC, deep-copy OLD's
`dynamic_props` to the shadow, and rewrite the
`PendingTimelineUnload->mc` and `PendingClipAction->mc` pointers to
the shadow. The original cache slot is freed for reuse.

- Pros: localized to the queue site. Existing cache machinery
  unchanged.
- Cons: deep-copying `dynamic_props` is non-trivial — recursive over
  an ASObject graph that may contain functions, prototypes, and
  cyclic refs. Functions stored on `this` (e.g.
  `this.onUnload = function(){...}`) capture closures by pointer; the
  shadow needs the same closure for the handler to reference its `c`
  field correctly.
- Estimate: 4-6 hours but with surprising edge cases (closures, getter/
  setter properties, circular `__proto__` chains). Likely needs a
  follow-up to handle cases not covered by ActionOrderTest3.

**Verdict.** Both sub-options have high risk. 1B is smaller-scope but
the deep-copy semantics are likely to leak bugs into unrelated
addProperty/getter tests.

### Option 2: Snapshot at queue time (single-field)

**Premise.** Rather than copying `dynamic_props`, snapshot only the
specific properties the handler will read. For ActionOrderTest3's
`'dynamic unload: ' + this.c`, that's just `this.c`.

- Pros: trivial to implement for a known test pattern.
- Cons: completely ad-hoc. The handler is user-authored
  ActionScript — we cannot statically determine which properties it
  reads. Any test where `onUnload` reads more than one property, or
  reads a field set by a method, would still fail. Not a real fix.

**Verdict.** Reject. Even if we cherry-picked `c`, the next test that
reads two fields would fail again, and we'd be back to needing
Option 1 or 3.

### Option 3: Replicate Ruffle's `run_goto` rewind path (Approach B from the previous plan)

**Premise.** The recompiler emits per-sprite per-frame placement
tables (`(depth, char_id, ratio)` tuples). At sprite loop-back, the
runtime iterates these tables to compute `final_placements` for the
rewind range, walks the current display_list, and removes
non-survivors with full UNLOAD lifecycle.

- Pros: structurally correct. Exactly matches Ruffle's `run_goto`
  semantics. Same-char same-depth placements survive (no UNLOAD); only
  differing-char or absent-depth placements remove. Solves Bug A
  cleanly. Sets up the framework for future goto-related fixes.
- Cons: requires recompiler-side metadata emission. Introduces new
  per-sprite static data. Runtime-side iterator + survives_rewind
  predicate are non-trivial but well-bounded.
- Estimate: 6-8 hours per the previous plan's estimate, plus regression
  battery validation against existing sprite-rewind tests
  (`loop_test2/3/4/5/8`, `reverse_execute_PlaceObject2_test1/2`).

**Verdict.** This is the structurally-right answer for Bug A. It does
NOT by itself fix Bug B — but it minimizes Bug B's exposure: only
non-surviving placements take the fresh-MC path, and surviving
placements keep their existing MC (so existing tests that rely on
identity continuity don't regress).

## Recommended plan: Option 3 + minimal Option 1B

The recommendation is to **land Option 3 first** to fix Bug A, then
follow up with **a narrow Option 1B-style fix** scoped only to the
non-survivor branch of the new `survives_rewind` machinery.

The phased breakdown below assumes this layering.

---

## Phases

### Phase 1: Recompiler emits per-sprite per-frame placements table

**Goal.** Each sprite gets a static array of `FramePlacement` entries
covering all `PlaceObject2/3` calls per frame, plus a per-frame index
range so the runtime can ask "what does sprite S place during frame F?"

**File.** `SWFRecomp/src/swf.cpp` — extend the existing sprite frame
emission (`sprite_definitions` stream, around line 5230 where
`frame_funcs` is generated).

**New static data.**

```c
// Per-sprite per-frame placement metadata. One entry per PlaceObject2/3
// inside the sprite's frame body. Used by ng_advance_sprite_frames to
// compute survives_rewind at loop-back.
typedef struct {
    u16 depth;
    u16 char_id;       // 0 means "Modify" (no char_id specified)
    u16 ratio;
    u8  has_clip_actions;  // 0 or 1
} FramePlacement;

extern FramePlacement sprite_42_placements[];
extern u16 sprite_42_frame_starts[];  // cumulative offsets into sprite_42_placements; size = sprite_frame_count + 1

// Indexing: placements for frame F are sprite_42_placements[sprite_42_frame_starts[F]
// .. sprite_42_frame_starts[F+1]].
```

**Recompiler changes.**

1. Inside the per-sprite tag-walking loop (around `case SWF_TAG_PLACE_OBJECT_2`
   in the sprite branch, ~line 4391):
   - Push a `FramePlacement` entry to a `vector<FramePlacement>` keyed by
     the current `sprite_frame_i`.

2. After the sprite's `frame_funcs` array is emitted (line 5230-5236):
   - Emit `FramePlacement <sp>_placements[] = { ... };`
   - Emit `u16 <sp>_frame_starts[] = { 0, ... };` cumulative.

3. Register with the runtime via a new tag-init call:
   ```cpp
   tag_init << "\ttagSetSpritePlacements(" << sprite_id << ", "
            << sp << "_placements, " << sp << "_frame_starts, "
            << to_string(sprite_frame_i) << ");" << endl;
   ```

**Runtime registration.** Add a new tag-init function:

```c
// SWFModernRuntime/src/libswf/tag_stubs.c (or tag.c)
typedef struct {
    FramePlacement* placements;
    u16* frame_starts;
    u16 frame_count;
} SpritePlacementTable;

static SpritePlacementTable* g_sprite_placement_tables = NULL;
static u32 g_sprite_placement_table_capacity = 0;

void tagSetSpritePlacements(u16 sprite_id, FramePlacement* p, u16* fs, u16 fc) {
    // Resize as needed, store pointers indexed by sprite_id.
}

// Lookup helper:
const FramePlacement* ng_sprite_frame_placements(u16 sprite_id, u16 frame, u16* count) {
    // Returns pointer to first placement and count; NULL if no table.
}
```

**Storage.** ~10 bytes per `FramePlacement`, average sprite has ~3-5
placements per frame, average sprite has ~10 frames → ~150-300 bytes
per sprite. Negligible.

**Validation.** No behavior change yet — just new metadata. Tests
should be unchanged.

### Phase 2: Replace silent-clear with survives_rewind iteration

**Goal.** At sprite loop-back, run a Ruffle-faithful rewind:
1. Collect `final_placements` for the rewind range (frame 0 through
   target frame, but for natural-wrap target = 0, only frame 0).
2. Iterate current `display_list[1..max_depth]`.
3. For each entry: compute `survives_rewind`. If yes, leave it
   (frame 0's PlaceObject2 will modify it). If no, queue UNLOAD
   lifecycle and clear the slot.
4. After the iteration, run frame 0's tag function as normal — its
   PlaceObject2 calls will hit existing-survivor entries (modify
   path) or empty entries (fresh place path).

**File.** `SWFModernRuntime/src/libswf/tag.c` — replace the silent
clear at lines 872-885 in `advance_sprite_frames`.

**`survives_rewind` predicate.**

```c
// Returns 1 if existing entry at depth survives the rewind to target_frame.
// Mirrors Ruffle's MovieClip::survives_rewind (movie_clip.rs:1812).
static int sprite_survives_rewind(
    DisplayObject* entry,
    const FramePlacement* final_placements,
    u16 final_count,
    size_t depth)
{
    // Find the final placement at this depth.
    const FramePlacement* final = NULL;
    for (u16 i = 0; i < final_count; i++) {
        if (final_placements[i].depth == depth) {
            final = &final_placements[i];
            // Don't break — later placements at same depth override.
        }
    }
    if (final == NULL) return 0;  // Depth not placed in target → non-survivor
    if (final->char_id != 0 && final->char_id != entry->char_id)
        return 0;  // Different char → non-survivor
    if (final->ratio != entry->ratio)
        return 0;  // Different ratio → non-survivor
    return 1;
}
```

**Loop-back replacement.**

```c
if (frame == 0 && max_depth > 0) {
    // Look up frame 0's placements for this sprite.
    u16 final_count = 0;
    const FramePlacement* final_placements =
        ng_sprite_frame_placements(this_sprite_char_id, 0, &final_count);

    if (final_placements == NULL) {
        // No metadata (e.g. sprite from child SWF without recompilation).
        // Fall back to legacy silent-clear behavior to avoid regressions.
        // ... existing silent-clear code ...
    } else {
        // Ruffle survives_rewind iteration.
        for (size_t j = 1; j <= max_depth; ++j) {
            DisplayObject* entry = &display_list[j];
            if (entry->char_id == 0) continue;
            if (sprite_survives_rewind(entry, final_placements, final_count, j))
                continue;  // Frame 0 will re-place / modify this entry

            // Non-survivor: queue UNLOAD + clear slot.
            // This is the "fire UNLOAD on sprite loop-back" Phase 2 from
            // the prior plan, but now safely scoped to non-survivors only.
            queue_clip_action_unloads_for_entry(app_context, entry);
            if (entry->instance_name != NULL) {
                int has_unload = ng_compute_has_unload(j);
                MovieClip* sprite_mc = g_current_context;
                MovieClip* child_mc = actionFindOrCreateMovieClip(
                    app_context, entry->instance_name, sprite_mc);
                if (has_unload && child_mc != NULL) {
                    actionFireOnUnload(app_context, entry->instance_name, (int)j);
                    queue_pending_finalize_mc(child_mc, (int)j, j);
                } else {
                    actionInvalidateCachedMovieClip(app_context,
                        entry->instance_name, (int)j);
                }
            }
            // Free sprite_display_list and zero char_id.
            if (entry->sprite_display_list != NULL) {
                FREE(entry->sprite_display_list);
                entry->sprite_display_list = NULL;
            }
            entry->char_id = 0;
        }
        // Note: do NOT set max_depth = 0 here — survivors are still in
        // display_list[1..max_depth].
    }
}
```

**Validation tests** (must remain green):

- `loop_test2`, `loop_test3`, `loop_test4`, `loop_test5`, `loop_test8`
  (sprite loop-back with same-char survival).
- `reverse_execute_PlaceObject2_test1`, `reverse_execute_PlaceObject2_test2`.
- `avm1/unload`, `avm1/clip_events`, `avm1/issue_1104`,
  `avm1/bad_placeobject_clipaction`, `avm1/button_order`,
  `avm1/movieclip_in_removed_button`, `avm1/on_construct`.
- `avm1/goto_rewind1/2/3`.
- All `avm1/execution_order*`.

### Phase 3: Per-placement MC identity for non-survivors

**Goal.** Solve Bug B. After Phase 2, non-survivors have UNLOAD
queued via `queue_pending_finalize_mc`, which set
`mc->pending_finalize=1` (re-introducing the field). When frame 0's
fresh PlaceObject2 runs at the now-empty slot, `findOrCreateMovieClip`
must skip the pending_finalize MC and create a fresh one.

**This is exactly the 2026-05-03 attempt's `pending_finalize` flag.**
The reason it didn't fix RCT4 in the prior attempt was that it
triggered only on the `tagRemoveObject2` path; this plan fixes that by
having Phase 2's silent-clear replacement also queue via
`queue_pending_finalize_mc`. So pending_finalize *will* be set on OLD
during the silent-clear → fresh PlaceObject2 in frame 0 → fresh MC
allocated → NEW Bug ctor sets `c=N` on NEW's `dynamic_props`, OLD's
`c=N-1` is preserved.

**Files.**

1. `SWFModernRuntime/include/actionmodern/action.h`: re-add
   `u8 pending_finalize` to `MovieClip` (same as 2026-05-03 attempt).
2. `SWFModernRuntime/src/libswf/tag.c`: in `queue_pending_finalize_mc`,
   set `mc->pending_finalize=1`. Capture `g_current_sprite_obj` as
   `parent_obj` in `PendingFinalizeEntry`. In `run_pending_finalize`,
   swap `display_list` to `parent_obj->sprite_display_list` for the
   `clear_display_entry` call (architectural fix from the prior
   attempt). Clear `pending_finalize=0` after.
3. `SWFModernRuntime/src/actionmodern/action.c`: add
   `!child_mc_cache[i]->pending_finalize` to the
   `findOrCreateMovieClip` skip condition.

**This is a re-application of the 2026-05-03 attempt**, but layered
on top of Phase 2's working Bug A fix. Without Phase 2, this layer
alone gave +2 plan-target / -11 RCT4. With Phase 2 firing UNLOAD on
non-survivors via the queue path, RCT4's NEW Bug ctor allocates a
fresh MC and the off-by-one disappears.

### Phase 4: Regression battery

After Phases 1-3 land, validate against:

- **Plan-target tests:** ActionOrderTest3, ActionOrderTest4,
  ActionOrderTest5, loop_test6 — should improve significantly. Target:
  +30+ matching lines per test (these tests have 50+ lines in the tail
  that depend on UNLOAD ordering).
- **RegisterClassTest4:** must not regress below baseline 17/42, and
  ideally improves toward expected pass.
- **AVM1 sprite/lifecycle suite** (must remain 100%):
  `unload`, `unload_clip_event`, `unload_nested_child`, `clip_events`,
  `goto_rewind1/2/3`, `goto_frame*`, `set_interval`, `on_construct`,
  `register_and_init_order`, `bad_placeobject_clipaction`,
  `button_order`, `issue_1104`, `movieclip_in_removed_button`.
- **Sprite loop-back battery** (must remain 100%):
  `loop_test2/3/4/5/8`, `reverse_execute_PlaceObject2_test1/2`.
- **Goto/execution-order battery** (must remain 100%):
  `execution_order1/2/3/4`, `goto_execution_order2`.
- **register_class:** other RegisterClassTest variants
  (`RegisterClassTest1/2/3/5`).

## Out of scope

- AS3 child placements (we don't run AS3).
- `goto_remove_object` semantics for explicit `RemoveObject` tags
  inside the rewind range. Phase 1's metadata can be extended later if
  this becomes blocking.
- CSM_TEXT_SETTINGS and other non-Place tags. Sprite rewind only cares
  about Place/Remove.

## Open questions

1. **Do we need explicit Remove tags in the placements table?** Ruffle
   processes them in `goto_remove_object` to remove entries from
   `goto_commands`. For SWFRecomp, our recompiled C function calls
   `tagRemoveObject2(depth)` directly inside frame_N. If we run frame
   0 as code (not as data) after the survives_rewind iteration, the
   RemoveObject tags execute naturally. But if we want survives_rewind
   to consider them (e.g. a frame_0 that places-then-removes the same
   depth → final state is empty → entry is non-survivor), we'd need
   to track Remove tags in the metadata. **Recommendation: track
   Remove in the metadata for Phase 1, but defer using it to a
   follow-up if the basic Place-only metadata gets the plan-target
   tests to pass.**

2. **What about `gotoAndPlay(2)` from root that wraps mc3?** This
   isn't a sprite natural advance — it's a root goto routed through
   `ng_executeGotoCatchUp`. The catch-up replay re-enters
   `tagPlaceObject2` with `catch_up_backward=1`. The existing
   survives-rewind logic at `tag.c:4099-4149` handles that case. We
   need to verify that path also benefits from Phase 1's metadata, or
   whether it's already adequate. **Likely already adequate** — the
   existing logic walks the tags directly and doesn't need a separate
   final_placements table.

3. **Per-sprite metadata size.** For a movie with 100 sprites averaging
   10 frames, we'd emit ~1500 bytes of static `FramePlacement` data.
   Acceptable. If a stress test pushes this much higher, switch to
   16-bit indices into a global pool.

## Estimated effort

Phase 1 (recompiler): 3-4 hours.
Phase 2 (runtime survives_rewind): 3-4 hours including initial validation.
Phase 3 (pending_finalize re-add): 1-2 hours (well-trodden ground).
Phase 4 (regression battery): 2-3 hours.

Total: ~10-13 hours. Larger than the original `INTER_TAG_UNLOAD_PLAN`
estimate of 2-3 hours, but addresses the root cause structurally and
sets up future goto-related fixes.

## Why this should work where prior attempts failed

The prior attempts all tried to retrofit the silent-clear path with
UNLOAD queueing (Phase 2 Approach A) or MC isolation
(`pending_finalize`) without addressing the underlying lack of
survives_rewind logic. They suffered the symmetric trade-off: queueing
fired the UNLOADs at the cost of regressing same-char-survives tests
(or RCT4), and isolation alone didn't activate without a queue point.

This plan resolves the trade by:
- Phase 1 + Phase 2 = supplying the missing survives_rewind logic, so
  Phase 2's UNLOAD queueing only fires for actual non-survivors.
- Phase 3 = the MC isolation kicks in for the non-survivor path,
  giving NEW placements fresh `dynamic_props`.

Surviving same-char placements never enter the queue path, so they
never trigger MC isolation, so they keep their existing identity.
That's how Ruffle handles it, and it should resolve the trade family
that has blocked four prior attempts.

## Related plans

| Doc | Relationship |
|-----|--------------|
| `blocked/INTER_TAG_UNLOAD_PLAN.md` | Predecessor — four narrow attempts, all blocked by the trade family this plan resolves. |
| `incomplete/SPRITE_EXEC_LIST_LIFO_PLAN.md` | Sibling — Phase 2's UNLOAD ordering interacts with sprite advance ordering. |
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Grandparent. The `queue_pending_finalize_mc` infrastructure used by Phase 2 originates from this plan. |
| Ruffle source: `core/src/display_object/movie_clip.rs::run_goto` (1546-1696, with `survives_rewind` at 1812). | Reference implementation we're mirroring. |
