# w2-tail-bitmap-draw: AVM1 `draw()` timeline arm + AVM2 timeline bitmap fills (session 26, wave 2)

**New files (both under `session26-fanout-reports/`):** `w2-tail-bitmap-draw-report.md` (this file) and
`w2-tail-bitmap-draw.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt`, 828 lines, 18 files, `git apply --check -R` OK on the branch). **No new source
files, no new fixture dirs.** Source changes are also committed on the branch.

**Base:** `origin/master` **`3a8e02dc`** (patch generated against it; branch = my commit + a merge of it). Verified on
three bases: full sweep on `b4a81ebf`, re-sweep on `a18a9cc6`, and on `3a8e02dc` (after `w2-cm-chain-cab-edge`
landed) the 3 headline PNGs are again md5-identical (`22e81119…`, `4349a280…`, `bc16878e…`), `BitmapDataDraw`
passes and the 3 new `regression/avm1_po3_color_matrix_live*` rows pass. Rebase history: the first full sweep ran on `b4a81ebf`; the 5
sibling landings in between — `w2-acid-clip-fill-region`, `n-pixel-pass`, `w2-avm2-applyfilter-kernels`,
`w2-blendshader-cpu-pbj`, `w1-avm1-dispatch-scope` — applied with one trivial conflict in `render_canary_tests.txt`,
resolved by keeping both blocks, mine at EOF). Tests from upstream Ruffle master **`3e98d9ba6`** (categories
`visual avm1 avm2 from_shumway from_gnash fonts text`). Box: `SETUP_STATUS` all OK (Dawn on lavapipe).
**CI fidelity:** all three headline before-renders are md5-identical to `origin/ruffle-image-results` (the w1 values:
`static_text_offstage 5954f028…`, `pixelbender_dithering 3153e740…`, `bitmapbuttons a806ccf6…`), so the pixel numbers
below are CI-grade.

## Verdict: GO — landed as one patch, ledger reproduced exactly on both bases

| # | Test | Axis | Before (clean master, same box) | After (this patch) | Flip |
|---|---|---|---|---|---|
| 1 | `visual/static_text_offstage` | px | fail, 9 600 outliers (limit 0) | **pass, 0 outliers, max diff 0** | **+1 px** |
| 2 | `avm2/pixelbender_dithering` | px | fail, 1 297 344 | **pass, 8 614** (limit 19 929) | **+1 px** |
| 3 | `from_shumway/bitmapbuttons` | px | fail, 618 042 | fail, **52** (tol 4 / limit 0, max diff 11) | band |
| 4 | `from_gnash/misc-ming.all/BitmapDataDraw` (KF upstream) | trace | ruffle_matched (G and NG) | **pass (G and NG)** | **+1 trace** |

### EXPECTED-FLIP LEDGER (check CI against this)

- **Trace:** `from_gnash/misc-ming.all/BitmapDataDraw` ruffle_matched → **pass**, in **both** graphics and no-graphics.
  (It is `known_failure = true` upstream; this is a Flash-correct pass, not a KF regression.) No other trace status moves.
- **Pixel:** `visual/static_text_offstage output` fail → **pass**; `avm2/pixelbender_dithering output` fail → **pass** (+2).
- **Pixel band (stays fail):** `from_shumway/bitmapbuttons output` 618 042 → **52**.
- Every other comparison in the sweep below is **md5-identical**. A pixel status change anywhere else is a regression.

## Sweeps (md5, `render_canary` A/B, `--recompile`, same box)

1. **Full sweep on base `b4a81ebf`:** the whole standing canary (133 tests) + 45 argued extras = **177 tests**, plus
   an 11-test second leg (5 fonts/text canary rows whose category I had not downloaded for the first before-leg, 4
   more `regression/` bitmap/static-text rows, `avm2/click_block`, `from_shumway/as3-loader/events/loader-events`).
   Extras = every image-graded AVM2 SWF with a DefineBits* tag (39 by a decompressing tag scan, the w1 set), the 3
   image-graded AVM1 `draw()` rows, the 6 trace-only AVM1 `draw()` riders and the w1 regression rows.
   **Result: 235 comparisons, 232 md5-IDENTICAL, 3 DIFFER = exactly the ledger** (`pixelbender_dithering` fail→pass,
   `static_text_offstage` fail→pass, `bitmapbuttons` fail→fail band). **Trace status changes: only `BitmapDataDraw`
   ruffle_matched → pass.** (The first leg's "APPEARED 6" are the fonts/text rows; their second-leg before/after are
   md5-identical.)
