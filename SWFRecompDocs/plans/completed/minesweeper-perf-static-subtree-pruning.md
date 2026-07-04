> **AUDIT OUTCOME (2026-07-04):** Landed via `6308c4a03` (MC resolution cache, -38.4%) + `5f2530446` (event-driven walk pruning, -14.4%); riskier structural advance/presync prune deferred.

> ⚠️ **SUPERSEDED (2026-06-17).** The diagnosis below is WRONG for the browser.
> A real in-browser CPU profile showed the bottleneck is the WebGPU renderer's
> per-shape `writeBuffer` calls (~88% of frame CPU), not the AVM1 walks (<2% in
> the browser). The native NO_GRAPHICS profile this plan is based on has rendering
> stubbed, so the walks dominate *there* by construction only. The real fix
> (batch dynamic buffer writes) landed in `079c0fefe`; see
> `SWFRecompDocs/status/2026-06-17-minesweeper-perf-writeBuffer-batching.md`.
> The pruning below was implemented + shelved (`~/avm1_subtree_pruning_shelved.patch`).

# Minesweeper perf — static-subtree per-frame-walk pruning (PLAN / HANDOFF)

**Date:** 2026-06-17
**Status:** diagnosed, NOT started. Implementation deferred to a fresh session.
**Game:** flasharchive/Minesweeper (browser-WASM graphics), but the fix is in the
shared per-frame hot path → affects **all** games + **both CI modes**.

## TL;DR

Minesweeper is the first **genuinely CPU-bound** recompiled game (the perf effort
in [[wasm-game-performance-profiling]] had been waiting for one). On the
difficulty screen it runs at **~12 fps instead of 30** because every frame the
engine does **~5 separate full recursive walks of a deep, entirely-static
FUIComponent sprite tree** (the radios) even though nothing is animating. Goal:
skip those walks for subtrees with no dynamic content. Expected win: roughly
halve per-frame CPU on this screen.

## Measured evidence (real browser, perf HUD)

Difficulty screen, capped 30 fps (33 ms budget), read from `window.__swfPerf`:
- frame CPU **mean 63.7 ms, p95 181 ms, max 3132 ms** → ~190% of budget.
- delivered frame interval mean ~85 ms → **~12 fps**, CPU never idles.
- the single **3132 ms** frame = one-time difficulty-screen construction = the
  user's "slow to load". p95 181 ms = recurring heavy frames (investigate; may be
  a periodic rebuild or GC — not yet pinned).

How to reproduce the measurement (the deployed wasm has the HUD, swf.c
`swf_perf_report`, `__EMSCRIPTEN__`-gated):
```
# rebuild+deploy if needed (deployed wasm is gitignored):
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Minesweeper wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Minesweeper "$(pwd)/docs2/examples" --no-index --graphics
# then load demo.html?test=flasharchive/Minesweeper&perfhud=1 and read window.__swfPerf
# (one-off probe written this session: /tmp/ms_perf_probe.py — reads __swfPerf.cpu/iv
#  mean/p95/max; copy it into tools/divergence/game_drive/ if you want it kept).
```

## Native profile (NO_GRAPHICS, 100 frames) — the breakdown

`SWFRecomp/scripts/profile_game_native.sh flasharchive/Minesweeper 100 no-graphics`
(callgrind; 416M Ir total). Top per-frame costs, all in `tag.c`:

| % | function | what it does every frame |
|---|----------|--------------------------|
| 18.0 | `advance_sprite_frames` (`tag.c:865`) | recurses stopped subtrees via `advance_sprite_children_only` (`tag.c:823`, called at `:1101` for `!sprite_is_playing`) |
| 11.2 | `presync_nested_cf_recurse` (`tag.c:1692`) | unconditional full-tree recurse (see `:1719-1721`) |
| 6.9  | `ng_update_button_states_in_dl` (`tag.c:2692`) | button hit-test walk (recurses sprites + buttons) |
| 6.9  | `set_enterframe_eligible_recursive` (`tag.c:3525`) | full-tree recurse marking eligibility |
| 6.8  | `gather_clip_ef_entries` (`tag.c:3289`) | full-tree recurse gathering clip enterFrame entries |
| 6.0  | `swf_name_match` / 4.7 `_obj_utf8_decode` | name compares under the above |

**IGNORE** the 11% `__memset_avx2` in the native profile — it's the attachMovie
`swf_depth = as_depth + 16384` registration buffer (~16400 entries), which cont.39
**gated to CI modes only** (`!NO_GRAPHICS && !OFFSCREEN_RENDER` skips it in
browser-WASM). It is NOT a browser cost. The recursive walks above ARE
mode-invariant and ARE the browser cost.

Per-frame entry points (where the walks fire each frame):
- `advance_sprite_frames` — root advance (`tag.c:850` inside the frame-advance fn;
  also `:1221`,`:1427`,`:1894`,`:4651`,`:4674`).
- `presync_nested_cf_recurse` ← `presync_nested_sprite_currentframe` (`tag.c:1766`),
  run before the enterFrame flush ([[nested-cf-presync]]).
- `set_enterframe_eligible_recursive` (`tag.c:3577`) + `gather_clip_ef_entries`
  (`:3415`) ← `tagFlushPendingEnterFrame` (`tag.c:3542`).
- `ng_update_button_states_in_dl` ← `ng_update_button_states` ← `tagShowFrame`
  (`tag.c:4507`, cursor/hover path).

## Root cause

