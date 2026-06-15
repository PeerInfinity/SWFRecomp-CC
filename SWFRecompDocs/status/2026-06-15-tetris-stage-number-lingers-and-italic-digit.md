# Tetris stage number lingering after game start FIXED; italic "1" characterized

**Date:** 2026-06-15 (cont. 35)
**Bucket:** browser-WASM only (`invalidate_mc_for_dl_entry` is compiled only under
`#if !defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS) && !defined(OFFSCREEN_RENDER)`;
NO_GRAPHICS and graphics-native/OFFSCREEN never compile it) → **not CI-observable**,
verified with `tools/divergence/game_drive/tetris_compare.py`, no CI dispatch
(per `ci-only-when-observable`).

Two open Tetris issues from cont. 34:
- **(B) stage number stays visible after the game starts** — **FIXED** (this doc).
- **(A) stage-number digit "1" renders slanted/italic** — **CHARACTERIZED as a
  faithful render of a genuinely-italic embedded font glyph** (not a bug we
  introduce). See bottom.

---

## (B) The level-select "startLevel" number lingered over the game — FIXED

### Symptom
On the level-select screen the large stage number (the value the player picks
with the ◄ ► arrows) is correct, but after pressing OK and entering the game it
**stays drawn over the board** instead of disappearing. The small `level: N`
field in the score panel is a separate, correct field.

### Mechanism (instrumented, not guessed)
The number is **char 29**, a `DefineEditText` bound to the AS variable
`startLevel`, placed on the root display list at **depth 193** on the
level-select frame (`tagPlaceObject2Ratio(193, 29, …)` in `frame_2`). The next
frame removes it (`tagRemoveObject2(193)`) and reclaims depth 193 for `sound_mc`
(char 39).

DefineEditTexts render **only** via the dynamic glyph path
(`actionIterateTextFieldGlyphs`, which walks `child_mc_cache`) — the static
display-list draw is skipped for any char with a text-field index
(`render_display_list` / `render_single_object`). So the lingering draw comes
entirely from a `child_mc_cache` **wrapper MovieClip**, not the display list.

A one-shot/throttled diagnostic in both render walks showed:
- the **orphan walk** (`otf_walk_dl`, reads the display list directly) drew char 29
  once early, then a **wrapper MC** appeared and the **`child_mc_cache` walk** drew
  it on every subsequent tick: `depth=-16191 vis=1 text='1'` (then `'2'` after the
  up-arrow), persisting all the way into the game frame.
- `-16191 = 193 − 16384` is just the **normal AS-depth encoding** (`mc->depth =
  SWF depth − 16384` in `actionFindOrCreateMovieClip`), **not** a removed-zone
  marker — the wrapper is a perfectly normal cached MC.

