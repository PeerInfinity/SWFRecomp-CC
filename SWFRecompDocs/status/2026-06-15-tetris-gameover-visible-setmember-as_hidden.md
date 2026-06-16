# Tetris game-over freeze FIXED — SetMember `_visible` never synced `as_hidden`

**Date:** 2026-06-15 (cont. 36)
**Status:** ✅ **FIXED** — topping out now shows the "game over" / "enter your
name:" name-entry screen (`quitGame_mc` frame 2) instead of a frozen board.
Verified with `tools/divergence/game_drive/tetris_gameover_probe.py`.
**Bucket / CI:** the fix writes `DisplayObject::as_hidden`, which is **read** at
`tag.c:4766`. That render walk is inside `#if !defined(NO_GRAPHICS) ||
defined(HEADLESS_GRAPHICS)` — NOT the `#else` of `NO_GRAPHICS||OFFSCREEN_RENDER`
(that `#endif` closes earlier, at the button-hit-test boundary ~line 4469). So
the read is compiled in **OFFSCREEN_RENDER (graphics-native) and
HEADLESS_GRAPHICS** as well as browser-WASM → the SetMember `_visible` change
**IS CI-observable** in the `--mode=graphics` suite. (An earlier draft of this
doc wrongly called it browser-WASM-only; corrected after re-reading the
preprocessor nesting.) Pure NO_GRAPHICS/trace never reads `as_hidden`, so traces
are unaffected. **Graphics CI dispatched** as a no-regression check.

---

## Symptom

When the player tops out, Tetris is supposed to pop up a name-entry "game over"
screen. Instead the board froze and **no game-over screen appeared**. (Reported
together with a separate line-clear freeze — see "Still open" below.)

## Investigation (instrumented, not guessed)

The game-over path is `frame_4`'s `down()` interval callback (FFDec export):

```as
if (collision(xPos,yPos,rotation) && yPos == -10) {
    gameOver = true;
    stopFall();                    // clearInterval(timeout)
    sound_mc.gotoAndPlay("end");
    quitGame_mc.gotoAndStop(2);    // -> name-entry screen
    quitGame_mc._visible = true;
}
```

A lean one-line-per-tick heartbeat + targeted one-shot dumps (PMDIAG) in the
browser-WASM main loop established, in order:

1. **Not a hang.** The main-loop heartbeat keeps ticking after game-over
   (`cf=23 tmr=0`); the fall timer is cleared (`stopFall` → `tmr 1→0` works).
2. **Game-over is detected and `gotoAndStop(2)` runs to completion.**
   `ng_gotoFrameByMC` for `quitGame_mc` enters and exits OK (`newframe=2`), and
   it operates on the **same** `DisplayObject` the renderer draws
   (`&display_list[219] == mc->display_obj == found_obj`, depth 219).
3. **The sprite DL is correctly rebuilt to frame 2.** A render-side dump of
   `display_list[219].sprite_display_list` showed the game-over content
   (char1@1, char1@2, char61@3, ok_btn(62)@4, char63@7, name_txt(64)@8) — exactly
   `DefineSprite_65` frame 2. So neither the goto nor the DL build is at fault.
4. **The render walk skips it because `as_hidden == 1`.** The same dump showed
   `hidden=1` on `display_list[219]` even after `quitGame_mc._visible = true`.
   `tag.c:4766` skips any non-mask entry with `as_hidden` set, so the fully-built
   game-over screen never painted.

## Root cause

`quitGame_mc` is hidden during play by its **frame-script** `_visible = false`
(implicit-`this`), which compiles to the **`SetProperty` opcode** →
`actionSetProperty` **case 7**, which (since cont. 27) syncs
`mc->display_obj->as_hidden = 1`.

Game-over re-shows it with the **explicit** `quitGame_mc._visible = true`, which
compiles to a **`SetMember`**, not the opcode. The three SetMember-style
`_visible` setters in `action.c`
(`actionSetVariable` ~41133, `actionSetMember` ~46813, `setMCBuiltinProperty`
~54950) each set `mc->visible` but **never touched `as_hidden`** — cont. 27 only
patched the opcode path (paused_mc used implicit-`this` `_visible=false`). So
`as_hidden` stayed `1`, and the renderer skipped the now-visible sprite forever.

