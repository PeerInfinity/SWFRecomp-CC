# s28 snap-pixel-audit: interim #2's 51 pixel pass → fail moves, attributed and graded against Flash 32

One-task LOCAL session, 2026-11-25 (launched by `s28-coordinator`). Brief: interim #2 (graphics images run
`45694673542`, results `947443a23`, built at `10a5b515a`) vs interim #1 (`7e8aa52af`, built at `13b40eabb`). The list
is in `interim2-pixel-diff.txt`. Captures, grading scripts and raw data are in `snap-pixel-audit/`.

## Verdict

- **Owner: the n-stroke-snap pass `09b2c9130` owns all 51.**
  - With `SWF_STROKE_SNAP=0`, our render equals the golden on 50 of 51 rows. The exception is `filters/drop_shadow`,
    whose default-font text differs by host: 32818 channels locally vs CI's 8052.
  - w2-glyph-quarter-snap `-DTF_GLYPH_NO_QSNAP` changes **0** rows. Its qsnap is compiled only under `MSAA_SAMPLES > 1`
    (`tag.c` ~8408), i.e. HIGH quality, and these rows are quality LOW or have no embedded text.
  - AVM2 culling `958313b73` owns nothing here.
- **No golden is Flash.** Every row is "not Flash" or "untestable" in the s27 golden-provenance sweep, or is one of our
  own fixtures with a Ruffle golden (§Regression fixtures). Class (a), "golden == Flash and we moved away", has
  **0 rows**.
