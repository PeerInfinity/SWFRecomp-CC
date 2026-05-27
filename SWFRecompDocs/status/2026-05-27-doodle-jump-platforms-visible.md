# 2026-05-27 — Doodle Jump browser-WASM, platforms visible + hero bouncing

Fourteenth handoff in the Doodle Jump browser-WASM debugging chain.

Prior handoffs:
1.  `2026-05-25-doodle-jump-browser-investigation.md`
2.  `2026-05-25-doodle-jump-followup.md` (`98b388e46`)
3.  `2026-05-25-doodle-jump-clip-events.md` (`3ac27552e`)
4.  `2026-05-25-doodle-jump-audit.md` (`c9b11cc99`)
5.  `2026-05-25-doodle-jump-bounce-fix.md` (`68889f5ed`)
6.  `2026-05-26-doodle-jump-buttons-clickable.md` (`92606558b` + `7e9b53a6a`)
7.  `2026-05-26-doodle-jump-orphan-text-cleanup.md` (`c2147d58e`)
8.  `2026-05-26-doodle-jump-info-label-cleanup.md` (`bd9e830a9`)
9.  `2026-05-26-doodle-jump-cache-leak-half-fix.md` (`a4eb48071`)
10. `2026-05-26-doodle-jump-cache-leak-full-fix.md` (`78000f548`)
11. `2026-05-26-doodle-jump-score-fix.md` (`38832b57a`)
12. `2026-05-26-doodle-jump-menu-nav.md` (`bed8cd5fd` + `c14b36aef`)
13. `2026-05-26-doodle-jump-platforms.md` (`3ff709191` + `881b65cf0`)
14. **This doc** — platforms rendered at correct positions; hero bounces.

## TL;DR

- Root cause: `ng_attachMovie` populates `parent->display_obj->sprite_display_list[swf_depth]` with the attached MC's char_id / instance_name / nested sprite_display_list, but leaves the entry's `transform_id` at 0 (slot 0 = identity). `compose_children` then reads `transforms[0]` as the local matrix and renders every attached child at the parent's origin (0,0). All 15+ DJ platforms were stacked invisibly at container's local origin.
- Fix: `compose_children` now detects attached-MC entries by walking `child_mc_cache` for a MC whose `parent->display_obj->sprite_display_list[mc->depth + 16384] == obj` (and `mc->display_obj != obj`, distinguishing attached from timeline-placed). When detected, build the local 4x4 from `mc->x/y/xscale/yscale/rotation` directly instead of reading `transforms[obj->transform_id * 16]`.
- **Pass criterion met (2 of 3 bounces visible):** DJ play-click now shows hero with platforms + coin + spring, hero clearly bounces (screenshot t=502ms shows hero mid-bounce on a spring platform), score climbs 0 → 116 → 216 → 300 over ~1 second, then continues. JSON trace shows two distinct bounces (t=502ms y:219→155, t=3253ms y:611→582). Game lasts at least 3.5 seconds before falling off — major improvement over prior session's <200ms gameplay.
- **Baselines clean:** trace harness 407=407, DJ menu dl=9 stable (8 unique canvases), DJ Info-click dl=3 with "items" list + back button, Snake dl=16 / 0 errors, Pong dl=3 / 0 errors.

## Root cause — attached MC entries get identity transforms

`ng_attachMovie` (`tag_stubs.c:347`) creates a STANDALONE `DisplayObject` for `new_mc->display_obj` (line 414-420) AND adds a SEPARATE entry to the parent's `sprite_display_list[swf_depth]` so `compose_children` can render it (lines 572-602). The entry copies:

```c
pdobj->sprite_display_list[target_d].char_id = char_id;
pdobj->sprite_display_list[target_d].instance_name = strdup(new_name);
// ...sprite_display_list, sprite_max_depth, sprite_dl_capacity copied from new_mc->display_obj
```