Instrumenting `invalidate_mc_for_dl_entry` (the reclaim path's cleanup) at the
menu→game transition gave the root cause:

```
PMDIAG INVAL char29 obj=… matched=-1 tf_seen=1 tf_dobj=0 tf_depth=-16191
```

- `matched=-1`: **no** cached MC has `display_obj == &display_list[193]`.
- `tf_seen=1, tf_dobj=0`: the char-29 wrapper exists but its **`display_obj` is
  NULL**.

`invalidate_mc_for_dl_entry` matches the MC to invalidate **only by
`mc->display_obj == obj`**. Root-placed `DefineEditText` wrappers are created
lazily by **name lookup** (`actionFindOrCreateMovieClip`, which sets
`ng_textfield_idx` + `depth` but never links `display_obj` — only sprites get
`display_obj` set, via `exec_sprite_frame`). So the reclaim's invalidate scan
misses the wrapper, it survives in `child_mc_cache`, and
`actionIterateTextFieldGlyphs` keeps drawing its bound `startLevel` value forever.

### The fix (`tag.c`, `invalidate_mc_for_dl_entry`)
Add a fallback after the primary `display_obj` scan: when the removed/reclaimed
entry is a **text field** (`ng_find_textfield(obj->char_id) >= 0`) and the
primary scan found nothing, match the orphaned wrapper by the **AS-depth that
corresponds to this SWF depth** (`(obj − display_list) − 16384`) plus the
text-field index, and invalidate it. Guards:
- compute the SWF depth via `uintptr_t` arithmetic and verify
  `&display_list[d] == obj` so a (hypothetical) sprite-child entry can't be
  misread as a root depth;
- require `display_obj == NULL` and an exact `ng_textfield_idx` + `depth` match,
  so a text field still legitimately placed at a different depth is never
  touched.

The primary loop's `break` became `return` so a successful `display_obj` match
skips the fallback (equivalent before — nothing followed the loop).

### Verification (`tetris_compare.py`)
With the fix, the diagnostic confirmed: wrapper created **once** (`TFCREATE … is_new=1`),
drawn until the transition, then `FBINVAL … invalidated` fires on the frame that
reclaims depth 193, and char 29 **never renders again**. `compare_ok.png` (clean
build, no diagnostics) shows the SWFRecomp game board (pieces falling/stacking,
level/lines/score panel, quit/pause) with **no stage number** over the play area,
matching Ruffle. `compare_menu/play/up` unchanged.

### Scope / risk
Browser-WASM-only render-lifecycle code; the fallback only fires for orphaned
text-field wrappers with no `display_obj` link sitting at the exact reclaimed
depth. Cannot affect NO_GRAPHICS / OFFSCREEN (not compiled there) → no CI.

---

## (A) The slanted/italic "1" — our geometry is correct; the gap is anti-aliasing

**Root-caused and confirmed against ground truth (real Flash + Ruffle). NOT a glyph,
parse, or tessellation bug — it is an anti-aliasing fidelity difference.**

What I verified:

- **The level number uses font 12 "Wide awake Black"** (the decorative title font),
  glyph index **5** = correctly code `'1'` (`font_12_codes[5] == 49`). `FontID=12`
  with the `UseOutlines`/embedFonts flag set (`flags=0x98`), so the field genuinely
  renders with the embedded outlines, not a device font.
- **Font 12 is a uniformly OBLIQUE font.** I dumped all 42 glyphs from the recompiler
  and measured each glyph's top-vs-bottom horizontal shift: **almost every glyph —
  digits and letters alike — leans by the same ~135-unit shear (~10°)** (`0`/`2`/`3`/
  `5`/`6`/`8`/`9`/`e`/`o`/`r`/… all = 135; `i`/`l` = 152). The "1" is **not** specially
  slanted; it leans the same ~10° as the whole font.
- **Our parse is correct.** The raw SWF edge records for the "1" encode the two side
  strokes as **general lines with `dx=±135`** (verified by logging the recompiler's
  edge reader: `DBGEDGE general dx=135 dy=-768` / `dx=-135 dy=768`), i.e. a genuine
  parallelogram — not vertical lines we sheared. Ruffle's own `swf` crate
  (`read.rs::read_shape_record`) reads the same general-line deltas, so **Ruffle ends
  up with identical geometry.**
- **Why ours looks like a harsh `/`:** the "1" is a thin bar (~154 wide) and the lean
  (135) is nearly the bar's full width, so the top sits almost entirely to the right
  of the bottom. The same 10° that's invisible on a wide letter is stark on a thin
  bar. Our glyph render is uniform scale+translate (no skew added), so the rendered
  slant **equals** the font's true slant.

**Ground-truth confirmation (user test):** in both Ruffle and the Basilisk official
Flash player, zooming in shows the "1" **does** have the slight slant — it is just
**mostly hidden by anti-aliasing**. So Flash/Ruffle render the same oblique geometry
we do; their rasterizer softens the thin slanted bar into a near-vertical stroke,
while our hard-edged WebGPU triangle fill shows the slant crisply.

**Conclusion:** our render is geometrically faithful to the embedded font. The visible
difference is an instance of the **known "our glyph anti-aliasing differs from Ruffle"**
gap (other AA differences were noted previously and deprioritized). **No render change
made** — the geometry is correct; closing this would require glyph-edge anti-aliasing
in the renderer, a broader change. **Low priority** (user-confirmed). Not a
device-font-substitution issue (an earlier draft of this doc speculated that; the
user's zoom test disproved it).

## Reproduce
```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics
# cleanup in a SEPARATE bash call (pkill self-matches the launching shell):
pkill -9 -f 'tetris_compar[e]'; pkill -9 chrome; rm -f tools/divergence/game_drive/compare_out/pmdiag.log
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/tetris_compare.py
#   -> compare_out/compare_ok.png : SWFRecomp game board, no stage number overlay
```
Note: `tetris_compare.py` element screenshots currently time out under WSLg
(a capture-latency artifact, not a hang); the harness still writes the compare
PNGs and the PMDIAG console log.