- **Direction vs Flash** (Flash 32 re-captured at each test's quality):
  - **34 rows move Flash-ward**: simple_loop ×6, the 4 fixtures, 14 blend_modes, acid-chars/-scale/-text,
    symbol_class_conflict, opaque_background, focal_radial, gradients, color_matrix, blur_size_grows and
    drop_shadow_angles. On the pixels the snap changed, more land within 2 of Flash than before, on every one of them.
  - 5 rows are neutral (`drawing_order`, `masks` ×2, `displacement_map`, `layers`).
  - **2 rows move away**: `doubleAndRegister` and `acid-gradient-2` (defect D1, below).
  - 10 rows are ungradable: host fonts ×8, input.json ×1, stage size ×1.
  - 34 + 5 + 2 + 10 = 51.
- **Current master:** `4b5dca5c2` (with w2b-stroke-width-merge `a7c72d830` and drawing-API snap `e81d27317`) grades
  identically to `00b35fa5e` on all 51 rows. It differs from the interim-#2 code only on `acid-scale`, where the
  width merge cut ours vs Flash from 11194 to 4350.

## Actions taken

| what | rows | expected CI move |
|---|---|---|
| `flash_fixes` swap to the Flash 32 capture (draw, quality low, LNX == WIN at 0 px; ours == Flash at 0 channels) | `from_gnash/misc-ming.all/loop/simple_loop_test` frame1, 2, 3, 5, 6, 7 | **6 × fail → pass** |
| regression goldens → Flash 32 capture (LNX == WIN), `max_outliers` = measured ours vs Flash | `regression/avm1_hairline_scaled_instances` (366), `regression/avm1_stroke_style_id_order` (56) | **2 × fail → pass** |
| RvF priced-loss entry + image-axis marker ("s28 stroke snap at quality LOW", 31 rows); simple_loop entry updated | the 31 class-b rows | stay fail (priced) |
| `regression/README.md`: layer_group twins' golden is Ruffle's, not Flash's | `avm2_layer_group_alpha` / `_erase` | stay fail (priced) |
| D1 sent to the stroke owner; its slice had closed, so D1 is the next slice's line | `doubleAndRegister`, `acid-gradient-2` | — |

No runtime code changed. Net expected interim move: **+8 pass**, with the other 43 still failing, as priced, ungradable
or D1.

## Regression fixtures (brief §4)

| fixture | golden provenance | golden vs Flash | ours (master) vs Flash | snap off vs Flash | outcome |
|---|---|---:|---:|---:|---|
| `avm1_hairline_scaled_instances` | Ruffle exporter (`d70f2c0aa`), HIGH | 1551 | 366 | 1551 | swapped to Flash, max_outliers 366 → passes |
| `avm1_stroke_style_id_order` | Ruffle exporter (`d70f2c0aa`), HIGH | 2004 | 56 | 2004 | swapped to Flash, max_outliers 56 → passes |
| `avm2_layer_group_alpha` | upstream Ruffle `layer_alpha` golden (`a281b60d4`), LOW | 13763 (screen) | 12322 | 14103 | priced loss; not swapped |
| `avm2_layer_group_erase` | upstream Ruffle `layer_erase` golden (`a281b60d4`), LOW | 11579 (screen) | 9786 | 11538 | priced loss; not swapped |

None is Flash-made, so the brief's "if Flash, they must pass again" does not apply.
- **The two AVM1 fixtures** are swapped anyway: they are ours, the Flash capture is host-independent, and the measured
  max_outliers still catches the regression they exist for (snap off = 1551 / 2004 channels).
- **The layer_group pair** needs `--screen`, because draw() is ~89k off. Screen capture is Linux-only: the Windows
  harness has no screen mode. So the pair stays on the Ruffle golden; swap it once a Windows screen capture exists.

## D1: the LOW AA-centre ¼-px quantisation moves two rows away from Flash

`hairline_restage` quantises every stroke's device centre to the ¼-px grid, then snaps the axis-aligned 1/2/3-px
segments. At quality LOW (MSAA 1, pixel-centre sampling) this moves two non-snapped strokes away from Flash:

| row | changed px | within 2 of Flash: snap on / off | what |
|---|---:|---:|---|
| `from_shumway/doubleAndRegister` | 28 | 6 / 22 | a diagonal stroke edge shifted 1 px |
| `from_shumway/acid/acid-gradient-2` | 24 | 5 / 14 | one 20-px-wide (LineStyle 400) curve |

**Experiment** (worktree only): skip the quantisation when `MSAA_SAMPLES == 1` and the segment is not snapped
(`SWF_EXP_QLOW`).
- It **fixes both** rows: they return to the snap-off pixels.
- It **loses** on `acid-scale` (85 → 48 changed px within 2) and on every `filters` row (e.g. `drop_shadow_angles`
  1231 → 885, `blur_size_grows` 664 → 573, `bevel_outer` 39317 → 37797), plus `color_matrix` and `layers`.

So "no centre quantisation at LOW" is **not** Flash's rule. The separating property is still open: diagonal/curve
segments vs axis-aligned ones, or wide strokes. Since `e81d27317` the drawing-API pass (`render_webgpu_stroke_snap`)
uses the same quantisation, so a rule change belongs in both functions. `SWF_STROKE_SNAP_DRAWAPI=0` separates them.
Data: `snap-pixel-audit/changed_cur_exp.json`.

**Side gap (not snap-owned): `visual/drawing_api/drawing_order`.** Its 3-px (u = 12) rectangle comes out 2 px smaller
per axis in Flash. The stroke-centre spans are 415×339 in Flash vs 417×341 for us. Flash's bands: left 45-47, right
460-462, top 75-77, bottom 414-416. Ours: 44-46, 461-463, 75-77, 416-418. The snap does not change this row
(1492 vs 1501 changed px within 2). It is a separate geometry gap.

## Ungradable rows (class c)

- **Default-font `visual/filters/*`** (`bevel` ×4, `drop_shadow`, `glow` ×3): host fonts, so no flash_fixes swap and no
  absolute grade. On the pixels the snap changed, 7 of the 8 move Flash-ward. `bevel_inner` is level (3393 vs 3554
  within 2). These rows are not in the RvF entry.
- **`avm1/mouse_events_visible_enabled`**: needs input.json, and a Flash capture without input is invalid (598k off).
- **`visual/filters/blur_scales_with_screen`**: stage size (viewport scaling); no comparable capture.

## Method

- **A/B renders:** scratch worktree, graphics mode, one verify per suite under `flock /tmp/swfrecomp-cpu.lock`
  (`snap-pixel-audit/abatch.sh`). Variants:
  - `on` = `aa595bbc6` (≈ interim-#2 code);
  - `snapoff` = `SWF_STROKE_SNAP=0`;
  - `cur` = `00b35fa5e`;
  - `glyphoff` = `SWFRECOMP_EXTRA_DEFINES=-DTF_GLYPH_NO_QSNAP`;
  - `exp` = D1 experiment;
  - `master` = `4b5dca5c2`.
  The local `on` grades reproduce CI's interim-#2 excess exactly on every row except `drop_shadow` (host fonts).
- **Flash:** `tools/flash-oracle/sweep_goldens.py` at each test.toml quality.
  - draw() wrapper for every row; `--screen` for the 14 `blend_modes` and the 2 layer_group twins (non-LAYER blends).
  - `--windows` draw for simple_loop_test (7 frames) and the two AVM1 fixtures: Linux == Windows at 0 px.
  - A second Linux screen capture of the layer_group twins was identical.
  - PNGs: `snap-pixel-audit/flash/png/`. No archived capture was reused.
- **Grading:** `grade.py` counts outlier channels over the test's tolerance (and px with any channel > 2) for golden vs
  Flash and for each variant vs golden / Flash (`grade.json`). `changed.py A B` looks only at the pixels where A and
  B differ: how many land within 2 of Flash, how many are closer, and L1 (`changed_*.json`).

## The 51 rows

Numbers are outlier channels over the test's tolerance. "after" is master `4b5dca5c2`. "before" is the snap-off render,
which equals the golden. The Flash mode is the one used in the columns. The last numeric column counts changed pixels
within 2 of Flash, after/before.

| test | cmp | tol | owner | golden provenance | ours vs golden | golden vs Flash | before (snap off) vs Flash | after vs Flash | changed px within 2 of Flash: after/before | Flash mode | class | action |
|---|---|---:|---|---|---:|---:|---:|---:|---|---|---|---|
| `avm1/mouse_events_visible_enabled` | output | 0 | stroke snap 09b2c9130 | untestable (s27) | 3610 | 598288 | 598288 | 596484 | – | draw | c (input.json) | none |
| `avm2/symbol_class_conflict` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 5022 | 5293 | 5293 | 449 | – | draw | b | RvF |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame1 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 242 | 242 | 242 | 0 | 121/0 of 121 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame2 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 482 | 482 | 482 | 0 | 241/0 of 241 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame3 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 722 | 722 | 722 | 0 | 361/0 of 361 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame5 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 242 | 242 | 242 | 0 | 121/0 of 121 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame6 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 482 | 482 | 482 | 0 | 241/0 of 241 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame7 | 1 | stroke snap 09b2c9130 | not Flash (s27) | 722 | 722 | 722 | 0 | 361/0 of 361 | draw | b → flash_fixes | swap (6 × fail→pass) |
| `from_shumway/acid/acid-chars` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 1272 | 3024 | 3024 | 1752 | 424/0 of 424 | draw | b | RvF |
| `from_shumway/acid/acid-gradient-2` | output | 1 | stroke snap 09b2c9130 | not Flash (s27) | 61 | 3002 | 3002 | 3030 | 5/14 of 24 | draw | **away (D1)** | handed to stroke owner |
| `from_shumway/acid/acid-scale` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 8942 | 11240 | 11240 | 4350 | 80/57 of 137 | draw | b | RvF |
| `from_shumway/acid/acid-text` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 2598 | 18522 | 18522 | 16044 | 833/6 of 866 | draw | b | RvF |
| `from_shumway/doubleAndRegister` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 56 | 772 | 772 | 804 | 6/22 of 28 | draw | **away (D1)** | handed to stroke owner |
| `regression/avm1_hairline_scaled_instances` | output | 0 | stroke snap 09b2c9130 | Ruffle exporter (d70f2c0aa) | 366 | 0 | 1551 | 366 | 399/6 of 511 | draw | b (own fixture) | golden → Flash capture, max_outliers measured |
| `regression/avm1_stroke_style_id_order` | output | 0 | stroke snap 09b2c9130 | Ruffle exporter (d70f2c0aa) | 56 | 0 | 2004 | 56 | 874/0 of 876 | draw | b (own fixture) | golden → Flash capture, max_outliers measured |
| `regression/avm2_layer_group_alpha` | output | 2 | stroke snap 09b2c9130 | upstream Ruffle layer_* golden | 1876 | 13763 | 14103 | 12322 | 638/12 of 675 | screen | b | RvF |
| `regression/avm2_layer_group_erase` | output | 3 | stroke snap 09b2c9130 | upstream Ruffle layer_* golden | 1796 | 11579 | 11538 | 9786 | 633/3 of 653 | screen | b | RvF |
| `visual/blend_modes/add` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 695 | 5465 | 6344 | 5718 | 248/20 of 276 | screen | b | RvF |
| `visual/blend_modes/alpha_no_layer` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1888 | 12301 | 12590 | 10751 | 650/1 of 675 | screen | b | RvF |
| `visual/blend_modes/darken` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1774 | 8513 | 8678 | 6966 | 593/0 of 611 | screen | b | RvF |
| `visual/blend_modes/difference` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 777 | 7535 | 9255 | 8574 | 240/20 of 276 | screen | b | RvF |
| `visual/blend_modes/erase_no_layer` | output | 3 | stroke snap 09b2c9130 | not Flash (s27) | 1880 | 11990 | 11990 | 10154 | 650/1 of 675 | screen | b | RvF |
| `visual/blend_modes/hardlight` | output | 4 | stroke snap 09b2c9130 | not Flash (s27) | 1742 | 11610 | 12302 | 10636 | 544/0 of 612 | screen | b | RvF |
| `visual/blend_modes/invert` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1758 | 12800 | 12830 | 11141 | 572/11 of 586 | screen | b | RvF |
| `visual/blend_modes/layer_alpha` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1876 | 13763 | 14103 | 12322 | 638/12 of 675 | screen | b | RvF |
| `visual/blend_modes/layer_erase` | output | 3 | stroke snap 09b2c9130 | not Flash (s27) | 1796 | 11579 | 11538 | 9786 | 633/3 of 653 | screen | b | RvF |
| `visual/blend_modes/lighten` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 325 | 5980 | 7517 | 7252 | 166/0 of 203 | screen | b | RvF |
| `visual/blend_modes/multiply` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1749 | 8659 | 8914 | 7227 | 593/0 of 611 | screen | b | RvF |
| `visual/blend_modes/overlay` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 1623 | 10463 | 11141 | 9558 | 592/1 of 611 | screen | b | RvF |
| `visual/blend_modes/screen` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 544 | 5839 | 6514 | 6049 | 227/24 of 260 | screen | b | RvF |
| `visual/blend_modes/subtract` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 739 | 5797 | 7073 | 6406 | 250/20 of 273 | screen | b | RvF |
| `visual/drawing_api/drawing_order` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 5985 | 11831 | 11831 | 11850 | 1492/1501 of 2999 | draw | b (neutral) | RvF |
| `visual/filters/bevel` | output | 3 | stroke snap 09b2c9130 | untestable (s27) | 4076 | 116897 | 117000 | 114943 | 14352/13043 of 34994 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/bevel_full` | output | 4 | stroke snap 09b2c9130 | untestable (s27) | 1956 | 110141 | 109894 | 108328 | 42390/41038 of 60812 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/bevel_inner` | output | 4 | stroke snap 09b2c9130 | untestable (s27) | 2065 | 73381 | 73380 | 73134 | 3393/3554 of 8822 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/bevel_outer` | output | 3 | stroke snap 09b2c9130 | untestable (s27) | 2186 | 126477 | 127241 | 124908 | 39317/37797 of 52755 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/blur_scales_with_screen` | output | 2 | stroke snap 09b2c9130 | untestable (s27) | 73030 | s | s | s | – | draw | c (stage size) | none |
| `visual/filters/blur_size_grows` | output | 3 | stroke snap 09b2c9130 | not Flash (s27) | 360 | 99011 | 100796 | 100579 | 664/573 of 12487 | draw | b | RvF |
| `visual/filters/color_matrix` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 12 | 16717 | 16717 | 16707 | 4/0 of 4 | draw | b | RvF |
| `visual/filters/displacement_map` | output | 20 | stroke snap 09b2c9130 | not Flash (s27) | 2005 | 38375 | 38374 | 38470 | 387/397 of 1563 | draw | b (neutral) | RvF |
| `visual/filters/drop_shadow` | output | 2 | stroke snap 09b2c9130 | untestable (s27) | 34700 | 49187 | 48332 | 47996 | 713/596 of 4022 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/drop_shadow_angles` | output | 2 | stroke snap 09b2c9130 | not Flash (s27) | 13495 | 68725 | 68725 | 67729 | 1231/885 of 4707 | draw | b | RvF |
| `visual/filters/glow` | output | 2 | stroke snap 09b2c9130 | untestable (s27) | 5387 | 31905 | 31905 | 31770 | 508/433 of 2699 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/glow_with_alpha_strength` | output | 4 | stroke snap 09b2c9130 | untestable (s27) | 2414 | 67343 | 67337 | 66788 | 32190/30985 of 38828 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/filters/glow_without_composite_source` | output | 3 | stroke snap 09b2c9130 | untestable (s27) | 5850 | 30907 | 30907 | 30657 | 588/463 of 2949 | draw | c (host fonts) | none (stroke moves Flash-ward on changed px) |
| `visual/opaque_background` | output | 1 | stroke snap 09b2c9130 | not Flash (s27) | 2780 | 6248 | 6248 | 3474 | 1388/1 of 1390 | draw | b | RvF |
| `visual/simple_shapes/gradients/focal_radial` | output | 13 | stroke snap 09b2c9130 | not Flash (s27) | 10366 | 10366 | 10366 | 3 | 3616/0 of 3667 | draw | b | RvF |
| `visual/simple_shapes/gradients/gradients` | output | 1 | stroke snap 09b2c9130 | not Flash (s27) | 1243 | 6959 | 6959 | 5874 | 480/0 of 638 | draw | b | RvF |
| `visual/simple_shapes/layers` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 3 | 1759 | 1759 | 1756 | 1/0 of 1 | draw | b (neutral) | RvF |
| `visual/simple_shapes/masks` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 12 | 4119 | 4119 | 4119 | 2/2 of 4 | draw | b (neutral) | RvF |
| `visual/simple_shapes/masks_equal_clipdepth` | output | 0 | stroke snap 09b2c9130 | not Flash (s27) | 12 | 4119 | 4119 | 4119 | 2/2 of 4 | draw | b (neutral) | RvF |

<!-- 51 rows -->
