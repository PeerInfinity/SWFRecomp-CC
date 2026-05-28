# 2026-05-27 — Snake keyboard input (browser-WASM)

Follow-up to the wasm-probe / B-group fixes (`dd16c9a20` … `5d5d157a0`).

## TL;DR

- **Symptom:** In browser-WASM, Snake gameplay was unsteerable. After clicking SLUG to start, the snake walked straight south to GAME OVER. Pressing arrow keys did nothing.
- **Two gaps in `swf.c` (browser-WASM main loop) vs `swf_core.c` (NO_GRAPHICS / OFFSCREEN_RENDER):**
  1.  No `dispatch_button_key_actions(app_context, code)` call. SWF5-era `on(keyPress "X")` button conditions never fired. Snake (SWF 5) wires arrow keys via button-29's keyPress conditions (cond codes 1/2/14/15 = Left/Right/Up/Down at `tagPlaceObject2(13, 29, …)` on frame 50) — the only AVM1 keyboard pattern available pre-`Key.addListener`. Without the dispatcher, the button actions that update `xv`/`yv` were dead code.
  2.  No `dispatch_clip_event_flag(CLIP_EVENT_KEY_DOWN / KEY_UP)` calls on key transitions. Sprites with `onClipEvent(keyDown)` handlers got nothing in browser-WASM. Snake itself doesn't use these, but other SWFs do (and `swf_core.c` already fires them at EV_KEY_DOWN/UP).
- **Plus one orthogonal frame-collapse bug uncovered while fixing 1+2:** `swf.c`'s key-transition loop is snapshot-based — it compares `prev_keys_down[code]` to `keys.down[code]` once per ~16ms tick. Playwright's `page.keyboard.press()` fires keydown + keyup synchronously in JS, both within one tick. The DOM handler sets `keys.down[code]=1` then immediately `=0`, and by the time swf.c looks both `prev` and `cur` are 0 → no transition detected. Real keyboards exhibit the same collapse if a key is tapped during one frame (uncommon at 60 Hz, but possible).
- **Fix:** added `edge_down[256]` / `edge_up[256]` latches to `KeyState`. `on_key_down` / `on_key_up` set them; swf.c's transition loop also fires on the latch (then clears it). `keys.down[]` polling for `Key.isDown` is unchanged.

This handoff covers a single commit landing all three pieces together.

## Files changed

- `SWFModernRuntime/include/libswf/swf.h` — extend `KeyState` with `edge_down[256]` / `edge_up[256]`.
- `SWFModernRuntime/src/rendering/render_webgpu.c` — `on_key_down` / `on_key_up` set the new edge latches alongside `keys.down[]`.
- `SWFModernRuntime/src/libswf/swf.c` — key-transition loop now fires on `(cur && !prev) || edge_down[code]` (and symmetric for up), invokes `dispatch_clip_event_flag(CLIP_EVENT_KEY_DOWN)` + `dispatch_button_key_actions` (then falls back to `actionDispatchKeyPressToFocused`) on press, and `dispatch_clip_event_flag(CLIP_EVENT_KEY_UP)` on release. Mirrors `swf_core.c`'s EV_KEY_DOWN / EV_KEY_UP arms.
- `tools/browser-test/baseline-probes/snake_keyboard.py` — new baseline probe; clicks SLUG, then issues ArrowRight / Down / Left / Up with 2 s settle each. Visual check: the snake should change direction visibly between shots. Without the fix, all four post-key shots show GAME OVER.

## How the diagnostic chain worked

