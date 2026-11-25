# s28 lowq-recapture: Flash 32 LOW recapture of the w2-lowq-sample-point swap table (report)

One-task local session, launched by `s28-coordinator`. Brief: `lowq-recapture-prompt.md`. Inputs:
`w2-lowq-sample-point-report.md` §4 (72 comparisons / 66 tests) and `w2-lowq-sample-point.patch`.

**Files**
- `lowq-recapture/png/` — Flash 32 captures at quality=low: `<test>__<cmp>.low.png` (Linux wrapper `draw()`),
  `.screen.low.png` (Linux `--screen`), `.win.low.png` (Windows `draw()`). `lowq-recapture/*.json` = sweep grades
  vs the golden.
- `lowq-recapture/provenance-audit/` — the §5 re-captures (LOW and HIGH wrapper, direct pinned new stub).
- `lowq-recapture/compare.json` — every number in §3 (outlier px / channels / max at the row's tolerance).
- `lowq-fixes` branch (pushed, NOT master): 33 `flash_fixes` entries + golden files + RvF entry + README row.

## Verdict (lead)

1. **The brief's premise is overturned: the archived s27 captures were already LOW.** All 53 s27 wrapper/screen
   captures of these rows are **byte-identical** to the fresh `--quality low` captures. The other 19 had no s27 capture, or an AVM2
   direct one (`loader_events`, `loader_loadbytes_events`). The wrapper always set `stage.quality`; the old-stub
   bug only hit pinned-*direct* runs. `gradients/gradients` was NOT a HIGH capture.
   The w2 "golden→Flash" column stands as measured.
2. **The w2 cost is stale by half: 37 of the 72 comparisons already fail at current master** (local == CI
   `16033a154`/`4163c12aa` byte-for-byte on the counts: `blend_modes/add` 695, `focal_radial` 10366, `gradients`
   1243, `drop_shadow` 34700). Post-baseline landings (n-stroke-snap, glyph-quarter-snap, filter-residuals, …)
   flipped all 14 `blend_modes`, 13 of the 15 `filters/*` rows, `focal_radial`, `gradients`, `opaque_background`,
   `drawing_order`, `masks*`, `edittext_scroll`, `layers`, `symbol_class_conflict`. **The model's marginal cost at
   master is 35 pass→fail comparisons** (§4), of which 16 are in the swap list.
3. **Class (a) is empty**: no golden == Flash-LOW at its tolerance, so the model loses no Flash-LOW golden here.
4. **Class (c) = 14 comparisons; one real model defect dominates.** `gradients/gradients` goes 5 874 → 173 226
   channels off Flash. A/B variants (§2) pin it on ONE component: the **gradient corner paint shift
   (`LOWQ_SHADE_HEAD`)**. Without it the row scores exactly the before render's 5 874, and
   `fills_and_lines` (36 402 → 32 185) and `begin_gradient_fill` (33 691 → 33 633) go *closer* to Flash than
   before. But the same shift is what wins `radial` (65 541 → 3 453), `focal_radial` (3 → 0, a PASS vs Flash) and
   the probe (10 671 → 1 825). The **floor LUT is inert** at every test tolerance (variant without it: identical
   probe / radial; marginally worse on `gradients`).
5. **Recommendation: fix the corner rule first (one more probe), then land model + the 33 swaps together.** See §6.

## 1. Method

- **Flash:** `sweep_goldens.py <test> --quality low` (wrapper `draw()`, every numeric trigger) for all 66 tests,
  Linux, ≤ 3 parallel. Re-run once into scratch: **all 72 PNGs byte-identical** (deterministic). `--screen` for
  all 14 `blend_modes`, `fills_and_lines`, `overlaps` and both loader rows: screen == draw (0 px) except the four
  non-LAYER blends `alpha_no_layer`, `erase_no_layer`, `layer_alpha`, `layer_erase` (those are graded and swapped
  from the screen capture; a second screen run was byte-identical). Windows (`--windows`, sequential) for all 66.
- **Untestable in Flash:** `filters/blur_scales_with_screen`, `filters/drop_shadow_scales_with_screen`
  (`viewport_dimensions` 400×400 vs a 200×200 stage: size mismatch).
- **Ours:** scratch worktrees at `c02afc1e9` (= origin/master at start), *before* clean and *after* =
  `git apply --include='SWFModernRuntime/*'` of the w2 patch (its fixture/doc hunks are already on master). The
  patch was live: `lowq_sample_point_probe` FAIL 11 171 before → PASS 1 825 after. `verify_output.py
  --mode=graphics --verbose`, one batch per suite dir under `flock /tmp/swfrecomp-cpu.lock`, `CCACHE_NODIRECT=1`
  (preprocessor-mode ccache: content-hashed, so the before/after `render_webgpu.c`/`tag.c` can't alias).
  SWFRecomp rebuilt at `c02afc1e9` (`-j4`, under the lock).
- **Metric:** Ruffle's, per channel `> tolerance` at the row's first check; tables give **channels** (pixels in
  `compare.json`). "golden→FL" = golden vs Flash-LOW, "before/after→FL" = our render vs Flash-LOW.

## 2. Isolating the gradient defect (variants of the after build)

| channels off Flash-LOW | before | after (w2) | after − corner shift | after − floor LUT |
|---|---:|---:|---:|---:|
| `simple_shapes/gradients/gradients` (tol 1) | 5 874 | **173 226** | **5 874** | 176 375 |
| `simple_shapes/gradients/radial` (tol 1) | 65 541 | **3 453** | 65 490 | 3 453 |
| `avm1/movieclip_begin_gradient_fill` (tol 6) | 33 691 | 34 425 | 33 633 | 34 536 |
| `drawing_api/fills_and_lines` (tol 2) | 36 402 | 65 755 | 32 185 | 68 696 |
| `regression/lowq_sample_point_probe` (tol 2; its golden IS Flash) | 11 171 | **1 825** | 10 671 | 1 825 |

- "− corner shift" replaces `LOWQ_SHADE_HEAD`'s `v_args − ½·dpdx − ½·dpdy` with `v_args`; "− floor LUT" sets
  `LOWQ_GRADIENT_LOOKUP` to `""`. The vertex y rule stays in both.
- **Mechanism.** On `gradients`' big rotated linear fill, before is within ±1 of Flash everywhere; after is off by
  ±2 across the whole 427×310 field (signed error flips sign either side of the red band). A least-squares fit of
  the residual against Flash's local gradient gives before ≈ Flash shifted (−0.97, −0.05) px and after ≈ (−0.72,
  −0.95) px: the corner rule moves this field the wrong way in y. The probe's ramps were all **axis-aligned,
  increasing, 32-px** (H, V) plus radial; the corner rule fits those exactly and fails this rotated one. So the rule
  is right for radials and axis-aligned linears, wrong (or incomplete) for rotated linear fills. One probe decides it
  (§7).
- **Other class-(c) mechanisms** (newly-wrong pixels vs before, classified against Flash's own edges):
  - `visual/avm2_button_scroll_rect` (54 → 288): 76 of 78 new pixels sit on **horizontal** edges. That is the vertex
    y rule applied inside a button's scrollRect, where Flash keeps the centre rule. The crop quad is exempt
    (`crop_m` flag), its content is not.
  - `visual/opaque_background` (3 474 → 3 904): 215 of 215 new pixels on horizontal edges. Same y rule, on the
    `opaqueBackground` fill quad. Candidate: exempt it like the Bitmap/crop quads.
  - `drawing_api/drawing_order` (+934): new pixels are interior, not edges: gradient paint (corner shift).
  - `simple_shapes/masks`, `masks_equal_clipdepth` (+279), `text_field_mask` (+26): mixed. Edges move both ways;
    mask stencil shapes ride the y rule.
  - `movieclip_begin_gradient_fill` (+734): repeat/reflect-spread cell 5 259 → 6 730 px, one linear cell
    192 → 625; solid cells unchanged. Corner shift (the variant fixes it).
  - `fonts/duplicate_font` (+12), `edittext_scroll` (+2/+5), `stage3d_bitmap` (+42), `line_gradient_style` (+48):
    noise-level. `edittext_scroll`, `stage3d_*` are also WIN≠LNX.
- `reflect` / `repeat` are "same" vs Flash (645 528 / 649 083 channels either way) but leave their Ruffle golden by
  642k: Flash LOW draws these spread modes completely differently (≈ 215k px off any of us). Not a sample-point
  question.

## 3. The reclassified table (72 comparisons)

Classes per the brief: **a** golden == Flash-LOW (in tol); **b** golden ≠ Flash-LOW and after closer than before; **c** after farther from Flash than before. "before→FL" (current master) replaces the w2 golden→Flash column as the comparator, since master moved. WIN→LNX = Windows `draw()` vs the graded Linux capture at the row tolerance; for the four screen rows it compares Windows draw with Linux SCREEN, which is not like for like (Windows draw == Linux draw: 0 px on all four). ✅ = passes Flash-LOW at its tolerance.

| test | cmp | tol/max | golden→FL | before→FL | after→FL | after→golden | WIN→LNX | class | swap |
|---|---|---|---:|---:|---:|---:|---:|---|---|
| `avm1/movieclip_begin_gradient_fill` | output | 6/0 | 33800 | 33691 | 34425 | 2662 | 125 | **c** |  |
| `avm1/movieclip_line_gradient_style` | output | 6/0 | 15126 | 15069 | 15117 | 1128 | 34 | **c** |  |
| `avm2/displayobject_mask` | output | 0/0 | 56 | 56 | 38 | 30 | 0 | b | **YES** |
| `avm2/displayobject_opaque_background` | output | 1/0 | 484 | 484 | 428 | 280 | 8 | b | no: WIN≠LNX |
| `avm2/displayobject_scrollrect` | output | 0/0 | 428 | 428 | 152 | 398 | 0 | b | **YES** |
| `avm2/graphics_bad_direct_commands` | output | 1/0 | 588 | 588 | 273 | 327 | 0 | b | **YES** |
| `avm2/loader_events` | output | 0/0 | 15752 | 15752 | 15734 | 122 | 0 | b (screen) | no: Flash load not done at tick (blank) |
| `avm2/loader_loadbytes_events` | output | 0/0 | 188 | 188 | 102 | 122 | 0 | b (screen) | **YES** |
| `avm2/mouse_pick_dobj_mask` | output | 1/0 | 177 | 177 | 99 | 120 | 0 | b | **YES** |
| `avm2/mouse_pick_non_interactive_dobj_mask` | output | 1/0 | 168 | 168 | 90 | 96 | 0 | b | **YES** |
| `avm2/stage3d_bitmap` | output | 4/24 | 88791 | 88766 | 88808 | 177 | 4598 | **c** |  |
| `avm2/stage3d_texture` | output | 8/117 | 623338 | 623336 | 622246 | 1860 | 19052 | b | no: WIN≠LNX |
| `avm2/symbol_class_conflict` | output | 0/0 | 5293 | 449 | 449 | 5022 | 0 | same |  |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | 5/0 | 393 | 393 | 193 | 200 | 0 | b | **YES** |
| `from_gnash/misc-ming.all/morph_test1` | frame2 | 5/0 | 1563 | 1563 | 1530 | 75 | 0 | b | **YES** |
| `from_gnash/misc-ming.all/morph_test1` | frame3 | 5/0 | 1563 | 1563 | 1530 | 75 | 0 | b | **YES** |
| `from_gnash/misc-ming.all/morph_test1` | frame4 | 5/0 | 1563 | 1563 | 1530 | 75 | 0 | b | **YES** |
| `from_gnash/misc-ming.all/morph_test1` | frame5 | 5/0 | 1563 | 1563 | 1530 | 75 | 0 | b | **YES** |
| `from_gnash/misc-ming.all/morph_test1` | frame6 | 5/0 | 760 | 760 | 727 | 75 | 0 | b | **YES** |
| `visual/avm2_button_scroll_rect` | output | 0/0 | 54 | 54 | 288 | 234 | 6 | **c** |  |
| `visual/blend_modes/add` | output | 2/0 | 5465 | 5718 | 3978 | 1096 | 0 | b (screen) | **YES** |
| `visual/blend_modes/alpha_no_layer` | output | 2/0 | 12301 | 10751 | 9586 | 2883 | 115684 | b (screen) | **YES** |
| `visual/blend_modes/darken` | output | 2/0 | 8513 | 6966 | 6160 | 2415 | 0 | b (screen) | **YES** |
| `visual/blend_modes/difference` | output | 2/0 | 7535 | 8574 | 5030 | 1238 | 0 | b (screen) | **YES** |
| `visual/blend_modes/erase_no_layer` | output | 3/0 | 11990 | 10154 | 9320 | 2847 | 111226 | b (screen) | **YES** |
| `visual/blend_modes/hardlight` | output | 4/0 | 11610 | 10636 | 8812 | 2661 | 0 | b (screen) | **YES** |
| `visual/blend_modes/invert` | output | 2/0 | 12800 | 11141 | 10040 | 2809 | 0 | b (screen) | **YES** |
| `visual/blend_modes/layer_alpha` | output | 2/0 | 13763 | 12322 | 11067 | 2815 | 78170 | b (screen) | **YES** |
| `visual/blend_modes/layer_erase` | output | 3/0 | 11579 | 9786 | 9032 | 2702 | 76479 | b (screen) | **YES** |
| `visual/blend_modes/lighten` | output | 2/0 | 5980 | 7252 | 4346 | 702 | 0 | b (screen) | **YES** |
| `visual/blend_modes/multiply` | output | 2/0 | 8659 | 7227 | 6324 | 2395 | 0 | b (screen) | **YES** |
| `visual/blend_modes/overlay` | output | 2/0 | 10463 | 9558 | 8096 | 2472 | 0 | b (screen) | **YES** |
| `visual/blend_modes/screen` | output | 2/0 | 5839 | 6049 | 4180 | 931 | 0 | b (screen) | **YES** |
| `visual/blend_modes/subtract` | output | 2/0 | 5797 | 6406 | 4037 | 1150 | 0 | b (screen) | **YES** |
| `visual/cache_as_bitmap/drawing_api` | output | 1/0 | 1798 | 1798 | 603 | 1195 | 0 | b | **YES** |
| `visual/cache_as_bitmap/edittext_scroll` | output.01 | 0/5 | 1264 | 1298 | 1300 | 287 | 1281 | **c** |  |
| `visual/cache_as_bitmap/edittext_scroll` | output.02 | 0/5 | 1258 | 1286 | 1291 | 289 | 1281 | **c** |  |
| `visual/cache_as_bitmap/nested_rotation` | output | 0/0 | 387 | 387 | 96 | 339 | 0 | b | **YES** |
| `visual/drawing_api/drawing_order` | output | 0/0 | 11831 | 11850 | 12784 | 6915 | 0 | **c** |  |
| `visual/drawing_api/fills_and_lines` | output | 2/0 | 36154 | 36402 | 65755 | 19910 | 5524 | **c** (screen) |  |
| `visual/drawing_api/gradient_focal_point` | output | 13/0 | 28805 | 28809 | 28747 | 4361 | 0 | b | **YES** |
| `visual/filters/bevel` | output | 3/6 | 116897 | 114943 | 108531 | 63222 | 4144 | b | no: WIN≠LNX |
| `visual/filters/bevel_full` | output | 4/18 | 110141 | 108328 | 87876 | 35962 | 7742 | b | no: WIN≠LNX |
| `visual/filters/bevel_inner` | output | 4/18 | 73381 | 73134 | 60830 | 27440 | 7745 | b | no: WIN≠LNX |
| `visual/filters/bevel_outer` | output | 3/18 | 126477 | 124908 | 102073 | 62381 | 7748 | b | no: WIN≠LNX |
| `visual/filters/blur_scales_with_screen` | output | 2/0 | size | size | size | 73093 | 0 | untestable (viewport ≠ stage) |  |
| `visual/filters/blur_size_grows` | output | 3/0 | 99011 | 100579 | 98991 | 2988 | 39 | b | no: WIN≠LNX |
| `visual/filters/color_matrix` | output | 0/0 | 16717 | 16707 | 16674 | 54 | 0 | b | **YES** |
| `visual/filters/displacement_map` | output | 20/72 | 38375 | 38470 | 37939 | 11049 | 2576 | b | no: WIN≠LNX |
| `visual/filters/drop_shadow` | output | 2/0 | 49187 | 47996 | 46460 | 39985 | 1664 | b | no: WIN≠LNX |
| `visual/filters/drop_shadow_angles` | output | 2/0 | 68725 | 67729 | 65470 | 44222 | 176 | b | no: WIN≠LNX |
| `visual/filters/drop_shadow_scales_with_screen` | output | 2/0 | size | size | size | 1200 | 0 | untestable (viewport ≠ stage) |  |
| `visual/filters/glow` | output | 2/0 | 31905 | 31770 | 29881 | 18373 | 1563 | b | no: WIN≠LNX |
| `visual/filters/glow_with_alpha_strength` | output | 4/18 | 67343 | 66788 | 57327 | 15800 | 7750 | b | no: WIN≠LNX |
| `visual/filters/glow_without_composite_source` | output | 3/0 | 30907 | 30657 | 29848 | 19184 | 1552 | b | no: WIN≠LNX |
| `visual/fonts/device-font` | output | 0/3 | 10611 | 10611 | 10596 | 711 | 15813 | b | no: device font |
| `visual/fonts/duplicate_font` | output | 0/0 | 8070 | 8070 | 8082 | 39 | 0 | **c** |  |
| `visual/fonts/glyph` | output | 0/0 | 1656 | 1656 | 1470 | 744 | 0 | b | **YES** |
| `visual/opaque_background` | output | 1/0 | 6248 | 3474 | 3904 | 2782 | 0 | **c** |  |
| `visual/simple_shapes/gradients/focal_radial` | output | 13/0 | 10366 | 3 | 0 ✅ | 10365 | 0 | b | **YES** |
| `visual/simple_shapes/gradients/gradients` | output | 1/0 | 6959 | 5874 | 173226 | 6956 | 0 | **c** |  |
| `visual/simple_shapes/gradients/radial` | output | 1/0 | 67449 | 65541 | 3453 | 51435 | 210 | b | no: WIN≠LNX |
| `visual/simple_shapes/gradients/reflect` | output | 1/0 | 644343 | 645528 | 645528 | 642270 | 0 | same |  |
| `visual/simple_shapes/gradients/repeat` | output | 1/0 | 649083 | 649083 | 649083 | 644640 | 0 | same |  |
| `visual/simple_shapes/heavy_tesselation` | output | 0/3 | 69352 | 69355 | 44707 | 35846 | 42 | b | no: WIN≠LNX |
| `visual/simple_shapes/layers` | output | 0/0 | 1759 | 1756 | 1754 | 31 | 0 | b | **YES** |
| `visual/simple_shapes/masks` | output | 0/0 | 4119 | 4119 | 4398 | 2630 | 21 | **c** |  |
| `visual/simple_shapes/masks_equal_clipdepth` | output | 0/0 | 4119 | 4119 | 4398 | 2630 | 21 | **c** |  |
| `visual/simple_shapes/overlaps` | output | 0/0 | 1792 | 1792 | 1088 | 870 | 3 | b (screen) | no: WIN≠LNX |
| `visual/simple_shapes/scroll_rect_mask` | output | 0/0 | 11612 | 11612 | 11416 | 272 | 4 | b | no: WIN≠LNX |
| `visual/simple_shapes/text_field_mask` | output | 0/0 | 2378 | 2378 | 2404 | 630 | 0 | **c** |  |
| `visual/text/String_path_variable_button` | output | 0/12 | 2196 | 2199 | 2199 | 78 | 1435 | same |  |

Totals: **a 0**, **b 52**, **c 14**, same 4, untestable 2.

## 4. What the model costs at current master

- 37 of the 72 comparisons already fail at master (§Verdict 2). For those the model's "pass → fail" is not its cost.
- **35 still pass at master and fail after the model**:
  - **16 are in the swap list** (the 6 avm2 rows, `morph_test1` ×6, `cache_as_bitmap/drawing_api`,
    `nested_rotation`, `gradient_focal_point`, `fonts/glyph`). They are graded against Flash after the swap, and fail
    either way; after is closer to Flash on every one.
  - **19 are not swapped:**
    - class c: `begin_gradient_fill`, `line_gradient_style`, `avm2_button_scroll_rect`, `fills_and_lines`,
      `duplicate_font`, `text_field_mask`, `stage3d_bitmap`;
    - closer to Flash but host-dependent (WIN≠LNX): `displayobject_opaque_background`, `stage3d_texture`, `radial`,
      `heavy_tesselation`, `overlaps`, `scroll_rect_mask`;
    - other: `loader_events` (Flash capture blank at the tick), `device-font`, `reflect`, `repeat`,
      `String_path_variable_button`, `drop_shadow_scales_with_screen`.
- With the swaps, 17 already-failing comparisons (14 blends, `color_matrix`, `focal_radial`, `layers`) are also
  graded against Flash. **`focal_radial` then PASSES with the model (0 channels vs Flash; before 3)**: the only
  fail → pass in the package.

## 5. Provenance audit of the Flash-golden LOW set (old-stub / HIGH evidence)

The s27 merged sweep (`golden-provenance-data/merged.json`) has 79 quality=low tests with a Flash verdict. 15 rest
on evidence other than a LOW wrapper capture. Re-checked here (`lowq-recapture/provenance-audit/`):

| row | old evidence | LOW re-check | verdict |
|---|---|---|---|
| `avm1/mcl_target_gif87a`, `gif89a` | direct UNPINNED (= HIGH) | direct pinned, new stub (LOW applied) | **PASS: claim holds at LOW** |
| `from_shumway/gradientTransform` | wrapper `--quality high` (exact) | direct pinned new stub LOW: 3 px / 9 ch over tol 3 | **golden = Flash HIGH, NOT Flash LOW** |
| `from_shumway/acid/acid-color` frame1 | wrapper high | wrapper LOW: 86 790 px diff; HIGH: PASS | **golden = Flash HIGH, NOT Flash LOW** |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | direct-pinned AVM2 root (renders HIGH) | wrapper LOW 30 511 px; wrapper HIGH **PASS** | **golden = Flash at stage HIGH, NOT Flash LOW** |
| `avm2/loader_image` | direct AVM2 root (HIGH) | wrapper LOW == wrapper HIGH byte-identical (both 9 801 px off: wrapper load artifact) | quality-insensitive content: claim holds |
| `avm2/sprite_with_frames` | direct AVM2 root (HIGH) | wrapper LOW ≠ HIGH (both ~20k off: stage-dependent test) | **unverifiable at LOW** |
| `avm2/bitmapdata_encode_{jpeg,png}_visual`, `bitmapdata_sync`, `edittext_always_show_selection`, `focus_root_movie`, `focus_stage`, `fonts/embed_matching/no_font_found`, `focus_highlight_empty_clip` | direct AVM2 root (HIGH) | wrapper can't run them (stage null) | **unverifiable at LOW** (AVM2 root ignores the stub's quality) |

So 3 "Flash" LOW goldens are Flash-**HIGH** (`gradientTransform`, `acid-color` frame1, `acid-bitmap-draw_quality_low`),
and 9 AVM2-root rows (`sprite_with_frames` + 8) carry a Flash claim made at HIGH that can't be checked at LOW. The
w2 gate counted all of them as Flash LOW targets. They pass after the model, so nothing moves today, but none of the
12 should be used as LOW-model evidence. (The pinned AVM1 LOW rows the coordinator re-captured as `.newstub` are
not repeated here.)

## 6. Recommendation

**Fix the gradient corner rule first, then land model + swaps together.** As patched, the model buys `radial`,
`focal_radial` (→ PASS vs Flash) and every swap row's move toward Flash. It pays with a 30× regression on
`gradients/gradients` (5 874 → 173 226 vs Flash) plus the `fills_and_lines`/`drawing_order`/gradient-fill losses,
all from one line (`LOWQ_SHADE_HEAD`). Two fixes are cheap and specific:

1. **Corner shift:** fit it on rotated linear gradients (probe in §7). Data in hand: corner is right for radials
   and axis-aligned increasing linears, and wrong on `gradients`' rotated linear. Gating it to radial fills alone
   would keep `radial`/`focal_radial`, restore `gradients`/`fills_and_lines`, and cost the probe's linear H/V cells.
   That stays a guess until the probe exists.
2. **Exempt the `opaqueBackground` quad and a button's scrollRect content from the vertex y rule** (the
   horizontal-edge losses in §2).

