# 2026-05-27 — Snake's food visible, stage no longer shifts (composite wasm fix)

Follow-up to `2026-05-27-snake-removesprite-makes-snake-move.md` (`2d792bde3`).
With Bug B's actionCloneSprite + actionRemoveSprite widenings in, the snake
moves correctly but the food MC was invisible — it sat at its static
timeline position (off-screen) because opcode-form `SetProperty _x/_y`
inside a `SetTarget "Food"` block silently routed to root rather than to
Food. With this change, Snake's gameplay shows the food at a random grid
position AND the play area stays correctly centered, the snake moves
toward whatever wall it's heading at.

## TL;DR

Three coupled runtime changes — no recompiler change. Each one is needed;
removing any of them breaks something (verified during diagnosis).

- **Fix 1 (`SWFModernRuntime/src/actionmodern/action.c:~19283`):**
  `getMovieClipByTarget("")` (empty target = "current execution context")
  was gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` to
  return `g_current_context`; browser-WASM fell through to the `#else`
  and returned `&root_movieclip` regardless of SetTarget state. This is
  the actual root cause of the play-area shift symptom — Snake's
  gameplay path is:

  ```actionscript
  SetTarget "Food";
  Food._x = randomGridX;   // opcode SetProperty, empty target
  Food._y = randomGridY;
  SetTarget "";
  ```

  Browser-WASM's `getMovieClipByTarget("")` returned root, so the
  SetProperty's `mc` was `root_movieclip` — and with Fix 2 below making
  the as_set_flags write unconditional, `root.as_set_flags |= 1|2` got
  set with `root.x = randomGridX, root.y = randomGridY`. Then tag.c's
  root-transform compose (`tag.c:~3155`) overlayed those onto the stage
  matrix every tick, shifting the entire stage. Un-gating the
  `g_current_context` return fixes the routing so SetProperty actually
  hits Food's MC, not root.

- **Fix 2 (`SWFModernRuntime/src/actionmodern/action.c:~52883`):**
  Un-gate `mc->as_set_flags |= 1|2|4|8|16` in `actionSetProperty` cases
  0/1/2/3/10 (the `_x`/`_y`/`_xscale`/`_yscale`/`_rotation` properties).
  Was gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` —
  browser-WASM wrote `mc->x` but didn't set the flag, so the compose-time
  `apply_as_transform` skipped the entry and the renderer used the
  timeline matrix. `actionSetMember` already sets the flag unconditionally,
  so this just brings opcode SetProperty in line with the dot-syntax
  setter that DJ uses exclusively (0 SetProperty calls in DJ; Snake's
  the only test in the corpus that exercises the opcode for `_x`/`_y`).

- **Fix 3 (`SWFModernRuntime/src/libswf/tag.c:~3074` and `~3102`):**
  Sidestep `apply_as_transform`'s shared-slot mutation for SPRITE / BUTTON
  display entries by:
  - Skipping them in the per-tick runtime-transform-update loop (the
    in-place `transform_data[obj->transform_id]` mutation that drags
    every other display entry sharing the same dedupedd matrix slot).
  - Building the effective parent matrix on a LOCAL stack buffer inside
    the compose loop (`apply_as_transform` overlay onto a memcpy of the
    original CPU-side matrix), passed to `compose_children` as
    `parent_composed`. The CPU-side `transform_data[obj->transform_id]`
    slot stays un-mutated so other display entries that share the
    transform_id (the recompiler dedupes identical matrices into one
    slot — sharing is the common case for the static-stage default
    matrix) render against their own correct timeline position.

  Shapes / text / morph entries still go through the in-place mutation
  path because they're leaf nodes — `render_display_list` draws them
  via `obj->transform_id` directly, so the GPU slot must hold the
  AS-overlaid matrix. The shared-slot hazard remains for them but only
  when a leaf-class entry has AS-set transforms AND shares a slot,
  which is rare in practice; documented as a known limitation.

## Diagnostic chain

This took three attempts to nail down — recording all three because the
intermediate symptoms misled the diagnosis.

1. **First un-gate attempt (Fix 2 alone) shifted the entire stage.**
   Re-enabling `as_set_flags |= 1|2` in `actionSetProperty` made the
   snake clones visible (their `_x`/`_y` finally applied) but the
   play-area border slid up-and-left to match wherever Food's random
   grid position landed. Initial hypothesis: shared transform_id
   between Food's static placement and the play-area border, line 3074
   loop's in-place mutation displacing both. Inspected `transform_data`
   sharing and yes — the recompiler dedupes identical static matrices.

2. **Second attempt (Fix 2 + Fix 3 only) — Snake column visible but
   play-area STILL shifted.** Added a printf to the line 3074 loop to
   confirm it was running on Food (or whoever was shifting things).
   The printf NEVER fired. So no display entry was hitting the
   mutation path. But the stage was definitely shifting. Deduced:
   something outside the loop was applying an AS-set transform, most
   likely `tag.c:~3155`'s root-transform apply (the line
   `if (root_movieclip.as_set_flags != 0) apply_as_transform(root_xform, ...)`).
   Inferred root was getting AS-set somehow.

3. **Traced the routing.** `actionSetProperty` calls
   `getMovieClipByTarget(target)`. For `target=""` (empty, inside a
   `SetTarget "Foo"` block), the browser-WASM arm of
   `getMovieClipByTarget` returned `&root_movieclip` regardless of
   active SetTarget context. So `Food._x = ...` was writing to root.
   With Fix 2's un-gate making the flag write unconditional, root
   accumulated bogus `as_set_flags` + `x`/`y`. The root-transform
   compose then shifted the stage every tick.

4. **Fix 1 lands.** `getMovieClipByTarget("")` now returns
   `g_current_context` in all build modes (matching NO_GRAPHICS /
   OFFSCREEN_RENDER behavior). Snake's `SetTarget "Food"; Food._x = ...`
   now correctly targets Food's MC. Combined with Fix 2 (so Food gets
   as_set_flags) and Fix 3 (so Food's positioning doesn't drag the
   shared-slot play-area along), Snake's gameplay renders correctly.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`getMovieClipByTarget("")` returns `g_current_context` in all build
  modes** (`SWFModernRuntime/src/actionmodern/action.c:~19283`). **Do
  NOT** re-add the `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
  gate around the `g_current_context` return — without it, opcode-form
  `SetProperty` inside a `SetTarget "Foo"` block writes to root in
  browser-WASM, and Foo's intended _x/_y/scale/rotation changes shift
  the entire stage instead of moving Foo.