1.  Confirmed the prior session's `snake_gameplay.py` reliably starts gameplay (slug-click landed; snake spawns then walks south into the wall → GAME OVER). Click-reliability was a non-issue.
2.  Grepped Snake's `RecompiledScripts/script_*.c` for `Key|isDown|onKeyDown|onClipEvent` — zero matches. Then grepped `RecompiledTags/tagMain.c` for `button_.*_actions` — found `button_29_actions` with conditions `0x1c00 / 0x200 / 0x1e00 / 0x400 / 0x4000` → cond codes 14 / 1 / 15 / 2 / 32 → Up / Left / Down / Right / Space. So Snake uses SWF5 button keyPress, not `Key.isDown` polling.
3.  Grepped `Doodle_Jump/RecompiledScripts/script_*.c` for the same — `script_defs.c` has `"Key"` and `"isDown"` strings. DJ uses `Key.isDown(38)` polling. Confirmed the divergence: DJ works because polling reads the always-updated `keys.down[code]`; Snake fails because keyPress dispatch was never wired in browser-WASM.
4.  Read `swf_core.c` EV_KEY_DOWN arm (lines ~615-690) and `swf.c` key transition loop (lines ~479-528). `swf.c` calls `actionDispatchKeyDownToFocused` + `actionDispatchKeyDown` + `actionDispatchKeyPressToFocused` but **not** `dispatch_button_key_actions` or `dispatch_clip_event_flag(CLIP_EVENT_KEY_DOWN)`. Gap confirmed.
5.  Added the two dispatchers (mirroring `swf_core.c`'s ordering: clip event → focused-MC handler → global Key broadcast → button keyPress → focused button press fallback). Rebuilt Snake `--graphics`, redeployed, ran the keyboard probe — still all four arrow shots showed GAME OVER, but added a `printf("[KBD]…")` after `dispatch_button_key_actions` printed exactly one line per probe run, for the Down key only.
6.  Realized Playwright's `page.keyboard.press()` fires keydown + keyup in the same JS turn → both arrive at the DOM handler before swf.c next polls → `keys.down[code]` flips up then down again, no transition observed at frame boundary. Only the Down key happened to land in a frame where the up-event followed the next swf.c tick by chance.
7.  Added `edge_down[]` / `edge_up[]` latches set in the DOM handlers, consumed by swf.c. Rebuilt; all four arrow keys now fire one dispatch each, snake responds visibly: Right → east wall, Down → SE corner, Left → S-center, Up → mid-center vertical pair.

## Why the regression surface is small

- `Key.isDown(code)` reads `keys.down[code]` — unchanged; DJ continues working (verified via the `dj_menu` + `dj_info` baseline probes).
- `Key.addListener(obj).onKeyDown` fires via `actionDispatchKeyDown(app_context)`, called in the same place as before. Order preserved.
- `actionDispatchKeyPressToFocused` (Enter / Space on the focused button) is now gated behind `if (!key_press_handled)` — matches `swf_core.c`. Tests that exercise focused-button Enter/Space (e.g., tab focus → Enter to click) still work because no display-list button has a matching keyPress condition for those keys in the affected SWFs.
- `dispatch_clip_event_flag(CLIP_EVENT_KEY_*)` was previously not firing in browser-WASM, so any SWF that relied on it was already broken under graphics-WASM. Adding it cannot regress anything that worked before.
- The edge latch is additive: snapshot-based transitions still fire as before. The only behavioral change is that a press collapsed inside one tick now ALSO fires (previously it was silently lost).

## Verification

- `tools/wasm_probe_runner.py` — 8/8 pass (rebuilt + redeployed every probe so the new `KeyState` struct size matches).
- `tools/browser-test/baseline-probes/snake_keyboard.py` — visual confirmation Snake responds.
- `tools/browser-test/baseline-probes/snake_gameplay.py` — unchanged baseline (no input → snake walks south to GAME OVER).
- `tools/browser-test/baseline-probes/snake_title.py`, `dj_menu.py`, `dj_info.py`, `pong_loading.py` — all visually intact.
- `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle` → `Trace: identical 407=407`.

## Don't-touch additions (extend the cumulative list)

- `KeyState.edge_down[256]` / `edge_up[256]` must be set by every DOM-bridge keyboard handler. Today only `render_webgpu.c::on_key_down/up` writes them; if a new keyboard entry point lands, add the same latch writes.
- `swf.c`'s key-transition loop is the only consumer that clears the latches. `swf_core.c` does not need them — its event queue model fires synchronously and never collapses keydown+keyup into one tick.
- `dispatch_button_key_actions` and `dispatch_clip_event_flag(CLIP_EVENT_KEY_*)` calls in `swf.c` mirror `swf_core.c` line numbers ~616 / ~672 / ~700. If `swf_core.c`'s ordering ever changes, update `swf.c` in lockstep.
