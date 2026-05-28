# 2026-05-27 — Snake restart clone visibility (browser-WASM)

Follow-up to `8e0397b8d` (snake restart wrap-back cleanup). That landing fixed the menu-leftover textfield + game-2 countdown black square; this lands the missing piece — the snake itself reappearing on the second game.

## TL;DR

`clone_depth_evict` (in `tag_stubs.c::clone_depth_register`) walked `child_mc_cache` by name and nuked the *first* match — which on restart was the **freshly-created clone we were trying to register**, not the dead one from the prior session. With `clone_mc->depth = INT_MIN` after register, the browser-WASM render loop's `child_mc_cache` pass skipped the clone forever.

Game logic was running correctly; the snake's MCs existed; they just had their depth stamped to INT_MIN at birth and the renderer's filter at `tag.c:3324` excluded them.

## Fix

Threaded the freshly-created MC pointer through `clone_depth_register` → `clone_depth_evict` as a `keep` argument. The by-name walk now skips `child_mc_cache[ci] == keep`. Updated all four call sites (`ng_attachMovie`, `ng_cloneSprite`, `ng_cloneSpriteFromMC`, `ng_duplicateMovieClip`).

## Diagnostic chain

1. Confirmed game 2 reproduces (food visible, snake invisible — exactly as documented in the prior status doc).
2. Instrumented `actionCloneSprite` to dump `clone_mc->depth` after `ng_cloneSprite` returns. Game 1 showed `depth=4, 5, 6, …`. Game 2 showed `depth=-2147483648` (INT_MIN) for every clone.
3. Instrumented the `child_mc_cache` render loop in `tag.c::tagDrawDisplayList`. Confirmed the `if (mc->depth == INT_MIN) continue;` gate at line 3324 was the filter dropping them.
4. Grepped for `depth = INT_MIN` and found `clone_depth_evict` at `tag_stubs.c:83`. Read the function and the chain back to `clone_depth_register` — the bug was visible immediately once the call ordering was clear.

### Why this is restart-specific

`g_clone_depth_table` is a static module-level array that survives across the natural-wrap-back from frame_56 to frame_0. It's only mutated by `clone_depth_register` (via `clone_depth_evict`); `actionRemoveSprite` never clears entries. So after game 1's `duplicateMovieClip("Snake", "4", 16388) … ("Snake", "23", 16407)` loop, the table has 20+ stale entries.

In game 2 the same SWF runs the same loop with the same names and depths, and on the *very first clone* `clone_depth_evict(16388, …)` finds the stale `(16388, "4")` entry, walks `child_mc_cache` for an MC named `"4"`, and — since the OLD `"4"` was `actionRemoveSprite`'d back in game 1 tick 4 and its slot in the cache is now NULL — matches the freshly-allocated `"4"` we just created two function calls ago.

The matching MC then gets `depth = INT_MIN`, `avm1_removed = 1`, and its cache slot is cleared. The render loop's `if (mc->depth == INT_MIN) continue;` filter excludes it from the child_mc_cache pass. Result: the clone exists, has correct position, correct sprite_display_list, but is silently dropped from every render.

`ng_cloneSprite` then runs `funcs[0]` to populate the (already-orphaned) clone's display_obj, returns the clone, and `actionCloneSprite` followed by `actionSetProperty` continue to "work" — they update fields on a memory-live MC that nothing renders.

### Why it didn't break the wasm probes

Every test in `tools/wasm_probe_runner.py` runs a fresh page load, so `g_clone_depth_table` is empty at the start. The bug requires the same name+depth to be cloned twice across the lifetime of one page. Snake's restart loop is the first SWF that exercises this — the snake-gameplay baseline only plays one game and quits.

The `ng_attachMovie` site has the *same* hazard latently; it shipped at `tag_stubs.c:381` with the register call *before* `new_mc->depth = as_depth`, which would have papered over the depth nuke (the subsequent assignment fixes the depth) — but `clone_depth_evict` still clears the cache slot, so the MC would still be missing from `child_mc_cache` and still invisible in the render loop. Passing `keep` fixes that path too. (No restart tests currently exercise attachMovie under this scenario, so this is hardening, not a known regression.)

## Files changed

- `SWFModernRuntime/src/libswf/tag_stubs.c` — `clone_depth_evict` / `clone_depth_register` now take a `MovieClip* keep` arg; the by-name walk skips `keep`. Four call sites updated: `ng_attachMovie` (passes `new_mc`), `ng_cloneSprite` (passes `clone_mc`), `ng_cloneSpriteFromMC` (passes `clone_mc`), `ng_duplicateMovieClip` (passes `clone_mc`).

## Verification

- `/tmp/snake_restart_probe.py`: game 2 `g2_t04.png` shows the snake at center (matches game 1's `g1_countdown_04.png`), continues walking south through `g2_t07.png`. Pre-fix this shot showed only food.
- `tools/wasm_probe_runner.py`: 8/8 pass.
- `tools/browser-test/baseline-probes/snake_gameplay.py`: snake visible, walks south, ends in GAME OVER.
- `tools/browser-test/baseline-probes/snake_keyboard.py`: ArrowRight steers snake east (visible in `02_after_right.png`).
- `tools/browser-test/baseline-probes/snake_title.py`: title screen ("SNAKE / CHOOSE LEVEL / SLUG WORM PYTHON") intact.
- `tools/browser-test/baseline-probes/dj_menu.py`, `dj_info.py`, `pong_loading.py`: visually intact.
- `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle`: `Trace: identical 407=407`.

## Residuals (carried forward, untouched by this commit)

- Game 1's countdown still has a small black square in the upper-left during the menu→gameplay transition (frames 4 through 50). It is NOT a restart bug — appears on a fresh first game too. Suspected: a stale char_id from a transition frame painted on a now-occupied depth. Bisect by frame to identify the depth.

## Don't-touch additions

- `clone_depth_register(swf_depth, name, keep)` requires `keep` to be the freshly-created MC at that depth+name. Always pass it — do not pass `NULL` from the runtime clone primitives. (External `NULL` would be acceptable if a caller genuinely wants to evict regardless, but no such caller exists today.)
- `g_clone_depth_table` entries persist across the natural-wrap-back. If a future cleanup path wants to GC them at frame_0 boundary, audit carefully — `actionRewindCleanup` uses `ng_clone_get_swf_depth` to decide survival via the dynamic-range rule, and clearing the table would break that for any clone that *does* survive rewind.
