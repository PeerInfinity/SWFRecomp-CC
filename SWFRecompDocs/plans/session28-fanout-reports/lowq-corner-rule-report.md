# s28 lowq-corner-rule: Flash LOW gradient paint + the two model defects, re-graded package (report)

One-task local session, launched by `s28-coordinator`. Brief: `lowq-corner-rule-prompt.md`. Predecessor:
`lowq-recapture-report.md`. Model: `w2-lowq-sample-point.patch`.

**Deliverables**
- `lowq-final.patch`: the w2 model plus this slice's fixes, plus fixtures `regression/lowq_sample_point_probe`
  (w2's) and `regression/lowq_gradient_orient_probe` (new), plus an RvF entry. It is `git diff --binary` vs
  `origin/master` `a81888ada`; `git apply --check` passes on a fresh worktree there. **Not applied to master.**
- Branch `lowq-fixes` `20ddedf5d` (pushed as fast-forwards; no history rewrite). It is `origin/master` merged in
  (`aadf2d2ca`) plus **4 new swaps**, so 37 flash_fixes entries ride with the model.
- Probe and captures: `regression/lowq_gradient_orient_probe/` (in the patch; golden = FP32 LOW).
  `lowq-corner-rule/sweep_translation/` and `lowq-corner-rule/sweep_placement/` hold the two extra FP32 LOW sweeps
  (gen.py, cells.json, test.swf, flash_low.png). `lowq-corner-rule/tools/` holds the fitters, the grader and the
  runners.

## Verdict (lead)

1. **The brief's premise for goal 1 is overturned.** The corner paint rule is *right* for rotated linear
   gradients. On the probe, every linear cell matches index = floor(256·t) at the pixel's top-left corner, pixel
   exact: 8 angles, mirrors, anisotropic, long and skewed ramps, rotated / scaled / mirrored placements.
   `gradients/gradients` broke for another reason: its big field is a **reflect-spread** gradient, and **Flash
   evaluates reflect / repeat gradients with the gradient matrix translation scaled by 255/256** (shape-local).
   That one law fits every spread cell pixel-exact, from a 0.03 to a 40 ramp-entry shift, and predicts
   `gradients`' measured +1.52-entry offset. Implemented: `gradients/gradients` goes from 173 226 (w2) to **3**
   channels off Flash (master 5 874). `reflect` / `repeat` go from 645 528 / 649 083 (which the recapture had
   written off as "Flash draws spread modes differently") to **5 628** each.
2. Two more Flash rules came out of the probe and are implemented:
   - radial and focal ramps read **round(256 t)**, linear ramps floor;
   - the paint uses the object's device translation **rounded half-down**, in the main pass only (not inside
     blend / filter layers).
3. **Goal 2 is half fixed.**
   - `opaqueBackground`: Flash fills device pixels floor(min)..ceil(max) *inclusive*. That rule is now implemented
     for the background rect: `visual/opaque_background` goes 3 904 (w2) → **1 956** (master 3 474). It is not
     applied to cacheAsBitmap-snapped entries: on those it would build on the snapped slot
     (`visual/cache_as_bitmap/avm2_button` 826 → 1 228). Those keep master's rect, byte-identical.
   - `avm2_button_scroll_rect` stays at w2's 288 (master 54). Its loss is the y rule's exact-.5 tie: the content
     edge at 22.5 lands at 22.5+ε in float. An epsilon fix took it to 78, but cost the Flash-golden probe (+150),
     `morph_test1` frame1 (+200) and `bevel_full` (+4 200). Flash's .5-tie direction is not one rule (§4), so it is
     reverted and booked class c.
4. **Package grade** (current master + final model, vs Flash LOW). The recapture table: 56 class b, 12 c, 2 same,
   2 untestable. Its summed distance to Flash: master 3.30M, w2 3.31M, **final 1.81M** channels.
   **Flash-golden LOW gate: 0 losses** (73 tests). **HIGH canary: 35/35 PNGs byte-identical** (16 HIGH members);
   HIGH WGSL is byte-identical. No trace-axis moves.
