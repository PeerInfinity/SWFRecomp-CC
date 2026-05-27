# 2026-05-27 — Snake gameplay clones now visible (Bug B from 2026-05-27 handoff)

Follow-up to `2026-05-27-snake-countdown-gameover.md` (HEAD `217f8cc86`).
Snake's gameplay clones now render and move visually across the play field
during play. Score still 0 (game can't be played without keyboard input from
the probe), but the visible snake column makes the game state observable.

## TL;DR

Three runtime changes to wire AVM1 opcode `duplicateMovieClip` (`actionCloneSprite`,
0x24) through to the browser-WASM graphics renderer, plus one fix so clones
actually pick up their AS-set positions.

- **Fix 1 (`SWFModernRuntime/src/actionmodern/action.c`):** Widen
  `actionCloneSprite`'s dispatch gate. Drop the `cloneMovieClip(...)` no-op
  stub branch (and the stub itself); all three build modes (NO_GRAPHICS /
  OFFSCREEN_RENDER / browser-WASM graphics) now route to the same
  `ng_cloneSprite` / `ng_cloneSpriteFromMC` + `child_mc_cache` primitives.
  Same precedent as `actionRemoveSprite` per the e0568fe7 widening — but
  taken one step further (no stub remains). Added `extern int
  g_clone_depth_already_unbiased;` declarations so the variable resolves in
  browser-WASM where it's defined in `graphics_stubs.c`. Un-gated
  `actionMarkCloneStripped`'s setter so the recompiler-emitted Phase 2a
  marker works in all modes.

- **Fix 2 (`SWFModernRuntime/src/libswf/tag_stubs.c`):** In `ng_cloneSprite`
  and `ng_cloneSpriteFromMC`, gate the `display_list[target_swf_depth] =
  display_list[src_depth]` struct-copy block on `NO_GRAPHICS ||
  OFFSCREEN_RENDER`. Browser-WASM skips this block. Reason: the struct copy
  makes the clone's `DisplayObject` share `transform_id` with the source,
  and tag.c's runtime-transform-update loop (`tag.c:~3070`) then mutates the
  shared `transform_data[transform_id]` slot every tick — for whichever
  display entry it processes last — corrupting the source MC's stage
  transform. Concrete symptom in Snake: the play-area border (a child of
  Snake's sprite, composed through Snake's slot) shifted up-and-left to
  wherever the last snake clone's `_x`/`_y` happened to land. Browser-WASM
  renders clones exclusively through the `child_mc_cache` loop (the same
  path attachMovie uses) — that loop builds a fresh local `mc_xform` per
  clone, no shared mutation. NO_GRAPHICS and OFFSCREEN_RENDER still need the
  display_list write for name lookups / instance walks; their renderers
  (trace = no rendering, graphics-native = different transform model) don't
  hit the shared-slot mutation.

- **Fix 3 (`SWFModernRuntime/src/libswf/tag.c:~3948`):** Drop the
  `if (mc->as_set_flags != 0)` gate before `apply_as_transform` in the
  child_mc_cache render loop. Always overlay `mc->x`/`mc->y`/`xscale`/
  `yscale`/`rotation` for clones rendered via this path. Reason: AVM1
  opcode `SetProperty` (0x23, used by Snake's `script_14.c:84-97` to place
  every snake segment with `_x`/`_y`) writes `mc->x`/`mc->y` but in
  browser-WASM doesn't set `mc->as_set_flags |= 1|2` (that's gated on
  `NO_GRAPHICS || OFFSCREEN_RENDER` at `action.c:~52886`). With the gate
  intact, clones rendered at the composed identity (origin); the field
  looked empty. With the gate dropped, clones use their AS-set position —
  `mc->x`/`mc->y` always hold valid values (defaulting to 0; scales
  default to 100), so force-applying is safe for attachMovie / SetMember
  callers too (their AS-set-flag bits would have triggered the same apply
  anyway). DJ uses SetMember exclusively (0 `actionSetProperty` calls in
  any of its scripts) so it's unaffected.

I considered un-gating the `as_set_flags |= 1|2|4|8|16` writes in
`actionSetProperty` directly (matching what `actionSetMember` already does
unconditionally). That made Snake's snake segments visible, but
`apply_as_transform` in the runtime-transform-update loop (`tag.c:~3070`)
then mutated `transform_data[Food->transform_id]` in place for the food
MC's `_x`/`_y` SetProperty. If Food's transform_id was shared with any other
static placement (it usually is — the recompiler dedupes identity-ish
matrices), the play area got dragged to Food's random grid position. Fix 3
is narrower and avoids that whole shared-slot hazard. The `apply_as_transform`
shared-slot bug is real for any AS-set position on a non-clone in
browser-WASM, but right now no test in the corpus exercises it without
also opting into the un-gate; revisit if a follow-up surfaces it.