## The fix (`action.c`, 3 sites)

Add the same one-line `as_hidden` sync that `actionSetProperty` case 7 already
has to all three SetMember `_visible` setters:

```c
if (mc->display_obj != NULL)
    ((DisplayObject*)mc->display_obj)->as_hidden = new_vis ? 0 : 1;
```

This brings SetMember-form `_visible` into parity with the opcode form. The
field is only read in the browser-WASM render walk, so the change is inert in
all other modes (no trace/render change in NO_GRAPHICS / OFFSCREEN / HEADLESS).

## Verification

`tetris_gameover_probe.py` (new) drives play → level-up → OK, then runs the
game to a no-input single-column top-out (~110 s). After the fix the render dump
shows `hidden=0` with the frame-2 DL, and `go_final.png` (clean build, no
diagnostics) shows the **"game over" / "enter your name:" / "ok"** screen over
the board — previously completely absent.

## Follow-up 1 — game-over screen rendered BEHIND the blocks — FIXED

User-reported after the screen started showing: the game-over form drew *behind*
the board blocks. The board cells are `attachMovie`'d into `b_mc` (timeline
depth 198), but the browser-WASM attached-MC pass (`tag.c`) drew **all**
`child_mc_cache` clips *after* the entire timeline walk, assuming attached clips
sit above all timeline content. That holds only for clips attached to `_root`
(AS depth 16384+). `quitGame_mc` is a timeline object at depth **219 > 198**, so
the cells (parented to b_mc@198) painted over it.

**Fix (`tag.c`):** interleave attached clips at their parent's timeline depth.
After rendering `display_list[i]` in the main loop, render the `child_mc_cache`
clips whose parent's `display_obj == &display_list[i]`; the post-loop pass now
renders only root-attached clips (and nested-attached clips whose parent isn't a
timeline object), which correctly stay above all timeline content. Extracted the
per-clip render into `render_attached_child()`; added `attached_parent_dl_index()`.
Gated `!OFFSCREEN_RENDER && !HEADLESS_GRAPHICS` (those modes skip non-root
attaches), so browser-WASM-only; the refactored post-loop pass is
behavior-equivalent for root-parent clips in all modes. Verified: form now in
front of the blocks; board cells during play unchanged; DJ menu smoke clean.

## Follow-up 3 — name-field input — Selection API wired (browser-WASM), input now works

User-reported: can't type into the name field. Instrumented the whole chain
(reaching game-over via `tetris_gameover_interact_probe.py`, ~118 s):

