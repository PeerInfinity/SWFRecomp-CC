# s29 w1-lowq-next: LOW .5 tie and "LOW stroke y" (report)

Slot `w1-lowq-next`, wave 1: diagnosis plus a measured prototype.
- Branch `fanout/w1-lowq-next`, base `origin/master` `aa36d43a`. Its runtime is the s29 baseline code `bfa47037b`.
- Cloud box, Dawn on lavapipe.
- Corpus as downloaded 2026-11-26 (`visual avm2 from_shumway avm1 from_gnash text fonts timeline swf import_assets
  mixed_avm`), flash_fixes applied.

**Fidelity.** Local *before* renders of `drawing_order` and `masks` are byte-identical to CI's `ruffle-image-results`
actuals (`6bfbec440`), so local grading is CI-grade. The prototype's kill-switch leg (`SWF_LOWQ_GEOM_SNAP=0`) was also
byte-identical to CI master on `blend_modes/add`.

**New files** (all under `session29-fanout-reports/`):
- `w1-lowq-next-report.md` (this file).
- `w1-lowq-next-prototype.patch`: `git diff origin/master -- SWFModernRuntime`. It is reverted on the branch.
- `w1-lowq-next-fixtures/lowq_tsnap_tie_probe/`:
  - the FLASH request fixture (§5): `create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`, `cells.json`;
  - our renders, `ours_master.png` and `ours_tsnap.png`.
- `w1-lowq-next-fixtures/ledger/`:
  - `tsnap_vs_ci_baseline.txt`: every LOW comparison that moved;
  - `tsnap_vs_fp32.txt`: master vs prototype, graded against FP32 LOW;
  - the 256-test `tsnap_all_low_summary.txt`;
  - the gate list `flash_golden_low_gate.txt` (114 tests);
  - `variantB_subset_summary.txt`.
- `w1-lowq-next-fixtures/tools/`:
  - `swfshapes.py`: dumps DefineShape edges, line styles, PlaceObject matrices and sprites;
  - `setplace.py`: rewrites a root PlaceObject2's translation;
  - `ledger.py`: compares a local leg with CI `image_results_graphics.json`.

## Verdicts (lead)

1. **"LOW stroke y rule" is the wrong premise for all three class-c rows. REFUTED.** None of them is driven by stroke y.
   Their goldens are not Flash (s27 provenance: `drawing_order`, `masks`, `masks_equal_clipdepth` are "not Flash"), so
   they grade only against the s28 FP32 LOW recaptures (LNX == WIN at 0 px).
   - **`masks` / `masks_equal_clipdepth` contain no strokes.** The content is FILLED curves (DefineShape1, 110 / 136
     curved edges, no line styles). On their diff pixels Flash's fill sits 1 px left / up of ours: 1 554 px one way vs
     350 the other. The sprite sits at a fractional placement (4.35, 2.4), and snapping that placement to (4, 2) cuts
     the distance to Flash from 4 398 to 3 248. The residual is then balanced left/right (curve flattening). See §2.
   - **`drawing_order`'s distance to Flash is stroke WIDTH and band PLACEMENT, not y.** Of 6 412 diff px:
     - ~4.5 k are the black 3-px rect borders: Flash's bands sit ~1 px inside ours (§3);
     - ~1.9 k are the two 5-px 45° Drawing-API lines: Flash spans **4 px per row**, ours 8.

     The s28 "+934" was the y rule moving rows inside a much larger width/placement gap; ours→Flash is still 12 784.
2. **New Flash fact: Flash LOW 45° stroke width is not our perpendicular device-width model, in either direction.**
   - On the Flash-golden `acid-stroke-0`, the 4-px square under `(2, 0, −1.414, 1.414)` has 45° edges at 4 px/row in
     Flash; ours draws 6. The same square under `(2, 0, +1.414, 1.414)` draws 16 in Flash and 15 for us.
   - The 2-px 26.6° Drawing-API polyline in `lowq_sample_point_probe` matches ours.

   No single pen model fits these (§3). This is a probe question, not a code change: §5, row 4 + row 5.
