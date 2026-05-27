# 2026-05-27 — Snake's snake actually MOVES (actionRemoveSprite wired for browser-WASM)

Follow-up to `2026-05-27-snake-gameplay-clones-visible.md` (commit `7fd96e6f2`).
With Bug B's three Snake-render fixes in, the snake column was visible during
play but accumulated segments every tick instead of moving — `removeMovieClip`
on the tail was a no-op in browser-WASM. After this change the snake moves
across the play field at a constant length (head added, tail removed each
tick), and hits the bottom wall to trigger GAME OVER cleanly.

## TL;DR

Two runtime changes — no recompiler change, no new test coverage needed.

- **Fix 1 (`SWFModernRuntime/src/actionmodern/action.c`):** Widen
  `actionRemoveSprite`'s dispatch gate. Same pattern as the
  `actionCloneSprite` widening in `7fd96e6f2`: drop the wasm-graphics stub
  arm entirely (it was just a `#ifdef DEBUG printf("would remove %s")`)
  and route all three build modes through the same `child_mc_cache`
  removal path. Added `extern int g_settarget_invalid;` / `extern int
  g_settarget_none;` so the active-context-fallback branch links in
  browser-WASM where those globals live in `graphics_stubs.c`.

  Also fixed a pre-existing bug while in the function: the toString
  coercion was gated `if (STACK_TOP_TYPE == OBJECT|ARRAY|FUNCTION)` so
  numeric targets fell through to `popVar` as-is, `target_name` stayed
  `""`, and the function returned at the empty-name guard. Snake's
  gameplay pushes the `tail` counter directly (`actionGetVariable("tail")`
  → integer on stack, then `actionRemoveSprite`), so every removal was
  silently dropped. Now: peek for MOVIECLIP first (so MC-by-reference
  targets keep their `mc->name` access path), then unconditionally
  `convertString` for everything else — matches `actionCloneSprite`'s
  pattern at `action.c:~53112` and Ruffle's argument-coercion semantics.

- **Fix 2 (`SWFModernRuntime/src/libswf/graphics_stubs.c`):** Add a no-op
  stub for `ng_queue_slot_unload_events` so the widened
  `actionRemoveSprite` body links in browser-WASM. The real impl is in
  `tag.c:~5171` gated on `NO_GRAPHICS || OFFSCREEN_RENDER`. Browser-WASM
  doesn't have clip-action UNLOAD events for clones to fire anyway (clones
  in browser-WASM don't get a display_list[clone_depth] entry per the
  `tag_stubs.c` gate in `7fd96e6f2`, so the call site that would queue
  UNLOAD events is short-circuited by the `ng_findDisplayEntryByName ==
  SIZE_MAX` check before reaching the stub).

## How it looks now

Click slug, countdown 3/2/1/GO!, snake appears as a column of segments at
center, then proceeds to move *down* the play field at constant length —
the column slides downward each tick as the head extends and the tail
retracts. When the head hits the bottom wall, GAME OVER triggers with the
snake's last 2 segments still rendered just inside the field's bottom
edge. Score stays 0 because the probe can't simulate keyboard input (no
direction changes, snake just moves in its initial direction).

This is what Snake gameplay actually looks like — without keyboard input,
the snake walks in a straight line into the wall.

## Diagnostic path

1. **Initial widening landed clean** (drop `#if !defined(NO_GRAPHICS) &&
   !defined(OFFSCREEN_RENDER)` ... `#else` ... `#endif`, keep body). Build
   green after adding the two extern declarations and the
   `ng_queue_slot_unload_events` graphics_stubs.c stub.

2. **Snake column still accumulated.** Probe at t=2s showed 7 segments,
   t=3s showed 13 segments — same as pre-fix. Added a printf at the
   top of `actionRemoveSprite` ("[RemoveSprite] ENTER"). Got 12 ENTER
   logs in the 4-second probe window. So the function WAS being called
   but exiting early.

