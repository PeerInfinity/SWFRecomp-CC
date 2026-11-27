# s29 w2-text-coverage-land: Flash HIGH coverage rule for skewed AVM1 text, landed (batched)

**New files**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-text-coverage-land-report.md` (this report)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-text-coverage-land.patch`
  (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  + the two new fixture dirs; `git apply --check -R` verified on the branch)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_rotated_color/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `output.expected.png` = the coordinator's FP32 W1 capture, md5-identical SWF rebuilt from the generator)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_rotated_paragraph/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`; **no golden yet**, image comparison = skip, FLASH request F1 below)

Also edited (not new): `ruffle-tests/render_canary_tests.txt` (2 members appended at EOF),
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (1 entry appended at EOF).

**Box.** Cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Branch `fanout/w2-text-coverage-land` from
`origin/master` `8af03dc3` (code = `bfa47037b`). Corpus: `download_tests.sh visual text from_gnash from_shumway avm1 avm2
fonts`, upstream Ruffle master **`b7ff32d93`**; `apply_flash_fixes` ran. **Fidelity: CI-grade**: my clean-master
`from_shumway/acid/acid-text-4` render is byte-identical to CI's actual PNG on `origin/ruffle-image-results`
(`01b05e1b…`), before and after. Before leg = a clean `origin/master` worktree (not the kill switch).