If the coordinator prefers to land now: model + the 33 swaps are internally consistent (every swap row is class b,
deterministic, LNX == WIN in tol, no device fonts). Expect −35 passing comparisons vs master, +1 (`focal_radial`),
and the `gradients` regression booked against the model.

### flash_fixes list (branch `lowq-fixes`, 33 entries / 28 tests; written, NOT on master)

Every entry: Flash 32 quality=low, Linux deterministic ×2, `upstream_sha256` = the current mirror file (checked equal to Ruffle `origin/master` `6f0ac73ff`), evidence = `lowq-recapture/png/…`, `apply_flash_fixes.py --check`: 33 APPLIED, 0 STALE.

- `avm2/displayobject_mask`, `avm2/displayobject_scrollrect`, `avm2/graphics_bad_direct_commands`,
  `avm2/loader_loadbytes_events`, `avm2/mouse_pick_dobj_mask`, `avm2/mouse_pick_non_interactive_dobj_mask`
- `from_gnash/misc-ming.all/morph_test1` `frame1`…`frame6`
- `visual/blend_modes/{add,darken,difference,hardlight,invert,lighten,multiply,overlay,screen,subtract}` (draw == screen)
- `visual/blend_modes/{alpha_no_layer,erase_no_layer,layer_alpha,layer_erase}` (**screen** capture; Windows has no
  screen path; Windows draw == Linux draw 0 px)
