# w1-filter-label: filter label residuals (pixels), session 23 wave 1

**New files:** this report, and `w1-filter-label-prototype.patch`. The patch is `git diff origin/master -- SWFRecomp/src SWFModernRuntime/src`
against `ad99dc15`. It applies cleanly with `git apply --check`. The source files are reverted on the branch.

**Setup.** `SETUP_STATUS` was all OK (apt, Pillow, Dawn). The renderer is lavapipe. Upstream corpus: `download_tests.sh` at
Ruffle `0ddd12b6a`, categories `visual avm1 avm2 text fonts from_gnash from_shumway timeline swf mixed_avm
import_assets audio stage3d` (no `from_avmplus`: it is pure ABC with no DefineFont). Ruffle source is cloned at `0ddd12b6a`.
lyon is cloned for `lyon_tessellation 1.0.15` / `lyon_geom 1.0.6` (the versions in Ruffle's `Cargo.lock`).

## Verdicts (lead)

**GO: two independent mechanisms, measured. 15 image comparisons flip. 10 tests flip on the pixel axis. 0 pass→fail.
0 trace moves.**

| # | Mechanism | Owner | Flips (graded locally on CI-identical renders) |
|---|---|---|---|
| **B** | **Glyph build for synthesized device fonts.** Glyph curves are flattened with lyon's Levien schedule in Ruffle's coordinate space, and the vertices are kept float instead of being truncated to the 20480-em integer grid. | `SWFRecomp/src/swf.cpp` zero-glyph synth / device-font fallback loop (~2800-2900 on master: the quad branch's fixed 6 equal steps, plus `(Coord)` truncation and `lround` in `tessellateContours`) | **7**: `visual/filters/glow` 3→**0**, `glow_without_composite_source` 3→**0**, `drop_shadow` 3→**0**, `bevel_inner` 42→**18**, `bevel_outer` 42→**18**, `bevel_full` 42→**18**, `glow_with_alpha_strength` 42→**18** (budget 18) |
| **A** | **AVM1 EditText baseline truncated to whole twips.** Ruffle's `FontMetrics::ascent(height)` is `Twips::new((ascent as f32 * scale) as i32)` (`core/src/font.rs:280`). We used the unrounded product. | `SWFModernRuntime/src/libswf/tag.c:6432` `textfield_glyph_render_cb` `y_pos` (graphics-only, `#ifndef NO_GRAPHICS`) | **8 comparisons**: `visual/cache_as_bitmap/edittext_scroll` `.02` 6/5→**0** (test flips), `from_gnash/misc-ming.all/morph_test1` frame2-6 12→**0** ×5 (test still fails on frame1, 217), `from_shumway/acid/acid-text-escape` 110→**0** (test flips), `visual/simple_shapes/text_field_mask` 56→**0** (test flips) |

Pixel-axis test flips: the 7 filters rows, plus `edittext_scroll`, `acid-text-escape` and `text_field_mask` = **10 tests**
(15 comparisons). Neither mechanism moves `morph_test1` frame1 (217) or `Video-EmbedSquareTest` (1794 → 1782,
exactly its 4 xtrace pixels × 3 channels; the rest of that row is the video band). A alone was measured on 8 rows. B alone
(Levien only, and float only) was measured on 6 rows (table §4).

**Zero headroom warning.** `bevel_inner`, `bevel_outer`, `bevel_full` and `glow_with_alpha_strength` land **exactly at budget, 18/18**
(6 pixels × 3 channels). They pass, but any future 1-pixel text move fails them again. The 6 residual pixels are Ruffle-side ties
(§3); I have no cheap fix for them.

**Premise checks.**
- **"7 rows within reach of one depth-0 text glyph fix": CONFIRMED but SPLIT.** All 7 are mechanism B (glyph build).
  - The `glow` trio needs both halves of B: Levien flattening moves the comma pixel, and float vertices fix the K pixel that Levien
    alone breaks.
  - The bevel quartet needs only the Levien half (float alone makes `bevel_inner` 45).
  - They are one fix, not two prices.
- **Board numbers corrected.**
  - `bevel_*` / `glow_with_alpha_strength` are **42/18** outliers. The board's "24" is the excess over budget (`excess_outliers` in
    `image_results_graphics.json`).
  - `bevel` is **750** locally and in the latest `origin/ruffle-test-results` (b3b80ea9). The board says 744, which is what
    mechanism A alone gives.
- **Sibling overlap (say it plainly): `w1-glyph-precision`'s rows are mechanism A, which is mine.** `morph_test1`
  frame2-6, the 4 xtrace pixels in `Video-EmbedSquareTest`, and `edittext_scroll .02` are all fixed by the one-line baseline
  truncation in tag.c.
  - The playbook's "AVM1 embedded-glyph precision" label and its "edittext_scroll .02 needs a port of Ruffle's device glyph build" note
    are both refuted. It is not glyph precision: it is a 0.6-twip baseline offset that lands on pixel centres.
  - **The coordinator should merge the slots.**

## 1. Fidelity (BRIEFS_COMMON "Your box")

Before-renders of **all 7 rows** are **md5-identical** to CI's actual PNGs on `origin/ruffle-image-results`. That branch was force-pushed
2026-10-17 by **run `38995363802`** (s22 final). The fresh run `44922638965` had still not pushed when I last fetched it at the end of
this session.

| row | md5 (CI = local before) |
|---|---|
| glow | 76e8ae21 |
| glow_without_composite_source | 675c06f1 |
| drop_shadow | d7dae990 |
| bevel_inner / bevel_outer / bevel_full | 3bea8ee6 / 3e69a87a / 450c0fc0 |
| glow_with_alpha_strength | da1038fa |

Local grading is CI-grade for these rows. Every number in this report is from `--mode=graphics --recompile` on this box.

## 2. Where the failing pixels are

- **`glow` / `glow_wcs` / `drop_shadow`.** One pixel, (514,248): the tail of the comma in field `K,I`. Ours is black and the golden is
  white.
- **`bevel_*` / `glow_with_alpha_strength`.** 14 pixels, all in the three device-text fields `0.25` / `0.5` / `0.75`
  (x = 2801 / 8221 / 13520 twips, y = 826).
  - Each pixel is a single on/off flip: `quality = "low"`, so there is no AA and the colours are 0 / 199 / 254.
- **All are text-glyph pixels.** They are not filter pixels.
  - The labels are AVM1 `DefineEditText` fields (SWF v15, no ABC) on a **zero-glyph `DefineFont3 "_sans"`**.
  - Ruffle renders that font through `with_default_font` → Noto Sans, `Font::from_font_file`.
  - We render it through the recompiler's zero-glyph synthesis (`swf.cpp`, "Phase A of device-font-rendering-plan"), which tessellates
    `SWFRecomp/assets/NotoSans.ttf`.

### Exact-geometry model

The model lives in the scratchpad (`tools/tie.py`). It uses fontTools outlines and Ruffle's layout:
- the field origin is `PlaceObject tx + bounds.x_min + 40 gutter`;
- the baseline is `ty + trunc(1069·h/1000)` twips;
- each advance is `round_to_pixel(trunc(adv·h/1000))` (`font_like.rs:125`);
- flattening is lyon's Levien at tolerance 0.1 in `font_units/20`.

For `K,I` this reproduces the fitted origin (493.0, 245.75) px. Margins of each failing pixel centre from the outline:

| pixel | glyph | exact-curve margin | Levien 0.1 margin | golden |
|---|---|---|---|---|
| (514,248) | `,` | inside, 0.004 px | **outside**, 0.016 px | white |
| (504,228) | `K` arm (straight edge) | inside, **0.0007 px** | same | black |

- The comma pixel is decided by **flattening**. Ruffle's chord at tolerance 0.1 (≈0.058 px at 29 px text) cuts it off; our
  6-step chord does not. Finer flattening (48 steps, measured) does not help either: glow stays at 3 and `bevel_inner` goes 42→45.
- The K pixel is a 0.0007 px tie, far below lavapipe's 1/256-px vertex snap. It flips on **vertex quantization**: `(Coord)` truncation
  versus `lround` of one endpoint, 1 unit at 20480 em, about 0.0014 px. Only unquantized vertices reproduce Ruffle's f32 path there.

## 3. The 6 residual bevel pixels (why 18/18, not 0)

After the prototype, **our render agrees with the exact Levien model at all 6 residual pixels**. The golden is on the other side:

| pixel | glyph | model / ours | golden | margin |
|---|---|---|---|---|
| (147,72), (418,72) | `0` bottom | out | in | 0.0008 px |
| (677,63), (690,67) | `0` sides | in | out | 0.003 / 0.0004 px |
| (726,72) | `5` | out | in | 0.003 px |
| (168,52) | `2` | out | in | **0.026 px** |

- Five of the six are sub-snap ties: Ruffle's f32 pipeline order lands them on the other side.
- The `2` pixel is not a tie. Ruffle's `2` differs from the Levien model by about 0.03 px there.
  - Untested candidates: lyon's event queue flattens each quad **swapped so it runs downward** (`event_queue.rs`
    `quadratic_bezier_segment`), and lyon_tessellation's own vertex handling.
