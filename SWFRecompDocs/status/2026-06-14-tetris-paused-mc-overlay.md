# Tetris game frame: `paused_mc` overlay covers the whole game (browser-WASM)

**Date:** 2026-06-14
**Status:** ✅ **FIXED** (cont. 27). The overlay no longer covers the game — verified
with `tetris_compare.py`. A separate, newly-unmasked board-render gap remains (see
"Follow-up" below).
**Bucket:** browser-WASM only (not CI-observable; verified with the harness below).

---

## RESOLUTION (cont. 27) — read this first; the original root cause below was WRONG

The cont. 26 root cause ("`frame_1`'s `_visible=false` never runs; `VISDIAG count: 0`")
was **stale/incorrect**. Fresh instrumentation (`advance_sprite_frames` + sprite-script
dispatch + `actionSetProperty` case 7) showed the opposite:

- `paused_mc`'s `frame_0` **does** run, once, on the game frame with `catch_up_mode=0`
  (`ASF callframe char=68 frame=0 cm=0`).
- `script_15` **is** queued and dispatched **in paused_mc's context**
  (`SPRITESCRIPT dispatch char=68 ... name='paused_mc'`).
- `""._visible=false` **is** applied to the right MC
  (`SETVIS ... mcname='paused_mc' new_vis=0`), so `mc->visible == 0`.

**The real bug was in the renderer**, not the script: the browser-WASM render path
**never honored `_visible` for a timeline-placed sprite**. The root render loop tried
no visibility check at all, and a name-based check doesn't work either — from the root
render loop, `actionFindMovieClipByName("paused_mc")` returns NULL and
`actionFindOrCreateMovieClip("paused_mc", root)` **mints a brand-new `visible=1` MC on
every call** (a different pointer each frame), never the MC that got `visible=0`.

### The fix (commit: see git log near this date)

- `DisplayObject::as_hidden` — new `u8`, zero-init = visible (`SWFModernRuntime/include/libswf/swf.h`).
- `actionSetProperty` case 7 (`_visible`) syncs it onto the linked entry via
  `mc->display_obj` (set by `exec_sprite_frame`: `mc->display_obj = &display_list[depth]`),
  so the flag rides on the exact `DisplayObject` the render loop iterates
  (`SWFModernRuntime/src/actionmodern/action.c`).
- Browser-WASM root render loop (`tagShowFrame`, `tag.c`) skips non-mask entries with
  `obj->as_hidden` set; the root-attached (`child_mc_cache`) pass skips `!mc->visible`.
  A mask's `_visible` is irrelevant to clipping, so mask entries are not skipped.
- The render-loop edit sits in the `#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`
  block, so it also compiles for OFFSCREEN/HEADLESS → run CI both modes as a
  no-regression check (the suites are trace-based, so honoring `_visible` in rendering
  is inert there).

### Follow-up (OPEN, separate bug — anticipated by the original "behind-the-overlay" note)

With the overlay gone, the game still doesn't fully render: the **board** (190
`b_mc.attachMovie("block")` clips), the **next-piece preview**, the **level/lines/score
labels**, and the **quit/pause buttons** don't appear on the SWFRecomp side (Ruffle
renders them all). These were always masked by the overlay and have their own render
gap — likely in how attached children of a non-root sprite (`b_mc`) are rendered in
browser-WASM. The dynamic-number italic SLANT is still a separate, user-deprioritized bug.

---

## Original (cont. 26) writeup — KEPT FOR HISTORY; root cause superseded above

## Symptom (what the user sees)

Tetris menu → Play → (set level) → OK reaches the game frame, but the game is
**not playable**: a blank white box with the word **"paused"** and a stray
slanted level number covers the play area; the falling piece, next-piece
preview, level/lines/score labels, quit/pause buttons, and the "tetris" title
are all missing. Ruffle (ground truth) renders the full game.

## Root cause (confirmed)

The pause overlay **`paused_mc` = `DefineSprite_68`**, placed on the game frame
at **depth 228 (the topmost element)**, is a stage-covering white box + "paused"
text. Its `frame_1` is:

```actionscript
_visible = false;            // hide itself initially
hit_mc.onPress = _root.pause;
```

That `_visible = false` **never executes in browser-WASM**, so the overlay stays
visible and covers everything below it. (`quitGame_mc` = `DefineSprite_65` has the
same `frame_1` `_visible = false` and is affected the same way.)

**Evidence:** a temporary diagnostic in `actionSetProperty` case 7 (`_visible`)
printed nothing across the entire menu→game flow (`VISDIAG count: 0`). Tetris's
menu/level-select don't set `_visible` (arrows use `_alpha`); only the game
frame's `paused_mc`/`quitGame_mc` do — so zero `_visible` sets ⇒ those nested
sprite frame scripts didn't run. The slanted "2" that *does* render proves the
game frame's **main** DoAction ran (it sets `level` + places the bound
textfields); it is specifically the **timeline-placed nested-sprite `frame_0`
scripts** on the game frame that don't execute.