3. **The .5 tie: Flash snaps a translation at LOW.** On `avm2_button_scroll_rect` (button at 22.5, scrollRect
   (10, 10, 100, 100)) the crop and content land as if translated by `ceil(T − ½)` = 22.
   - The prototype that snaps every vector draw's device translation takes it from **288 to 15** channels vs FP32
     (the Ruffle golden is 54). Against its own golden it goes from 234 to 45 outliers; it stays fail at tolerance 0.
   - This explains the s28 tie table without a per-source epsilon. `lowq_fill_edges` (placement offsets on
     integer-local rects) predicts exactly the same pixels under "snap the translation, then centre rule" as under
     "centre rule with .5 included". s28's `sweep_placement` cells were integer-aligned in stage space, so a ≤ ½-px
     geometry snap could not show there either. Neither Flash oracle refutes TSNAP.
   - The remaining .5 source is the AS3 `drawRect(5.5, …)` exclusion. It is a vertex .5 in Drawing-API data under
     an integer placement, so TSNAP does not touch it. Probe row 5, c6 vs c7.
4. **The shader prototype (snap the WORLD translation of every vector draw) is NO-GO.** It fails the gate:
   - **`visual/cache_as_bitmap/scroll_rect` goes pass → fail** (Flash golden, 0 → 2 056).
   - 14 `blend_modes/*` rows, `simple_shapes/layers`, `opaque_background` and `cache_as_bitmap/drawing_api` move AWAY
     from their FP32 flash_fixes goldens, by up to +11 948 channels.
   - 11 `filters/*` rows also move away from FP32 LOW.

   Snapping inside offscreen layers too (variant B) gives identical numbers, so layers are not the cause. In those
   SWFs Flash does **not** snap deep children's world translations. The rule's scope is the open question: root-level
   only, per display-list level, or something else. The probe's row 3 (nesting) decides it. **HOLD** on any TSNAP
   implementation until that capture exists. The completion mechanism is in §4.
5. **No flash_fixes candidates, no RvF entries, no swap-candidate rows touched.** As briefed, `invalidClipDepth`,
   `from_shumway/gradient`, `acid-gradient(-0)` and `acid-filter` are left alone.

Priced flips available now: **none**. The deliverable is the refutation, the TSNAP lead with its measured scope
problem, and one FLASH request that settles all three open rules at once.

## 1. Row provenance (brief goal 2)

| row | golden | Flash reference used | ours→FP32 (master) | golden→FP32 |
|---|---|---|---:|---:|
| `visual/drawing_api/drawing_order` | not Flash (s27) | s28 lowq-recapture LOW, LNX == WIN | 12 784 | 11 831 |
| `visual/simple_shapes/masks` | not Flash | same | 4 398 | 4 119 |
| `visual/simple_shapes/masks_equal_clipdepth` | not Flash | same (LNX vs WIN differ by 21 ch) | 4 398 | 4 119 |
| `visual/avm2_button_scroll_rect` | not Flash | same (LNX vs WIN 6 ch) | 288 | 54 |

All four captures have 2–6 colours, so they really are LOW: no AA, so not the pre-2026-11-25 HIGH trap.

## 2. masks: a placement snap, not a stroke rule

- **Structure.** The SWF holds DefineShape1 fills 2, 3, 5, 6 (no line styles) and DefineShape4 1 / 4 (1-px lines, mask
  frame only). All sit in sprite 7, which is placed at **(4.35, 2.4)**.
- **Diff orientation** (ours master vs FP32, on the diff px): v-ish and diagonal edges show Flash = ours(x+1) on
  1 554 px and = ours(x−1) on 350 px. Flash's content is up/left of ours.
- **Experiment (SWF rewrite, `setplace.py`):**

  | placement | ours→FP32 (ch) |
  |---|---:|
  | (4.35, 2.4), master | 4 398 |
  | **(4, 2)** | **3 248** |
  | (4, 2.4) | 3 652 |
  | (4.35, 2) | 4 025 |

  After the snap the residual is direction-balanced: 380 left vs 392 right, 238 vs 186. That is curve flattening, owned
  by no LOW rule.
- **Shader prototype (§4):** 3 206.

## 3. drawing_order: band placement and 45° width (not y)