- **HOLD**: completion needs a bit-exact replica of lyon's flattening order, and a check of whether f32 path construction (`Twips::to_pixels`
  → f32, then the `a = 0.58` matrix in the vertex shader) is enough to resolve the ties. Price: 0 flips (the rows already pass); only
  headroom is at stake.

## 4. Measurements (local lavapipe, graphics, `--recompile`)

`before` = origin/master recompiler and runtime. `L` = Levien only. `F` = float only. `B` = L+F. `A` = baseline truncation only (master
recompiler). `A+B` = the full prototype. Values are outliers; the budget is in brackets.

| comparison | before | L | F | B (L+F) | A | **A+B** |
|---|---:|---:|---:|---:|---:|---:|
| filters/glow [0] | 3 | 3 | 3 | **0** | 3 | **0** |
| filters/glow_without_composite_source [0] | 3 | | | **0** | | **0** |
| filters/drop_shadow [0] | 3 | | | **0** | | **0** |
| filters/bevel_inner [18] | 42 | **18** | 45 | **18** | 42 | **18** |
| filters/bevel_outer, bevel_full, glow_with_alpha_strength [18] | 42 | | | **18** | | **18** |
| filters/bevel [6] | 750 | 759 | 750 | 759 | 744 | 738 |
| cache_as_bitmap/edittext_scroll .02 [5] | 6 | 12 | 6 | 12 | **0** | **0** |
| cache_as_bitmap/edittext_scroll .01 [5] | 0 | 0 | 0 | 0 | 2 | 0 |
| morph_test1 frame2..6 [0] | 12 each | | | | **0** | **0** |
| acid-text-escape [0] | 110 | | | | **0** | **0** |
| simple_shapes/text_field_mask [0] | 56 | | | | **0** | **0** |
| cache_as_bitmap/text [1500] (pass) | 1200 | 1251 | 1200 | 1254 | | 1257 |
| avm1/text-bind [600] (pass) | 583 | 581 | 583 | 581 | | 587 |
| Video-EmbedSquareTest [0] | 1794 | | | | 1782 | 1782 |