The difficulty screen builds a deep, **static** FUIComponent tree: 3 radios, each
`frb_states` (5-frame clip, `gotoAndStop`'d = stopped) → `frb_frame_mc`(cid14)/cid17
→ grandchildren cid7/9/11/13/16 → leaf shapes, plus `fLabel_mc`→`labelField`,
`frb_hitArea_mc`, `deadPreview`, (unloaded) `boundingBox_mc`. ≈50–75 sprite nodes.
Nothing animates (all stopped, no `onEnterFrame`), yet all ~5 walks recurse the
entire tree every frame. Each walk visits every node; `advance_sprite_frames` also
runs an insertion sort over the depth list at each level.

## Proposed fix — skip walks for static subtrees

Add a per-sprite summary flag, e.g. `DisplayObject.subtree_dynamic` (or compute a
"static" predicate), meaning **"this sprite OR any descendant has something that
needs per-frame work"**: a playing multi-frame sprite, an `onEnterFrame` handler,
a mouse/clip-event handler, a pending manual goto, or `attached_playable`. When
false, the per-frame walks short-circuit at that node (don't recurse in).

Maintenance points (set/clear the flag and propagate UP to ancestors):
- when a subtree is built (`advance_sprite_frames` just_allocated; the cont.40f
  deep-build in `ng_attachMovie` / `exec_sprite_frame`; `ng_gotoFrameByMC`).
- on `play()`/`stop()`/`gotoAndPlay`/`gotoAndStop` (sprite play-state change).
- on `attachMovie`/`createEmptyMovieClip`/`removeMovieClip`/`unloadMovie`.
- on assigning `onEnterFrame` / button handlers / clip events.
- on button-state swaps (`ng_update_button_states_in_dl` rebuilds children).

Then gate the recursion in: `advance_sprite_frames`/`advance_sprite_children_only`,
`presync_nested_cf_recurse`, `set_enterframe_eligible_recursive`,
`gather_clip_ef_entries`, and (carefully) the sprite-recursion in
`ng_update_button_states_in_dl`. A node with `subtree_dynamic==0` is skipped
(its own per-frame state is already settled and can't change until something
re-marks it dynamic).

### Correctness traps (do NOT regress)
- **enterFrame semantics:** Flash fires `onEnterFrame`/clip ENTER_FRAME every tick
  even on stopped clips. A static subtree with NO enterFrame/clip handler anywhere
  legitimately needs none of these — but if ANY descendant has one, the subtree is
  dynamic and must still be walked. Be conservative: presence of a handler ⇒
  dynamic.
- **First build:** a just-allocated sprite must still run its frame-0 once (don't
  skip the build, only skip re-walking after it's settled).
- **Re-activation:** clicking a radio fires `gotoAndStop("selectedEnabled")` → the
  subtree changes → must re-mark dynamic for that tick so the goto/rebuild runs,
  then settle back to static. Verify the dot still appears/clears (cont.40i).
- **Buttons:** `ng_update_button_states_in_dl` must still hit-test buttons every
  frame (hover/cursor) — a button is interactive = dynamic. Only skip pure-static
  graphic subtrees with no button/handler inside.
- Don't break the existing flags this overlaps with: `enterframe_eligible`,
  `attached_playable`, `sprite_is_playing`, `sprite_manual_next_frame`.

### Also worth checking
- The **3132 ms construction spike**: separately confirm whether the cont.40f
  deep-build is O(n²) or runs more than once; the static-pruning won't fix a slow
  one-time build. May warrant its own narrower fix.
- The **p95 181 ms recurring** frames: pin what they are (instrument frame index
  vs cost) before/after the fix.

## Verification gates (mandatory — shared hot path)
1. Re-measure with the perf HUD (`__swfPerf`) — confirm mean frame CPU drops well
   under 33 ms and fps approaches 30 on the difficulty screen.
2. **Functional, real browser:** radios still select (exclusive dot), Start still
   hover/click, text field still works ([[minesweeper-interactivity-done]]).
3. **OFFSCREEN no-regression:** `divergence_test.py SWFRecomp/tests/flasharchive/
   Minesweeper/test.swf --frames 16 --skip-ruffle` → trace still 634 lines.
4. **Regression smokes (browser-WASM):** Tetris (play→gameplay, falling pieces +
   line-clear `bang_mc` animation MUST still play — it's a *dynamic* subtree),
   Doodle Jump (menu + play, animating doodle), Snake, Pong. Animation is the key
   risk: if the static-flag wrongly marks a playing/animating clip static, it
   freezes. Test games with continuous animation hard.
5. **CI both modes** (no-graphics + graphics) per `.claude/pipeline-handoff.md` —
   this changes `advance_sprite_frames`/`tagFlushPendingEnterFrame` etc. which are
   exercised by many trace tests (enterFrame, tell-target, goto, button suites).
   Expect this to be the load-bearing signal; chase any pass→fail.

## Key files
- `SWFModernRuntime/src/libswf/tag.c` — all 5 walk functions + per-frame entry
  points (line numbers above; re-grep, they drift).
- `SWFModernRuntime/include/actionmodern/action.h` / the `DisplayObject` struct
  (in `libswf/swf.h`) — add the flag.
- Tools: `SWFRecomp/scripts/profile_game_native.sh`, the perf HUD in `swf.c`.

## Context from this session
Interactivity work (commit `e86241173`) is DONE and CI-clean both modes; this perf
issue predates it (the deep tree existed; my deep-build made construction heavier
but the per-frame walks are the engine's, not mine). See
`SWFRecompDocs/status/2026-06-17-minesweeper-interactivity-DONE.md`.
