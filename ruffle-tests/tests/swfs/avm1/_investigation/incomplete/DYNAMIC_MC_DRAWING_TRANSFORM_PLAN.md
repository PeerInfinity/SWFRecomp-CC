# Dynamic-MC Drawing-API Transform Plan
<!-- TESTS: BeginBitmapFill (from_gnash/misc-ming.all) -->

<!-- PLAN_META
id: DYNAMIC_MC_DRAWING_TRANSFORM
status: not_started
phases:
  - id: 1
    name: "Allocate dynamic GPU transform slots for dynamic MCs with as_set_flags"
    status: not_started
  - id: 2
    name: "Route per-path transform_id through fillDrawingInfos / drawing_render_cb"
    status: not_started
  - id: 3
    name: "Verify BeginBitmapFill mc2 + other dynamic-MC transform.matrix tests"
    status: not_started
dependencies:
  - plan: RUNTIME_TRANSFORM_GPU
    type: requires
    reason: "Reuses apply_as_transform helper and dynamic-slot allocator infrastructure"
blockers: []
-->

Last updated: 2026-05-14

## Status: NOT STARTED

## Problem

When a *dynamic* MovieClip (created via `createEmptyMovieClip` /
`duplicateMovieClip` / `attachMovie`) has Drawing-API paths and gets its
position/transform changed via AS — including `transform.matrix =
new Matrix(...)` — the GPU transform fed to the drawing path is never
rebuilt, so the drawing renders with an identity (or stale placement)
transform.

`RUNTIME_TRANSFORM_GPU_PLAN` solved the equivalent problem for *placed*
sprites: `tagShowFrame` / `tagRerenderFrame` walk `display_list[i]`,
match the entry to an MC, and rewrite the GPU slot in-place. Dynamic
MCs aren't in `display_list` (they live in `child_mc_cache`), so that
loop never touches them.

## Affected Image Tests

| Test | Suite | Symptom |
|------|-------|---------|
| BeginBitmapFill | from_gnash/misc-ming.all | mc2 diagonal-stripe block (`transform.matrix = new Matrix(2, -1.3, 2.4, 1, 20, 200)`) is missing entirely from the rendered frame; ~18k outliers |

Other dynamic-MC drawing + transform tests likely benefit downstream.

## Root Cause

1. Drawing paths for dynamic MCs are rendered by `actionIterateDrawings`
   in `SWFModernRuntime/src/actionmodern/action.c` (~line 24587). That
   walks `child_mc_cache[]`, calls `fillDrawingInfos` per MC, and hands
   each `DrawingRenderInfo` to the callback `drawing_render_cb` in
   `tag.c` (~line 2767), which immediately calls `render_drawing_path`.

2. `fillDrawingInfos` (action.c:24524) sets
   `info->transform_id = mc->last_transform_id;`. For a
   `createEmptyMovieClip` MC, `last_transform_id` is whatever the static
   placement matrix was — typically slot 0 (identity).

3. Even when `transformMatrixSetter` updates `mc->x/y/xscale/yscale/
   rotation/skew` and sets `mc->as_set_flags`, no code path rebuilds
   `transform_data[last_transform_id]` or allocates a fresh slot, so
   the renderer keeps using the original.

4. `apply_as_transform` (tag.c:1266) exists and handles the
   reconstruction correctly (including the 2026-05-14 skew fix), but
   it's only invoked from `display_list`-iterating loops.

## Implementation Plan

### Phase 1 — Allocate dynamic GPU transform slots for dynamic MCs

Before the drawing render pass in `tagShowFrame` /
`tagRerenderFrame`, walk `child_mc_cache[]` (via a new
`actionIterateDynamicMCsForTransform` helper in action.c, or inline if
the iteration helper already exists).

For each `mc` where `mc->as_set_flags != 0`:

- Allocate a fresh dynamic slot (`g_next_dynamic_xform_slot++`).
- Build the 16-float matrix via `apply_as_transform` applied on top of
  an identity slot (or directly using the existing
  `getLocalMatrixForMC_render` logic in action.c which already
  composes rotation+skew).
- Write the slot via `renderer_write_transform`.
- Stash the slot ID on the MC (new field `mc->dynamic_xform_slot` or
  reuse a transient field) so `fillDrawingInfos` can pick it up.
- Track for restoration through the existing `xform_overrides` machinery
  (or a parallel restore loop, since these slots are MC-keyed not
  DisplayObject-keyed).

### Phase 2 — Route per-path transform_id through fillDrawingInfos

In `fillDrawingInfos` (action.c:24581), replace:

```c
info->transform_id = mc->last_transform_id;
```

with:

```c
info->transform_id = (mc->as_set_flags != 0 && mc->dynamic_xform_slot != 0)
    ? mc->dynamic_xform_slot
    : mc->last_transform_id;
```

After the render pass, reset `mc->dynamic_xform_slot = 0` so subsequent
ticks re-allocate a fresh slot. (Slots are tick-scoped per the existing
dynamic-slot allocator semantics.)

### Phase 3 — Verify

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all \
  --test=BeginBitmapFill --mode=graphics --diff --verbose
```

Regression-check the sibling drawing tests that already pass:

- `movieclip_begin_gradient_fill` (was failing pre-this-plan for an
  unrelated reason — verify the outlier count doesn't move)
- `movieclip_line_gradient_style` (same)
- `bitmap_data_draw_cliprect`, `bitmap_data_fillrect`,
  `duplicate_movie_clip_drawing`, `mask_with_drawing`
- `display_object_properties`, `color`

## Design Considerations

1. **mc->last_transform_id vs dynamic slot.** Don't overwrite
   `last_transform_id` itself — other code (e.g. PlaceObject2 decompose
   guard at action.c:23158) reads it for "has this transform changed
   since last sync" detection. Use a separate transient field that's
   cleared per tick.

2. **Parent transform composition.** Dynamic MCs created on `_root`
   should compose against `_root`'s transform (identity in most tests).
   Dynamic MCs created inside another sprite (via `mc.createEmptyMovieClip`)
   should compose against the parent's *current* composed transform.
   `compose_children` handles the nested case for placed sprites — we
   need an equivalent pass for dynamic children. Possibly: after
   composing the parent sprite, walk its dynamic children too.

3. **Identity fast path.** Skip allocation entirely when
   `as_set_flags == 0` — the existing `last_transform_id` is correct.

4. **Bitmap fill matrix interaction.** `info->bitmap_matrix` is a
   separate per-path matrix that maps source bitmap coordinates to
   shape-space; the parent MC transform composes *outside* that
   (shape-space → world-space). The two are orthogonal; the proposed
   change only affects the outer transform.

## Estimated Complexity

Low-medium. ~50-80 LOC across action.c (iteration helper, struct field,
fillDrawingInfos override) and tag.c (pre-render dynamic-MC walk in
both `tagShowFrame` and `tagRerenderFrame`).

## Out of Scope

- AS-driven transform on placed sprites — handled by
  `RUNTIME_TRANSFORM_GPU_PLAN` (complete).
- Color transforms on dynamic MCs (`Color.setRGB` etc.) — similar
  problem for cxforms; track separately if a test exercises it.
- Sprite-content rendering (vs Drawing-API content) on dynamic MCs —
  dynamic MCs created via `attachMovie` from a Library symbol have
  sprite content, which goes through a different render path
  (`render_display_list` on `obj->sprite_display_list`). Verify whether
  that path already handles `as_set_flags` correctly when the dynamic
  MC's sprite shows up in the parent's display list.
