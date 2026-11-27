# s29 w2-pixel-gaps-land: report (wave 2, implementation)

**New files:**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-pixel-gaps-land-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-pixel-gaps-land.patch`
- `ruffle-tests/flash_fixes/visual/simple_shapes/text_field_mask/output.expected.png` (= coordinator FP32 LOW capture `w1-local-oracles/w1-pixel-flash-gaps/text_field_mask.low.png`, byte copy)
- `ruffle-tests/flash_fixes/from_shumway/gradientTransform/output.expected.png` (= `.../gradientTransform.low.png`, byte copy)

**Modified:** `SWFModernRuntime/{include/actionmodern/action.h, src/actionmodern/action.c, src/libswf/tag.c,
src/rendering/render_webgpu.c}`, `ruffle-tests/flash_fixes/{fixes.json, README.md}` (2 entries, appended),
`ruffle-tests/render_canary_tests.txt` (2 members appended at EOF),
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (1 entry appended at EOF).

**The patch is wider than the brief's path list.** It also carries the flash_fixes files (with `--binary` for the two
PNGs) and the RvF entry, so applying it lands the two swaps. Apply it with `git apply --binary`.

Base: `origin/master` `9c9c18574` (code = `bfa47037b` plus `ab49742e` paletteMap). Upstream Ruffle at download time:
`952362ecf` (2026-11-26). Categories downloaded: visual, from_gnash, from_shumway, avm2, avm1, fonts, text, timeline,
swf, import_assets, audio, mixed_avm, stage3d. flash_fixes: 64 applied cleanly, plus my 2.
**Fidelity:** my master renders are md5-identical to CI's `ruffle-image-results` actual PNGs on 6 rows
(`text_field_mask`, `gradientTransform`, `avm1_color`, `acid-shapes`, `place_object_test`, `graphics_simple_shapes`).
Local grading is therefore CI-grade on those rows.

## Verdicts (lead)

| item | verdict | priced moves (by name) |
|---|---|---|
| **C**: unfiltered cacheAsBitmap is not snapped at HIGH | **LANDED** | `visual/cache_as_bitmap/avm1_color` (FP32 golden) 1200 → **230** (max 192 → 1; still fails at tol 0). `scroll_rect_scaled` 799 → 697 (pass → pass). 0 other moves on 41 HIGH/LOW cacheAsBitmap rows |
| C pricing of script-set `cacheAsBitmap` HIGH rows (w1 lead 5) | **done: 0 moves** | I scanned every image row's SWF (zlib and LZMA decompressed) for `cacheAsBitmap` and the PlaceObject3 flag. That gives 26 HIGH rows: `avm2/{bitmapdata_copychannel,bitmapdata_draw_cab_quality,graphics_bitmap_fill}`, `acid-mask`, 7 regression rows, 2 blend_modes rows and 14 `cache_as_bitmap/*`. No `avm1/` row sets it from script. All are md5-identical except the two above. AVM2 has no unfiltered snap at all (`avm2_display.c` snaps filtered caches only), so C can only reach the AVM1/timeline path |
| **A**: LOW glyph pen → whole device px (plain embedded fields) | **LANDED, no narrowing** | `text_field_mask` vs FP32 LOW **2404 → 1336** (toward Flash). Gnash ledger as in w1. One new Ruffle-golden loss w1 did not see: `text/style_changes_in_html` 688 → 3278 vs its golden, but **24 332 → 23 938 vs FP32 LOW** (toward Flash) |
| **B**: drawing-API centre ¼-px grid only on axis-aligned segment ends | **LANDED** | `acid-shapes` failing checks 6 → 2 (over at tol 16 / 32: 184 / 243 → 85 / 88). `graphics_simple_shapes` 124 → 114, `graphics_gradients` 304 → 293. Ruffle rows `graphics_bitmaps`, `displayobject_getbounds_shape` and `graphics_direct_commands` stay pass → pass. The n-drawapi-stroke-snap rows are all unchanged |
| flash_fixes `visual/simple_shapes/text_field_mask` | **ADDED** | upstream sha256 `245bbbe5…7b137`, verified on my fresh download. Golden → FP32: 2378 ch. Ours → FP32: master 2404, A 1336. Fails either way |
| flash_fixes `from_shumway/gradientTransform` | **ADDED** | upstream sha256 `e5c1b699…c6c31`, verified. The golden is FP32 HIGH exactly. Ours → FP32 LOW: 3 ch over tol 3 (max 21), at master and with the patch alike. Against the old golden it was 6 over (max 9). Fails either way |
| Kill switches | **3, verified** | `SWF_TF_LOW_PEN_SNAP=0` (or `-DTF_GLYPH_NO_LOW_PEN`), `SWF_STROKE_CENTRE_QSNAP_ALL=1` and `SWF_CAB_HIGH_SNAP=1`. With all three set, the 17 headline tests (22 PNGs) are md5-identical to master. `SWF_TF_LOW_PEN_SNAP=0` alone reproduces master's `style_changes_in_html` byte for byte |
| Gate: Flash-golden LOW set | **0 losses** | Every Flash-golden row that moves goes toward Flash. Every other Flash-golden LOW row I can reach is md5-identical (lists §4) |
| Gate: render canary (195 + 3 `text/` members) | **md5-identical outside the ledger** | 244 identical, 13 DIFFERS + `style_changes_in_html`. All 14 are ledger rows. 0 trace-status and 0 image-status changes |

No row flips status in either axis. The patch is a set of honest moves toward Flash.

## EXPECTED-FLIP LEDGER (for the coordinator's CI grade)

**Trace axis: no moves expected.** Canary: 0 trace-status changes. The edits are render-only, apart from one int field
filled in `action.c`.

**Pixel axis: no status flips expected.** Excess outliers per comparison (graphics, this box = CI on the 6 fidelity
rows):

| row | cmp | golden | master | **patch** | status | change |
|---|---|---|---:|---:|---|---|
| `visual/simple_shapes/text_field_mask` | output | **FP32 LOW (swap)** | 630 vs old golden / **2404** vs FP32 | **1336** | fail → fail | A + swap |
| `from_shumway/gradientTransform` | output | **FP32 LOW (swap)** | 6 vs old / **3** vs FP32 | 3 | fail → fail | swap only |
| `from_gnash/misc-ming.all/place_object_test` | output | FP32 LOW | 5073 | **2604** | fail → fail | A |
| `from_gnash/misc-ming.all/shape_test` | output | FP32 LOW | 10300 | **9715** | fail → fail | A |
| `from_gnash/misc-ming.all/morph_test1` | frame2..5 | FP32 LOW | 1530 ×4 | **1401 ×4** | fail → fail | A |
| `from_gnash/misc-ming.all/morph_test1` | frame6 | FP32 LOW | 727 | **598** | fail → fail | A |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | FP32 LOW | 193 | 193 | fail | — |
| `from_gnash/misc-ming.all/BeginBitmapFill` | output (limit 100) | Flash | 951 | **894** | fail → fail | A |
| `text/style_changes_in_html` | output | Ruffle | 688 | **3278** | fail → fail | A (priced Ruffle loss; vs FP32 LOW 24 332 → 23 938) |
| `from_shumway/acid/acid-shapes` | 6 checks | Flash | 6 checks fail; over t3/16/32/64/128/200 = 22/184/243/21/22/3 | 2 checks fail; over t16/32 = 85/88 | fail → fail | B |
| `avm2/graphics_simple_shapes` | output | FP32 LOW | 124 | **114** | fail → fail | B |
| `avm2/graphics_gradients` | output | Flash | 304 | **293** | fail → fail | B |
| `regression/avm1_drawing_stroke_scale` | output (limit 14000) | FP32 | 11703 | 11736 | pass → pass | B (in band) |
| `avm2/displayobject_getbounds_shape` | output (limit 3800) | Ruffle | 3714 | 3716 | pass → pass | B |
| `avm2/graphics_bitmaps` | 3 checks | Ruffle | t8 938/4000, t16 705/800, t32 504/600 | 959, 711, 526 | pass → pass | B (headroom −22 on t32) |
| `avm2/graphics_direct_commands` | 4 checks | Ruffle | t0 4641, t16 2763, t32 1634, t64 262/300 | 4642, 2762, 1634, 262 | pass → pass | B (±1) |
| `visual/cache_as_bitmap/avm1_color` | output | FP32 | 1200 (max 192) | **230 (max 1)** | fail → fail | C |
| `visual/cache_as_bitmap/scroll_rect_scaled` | 2 checks (limit 900) | Ruffle | 799 | 697 | pass → pass | C |

Everything else is expected md5-identical. A CI pixel move on any row not in this table is unexpected.

## 1. Patch scope (functions touched)

- `SWFModernRuntime/src/libswf/tag.c`
  - **`tf_glyph_quarter_snap`**: new `#elif … MSAA_SAMPLES == 1` arm (prototype A). It applies to embedded,
    non-FlashType (`!csm_advanced`) fields: pen x/y → `rintf(pos / q) * q`, with q = 1 device px in stage twips,
    and the outline left unsnapped. It sits on the identity-matrix arm only, the same call site as the HIGH ¼-px rule.
    The stale "LOW fits no rule" header comment is corrected. Kill switches: `SWF_TF_LOW_PEN_SNAP=0`, or
    `-DTF_GLYPH_NO_LOW_PEN` (the existing `-DTF_GLYPH_NO_QSNAP` also removes it).
  - **`cab_snap_delta`**: at HIGH (`!defined(MSAA_SAMPLES) || MSAA_SAMPLES > 1`; w1's gotcha, because
    `MSAA_SAMPLES` is defaulted later in the file), an unfiltered entry returns 0. Filtered entries and LOW are
    unchanged. Kill switch: `SWF_CAB_HIGH_SNAP=1`.
- `SWFModernRuntime/src/rendering/render_webgpu.c`
  - **`render_webgpu_stroke_snap`** only. The `cdx/cdy` ¼-px grid now runs only when
    `sf & (STROKE_SNAP_VERT|STROKE_SNAP_HORZ)` (prototype B). Kill switch `SWF_STROKE_CENTRE_QSNAP_ALL=1` is read
    lazily in the same function, so `hairline_init` is untouched (sibling w1-lowq-next owns the LOW rules there).
- `SWFModernRuntime/src/actionmodern/action.c`: new `static tf_glyph_csm_advanced`. It is set in
  `actionIterateTextFieldGlyphs` (next to `bounds_ymin_twips = 0`) and in `otf_emit_textfield` (next to
  `word_wrap`).
- `SWFModernRuntime/include/actionmodern/action.h`: `TextFieldGlyphInfo` gains the trailing field `int csm_advanced`.
  The `tag.c` `tf_layout_info` copy is a struct copy, so the field survives.

Sibling overlap: w2-text-coverage-land edits `textfield_glyph_render_cb` (the matrix arm) and `tf_border_skewed_line_rect`.
I touch neither, only the helper `tf_glyph_quarter_snap` that the identity arm calls. w1-lowq-next / n-seam-caps:
no shared function.

**Mode parity:** none of the edits is in `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS` arm. A no-graphics build of
`place_object_test` compiles, links and passes its trace.

## 2. Headline before/after (clean `origin/master` vs patch, same box, graphics)

| test | before | after |
|---|---|---|
| `visual/simple_shapes/text_field_mask` | 630 vs Ruffle golden; **2404 vs FP32** | 1738 vs Ruffle; **1336 vs FP32** (graded by CI against FP32 after the swap) |
| `from_gnash/…/place_object_test` | 5073 | 2604 |
| `from_gnash/…/shape_test` | 10300 | 9715 |
| `from_gnash/…/morph_test1` f1/f2–5/f6 | 193 / 1530 / 727 | 193 / 1401 / 598 |
| `from_gnash/…/BeginBitmapFill` | 951 (limit 100) | 894 |
| `from_shumway/acid/acid-shapes` | t3 113022/113000, t16 61484/61300, t32 25843/25600, t64 5621/5600, t128 202/180, t200 3/0 | t3 112728 ✓, t16 61385 ✗, t32 25688 ✗, t64 5575 ✓, t128 175 ✓, t200 0 ✓ |
| `avm2/graphics_simple_shapes` | 124 | 114 |
| `avm2/graphics_gradients` | 304 | 293 |
| `regression/avm1_drawing_stroke_scale` | 11703 / 14000 pass | 11736 pass |
| `visual/cache_as_bitmap/avm1_color` | 1200 (max 192) | 230 (max 1) |
| `visual/cache_as_bitmap/scroll_rect_scaled` | 799 / 900 pass | 697 pass |
| `from_shumway/gradientTransform` | 6 vs HIGH golden; 3 vs FP32 LOW | 3 vs FP32 LOW (render md5-identical) |
| `from_shumway/acid/acid-shapes-testing` | 10317 | 10317 (md5 =) |
| `regression/avm1_drawapi_stroke_snap` | 2436 / 2800 | 2436 (md5 =) |
| `regression/avm2_drawapi_stroke_snap` | 2550 / 2950 | 2550 (md5 =) |
| `visual/drawing_api/cursor` | 400 | 400 (md5 =) |
| `visual/drawing_api/fills_and_lines` | 38429 | 38429 (md5 =) |

The n-drawapi-stroke-snap ledger rows (`acid-shapes-testing`, both drawapi fixtures, `cursor`, `fills_and_lines`)
are byte-identical, so nothing moves away from Flash (item 3).

## 3. The two swaps (item 2 + 4)

Both captures are platform-stable: WIN == LNX byte for byte, as re-checked here. They come from the new stub at the
row's own quality.
- `text_field_mask`: Ruffle golden → FP32 is 2378 ch at tol 0 (1189 px). A moves ours **toward** FP32
  (2404 → 1336), so the gate needed no narrowing. The remaining 1336 ch are glyph-interior LOW raster decisions on
  the big "W" glyphs (w1 lead 3).
- `gradientTransform`: the upstream golden == FP32 HIGH exactly, but the row runs at LOW. Ours vs FP32 LOW is 3 ch
  over tol 3 (max 21), down from 6 over (max 9) vs the HIGH golden. None of A/B/C changes this render (md5 identical).
  The residual is the LOW linear-gradient paint, a w1-lowq-next item. `test.toml` keeps `known_failure = true`, so
  Ruffle's own row stays known-failing. That affects only the `vs_ruffle` side stat.
- Entries: `fixes.json` and the README table, plus one RvF entry "Two image goldens swapped to FP32 LOW" at EOF.
  `apply_flash_fixes.py` result: ALREADY 64, APPLIED 2.

## 4. Gates and regression checks

**Affected-row sets.** I found them by scanning every image row's SWF; each list was run before and after:
- **A (LOW, embedded DefineEditText with UseOutlines, or script `embedFonts`):** 13 tag rows (w1's list) +
  **4 `text/` rows w1 missed** (`style_changes_in_html`, `auto_size/{width,height,return}`) + 9 `embedFonts` rows
  (`edittext_underline{,_scale2}`, `definefont4`, `font_lookup_as3`, `fonts/embed_matching/{fallback_preferences,
  no_font_found,match_style}`, `edittext_always_show_selection`, `away3d_advanced_shallow_water_demo`).
  - Moves: the gnash 4, `text_field_mask` and `style_changes_in_html`.
  - Everything else is md5-identical: all FlashType rows, AVM2 script fields (the `avm2_render_glyphs` path), and
    device-font fields.
- **B (`lineStyle` / `drawPath` / `GraphicsStroke` in the SWF, any quality):** 27 rows + 6 regression stroke fixtures
  + `acid-stroke-0` + `graphics_draw_triangles`.
  - Moves: `acid-shapes`, `graphics_simple_shapes`, `graphics_gradients`, `avm1_drawing_stroke_scale`,
    `displayobject_getbounds_shape`, `graphics_bitmaps`, `graphics_direct_commands`.
  - All the rest are md5-identical, including the Flash-golden LOW rows `acid-shapes-testing`, `acid-stroke-0`,
    `graphics_draw_path`, `drawing_order`, `cursor`, `fills_and_lines`, `cache_as_bitmap/drawing_api`, `definefont4`,
    `movieclip_{begin_gradient_fill,line_gradient_style}`, `graphics_bad_direct_commands`, `bitmapdata_opaque`
    and `stage3d_texture`.
- **C (HIGH cacheAsBitmap):** 26 HIGH rows + every remaining `visual/cache_as_bitmap/*` row (including the LOW
  `scroll_rect`, `drawing_api`, `avm2_button`, `nested_rotation`).
  - Moves: `avm1_color` and `scroll_rect_scaled` only.

**Flash-golden LOW gate (lowq-corner-rule §3/§5 set, `interim6-low`):**
- A is LOW-only and B is quality-blind.
- Every Flash-golden row that moved went toward Flash: `place_object_test`, `shape_test`, `morph_test1`,
  `BeginBitmapFill`, `graphics_simple_shapes`, `graphics_gradients`, `text_field_mask` (now FP32), plus `acid-shapes`
  at HIGH.
- The Flash-golden LOW rows in the §5 improvement list are md5-identical: `graphics_draw_path`, `acid-shapes-testing`,
  `acid-stroke-0`, `sprite_with_frames`, `acid-textfield`.
- **0 losses.** The interim6-low rows (`acid-color-0`, `font_lookup_as3`, `fills_and_lines`, `drawing_order`) are
  md5-identical.

**Render canary.** Command: `render_canary.py capture --label before|after`, 195 members.
- First run: 3 `text/` members were missing (category not yet downloaded); I captured them separately after
  downloading.
- Result: 244 PNGs identical and 13 DIFFERS. The 13 are `displayobject_getbounds_shape`, `graphics_bitmaps`,
  `graphics_direct_commands`, `graphics_gradients`, `graphics_simple_shapes`, `BeginBitmapFill`, `morph_test1`
  f2–f6, `place_object_test` and `text_field_mask`, plus `text/style_changes_in_html` vs `before_text`.
- All 14 are ledger rows. 0 trace-status changes and 0 image-status changes.
- HIGH text (`avm1_edittext_*`, `avm2_*text*`, `edittext_*`) is all identical.
- Appended at EOF: `visual/cache_as_bitmap/avm1_color` and `from_shumway/acid/acid-shapes`. They are needed because
  no standing member saw C.

**Regression suite** (near text, cacheAsBitmap and the drawing API):
- Before == after md5: `avm1_drawapi_stroke_snap`, `avm2_drawapi_stroke_snap`, `avm1_stroke_join_cap_snap`,
  `avm1_stroke_noscale_signed`, `avm1_stroke_pixel_snap{,_matrix}`, `avm2_graphics_runtime`, `group_alpha_cab`,
  `avm2_group_alpha_cab`, `avm2_parent_child_render`, `avm2_timeline_{solid,gradients,stroke_gradient}`,
  `avm1_edittext_wordwrap_render`, `avm1_edittext_scaled_glyphs`, `avm1_edittext_rotated_glyphs`, and the 59
  regression canary members.
- `avm1_drawing_stroke_scale` moves 11703 → 11736 / 14000 and still passes.
- No new fixture: every behaviour has a corpus Flash-golden row (`place_object_test` / `text_field_mask` for A,
  `acid-shapes` / `graphics_simple_shapes` for B, `avm1_color` for C).

## 5. Refutations / attacks on the brief

- **"`text_field_mask` is the only Ruffle-golden loss of A"**: refuted. w1 never downloaded `text/`, and
  `text/style_changes_in_html` (LOW, 3 embedded non-CSM fields) also loses against its Ruffle golden
  (688 → 3278). It is a priced loss: vs the s28 FP32 LOW capture (`lowq-corner-rule/flash_rest/`, wrapper draw())
  it moves toward Flash, 24 332 → 23 938. That capture's absolute distance is large: the Ruffle golden is itself
  24 446 from it. It is still the only Flash witness, and every leg moves in Flash's direction. Under the
  Flash-over-Ruffle ruling this is not a reason to narrow A.
  - `text/auto_size/{width,height,return}` are md5-identical.
- **"`gradientTransform` swap is a grade change only"**: confirmed. The render is unchanged and the excess goes
  6 → 3 by the golden alone.
- **C's reach**: the AVM2 display path never snapped unfiltered caches, so C is AVM1/timeline-only. No `avm1/` corpus
  row sets `cacheAsBitmap` from script.

## 6. Not finished / completion mechanisms

- **Runtime `antiAliasType` is not plumbed** into `csm_advanced`. An AVM1 `tf.antiAliasType = "advanced"` on an
  embedded field at LOW would be pen-snapped although Flash anti-aliases it. No corpus row needs it.
  Completion mechanism: set `csm_advanced` from the AVM1 property in the two producers (w1 lead 2).
- **`style_changes_in_html` FP32 witness** is a draw() wrapper capture. If the coordinator wants a stronger one:
  LOCAL ORACLE REQUEST 1.
- Neither swap flips its row. The residuals are LOW glyph interiors (`text_field_mask`) and LOW linear-gradient paint
  (`gradientTransform`), both w1-lowq-next territory.

## New unclaimed leads

1. `text/style_changes_in_html` is a Ruffle-golden LOW text row. A swap candidate needs a WIN FP32 LOW capture of it
   to check platform stability. If WIN == LNX, swap it via flash_fixes; ours is closer to that capture than the
   golden.
2. The `text/auto_size/*` trio: our renders are closer to the s28 FP32 LOW captures than their Ruffle goldens
   (width 15084 vs 15642, height 7527 vs 7797, return 7788 vs 8043). These are swap candidates under the same
   Windows check.
3. `avm2/graphics_bitmaps` (Ruffle golden) headroom on its t32 check fell from 96 to 74 under B. Watch it if a
   later drawing-API change moves curved strokes.

## LOCAL ORACLE REQUESTS

1. **FLASH: `ruffle-tests/tests/swfs/text/style_changes_in_html` (corpus, AVM1, `quality = "low"`), image, tick 1,
   direct pinned (new stub), LNX and WIN.** Grade ours at the patch, and the Ruffle golden, against it. It confirms
   the A direction on this row (s28's draw() capture says toward Flash), and if WIN == LNX it is a flash_fixes swap.
   Optional, in the same batch: `text/auto_size/{width,height,return}` WIN LOW, for lead 2.