2. **Re-sweep on rebased base `a18a9cc6`** (29 tests / 17 comparisons): my 4 headline rows, every canary line the 5
   sibling landings added (`acid-clip`, `3_joystick`, `acid-text-6`, `bitmapdata_applyfilter_destpoint_edges`,
   `blend_shader_luma_lighten`, `shader_as_mask`), the AVM1/AVM2 `draw()` and bitmap-fill rows, and all 8 `regression/`
   fixtures added since `b4a81ebf`. **14 identical, 3 DIFFER = the ledger, 1 trace change = `BitmapDataDraw`.** The
   three after-PNGs are byte-identical to the first sweep's after-PNGs (`22e81119…`, `4349a280…`, `bc16878e…`): the
   sibling blendShader / applyFilter / fill-region work does not interact with this patch on any graded row.
3. **No-graphics A/B** (verify_output default mode, full `--diff --verbose` output compared): `GradientFillTest`
   (mismatch, **byte-identical** 311-line diff to master), `static_text_offstage`, `pixelbender_dithering`,
   `bitmapbuttons`, `click_block` (pass/pass), `loader-events`, `BitmapData-v8` (ruffle_matched/ruffle_matched): all
   identical to master. `BitmapDataDraw` NG: ruffle_matched → pass (ledger).
4. **AVM1 `draw()` riders, both modes:** `avm1/bitmap_data`, `bitmap_data_draw_cliprect`, `_return_value`,
   `_string_target` pass/pass; `BitmapData-v8` ruffle_matched/ruffle_matched; `GradientFillTest` graphics
   `fp10__output` pass 936/1070 as master (md5-identical); `bmd_draw_with_msaa_issue_10579` md5-identical.
5. **`regression/` suite** (graphics, all md5/trace-identical, all pass): `avm1_parent_child_bitmap`,
   `avm1_parent_child_bitmap_fill`, `avm1_placed_drawing_color`, `avm1_runtime_filters_cm_bitmap`,
   `avm2_bitmapdata_draw_textfield`, `avm2_parent_child_static_text`, `avm2_static_and_store_slots`, `avm2_static_text`,
   `bitmap_pool_layer_cap`, plus every regression row in the standing canary and the 8 new ones on `a18a9cc6`.
6. **Recompiler generated-code sweep (cheapest exact sweep):** old (`b4a81ebf`) vs new `SWFRecomp` over **every
   image-graded test dir (403 rows, all suites)**, `diff -r` of `RecompiledScripts/Tags/ABC`: **2 files differ**,
   `avm2/pixelbender_dithering` and `from_shumway/bitmapbuttons` `abc_timeline.c`, and the only change is the
   `renderable` byte of their bitmap-fill shape rows `0 → 2` (1 row and 8 rows). Every AVM1 row's generated code is
   byte-identical (the geometry record is AVM2-only). Same on the two trace-only AVM2 bitmap-fill SWFs:
   `avm2/click_block` 1 row `0 → 2` (trace pass → pass, both modes); `loader-events`' `child.swf` is runtime-gated
   (below), trace ruffle_matched → ruffle_matched.

## What landed (patch scope, every function named)