**SWF content:**
- `_root.lineStyle(5, 0x00FF00); lineTo(500, 500)`;
- `attachMovie("mc")` at (250, 250), with a ±104.25 × ±85.25 rect: fill + 3-px stroke;
- `mc.lineStyle(5, 0xFF); moveTo(250, −250); lineTo(−250, 250)`;
- a root sprite at **(253.5, 246.5)** holding a ±208.5 × ±170.5 rect with fill + 3-px stroke.

**Bands, Flash vs ours.**
- Outer rect: centrelines at x 45 / 462 and y 76 / 417. Flash's bands are [45, 48) [460, 463) [75, 78) [414, 417);
  ours are [44, 47) [461, 464) [75, 78) [416, 419).
- Inner rect: each side is 1 px further in for Flash.
- Flash's rects are therefore 2 px smaller per axis. No translation snap of the .5 placement reproduces it. For
  example, half-down (253, 246) puts the outer centres at 44.5 / 461.5 / 75.5 / 416.5, and the n-stroke-snap W = 3
  band rule then gives [43, 46) on the left, against Flash's [45, 48).
- This is a LOW 3-px stroke band rule we do not have. HIGH-calibrated n-stroke-snap does not cover it.

**45° Drawing-API lines (w = 5).**
- Flash covers exactly x = y−2 … y+1 on row y: 4 px, every row.
- Ours covers 8, the perpendicular rule: 5·√2 = 7.07 sampled at the scanline top.
- 4 px is consistent with a "minor-axis pen" (horizontal span = w with both .5 ties out) or with a perpendicular width
  near w/√2. The integer-phase 45° line cannot separate the two.

**`acid-stroke-0` (Flash golden) separates them, and fits neither.**