- **The Levien half also has costs.**
  - It worsens `bevel`'s 20-px "Knockout" label by 9 (the 'o' tops at y=17 lose pixels): with Levien our glyph sits 0.03 px low because
    of the untruncated baseline.
  - It worsens `edittext_scroll .02` by 6.
  - **Mechanism A cancels both** (`bevel` 738 < 750; `.02` → 0). **Land A with B, or A first.** B without A regresses
    `edittext_scroll` (still failing, 6→12) and `bevel`.

## 5. What else moves (A/B, the full prototype versus master)

### Scope argument (why this list is complete)

- **Recompiler half (B).** It touches only the zero-glyph-synth and env-gated device-font-fallback glyph loop. Moving the Levien block
  up the file is pure code motion.
  - I scanned **every `.swf` in all downloaded suites** for a named DefineFont2/3 with 0 glyphs: **51 SWFs** (avm1 16, avm2 14,
    gnash 1, shumway 9, visual 11).
  - Generated C changes for all 51. Generated C is byte-identical on 5 control SWFs outside the set (`edittext_tag_indent`,
    `fonts/device-font`, `avm2/edittext_scrollh`, `edittext_border_transform`, `text/auto_size/width`).
- **Runtime half (A).** It is AVM1 `DefineEditText` glyph rendering, graphics-only. I scanned every image-graded test for
  `DefineEditText`: **51 tests** (35 AVM1, 16 AVM2).

### What was rendered

The union is 51 image-graded tests (the 14 zero-glyph image tests plus 37 more). Each was rendered before and after (md5). Every
standing-canary member that contains EditText is in this set; no other canary member can reach either changed path, so I did not run
the full canary (it would cost an hour or more per leg).

### Results

- **Moved, and the verdict changed:** the 10 flips above (15 comparisons). There is **no pass→fail**.
- **Moved, still failing** (the counts are the full prototype):
  - `bevel` 750→738
  - `Video-EmbedSquareTest` 1794→1782
  - `acid-text` 5019→**5040**
  - `acid-color-0` 17376→17326
  - `place_object_test` 41874→**41937**
  - `shape_test` 17911→**17953**
  - `br_at_start` 3681→**3684**
  - `style_changes_in_html` 25024→24998
  - `String_path_variable_button` 999→999 (pixels moved)
  - `BeginBitmapFill` (pixels moved, same count)
  - `morph_test1` frame1 217 (md5 moved, count same)
- **Moved, still passing:** `cache_as_bitmap/text` 1200→1257 (budget 1500) and `text-bind` 583→**587 (budget 600, headroom 13)**.
- **md5-identical:** the other 27 tests (`MaskTest-2`, `hardwrap`, …), including all 16 AVM2 EditText rows, `edittext_hscroll`, `edittext_selection`,
  `edittext_border_filters` (a zero-headroom watch row), `edittext_tag_indent`, the `edittext_*` background/border/caret/bounds rows and
  `focus_highlight_render`.