1. **`Selection.setFocus(name_txt)` was a no-op in browser-WASM.** The entire
   Selection API (`setFocus`/`getFocus`/`setSelection`/`getBeginIndex`/…) was
   wired only under `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
   (`action.c` ~37655 + the forward decls ~34716). The impls are ungated.
   Browser-WASM had the `Selection` object but no methods, so
   `Selection.setFocus(name_txt)` resolved to **undefined**. Calling undefined
   also aborted the rest of `quitGame_mc` frame 2's DoAction (`script_14`),
   which is why `_root.pause_btn._visible = _root.quit_btn._visible = false`
   never ran (quit/pause stayed visible). **Fix:** remove both gates so the API
   is wired in all modes. NO_GRAPHICS/OFFSCREEN already had it → browser-WASM-only,
   not CI-observable. After the fix, SETFOCUS reports `name_txt` focused
   (`focusable=1 istf=1`).
2. **Keystroke routing already works.** `on_keypress` (`render_webgpu.c`,
   registered on the focusable `#canvas`) → `g_text_input_ring` → `swf.c` drain →
   `actionTextFieldInput` with `g_focused_mc == name_txt`. Confirmed end-to-end:
   chars A/B/C are inserted into `name_txt`.
   - **Harness gotchas** (documented in the probe): Playwright's
     `keyboard.type`/`press` does **not** emit the `keypress` event emscripten
     listens for (KEYDOWN fires, KEYPRESS doesn't) — dispatch a synthetic
     `KeyboardEvent('keypress', …)` instead. And a mouse **click** on the canvas
     clears the AS field focus, so don't click before typing.

**Residual — FIXED.** The focused input field rendered its typed text at the
wrong world position (top-left). `actionIterateTextFieldGlyphs` computed world
position as `mc->x + Σ(parent->x)`, but a TIMELINE-placed parent (quitGame_mc)
holds its placement in the root display-list transform, not `mc->x` (which stays
0). Instrumented: `name_txt mc=(-102.7,28), quitGame_mc x=0` → `world=(-102.7,28)`.
**Fix:** in the parent-chain walk, when a parent's `display_obj` points INTO the
global display_list (timeline-placed) and AS hasn't overridden `_x/_y`, add that
entry's placement-transform translation instead of `mc->x`. Now `world=(7.3,203)`
and the typed text renders inside the form. CI-observable (graphics text) — ran
graphics CI, **0 regressions** (all suites delta=0). Still minor:
`_root.pause_btn/quit_btn._visible=false` doesn't hide them (name-resolved button
MC has no linked `display_obj`, so the as_hidden sync no-ops).

## Follow-up 2 — `ok` button hover doesn't darken its text — FIXED

The state machine was fine: instrumentation confirmed `ok_btn` (char 62) reaches
the OVER state on hover, runs `button_62_frame_over`, and places its "ok" text
(char 31) with **cxform 97**, which the renderer received (`OKTEXT char31
cxform=97`). cxform 97 zeros RGB → black. But the **`CHAR_TYPE_TEXT` render path
used `ch->cxform_id`** (the DefineText's baked cxform), **ignoring
`obj->cxform_id`** (the placement = 97). So the placement darkening was dropped
and "ok" kept its up-state white. (Shapes already use `obj->cxform_id`; only text
glyphs had this gap.)

**Fix (`tag.c`):** in the TEXT path, compose the placement cxform over the baked
text cxform (`out = placement(baked(color))`) into a dynamic cxform slot via a new
`compose_cxform20()` (column-major mat4 mult + add, matching the shader's
`apply_cxform`). Guarded to fire only for a NON-identity BAKED placement slot
(slot 0 is identity; dynamic/composed slots are GPU-side) with a free dynamic
slot; otherwise unchanged (identity placement → baked cxform). Verified: "ok"
turns black on hover. CI-observable (graphics static text) — graphics CI run.

## Still open — the line-clear freeze (separate bug)

The reported line-clear freeze is **not** this bug. Line-clear
(`frame_4` `down()`, full-row branch) calls `stopFall()` then
`b_mc[...].bang_mc.play()` and does **not** restart the fall itself — it waits
for `bang_mc` (the explosion sprite, `DefineSprite_2`) to play through to
**frame 7**, whose script (`DefineSprite_2/frame_7`) collapses the rows,
decrements `simult`, and calls `startFall()` when `simult==0`. `bang_mc` is a
sprite nested two levels under an `attachMovie`'d `block` clip (char 10) inside
`b_mc`, so resumption depends on the **nested attached-clip playhead advance**
machinery — a known gap (cf. `dj-physics-measurements`: "nested children of
attachMovie'd clips don't run enterFrame after forced goto"), unrelated to
`_visible`/`as_hidden`. Driving a line-clear needs lateral input to fill a row
(`tetris_input_probe.py`); left for a follow-up session.

## Reproduce

```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics
# cleanup in a SEPARATE bash call (pkill self-matches the launching shell):
pkill -9 -f 'tetris_gameover_prob[e]'; pkill -9 chrome
DISPLAY=:0 GO_RUNTIME=130 /tmp/browser-test-venv/bin/python3 \
    tools/divergence/game_drive/tetris_gameover_probe.py
#   -> compare_out/go_final.png : game-over name-entry screen over the board
```
