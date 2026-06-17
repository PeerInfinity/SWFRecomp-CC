# Minesweeper browser-WASM interactivity — session handoff

**Date:** 2026-06-17 (scouting only — NO code changed)
**Game:** flasharchive/Minesweeper, browser-WASM graphics ONLY
**Bucket:** needs-browser (invisible to CI / divergence harness; the human's
real-browser eyeball is the verdict). Smoke screenshots are unreliable for the
final frame (headed-Chrome rAF throttling, guide gotcha #8) — fine for "no crash"
and reading instrumented console.

## Goal (next session)

Make the difficulty screen interactive:
1. **Radio buttons** clickable (click Easy/Medium/Tough → selects that difficulty,
   moves the ◉ dot, runs the `switchLevel` changeHandler → sets `_root.bombs_amount`).
2. **Text field** ("Enter your name" = `anonymous`) clickable → focus + caret +
   keyboard text entry.
3. **Start button** (cid 53, DefineButton2) clickable → runs its release action.
4. **Start button hover** → changes color (its over-state).
5. **Cursor** → hand/pointer over the Start button and (I-beam or hand over) the
   text box.

Predecessor work (cont.39–40i, all committed): the radios now CONSTRUCT, render
their circles+labels, and the default Medium ◉ selects. See
`2026-06-16-minesweeper-browser-wasm-registerclass-ctor.md`. This handoff is the
NEXT layer (input), a different subsystem.

## The browser-WASM input pipeline (already exists — reuse it)

`swf.c` main loop (the `#ifndef OFFSCREEN_RENDER` arms ~line 510-605) reads
`app_context->mouse` and dispatches:
- **`mouse.clicked`** → `actionDispatchMCPress(app_context)` (action.c ~70050) +
  clip-event PRESS.
- **`mouse.released`** → `actionDispatchMCRelease` (action.c ~70074) +
  clip-event RELEASE.
- **`mouse` move** → clip-event ROLL_*/MOUSE_MOVE.
- `mouse.stage_x/stage_y` are in **twips** (÷20 → pixels).

Two SEPARATE interactive-object paths:
- **Sprite/MC handlers** (`onPress`/`onRelease`/`onRollOver`… as MC properties or
  RegisterClass-prototype methods): `actionDispatchMCPress`/`Release` iterate
  `child_mc_cache`, AABB-hit-test each via `mc_get_pixel_aabb_ng(mc)`, and call
  `mc_call_as2_handler_ng(mc, "onPress"/…)`. **`mc_call_as2_handler_ng`
  (action.c ~69936) walks the prototype chain** (`getPropertyWithPrototype`), so
  RegisterClass-prototype handlers (the radios' `FRadioButtonClass.prototype.onPress`)
  DO resolve — IF the MC is in the iterated set and gets hit.
- **DefineButton state machine** (baked `on(release)` actions + up/over/down
  states): `ng_update_button_states(app_context)` → `ng_update_button_states_in_dl`
  (tag.c ~2692), called from `tagShowFrame` (tag.c ~4727). It hit-tests buttons,
  drives state transitions, runs baked actions, AND fires AS-assigned handlers via
  `actionFireButtonAS2Event` (action.c ~70114). Its return value `any_hover`
  drives the **cursor**: `tag.c ~4729` `EM_ASM(... canvas.style.cursor = $0 ?
  'pointer' : 'default')`. **So hand-cursor-on-hover already exists, but only for
  DefineButtons.**

## Per-element status + likely gaps + entry points

### Start button (cid 53, DefineButton2) — START HERE (probably closest to working)
- Placed on root: `frame_4` `tagPlaceObject2Ratio(app_context, 3, 53, 186, …)`
  (depth 3). Baked release action = `button_53_actions`. Up/over/down/hit =
  `button_53_state_funcs`.
- It SHOULD already route through `ng_update_button_states` → hover color (over
  state) + cursor=pointer + release action. **First task: verify in a real
  browser** whether clicking Start does anything and whether hover changes its
  color. If not, instrument `ng_update_button_states_in_dl` (does it hit-test cid
  53? does the over-state func run? does button_53_actions fire?). The hover-color
  is "free" if the state machine engages — the over state is a baked button state.
- Decompiled action: `scripts/DefineButton2_53/BUTTONCONDACTION on(release).as`.

### Radio buttons (FRadioButton components) — the hard one
- The radio MCs are `level_eazy`/`level_medium`/`level_tough` (timeline-placed,
  cid 37, RegisterClass'd). Handlers are **prototype methods**:
  `FRadioButtonClass.prototype.onPress` = `this.frb_states_mc.gotoAndStop("press")`;
  `.onRelease` = `gotoAndStop("unselectedDisabled"); this.setValue(!this.selected)`.
  (Decompiled: `scripts/FRadioButtonSymbol.as`.)
- Flash hit-detection uses **`this.hitArea = this.frb_hitArea_mc`** (a wide,
  `_visible=false` shape; see `FRadioButton.setHitArea`). Clicking the hitArea (or
  anywhere on the component) must fire the PARENT radio's onPress/onRelease.
- **Gaps to confirm with fresh instrumentation (don't trust this list blindly —
  process lesson from the registerClass saga):**
  1. **Is the radio MC in `child_mc_cache`?** `actionDispatchMCPress` only iterates
     `child_mc_cache`. The radios are timeline-placed (not attachMovie'd), so they
     may NOT be there → never hit-tested. Their *children* (frb_hitArea_mc /
     frb_states_mc / fLabel_mc) ARE attached → in the cache. (Verify which.)
  2. **hitArea → parent redirect:** even if `frb_hitArea_mc` is hit, the dispatch
     fires `frb_hitArea_mc.onPress` (none), not `radio.onPress`. AS sets
     `radio.hitArea = frb_hitArea_mc`; the dispatch needs to honor `mc.hitArea`
     (fire the owner's handler when the hitArea is hit). Grep `hitArea` —
     action.c ~21039 has a comment about `frb_hitArea_mc` but check whether the
     `hitArea` *property* is actually consulted during hit-test (likely NOT).
  3. **`_visible=false` skip:** `frb_hitArea_mc._visible=false`. Confirm the
     dispatch doesn't skip invisible MCs (a hitArea is invisible by design but must
     still hit-test).
  4. **Radio AABB excludes attached children** (the cont.40c "5th gap"):
     `mc_get_pixel_aabb_ng(radio)` may be just the circle, not the full component —
     so even a direct radio hit-test misses the label. The hitArea path sidesteps
     this if (2) is solved.
- Likely cleanest fix: in `actionDispatchMCPress`/`Release`, when an MC has a
  `hitArea` property pointing at another MC, hit-test the hitArea's bounds but fire
  the owner's handler; and ensure the radio MCs (or their hitAreas) are in the
  iterated set. Mirror how OFFSCREEN/NO_GRAPHICS does radio hit-testing if it does.

### Text field (the name box) — focus + keyboard
- `actionDispatchMCPress` explicitly SKIPS text fields ("clicking them acquires
  focus instead", action.c ~70058, guard `mc->ng_textfield_idx >= 0`). Find where
  click→focus actually happens for a textfield in browser-WASM (Selection infra
  exists: `builtin_selection_setFocus`, `g_selection_caret`, action.c ~34800+).
- Tasks: click → focus + caret render; keyboard events → insert/delete chars into
  the field; cursor (I-beam or hand) on hover. The keyboard path: check how
  `mouse`/`key` events reach the runtime in browser-WASM (the canvas key listener
  → `app_context` → `input_events`?), and whether an editable EditText consumes them.

### Cursor (hand/I-beam)
- Hand cursor on button hover already works (`tag.c ~4729`, gated on
  `ng_update_button_states` returning any_hover). To extend to the radios and text
  box: either make those participate in the `any_hover` computation, or add a
  parallel hover check that ORs into the cursor EM_ASM. Keep it one place.

## Recommended first steps (next session)
1. **Real-browser verify the Start button FIRST** (it's likely closest): does it
   hover-highlight / click? That calibrates how much of the button path works and
   whether the cursor infra is firing. Instrument `ng_update_button_states_in_dl`
   if not.
2. Then the radios: instrument `actionDispatchMCPress` — print every
   `child_mc_cache` MC name + AABB + whether a click hits it, on a click at the
   Medium radio. Determine which of gaps 1-4 above are real. Diff against
   NO_GRAPHICS/OFFSCREEN radio hit-testing if that path exists.
3. Text field + cursor last.

## Repro / test loop (run probes DIRECTLY, never via `timeout … | tail` — SIGPIPE)
```
source emsdk/emsdk_env.sh
# temp DBG: SWFRecomp/scripts/build_test.sh line ~253 EXTRA_DEFINES="-DMINESWEEPER_DBG"
SWFRecomp/scripts/build_test.sh flasharchive/Minesweeper wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Minesweeper "$(pwd)/docs2/examples" --no-index --graphics
# console capture (clicks Run only — extend to click radios/Start for input):
DISPLAY=:0 /tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/dbg_capture.py Minesweeper 12 "MSDBG"
# DBG → stderr (fprintf) so it shows in browser console AND keeps OFFSCREEN
# trace.txt clean. Strip all DBG before committing (grep MINESWEEPER_DBG\|MSDBG) +
# reset build_test.sh EXTRA_DEFINES="".
```
The existing harnesses (`dbg_capture.py`, `smoke_demo.py`) only click the demo's
"Run" button — to test clicks ON the radios/Start you'll need a small Playwright
driver that clicks at canvas coordinates (see `tetris_*_probe.py` /
`tetris_fall_probe.py` `FRAC`/`held_click` for the click-at-fraction pattern).
Ruffle ground truth: `tools/divergence/game_drive/minesweeper_ruffle_capture.py`.

## Constraints
Trunk-based, commit to master with the Co-Authored-By trailer. Input-path code in
`action.c` (`actionDispatchMCPress`/`Release`, hitArea) is SHARED/CI-observable —
gate browser-WASM-only changes `!NO_GRAPHICS && !OFFSCREEN_RENDER` and keep CI
modes byte-identical, OR if changing shared behavior, dispatch CI and check the
suite. `ng_update_button_states_in_dl` / cursor are graphics-only. Regression-smoke
Tetris + Doodle Jump (both have clickable buttons via these same paths) for any
change to `actionDispatchMCPress`/`Release` / `ng_update_button_states` / the
cursor EM_ASM. Local OFFSCREEN no-regression gate (Minesweeper trace must stay
634 lines):
```
/tmp/browser-test-venv/bin/python3 tools/divergence/divergence_test.py \
  SWFRecomp/tests/flasharchive/Minesweeper/test.swf --frames 16 --skip-ruffle
```

## Still-open cosmetic items (LOW priority, from cont.40i)
- Selected dot renders slightly **up-and-left** of centre (suspect cid-28-holder
  `transform_id` not the placed value at compose — see the cont.40i status section).
- Radio ring SHADING (glossy bead vs Ruffle's flat circle).