3. **Added a second printf inside the find-MC loop** ("target=%s
   found_mc=%p depth=%d"). It never fired. So the early-return at
   `if (target_name[0] == '\0') return;` was hitting. Traced the popVar:
   `target.type` was `F64` (Snake pushes integer `tail` counter), and the
   `target_name = "";` initializer was never overwritten — the
   conditional `if (target.type == STRING)` / `else if (... MOVIECLIP)`
   chain has no numeric branch, so target_name stayed empty.

4. **Fixed the coercion.** Peek for MOVIECLIP first (so MC-by-reference
   `removeMovieClip(_root.foo)` keeps the direct `mc->name` access),
   then unconditionally `convertString` — matches `actionCloneSprite`.
   After this, snake stays at 2 segments and visibly slides down the
   field; hits bottom wall, GAME OVER renders with snake stretched just
   above the wall.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`actionRemoveSprite` is gate-less in all three build modes**
  (`SWFModernRuntime/src/actionmodern/action.c:~53275`). Removed the
  `#if !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)` stub arm.
  **Do NOT** re-introduce the gate — browser-WASM uses the same
  `child_mc_cache` removal primitives as NO_GRAPHICS / OFFSCREEN_RENDER
  (the display_list-clearing inner block is naturally a no-op for
  browser-WASM clones because `ng_findDisplayEntryByName` returns
  `SIZE_MAX` for them per the `tag_stubs.c` gate in `7fd96e6f2`).

- **`actionRemoveSprite` unconditionally `convertString`s its target**
  (`SWFModernRuntime/src/actionmodern/action.c:~53282`). Previously the
  coercion was gated on OBJECT/ARRAY/FUNCTION types only. **Do NOT**
  re-add the gate — Snake's gameplay pushes the `tail` counter as a
  numeric value (`actionGetVariable("tail")` → F64), and without
  unconditional coercion the popped target's `target_name` stays empty
  and the call early-returns. The MOVIECLIP path is preserved via a
  pre-coercion `peekVar` (same pattern as `actionCloneSprite`).

- **`ng_queue_slot_unload_events` is a no-op in browser-WASM**
  (`SWFModernRuntime/src/libswf/graphics_stubs.c:~104`, gated
  `#ifndef OFFSCREEN_RENDER`). Real impl in `tag.c:~5171` for NO_GRAPHICS
  / OFFSCREEN_RENDER. Browser-WASM clones don't have display_list
  entries (per the `7fd96e6f2` tag_stubs.c gate), so the call site
  short-circuits before reaching this stub — the stub exists only to
  satisfy the linker.

## Baselines (all green)

- **Trace divergence (DJ):** 407=407 (identical).
- **DJ menu (no click, 8s probe):** title + 4 buttons centered, doodle
  character on the left, 0 errors.
- **Snake title:** SNAKE / CHOOSE LEVEL / SLUG WORM PYTHON / URL all
  positioned correctly.
- **Snake gameplay (NEW):** snake column moves down the field at constant
  length (no accumulation). Final 2 segments visible at bottom wall when
  GAME OVER triggers.
- **Snake game-over:** GAME / OVER on two lines, SCORE / LEVEL bottom
  labels intact.

## Known limitations still carried forward

- **Score stays 0 without keyboard input** (probe limitation, not a
  code issue).

- **`apply_as_transform`'s shared-slot mutation is still unfixed**
  (`tag.c:~3074`). Not exercised by current corpus (Snake's SetProperty
  doesn't set as_set_flags in browser-WASM per the gate at
  `action.c:~52886`; DJ uses 0 actionSetProperty calls). A SWF that
  sets `_x`/`_y` on a non-clone with a shared transform_id would still
  drag siblings to the same position. Per-tick fresh-slot allocator in
  the runtime-transform-update loop would fix it; documented in the
  prior handoff.

## Tools / state

- 1 unpushed commit expected (2 files: action.c + graphics_stubs.c)
  plus this docs handoff (2 commits total).
- Recompiler unchanged. Tests deployed individually via `build_test.sh`
  + `deploy_example.sh`.

Push when ready.