5. Recommendation: **land `lowq-final.patch` + `lowq-fixes` together.** Expected flips are in §6.

## 1. Probe and method

- **Probe** `regression/lowq_gradient_orient_probe`: AVM1 SWF 8, 71 static 40×40 cells on a 320×360 stage. Rows:
  smooth 32-px ramps at 0/30/45/60/90/135/180/315°; hard-step ramps at those and 13 more angles; mirrored /
  anisotropic / long ramps; rotated / ×2 / mirrored placements; fractional shape offsets; radial / focal controls;
  reflect / repeat spreads; skewed matrices including `gradients/gradients`' own reflect matrix, near its origin and
  at its real stage translation.
- **Captured** with `run_image.py --quality low` (Linux `draw()`). Two captures were byte-identical.
- **Sweeps** (scratch SWFs, archived under `lowq-corner-rule/`):
  - `sweep_translation`: reflect ramps with the gradient translation moved by 0 … 1280 px in x and y; placements
    of ±0.05 … ±500 px; pad controls.
  - `sweep_placement`: fractional *placement* translations (.25 / .5 / .75 / 1.75 / −.25, x and y), pad / reflect,
    linear / radial.
- **Fit** (`fit_paint_point.py`, `tools/model.py`): every interior pixel of a linear cell bounds the cell's offset
  s, where index = floor(u + s) and u = 256·t at the corner. Exact cells give an interval. Radials are
  grid-searched.
- **Ours:** scratch worktrees, `verify_output.py --mode=graphics` one test at a time, 2 parallel under
  `flock /tmp/swfrecomp-cpu.lock`. The before-leg is clean master `89a78bc36` (runtime == `4b5dca5c2`, the
  after-leg base). Metric: Ruffle's, channels > row tolerance, vs the recapture's FP32 LOW PNGs (`grade.py`; it
  reproduces the recapture's master column exactly).

## 2. The Flash LOW gradient rules (probe fits)

| rule | evidence |
|---|---|
| paint at the pixel's **top-left corner** | all 43 pad-linear cells: s ∈ [−0.03, +0.03] around 0, 0 misses (ours with w2's corner = the same intervals) |
| linear ramps: floor(256 t) | as above. An exact integer tie reads the upper entry on axis-aligned slopes and the lower one on irrational slopes (Flash fixed-point). Not modelled; ±1 level |
| radial / focal: **round**(256 t) | `rad_c` 377 → 9 misses, `rad_frac` 335 → 25, `rad_aniso` 339 → 17, `focal_06` 345 → 0; residual = coarse sqrt near r = 0 |
| reflect / repeat: gradient translation **× 255/256** | s = (∇u_local · T_local)/256: tx slope 0.0311 = α/256, ty slope = β/256; ±50-px placement splits to 0.005; out to s = 40 entries, 0–1 misses per cell; `refl_rad` 0 misses; `gradients` predicts 1.52 (measured 1.522, slope equal to 1e-6) |
| paint: object translation **rounded half-down**, ceil(T − ½) | sweep_placement: 964 → 70 misses over 24 cells (none: 964; round-half-up: 2 335; floor: 8 536). Geometry does not move with it |
| … but **not inside blend / filter layers** | `blend_modes/add` 5 347 → 3 978, `hardlight` 9 815 → 8 812, `bevel_full` 92 572 → 87 305 without it; nothing else moved |
| `opaqueBackground` fill: device px floor(min)..ceil(max) **inclusive** | `visual/opaque_background` (bounds 272.5..487.5 × 59.5..329.45 cover 272..488 × 59..330); not applied on cacheAsBitmap-snapped entries (§Verdict 3) |

**Implementation** (`render_webgpu.c`, all preprocessor-dead at MSAA ≠ 1):
- the fragment `dpdx` corner shift is replaced by a vertex-stage paint position `lq_paint` (screen-fixed;
  centre − ½ − snap);