| shape (4-px stroke, 32-px square) | matrix | our width (\|M·(1,1)\|/√2 law) | Flash band / 45° span | ours band / 45° span |
|---|---|---:|---|---|
| depth 41 parallelogram | (2, 0, −1.414, 1.414) | 4.33 | 4 rows / **4** | 4 / 6 |
| depth 51 parallelogram | (2, 0, +1.414, 1.414) | 10.45 | 10 rows / **16** | 10 / 15 |
| depth 81 rotated rect | (.707, .707, −1.414, 1.414) | 6.32 | – / **8** | – / 8 |
| depth 101 (= 41's matrix) | | 4.33 | 4 / **4** | 4 / 5 |

- The minor-axis pen fits 41 / 101 and `drawing_order`, but not 51 / 81.
- The perpendicular pen fits 81 and is near on 51, but not 41.
- Two parallelograms with the same |entries| and opposite shear differ 4 vs 16 in Flash. So Flash's LOW stroker is
  not a function of device edge direction plus one isotropic width. Local-space stroking with any single local width
  also fails: it predicts equal spans for 41 and 51.
- The 26.6° 2-px polyline (`lowq_sample_point_probe` cell (200, 40)) matches ours, but cannot discriminate (2 rows per
  column under every model).
- **Completion:** probe rows 4 and 5 (static 45° X at widths 1–10, the three acid matrices at 8 px, and a Drawing-API
  w = 5 line).

Same row, unrelated finding: the 45° rotated rect's lower-left edge (`acid-stroke-0`, rows 58–84) is 1 px low in ours.
That is a genuine stroke-y residual, but it comes with the width issue, so it waits for the same capture.

## 4. Prototype TSNAP (reverted; `w1-lowq-next-prototype.patch`)

**What it does.** At MSAA 1, the main pass, for every non-bitmap draw without style bit 0x1000 (including the
`transform[2].w`-flagged scrollRect crop and cacheAsBitmap quads), it moves the geometry by `ceil(T − 0.525) − T`,
where T is the object's device translation. The 0.025 px is half a twip of tie tolerance: without it, T = 22.5 + ε
rounded UP. The y rule (`LOWQ_SNAP_Y`) then applies to the moved vertex. The paint keeps master's formula, so the
gradient field stays screen-fixed and identical.

- **Touched in `render_webgpu.c`:**
  - the `LOWQ_VS_POSITION` macro (WGSL `vs_main`): `d0` / `lq_t` / `lq_dt` / `lq_gc` / `lq_yc`; `lq_o` merged
    into `lq_t`;
  - `lowq_put_target`: m[11] = 2 enables it; variant B, m[11] = 3, snaps inside layers.
- **Not touched:** `tag.c`.
- **Kill switch** `SWF_LOWQ_GEOM_SNAP=0` (= master; verified byte-identical on `blend_modes/add`). Variant B is
  `SWF_LOWQ_GEOM_SNAP=2`.
- **HIGH:** `gcc -E -P -DMSAA_SAMPLES=4` of master vs prototype is identical except the `__LINE__` numbers inside
  `assert` strings. Everything is preprocessor-dead at HIGH, so the HIGH canary is md5-identical by construction.

**Gate run.** All 256 `quality = "low"` image tests (376 comparisons) were run locally, graphics, with `-P 2`, and
compared with the CI baseline `45878805896`'s `image_results_graphics.json`. That covers the 114-test Flash-golden
LOW gate (s27 "Flash" ∪ flash_fixes LOW). Trace status did not move on any of the 256.

**Pass ↔ fail moves (3, all losses):**

| row | golden provenance | outliers vs golden | vs FP32 |
|---|---|---|---|
| `visual/cache_as_bitmap/scroll_rect` | **Flash** (s27 provenance) | pass → fail, 0 → 2 056 | **loss on a Flash golden: gate FAIL** |
| `from_shumway/acid/acid-gc` | not Flash | pass → fail, 0 → 3 792 | s27 capture: golden 3 792, ours 3 816 (≈ same) |
| `from_shumway/acid/acid-gradient-1` | not Flash (no capture) | pass → fail, 0 → 384 | — |

**Band moves graded vs FP32 LOW** (full list in `ledger/tsnap_vs_fp32.txt`):

- **Toward Flash (10):**

  | row | master → TSNAP |
  |---|---:|
  | `avm2_button_scroll_rect` | 288 → **15** |
  | `masks` ×2 | 4 398 → 3 206 |
  | `acid-clip-3` | 358 → 312 |
  | `acid-clip-3` frame3 | 512 → 386 |
  | `acid-child` frame5 | 504 → 381 |
  | `acid-blend` | 9 971 → 9 506 |
  | `duplicate_font` | 8 082 → 8 022 |
  | `drawing_order` | 12 784 → 12 772 |

- **AWAY from FP32 flash_fixes goldens (18):**
  - `blend_modes/*` ×14, e.g. `add` 5 347 → 15 316;
  - `simple_shapes/layers` 1 754 → 3 437;
  - `opaque_background` 1 956 → 4 300;
  - `cache_as_bitmap/drawing_api` 603 → 1 795.
- **AWAY from FP32 captures:**
  - `filters/*` ×11, e.g. `bevel_full` 92 572 → 132 370;
  - `symbol_class_conflict` 449 → 1 169;
  - `acid-child` 774 → 1 578;
  - `acid-filter` 104 → 176;
  - `acid-text-6` +72 / +9;
  - `stage3d_texture` +219.
- **Flash-golden band move:** `avm2/sprite_with_frames` 4 944 → 5 094. Every changed pixel is on the "Frame 1" text
  labels: the text field's translation snaps, and the ¼-px glyph snap is HIGH-only.
- **Probes:**
  - `lowq_sample_point_probe` 1 543 → 1 579 (still passes, limit 2 000);
  - `lowq_gradient_orient_probe` 915 → 729 (passes);
  - `lowq_fill_edges` passes, unchanged.
- **Not FP32-gradable:** `layer_group_{alpha,erase}` 2.8 k → 14.6 k (upstream Ruffle goldens) and `acid-stroke-0`
  7 173 → 7 835.

**Mechanisms of the losses (measured, not guessed):**
- **Stroke-snap interaction.** `hairline_restage` and `render_webgpu_stroke_snap` place strokes on integer device
  bands using the UNSNAPPED translation. A shader shift of exactly −½ (T = x.5) then puts those integer edges on pixel
  centres, so the bands slip 1 px. `symbol_class_conflict` (sprite at 411.5, hairline rect) shows it: our red
  columns go from 330–493 to 329–492, while Flash's are 330–494.
- **Scope.** `blend_modes/add` has a root sprite at (80.5, 38.45) and deep children at 28.5 / 87.6 / 115.1 …. The
  world-translation snap moves each child differently, and FP32 says no. Snapping only that root placement in the
  SWF (`setplace.py`, grid sprite only) was neutral: 5 347 → 5 359. The content sprite is a PlaceObject3, which the
  rewriter does not handle, so "root-level only" is **untested** there.
- **Layers are not the factor.** Variant B (snap inside offscreen layers too) gives byte-identical counts on all 8
  sampled rows.

**Completion mechanism for TSNAP (wave 2, after the FLASH capture):**
- implement the snap on the CPU in the composed translation, at the scope row 3 shows: `tag.c` `compose_children`
  (`composed[12..13]`) and the AVM2 world in `avm2_display.c`, for both the main and cab paths;
- this lets `hairline_restage` / `render_webgpu_stroke_snap`, the glyph placement and the paint snap
  (`LOWQ_VS_POSITION`'s `lq_snap_t` term, which would then become redundant) all see the same translation;
- gate on the 114-test list plus the 14 `blend_modes` rows.

## 5. LOCAL ORACLE REQUESTS

1. **FLASH: `session29-fanout-reports/w1-lowq-next-fixtures/lowq_tsnap_tie_probe/test.swf`, image, tick 1,
   DIRECT pinned** (an AVM1 root; the SWF sets `_quality = "LOW"` itself in its frame-1 DoAction). Capture LNX; WIN
   too if cheap. Also run `--screen` once to rule out a `draw()` artefact on the strokes. Do not use `--wrapped`.
   - Rows (40-px cells, 320 × 240; predictions per cell in `cells.json`; our renders `ours_master.png` /
     `ours_tsnap.png`, which differ on 878 px):
     - 0 / 1: x / y placement fractions 0 … .75 on rects whose local edge is at .25. Centre rule vs TSNAP differ at
       .35 / .45 / .5.
     - 2: a slanted triangle, same fractions.
     - 3: **nesting** (parent, child) fraction pairs. World snap vs per-level snap vs none. This decides TSNAP's
       scope.
     - 4: static 45° X strokes, widths 1 2 3 4 5 6 8 10.
     - 5:
       - c0 / c1: `drawing_order`'s 3-px stroke + fill rect at +.5 / +0;
       - c2–c4: the 4-px square under `acid-stroke-0`'s three matrices;
       - c5: AVM1 Drawing-API `lineStyle(5)` 45° line;
       - c6 / c7: a filled rect at 5.5 … 25.5 through the Drawing API vs as a static shape.
   - What to compare: grade ours vs the capture per cell. The coordinator archives it under
     `w1-local-oracles/w1-lowq-next/`. It then also becomes this fixture's `output.expected.png` (regression
     candidate, tolerance 0 + measured `max_outliers`).
   - Fixture trap check: it has no fonts and no bitmaps. The AVM1 Drawing-API calls in cells c5/c6 are new to the
     harness; if they draw nothing in Flash, say so.
2. **FLASH (optional, cheap): `visual/drawing_api/drawing_order` at quality HIGH, direct.** This tells whether the 2-px
   inset of the 3-px rect bands and the 45° w = 5 width are LOW-only. If HIGH shows them too, the gap belongs to the
   n-stroke-snap ladder, not to LOW.

## New unclaimed leads

- **The LOW 3-px stroke band rule** (`drawing_order`: Flash's rect bands ~1 px inside the n-stroke-snap W = 3 bands on
  both rects, asymmetric on the .5-placed outer rect). It is not owned by lowq or by the N ladder's HIGH rule. Request 2
  decides the owner.
- **`sprite_with_frames` text under any translation snap:** the LOW text-field translation / glyph placement is
  unmodelled (the glyph ¼-px snap is HIGH-only, `tf_glyph_quarter_snap`). Leave TSNAP off text until a capture says
  otherwise.
- **`acid-gc` / `acid-gradient-1`** are non-Flash passes that any translation snap will break. `acid-gc` already sits
  3 792 channels from its s27 Flash capture, so it is a flash_fixes candidate once a LOW capture confirms it. Not done
  here: no LOW capture exists.
