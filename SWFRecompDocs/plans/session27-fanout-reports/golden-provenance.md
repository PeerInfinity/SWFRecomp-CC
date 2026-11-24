# s27 golden-provenance sweep: every Ruffle image golden vs real Flash Player 32 (LNX)

One-task session, 2026-11-24. Brief: `golden-provenance-prompt.md` (s27-coordinator, Robert's request). Tool:
`tools/flash-oracle/sweep_goldens.py` (new; README §"Golden sweep"). Flash PNGs cited for non-Flash verdicts are in
`golden-provenance/` (159 PNGs, 2.9 MB; `<test with / → __>__<comparison>[.screen|.direct].png`). Machine-readable
rows: `golden-provenance-data/merged.json`.

## Summary paragraph for `graphics-fanout-playbook.md` §26

> **s27 golden-provenance sweep (Linux Flash Player 32, 389 image tests / 596 comparisons, `regression/` excluded):**
> **229 goldens are Flash-made** (184 pixel-exact, 45 within the test's own tolerance), **12 are near-Flash** (fail
> the tolerance at max diff ≤ 16, i.e. rounding / other-platform), **146 are not Flash**, and **209 are untestable**
> (mostly `input.json` interaction, then Stage3D, video, default-font and viewport scaling).
> Re-priced pixel board: **15 of our 38 failing rows have a Flash-made golden** (`graphics_draw_triangles`,
> `graphics_gradients`, `graphics_simple_shapes`, `sprite_with_frames`, `BeginBitmapFill`, `acid-mask` ×3,
> `acid-shapes`, `acid-shapes-testing`, `acid-stroke-0`, `acid-textfield`, `bitmapbuttons`, `avm1_color`, plus
> `acid-text-4` at max diff 1). These are real Flash targets, and all of them are upstream `known_failure` too.
> 14 failing rows have non-Flash goldens. Grade those against the archived Flash PNG, not the golden.
> **`visual/filters/blur_quality` is the one clean flip.** Our CI render is pixel-identical to Flash (0 px), while
> the golden is 342 k px / max 9 off Flash. That meets the s26 ACCEPTED_DIFFS prune criterion; an RvF entry is
> written.
> Upstream has started replacing goldens with Flash references (26 "Flash Player output/reference" commits; latest
> `5128d3943` / `7facc1fcc`, 2026-11-23). Our mirror is stale for 2 of them (`avm2/pixelbender_dithering`,
> `bitmapdata-clone`), and the upstream files equal our Flash capture at 0 px, so sync them.
> **Oracle limit found:** the Linux projector's stage window races its startup size (about 640×480 first). Direct
> runs of SWFs narrower than 640 stay show-all scaled, so coordinate-dependent direct traces are unreliable there.
> `movieclip_hittest`'s Flash `false` was re-checked and still holds (stable in direct ×2 and in wrapped mode).

## Method

- **Scope.** Every dir under `ruffle-tests/tests/swfs/` whose `test.toml` parses with a non-empty
  `image_comparisons`, excluding `regression/` and `_*` harness dirs: **389 tests, 596 comparisons**. s26's "279"
  came from a header grep. A `^\[image_comparisons` grep finds 333, because it misses the tests whose comparisons are
  only `[[image_comparisons.<name>.checks]]` tables (e.g. `bitmapdata_draw`, `acid-shapes`).
- **`sweep_goldens.py`** captures every numeric `trigger` tick in one wrapper run. It grades each comparison with ALL
  of its `checks`, using Ruffle semantics (per-channel outliers > tolerance; pass iff ≤ `max_outliers` for every
  check). `trigger = "fs_command"` comparisons are reported untestable. Three passes:
  1. **draw** (CaptureWrapper + `draw()`, the proven tick model) on all 389;
  2. **`--screen`** (Xvfb grab, one run per trigger tick) on every draw failure, per the non-LAYER blend rule. It
     turned 2 comparisons into passes; the blend-mode goldens stay "not Flash" in both modes;
  3. **`--direct`** (new): the SWF runs as the real root and the window is grabbed after it settles. The tick is
     **not pinned**, so a direct result counts only for the last-trigger comparison, and only a PASS counts as
     evidence. A direct-only failure is "untestable". Direct mode exists because **about 50 AVM2 tests touch
     `stage` in their document-class constructor**: `stage` is null in a Loader child, so the wrapper never reaches
     tick 1 (`TypeError #1009`).
  4. Runtime-load tests (`mcl_target_*`, `loader_*`, `movieclip_methods_with_loaded_image`, `avm1_imports_avm1`) use
     direct mode as the primary capture, because AVM1 `loadMovie` never loads under the wrapper (README).
- **Verdicts.**
  - **Flash:** any valid mode passes the test's checks.
  - **near Flash:** fails, with max diff ≤ 16.
  - **not Flash:** fails with max diff > 16 and no untestable reason.
  - **untestable:** see the reasons in the Notes column.
- **Provenance.** Upstream history comes from `gh api repos/ruffle-rs/ruffle/commits?path=…`. It also queries the
  pre-2023-08 `expected.png` name, because `1c8724a458` renamed every golden. `~/CC/ruffle` is a shallow clone
  (946 commits), so `git log --follow` there sees nothing older. The mirror is blob-compared with upstream master
  `efb612fd7`.
- **Our render.** The failing-row comparison uses the CI actuals on `origin/ruffle-image-results` (`3c450b5c0`, the
  same run as `image_results_graphics.json` at `dc5d2936a`, lavapipe). Those are the pixels that are graded, so no
  local Dawn render was needed and nothing took the build lock.
- The platform is LNX 32,0,0,465 throughout; no Windows projector runs (brief).

## Counts

| Suite | Flash | near Flash | not Flash | untestable |
|---|---:|---:|---:|---:|
| avm1 | 35 | 1 | 6 | 27 |
| avm2 | 51 | 1 | 18 | 58 |
| fonts | 1 | 0 | 0 | 4 |
| from_gnash | 4 | 0 | 15 | 1 |
| from_shumway | 52 | 7 | 54 | 10 |
| import_assets | 1 | 0 | 0 | 0 |
| stage3d | 1 | 0 | 0 | 4 |
| text | 1 | 0 | 4 | 0 |
| visual | 83 | 3 | 49 | 105 |
| **total (596)** | **229** (184 exact) | **12** | **146** | **209** |

**Untestable reasons:**

| Reason | Count | Notes |
|---|---:|---|
| `input.json` interaction | 112 | |
| direct-only failure (tick unpinned) | 24 | |
| Stage3D | 22 | under Xvfb the projector often reports `Error #3702: Context3D not available` |
| video | 21 | |
| `viewport_dimensions` / `scale_factor` stage size | 13 | |
| default-font | 12 | |
| `fs_command` trigger | 3 | |
| `mode = "Release"` | 1 | `error_stack_trace_release_swf17`: the debug projector has a stack trace, so the marker is blue where release red is expected |
| FileReference.save dialog | 1 | `bitmapdata_colortransform`: its SWF still contains the golden-saving code, which hints the golden IS Flash-made |

Provenance tells:
- **Upstream `known_failure` + `<name>.ruffle.png` pairs (34 comparisons):** the expected PNG is meant to be the
  Flash reference. Linux Flash agrees on 19, is near on 2, and disagrees on 10. The 10 are likely Windows-Flash
  captures (text/AA heavy): the next slice's Windows pass.
- **Commits titled "Use Flash Player's output / a Flash Player reference / Correct … against Flash Player 32"
  (26 comparisons):** 24 are Flash here. The 2 misses are the stale-mirror pair.
- **42 of the 158 non-Flash goldens were re-baked in a renderer/core commit.** Examples: `7b1c101c8` "wgpu: Fix
  repeat & reflect gradients" (gradients/reflect, repeat), "core: Add pixel snapping …" (15),
  "wgpu: Implement Bevel filter", "tests: Update visual test images due to slightly different blur algorithm" — the
  brief's tell. The rest are single-commit "tests: Add/Port/Import …" images, mostly the from_shumway / from_gnash
  imports, which were rendered by Ruffle when imported.

## Re-priced pixel board

Rows are the s27 baseline (`s27-baseline-pixel-failing.txt`, **B**) ∪ the current failures in
`origin/ruffle-test-results` `image_results_graphics.json` (`dc5d2936a`, run 45339607994, **C**); regression rows
are omitted. The last column counts px over max(2, tol) as "ours≠Flash / golden≠Flash / ours-only". Ours-only =
pixels where we miss Flash and the golden doesn't, i.e. our real residual against Flash.

| Test | Comparison | B/C | ours vs golden (CI) | golden verdict | golden is a Flash target? | ours≠Fl / gold≠Fl / ours-only |
|---|---|---|---|---|---|---|
| `avm2/away3d_advanced_shallow_water_demo` | output | BC | 1326765/400 max 255 | untestable — default-font; input.json; stage3d; direct run: tick unpinned | unknown | — |
| `avm2/bitmapdata_applyfilter_blur` | output | BC | 47515/0 max 238 | untestable — default-font | unknown | — |
| `avm2/bitmapdata_draw` | output | BC | 753/600 max 255 | not Flash | no | 2051 / 1110 / 1104 |
| `avm2/bitmapdata_opaque` | output | BC | 4/0 max 127 | not Flash | no | 4 / 2 / 2 |
| `avm2/blend_scroll` | output | BC | 296/0 max 128 | not Flash | no | 195 / 87 / 108 |
| `avm2/graphics_draw_path` | output | BC | 664/0 max 255 | not Flash | no | 387 / 28 / 363 |
| `avm2/graphics_draw_triangles` | output | BC | 1812/0 max 255 | Flash | **yes — Flash target** | 1031 / 0 / 1031 |
| `avm2/graphics_gradients` | output | BC | 3685/0 max 255 | Flash | **yes — Flash target** | 1391 / 0 / 1391 |
| `avm2/graphics_simple_shapes` | output | BC | 158/0 max 255 | Flash | **yes — Flash target** | 79 / 0 / 79 |
| `avm2/pixelbender_dithering` | output | B | pass now | not Flash | no | — |
| `avm2/sprite_with_frames` | output | BC | 6342/0 max 255 | Flash | **yes — Flash target** | 1874 / 0 / 1874 |
| `avm2/stage3d_fractal` | output | BC | 1104108/100 max 255 | untestable — default-font; stage3d | unknown | — |
| `avm2/stage3d_raytrace` | output | BC | 660000/10 max 255 | untestable — input.json; stage3d | unknown | — |
| `from_gnash/misc-ming.all/BeginBitmapFill` | output | BC | 939/100 max 255 | Flash | **yes — Flash target** | 486 / 8 / 484 |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | output | BC | 1782/0 max 255 | untestable — video | unknown | — |
| `from_gnash/misc-ming.all/place_object_test` | output | BC | 38238/0 max 255 | not Flash | no | 15586 / 5209 / 12179 |
| `from_gnash/misc-ming.all/shape_test` | output | BC | 15994/0 max 255 | not Flash | no | 8508 / 1071 / 7625 |
| `from_shumway/MaskTest-2` | output | BC | 7162/0 max 251 | not Flash | no | 2415 / 2822 / 705 |
| `from_shumway/acid/acid-color-0` | output | B | pass now | not Flash | no | — |
| `from_shumway/acid/acid-mask` | output | B | — | (renamed upstream: now output.01/.05/.10) | | |
| `from_shumway/acid/acid-mask` | output.01 | C | 12018/20 max 124 | Flash | **yes — Flash target** | 5074 / 0 / 5074 |
| `from_shumway/acid/acid-mask` | output.05 | C | 10915/20 max 124 | Flash | **yes — Flash target** | 4627 / 0 / 4627 |
| `from_shumway/acid/acid-mask` | output.10 | C | 9447/20 max 128 | Flash | **yes — Flash target** | 3946 / 0 / 3946 |
| `from_shumway/acid/acid-shapes` | output | BC | 25688/25600 max 197 | Flash | **yes — Flash target** | 41758 / 0 / 41758 |
| `from_shumway/acid/acid-shapes-testing` | output | BC | 41339/0 max 255 | Flash | **yes — Flash target** | 31420 / 0 / 31420 |
| `from_shumway/acid/acid-stroke-0` | output | BC | 52702/0 max 255 | Flash | **yes — Flash target** | 18521 / 0 / 18521 |
| `from_shumway/acid/acid-text-4` | output | BC | 51678/0 max 255 | near Flash | no (near Flash) | 11760 / 0 / 11760 |
| `from_shumway/acid/acid-text-5` | output | BC | 422241/6 max 255 | not Flash | no | 63459 / 53354 / 35893 |
| `from_shumway/acid/acid-textfield` | output | BC | 15754/0 max 255 | Flash | **yes — Flash target** | 4125 / 0 / 4125 |
| `from_shumway/bitmapbuttons` | output | BC | 52/0 max 11 | Flash | **yes — Flash target** | 27 / 0 / 27 |
| `from_shumway/captions` | output | BC | 6528/0 max 255 | not Flash | no | 2134 / 2278 / 727 |
| `from_shumway/flash_text_TextField` | output | BC | 966/0 max 253 | untestable — direct run: tick unpinned | unknown | — |
| `from_shumway/gradientTransform` | output | BC | 9/0 max 11 | near Flash | no (near Flash) | 1 / 3 / 0 |
| `from_shumway/hardwrap` | output | BC | 3099/0 max 255 | not Flash | no | 1135 / 1297 / 298 |
| `from_shumway/stylesheet` | output | BC | 2089/0 max 255 | not Flash | no | 999 / 1543 / 32 |
| `visual/blend_modes/shader_as_mask` | output | B | pass now | Flash | **yes — Flash target** | — |
| `visual/cache_as_bitmap/avm1_color` | output | BC | 1200/0 max 192 | Flash | **yes — Flash target** | 600 / 0 / 600 |
| `visual/definefont4` | output | BC | 16086/0 max 255 | not Flash | no | 5325 / 6331 / 2178 |
| `visual/filters/blur_quality` | output | BC | 205332/0 max 9 | near Flash | no (near Flash) | 0 / 68444 / 0 |
| `visual/fonts/font_lookup_as3` | output | BC | 11592/72 max 255 | untestable — default-font | unknown | — |
| `visual/simple_shapes/strokes/scale` | output | BC | 19287/0 max 255 | not Flash | no | 7797 / 3589 / 4252 |
| `visual/video/colorconversion/h263` | output | BC | 3/0 max 1 | untestable — video | unknown | — |

Reading it:
- **Flash targets (15 rows).** The golden is Flash (exact, or within tolerance for `bitmapbuttons` and
  `BeginBitmapFill`), so every px we miss is real. All are upstream `known_failure` (Ruffle misses them too). Count
  `acid-text-4` here as well: its golden equals the Flash screen capture at max diff 1.
- **Non-Flash golden, and we are closer to Flash than the golden:** `MaskTest-2`, `captions`, `hardwrap`,
  `stylesheet` (only 32 ours-only px), `definefont4`, `gradientTransform` (and `bitmap_pixelsnapping`, which is upstream-ignored, not on the board) (ours 1 px over
  tol 3, golden 3). None matches Flash outright, so none earns an ignore-list disposition; the ours-only column is
  the honest residual. Recommended disposition: grade these rows against the archived Flash PNG instead of the
  golden. That is the coordinator's call (it needs a per-row golden override in `image_triage.py` or the runner).
- **Non-Flash golden, and the golden is closer to Flash:** `bitmapdata_draw`, `bitmapdata_opaque`, `blend_scroll`,
  `graphics_draw_path`, `place_object_test`, `shape_test`, `acid-text-5`, `strokes/scale`. Our residual is real work
  either way, and the Flash PNG is the better target.
- **`visual/filters/blur_quality`:** ours == Flash (0 px over tol 6, max diff 0); the golden is max 9 off. An RvF
  entry is written (`avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`), and the ACCEPTED_DIFFS entry notes that
  its prune criterion is met. `blur_fractional`'s golden is Flash-exact, so the s26 "two goldens contradict" call is
  settled in favour of `blur_fractional`.
- **Untestable (8 rows):**
  - Stage3D ×3;
  - default-font ×3 (`bitmapdata_applyfilter_blur` is already dispositioned from a Flash capture);
  - video ×2;
  - `flash_text_TextField`: direct-only, max diff 15, likely Flash but unproven.
- `pixelbender_dithering`, `acid-color-0` and `shader_as_mask` pass in the current run.

## RvF candidates (goldens that disagree with Flash)

| Test | Axis | Flash says | Golden says | Ours | Status |
|---|---|---|---|---|---|
| `visual/filters/blur_quality` | image | Flash capture == ours (0 px) | 342 229 px off Flash, max 9 | **matches Flash** | **RvF entry written** |
| `avm1/movieclip_hittest` | trace | `square.hitTest(50, 50)` = `false` | `true` | matches golden (CI pass) | Candidate. Flash is stable across direct ×2 and wrapped runs. A fix toward Flash flips a passing row to an RvF-dispositioned fail: needs a ruling. |
| `avm2/displayobject_hittestpoint_boundary` | trace + image | wrapped (unscaled): shape-flag hits on the right/top octagon edges are `false` (14 lines) | `true` | matches golden (CI pass) | **Inconclusive.** Direct mode is show-all scaled (500-wide stage) and wrapped tests an off-stage child. Needs a 1:1 root capture. |
| `from_gnash/misc-swfmill.all/missing_bitmap` | image | a missing-bitmap fill renders as a **solid red 100×100 square** | blank white | row passes vs golden | candidate (one draw capture) |
| `visual/simple_shapes/gradients/reflect`, `repeat` | image | reflect/repeat phase differs (98 % px) | re-baked in `7b1c101c8` "wgpu: Fix repeat & reflect gradients" | rows pass vs golden | candidate: a Ruffle-made golden; Flash PNG archived |
| `avm1/mcl_target_jpg` | image | JPEG decode differs (max 79); `mcl_target_png` is max 1, `gif87a`/`gif89a` exact | Ruffle's decoder | row passes vs golden | same mechanism as `getpixel-from-embedded` (ACCEPTED_DIFFS Cat 9) |

**Trace pass (106 image tests with a non-empty `output.txt`, direct mode):**

| Result | Tests | Cause |
|---|---:|---|
| byte-identical | 70 | |
| prefix + tail overrun | 1 | |
| Flash trace shorter | 18 | the test needs `input.json` mouse/key events, which direct mode doesn't replay |
| differs | 17 | see below |

The 17 differing traces split as:
- timing: netstream, the MCL `onLoadProgress` count;
- device fonts: `device_font_kerning` widths 24 vs 50 (host font);
- Stage3D unavailable;
- loadBytes `loaderURL`;
- show-all scaling: `displayobject_scrollrect` concatenatedMatrix ×1.1636 = 640/550;
- the two hitTest rows above.

## Tooling findings (README updated)

- **New `sweep_goldens.py`:** all triggers, all checks, plus `--screen` and `--direct`.
- **Stage-null constructors.** About 50 AVM2 tests can't run under the wrapper, because `stage` is null in a Loader
  child's constructor. `--direct` covers static content, but its tick is unpinned.
- **`mm.cfg PreloadSwf` root agent: dead end.** The preload SWF does run, for AVM1 and AVM2 roots alike, but the main
  movie gets a NEW Stage. The preload's `stage` turns null, and no main-movie stage event reaches it.
- **Window-size race.**
  - The projector window starts at about 640×480 and shrinks to the SWF size later.
  - Stages narrower than 640 stay show-all scaled: the drawing area measured 640×468 for a 500×250 SWF.
  - 550-wide stages are scaled for their first frames under parallel load.
  - Affected: direct-mode traces involving coordinates (`hitTest*`, `concatenatedMatrix`, mouse coords) and
    direct-mode images.
  - Wrapper draw/screen captures are immune (NO_SCALE).
  - Fix this before trusting direct-mode trace diffs: wait for a `size=WxH` drawing area before frame 1, or run
    direct traces serially and check the stage size.
- **README validation rows.** The flash-oracle README's rows for `pixelbender_dithering` / `bitmapdata-clone` were
  validated against the NEW upstream goldens, not our mirror's. Our mirror's goldens are the old Ruffle-made ones:
  22 953 px and 23 380 px off Flash.
- **`--direct` and modal dialogs.** A modal dialog (FileReference.save) fools `--direct`: the crop picks up the
  dialog.

## Next slice

1. Sync the 2 stale upstream Flash goldens (`5128d3943`, `7facc1fcc`: golden + test.toml).
2. Coordinator: decide whether non-Flash goldens should be graded against the archived Flash PNGs (a per-row
   override), for the 14 board rows above.
3. Pin the projector window size in direct mode. Then re-run the 24 direct-only rows, the hitTest candidates and
   `missing_bitmap` at 1:1.
4. A Windows-projector pass over the 12 `known_failure` "Flash references" that Linux Flash rejects (likely
   Windows-made text/AA).

## Full table

Columns: "outliers vs Flash" lists each check as `outliers/max_outliers@t<tolerance>`. Max diff and diff px are for
the best mode. Mode `draw` = wrapper `draw()`, `screen` = Xvfb window, `direct` = root run (tick unpinned).
Platform is LNX for all rows.

| Test | Comparison | Verdict | Outliers vs Flash | Max diff | Diff px | Mode | Platform | Notes |
|---|---|---|---|---:|---:|---|---|---|
| `avm1/bitmap_data_colortransform` | output | Flash (exact) | 0/0@t5 | 0 | 0 | draw | LNX |  |
| `avm1/bitmap_data_copypixels` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. e0998642f6 "core: Divide by 255 in blend_over calculation" |
| `avm1/bitmap_data_fillrect` | output | not Flash | 45/0@t0 | 255 | 18 | draw | LNX | 2 renderer/core re-bake(s), e.g. e614265c17 "core: Move fill_rect from BitmapData to bitmap_dat" |
| `avm1/bitmap_data_perlinnoise` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/bitmap_data_pixeldissolve_image` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. e74a543ebb "core: Add visual test for 'pixelDissolve()' for AV" |
| `avm1/bitmapdata_applyfilter_colormatrix` | output | Flash (in tol) | 0/0@t1 | 1 | 22500 | draw | LNX | 1 renderer/core re-bake(s), e.g. 98ce792a5b "avm1: Implement BitmapData.applyFilter()" |
| `avm1/color` | output | Flash (in tol) | 0/0@t1 | 1 | 20000 | draw | LNX |  |
| `avm1/define_font_glyph_table_order` | output | untestable | 1407/4@t5 | 255 | 469 | direct | LNX | direct run: tick unpinned |
| `avm1/define_font_glyph_table_overlap` | output | untestable | 807/4@t5 | 255 | 269 | direct | LNX | direct run: tick unpinned |
| `avm1/display_object_properties` | output | Flash (exact) | 0/0@t90 | 0 | 0 | draw | LNX |  |
| `avm1/edittext_stylesheet` | output | Flash (in tol) | 0/6@t64 | 16 | 2 | draw | LNX |  |
| `avm1/edittext_tag_indent` | output | Flash (exact) | 0/0@t128 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png) |
| `avm1/focusrect_focuslost` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.01.tab | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf8` | output.02.move | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.03.left_down | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.04.left_up | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.05.right_down | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.06.right_up | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf8` | output.07.middle_down | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf8` | output.08.middle_up | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.01.tab | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.02.move | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.03.left_down | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_mouse_swf9` | output.04.left_up | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.05.right_down | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.06.right_up | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.07.middle_down | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_mouse_swf9` | output.08.middle_up | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.01a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.01b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.02a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf5` | output.02b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf5` | output.03a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf5` | output.03b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf5` | output.04a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.04b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.05a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.05b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf5` | output.06a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf5` | output.06b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.01a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.01b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.02a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.02b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.03a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.03b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.04a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.04b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.05a | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.05b | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `avm1/focusrect_swf6` | output.06a | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/focusrect_swf6` | output.06b | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/frame_size_translated_negative` | output | Flash (in tol) | 1/1@t0 | 255 | 1 | screen | LNX |  |
| `avm1/frame_size_translated_positive` | output | Flash (in tol) | 1/1@t0 | 255 | 1 | screen | LNX |  |
| `avm1/mask_reapply` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `avm1/mask_with_drawing` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/mcl_target_gif87a` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX |  |
| `avm1/mcl_target_gif89a` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX |  |
| `avm1/mcl_target_jpg` | output | not Flash | 18010/0@t3 | 79 | 147473 | direct | LNX |  |
| `avm1/mcl_target_png` | output | near Flash | 315333/0@t0 | 1 | 147524 | direct | LNX |  |
| `avm1/mouse_events_visible_enabled` | output | untestable | 598288/0@t0 | 255 | 199730 | draw | LNX | input.json; 1 renderer/core re-bake(s), e.g. ad4dc943fa "avm1: Fix some issues with buttons" |
| `avm1/movieclip_begin_gradient_fill` | output | not Flash | 33800/0@t6 | 255 | 55202 | draw | LNX | 1 renderer/core re-bake(s), e.g. 2894f01d50 "avm1: Implement `MovieClip.lineGradientStyle`" |
| `avm1/movieclip_create_text_field` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm1/movieclip_line_gradient_style` | output | not Flash | 15126/0@t6 | 255 | 20656 | draw | LNX | 1 renderer/core re-bake(s), e.g. 2894f01d50 "avm1: Implement `MovieClip.lineGradientStyle`" |
| `avm1/movieclip_methods_with_loaded_image` | output | not Flash | 30436/0@t0 | 235 | 14679 | direct | LNX |  |
| `avm1/movieclip_setmask` | output | not Flash | 40852/0@t0 | 255 | 20020 | draw | LNX |  |
| `avm1/netstream_play_flv` | output | untestable | 57444/0@t1 | 255 | 19200 | draw | LNX | video |
| `avm1/netstream_play_flv_screen` | output | untestable | 44751/0@t1 | 235 | 15856 | draw | LNX | video; 1 renderer/core re-bake(s), e.g. 32524d3abd "core: AVM2 display object allocators always ensure" |
| `avm2/away3d_advanced_shallow_water_demo` | output | untestable | 6029/400@t30 | 251 | 624750 | direct | LNX | default-font; input.json; stage3d; direct run: tick unpinned; 2 renderer/core re-bake(s), e.g. 1cb24b41b0 "render: Support PixelBender ByteArray/Vector.<Numb"; **on our failing board** |
| `avm2/bitmap_pixelsnapping` | output | not Flash | 4233/0@t0 | 255 | 1411 | draw | LNX | 1 renderer/core re-bake(s), e.g. 4410d666ed "avm2: Implement Bitmap.pixelSnapping" |
| `avm2/bitmap_subclass_properties` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_applyfilter_blur` | output | untestable | 73140/0@t12 | 246 | 125600 | draw | LNX | default-font; 9 renderer/core re-bake(s), e.g. e73389aa71 "wgpu: Implement blur filter"; **on our failing board** |
| `avm2/bitmapdata_applyfilter_colormatrix` | output | untestable | 18419/0@t2 | 255 | 83495 | draw | LNX | default-font; 4 renderer/core re-bake(s), e.g. 284a58c817 "avm2: Implement BitmapData.apply_filter for ColorM" |
| `avm2/bitmapdata_applyfilter_destpoint` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX |  |
| `avm2/bitmapdata_applyfilter_destpoint_edges` | output | Flash (exact) | 0/35@t1 | 0 | 0 | direct | LNX | upstream known_failure (.ruffle.png) |
| `avm2/bitmapdata_clone` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_colortransform` | output | untestable | 652091/0@t5 | 255 | 219143 | direct | LNX | FileReference.save dialog in direct run; direct run: tick unpinned |
| `avm2/bitmapdata_copychannel` | output | untestable | 48667/0@t0 | 255 | 20836 | direct | LNX | direct run: tick unpinned |
| `avm2/bitmapdata_copypixels` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. e0998642f6 "core: Divide by 255 in blend_over calculation" |
| `avm2/bitmapdata_draw` | output | not Flash | 3456/5200@t0, 2025/1500@t64, 1158/600@t128 | 255 | 1152 | draw | LNX | 1 renderer/core re-bake(s), e.g. 0f6dae56b5 "core: Improve spacing of device font letters (clos"; **on our failing board** |
| `avm2/bitmapdata_draw_alpha_erase` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 2cd518013c "wgpu: Don't skip alpha/erase blend modes for Bitma" |
| `avm2/bitmapdata_draw_cab_quality` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `avm2/bitmapdata_draw_colortransform` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_draw_cpu_overwrite_gpu` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_draw_filters` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png) |
| `avm2/bitmapdata_draw_masks` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_draw_rotation` | output | not Flash | 360/0@t0 | 255 | 120 | draw | LNX | 1 renderer/core re-bake(s), e.g. 94e5aa8f34 "core: Fix calculating dirty area of BitmapData.dra" |
| `avm2/bitmapdata_draw_self_via_graphic` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_draw_stage` | output | untestable | 2196/0@t0 | 255 | 1200 | direct | LNX | direct run: tick unpinned |
| `avm2/bitmapdata_embedded` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_encode_jpeg_visual` | output | Flash (exact) | 0/0@t14 | 0 | 0 | direct | LNX |  |
| `avm2/bitmapdata_encode_png_visual` | output | Flash (exact) | 0/0@t2 | 0 | 0 | direct | LNX |  |
| `avm2/bitmapdata_fillrect` | output | not Flash | 45/0@t0 | 255 | 18 | draw | LNX | 2 renderer/core re-bake(s), e.g. e614265c17 "core: Move fill_rect from BitmapData to bitmap_dat" |
| `avm2/bitmapdata_filter_sourcerect` | output | Flash (exact) | 0/1700@t5 | 0 | 0 | draw | LNX |  |
| `avm2/bitmapdata_opaque` | output | not Flash | 2/0@t0 | 255 | 2 | draw | LNX | **on our failing board** |
| `avm2/bitmapdata_pixeldissolve_image` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 1bd9f82496 "core: Implements `BitmapData.pixelDissolve()` for " |
| `avm2/bitmapdata_sync` | output | untestable | 4078/0@t0 | 255 | 1364 | direct | LNX | direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 06bc4e1403 "wgpu: Fix sync issue introduced in #9753 and added" |
| `avm2/blend_multiply_alpha` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/blend_scroll` | output | not Flash | 174/0@t0 | 255 | 87 | draw | LNX | 1 renderer/core re-bake(s), e.g. 455124d3ba "render: Fix blending onto BitmapData contents"; **on our failing board** |
| `avm2/blend_shader_luma_lighten` | output | Flash (exact) | 0/3300@t2, 0/280@t64, 0/0@t180 | 0 | 0 | direct | LNX | 1 renderer/core re-bake(s), e.g. 583caa3389 "avm2: Implement DisplayObject.blendShader (#12238)" |
| `avm2/blend_transform` | output | near Flash | 7500/0@t0 | 1 | 2500 | draw | LNX | 1 renderer/core re-bake(s), e.g. 455124d3ba "render: Fix blending onto BitmapData contents" |
| `avm2/context3d_draw_to_bitmap_data` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX | 1 renderer/core re-bake(s), e.g. b36debbc7d "avm2: Implement Context3D.drawToBitmapData" |
| `avm2/displayobject_blendmode` | output | Flash (in tol) | 0/0@t1 | 1 | 11200 | draw | LNX | 1 renderer/core re-bake(s), e.g. f7205a02a9 "render: Add BlendMode infrastructure and implement" |
| `avm2/displayobject_colortransform_nested` | output.1 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_colortransform_nested` | output.2 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_colortransform_nested` | output.3 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_getbounds_shape` | output | Flash (in tol) | 15/3800@t0 | 191 | 15 | draw | LNX | 1 renderer/core re-bake(s), e.g. b8081ac609 "core: Use actual bounding box of curves instead of" |
| `avm2/displayobject_hittestpoint_boundary` | output | not Flash | 19420/900@t0 | 255 | 9710 | draw | LNX |  |
| `avm2/displayobject_mask` | output | not Flash | 56/0@t0 | 255 | 28 | draw | LNX |  |
| `avm2/displayobject_opaque_background` | output | not Flash | 484/0@t1 | 255 | 242 | draw | LNX |  |
| `avm2/displayobject_scrollrect` | output | not Flash | 428/0@t0 | 255 | 178 | draw | LNX |  |
| `avm2/displayobject_set_matrix_nested` | output.1 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_set_matrix_nested` | output.2 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_set_matrix_nested` | output.3 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. b9645e5e6b "avm2: Set dobj as transformed_by_script on transfo" |
| `avm2/displayobject_z` | output | Flash (in tol) | 0/6500@t100, 0/17500@t10 | 1 | 6 | direct | LNX |  |
| `avm2/edittext_always_show_selection` | output | untestable | 2976/0@t0 | 255 | 992 | direct | LNX | direct run: tick unpinned |
| `avm2/edittext_autosize_align` | output | untestable | 174162/0@t128 | 255 | 58066 | direct | LNX | direct run: tick unpinned |
| `avm2/edittext_autosize_height_dynamic` | output | Flash (exact) | 0/0@t128 | 0 | 0 | direct | LNX |  |
| `avm2/edittext_autosize_lazy_bounds_visual` | output | untestable | 12312/0@t128 | 255 | 4105 | direct | LNX | direct run: tick unpinned |
| `avm2/edittext_get_char_index_at_point` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `avm2/edittext_get_line_index_at_point` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX |  |
| `avm2/edittext_tag_indent` | output | untestable | 9729/0@t128 | 255 | 3327 | direct | LNX | direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 156c3a5c6f "core: Reimplement text wrapping for compatibility " |
| `avm2/error_stack_trace_debug_swf17` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/error_stack_trace_debug_swf18` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/error_stack_trace_release_swf17` | output | untestable | 200/0@t0 | 255 | 100 | draw | LNX | mode=Release |
| `avm2/error_stack_trace_release_swf18` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/focus_root_movie` | output | untestable | 1144/0@t0 | 255 | 395 | direct | LNX | direct run: tick unpinned |
| `avm2/focus_stage` | output | untestable | 900/0@t0 | 255 | 900 | direct | LNX | direct run: tick unpinned |
| `avm2/focusrect` | output.01a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.01b | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.02a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.02b | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.03a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.03b | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.04a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.04b | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.05a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.05b | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.06a | untestable | — | — | — | — | LNX | input.json; no capture |
| `avm2/focusrect` | output.06b | untestable | 2100/0@t0 | 255 | 700 | direct | LNX | input.json; direct run: tick unpinned |
| `avm2/focusrect_focuslost` | output | untestable | 800/0@t0 | 255 | 400 | direct | LNX | input.json; direct run: tick unpinned |
| `avm2/geom_transform` | output | Flash (in tol) | 0/4000@t10 | 1 | 156 | draw | LNX | 1 renderer/core re-bake(s), e.g. 45be8d5365 "avm2: Implement DisplayObject z getter/setter" |
| `avm2/graphics_bad_direct_commands` | output | not Flash | 588/0@t1 | 255 | 196 | draw | LNX | 1 renderer/core re-bake(s), e.g. 3156bf31ce "avm2: Throw correct errors in Graphics.[drawPath,d" |
| `avm2/graphics_bitmap_fill` | output | Flash (exact) | 0/60@t5 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. e713ab736e "avm2: Use proper scale for GraphicsBitmapFill and " |
| `avm2/graphics_bitmaps` | output | Flash (exact) | 0/4000@t8, 0/800@t16, 0/600@t32 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 70cdf1686d "avm2: Implement Graphics.lineBitmapStyle and Graph" |
| `avm2/graphics_direct_commands` | output | Flash (exact) | 0/6000@t0, 0/4000@t16, 0/1800@t32, 0/300@t64 | 0 | 0 | draw | LNX | 4 renderer/core re-bake(s), e.g. f7cbe3b7cd "avm2: Implement Graphics.copyFrom" |
| `avm2/graphics_draw_path` | output | not Flash | 56/0@t0 | 255 | 28 | draw | LNX | upstream known_failure (.ruffle.png); 1 renderer/core re-bake(s), e.g. aab4f7122b "avm2: Support non-zero winding rule when drawing p"; **on our failing board** |
| `avm2/graphics_draw_triangles` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `avm2/graphics_gradients` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); 1 renderer/core re-bake(s), e.g. 78f9bb13d6 "render: Fix PixelRegion::for_region_i32 for negati"; **on our failing board** |
| `avm2/graphics_gradients_nulls` | output | Flash (exact) | 0/0@t5 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. d9faefb737 "avm2: Allow null ratios is Graphics gradient APIs" |
| `avm2/graphics_simple_shapes` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `avm2/loader_events` | output | not Flash | 600/0@t0 | 192 | 300 | direct | LNX | 1 renderer/core re-bake(s), e.g. 86e6983943 "avm2: Partially implement Loader.load" |
| `avm2/loader_image` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX | 1 renderer/core re-bake(s), e.g. ad77cb0209 "core: Refactor Loader to properly load images" |
| `avm2/loader_jpegxr` | output | not Flash | 136033/0@t1 | 204 | 45424 | draw | LNX | 1 renderer/core re-bake(s), e.g. 6fe1731010 "core/render: Add support for loading JPEGXR images" |
| `avm2/loader_jpegxr_alpha` | output | not Flash | 11574/1500@t48 | 204 | 7478 | draw | LNX | 1 renderer/core re-bake(s), e.g. 6fe1731010 "core/render: Add support for loading JPEGXR images" |
| `avm2/loader_loadbytes_events` | output | not Flash | 600/0@t0 | 192 | 300 | direct | LNX | 1 renderer/core re-bake(s), e.g. ba88b52167 "avm2: Correctly apply 'skip_next_enter_frame' to L" |
| `avm2/mask_reapply` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `avm2/mouse_pick_dobj_mask` | output | untestable | 177/0@t1 | 255 | 59 | draw | LNX | input.json; 1 renderer/core re-bake(s), e.g. 715abd8985 "avm2: Use invisible mask descendants for mouse pic" |
| `avm2/mouse_pick_non_interactive_bitmap_mask` | output | untestable | 625/0@t1 | 255 | 625 | direct | LNX | input.json; direct run: tick unpinned |
| `avm2/mouse_pick_non_interactive_dobj_mask` | output | untestable | 168/0@t1 | 255 | 56 | draw | LNX | input.json; 1 renderer/core re-bake(s), e.g. 60000d6930 "avm2: Skip mouse pick for all mask children" |
| `avm2/netstream_play_flv` | output | untestable | 229724/0@t1 | 255 | 76798 | draw | LNX | video |
| `avm2/netstream_seek_flv` | output | untestable | 40943/271@t30 | 255 | 18930 | draw | LNX | video |
| `avm2/pixelbender_dithering` | output | not Flash | 27045/19929@t1 | 255 | 22953 | draw | LNX | upstream: 5128d39430 "tests: Use a Flash Player reference for avm2/pixelbender_dit"; **mirror golden ≠ upstream master**; **on our failing board** |
| `avm2/pixelbender_effect_BlurredFocus` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 1 renderer/core re-bake(s), e.g. 9d3e96e3a4 "render: Implement more Pixelbender opcodes, and fi" |
| `avm2/pixelbender_effect_glassDisplace` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 1 renderer/core re-bake(s), e.g. 6e1f00edf2 "render: Implement more PixelBender features (#1180" |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` | output | Flash (in tol) | 380/380@t3 | 255 | 528 | draw | LNX | 1 renderer/core re-bake(s), e.g. 6e1f00edf2 "render: Implement more PixelBender features (#1180" |
| `avm2/pixelbender_effect_smudge` | output | Flash (in tol) | 0/0@t1 | 1 | 726 | draw | LNX | 1 renderer/core re-bake(s), e.g. 6e1f00edf2 "render: Implement more PixelBender features (#1180" |
| `avm2/pixelbender_effect_tintype` | output | Flash (in tol) | 0/0@t1 | 1 | 517 | draw | LNX | 1 renderer/core re-bake(s), e.g. 6e1f00edf2 "render: Implement more PixelBender features (#1180" |
| `avm2/pixelbender_effect_twirl` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 1 renderer/core re-bake(s), e.g. 9d3e96e3a4 "render: Implement more Pixelbender opcodes, and fi" |
| `avm2/pixelbender_images` | output | Flash (in tol) | 0/0@t1 | 1 | 92638 | draw | LNX | 1 renderer/core re-bake(s), e.g. 69fce3f7f8 "wpgu: Initial implementation of PixelBender shader" |
| `avm2/pixelbender_malformed_data` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `avm2/sprite_with_frames` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX | upstream known_failure (.ruffle.png); 3 renderer/core re-bake(s), e.g. 15af946cf1 "avm2: Stop after first frame when movieclip doesn'"; **on our failing board** |
| `avm2/stage3d_agal_cross_product` | output | untestable | 599874/10@t2 | 255 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 7289a8bd95 "naga-agal: Zero-extend input vectors for cross-pro" |
| `avm2/stage3d_bitmap` | output | untestable | 88791/24@t4 | 255 | 38930 | draw | LNX | default-font; stage3d; 4 renderer/core re-bake(s), e.g. de8448e00a "avm2: Implement Stage3D depth test, blend factors," |
| `avm2/stage3d_blend` | output | untestable | 1078042/37000@t3, 1039360/5200@t16 | 255 | 367341 | direct | LNX | stage3d; direct run: tick unpinned; 2 renderer/core re-bake(s), e.g. de8448e00a "avm2: Implement Stage3D depth test, blend factors," |
| `avm2/stage3d_float1_index` | output | untestable | 191998/0@t2 | 254 | 64000 | draw | LNX | stage3d |
| `avm2/stage3d_fractal` | output | untestable | 1101393/100@t2 | 255 | 385184 | draw | LNX | default-font; stage3d; upstream known_failure (.ruffle.png); 6 renderer/core re-bake(s), e.g. 8cb6e5bdf0 "wgpu: Implement drop shadow filter"; **on our failing board** |
| `avm2/stage3d_ignore_sampler_override` | output | untestable | 788484/1935@t8 | 255 | 300000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 837143bb12 "naga-agal: Fix handling of sampler overrides" |
| `avm2/stage3d_multistage_triangle` | output | untestable | 191416/0@t1 | 255 | 64000 | draw | LNX | stage3d; 1 renderer/core re-bake(s), e.g. 0b296b58e8 "avm2: Always create four Stage3D instances" |
| `avm2/stage3d_program_constants_bytearray_be` | output | Flash (in tol) | 3253/5000@t50 | 255 | 17845 | direct | LNX |  |
| `avm2/stage3d_program_constants_bytearray_le` | output | Flash (in tol) | 3253/5000@t50 | 255 | 17845 | direct | LNX |  |
| `avm2/stage3d_raytrace` | output | untestable | 657121/10@t8 | 245 | 219967 | draw | LNX | input.json; stage3d; 1 renderer/core re-bake(s), e.g. 2748b95c86 "avm2: Improve Stage3D support for textures, regist"; **on our failing board** |
| `avm2/stage3d_rotating_cube` | output | untestable | 3219/2160@t3, 2373/1250@t16, 1336/250@t32 | 159 | 1741 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. a52cb7461e "wgpu: Implement MSAA support for Stage3D" |
| `avm2/stage3d_sampler` | output | untestable | 577781/850@t1 | 255 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 962cf92223 "avm2: Implement Context3D.setSamplerStateAt" |
| `avm2/stage3d_sampler_partial_upload` | output | untestable | 597818/782@t1 | 255 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 820e7e828a "wgpu: Allow Stage3D texture upload where source is" |
| `avm2/stage3d_stencil` | output | untestable | 48000/0@t0 | 204 | 19200 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. e702fd60d6 "Add test for Context3D stencil actions" |
| `avm2/stage3d_texture` | output | untestable | 623338/117@t8 | 255 | 208211 | draw | LNX | default-font; input.json; stage3d; 8 renderer/core re-bake(s), e.g. 1e973af747 "avm2: Implement Context3D.setRenderToTexture/setRe" |
| `avm2/stage3d_texture_bytearray` | output | untestable | 590185/0@t4 | 236 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 2 renderer/core re-bake(s), e.g. ec7a8ac645 "avm2: Add support for Stage3D bytearray/compressed" |
| `avm2/stage3d_texture_bytearray_compressed_alpha` | output | untestable | 595420/66@t4 | 239 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 2 renderer/core re-bake(s), e.g. b5097445e6 "render: Add support for Context3DTextureFormat.COM" |
| `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | output | untestable | 595381/66@t4 | 239 | 200000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 7110be920c "Suport uploading ATFTextureData::CompressedRawAlph" |
| `avm2/stage3d_triangle` | output | untestable | 191267/0@t1 | 255 | 64000 | draw | LNX | stage3d; 1 renderer/core re-bake(s), e.g. a52cb7461e "wgpu: Implement MSAA support for Stage3D" |
| `avm2/stage3d_triangle_bytes4` | output | untestable | 191267/0@t1 | 255 | 64000 | draw | LNX | stage3d; 2 renderer/core re-bake(s), e.g. 1dd0d237ab "render: Correctly handle BYTES_4 vertex data" |
| `avm2/stage3d_triangle_float1` | output | untestable | 144420/0@t1 | 255 | 64000 | draw | LNX | stage3d; 1 renderer/core re-bake(s), e.g. 7619594b1c "agal: Implement Float1 to vec4f conversion" |
| `avm2/stage3d_triangle_index_upload` | output | untestable | 191267/0@t1 | 255 | 64000 | draw | LNX | stage3d; 1 renderer/core re-bake(s), e.g. e488cc9f7a "wgpu: Allow unaligned writes to IndexBuffer3D" |
| `avm2/stage_scale_factor` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 1 renderer/core re-bake(s), e.g. 66aad3ebc5 "core: Use a separate matrix for stage alignment an" |
| `avm2/symbol_class_conflict` | output | not Flash | 5293/0@t0 | 255 | 2103 | draw | LNX | 1 renderer/core re-bake(s), e.g. da6384b30e "Warn instead of panicking" |
| `fonts/device_font_kerning` | output | untestable | 2556/0@t0 | 255 | 852 | direct | LNX | direct run: tick unpinned |
| `fonts/device_font_no_ink` | output | untestable | 4908/0@t0 | 255 | 1636 | direct | LNX | direct run: tick unpinned |
| `fonts/embed_matching/fallback_preferences` | output | untestable | 475680/6@t3 | 255 | 158560 | direct | LNX | direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 64385efe48 "core: Use correct embedded font fallback order + t" |
| `fonts/embed_matching/match_style` | output | untestable | 9138/0@t3 | 240 | 3046 | direct | LNX | direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 64385efe48 "core: Use correct embedded font fallback order + t" |
| `fonts/embed_matching/no_font_found` | output | Flash (exact) | 0/0@t0 | 0 | 0 | direct | LNX | upstream known_failure (.ruffle.png); 1 renderer/core re-bake(s), e.g. 64385efe48 "core: Use correct embedded font fallback order + t" |
| `from_gnash/misc-ming.all/BeginBitmapFill` | output | Flash (in tol) | 24/100@t50 | 255 | 8 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_gnash/misc-ming.all/GradientFillTest` | output | Flash (in tol) | 37/1070@t34 | 255 | 44404 | draw | LNX |  |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | output | untestable | 84/0@t5 | 63 | 28 | draw | LNX | video; upstream known_failure (.ruffle.png); **on our failing board** |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame1 | not Flash | 242/0@t1 | 255 | 121 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame2 | not Flash | 482/0@t1 | 255 | 241 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame3 | not Flash | 722/0@t1 | 255 | 361 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame4 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame5 | not Flash | 242/0@t1 | 255 | 121 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame6 | not Flash | 482/0@t1 | 255 | 241 | draw | LNX |  |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | frame7 | not Flash | 722/0@t1 | 255 | 361 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame1 | not Flash | 393/0@t5 | 255 | 201 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame2 | not Flash | 1563/0@t5 | 255 | 521 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame3 | not Flash | 1563/0@t5 | 255 | 521 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame4 | not Flash | 1563/0@t5 | 255 | 10521 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame5 | not Flash | 1563/0@t5 | 255 | 10521 | draw | LNX |  |
| `from_gnash/misc-ming.all/morph_test1` | frame6 | not Flash | 760/0@t5 | 255 | 320 | draw | LNX |  |
| `from_gnash/misc-ming.all/place_object_test` | output | not Flash | 15627/0@t50 | 255 | 5209 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_gnash/misc-ming.all/shape_test` | output | not Flash | 3213/0@t50 | 255 | 1071 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_gnash/misc-swfmill.all/background` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_gnash/misc-swfmill.all/missing_bitmap` | output | not Flash | 80000/0@t0 | 255 | 40000 | draw | LNX |  |
| `from_shumway/3_joystick` | output | Flash (in tol) | 0/0@t128, 0/2500@t32 | 15 | 2755 | direct | LNX | upstream: c359e01cc4 "tests: Use Flash Player's output for from_shumway/3_joystick" |
| `from_shumway/MaskTest` | output | not Flash | 187/0@t0 | 255 | 187 | draw | LNX |  |
| `from_shumway/MaskTest-2` | output | not Flash | 8377/0@t3 | 253 | 3643 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/MaskTest-3` | output | Flash (exact) | 0/0@t3 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid` | output.01 | not Flash | 544/9100@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.02 | not Flash | 544/12500@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.03 | not Flash | 544/11000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.04 | not Flash | 544/12100@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.05 | not Flash | 544/11000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.06 | not Flash | 544/12500@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.07 | not Flash | 544/11000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.08 | not Flash | 544/11000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.09 | not Flash | 544/12500@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.10 | not Flash | 544/11000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.11 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.12 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.13 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.14 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.15 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.16 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.17 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid` | output.18 | not Flash | 544/13000@t0, 430/360@t128 | 204 | 272 | draw | LNX |  |
| `from_shumway/acid/acid-big` | output | Flash (in tol) | 0/20@t50 | 49 | 244608 | draw | LNX |  |
| `from_shumway/acid/acid-bitmap-draw_quality_high` | output | Flash (exact) | 0/35000@t5, 0/700@t32, 0/0@t64 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-bitmap-draw_quality_low` | output | not Flash | 66861/35000@t5, 15095/700@t32, 2192/0@t64 | 149 | 30511 | draw | LNX | upstream known_failure (.ruffle.png) |
| `from_shumway/acid/acid-bitmap-fill` | output | Flash (in tol) | 49166/70000@t12, 12520/20000@t32, 3637/6000@t64, 30/300@t128 | 154 | 160525 | draw | LNX |  |
| `from_shumway/acid/acid-bitmap-fill-2` | output | Flash (exact) | 0/9000@t3, 0/0@t32 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-bitmapData-copyPixels` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-bitmapData-draw` | output | Flash (exact) | 0/650@t0, 0/250@t32, 0/50@t64, 0/0@t128 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-bitmaps` | frame5 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-bitmaps` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-blend` | output | not Flash | 10161/348@t11 | 255 | 219750 | draw | LNX |  |
| `from_shumway/acid/acid-blend-2` | output.10 | Flash (exact) | 0/5000@t20, 0/0@t130 | 0 | 0 | draw | LNX | upstream: e8f083df1d "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-blend-2` | output.15 | Flash (exact) | 0/6000@t20, 0/0@t135 | 0 | 0 | draw | LNX | upstream: e8f083df1d "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-blend-2` | output.20 | Flash (exact) | 0/5500@t20, 0/0@t130 | 0 | 0 | draw | LNX | upstream: e8f083df1d "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-blend-2` | output.26 | Flash (exact) | 0/6000@t20, 0/0@t120 | 0 | 0 | draw | LNX | upstream: e8f083df1d "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-blend-2` | output.40 | Flash (exact) | 0/9000@t20, 0/1500@t40, 0/0@t160 | 0 | 0 | draw | LNX | upstream: e8f083df1d "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-chars` | output | not Flash | 3024/0@t0 | 255 | 1008 | draw | LNX |  |
| `from_shumway/acid/acid-child` | frame5 | not Flash | 522/0@t0 | 255 | 174 | draw | LNX |  |
| `from_shumway/acid/acid-child` | output | not Flash | 774/0@t0 | 255 | 258 | draw | LNX |  |
| `from_shumway/acid/acid-clip` | output | Flash (exact) | 0/0@t150, 0/140@t64, 0/7000@t0 | 0 | 0 | draw | LNX | upstream: 58b0c617b7 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-clip-2` | output | Flash (exact) | 0/3000@t0, 0/1300@t32, 0/300@t64, 0/0@t110 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-clip-3` | frame3 | not Flash | 552/0@t0 | 255 | 276 | draw | LNX |  |
| `from_shumway/acid/acid-clip-3` | output | not Flash | 376/0@t0 | 255 | 188 | draw | LNX |  |
| `from_shumway/acid/acid-color` | frame1 | near Flash | 2/0@t3 | 4 | 86790 | draw | LNX |  |
| `from_shumway/acid/acid-color` | output | near Flash | 675/0@t3 | 6 | 153065 | draw | LNX |  |
| `from_shumway/acid/acid-color-0` | output | not Flash | 26477/3@t3 | 255 | 155867 | draw | LNX | **on our failing board** |
| `from_shumway/acid/acid-color-2` | output | Flash (exact) | 0/6400@t0, 0/1500@t32, 0/100@t52, 0/0@t80 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-filter` | output | not Flash | 536/0@t4 | 255 | 17763 | draw | LNX |  |
| `from_shumway/acid/acid-filter-2` | output | Flash (exact) | 0/2500@t5, 0/0@t20 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-gc` | output | not Flash | 3792/0@t0 | 255 | 1264 | draw | LNX |  |
| `from_shumway/acid/acid-gradient` | output | not Flash | 75465/0@t1 | 172 | 34771 | draw | LNX |  |
| `from_shumway/acid/acid-gradient-0` | output | near Flash | 69205/0@t1 | 11 | 57927 | draw | LNX |  |
| `from_shumway/acid/acid-gradient-1` | output | not Flash | 384/0@t1 | 255 | 47232 | draw | LNX |  |
| `from_shumway/acid/acid-gradient-2` | output | not Flash | 3002/0@t1 | 255 | 2839 | draw | LNX |  |
| `from_shumway/acid/acid-image` | output | not Flash | 540/0@t11 | 149 | 407 | draw | LNX |  |
| `from_shumway/acid/acid-large` | output | not Flash | 178720/0@t11 | 115 | 219376 | draw | LNX |  |
| `from_shumway/acid/acid-mask` | output.01 | Flash (exact) | 0/20@t4 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); upstream: 79ff73ff7f "tests: Use Flash Player's output for from_shumway/acid/acid-"; **on our failing board** |
| `from_shumway/acid/acid-mask` | output.05 | Flash (exact) | 0/20@t4 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); upstream: 79ff73ff7f "tests: Use Flash Player's output for from_shumway/acid/acid-"; **on our failing board** |
| `from_shumway/acid/acid-mask` | output.10 | Flash (exact) | 0/20@t4 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); upstream: 79ff73ff7f "tests: Use Flash Player's output for from_shumway/acid/acid-"; **on our failing board** |
| `from_shumway/acid/acid-morph` | output | Flash (exact) | 0/5600@t10, 0/2600@t64 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-scale` | output | not Flash | 11240/0@t0 | 255 | 5620 | draw | LNX |  |
| `from_shumway/acid/acid-shapes` | output | Flash (exact) | 0/113000@t3, 0/61300@t16, 0/25600@t32, 0/5600@t64, 0/180@t128, 0/0@t200 | 0 | 0 | draw | LNX | **on our failing board** |
| `from_shumway/acid/acid-shapes-testing` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/acid/acid-small` | output.01 | Flash (exact) | 0/30000@t0, 0/20000@t20, 0/3000@t80 | 0 | 0 | draw | LNX | upstream: e6eaa45490 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-small` | output.05 | Flash (exact) | 0/30000@t0, 0/21000@t20, 0/3000@t80 | 0 | 0 | draw | LNX | upstream: e6eaa45490 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-stroke-0` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/acid/acid-text` | output | not Flash | 18522/0@t0 | 255 | 6174 | draw | LNX |  |
| `from_shumway/acid/acid-text-2` | output | Flash (exact) | 0/0@t128 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-text-3` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-text-4` | output | near Flash | 6/0@t0 | 1 | 2 | screen | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/acid/acid-text-5` | output | not Flash | 162135/6@t0 | 255 | 54045 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/acid/acid-text-6` | frame5 | not Flash | 327/0@t0 | 255 | 109 | draw | LNX |  |
| `from_shumway/acid/acid-text-6` | output | not Flash | 13110/0@t0 | 255 | 4370 | draw | LNX |  |
| `from_shumway/acid/acid-text-escape` | output | not Flash | 13844/0@t0 | 255 | 6922 | draw | LNX |  |
| `from_shumway/acid/acid-text-x` | output | not Flash | 21534/0@t0 | 255 | 7178 | draw | LNX |  |
| `from_shumway/acid/acid-textfield` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/acid/acid-textfield-scroll` | output | Flash (exact) | 0/600@t128 | 0 | 0 | draw | LNX |  |
| `from_shumway/acid/acid-video` | output.01 | Flash (exact) | 0/20000@t5, 0/300@t50 | 0 | 0 | draw | LNX | upstream: 5b2d8b4921 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-video` | output.10 | Flash (exact) | 0/18000@t5, 0/300@t50 | 0 | 0 | draw | LNX | upstream: 5b2d8b4921 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/acid/acid-video` | output.20 | Flash (exact) | 0/15000@t5, 0/130@t50 | 0 | 0 | draw | LNX | upstream: 5b2d8b4921 "tests: Use Flash Player's output for from_shumway/acid/acid-" |
| `from_shumway/avm1/text-bind` | output | not Flash | 2085/100@t128, 2417/600@t64 | 158 | 3096 | draw | LNX |  |
| `from_shumway/avm2/flash/display/bitmapdata/bitmapdata-clone` | output | not Flash | 18693/0@t3 | 77 | 23380 | draw | LNX | upstream: 7facc1fccb "tests: Use a Flash Player reference for bitmapdata-clone"; **mirror golden ≠ upstream master** |
| `from_shumway/bitmapbuttons` | output | Flash (in tol) | 0/0@t4 | 1 | 13 | draw | LNX | **on our failing board** |
| `from_shumway/button1` | output.1 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/button1` | output.2 | untestable | 145920/0@t0 | 204 | 48640 | draw | LNX | input.json |
| `from_shumway/button1` | output.3 | untestable | 145920/0@t0 | 255 | 48640 | draw | LNX | input.json |
| `from_shumway/button1` | output.4 | untestable | 145920/0@t0 | 204 | 48640 | draw | LNX | input.json |
| `from_shumway/button2` | output.1 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/button2` | output.2 | untestable | 95634/0@t0 | 255 | 47817 | draw | LNX | input.json |
| `from_shumway/button2` | output.3 | untestable | 95634/0@t0 | 255 | 47817 | draw | LNX | input.json |
| `from_shumway/button2` | output.4 | untestable | 95634/0@t0 | 255 | 47817 | draw | LNX | input.json |
| `from_shumway/button3` | output.1 | Flash (in tol) | 3/3500@t0 | 255 | 1 | draw | LNX |  |
| `from_shumway/button3` | output.2 | untestable | 160265/3500@t0 | 255 | 80132 | draw | LNX | input.json |
| `from_shumway/button3` | output.3 | untestable | 160265/3500@t0 | 255 | 80132 | draw | LNX | input.json |
| `from_shumway/button3` | output.4 | untestable | 160265/3500@t0 | 255 | 80132 | draw | LNX | input.json |
| `from_shumway/captions` | output | not Flash | 6834/0@t3 | 255 | 2479 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/clipping` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/doubleAndRegister` | output | not Flash | 772/0@t0 | 255 | 386 | draw | LNX |  |
| `from_shumway/flash_geom_ColorTransform` | output | Flash (in tol) | 0/0@t1 | 1 | 1200 | draw | LNX |  |
| `from_shumway/flash_text_TextField` | output | untestable | 639/0@t3 | 15 | 310 | direct | LNX | direct run: tick unpinned; upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/flash_text_TextField2` | output | Flash (exact) | 0/10@t200, 0/250@t128 | 0 | 0 | draw | LNX |  |
| `from_shumway/gradient` | output | near Flash | 15897/0@t3 | 9 | 70122 | draw | LNX |  |
| `from_shumway/gradientTransform` | output | near Flash | 9/0@t3 | 15 | 3 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/hardwrap` | output | not Flash | 3891/0@t3 | 255 | 1337 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/invalidClipDepth` | output | near Flash | 1800/0@t0 | 1 | 1800 | draw | LNX |  |
| `from_shumway/stylesheet` | output | not Flash | 3345/0@t5 | 255 | 1603 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `from_shumway/timeline/Timeline3` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/Timeline4` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.01 | Flash (exact) | 0/0@t40 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.02 | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.03 | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.04 | Flash (exact) | 0/0@t40 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.05 | Flash (exact) | 0/0@t40 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.06 | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_as2_5` | output.07 | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.02 | Flash (exact) | 0/70@t32 | 0 | 0 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.06 | not Flash | 69156/90@t32 | 157 | 23446 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.07 | not Flash | 68464/70@t32 | 157 | 23121 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.11 | not Flash | 68464/90@t32 | 157 | 23121 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.12 | not Flash | 68464/70@t32 | 157 | 23121 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.15 | not Flash | 37758/90@t32 | 157 | 12982 | draw | LNX |  |
| `from_shumway/timeline/timeline_loop` | output.16 | not Flash | 69156/90@t32 | 157 | 23446 | draw | LNX |  |
| `import_assets/avm1_imports_avm1` | output | Flash (exact) | 0/500@t100 | 0 | 0 | direct | LNX | 1 renderer/core re-bake(s), e.g. 3173fcc945 "core: Pause preloading until an ImportAssets is fi" |
| `stage3d/sampler_odd_size` | output | untestable | 592737/782@t1 | 255 | 200000 | direct | LNX | stage3d; direct run: tick unpinned |
| `stage3d/scissor_rectangle` | output | untestable | 657946/0@t1 | 255 | 220000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 999e2f5b71 "wgpu: Implement Context3D.setScissorRectangle" |
| `stage3d/scissor_rectangle_invalid` | output | untestable | 657072/0@t1 | 255 | 220000 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. cd9efb2dfa "wgpu: Ignore zero width/height Stage3D scissor rec" |
| `stage3d/unbound_texture` | output | Flash (exact) | 0/0@t1 | 0 | 0 | direct | LNX | 1 renderer/core re-bake(s), e.g. 1636c78067 "render: Fix panic when calling `Context3D.drawTria" |
| `stage3d/unbound_texture_multiple` | output | untestable | 50364/0@t1 | 255 | 16788 | direct | LNX | stage3d; direct run: tick unpinned; 1 renderer/core re-bake(s), e.g. 1636c78067 "render: Fix panic when calling `Context3D.drawTria" |
| `text/auto_size/height` | output | not Flash | 7797/3@t0 | 255 | 2599 | draw | LNX | 1 renderer/core re-bake(s), e.g. 59c0bcf073 "core: Improve EditText's border and background ren" |
| `text/auto_size/return` | output | not Flash | 8043/18@t0 | 255 | 2681 | draw | LNX | 3 renderer/core re-bake(s), e.g. 59c0bcf073 "core: Improve EditText's border and background ren" |
| `text/auto_size/width` | output | not Flash | 15642/18@t0 | 255 | 5214 | draw | LNX | 1 renderer/core re-bake(s), e.g. 59c0bcf073 "core: Improve EditText's border and background ren" |
| `text/br_at_start` | output | Flash (in tol) | 0/8@t128 | 32 | 99 | draw | LNX | 3 renderer/core re-bake(s), e.g. 6061186c0f "core: Fix formatting texts when they start with an" |
| `text/style_changes_in_html` | output | not Flash | 24446/0@t0 | 103 | 12223 | draw | LNX | 1 renderer/core re-bake(s), e.g. feacbdc118 "core: <font> tag in text should reset the style to" |
| `visual/avm2_button_scroll_rect` | output | not Flash | 54/0@t0 | 255 | 18 | draw | LNX | 1 renderer/core re-bake(s), e.g. 5e1a30cf4a "core: Fix avm2 button bounding box when using scro" |
| `visual/bitmapdata_copypixels_with_alpha_oob` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/blend_across_masks_issue_24549` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/blend_modes/add` | output | not Flash | 5465/0@t2 | 255 | 9613 | draw | LNX |  |
| `visual/blend_modes/alpha_no_layer` | output | not Flash | 12301/0@t2 | 255 | 17585 | screen | LNX | 1 renderer/core re-bake(s), e.g. 078672782c "wgpu: Skip Alpha/Erase blends with no parent Layer" |
| `visual/blend_modes/darken` | output | not Flash | 8513/0@t2 | 255 | 8899 | draw | LNX |  |
| `visual/blend_modes/difference` | output | not Flash | 7535/0@t2 | 255 | 11571 | draw | LNX |  |
| `visual/blend_modes/erase_no_layer` | output | not Flash | 11990/0@t3 | 255 | 17585 | screen | LNX | 1 renderer/core re-bake(s), e.g. 078672782c "wgpu: Skip Alpha/Erase blends with no parent Layer" |
| `visual/blend_modes/hardlight` | output | not Flash | 11610/0@t4 | 255 | 51617 | draw | LNX |  |
| `visual/blend_modes/invert` | output | not Flash | 12800/0@t2 | 255 | 11128 | draw | LNX |  |
| `visual/blend_modes/layer_alpha` | output | not Flash | 13763/0@t2 | 255 | 32682 | screen | LNX | 1 renderer/core re-bake(s), e.g. 622abe60d1 "wgpu: Extract T->Color lookup from gradient shader" |
| `visual/blend_modes/layer_erase` | output | not Flash | 11579/0@t3 | 255 | 32775 | screen | LNX |  |
| `visual/blend_modes/lighten` | output | not Flash | 5980/0@t2 | 255 | 9230 | draw | LNX |  |
| `visual/blend_modes/masked_layer_cached_children` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `visual/blend_modes/multiply` | output | not Flash | 8659/0@t2 | 255 | 11183 | draw | LNX |  |
| `visual/blend_modes/overlay` | output | not Flash | 10463/0@t2 | 251 | 45812 | draw | LNX |  |
| `visual/blend_modes/overlay_onto_stage` | output | Flash (in tol) | 12407/40000@t0, 0/1300@t16, 0/60@t32, 0/0@t64 | 1 | 12407 | draw | LNX |  |
| `visual/blend_modes/screen` | output | not Flash | 5839/0@t2 | 255 | 11248 | draw | LNX |  |
| `visual/blend_modes/shader_as_mask` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `visual/blend_modes/shader_without_shader` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/blend_modes/subtract` | output | not Flash | 5797/0@t2 | 255 | 9611 | draw | LNX |  |
| `visual/bmd_draw_with_msaa_issue_10579` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 4f4327b152 "wgpu: Fix drawing a transparent bitmap with MSAA" |
| `visual/cache_as_bitmap/avm1_color` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | upstream known_failure (.ruffle.png); upstream: 045db00b39 "tests: Correct avm1_color reference against Flash Player 32"; **on our failing board** |
| `visual/cache_as_bitmap/avm2_button` | output | not Flash | 826/0@t1 | 255 | 413 | draw | LNX | 1 renderer/core re-bake(s), e.g. f55147d7c3 "core: Override render_bounds_with_transform in Avm" |
| `visual/cache_as_bitmap/avm2_button_state` | output | Flash (exact) | 0/900@t2 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/bitmap_changed` | applyfilter | untestable | — | — | — | — | LNX | trigger=fs_command; 1 renderer/core re-bake(s), e.g. d35b2b8b84 "core: Inform Bitmaps to invalidate, if their backi" |
| `visual/cache_as_bitmap/bitmap_changed` | fillrect | untestable | — | — | — | — | LNX | trigger=fs_command; 1 renderer/core re-bake(s), e.g. d35b2b8b84 "core: Inform Bitmaps to invalidate, if their backi" |
| `visual/cache_as_bitmap/bitmap_changed` | initial | untestable | — | — | — | — | LNX | trigger=fs_command; 1 renderer/core re-bake(s), e.g. d35b2b8b84 "core: Inform Bitmaps to invalidate, if their backi" |
| `visual/cache_as_bitmap/cab_bitmapdata_invalidate` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/cab_mask_alpha` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/cab_mask_filters` | output | Flash (exact) | 0/0@t4 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/cab_mask_transform` | output | Flash (exact) | 0/0@t4 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/cab_mask_triangle` | output | Flash (in tol) | 60/200@t0, 0/0@t35 | 1 | 24 | draw | LNX |  |
| `visual/cache_as_bitmap/children_changed` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. c39217e139 "core: Invalidate cacheAsBitmap when children are a" |
| `visual/cache_as_bitmap/color_transform` | output | near Flash | 364500/0@t0 | 1 | 182250 | draw | LNX |  |
| `visual/cache_as_bitmap/contains_grown_filter` | output | Flash (in tol) | 0/0@t5 | 1 | 194 | draw | LNX |  |
| `visual/cache_as_bitmap/drawing_api` | output | not Flash | 1798/0@t1 | 255 | 600 | draw | LNX | 2 renderer/core re-bake(s), e.g. d49a8ce0e6 "core: Invalidate cacheAsBitmap when drawing api is" |
| `visual/cache_as_bitmap/edittext_hscroll` | output.01 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/edittext_hscroll` | output.02 | untestable | 1056/0@t0 | 255 | 352 | draw | LNX | input.json; 1 renderer/core re-bake(s), e.g. 6429cc8865 "text: Take the gutter into account when masking te" |
| `visual/cache_as_bitmap/edittext_scroll` | output.01 | untestable | 1264/5@t0 | 255 | 423 | draw | LNX | default-font; input.json |
| `visual/cache_as_bitmap/edittext_scroll` | output.02 | untestable | 1258/5@t0 | 255 | 421 | draw | LNX | default-font; input.json |
| `visual/cache_as_bitmap/edittext_selection` | output.01 | Flash (exact) | 0/8@t0 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/edittext_selection` | output.02 | Flash (exact) | 0/8@t0 | 0 | 0 | draw | LNX |  |
| `visual/cache_as_bitmap/edittext_selection` | output.03 | untestable | 6560/8@t0 | 255 | 2213 | draw | LNX | input.json; 1 renderer/core re-bake(s), e.g. 5aaff966aa "text: Render caret using lines" |
| `visual/cache_as_bitmap/masks` | output.01 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.02 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.03 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.04 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.05 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.06 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/masks` | output.07 | Flash (in tol) | 0/3200@t10, 0/350@t64, 0/0@t128 | 1 | 1038 | draw | LNX | upstream: a31c286451 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/morph` | output | near Flash | 2832/0@t0 | 1 | 2832 | draw | LNX | 1 renderer/core re-bake(s), e.g. 932291bbad "core: Invalidate cacheAsBitmap when morphs change" |
| `visual/cache_as_bitmap/nested_color_transform` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 27db3e70b4 "core: Invalidate cacheAsBitmap when transform chan" |
| `visual/cache_as_bitmap/nested_matrix` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 27db3e70b4 "core: Invalidate cacheAsBitmap when transform chan" |
| `visual/cache_as_bitmap/nested_rotation` | output | not Flash | 387/0@t0 | 204 | 129 | draw | LNX | 1 renderer/core re-bake(s), e.g. cc8edb3bf1 "core: Invalidate cacheAsBitmap when various more p" |
| `visual/cache_as_bitmap/oversize/swf_10_masks` | output | Flash (exact) | 0/200@t64, 0/0@t128 | 0 | 0 | direct | LNX |  |
| `visual/cache_as_bitmap/oversize/swf_10_too_big` | output | Flash (exact) | 0/0@t1 | 0 | 0 | direct | LNX | upstream known_failure (.ruffle.png) |
| `visual/cache_as_bitmap/oversize/swf_9_masks` | output | untestable | 33556/200@t64, 48/0@t128 | 129 | 34223 | direct | LNX | direct run: tick unpinned |
| `visual/cache_as_bitmap/oversize/swf_9_too_big` | output | Flash (exact) | 0/0@t1 | 0 | 0 | direct | LNX | upstream known_failure (.ruffle.png) |
| `visual/cache_as_bitmap/scroll_rect` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX | 2 renderer/core re-bake(s), e.g. 9795fc9311 "core: Invalidate ancestors on scrollRect changes" |
| `visual/cache_as_bitmap/scroll_rect_scaled` | output | Flash (exact) | 0/2800@t0, 0/900@t64 | 0 | 0 | draw | LNX | upstream: 17eb82b273 "tests: Use Flash Player's output for visual/cache_as_bitmap/" |
| `visual/cache_as_bitmap/shape_changed` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 8a3ccdd080 "core: Invalidate cacheAsBitmap when graphics chang" |
| `visual/cache_as_bitmap/text` | output | not Flash | 14862/12000@t0, 9234/1500@t128 | 254 | 4954 | draw | LNX | 3 renderer/core re-bake(s), e.g. 41991da624 "core: Invalidate cacheAsBitmap when texts change" |
| `visual/color_transform_issue_9698` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. edd7f80341 "wgpu: Fix blown out colors when transforming them " |
| `visual/define_bits_lossless2_rgb15` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `visual/definefont4` | output | not Flash | 18993/0@t1 | 255 | 6331 | draw | LNX | 2 renderer/core re-bake(s), e.g. f8577a843d "core: Use non-zero winding rule for fonts"; **on our failing board** |
| `visual/drawing_api/cursor` | output | not Flash | 798/0@t0 | 255 | 399 | draw | LNX |  |
| `visual/drawing_api/drawing_order` | output | not Flash | 11831/0@t0 | 255 | 5933 | draw | LNX |  |
| `visual/drawing_api/fills_and_lines` | output | not Flash | 36154/0@t2 | 255 | 50119 | screen | LNX | 2 renderer/core re-bake(s), e.g. 7b1c101c81 "wgpu: Fix repeat & reflect gradients" |
| `visual/drawing_api/gradient_focal_point` | output | not Flash | 28805/0@t13 | 232 | 71812 | draw | LNX |  |
| `visual/edittext/edittext_background_basic` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/edittext/edittext_background_basic_scale2` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `visual/edittext/edittext_border_basic` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/edittext/edittext_border_basic_scale2` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `visual/edittext/edittext_border_filters` | output | Flash (in tol) | 0/17@t32 | 16 | 16 | draw | LNX |  |
| `visual/edittext/edittext_border_transform` | output.01 | untestable | 141/0@t0 | 255 | 141 | draw | LNX | input.json |
| `visual/edittext/edittext_border_transform` | output.02 | untestable | 864/0@t0 | 255 | 432 | draw | LNX | input.json |
| `visual/edittext/edittext_border_transform` | output.03 | untestable | 867/0@t0 | 255 | 504 | draw | LNX | input.json |
| `visual/edittext/edittext_border_transform` | output.04 | untestable | 512/20@t128 | 255 | 642 | draw | LNX | input.json |
| `visual/edittext/edittext_border_transform` | output.05 | untestable | 3168/20@t128 | 255 | 1626 | draw | LNX | input.json |
| `visual/edittext/edittext_border_transform` | output.06 | untestable | 3183/20@t128 | 255 | 1923 | draw | LNX | input.json |
| `visual/edittext/edittext_bounds_vs_position` | output | Flash (exact) | 0/0@t0, 0/140@t0 | 0 | 0 | draw | LNX |  |
| `visual/edittext/edittext_caret_empty` | output.01 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.02 | untestable | 36/0@t64 | 255 | 25 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.03 | untestable | 21/3@t64, 18/0@t192 | 255 | 19 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.04 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.05 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.06 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.07 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.08 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.09 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.10 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.11 | untestable | 48/0@t64 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_empty` | output.12 | untestable | 48/0@t65 | 255 | 29 | draw | LNX | input.json |
| `visual/edittext/edittext_caret_multiline` | output.01 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_caret_multiline` | output.02 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_caret_multiline` | output.03 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_caret_multiline` | output.04 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_caret_multiline` | output.05 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_caret_multiline` | output.06 | untestable | 948/0@t64 | 255 | 316 | direct | LNX | input.json; direct run: tick unpinned |
| `visual/edittext/edittext_device_transform_negative` | output | untestable | 3072/160@t0, 2442/30@t128 | 255 | 1024 | direct | LNX | direct run: tick unpinned |
| `visual/edittext/edittext_device_transform_small_rotation` | output | Flash (in tol) | 11/11@t0 | 255 | 11 | draw | LNX |  |
| `visual/edittext/edittext_device_transform_small_shear` | output | Flash (in tol) | 49/50@t0 | 255 | 49 | draw | LNX |  |
| `visual/edittext/edittext_gutter` | output | untestable | 9684/0@t128 | 255 | 3276 | direct | LNX | direct run: tick unpinned |
| `visual/edittext/edittext_justify` | output | Flash (exact) | 0/0@t128 | 0 | 0 | direct | LNX |  |
| `visual/edittext/edittext_negative_bounds` | output | Flash (exact) | 0/0@t128 | 0 | 0 | draw | LNX |  |
| `visual/edittext/edittext_selection_font_size` | output | untestable | 8113/0@t128 | 255 | 4516 | direct | LNX | direct run: tick unpinned |
| `visual/edittext/edittext_selection_leading` | output.01 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.02 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.03 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.04 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.05 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.06 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.07 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.08 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.09 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.10 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.11 | untestable | — | — | — | — | LNX | input.json; no capture |
| `visual/edittext/edittext_selection_leading` | output.12 | untestable | 21267/0@t128 | 255 | 17019 | direct | LNX | input.json; direct run: tick unpinned |
| `visual/edittext/edittext_underline` | output | Flash (in tol) | 12/16@t0, 0/0@t144 | 111 | 4 | draw | LNX |  |
| `visual/edittext/edittext_underline_scale2` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `visual/filters/any_blur_scales_with_screen` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `visual/filters/bevel` | output | untestable | 116897/6@t3 | 254 | 118027 | draw | LNX | default-font; 3 renderer/core re-bake(s), e.g. b1ba144166 "wgpu: Implement Bevel filter" |
| `visual/filters/bevel_full` | output | untestable | 110141/18@t4 | 254 | 248885 | draw | LNX | default-font; 3 renderer/core re-bake(s), e.g. b1ba144166 "wgpu: Implement Bevel filter" |
| `visual/filters/bevel_inner` | output | untestable | 73381/18@t4 | 254 | 91999 | draw | LNX | default-font; 3 renderer/core re-bake(s), e.g. b1ba144166 "wgpu: Implement Bevel filter" |
| `visual/filters/bevel_outer` | output | untestable | 126477/18@t3 | 255 | 217788 | draw | LNX | default-font; 3 renderer/core re-bake(s), e.g. b1ba144166 "wgpu: Implement Bevel filter" |
| `visual/filters/blur_fractional` | output | Flash (exact) | 0/0@t5 | 0 | 0 | draw | LNX |  |
| `visual/filters/blur_pass_scaling` | output | Flash (in tol) | 0/0@t3 | 2 | 24380 | draw | LNX |  |
| `visual/filters/blur_quality` | output | near Flash | 205332/0@t6 | 9 | 342229 | draw | LNX | **on our failing board** |
| `visual/filters/blur_scales_with_screen` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 6 renderer/core re-bake(s), e.g. 146d565c02 "render: Add Filter::scale() and use it to scale fi" |
| `visual/filters/blur_size_grows` | output | not Flash | 99011/0@t3 | 230 | 50152 | draw | LNX | 3 renderer/core re-bake(s), e.g. 30e7a1eac6 "core: Account for filter size changes when drawing" |
| `visual/filters/color_matrix` | output | not Flash | 16717/0@t0 | 255 | 16651 | draw | LNX |  |
| `visual/filters/displacement_map` | output | not Flash | 38375/72@t20, 30962/160@t32 | 254 | 69219 | draw | LNX | 2 renderer/core re-bake(s), e.g. 400ff32723 "wgpu: Implement a naive DisplacementMap filter" |
| `visual/filters/displacement_map_scales_with_screen` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor) |
| `visual/filters/displacement_map_through_applyFilter` | output | Flash (exact) | 0/0@t4 | 0 | 0 | draw | LNX |  |
| `visual/filters/displacement_map_through_filters` | output | Flash (in tol) | 0/0@t4 | 2 | 1200 | draw | LNX |  |
| `visual/filters/drop_shadow` | output | untestable | 49187/0@t2 | 255 | 18137 | draw | LNX | default-font; 2 renderer/core re-bake(s), e.g. 8cb6e5bdf0 "wgpu: Implement drop shadow filter" |
| `visual/filters/drop_shadow_angles` | output | not Flash | 68725/0@t2 | 255 | 25941 | draw | LNX | 2 renderer/core re-bake(s), e.g. 8cb6e5bdf0 "wgpu: Implement drop shadow filter" |
| `visual/filters/drop_shadow_scales_with_screen` | output | untestable | — | — | — | — | LNX | stage size (viewport_dimensions / scale_factor); 2 renderer/core re-bake(s), e.g. c3fdfc17dd "swf: Scale filter distances where appropriate" |
| `visual/filters/empty_child_filter_bounds` | output | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/filters/glow` | output | untestable | 31905/0@t2 | 255 | 15448 | draw | LNX | default-font; 3 renderer/core re-bake(s), e.g. b30c522f9c "wgpu: Implement glow filter" |
| `visual/filters/glow_pass_scaling` | output | Flash (in tol) | 0/0@t100 | 100 | 280 | draw | LNX |  |
| `visual/filters/glow_with_alpha_strength` | output | untestable | 67343/18@t4 | 254 | 134231 | draw | LNX | default-font; 4 renderer/core re-bake(s), e.g. aba2394732 "wgpu: Respect alpha for glows" |
| `visual/filters/glow_without_composite_source` | output | untestable | 30907/0@t3 | 255 | 15539 | draw | LNX | default-font; 2 renderer/core re-bake(s), e.g. 5c13d323b3 "wgpu: Implement the undocumented ability to disabl" |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.01 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.02 | untestable | 168/0@t0 | 204 | 84 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.03 | untestable | 168/0@t0 | 204 | 84 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.04 | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.05 | untestable | 888/0@t0 | 204 | 444 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_avm1_button` | output.06 | untestable | 888/0@t0 | 204 | 444 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_avm2_button_bounds` | output | untestable | 800/0@t0 | 255 | 400 | direct | LNX | input.json; direct run: tick unpinned |
| `visual/focus_highlight/focus_highlight_basic` | output.01_highlight_under | untestable | 3048/0@t0 | 255 | 1404 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_basic` | output.02_highlight_over | untestable | 3492/0@t0 | 153 | 1164 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_basic` | output.03_after_mouse_move | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_basic` | output.04_after_mouse_up | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_basic` | output.05_after_mouse_down | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_basic` | output.06_after_key_down | untestable | 3492/0@t0 | 153 | 1164 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_basic` | output.07_after_focus_change | untestable | 3048/0@t0 | 255 | 1404 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_basic` | output.08_after_focus_change_and_tab | untestable | 3492/0@t0 | 153 | 1164 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_basic` | output.09_after_focus_change_without_highlight | untestable | 3048/0@t0 | 255 | 1404 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_empty_clip` | output | untestable | 800/0@t0 | 255 | 400 | direct | LNX | direct run: tick unpinned |
| `visual/focus_highlight/focus_highlight_move` | output.01 | untestable | 408/0@t0 | 204 | 204 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_move` | output.02 | untestable | 1749/0@t0 | 255 | 651 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_move` | output.03 | untestable | 1329/0@t0 | 255 | 471 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_move` | output.04 | untestable | 2319/0@t0 | 255 | 881 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_move` | output.05 | untestable | 2319/0@t0 | 255 | 881 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_render` | output.01 | untestable | 1614/4@t0 | 255 | 1464 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_render` | output.02 | untestable | 2907/4@t0 | 255 | 2364 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_render` | output.03 | untestable | 3909/4@t0 | 255 | 2964 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_render` | output.04 | untestable | 1164/4@t0 | 204 | 582 | draw | LNX | input.json |
| `visual/focus_highlight/focus_highlight_render` | output.05 | Flash (in tol) | 51/100@t0 | 255 | 17 | draw | LNX |  |
| `visual/focus_highlight/focus_highlight_render` | output.06 | untestable | 732/4@t0 | 255 | 732 | draw | LNX | input.json |
| `visual/fonts/advance_u16` | output | Flash (exact) | 0/0@t128 | 0 | 0 | draw | LNX |  |
| `visual/fonts/device-font` | output | not Flash | 10611/3@t0 | 255 | 3537 | draw | LNX | 1 renderer/core re-bake(s), e.g. 865dedb86a "text: Fix layout measurements" |
| `visual/fonts/duplicate_font` | output | not Flash | 8070/0@t0 | 255 | 2690 | draw | LNX | 1 renderer/core re-bake(s), e.g. 18f5ba18e9 "core: Don't overwrite font descriptor with a dupli" |
| `visual/fonts/font_lookup_as3` | output | untestable | 65160/72@t1 | 255 | 21789 | screen | LNX | default-font; 1 renderer/core re-bake(s), e.g. 0f6dae56b5 "core: Improve spacing of device font letters (clos"; **on our failing board** |
| `visual/fonts/glyph` | output | not Flash | 1656/0@t0 | 255 | 552 | draw | LNX |  |
| `visual/fonts/leading_define_font` | output | Flash (in tol) | 0/0@t128 | 16 | 12 | draw | LNX |  |
| `visual/fonts/leading_device_font` | output | untestable | 23220/0@t128 | 255 | 9096 | direct | LNX | direct run: tick unpinned |
| `visual/fonts/leading_embedded_font` | output | untestable | 18282/0@t128 | 255 | 6104 | direct | LNX | direct run: tick unpinned |
| `visual/gradient_issue_9892` | output | Flash (in tol) | 965/2329@t24 | 252 | 76353 | draw | LNX |  |
| `visual/gradient_nonsequential_ratios` | output | Flash (exact) | 0/1300@t36 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 9f9a3da4a0 "render: Improve gradient rendering" |
| `visual/gradient_radial_same_ratios` | output | Flash (in tol) | 3425/3860@t35 | 254 | 23051 | draw | LNX | 1 renderer/core re-bake(s), e.g. 9f9a3da4a0 "render: Improve gradient rendering" |
| `visual/gradient_same_ratios` | output | Flash (exact) | 0/5130@t37 | 0 | 0 | draw | LNX | 1 renderer/core re-bake(s), e.g. 9f9a3da4a0 "render: Improve gradient rendering" |
| `visual/layout/line_vertical_align` | output | untestable | 7728/0@t128 | 255 | 2577 | direct | LNX | direct run: tick unpinned |
| `visual/opaque_background` | output | not Flash | 6248/0@t1 | 255 | 3124 | draw | LNX | 2 renderer/core re-bake(s), e.g. cdb0774642 "core: Hook up DisplayObject::opaque_background" |
| `visual/scale_rotation_cache` | output.15 | not Flash | 26624/0@t0 | 255 | 9216 | draw | LNX |  |
| `visual/scale_rotation_cache` | output.25 | not Flash | 26624/0@t0 | 255 | 9216 | draw | LNX |  |
| `visual/scale_rotation_cache` | output.35 | not Flash | 26624/0@t0 | 255 | 9216 | draw | LNX |  |
| `visual/scale_rotation_cache` | output.5 | not Flash | 26624/0@t0 | 255 | 9216 | draw | LNX |  |
| `visual/scroll_rect_culling` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/simple_shapes/gradients/focal_radial` | output | not Flash | 10366/0@t13 | 204 | 183551 | draw | LNX | 1 renderer/core re-bake(s), e.g. 622abe60d1 "wgpu: Extract T->Color lookup from gradient shader" |
| `visual/simple_shapes/gradients/gradients` | output | not Flash | 6959/0@t1 | 255 | 85083 | draw | LNX | 2 renderer/core re-bake(s), e.g. 7b1c101c81 "wgpu: Fix repeat & reflect gradients" |
| `visual/simple_shapes/gradients/radial` | output | not Flash | 67449/0@t1 | 255 | 50447 | draw | LNX |  |
| `visual/simple_shapes/gradients/reflect` | output | not Flash | 644343/0@t1 | 255 | 215572 | draw | LNX | 1 renderer/core re-bake(s), e.g. 7b1c101c81 "wgpu: Fix repeat & reflect gradients" |
| `visual/simple_shapes/gradients/repeat` | output | not Flash | 649083/0@t1 | 255 | 216363 | draw | LNX | 1 renderer/core re-bake(s), e.g. 7b1c101c81 "wgpu: Fix repeat & reflect gradients" |
| `visual/simple_shapes/heavy_tesselation` | output | not Flash | 69352/3@t0 | 155 | 23229 | draw | LNX |  |
| `visual/simple_shapes/layers` | output | not Flash | 1759/0@t0 | 255 | 1079 | draw | LNX |  |
| `visual/simple_shapes/masks` | output | not Flash | 4119/0@t0 | 255 | 2118 | draw | LNX |  |
| `visual/simple_shapes/masks_equal_clipdepth` | output | not Flash | 4119/0@t0 | 255 | 2118 | draw | LNX |  |
| `visual/simple_shapes/overlaps` | output | not Flash | 1792/0@t0 | 255 | 626 | screen | LNX |  |
| `visual/simple_shapes/scroll_rect_mask` | output | not Flash | 11612/0@t0 | 255 | 5806 | draw | LNX |  |
| `visual/simple_shapes/strokes/scale` | output | not Flash | 10767/0@t5 | 192 | 3589 | draw | LNX | upstream known_failure (.ruffle.png); **on our failing board** |
| `visual/simple_shapes/text_field_mask` | output | not Flash | 2378/0@t0 | 255 | 1189 | draw | LNX |  |
| `visual/simple_shapes/winding_rule` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/static_text_offstage` | output | Flash (exact) | 0/0@t2 | 0 | 0 | draw | LNX |  |
| `visual/text/String_path_variable_button` | output | untestable | 2196/12@t0 | 153 | 732 | draw | LNX | default-font; 2 renderer/core re-bake(s), e.g. 690ce110d8 "avm1: reference displayObjects parents if parent i" |
| `visual/video/colorconversion/h263` | output | untestable | 563018/0@t0 | 8 | 203436 | draw | LNX | video; **on our failing board** |
| `visual/video/colorconversion/vp6` | output | untestable | 552513/0@t0 | 1 | 201305 | draw | LNX | video |
| `visual/video/colorconversion/vp6a` | output | untestable | 271/0@t1 | 2 | 117360 | draw | LNX | video |
| `visual/video/deblocking` | output | untestable | 2410310/0@t0 | 8 | 1177505 | draw | LNX | video |
| `visual/video/h264` | frame10 | untestable | 116817/0@t2 | 255 | 39136 | draw | LNX | video |
| `visual/video/h264` | frame11 | untestable | 116817/0@t2 | 255 | 39136 | draw | LNX | video |
| `visual/video/h264` | frame2 | untestable | 98961/0@t2 | 255 | 33952 | draw | LNX | video |
| `visual/video/h264` | frame3 | untestable | 101969/0@t2 | 255 | 34848 | draw | LNX | video |
| `visual/video/h264` | frame4 | untestable | 104945/0@t2 | 255 | 35696 | draw | LNX | video |
| `visual/video/h264` | frame5 | untestable | 107937/0@t2 | 255 | 36528 | draw | LNX | video |
| `visual/video/h264` | frame6 | untestable | 110865/0@t2 | 255 | 37360 | draw | LNX | video |
| `visual/video/h264` | frame7 | untestable | 113825/0@t2 | 255 | 38224 | draw | LNX | video |
| `visual/video/h264` | frame8 | untestable | 116817/0@t2 | 255 | 39136 | draw | LNX | video |
| `visual/video/h264` | frame9 | untestable | 116817/0@t2 | 255 | 39136 | draw | LNX | video |
| `visual/video/h264_multinalu` | output | untestable | 172800/0@t2 | 255 | 57600 | draw | LNX | video |
| `visual/video/vp6_alphaoffset` | output | Flash (exact) | 0/0@t0 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_dispsize` | output | untestable | 552513/0@t0 | 1 | 201305 | draw | LNX | video |
| `visual/video/vp6_inter_frames` | output.01 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.02 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.03 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.04 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.05 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.06 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.07 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.08 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.09 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.10 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.11 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.12 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.13 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.14 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.15 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
| `visual/video/vp6_inter_frames` | output.16 | Flash (exact) | 0/0@t1 | 0 | 0 | draw | LNX |  |