- `LOWQ_SPREAD_FIX` adds (½ − M·0)/256 to `inv_pos` for spread ≠ pad;
- `LOWQ_RAD_BIAS` adds +½ entry in `radial_t` / `focal_radial_t`;
- the snap flag rides in stage `m[11]` (`lowq_put_target`: 1 main pass, 0 offscreen layer);
- the opaqueBackground rect goes through `renderer_draw_rect_centre` → `render_webgpu_draw_rect_ex(…, 0x9000)`.
  Style bit 0x1000 skips the y rule, bit 0x8000 snaps outward, and bits 0x2000/0x4000 mark the max corner.

## 3. Re-graded recapture table (72 comparisons; final = `lowq-final.patch` model)

"master→FL" is clean master; "w2→FL" is the recapture's after column; **final** is this patch. "swap" = a
`lowq-fixes` entry (**new** = added this slice). ✅ = passes vs its Flash golden.

| test | cmp | tol | golden→FL | master→FL | w2→FL | **final→FL** | class | swap |
|---|---|---:|---:|---:|---:|---:|---|---|
| `avm1/movieclip_begin_gradient_fill` | output | 6 | 33 800 | 33 691 | 34 425 | 34 216 | c |  |
| `avm1/movieclip_line_gradient_style` | output | 6 | 15 126 | 15 069 | 15 117 | 15 357 | c |  |
| `avm2/displayobject_mask` | output | 0 | 56 | 56 | 38 | 38 | b | yes |
| `avm2/displayobject_opaque_background` | output | 1 | 484 | 484 | 428 | 428 | b |  |
| `avm2/displayobject_scrollrect` | output | 0 | 428 | 428 | 152 | 152 | b | yes |
| `avm2/graphics_bad_direct_commands` | output | 1 | 588 | 588 | 273 | 273 | b | yes |
| `avm2/loader_events` | output | 0 | 15 752 | 15 752 | 15 734 | 15 734 | b |  |
| `avm2/loader_loadbytes_events` | output | 0 | 188 | 188 | 102 | 102 | b | yes |
| `avm2/mouse_pick_dobj_mask` | output | 1 | 177 | 177 | 99 | 99 | b | yes |
| `avm2/mouse_pick_non_interactive_dobj_mask` | output | 1 | 168 | 168 | 90 | 90 | b | yes |
| `avm2/stage3d_bitmap` | output | 4 | 88 791 | 88 766 | 88 808 | 88 808 | c |  |
| `avm2/stage3d_texture` | output | 8 | 623 338 | 622 048 | 622 246 | 622 075 | c |  |
| `avm2/symbol_class_conflict` | output | 0 | 5 293 | 449 | 449 | 449 | same |  |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | 5 | 393 | 393 | 193 | 193 | b | yes |
| `from_gnash/misc-ming.all/morph_test1` | frame2 | 5 | 1 563 | 1 563 | 1 530 | 1 530 | b | yes |
| `from_gnash/misc-ming.all/morph_test1` | frame3 | 5 | 1 563 | 1 563 | 1 530 | 1 530 | b | yes |
| `from_gnash/misc-ming.all/morph_test1` | frame4 | 5 | 1 563 | 1 563 | 1 530 | 1 530 | b | yes |
| `from_gnash/misc-ming.all/morph_test1` | frame5 | 5 | 1 563 | 1 563 | 1 530 | 1 530 | b | yes |
| `from_gnash/misc-ming.all/morph_test1` | frame6 | 5 | 760 | 760 | 727 | 727 | b | yes |
| `visual/avm2_button_scroll_rect` | output | 0 | 54 | 54 | 288 | 288 | c |  |
| `visual/blend_modes/add` | output | 2 | 5 465 | 5 718 | 3 978 | 5 347 | b | yes |
| `visual/blend_modes/alpha_no_layer` | output | 2 | 12 301 | 10 751 | 9 586 | 9 586 | b | yes |
| `visual/blend_modes/darken` | output | 2 | 8 513 | 6 966 | 6 160 | 6 385 | b | yes |
| `visual/blend_modes/difference` | output | 2 | 7 535 | 8 574 | 5 030 | 8 154 | b | yes |
| `visual/blend_modes/erase_no_layer` | output | 3 | 11 990 | 10 154 | 9 320 | 9 320 | b | yes |
| `visual/blend_modes/hardlight` | output | 4 | 11 610 | 10 636 | 8 812 | 9 815 | b | yes |
| `visual/blend_modes/invert` | output | 2 | 12 800 | 11 141 | 10 040 | 10 211 | b | yes |
| `visual/blend_modes/layer_alpha` | output | 2 | 13 763 | 12 322 | 11 067 | 11 067 | b | yes |
| `visual/blend_modes/layer_erase` | output | 3 | 11 579 | 9 786 | 9 032 | 9 032 | b | yes |
| `visual/blend_modes/lighten` | output | 2 | 5 980 | 7 252 | 4 346 | 6 915 | b | yes |
| `visual/blend_modes/multiply` | output | 2 | 8 659 | 7 227 | 6 324 | 6 639 | b | yes |
| `visual/blend_modes/overlay` | output | 2 | 10 463 | 9 558 | 8 096 | 8 791 | b | yes |
| `visual/blend_modes/screen` | output | 2 | 5 839 | 6 049 | 4 180 | 5 695 | b | yes |
| `visual/blend_modes/subtract` | output | 2 | 5 797 | 6 406 | 4 037 | 6 026 | b | yes |
| `visual/cache_as_bitmap/drawing_api` | output | 1 | 1 798 | 1 798 | 603 | 603 | b | yes |
| `visual/cache_as_bitmap/edittext_scroll` | output.01 | 0 | 1 264 | 1 298 | 1 300 | 1 300 | c |  |
| `visual/cache_as_bitmap/edittext_scroll` | output.02 | 0 | 1 258 | 1 286 | 1 291 | 1 291 | c |  |
| `visual/cache_as_bitmap/nested_rotation` | output | 0 | 387 | 387 | 96 | 96 | b | yes |
| `visual/drawing_api/drawing_order` | output | 0 | 11 831 | 11 850 | 12 784 | 12 784 | c |  |
| `visual/drawing_api/fills_and_lines` | output | 2 | 36 154 | 36 424 | 65 755 | 5 703 | b |  |
| `visual/drawing_api/gradient_focal_point` | output | 13 | 28 805 | 28 809 | 28 747 | 24 109 | b | yes |
| `visual/filters/bevel` | output | 3 | 116 897 | 114 943 | 108 531 | 107 165 | b |  |
| `visual/filters/bevel_full` | output | 4 | 110 141 | 108 328 | 87 876 | 92 572 | b |  |
| `visual/filters/bevel_inner` | output | 4 | 73 381 | 73 134 | 60 830 | 64 795 | b |  |
| `visual/filters/bevel_outer` | output | 3 | 126 477 | 124 908 | 102 073 | 112 428 | b |  |
| `visual/filters/blur_scales_with_screen` | output | 2 | size | size | size | size | untestable |  |
| `visual/filters/blur_size_grows` | output | 3 | 99 011 | 100 579 | 98 991 | 98 991 | b |  |
| `visual/filters/color_matrix` | output | 0 | 16 717 | 16 707 | 16 674 | 16 674 | b | yes |
| `visual/filters/displacement_map` | output | 20 | 38 375 | 38 470 | 37 939 | 37 942 | b |  |
| `visual/filters/drop_shadow` | output | 2 | 49 187 | 47 996 | 46 460 | 46 460 | b |  |
| `visual/filters/drop_shadow_angles` | output | 2 | 68 725 | 67 729 | 65 470 | 65 470 | b |  |
| `visual/filters/drop_shadow_scales_with_screen` | output | 2 | size | size | size | size | untestable |  |
| `visual/filters/glow` | output | 2 | 31 905 | 31 770 | 29 881 | 29 881 | b |  |
| `visual/filters/glow_with_alpha_strength` | output | 4 | 67 343 | 66 788 | 57 327 | 57 327 | b |  |
| `visual/filters/glow_without_composite_source` | output | 3 | 30 907 | 30 657 | 29 848 | 29 848 | b |  |
| `visual/fonts/device-font` | output | 0 | 10 611 | 10 611 | 10 596 | 10 596 | b |  |
| `visual/fonts/duplicate_font` | output | 0 | 8 070 | 8 070 | 8 082 | 8 082 | c |  |
| `visual/fonts/glyph` | output | 0 | 1 656 | 1 656 | 1 470 | 1 470 | b | yes |
| `visual/opaque_background` | output | 1 | 6 248 | 3 474 | 3 904 | 1 956 | b | **new** |
| `visual/simple_shapes/gradients/focal_radial` | output | 13 | 10 366 | 3 | 0 | 0 ✅ | b | yes |
| `visual/simple_shapes/gradients/gradients` | output | 1 | 6 959 | 5 874 | 173 226 | 3 | b | **new** |
| `visual/simple_shapes/gradients/radial` | output | 1 | 67 449 | 65 541 | 3 453 | 3 435 | b |  |
| `visual/simple_shapes/gradients/reflect` | output | 1 | 644 343 | 645 528 | 645 528 | 5 628 | b | **new** |
| `visual/simple_shapes/gradients/repeat` | output | 1 | 649 083 | 649 083 | 649 083 | 5 628 | b | **new** |
| `visual/simple_shapes/heavy_tesselation` | output | 0 | 69 352 | 69 355 | 44 707 | 44 707 | b |  |
| `visual/simple_shapes/layers` | output | 0 | 1 759 | 1 756 | 1 754 | 1 754 | b | yes |
| `visual/simple_shapes/masks` | output | 0 | 4 119 | 4 119 | 4 398 | 4 398 | c |  |
| `visual/simple_shapes/masks_equal_clipdepth` | output | 0 | 4 119 | 4 119 | 4 398 | 4 398 | c |  |
| `visual/simple_shapes/overlaps` | output | 0 | 1 792 | 1 792 | 1 088 | 1 088 | b |  |
| `visual/simple_shapes/scroll_rect_mask` | output | 0 | 11 612 | 11 612 | 11 416 | 11 416 | b |  |
| `visual/simple_shapes/text_field_mask` | output | 0 | 2 378 | 2 378 | 2 404 | 2 404 | c |  |
| `visual/text/String_path_variable_button` | output | 0 | 2 196 | 2 199 | 2 199 | 2 199 | same |  |

