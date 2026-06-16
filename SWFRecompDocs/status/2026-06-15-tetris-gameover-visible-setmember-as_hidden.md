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

## Follow-up 2/3 — still open (game-over screen interactivity)

Both reported by the user, both deeper than the render fixes above:

- **(2) `ok` button hover doesn't darken the "ok" text.** The cursor DOES change
  to a pointer on hover, so the nested-button hit-test fires
  (`ng_update_button_states_in_dl` recurses into `quitGame_mc`'s sprite DL and
  composes the placement transform). The gap is the OVER-state **visual** not
  rendering for this nested button — needs browser instrumentation to localize
  (state rebuild vs. render of the rebuilt state DL). Bounded but not yet done.
- **(3) Can't type into the `name_txt` field.** `name_txt` (char 64) is an INPUT
  TextField inside `quitGame_mc`; `Selection.setFocus(name_txt)` is called on
  game-over. Editing requires routing keydown to the focused input field +
  mutating/re-rendering its text + caret — a substantial input-text-editing
  feature, not a small fix.

Both need a repro that reaches game-over (~110 s no-input top-out) then drives a
hover / keystrokes; left for a focused follow-up session.

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