`_visible = false` is emitted as `actionSetProperty` with an **empty target**
(`str_28 = ""`), property index 7. `getMovieClipByTarget("")` returns
`g_current_context`, and `exec_sprite_frame` (graphics_stubs.c, browser-WASM)
*does* swap `g_current_context` to the sprite's MC when it has a name and no
clip-actions — and `paused_mc` qualifies (flags `0x36`, no CLIPACTIONS). So IF
`paused_mc`'s `frame_0` ran, `""._visible=false` would correctly hit `paused_mc`.
It just never runs.

## Narrowed mechanism / the exact next step

`advance_sprite_frames` (tag.c ~844) is the browser-WASM sprite pump. It:
- iterates the display list (only `CHAR_TYPE_SPRITE`, line ~919),
- allocates the persistent DL on first encounter (`just_allocated`, ~922),
- and **calls the current frame func** at ~1134:
  `CALL_FRAME(app_context, obj, ch->sprite_frame_funcs[frame])`
  (`frame == sprite_current_frame == 0` for a just-allocated 1-frame sprite).

So on paper `paused_mc`'s `frame_0` *should* run. It doesn't. The remaining
unknown is **why** — trace one of:

1. **Is `paused_mc` in `display_list` (with `char_id != 0`) when
   `advance_sprite_frames` runs after the game frame loads?** The game frame is
   reached mid-handler via `ok_btn.onPress → play()` (a deferred advance), so the
   game frame's placements + the `advance_sprite_frames` call order may differ
   from a normal forward tick. Possibly the game frame's nested sprites are
   placed but `advance_sprite_frames` for that frame ran before they were placed,
   or ran with `catch_up_mode` set (which gates it off in NO_GRAPHICS/OFFSCREEN
   at line ~847 — check the browser-WASM equivalent).
2. **Is there a skip-gate between line 919 and 1134** (e.g. a `sprite_is_playing`
   / `just_allocated` / `enterframe_eligible` condition) that suppresses
   `frame_0` for a just-placed sprite on the tick it appears?
3. **Does the `play()`-driven game-frame advance run `advance_sprite_frames` at
   all** for the new frame, or does the deferred-goto path skip the
   nested-sprite pump? (Compare the `g_deferred_root_goto` / swf.c catch-up loop
   vs the normal `tagShowFrame → advance_sprite_frames` path.)

Add a diagnostic in `advance_sprite_frames` (print `obj->char_id`,
`ch->type`, `obj->instance_name`, `frame`, `just_allocated`,
`sprite_is_playing`, `catch_up_mode` for each iterated sprite) on the game
frame and see whether `paused_mc` (sprite 68, depth 228) is reached and what
gates it. That pinpoints which of (1)/(2)/(3) it is.

## Reproduce / verify (the harness)

Browser-faithful Ruffle-vs-SWFRecomp image comparison (built this session,
committed `dc6240037`):

```bash
# Deploy the demo (after any runtime .c change):
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics --clean
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics

# Compare (headed Chrome; needs DISPLAY):
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/tetris_compare.py
#   -> tools/divergence/game_drive/compare_out/compare_ok.png  (the game frame)
```

`compare_ok.png` left=Ruffle (full game), right=SWFRecomp (white "paused"
overlay). **Fix is correct when the SWFRecomp side shows the board/pieces
instead of the white "paused" box.** See `tools/divergence/game_drive/README.md`.

> CRITICAL: Chrome must launch with `--ignore-gpu-blocklist` or the WebGPU canvas
> screenshots come back black. The harness already sets it; if you write a custom
> Playwright driver, include it (this corrected the old "WebGPU capture is
> impossible" belief — see session guide gotcha #8).

## Constraints

- Browser-WASM-only behavior → **no CI dispatch** (per `ci-only-when-observable`);
  verify with the harness, not CI. (If the fix touches shared `advance_sprite_frames`
  / OFFSCREEN code, still run CI both modes as a no-regression check.)
- Strip any temp diagnostics before committing. Trunk-based: commit to `master`.

## Bug list status (Tetris)

- DONE this session: menu buttons fire AS onRelease (`eb85f9fc9` + gating
  `c5134fbbd`); textfield-bound numeric variable stringified at bind
  (`8f83dbd95`); all CI-green.
- **OPEN (this doc): `paused_mc` overlay covers the game** — the gameplay blocker.
- OPEN (deprioritized by user): dynamic-textfield digits render with an
  italic/diagonal **slant** (the "/" I first misread was a slanted "1").
- LIKELY-BEHIND-THE-OVERLAY: once `paused_mc` is hidden, re-check the board
  (190 `b_mc.attachMovie("block")` clips), next-piece preview, and labels — they
  may have their own residual render issues, currently masked.