- **Trace axis.** All 34 trace-only zero-glyph tests keep their CI status in graphics mode: 30 pass, `bounds_mode` and
  `getobjectsunderpoint` ruffle_matched, and the two mixed-AVM `output_mismatch` rows unchanged. Trace status is identical
  before and after on the 37 sweep tests, and all 14 zero-glyph image tests are trace-pass after.
- **Regression suite.** `regression/avm1_parent_child_text` passes after the change (0 outliers).
- **No-graphics.** The tag.c site is `#ifndef NO_GRAPHICS`. The recompiler change only alters glyph triangle data, and the path data
  stays byte-identical. I did not run no-graphics.

## 6. Prototype (`w1-filter-label-prototype.patch`)

**`swf.cpp`:**
- Moves the Levien block (`LEVIEN_TOL_TWIPS` … `levienT`) to the top of `namespace SWFRecomp`; it is pure code motion, so the glyph
  loop can use it.
- In the glyph loop:
  - contour points become `double`;
  - quads are flattened with `levienInit(…, 0.1f)` over `font_units/20` (via `(double)u/20`, as `Twips::to_pixels`), then scaled by
    `20·ttf_scale`;
  - contours go through `tessellateContours(…, keep_float=true)`;
  - the triangles are emitted with `x + fx_frac/16384`.
- It has two **measurement toggles**, both defaulting on, which wave 2 should delete: `SWFRECOMP_GLYPH_FLOAT=0` and
  `SWFRECOMP_GLYPH_LEVIEN=0`.
- The cubic branch (never hit by TrueType Noto; possible for CFF `[fonts.*]` faces) still uses 8 equal steps, now unquantized.

**`tag.c:6432`:** `baseline_twips = (float)(s32)(ascent * baseline_scale)`. Toggle `SWF_TF_BASELINE_TRUNC=0` (delete it in wave 2).

**Wave-2 notes:**
1. The selection box (`tag.c:6728`) and the caret (`:6914`) still subtract the untruncated ascent from `y_pos`.
   - Ruffle derives both from the same truncated metrics, so check `edittext_selection` / `edittext_caret_*` when porting.
   - Their md5s did not move here.
2. `text-bind` has 13 channels of headroom left after the change; watch it.
3. Add `visual/filters/bevel_inner` (B), `visual/simple_shapes/text_field_mask` (A) and `from_shumway/acid/acid-text-escape` (A) to the
   canary. The current members did not cover the zero-glyph glyph build except through `glow`, `drop_shadow`, `edittext_scroll` and
   `text`.

## 7. Refutations of record

- **"Integer-twip / font-unit `lround` quantization" (the s22 lead) as the sole mechanism: PARTIAL.**
  - At 20480 em, quantization is about 0.0014 px. It decides only the true ties (the K pixel).
  - The main glyph term is the **flattening schedule**: fixed 6 equal steps versus lyon's Levien at tolerance 0.1.
  - The main layout term is the **baseline truncation**, not glyph precision.
- **Finer flattening (48 steps): NO-GO.** It moves away from Ruffle (`bevel_inner` 42→45). Ruffle's chords are coarse, and we must match
  them, not the true curve.
- **Playbook §21 "AVM1 embedded-glyph precision … morph_test1 / Video-EmbedSquareTest" and "`edittext_scroll .02` needs a port of
  Ruffle's device glyph build": REFUTED.** Both are fixed by mechanism A, a one-line baseline truncation.
- **EditText layout pen positions: verified correct.** Device advances are `round_to_pixel` in both Ruffle and us (`tf_glyph_advance_twips`).

## New unclaimed leads

1. **Bit-exact lyon fill flattening** (the downward swap in the event queue, plus f32 path construction) for the 6 residual bevel pixels.
   It buys headroom only.
2. **Extend B to embedded DefineFont glyphs and the AVM2 device-font emitter (`abc_devicefont.cpp`).** They use the same historical
   integer round trip ("glyph outlines keep the historical integer round trip", `swf.cpp` `keep_float` comment).
   - They are unmeasured here. The A1 emitter already uses Levien 2.0 per w2-noto-d1, so check its tolerance and space against §2.
   - `acid-text` (+21) and `place_object_test` (+63) moved the wrong way under A+B. Attribute those before wave 2.
3. **Selection and caret metrics after A** (§6 note 1).

## LOCAL ORACLE REQUESTS

None. Every verdict was graded on renders that are md5-identical to CI.
