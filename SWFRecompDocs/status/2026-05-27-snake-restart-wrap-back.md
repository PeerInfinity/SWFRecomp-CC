# 2026-05-27 — Snake game-over → menu wrap-back cleanup (browser-WASM)

Partial fix for the user-reported "after Game Over, click to menu, start a new game, the snake isn't visible, and the game over screen quickly pops up again" issue.

## What this commit fixes

When Snake hits GAME OVER (frame 56) the SWF natural-wraps to frame 0 via the recompiler-emitted `next_frame=0; manual_next_frame=1;` at end of `frame_56`. The end-of-tick cleanup in `swf.c` that should clear stale display-list entries placed at frames > 0 was gated `#ifdef OFFSCREEN_RENDER` — so in browser-WASM graphics it never ran. The gameplay textfields/MCs at depths 1–8 stayed on the display list, and when the menu re-rendered at frame 0 it painted **over** them, leaving:

- A lingering `SCORE:` textfield in the menu's lower-left
- A black square in the upper-left of the **second** game's countdown (a stale char_id from the menu→gameplay transition, painted on the now-occupied depth)

This change widens the cleanup to run in all build modes. The `ng_display_clear_after` helper also moved outside its `NO_GRAPHICS || OFFSCREEN_RENDER` gate in `tag.c` so the linker can resolve it in graphics builds; the body is pure `display_list[]` manipulation with no graphics dependencies.

## What this commit does NOT fix

The user's full report includes "the snake isn't visible" on the second game. After this cleanup the menu re-renders correctly and the second start runs `tagPlaceObject2` on fresh-cleared depths, but the snake's `duplicateMovieClip("Snake.head", "s_<head>", 16384+head)` clones still don't appear visually. Game-logic state (`x`, `y`, `head`, `tail`, `eaten`, the `s_<x>_<y>` body-cell variables) all reset and progress correctly — verified by instrumenting `script_7` (init) and `script_14` (move) and seeing identical state trajectories across game 1 and game 2. The remaining issue is in the clone-render pipeline for the browser-WASM graphics path, and is tracked as a follow-up.

The black square in **game 1's** countdown is also still present — that's a pre-existing menu→gameplay transition bug, unrelated to restart. The black square's disappearance in **game 2's** countdown is downstream of this wrap-back cleanup (the stale char paint was happening because of the missing cleanup, not because of the menu→gameplay transition).

## Files changed

- `SWFModernRuntime/src/libswf/swf.c` — removed the `#ifdef OFFSCREEN_RENDER` gate around the `manual_next_frame` natural-wrap cleanup; the `_wrap_is_last_tick` MAX_FRAMES check now compounds to `#if defined(OFFSCREEN_RENDER) && defined(MAX_FRAMES)` so browser-WASM (which runs forever) is always 0.
- `SWFModernRuntime/src/libswf/tag.c` — moved `ng_display_clear_after` outside the `NO_GRAPHICS || OFFSCREEN_RENDER` block so the symbol is defined in graphics builds.

## Diagnostic chain

1. Reproduced via `/tmp/snake_restart_probe.py`: click SLUG, wait for game-over (snake walks south unattended), click center to return to menu, click SLUG again, observe.
2. Compared pre-fix screenshots:
   - `post_restart_menu_05` had a leftover `SCORE:` text in the bottom-left of the menu
   - `g2_t01` (game 2 countdown "1") had the same black square top-left as game 1
   - `g2_t04` (game 2 ~1.6s) showed food at top-left and no snake — game logic running with stale state
3. Traced `swf.c` end-of-tick cleanup — found the `#ifdef OFFSCREEN_RENDER` gate at line 891 around the `manual_next_frame` natural-wrap-back cleanup. Browser-WASM was missing it entirely.
4. Verified post-fix:
   - `post_restart_menu_05` clean (no `SCORE:` leftover, www.neave.com footer visible)
   - `g2_t01` clean (no black square)
   - `g2_t04` snake still invisible (residual clone-render issue) — but menu cleanup is real progress

## Why no regressions

- The natural-wrap cleanup is conservative: it only runs when `manual_next_frame && !goto_from_action && next_frame < current_frame`. `goto_from_action` covers all AS-driven gotos which have their own catch-up cleanup; the inner condition skips forward jumps. So this only fires on recompiler-emitted natural backward wraps (last-frame loop-back).
- `ng_display_clear_after` preserves entries whose `sprite_display_list != NULL` (initialized MovieClips) and skips dynamic-depth entries (≥ 16384) — same behavior in graphics builds as in NO_GRAPHICS. The catch-up branch then decides per-placement whether to modify or replace.
- `g_loopback_replay_armed = 1` arms `tagPlaceObject2`'s same-loop modify path, which already exists in browser-WASM.

## Verification

- `tools/wasm_probe_runner.py`: 8/8 pass (unchanged).
- `tools/browser-test/baseline-probes/snake_gameplay.py`: game 1 snake visible, working.
- `tools/browser-test/baseline-probes/snake_keyboard.py`: keyboard input still steers the snake.
- `tools/browser-test/baseline-probes/snake_title.py`, `dj_menu.py`, `dj_info.py`, `pong_loading.py`: visually intact.
- `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle`: `Trace: identical 407=407`.

## Follow-up needed

The restart-flow snake-invisibility (clone-rendering path) needs separate investigation. Initial findings:
- Game 2 starts cleanly (this fix), `script_7` resets all state, `script_14` runs and advances `head`/`tail`/`x`/`y` correctly across iterations.
- Clones at SWF depths 16384+N never appear visually despite the script-side state being correct.
- Suspect the browser-WASM clone-render path (`ng_cloneSprite`/`ng_cloneSpriteFromMC`) leaves the new clone in an unrendered state when the source MC has been replaced (depth 6's Snake MC was removed and re-placed across the wrap-back).

The pre-existing black square in game 1's countdown (menu→gameplay transition, frames 4–50) is also a separate residual.