## How this looked end-to-end

Snake's `script_14` (gameplay-tick body, called from a frame action) creates
visible segments via `duplicateMovieClip("Snake", "<head>", 16384 + head)`
and then positions each one via `<head>._x = grid_x; <head>._y = grid_y`.
Food MC is a static timeline placement; the same script does
`SetTarget "Food"; Food._x = random_x; Food._y = random_y; SetTarget ""`.
Before today the entire dispatch silently no-op'd in browser-WASM —
`actionCloneSprite`'s wasm arm was `cloneMovieClip(...);` (stub at
`action.c:~20144` that just `(void)`'d its args). After Fix 1, clones are
created. After Fix 2, the source MC's transform isn't corrupted by the
struct-copy. After Fix 3, clones render at their AS-set positions through
the child_mc_cache path.

## Diagnostic walk-through

1. **Verified `ng_cloneSprite` symbols are linked in browser-WASM.**
   `tag_stubs.c` is built in all three modes (`build_test.sh:193`).
   Transitive deps (`g_clone_depth_already_unbiased`,
   `ng_queue_placement_clip_events`) are defined in `graphics_stubs.c`
   (some as no-ops, which is fine for Snake — no clip-event scripts on the
   Snake template).

2. **Verified rendering reaches clone depth.** `tag.c:3912-3955`
   iterates `child_mc_cache` post-display-list-render, gated on
   `mc->display_obj` being **outside** the global `display_list` array.
   `ng_cloneSprite` allocates `clone_mc->display_obj` via
   `calloc(1, sizeof(DisplayObject))` (a fresh heap block, outside the
   array). attachMovie clones already use this path successfully.

3. **First fix attempt landed clones but shifted the play area.** Tracing
   showed clones were created (`ng_cloneSprite returned 0x412f2490`, etc.)
   but the play-area border had drifted up-and-left during gameplay. Root
   cause: ng_cloneSprite's struct-copy of `display_list[src_depth]` to
   `display_list[target_swf_depth]` carried the source's `transform_id`
   over, and tag.c's per-tick `apply_as_transform` mutator (`tag.c:~3074`)
   then rewrote `transform_data[shared_slot]` every tick to whichever
   display entry was processed last. Snake's children (the play-area
   border) composed through Snake's slot, so they tracked the corruption.

4. **Second attempt was the un-gate of `as_set_flags` in SetProperty.**
   That made clones visible (their `_x`/`_y` actually applied) but also
   set as_set_flags on Food. Food's slot then got mutated in place, and
   any static placement sharing Food's transform_id moved with it.

5. **Final landing: skip display_list write for clones in browser-WASM
   (Fix 2) and force-apply mc->x/y in the child_mc_cache loop (Fix 3).**
   Clones never share transform slots with the source. Static placements
   stay put. Snake column visible at the grid origin and progressing down
   the field each tick.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`actionCloneSprite` and `actionMarkCloneStripped` are gate-less now**
  (`SWFModernRuntime/src/actionmodern/action.c:~53078` and `~53059`). All
  three build modes route to `ng_cloneSprite` / `ng_cloneSpriteFromMC`.
  **Do NOT** re-add a `cloneMovieClip` stub — the symbol no longer exists.
  Re-adding the gate would silently no-op `duplicateMovieClip` in
  browser-WASM (Bug B).

- **`ng_cloneSprite` / `ng_cloneSpriteFromMC` skip the
  `display_list[target_swf_depth] = display_list[src_depth]` copy in
  browser-WASM** (`SWFModernRuntime/src/libswf/tag_stubs.c:~2086` and
  `~2335`, gated on `defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`).
  **Do NOT** un-gate. Without the gate, clones share `transform_id` with
  the source and `tag.c:~3074`'s in-place mutation of
  `transform_data[shared_slot]` shifts the source MC's children (Snake's
  play area shifts to track the last clone's position each tick).