| file | change |
|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | NEW statics `bd1_apply_cx_over`, `bd1_timeline_list`, `bd1_draw_timeline_entry` (+ file statics `g_bd1_draw_app`, `g_bd1_scratch*`), placed just before `rasterizeMovieClipToBitmap`. **`rasterizeMovieClipToBitmap`**: the child-MC loop now **interleaves the clip's own timeline shapes/static texts with its child MCs by depth** (slot d = SWF depth = AS depth + 16384, 16383 inside a button: the bias `action.c`'s depth sync uses) — w1 note (i); the child matrix folds in `skew` (`rotation_y = rotation + skew`, w1's rider-found fix). **`bitmapDataDraw`**: sets `g_bd1_draw_app`; turns the CPU raster's 4-sample AA **on** around the main source walk (mirrors AVM2 `bd_draw`; w1 note (ii)); the setMask stencil pass stays aliased. |
| `SWFModernRuntime/src/avm2/avm2_cpu_raster.c` | `RasterCtx` trailing bitmap fields; NEW `bmp_texel`, `bmp_sample` (bilinear for 0x40/0x41, nearest ties-to-lower for 0x42/0x43, w1's measured rule); `raster_tri` / `raster_tri_aa` bitmap shade arm; `avm2_cpu_raster_shape` accepts 0x40-0x43; `avm2_cpu_raster_tris` / `_morph` zero `bmp`. NEW (AVM2-only) `avm2_cpu_raster_embedded_rgba`: **per-index** inflate cache of the embedded bitmap table, shared with the GPU upload (replaces the prototype's single-entry static cache, which would re-inflate per triangle on a 2-bitmap draw, and the prototype's second, leaked inflate in `avm2_render_init`). |
| `SWFModernRuntime/include/avm2/avm2_cpu_raster.h` | declares `avm2_cpu_raster_embedded_rgba`; fill-class comment. |
| `SWFModernRuntime/src/libswf/tag.c` | NEW `ng_getBitmapByIndex` (unguarded, next to `ng_getBitmapMetadata`; no existing function changed). |
| `SWFModernRuntime/include/libswf/tag.h` | declares `ng_getBitmapByIndex`. |
| `SWFModernRuntime/src/avm2/avm2_display.c` | **`resolve_shape_geom`**: accepts `renderable != 0`, with a **root-movie gate**: `renderable == 2` (has a bitmap fill) only when `owner == NULL` (root tables) — a loaded child's bitmap style ids are movie-local and it has no static bitmap slots (w1 §2 slice 2). **`avm2_render_init`**: uploads the root's embedded bitmaps in emission order + `renderer_finalize_bitmaps` (w1 slice 3). The prototype's runtime `renderable` bypass is gone. |
| `SWFRecomp/src/swf.cpp` (`interpretShape` AVM2 geom record) | `shape_renderable = false` dropped: the flag is now `shape_has_bitmap_fill` and the record emits `renderable = 2` for a bitmap-fill DefineShape, `1` otherwise. **Morph** shapes with a bitmap fill keep `0` (the AVM2 morph path shades solids only — conservative, unchanged behaviour). |
| `SWFRecomp/include/abc/abc_timeline.hpp`, `SWFModernRuntime/include/avm2/avm2_abc.h`, `avm2_globals.h` | field comments for the 0/1/2 meaning. |
| build lists | see next section. |
| `ruffle-tests/render_canary_tests.txt` | EOF: tier 1 `visual/static_text_offstage`, `avm2/pixelbender_dithering`; tier 2 `from_shumway/bitmapbuttons` (band). |

Measurements behind the two design notes:
- **AA on vs off** around the AVM1 walk: **md5-identical on all 4 AVM1 `draw()` image/trace rows that the arm draws**
  (`static_text_offstage`, `bmd_draw_with_msaa_issue_10579`, `GradientFillTest` 2 PNGs, `BitmapDataDraw` trace). No
  corpus row distinguishes it; AA on mirrors AVM2 / Flash's draw() and is what landed.
- **Depth interleave:** no corpus row distinguishes it either (the 235-comparison sweep is unchanged by it vs the
  w1 prototype's ledger). See LOCAL ORACLE REQUESTS for a fixture.

## Build lists (grep-proved; no emsdk / wasi-sdk on this box, so no WASM build was run)

`avm2_cpu_raster.c` is self-contained (generated tables + `ng_combined*` from `ng_shared.c` + `ng_getBitmapByIndex`
from `tag.c`; `avm2_cpu_raster_embedded_rgba` and the zlib include are `#ifdef SWF_AVM2`). Every runtime build list
below stages sources **flat** into one dir and compiles `*.c`, so listing it in an AVM1 list and also getting it from
an AVM2 `avm2/*.c` copy yields **one** `avm2_cpu_raster.c` / one object: no double link.

| list | change | AVM2 path |
|---|---|---|
| `ruffle-tests/verify_output.py` | moved from `AVM2_CORE_SOURCES` to the base `core_sources` (both modes) | no longer in `AVM2_CORE_SOURCES` → linked once |
| `SWFModernRuntime/CMakeLists.txt` `CORE_SOURCES` | added | — (configure OK; the object compiles under `-DNO_GRAPHICS=ON`. Note: this CMake lib already fails on master at `action.c` — `tesselator.h` not on its include path — unrelated) |
| `SWFRecomp/scripts/build_test.sh` | added in BOTH the graphics and the NO_GRAPHICS branch | AVM1-only script |
| `SWFRecomp/scripts/build_wasm_runtime_lib.sh` (WASI NO_GRAPHICS lib that `build_wasm_test.sh` links) | added to `SOURCES` | — |
| `SWFRecomp/wasm_wrappers/bundle/build.sh` `RUNTIME_C` | added `avm2/avm2_cpu_raster.c` (read from `${RT}/src/avm2/`, which `deploy_wasm_demo.sh` always populates with `avm2/*.c`) | AVM2 branch copies `avm2/*.c` into the same flat `SRC` → same file, compiled once |
| `SWFRecomp/scripts/build_graphics_host.sh` `RUNTIME_C` (docs/recompiler in-browser graphics host) | added | `AVM2=1` copies `avm2/*.c` into the same flat `SRC` → once |
| `SWFRecomp/scripts/profile_game_native.sh` `COMMON_SRCS` | added | AVM1-only |
| `SWFRecomp/scripts/build_wasm_avm2.sh` | **no change needed**: line 90 copies every `avm2/*.c` already | — |
| `SWFRecomp/scripts/deploy_wasm_demo.sh` | **no change needed**: line 80 ships `avm2/*.c` into the bundle's `RT/src/avm2/` | — |
| `docs/recompiler/*.js` | **no change needed**: no `.c` runtime list (they use the bundle / graphics host above) | — |

**Not verified (completion mechanism):** the browser/WASM builds. Since `bundle/build.sh` and
`build_graphics_host.sh` changed, the coordinator should run `gh workflow run deploy-pages.yml --ref master -f
dry_run=true` (it builds the bundle + graphics host) after landing, and a real Pages deploy if green (CLAUDE.md
standing approval).

## Mode parity / CI mode

No `swf_core.c`, `tag_stubs.c` or no-graphics-only arm touched. The AVM1 arm runs in both modes; its cxform read is
inside new `#ifndef NO_GRAPHICS` code (cxform tables are graphics-only data), and both modes were run (above). The
patch touches recompiler AVM2 emission → per CLAUDE.md use **`categories=full`**; the pixel ledger needs an
**`images=true`** run to be graded.

## Known limits (documented in code, not regressions)

1. **Loaded child movies.** AVM2: a child's bitmap-fill shapes stay undrawn (runtime gate; needs per-movie static
   bitmap bases). AVM1 `draw()`: the timeline arm reads root tables (`transform_data` glyph slots, root bitmap ids) —
   a loaded child's static text / bitmap fill inside `draw()` would sample the wrong rows. No corpus row hits either.
2. **AVM2 bitmap id ↔ table slot.** The recompiler's fill style id counts every DefineBits* tag
   (`swf.cpp` `char_id_to_bitmap_id`), while `abc_timeline.cpp` skips a JPEG whose decode FAILS (no `bitmaps.push_back`,
   ~line 1700). A failed decode would shift later ids by one. No corpus row has a failed decode on a bitmap-fill SWF;
   the fix is to push an empty placeholder `BitmapAsset` on failure (L-tiny, but it changes `avm2_generated_bitmaps`
   indexing for `BitmapData` construction too, so it needs its own sweep).
3. Bitmap-fill **morph** shapes in AVM2 remain undrawn (unchanged).

## Refutations / premise checks

1. "Drop `shape_renderable = false` and keep a root gate": the flag cannot simply be dropped — once every shape is
   `renderable = 1` the runtime can no longer tell a bitmap-fill shape apart for the child gate. Landed as a 0/1/2
   class instead (2 = has bitmap fill), which also keeps old generated tables (0) meaning "never drawn".
2. Dropping it for **morphs** too would route bitmap-fill morphs through the solid-only morph path; kept at 0.
3. The prototype's single-entry inflate cache and second inflate in `avm2_render_init` (leaked) were replaced by one
   per-index cache; md5-identical results.

## New unclaimed leads

1. Per-movie static bitmap slots for loaded children (AVM1 + AVM2), lifting both child gates above.
2. AVM2 JPEG-decode-failure placeholder slot (limit 2).
3. AVM1 `draw()` of the Drawing-API paths (`RASTER_TRI` macros) is still aliased; only the timeline arm is AA'd now.
   Routing those paths through `avm2_cpu_raster_tris` would unify them (no graded row distinguishes it today).
4. `bitmapbuttons` residual 52 channels / 27 px = panel-corner AA at tol 4 / limit 0 (near-pass work).

## LOCAL ORACLE REQUESTS

1. **(optional, fixture for the depth interleave)** An AVM1 SWF (any authoring tool; v8): sprite `S` whose timeline
   places a red 40×40 DefineShape at depth 1, a timeline-placed child sprite (green 40×40, offset +20,+20) at depth 2
   and a blue 40×40 DefineShape (offset +40,+40) at depth 3; frame 1 script: `var bd = new flash.display.BitmapData(
   100,100,false,0xFFFFFF); bd.draw(S); attachBitmap(bd, 10); trace(bd.getPixel(30,30).toString(16));
   trace(bd.getPixel(50,50).toString(16));` Expected Flash/Ruffle: green over red at (30,30), blue over green at
   (50,50). Needs the Ruffle exporter trace + a render (`exporter -s -f 1 --trace-log out.txt in.swf out.png`) to become
   `regression/avm1_bitmapdata_draw_depth_interleave`. Not blocking: no corpus row and no ledger entry depend on it.