## Verdicts (lead)

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | **Batched emit** (the w1 blocker) | **DONE.** A field's coverage runs go to the GPU as **one draw** (`render_webgpu_draw_cov_runs`), each run quad carrying its colour slot per vertex, one slot per distinct (colour, n). The prototype's one-draw-and-one-slot-per-run is gone. The new stress fixture `regression/avm1_edittext_rotated_paragraph` (200 glyphs, 10 lines, rot 30°) emits **18 068 runs in one field, 4.4× the old 4 096-draw cap: `runs drawn 18068, fallbacks 0, failed 0`** (`SWF_TF_CPU_COV_STATS=1`). Total ink equals the MSAA render's (9 732 vs 9 697 px-equivalents), so no glyph is missing. When the pools could not hold a batch, the glyph falls back to the MSAA path before it is committed, so nothing drops. Forcing that for every fill gives an image **md5-identical to the kill-switch render** (402 fallbacks). | — |
| 2 | **Colour formula** (W1 FP32) | **FOUND, implemented, exact.** Flash writes **`out = floor((dst·(16−n) + c·n) / 16)`** per channel with the **exact colour byte**. It held on every W1 sample: coloured glyphs over white (all 15 levels), and the black border over white and over 0x808080 (`128 − 8n`). lavapipe's blend quantises source and alpha to 8 bits, so the encoding is integer: α = 16n/255, source byte `round(T·255/16n)`, T = ⌊n(c+1)/16⌋. It is exact over white for every colour (offline: 0 of 3 840 (c, n) pairs off) and exact for black over 0x808080. **On W1, every coloured pixel of the skewed fields whose level matches Flash's level is byte-exact: 12 203 / 12 203.** | new fixture passes |
| 3 | **Gate** | **0 status changes.** Canary 205 members (standing set + the 22-test w1 gate): **282 comparisons md5-IDENTICAL, 4 DIFFERS = exactly the ledger**, trace status changes none, image status changes none. The two FP32-golden rows are md5-identical to the w1 prototype's after PNGs. | 0 |
| 4 | **RvF entry** (Ruffle's `rint(s − 0.35)` size snap on a skewed box) | **Written** (EOF of `RUFFLE_VS_FLASH_DIFFERENCES.md`), with the per-push twip rounding and the Fixed8 colour note. | — |
| 5 | **W2 shapes** (optional, numbers only) | **The same rule fits shape fills and strokes.** Filled triangle: model **170 px > 2** (L1 2 713) vs our MSAA **563** (L1 18 641). 1-px stroke: model **136** (L1 2 271) vs MSAA **343** (17 288). Hairline: model 136 vs MSAA **409** (54 746). Best model per object: ¼-px vertices, sub-scanlines at y + j/4 (phase ½ gives 457 on the triangle, raw vertices 390), strokes as a parallelogram of width 1 + tan/2 along the minor axis. All Flash edge pixels are on the 255 − 16n ladder (0 off). No shape-renderer change (w1-aa-sizing's question). | — |

**Expected CI movement: trace 0, image status 0** (the new `rotated_color` row passes; `rotated_paragraph` is skip).

## EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

| row / comparison | golden | trace | pixel status | md5 | vs golden, before → after (px > 2 / L1 RGB / ch > tol) |
|---|---|---|---|---|---|
| `regression/avm1_edittext_rotated_glyphs` | FP32 | pass → pass | pass → pass | moves | 1034 / 120 660 / 12 → **198 / 11 001 / 0** (tol 128) |
| `regression/avm1_edittext_rotated_borders` | FP32 | pass → pass | pass → pass | moves | 1829 / 207 927 / 12 → **522 / 26 691 / 0** (tol 128) |
| `visual/edittext/edittext_border_transform` .04 | Ruffle | pass → pass | pass → pass | moves | 181 / 6 532 → 86 / 2 660 (toward the golden) |
| `visual/edittext/edittext_border_transform` .06 | Ruffle | pass → pass | pass → pass | moves | 213 / 8 065 → 140 / 4 743 (toward the golden) |
| `regression/avm1_edittext_rotated_color` (**new**) | FP32 | — → pass | — → **pass** (72 / 144 @ tol 16) | new | master would **fail**: 1034 / 101 103 / **1589** → 293 / 12 949 / **72** |
| `regression/avm1_edittext_rotated_paragraph` (**new**) | none | — → pass | — → **skip** | new | — (FLASH request F1) |

Everything else is unchanged: 0 trace, 0 image-status moves, and md5 identity on all 282 other canary comparisons.
`edittext_border_transform` .01/.02/.03/.05, the 90° / scaled / placed / device-font rotation rows and the
axis-aligned text rows are md5-identical.

## 1. Patch scope (functions touched)

**`SWFModernRuntime/src/rendering/render_webgpu.c`** (sibling-owned file; **two NEW functions only, no existing function
edited**, inserted before the "Clip-mask stencil state helpers" block):
- **new** `render_webgpu_draw_cov_runs(ctx, xywh, pal_idx, n_runs, pal_rgba, n_pal, transform_id, cxform_id)`. It
  stages `n_pal` dynamic colour slots and `6·n_runs` dynamic vertices (style_x 0 = solid, style_y = slot per vertex),
  then makes ONE `render_webgpu_draw_shape`. All-or-nothing: it returns 0 and draws nothing when `MAX_DYNAMIC_VERTICES`
  / `MAX_DYNAMIC_RECTS` cannot hold the batch. It uses the existing render pipeline, so MSAA_SAMPLES is untouched and
  there is no new pipeline.
- **new** `render_webgpu_dyn_room(ctx, &verts_left, &colors_left)`: what is left in the dynamic pools.
- Header `render_webgpu.h`: the 2 prototypes. `renderer.h`: `renderer_draw_cov_runs` / `renderer_dyn_room` in both
  arms (flashbang arm: `(0)` / zeros). `render_stub.c`: stubs (returns 0 = callers fall back).

**`SWFModernRuntime/src/libswf/tag.c`** (all new code is `static`):
- **new** types `TfCovPoly`, `TfCovIv`, `tf_cov_iv_cmp`, `tf_cpu_cov_enabled` (`SWF_TF_CPU_COV=0` = kill switch;
  `SWF_TF_CPU_COV_STATS=1` prints the run/fallback counters at exit via `tf_cov_report_stats`).
- **new** per-field batch `g_tfcov_*`, `tf_cov_push_run`, `tf_cov_flush` (one `renderer_draw_cov_runs`),
  `tf_cov_level_rgba` (the colour encoding, §2).
- **new** `tf_cpu_cov_fill(polys, np, dscale, cr, cg, cb)`: the w1 scan converter (4 sub-scanlines at y + j/4, exact x,
  n = round(16·cov)), now **appending** runs. It returns 0 with the batch unchanged (the caller falls back to MSAA) when
  the bbox is over 4 096 px wide, or when the whole pending batch would leave less than 65 536 vertices / 512 colour
  slots for the rest of the frame (`TF_COV_RESERVE_*`).
- `tf_border_skewed_line_rect`: the w1 arm (unsnapped corners → ¼ device px, 4 border parallelograms). It now passes
  colour bytes and flushes right after (1 draw for the 4 edges, which used to be 4 draws).
- `textfield_glyph_render_cb`: the w1 matrix-arm (`tf_mm`) skewed-glyph branch (unrounded composition, ¼-px vertices),
  now passing the **exact colour byte** (`cur_color`; 255 for selected glyphs) instead of the Fixed8 float. Plus 3
  flushes that keep draw order: before the MSAA `renderer_draw_tris` (a no-op unless runs are pending), before the
  selection-box `renderer_draw_rect`, and after the glyph loop (before the caret / `renderer_end_clip`).
- Untouched: `tf_border_line_segment`, `tf_glyph_quarter_snap`, the identity arm, `avm2_display.c`, DefineText, LOW
  (`MSAA_SAMPLES == 1` compiles the call sites out: the LOW canary members are md5-identical).

**Fixtures / lists:** `regression/avm1_edittext_rotated_color` (W1 + its FP32 golden, tol 16 / 144: 2× the measured 72;
master scores 1589), `regression/avm1_edittext_rotated_paragraph` (stress, skip until F1), and both appended to
`render_canary_tests.txt` (tier 1). The standing set had no coloured or multi-line skewed field.

**Mode parity:** renderer-only and graphics-only. A no-graphics build of the new fixture compiles and passes trace
(`renderer.h` flashbang arm), so no no-graphics CI leg is needed.

## 2. Colour formula (W1 fit)

W1 (`w1-local-oracles/w1-text-pixels/W1_color/flash.png`) shares its geometry with `rotated_glyphs`. So the black
capture gives n per pixel, and W1 gives the written colour at that n:

| n | black over white | black over 0x808080 | 0xCC3300 over white |
|---|---|---|---|
| 1 | 239 | 120 | 251,242,239 |
| 8 | 127 | 64 | 229,153,127 |
| 15 | 15 | 8 | 207,63,15 |

All are `floor((dst·(16−n) + c·n)/16)` with c = **204**,51,0. A fully covered glyph pixel is **204,51,0** (2 979 px),
so Flash does **not** use Ruffle's `Fixed8::from_f32(c/255)` multiply (0xCC → 203). The skewed path uses the exact byte.
The non-skewed paths keep `TF_FIXED8_MULT`, and on W1 that leaves the two 90° fields' glyph interiors 1 off (1 050 px,
R −1, under tolerance). That is lead 1 below.

**GPU encoding.** A float model (α = n/16 plus a −15/32 floor bias) was 1 off at n = 10–12 on W1. lavapipe stores the
source colour and alpha as 8-bit before it blends: the measured n = 10 pixel 222 = round(203·160/255) + 95. So
`tf_cov_level_rgba` works in integers. α = 16n/255 makes the destination term `dst·(255−16n)/255`: exactly
`255 − 16n` on white and `128 − 8n` on 0x808080. Source byte s = round(T·255/16n) with T = ⌊n(c+1)/16⌋ makes
round(s·16n/255) = T, which is exactly Flash's floor sum over white for every c. A coloured run over a non-white
destination can be 1 off. n = 16 writes the colour itself. Black-on-white output is unchanged from the prototype
(`rotated_glyphs` md5 `03bc577c…` = the w1 after PNG).

**W1 residual after the patch** (293 px > 2): skewed-field borders over white/grey 203 px, geometry 37 coloured px
(level n differs from Flash's: the same ~1/16 sub-scanline-x residual as w1 §2.1), and the 90° MSAA fields 53 px.

## 3. Headline before/after (clean `origin/master` vs patch, same box, CI-grade)

See the ledger. The new fixtures' before leg was captured on the clean worktree: `rotated_color` **fails** on master
(1 589 outliers > 144), and `rotated_paragraph` renders at master md5 `3f41f196…` (= the kill-switch render).
Kill-switch check: `SWF_TF_CPU_COV=0` on the patched build reproduces master's `rotated_color` statistics exactly
(6 178 diff channels, 1 589 outliers).

**Regression suite near the change:** all 59 `regression/` canary members (every `avm1_edittext_*` row, the stroke /
cxform / bitmap rows) are md5-identical except the two ledger rows. Trace status pass → pass on all.

## 4. Not done / caveats (each with its completion mechanism)

1. **Paragraph golden**: FLASH request F1 below. Until then the row is skip and a canary md5 member, and the stats
   counter is the drop proof.
2. **Browser camera/scroll offset** (w1 §2.4 (2)): the runs are placed in device px through slot 0 (stage twips,
   `20/stage_scale`). This is the same assumption the landed s28 `tf_border_line_segment` pen already makes. It needs
   one browser probe of a rotated field under a non-zero stage offset (local browser ladder).
3. **AVM2 twin** (`avm2_render_glyphs`, `avm2_draw_border_line`): not ported (w1 lead 2; s28 F1/F2 AVM2 fixtures wait
   for capture).
4. **Field background of a skewed box** still draws through MSAA. The border covers its edge on every graded row, so
   there is nothing to measure yet.
5. **Coloured coverage over a non-white destination** is within 1 (an 8-bit blend cannot floor exactly). Exactness
   would need a shader-side blend or a CPU composite.

## 5. Refutations / premise checks

- **"Landing needs a coverage texture or a vertex batch"**: a vertex batch alone was enough, because the existing vertex
  format already carries a colour slot **per vertex** (`style_y`, used by `render_webgpu_draw_morph`). No new pipeline,
  texture or shader.
- **"alpha 16n/255 reproduces Flash for black on white"** (w1 §2.4 (3)): true. For a colour it is up to 2 off (a float
  model gives 433 283 of 983 040 (c, dst, n) cases off), and a float-exact bias is still 1 off on lavapipe (8-bit
  blend). The integer encoding above is exact on white.
- The brief's `edittext_border_transform` "toward goldens" holds (.04 181 → 86, .06 213 → 140 px > 2). Both stay pass
  with 2 channels > tol 20 each (limit 20).

## 6. New unclaimed leads

1. **Fixed8 colour multiply is not Flash** (W1: FP32 draws 0xCC as 204, Ruffle/ours 203). `TF_FIXED8_MULT` in
   `textfield_glyph_render_cb` (s24 w2-text-pitch, a Ruffle match) moves every coloured embedded-text row by 1 per
   channel. Price it with `scripts/image_status_diff.py` over coloured-text rows. Ruffle-golden rows would move away by
   1 (under most tolerances). RvF note written; no flash_fixes candidate yet.
2. **The coverage rule for shapes** (task 5 numbers): fills 563 → 170 px > 2 and 1-px strokes 343/409 → 136 on W2.
   For CPU-known geometry (Drawing-API hairlines, axis-free strokes) the same batched run emit is now reusable
   (`render_webgpu_draw_cov_runs` is generic). For general shapes it is still NO-GO L (w1 §2.5).
3. **AVM2 twin** (above, caveat 3) with the same tag-side helpers. They would need to move to a shared TU, or be
   duplicated in `avm2_display.c`.
4. **Skewed field background** through `tf_cpu_cov_fill` (caveat 4) once a fixture shows its edge (a borderless
   rotated field with a background colour over a contrasting stage).

## LOCAL ORACLE REQUESTS

- **F1. FLASH, image, 1 frame, direct pinned, HIGH:** `ruffle-tests/tests/swfs/regression/avm1_edittext_rotated_paragraph/test.swf`
  (built by its `create_test_swf.py`; 240×240, one 200-glyph square-glyph field rotated 30°). It is the golden for the
  stress row: archive it as `output.expected.png`, and set the toml budget from the measured residual (expect ~1 px >
  2 per glyph edge, cf. `rotated_glyphs` 198 px for 4 glyphs + 3 borders). Check the square-glyph DefineFont2 draws in
  Flash (the s27 trap): it is the same font as the W1 / `rotated_glyphs` fixtures, which Flash drew.
