# Minesweeper difficulty-screen interactivity — DONE

**Date:** 2026-06-17 (continuation of the interactivity handoff)
**Game:** flasharchive/Minesweeper, browser-WASM graphics
**Commit:** `e86241173`
**Bucket:** needs-browser (verified in real headed Chrome; smoke screenshots
unreliable for the final visual per gotcha #8 — console instrumentation +
Ruffle ground-truth used for the verdict).

All five goals from `2026-06-17-minesweeper-interactivity-handoff.md` work:

1. **Radio buttons clickable** ✓ — click anywhere on Easy/Medium/Tough (circle
   OR label) selects it, the ◉ dot moves with exclusive selection, and
   `switchLevel` runs (`_root.bombs_amount` = 40/70/100, confirmed by starting
   the game with the matching mine count).
2. **Text field** ✓ — click the "Enter your name" box focuses it; keyboard entry
   inserts characters (`anonymous` → `anonymousXy`, confirmed at the data level).
   No code change needed — the infra already existed.
3. **Start button click** ✓ — release action fires, advances to the game screen.
4. **Start button hover** ✓ — over-state engages (the "Start" label turns red).
5. **Cursor** ✓ — `pointer` over the Start button, `text` (I-beam) over the name
   box, `default` elsewhere.

## Root causes (each re-confirmed with fresh instrumentation, not the handoff's
## hypotheses)

### Start button un-clickable — RECOMPILER bug (CI-observable, both modes)
The handoff assumed the Start button "probably already works." It didn't:
`ng_update_button_states` hit-tested cid 53 every frame but always missed. The
composed matrix was correct (mouse dead-center), but `ng_hitTestShapeChar`
returned 0 because the recorded hit shape (**cid 52**) is **stroke-only**
(`fill0=fill1=0` on every edge — a beveled border). A stroke-only shape only
hit-tests on its edges; the interior misses in BOTH our hit test and Ruffle's
`shape_hit_test` (verified by reading `render/src/shape_utils.rs`). Ruffle still
advances on a center-click (verified with `minesweeper_ruffle_click.py`) because
a button's StateHitTest region is the **union of ALL 0x08 records**, and cid 53's
records include cid **48** — a solid-fill invisible rectangle (the real hit area)
— flagged `0x0f` alongside cid 52's `0x0c`. SWFRecomp keeps a single hit char and
the old logic took the LAST shape (cid 52). Fix: rank hit candidates (filled
shape > any shape > non-shape), prefer the highest, ties keep the last (so
single-hit-shape buttons are byte-identical). `Start` now uses cid 48 → clickable
+ hover + cursor all "free" from the engaged state machine.

### Radios un-clickable — stage position + container AABB (browser-WASM only)
The radio component MCs (`level_eazy/medium/tough`) ARE in `child_mc_cache` with
`hitArea` set, and `actionDispatchMCPress` already walks the prototype chain
(finds `FRadioButtonClass.prototype.onPress`). The only blocker was
`mc_get_pixel_aabb_ng` returning 0: (a) the registerClass MC's `_x/_y` was (0,0)
— its stage position lived only in `display_obj`'s transform (cont.40g set
_xscale/_yscale but not _x/_y); (b) the radio has no graphics of its own — its
extent is the attached children (circle + label), which aren't in its
`sprite_display_list` and have no draw bounds. Fixes: set `_x/_y` from the
placement matrix in `exec_sprite_frame`; union the attached children's stage
bounds for container MCs with no own bounds. The unloadMovie'd `boundingBox_mc`
editor rectangle (100×103, lingers in `child_mc_cache`) was inflating/overlapping
the radios — fixed by marking it `unloaded` in the immediate-unload path and
treating unloaded MCs as having no hit area.

### Sibling-deselect (two dots) — for..in over MovieClip (browser-WASM only)
`FRadioButton.setState(true)` deselects siblings via
`for(var i in this._parent) this._parent[i].setState(false)`. The child-MovieClip
enumeration in `actionEnumerate`/`actionEnumerate2` was gated
`#if NO_GRAPHICS || OFFSCREEN_RENDER`, so in browser-WASM `for..in` over `_root`
never yielded `level_eazy/medium/tough` → the loop was empty → the previously
selected dot never cleared. Un-gated (CI modes already compiled it →
byte-identical).

### Cursor over text box (browser-WASM only)
The cursor EM_ASM only set `pointer` for buttons (`any_hover`). Added
`actionMouseOverFocusableTextField` → `text` (I-beam) over a focusable/editable
field; buttons still take precedence.

## Files
- `SWFRecomp/src/swf.cpp` + `context.hpp` — hit-char ranking + `filled_shape_char_ids`.
- `SWFModernRuntime/src/libswf/graphics_stubs.c` — registerClass MC `_x/_y` from placement.
- `SWFModernRuntime/src/actionmodern/action.c` — `mc_get_pixel_aabb_ng` child-union +
  unloaded skip; `for..in` child enumeration un-gate; `actionMouseOverFocusableTextField`.
- `SWFModernRuntime/src/libswf/tag.c` — cursor I-beam over text fields.
- `SWFModernRuntime/src/libswf/tag_stubs.c` — `unloadMovie` marks the emptied clip `unloaded`.

## Verification / gates
- Real-browser (headed Chrome) probes: `minesweeper_click_probe.py` (click radios/
  Start), `minesweeper_hover_probe.py` (cursor), `minesweeper_text_probe.py`
  (focus + keyboard), `minesweeper_ruffle_click.py` (Ruffle ground truth). All
  committed under `tools/divergence/game_drive/`.
- OFFSCREEN no-regression gate: Minesweeper divergence trace unchanged (634 lines).
- Regression smokes (browser-WASM): Tetris (play→gameplay, buttons work) + Doodle
  Jump (menu renders, play button works, cursor=pointer) — clean, no crash.
- CI: recompiler change is CI-observable → dispatched both modes (no-graphics +
  graphics).

## Process note
Same lesson as the whole saga: every handoff hypothesis was wrong until
re-confirmed with fresh instrumentation. The Start button was NOT "probably
working" (recompiler bug), the radio blocker was NOT the hitArea property (it's
set fine — the blocker was the missing AABB), and the text field needed NO code
(Playwright just wasn't delivering `keypress`).

## Deferred (LOW priority, unchanged from cont.40i)
- Selected dot renders slightly up-and-left of centre.
- Radio ring shading (glossy bead vs Ruffle's flat circle).
- The game-board grid cells don't render after Start (separate cell-render gap,
  out of scope for the difficulty-screen interactivity task).