- `visual/cache_as_bitmap/drawing_api`, `visual/cache_as_bitmap/nested_rotation`
- `visual/drawing_api/gradient_focal_point` (WIN vs LNX max 12 < tol 13: in tolerance, but fragile)
- `visual/filters/color_matrix`, `visual/fonts/glyph` (embedded; WIN == LNX exact)
- `visual/simple_shapes/gradients/focal_radial` (**after PASSES**), `visual/simple_shapes/layers`

Deliberately NOT swapped:
- class-b rows with WIN≠LNX beyond tolerance: all bevel/glow/drop_shadow/displacement/blur_size_grows filters,
  `radial` (70 px), `heavy_tesselation`, `overlaps` (1 px), `scroll_rect_mask` (2 px),
  `displayobject_opaque_background` (4 px), `stage3d_texture`;
- `loader_events`: the Flash capture is blank at the tick (real-I/O load timing in the wrapper);
- `device-font`: device font;
- class c / same / untestable rows.

`overlaps`, `scroll_rect_mask` and `displayobject_opaque_background` miss LNX == WIN by 1–4 px, so they are cheap
adds if the coordinator accepts Linux-only evidence.

## 7. Not done / next slice

- **Next slice (S, local): rotated-linear-gradient LOW probe.** One AS3 SWF with 32-px black→white linear ramps
  at 0/30/45/90/135/180° and negative-scale matrices, plus `gradients`' own fill. Capture `--quality low` draw, and
  fit the paint point per angle against the after build with and without `LOWQ_SHADE_HEAD`. That decides §6.1.
- No CI dispatched, as briefed. The coordinator grades patch + `lowq-fixes` together, by name.
- `lowq_fill_edges`, already on master, was not re-graded here.