- **`tag.c:~3948` child_mc_cache loop force-applies `apply_as_transform`
  unconditionally** (no `as_set_flags != 0` gate). **Do NOT** re-add the
  gate. AVM1 opcode `SetProperty` (used by Snake's script_14) writes
  `mc->x` / `mc->y` but doesn't set the `as_set_flags` bits in browser-
  WASM (gated at `action.c:~52886`); with the gate, clones rendered at
  the composed identity (origin = invisible). `mc->x`/`mc->y` always hold
  valid values; force-applying is a no-op when nothing AS-set them
  (slot[12]=0 / slot[13]=0 collapses to identity).

## Baselines (all green at HEAD + this change)

- **Trace divergence (DJ):** 407=407 (identical), via
  `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle`.
- **DJ menu (no click, 8s probe):** title + 4 buttons centered, doodle
  character on the left, 0 errors.
- **DJ info subscreen:** click → "items" body renders, "mushroom: inverse
  control" not truncated.
- **Pong (4s probe):** loading screen with notebook background + "Glaiel
  Games.Com" handwritten signature intact, 0 errors.
- **Snake title:** "SNAKE", "CHOOSE LEVEL:", "SLUG WORM PYTHON", URL all
  correctly positioned.
- **Snake countdown (click slug):** "3" / "2" / "1" centered, "GO!"
  centered (Bug A fix from prior handoff still holds).
- **Snake gameplay (NEW):** snake segments visible during play —
  initial column of segments at center, growing each tick as the snake
  "moves" down (cloned segments accumulate because actionRemoveSprite
  is still a stub for browser-WASM — see Known limitations below).
- **Snake game-over:** "GAME" / "OVER" on two lines with the snake
  stretched across, SCORE / LEVEL bottom labels intact (Bug C fix still
  holds).

## Known limitations carried forward

- **No keyboard input from the probe → snake can't be steered.** Without
  arrow-key input it just goes forward until off-grid; score stays 0
  (snake never reaches food). The render is correct given the inputs.
  Manual play in a real browser is needed to see score climbing / food
  consumption end-to-end.

- **`actionRemoveSprite` (browser-WASM) is still a stub**
  (`SWFModernRuntime/src/actionmodern/action.c:~53318`). The wasm-graphics
  arm of the dispatch is `#ifdef DEBUG printf("would remove...")`; clones
  created via `actionCloneSprite` are never freed. During Snake gameplay
  this manifests as the snake column growing each tick (every "move"
  duplicates a fresh head; old tail segments never get removed because
  the `removeMovieClip(...)` call no-ops). Net: the snake looks like it's
  *extruding* rather than *moving*. The remove path uses the same
  `child_mc_cache` primitives as the create path — the e0568fe7
  precedent already widened the gate to include OFFSCREEN_RENDER, but
  not browser-WASM. Following the same pattern this handoff established
  for `actionCloneSprite` (gate-less dispatch + skip display_list
  writes) should be a small follow-up.

- **`apply_as_transform`'s shared-slot mutation is unfixed.** The
  per-tick `tag.c:~3074` loop still writes
  `transform_data[obj->transform_id]` in place when an MC has
  `as_set_flags != 0`. If two display entries share a transform_id (the
  recompiler dedupes identical matrices into one slot) and AS modifies
  the position of one, the other shifts too. Snake doesn't exercise it
  (Food's SetProperty leaves `as_set_flags` unchanged in browser-WASM
  per the gate at `action.c:~52886`). DJ doesn't exercise it (0
  `actionSetProperty` calls). But any browser-WASM SWF that mixes
  shared transform slots with AS-set positions on placements would
  surface this bug. The fix is a per-tick fresh-slot allocator for the
  3070 loop (mirroring the `apply_dynamic_mc_transforms` pattern at
  `tag.c:~1408` and `compose_children`'s `tag.c:~1526` block), gated on
  available GPU slot capacity. Substantial enough to be its own session.

- **`g_clone_depth_already_unbiased` is reachable but inert in
  browser-WASM right now.** `actionMarkCloneStripped` now sets it
  unconditionally, and `actionCloneSprite` reads it via `extern` — but
  the recompiler's "strip the `Push 16384 Add` prefix" optimization
  isn't triggered by Snake (which builds the SWF depth as a runtime
  add). If a future browser-WASM SWF triggers the stripped path, it
  should now interpret correctly without the gate.

## Tools / state

- 1 unpushed commit expected (3 files: action.c + tag.c + tag_stubs.c)
  plus this docs handoff (2 commits total).
- No new probes; the existing `/tmp/snake-play2.py`, the inline
  `/tmp/dj-menu-probe.py` / `/tmp/dj-play-probe.py` / `/tmp/pong-baseline-probe.py`
  / `/tmp/snake-title-probe.py` ad-hoc scripts I wrote during validation
  weren't committed (single-use diagnostic, follow the same pattern as
  the snake-play2 probe). The trace divergence command is the standard
  `tools/divergence/divergence_test.py` invocation from CLAUDE.md.
- Recompiler unchanged — runtime-only fix. No re-recompile of any test
  needed; just rebuild + redeploy individual demos.

Push when ready.