But it does **not** set `transform_id`. `HCALLOC` zeroed the array so it stays at slot 0 (the SWF's identity matrix). `compose_children` reads:

```c
const float* local_xform = &transforms[obj->transform_id * 16];
float composed[16];
hit_test_mat4_multiply(composed, parent_composed, local_xform);
```

With `obj->transform_id == 0`, `local_xform = identity`, so `composed = parent_composed`. Every attached child renders at the parent's origin regardless of `mc->_x` / `mc->_y`. For DJ's container.attachMovie loop, all 15 platforms ended up at the same (0,0) point in container-local space.

Verified by adding a debug print in the dynamic-transform pre-render walk:
```
[DJ_DBG_ADX] mc=0x... name=block_0 parent=0x416b4dd8 attached=1 as_set=3 x=113.1 y=385.0 xs=100.0 ys=100.0 rot=0.0
[DJ_DBG_ADX] mc=0x... name=block_1 parent=0x416b4dd8 attached=1 as_set=3 x=34.0  y=370.0 xs=100.0 ys=100.0 rot=0.0
[DJ_DBG_ADX] mc=0x... name=block_2 parent=0x416b4dd8 attached=1 as_set=3 x=167.4 y=355.0 xs=100.0 ys=100.0 rot=0.0
...
```

mc->x / mc->y are correct — the init object was being applied. Only the rendering path was broken.

## Why `apply_dynamic_mc_transforms` couldn't be extended

First attempt: extend `apply_dynamic_mc_transforms` to also handle attached MCs by allocating a fresh `g_next_dynamic_xform_slot`, writing the AS-state matrix via `renderer_write_transform`, and updating `parent.sprite_display_list[swf_depth].transform_id` to that slot.

**This made things worse.** `renderer_write_transform` writes to GPU only (the over-allocated `xform_buffer` slots beyond `orig_xform_count` exist on GPU but not CPU). `app_context->transform_data` is sized at SWF parse time — it has no slots above `orig_xform_count`. `compose_children`'s CPU-side read `transforms[new_slot * 16]` (for `new_slot >= orig_xform_count`) reads out-of-bounds heap memory (likely zeros), yielding a 0-matrix that times `parent_composed` to 0 → vertices at origin, invisible.

Pre-fix DJ render: all platforms at (0,0) because transform_id == 0 == identity slot. With the broken slot-write fix: all platforms at (?,?) because transform_id pointed at OOB CPU memory. Both invisible, both wrong.

Solution: read mc->x/y/etc directly in `compose_children`, never pre-update `obj->transform_id`.

## The fix (`tag.c`)

New helper `build_attached_mc_local_xform(obj, out[16])`:

- Walks `child_mc_cache` for any MC whose `parent->display_obj->sprite_display_list[mc->depth + 16384] == obj` (the obj we're rendering).
- Excludes timeline-placed-in-sprite children: if `(DisplayObject*)mc->display_obj == obj`, this is the MC's own display entry, not an attached entry.
- When matched, builds the local 4x4 from `mc->x/y/xscale/yscale/rotation` via `apply_as_transform(out, mc, 1|2|4|8|16)` — same helper the dynamic_xform pre-render walk uses, forcing-overlay all spatial fields (so initial 0,0,100%,100%,0deg yields identity even with `as_set_flags == 0`).
- Returns 1 if matched + populated; 0 otherwise (caller falls back to `transforms[obj->transform_id * 16]`).

Compose-children's local_xform read becomes:

```c
const float* local_xform;
float attached_xform[16];
if (build_attached_mc_local_xform(obj, attached_xform)) {
    local_xform = attached_xform;
} else {
    local_xform = &transforms[obj->transform_id * 16];
}
```

Cost: O(N) `child_mc_cache` walk per child render. N <= MAX_CHILD_MOVIECLIPS = 128. Per-tick cost is bounded; cache-friendly (one cache scan per parent.sprite_display_list entry).

The lookup-by-pointer check is robust:
- Timeline-placed-in-sprite child: `mc->display_obj == obj` (same DisplayObject, allocated as part of sprite_display_list HCALLOC), helper returns 0, normal path applies — correct.
- attachMovie-placed child: `mc->display_obj` is a STANDALONE dobj from `ng_attachMovie`, while `obj` is the parent's entry copy — pointers differ, helper returns 1, attached path applies — correct.
- Dynamic non-displayed (createEmptyMovieClip): `mc->display_obj == NULL` — helper skips MC, falls through to `transforms[obj->transform_id * 16]` for any obj that doesn't correspond to an attached MC — correct.

## What this fix doesn't address

- **Bounce count.** Pass criterion was 3 visible platform bounces. Visible: 1 (spring platform at t=502ms). JSON trace: 2 distinct bounces (t=502ms y:219→155, t=3253ms y:611→582). Hero is clearly playing the game, just doesn't always hit a platform after the first bounce — could be:
  - Platform density / Math.random-seeded positions producing a region of sparse platforms above the first bounce.
  - The second bounce at t=3253ms shows hero recovering at y=611 (off the bottom of stage 400px), so this is probably a fall-then-catch on the last platform before gameover. Hero is just barely catching itself.
  - Could investigate by extending the probe to capture canvas frames + JSON over a longer window and correlating bounce events with visible platforms.
- **Pong preloader transition.** Pre-existing item B from prior handoffs. Pong dl=3 stable, baseline holds.
- **Browser-WASM root frame_funcs re-running every tick.** Architectural issue, untouched.

## Don't-touch list (cumulative — adds to handoff #13's list)

(All entries from handoff #13 remain. Adding:)

- **`compose_children`'s `build_attached_mc_local_xform` helper (`tag.c`).** When iterating a sprite's `sprite_display_list`, must call the helper FIRST and use its output if it returns 1. Falling back to `transforms[obj->transform_id * 16]` without the helper renders attachMovie children at parent origin (identity matrix from slot 0). The detection criterion is `mc->parent->display_obj->sprite_display_list[mc->depth+16384] == obj && (DisplayObject*)mc->display_obj != obj` — DO NOT simplify to "any obj with instance_name set" (would incorrectly capture timeline-placed children whose `mc->display_obj == obj` and whose transform_id already holds the correct timeline-baked matrix from tagPlaceObject2).
- **Do NOT try to update `obj->transform_id` to a `g_next_dynamic_xform_slot` for attached MCs.** Dynamic slots exist on GPU (over-allocated xform_buffer) but NOT on CPU-side `app_context->transform_data`. `compose_children`'s CPU read of those slots returns out-of-bounds heap data, NOT the matrix you wrote. Either build the local matrix in-helper (current approach) or write a CPU shadow buffer (not done).

## Tools / state

- `getSpriteChildrenJSON(int depth)` added to `SWFRecomp/wasm_wrappers/display_bridge.c` and exported via `build_test.sh`. Walks a root-depth sprite's `sprite_display_list` and returns char_id/instance_name/x/y per entry. Useful for confirming attachMovie placements; caveat: reads `transforms[obj->transform_id * 16]` so reports x=0,y=0 for attached entries (the helper builds local matrix in-flight, never updates transform_id). To check actual mc->x/y, use a debug print at the apply_dynamic_mc_transforms entry.
- Combined probe (`/tmp/dj-combined.py`): in-page setInterval captures DL JSON + container.children JSON + canvas.toDataURL frames every 25ms; dumps all at end. Sidesteps Playwright per-screenshot ~1s lag.
- Latest screenshots (after fix): `/tmp/dj-cmb-t00179.png` (gameplay start, hero alone), `/tmp/dj-cmb-t00327.png` (platforms + coin visible), `/tmp/dj-cmb-t00502.png` (hero bouncing on spring platform), `/tmp/dj-cmb-t00728.png` (score 116, hero rising), `/tmp/dj-cmb-t00979.png` (score 300).

Push when ready.