- **`actionSetProperty` cases 0/1/2/3/10 set `as_set_flags`
  unconditionally** (`SWFModernRuntime/src/actionmodern/action.c:~52883`).
  No mode gate. Matches `actionSetMember`. **Do NOT** re-gate — opcode
  SetProperty becomes inert visually in browser-WASM (writes mc->x but
  the compose-time apply skips because the flag bit is unset).

- **tag.c runtime-transform-update loop skips SPRITE / BUTTON entries**
  (`SWFModernRuntime/src/libswf/tag.c:~3074`). The compose loop below
  handles them via local-buffer AS overlay so they don't share-mutate
  `transform_data`. **Do NOT** un-skip — sprites/buttons with AS-set
  transforms typically share their transform_id with other static
  placements (recompiler dedupes identical matrices) and in-place
  mutation drags the sharers along (Snake's play-area-shift symptom).

- **tag.c compose loop builds effective parent matrix on a local
  buffer for SPRITE / BUTTON entries with `as_set_flags != 0`**
  (`SWFModernRuntime/src/libswf/tag.c:~3102`). Reads original
  CPU-side `transform_data[obj->transform_id]` (un-mutated per the
  line 3074 skip), copies to a 16-float stack buffer, applies
  `apply_as_transform` overlay, passes that as `parent_composed` to
  `compose_children`. **Do NOT** revert to the direct
  `app_context->transform_data + obj->transform_id * 16` read —
  without the local-buffer overlay, sprite/button MCs with AS-set
  positions render their children at the timeline position rather
  than the AS-set position.

## Baselines (all green)

- **Trace divergence (DJ):** 407=407 identical.
- **DJ menu (no click, 8s probe):** title + 4 buttons centered,
  doodle character on the left, 0 errors.
- **DJ info subscreen (click→info):** "items" body renders,
  "mushroom: inverse control" not truncated, "back" button centered.
- **Pong (4s probe):** loading screen with notebook background +
  "Glaiel Games.Com" handwritten signature intact, 0 errors.
- **Snake title:** SNAKE / CHOOSE LEVEL / SLUG WORM PYTHON / URL all
  positioned correctly.
- **Snake gameplay (NEW):** snake column moves down the field at
  constant length, food dot visible at random grid position. Stage
  layout intact (play-area border properly centered). Score stays 0
  because the probe can't simulate keyboard input — no direction
  changes, snake walks into the wall.
- **Snake game-over:** GAME / OVER on two lines.

## Known limitations still carried forward

- **Score stays 0 without keyboard input.** Probe limitation, not a
  code issue.

- **Shape / text / morph entries with AS-set transforms still hit
  the shared-slot mutation path.** Line 3074 loop only skips
  SPRITE / BUTTON. A leaf-class entry (rare: SHAPE MC repositioned
  via setMember) would still mutate `transform_data` in place and
  drag any sharers along. No test in the corpus exercises this.
  Fix would be the same local-buffer pattern applied to leaf renderers,
  but `render_display_list` reads `obj->transform_id` directly at
  GPU draw time so the leaf case needs a per-tick fresh-GPU-slot
  allocation (more invasive than the SPRITE/BUTTON compose-loop fix).

## Tools / state

- 1 unpushed commit expected (2 files: action.c + tag.c) plus this
  docs handoff (2 commits total).
- Recompiler unchanged.
- Don't-touch list now covers all four wasm fixes from this session's
  three commits (`7fd96e6f2` actionCloneSprite + `2d792bde3`
  actionRemoveSprite + this one).

Push when ready.