Totals: b 56, c 12, same 2, untestable 2. Summed channels vs Flash: master 3 298 894, w2 3 305 479, **final 1 812 733**.

**Class c (12):**
- `drawing_order` (+934; w2's): the diagonal Drawing-API lines get the fill y rule. Exempting strokes fixes it,
  but costs `graphics_simple_shapes` (Flash golden, 114 → 140), the probe and `fills_and_lines`, so it was
  reverted (§4).
- `avm2_button_scroll_rect` (+234; .5 tie, §4).
- `masks*` / `text_field_mask` / `duplicate_font` / `edittext_scroll` / `stage3d_*`: w2's numbers, unchanged here.
- `begin_gradient_fill` (+525) / `line_gradient_style` (+288): channels up but *pixels down* (17 914 vs 18 266;
  324 fixed vs 186 new). The new error pixels are band edges of the linearRGB / focal reflect cells.

## 4. What did not work (measured, reverted)

- **y-rule epsilon** (`ceil(y − 0.501)`, so exact .5 ties always include their row): button 288 → 78 and the
  probe's 4.5-offset rects fixed. But it cost `lowq_sample_point_probe` (+150, in its AS3-drawRect cell),
  `morph_test1` frame1 (193 → 393) and `bevel_full` (+4 200). Flash's tie direction depends on where the .5 comes
  from:
  - shape coordinates: both edges included (probe 4.5..35.5 → 4..35);
  - placement (`lowq_fill_edges`, sweep_placement): half-open;
  - AS3 `drawRect` 5.5: excluded.

  Next step: a tie probe across those three sources.
- **Stroke exemption from the y rule.** Drawing-API strokes (`renderer_stroke_snap`) plus static strokes (bit 31)
  fixed `drawing_order` (12 784 → 11 850). It cost `graphics_simple_shapes` 124 → 140 (Flash golden),
  `lowq_sample_point_probe` 1 693 → 1 939 (limit 2 000), `fills_and_lines` +771 and both gradient-style rows.
  Snapped timeline runs only: also probe-negative. Reverted.
- An apparent Flash-golden loss on `simple_loop_test` was a stale golden in the after-tree: its flash_fixes
  postdate that tree's base. Against the FP32 golden it is 0 channels on all 7 frames, before and after.

## 5. Gates

- **Flash-golden LOW gate: 0 losses.** 73 tests = s27 merged-provenance "Flash" LOW rows ∪ flash_fixes LOW rows,
  excluding the table above. 60 pass before and after. The other 13 fail at master too, and 8 of them improve:
  - `graphics_draw_path` 704 → 192
  - `graphics_gradients` 3 681 → 304
  - `graphics_simple_shapes` 164 → 124
  - `acid-shapes-testing` 15 079 → 10 317
  - `acid-stroke-0` 10 262 → 7 965
  - `gradientTransform` 9 → 6 (a HIGH golden, recapture §5)
  - `sprite_with_frames` −12
  - `BeginBitmapFill` +12 (a device-font label, master floor)

  `acid-textfield` is +84; the rest are unchanged.
- Fixtures: `lowq_gradient_orient_probe` **PASS** 915 / limit 1 000 (master 93 696). `lowq_sample_point_probe`
  **PASS** 1 543 / 2 000 (w2 1 990; master 11 171). `lowq_fill_edges` PASS 0.
- **HIGH:** `render_canary.py` on 16 HIGH canary members (`gradient`/`stroke`/`scroll`/`drawing` picks + 4 seeded):
  35/35 identical, no trace or image status changes. `gcc -E` at MSAA 4: vertex and fragment WGSL byte-identical
  after literal concatenation. C deltas: `draw_rect → draw_rect_ex(…, 0)` (flags forced to 0 at HIGH) and w2's
  `lowq_upload_stage` / `cab_snap` restatements.
- **The other 139 LOW tests** (every `quality = "low"` test in the corpus outside the two lists; both legs run):
  no trace moves. 171 comparisons are count-identical, 16 move within their status, and **22 go pass → fail**
  (Ruffle goldens). On 21 of them, FP32 LOW was captured this slice (`lowq-corner-rule/flash_rest/`). Distance to
  Flash, master → final:
  - toward Flash, big:
    - `acid/acid-gradient-0` 69 348 → **61**
    - `acid/acid-gradient` 75 738 → 1 686
    - `from_shumway/gradient` 15 611 → **16**
    - `invalidClipDepth` 1 800 → **0** (Flash-exact)
    - `acid/acid-filter` 536 → 104
  - toward Flash, small:
    - `MaskTest` 187 → 170
    - `acid-blend` 10 132 → 9 971
    - `acid-child` frame5 522 → 504
    - `acid-clip-3` 376 → 358 / frame3 552 → 512
    - `acid-text-x` −48
    - `text/auto_size/{height,return,width}` −270 / −255 / −558
    - `text/style_changes_in_html` −114
  - same: `acid-child` output, `acid-text-6` frame5;
  - away: `acid-text-6` output +9, `acid-text-escape` +64.
  - Not capturable: `fonts/embed_matching/{fallback_preferences,match_style}` (no Flash capture; device fonts).
  - The 22nd, `visual/cache_as_bitmap/avm2_button` (826 → 1 228, away), is fixed: the final patch keeps it
    byte-identical to master.
- **Trace axis:** no status moves on any of the 278 LOW tests run.
- **Base:** graded on runtime `4b5dca5c2`. The patch also applies to `a81888ada`, where a smoke build of
  `gradients`, `opaque_background` and the probe is byte-identical to the graded renders. The final cab /
  opaqueBackground split was re-run on its only two LOW users.

## 6. Expected-flip ledger (patch + `lowq-fixes` together; CI graphics, pixel axis)

Statuses: CI's per-comparison image pass/fail, before = master, after = patch + `lowq-fixes` (37 goldens swapped
to FP32 LOW). No trace-axis flips are expected.

**fail → pass (1):** `visual/simple_shapes/gradients/focal_radial` (swapped golden; ours == FP32, 0 channels).

**pass → fail, swapped rows (18), all closer to Flash, graded vs FP32:**
- `avm2/{displayobject_mask, displayobject_scrollrect, graphics_bad_direct_commands, loader_loadbytes_events,
  mouse_pick_dobj_mask, mouse_pick_non_interactive_dobj_mask}`
- `from_gnash/misc-ming.all/morph_test1` frame1–6
- `visual/cache_as_bitmap/{drawing_api,nested_rotation}`
- `visual/drawing_api/gradient_focal_point`
- `visual/fonts/glyph`
- `visual/simple_shapes/gradients/{reflect,repeat}`

**pass → fail, unswapped recapture rows (15):**
- class b, WIN ≠ LNX or no capture: `displayobject_opaque_background`, `radial`, `heavy_tesselation`, `overlaps`,
  `scroll_rect_mask`, `loader_events`, `drop_shadow_scales_with_screen`, `device-font`,
  `String_path_variable_button`;
- class c: `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`, `stage3d_bitmap`,
  `avm2_button_scroll_rect`, `duplicate_font`, `text_field_mask`.

**pass → fail, rest of LOW (21 comparisons / 17 tests):**
- `fonts/embed_matching/{fallback_preferences,match_style}`
- `from_shumway/{MaskTest, gradient, invalidClipDepth}`
- `from_shumway/acid/{acid-blend, acid-child (output, frame5), acid-clip-3 (output, frame3), acid-filter,
  acid-gradient, acid-gradient-0, acid-text-6 (output, frame5), acid-text-escape, acid-text-x}`
- `text/auto_size/{height,return,width}`, `text/style_changes_in_html`

Unchanged status, still failing, but moving: the recapture's other rows (§3), and the Flash-golden gate rows (§5).

**Swap candidates for the next slice** (Linux FP32 captured here; a Windows check is still needed): `invalidClipDepth`
(ours == FP32), `from_shumway/gradient` (16), `acid-gradient-0` (61), `acid-gradient` (1 686), `acid-filter` (104).


## 7. Not done / next slice

- **.5-tie probe (S, local):** rect edges at .5 from shape coordinates, from placement, and from AS3 `drawRect`,
  top / bottom / left / right. That decides the epsilon (§4); `avm2_button_scroll_rect` is the row it would
  recover.
- **Stroke y rule (M):** Flash LOW strokes need their own rule. Thin diagonal Drawing-API lines want the centre
  rule; probe strokes and `graphics_simple_shapes` want the y rule. Probe: diagonal and axis strokes at 1 / 2 / 4
  px, static and Drawing-API.
- Not modelled: Flash's fixed-point tie direction on ramp entries, and the radial sqrt near r = 0 (≤ 8 levels at
  the centre pixel).
- No CI dispatched, as briefed.
