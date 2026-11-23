# w1-pixel-tail: pixel axis, the tail rows + disposition records (session 26, wave 1)

**New files (both under `session26-fanout-reports/`):** `w1-pixel-tail-report.md` (this file) and
`w1-pixel-tail-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp ruffle-tests/verify_output.py`,
473 lines; sources reverted on the branch). No new source files, no new fixtures.

**Environment:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe). Base `origin/master` `ec07cc9e`
(code = `697669e5f`). Tests downloaded from upstream Ruffle master **`3e98d9ba6`** (categories `visual avm2
from_shumway from_gnash fonts stage3d avm1 timeline text mixed_avm swf import_assets audio`). Ruffle source: blobless
clone at `3e98d9ba6`.

**CI fidelity, proven per headline row.** Before-renders md5-identical to `origin/ruffle-image-results` (run
`45078991452`): `static_text_offstage` `5954f028…`, `acid-color-0` `f97ed470…`, `pixelbender_dithering` `3153e740…`,
`bitmapbuttons` `a806ccf6…`; every outlier count reproduces the baseline list exactly. All numbers below are CI-grade.

---

## Verdicts (lead)

| # | Row | Verdict | Measured (CI-grade, before → after) | Flips |
|---|---|---|---|---|
| 1 | `visual/static_text_offstage` | **GO, prototyped.** AVM1 `BitmapData.draw()` timeline arm (sub-mechanism (c)) | 9600 → **0 (max diff 0)**, tol 2 / limit 0 | **+1** |
| 2 | `avm2/pixelbender_dithering` | **GO, prototyped.** Premise "CPU bitmap-fill arm in `avm2_cpu_raster_shape`" is **only half right**: the shape never reaches the raster because `resolve_shape_geom` drops every bitmap-fill shape (`renderable = 0`) | 1 297 344 → **8 614** (limit 19 929, 57 % headroom) | **+1** |
| 2b | `from_shumway/bitmapbuttons` | **Old NO-GO REFUTED** ("feature slice", playbook §16 L994). Same mechanism, GPU half: AVM2 never uploads static bitmaps, and the walk skips bitmap-fill shapes | 618 042 → **52** (tol 4, limit 0; max diff 248 → 11) | 0 (band; 27 corner AA px) |
| 1b | `from_gnash/misc-ming.all/BitmapDataDraw` (trace, KF upstream) | **GO, prototyped — found by the rider sweep.** Slice 2 made AVM1 `draw()` render the test's JPEG clip, which exposed a pre-existing bug: the child-MC recursion in `rasterizeMovieClipToBitmap` rebuilt each child's matrix from `xscale/yscale/rotation` and **dropped `skew`** (`mc5` sits in `mc4` at a=0.75 b=−0.2 c=0.3 d=0.35). Folding `mc->skew` in (Ruffle's `rotation_y = rotation + skew`) | **ruffle_matched → PASS** in both modes (Flash's lines 46–50 incl. the two Ruffle fails) | **+1 trace** |
| 3 | `from_shumway/acid/acid-color-0` | **NO-GO for a flip (s24 stands, chain re-priced).** None of the s23/s24 hunks landed | 17 315 (unchanged) | 0 |
| 4 | Disposition records (20 rows) | see §4: drafted entries; re-tested 9 of 20 (`bitmapbuttons` fell; the s25 `stage3d_*` premise refuted: it is the CPU shading-budget latch) | — | — |

**Priced flips for wave 2: +2 pixel + 1 trace certain** (`static_text_offstage`, `pixelbender_dithering`; trace `BitmapDataDraw`), plus the
`bitmapbuttons` band (618 042 → 52). Both flips are one ~300-line patch in three slices that can land separately:
(1) AVM1 `draw()` timeline arm, (2) AVM2 bitmap-fill CPU raster + `resolve_shape_geom`, (3) AVM2 static-bitmap
upload for the GPU walk. Slice (1) alone = `static_text_offstage`; slice (2) alone already gives
`pixelbender_dithering` (8 614, measured before slice 3 existed), but **land (2) and (3) together**: (2) alone makes
the AVM2 GPU walk draw bitmap-fill shapes against EMPTY static pools (measured: `bitmapbuttons` md5 moves, 618 042
unchanged). (3) is `bitmapbuttons`' band.

**Sweeps** (md5, `render_canary` A/B, full prototype applied vs clean master, `--tier all`): the **whole standing
canary** (127 tests / 186 comparisons) **plus 33 argued extras** (every image-graded AVM2 SWF with a DefineBits* tag,
40 by tag scan, minus the 7 already in the canary; plus the 3 image-graded AVM1 `draw()` rows): **160 tests / 221
comparisons, 218 md5-IDENTICAL, 3 DIFFER — exactly the ledger** (`pixelbender_dithering` fail → pass,
`static_text_offstage` fail → pass, `bitmapbuttons` fail → fail band). **0 trace-status changes.** (The sweep ran
before the skew hunk existed; that hunk only runs inside AVM1 `draw()` for a sheared child, and the 3 image-graded
AVM1 `draw()` rows were re-run with it: md5-identical to the sweep.) Plus `regression/`
(graphics): `avm2_bitmapdata_draw_textfield`, `avm2_static_text`, `avm1_parent_child_bitmap_fill`,
`bitmap_pool_layer_cap`, `avm1_parent_child_text` all pass; `static_text_offstage` no-graphics trace passes. The
standing canary cannot see either change class (it holds no AVM1 `draw()` of timeline content and no AVM2 bitmap
fill): **wave 2 should append `visual/static_text_offstage` and `avm2/pixelbender_dithering` (and
`from_shumway/bitmapbuttons` as a tier-2 band) at EOF.**

---

## 1. `static_text_offstage` (c): AVM1 `draw()` never drew timeline content — GO, +1

**Mechanism (s24 §3c confirmed).** `rasterizeMovieClipToBitmap` (`action.c:14618`) draws only the source clip's
Drawing-API paths and its `child_mc_cache` children. The source MC's own **display list** (`mc->display_obj->
sprite_display_list`: DefineShape / DefineText placed by its timeline) is never visited. The test's sprite
`offstage` holds one DefineText; `bd.draw(offstage)` leaves the yellow bitmap empty → the two 40×40 blue squares
(9600 = 2×40×40×3 channels) are missing.

**Prototype** (`action.c`, new static `bd1_draw_timeline_entries` + `bd1_apply_cx_over`, called from
`rasterizeMovieClipToBitmap` after the Drawing-API paths and before the child-MC recursion):
- walks `sprite_display_list[0..sprite_max_depth]`; skips empty / clip-depth (mask) / `as_hidden` entries and
  EditTexts (`ng_getCharTextfieldIdx >= 0`; those render dynamically);
- `CHAR_TYPE_SHAPE`: `avm2_cpu_raster_shape(shape_offset, size)` under placement × draw matrix (twips);
- `CHAR_TYPE_TEXT`: per glyph, `glyph_data[4*text_data[...]]` range under placement × `transform_data
  [transform_start + j]` (the same data `render_single_object` feeds the GPU);
- rasterizes into a premultiplied scratch, then applies the placement cxform (shape) or the text's baked colour
  cxform (`ch->cxform_id`: zero RGB mult + colour add, which is how the recompiler colours static text) and the
  `draw()` colorTransform, and composites source-over onto the (straight-ARGB) AVM1 bitmap. Respects the setMask
  stencil and the stencil-build mode, like the existing paths.
- `g_bd1_draw_app` is set in `bitmapDataDraw` (the recursion has no app pointer).

**Build note (the one real cost).** `avm2_cpu_raster.c` was AVM2-only; an AVM1 build never linked it. It is
self-contained (only the generated tables + `ng_combined*` from `tag.c`), so the prototype moves it from
`AVM2_CORE_SOURCES` to the base list in `verify_output.py`. **Wave 2 must also** add it to `SWFModernRuntime/
CMakeLists.txt` `CORE_SOURCES` and the AVM1 WASM source list(s) (`SWFRecomp/scripts/build_wasm_test.sh` /
`build_wasm_runtime_lib.sh`), and drop it from the AVM2-only lists so AVM2 builds don't link it twice. The
alternative (no build-list change) is an AVM1-local solid-fill raster on the existing `RASTER_TRI` macro — cheaper to
land, but a second rasterizer that will drift from the Ruffle-matched one.

**Measured:** 9600 → **0 outliers, max diff 0** (graphics); no-graphics trace still passes. AVM1 `draw()` rider rows
(every SWF in the corpus whose constant pool holds `BitmapData` + `draw`, 9 rows found by a decompressing scan), **with
slice 1 alone** (the full-prototype table is in the next paragraph):
`avm1/bitmap_data`, `bitmap_data_draw_cliprect`, `_return_value`, `_string_target` (all pass → pass),
`from_gnash/BitmapData-v8`, `BitmapDataDraw` (ruffle_matched → ruffle_matched), `GradientFillTest`
(output_mismatch → output_mismatch, both PNGs md5-identical `5d491392…`), `visual/bmd_draw_with_msaa_issue_10579`
(pass, md5-identical `1e68ac0e…`).

**Skew hunk (rider-found, required).** With slices 1+2 but without it, `from_gnash/misc-ming.all/BitmapDataDraw`
regresses ruffle_matched → mismatch in both modes (lines 46–50: the newly drawn JPEG lands unsheared over the cyan
square). With it the row PASSES Flash's output in both modes. Final rider table (full prototype incl. skew): the 4
`avm1/bitmap_data*` rows pass/pass (G/NG), `BitmapData-v8` ruffle_matched/ruffle_matched, `BitmapDataDraw`
**pass/pass** (baseline ruffle_matched/ruffle_matched), `GradientFillTest` output_mismatch with a **byte-identical
diff** to master in both modes, `bmd_draw_with_msaa_issue_10579` and `static_text_offstage` md5 as in the sweep.

**Wave-2 notes.** (i) Draw order: the prototype draws all timeline shape/text entries, then the child MCs; Flash
interleaves them by depth. Merge the two lists by depth when landing (no corpus row distinguishes it). (ii) The CPU
raster's 4-sample AA is off here (`avm2_cpu_raster_set_aa`); AVM2's `bd_draw` turns it on around its walk. The test is
alias-free by construction, so AA on/off is unmeasured on a corpus row — mirror AVM2 (AA on) and re-run the rider set.
(iii) Child movies: the arm reads the root's `transform_data` for glyph slots; a loaded child's static text needs the
combined-table base (`ng_combined*`), same as every other CPU reader.

## 2. `pixelbender_dithering` + `bitmapbuttons`: AVM2 timeline bitmap fills — GO, +1 (and a 618k band)

**The brief's premise is half the story.** Adding the CPU bitmap-fill arm to `avm2_cpu_raster_shape` alone moves
**nothing** (1 297 344 → 1 297 344, measured): instrumentation shows the draw walk reaches the child Shape with
`shape_vert_count == 0`. Owner: `avm2_display.c:581` `resolve_shape_geom` copies geometry only when
`sg->renderable`, and the recompiler clears `renderable` for **any** bitmap fill (`SWFRecomp/src/swf.cpp:11161`,
"Only a BITMAP fill (0x40-0x43) makes the shape unrenderable this tranche"). That flag is read nowhere else. So in
AVM2 a timeline shape with a bitmap fill is **invisible on screen and in `draw()`** — every Flash-IDE-imported image
on an AVM2 timeline. That is also exactly why `bitmapbuttons` is blank (playbook §16 already said so and filed it as
a "feature slice"; it is ~120 lines).

Three slices, all in the prototype:
1. **CPU arm** (`avm2_cpu_raster.c`): `RasterCtx` gains `bmp/bmp_w/bmp_h/bmp_repeat/bmp_smooth`;
   `avm2_cpu_raster_shape` accepts style `0x40-0x43`: bitmap id = low 16 bits of the style index, fill matrix =
   `uninv_mat_data[high 16 bits]` inverted (bitmap px ← shape twips), repeat for 0x40/0x42, clamp for 0x41/0x43,
   bilinear (straight RGBA, −0.5 texel origin) for 0x40/0x41, nearest for 0x42/0x43. Both `raster_tri` and
   `raster_tri_aa` shade it; the two other `RasterCtx` users zero `bmp`. Texel source: new `tag.c`
   `ng_getBitmapByIndex` (AVM1 `defineBitmap` registration order) with an `#ifdef SWF_AVM2` fallback to
   `avm2_generated_bitmaps[id]` (inflating `z_len` entries).
2. **Geometry** (`avm2_display.c:585`): `resolve_shape_geom` accepts `sg->vert_count > 0` regardless of
   `renderable`. Wave 2 should make this the recompiler's job (drop the `shape_renderable = false` line, keep or
   retire the field) and gate it to root-movie shapes until loaded children have their own static bitmap slots
   (a child's bitmap style id is movie-local; `as3-loader/events/loader-events`' `child.swf` is the only corpus case,
   trace-only, unchanged).
3. **GPU static bitmaps** (`avm2_display.c` `avm2_render_init`): AVM2 never runs `defineBitmap`/`finalizeBitmaps`,
   so the static texture pools were empty. Upload `avm2_generated_bitmaps[0..bitmap_count)` (emission order = style
   id) then `renderer_finalize_bitmaps`. The existing AVM1 bitmap-fill WGSL path then draws them.

**The nearest-sampling tie rule (measured, not tuned).** The test's fill matrix is x 28.4445 / y **30** twips per
texel with ty −1600: y is exactly 1.5 px/texel, so every third row's pixel centre lands on a texel boundary. Exact
`floor` gives 20 153 (fail by 224); `ceil − 1` gives 19 853 (the 1/30 inverse is inexact in double, so "exact"
ties are noise either side); **ties-to-lower within float noise** (`floor(u − 1e-6)`) gives **8 614**, and the
result is flat for ε from 1e-6 to 1e-3 (1e-2 → 9 690, 0.05 → 11 770; a proportional bias is worse: k=1e-5 → 8 967).
So the golden resolves ties to the lower texel. That is the rule in the prototype.

**Residuals.** `pixelbender_dithering` 8 614 channels are scattered dither-threshold flips (input ±1 → output 0/255),
concentrated in the textured grass band; plausibly JPEG decode LSBs. Not worth chasing at 57 % headroom.
`bitmapbuttons` 52 channels / 27 px, max diff 11, all on the dark panel's rounded corners and the shadow edge
(x 171–417, y 129–216) — AA at tol 4 / limit 0. That is a near-pass for `w1-pixel-nearpass`-style work, not this slot.

**AVM2 sweep for slice 3** (it changes the static texture pools of every AVM2 movie that embeds a bitmap, even with
no bitmap fill): every image-graded AVM2 SWF with a DefineBits* tag, 40 rows found by tag scan, all in the A/B sweep
below. Only 4 AVM2 SWFs in the whole corpus carry bitmap-fill shapes (`avm2/click_block` trace pass → pass,
`loader-events` child, `pixelbender_dithering`, `bitmapbuttons`).

## 3. `acid-color-0`: NO-GO for a flip; the chain re-priced

Nothing in the s23/s24 chain has landed (no text-cx plumbing in `action.c`, no JPEG3 un-premultiply in `swf.cpp`, no
integer-twip centring). Re-stating the s24-measured chain, since that is the disposition:

| step | owner | price | measured (s24, on the then-baseline) |
|---|---|---|---|
| text colour transform on AVM1/timeline EditText (s23 prototype) | `action.c` text iterators + `swf.c` | M (correctness, game-visible) | 17 326 → 688 |
| JPEG3 colour is premultiplied: un-premultiply at emit | `swf.cpp` JPEG3/4 arm | S (Flash-correct, swept clean in s24) | 688 → 325 |
| premultiplied sampling for timeline bitmaps | `render_webgpu.c` | M, renderer-wide | 325 → ~127 (dilation stand-in) |
| integer-twip centring | `tag.c` `par_x_offset` | S | 127 → 121 |
| ring edge (quality=low shape AA) + glyph edges | — | unpriced | ~14 left |

Floor ≈ 121 against a limit of 3 → stays a band even if every step lands. One premise checked this session: at
`quality = "low"` Ruffle **does** still smooth shape bitmap fills (`render/wgpu/src/mesh.rs:183` takes
`bitmap.is_smoothed` from the fill; quality never enters), so the "straight-alpha bilinear bleed" mechanism is live
for the golden. **Completion mechanism:** the four steps above; fund the first two as correctness work (text cx is
game-visible), the sampling change only with a renderer-wide sweep.

## 4. Disposition records (drafted entries for the playbook's image-axis list)

Format: row — mechanism — disposition — completion mechanism. **[re-tested]** marks rows re-run or re-checked this
session; the rest carry their s24/s25 diagnosis forward (cited).

Re-tested this session (9 of 20, the cheapest-looking third plus the two that fell): `bitmapbuttons`,
`pixelbender_dithering` (both **fell**, §2), `font_lookup_as3`, `definefont4`, `place_object_test`,
`Video-EmbedSquareTest`, `BeginBitmapFill`, `stage3d_fractal`, `stage3d_raytrace` (gdb call census).
Every re-run reproduced the baseline count exactly (38 238, 1 782, 939, 1 104 108, 660 000).

### 4a. Image-axis dispositions to ADD (drafted text for the playbook §3 table / `ACCEPTED_DIFFS.md` with
`<!-- image-axis: ... -->` markers)

| comparison(s) | mechanism | disposition | completion mechanism |
|---|---|---|---|
| `from_shumway/flash_text_TextField output` (966), `from_shumway/stylesheet output` (2089), `from_shumway/hardwrap output` (3099), `from_shumway/captions output` (6528) | **Platform device fonts.** Device-font text (`_sans`, Times, Arial) with no `with_default_font`; the goldens are Flash on Windows system fonts. All four comparisons are `known_failure` upstream; Ruffle's own `output.ruffle.png` draws them the way we do (s25 F) | **ACCEPTED (image-axis, platform UB)**. Never re-diagnose: no code path makes Windows GDI glyphs appear | Shipping the exact Windows system fonts + GDI hinting. Never |
| `from_shumway/acid/acid-text-4 output` (51 678), `acid-text-5 output` (422 235), `acid-textfield output` (15 754) | **Flash advanced anti-aliasing (CSM/FlashType) at tolerance 0.** All KF upstream; ours vs Ruffle's render: 435 / **0** / 6 463 channels (s25 G), i.e. we already match Ruffle and Ruffle fails the golden too | **ACCEPTED (image-axis, Flash rasterizer)** | A FlashType rasterizer clone. Never |
| `from_gnash/misc-ming.all/place_object_test output` (38 238) **[re-tested]** | **Two characters at one depth** (`PlaceObject2` non-move at an occupied depth, frames 1–2): Flash keeps both. We and Ruffle refuse the second; KF on trace AND image upstream. Measured now: ours vs `output.ruffle.png` differs only in a 50-px band (y 85–135, the xtrace label, 1 649 px); Ruffle vs golden is 35 463 channels at tol 50 | **RUFFLE-MATCHED / KF** (RVF-style: both emulators share the display-list model) | A multi-occupancy depth model (L, touches every display-list walk) for one gnash row. NO-GO |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest output` (1 782) **[re-tested]** | xtrace label (embedded-glyph precision, the same 4 px as `morph_test1`) + video-frame chroma noise at the red square's corner; KF tol 5 / limit 0; we match Ruffle's sidecar (playbook §22 L1322) | **KF, Ruffle-matched** | Glyph-precision arc + Sorenson chroma parity; neither flips a limit-0 KF row. NO-GO |
| `from_shumway/acid/acid-shapes-testing output` (41 339) | Diffuse AA across every shape at **tolerance 0**; image comparison KF; trace already `ruffle_matched` (s22) | **KF** | Byte-exact Flash AA. NO-GO |
| `from_shumway/acid/acid-stroke-0 output` (52 702), `visual/simple_shapes/strokes/scale output` (19 287) | **Scale-mode strokes.** Every column renders the same stroke width per row; golden varies by `LineScaleMode` / `NoHScale` / `NoVScale` under scaled/sheared parents. `strokes/scale` adds noScale diagonals drawn scaled, a coarse ~16-gon circle (flattening tolerance applied in local units then scaled up) and square-cap nubs (s25 F). Both KF with zero budgets | **KF band** (correctness L; no flip possible) | Runtime scale-mode stroke widths + scale-aware flattening (L). Band-only |
| `from_gnash/misc-ming.all/shape_test output` (15 994) | Whole missing Ming shapes (left green glyph pair and bar) + hairline-colour ties; KF, tol 50 / limit 0; byte-identical to Ruffle's sidecar except the quality=low hairline tie (s24 §4: tie-break alone 15 994 → 12 575, floor is the missing shapes) | **KF, Ruffle-matched** | Diagnose the Ming fill0/fill1 edge case in the recompiler shape converter (M, unpriced flip: Ruffle misses them too) |
| `from_gnash/misc-ming.all/BeginBitmapFill output` (939) **[re-tested]** | 666 channels = the xtrace device-font label; 231 rotated bitmap-fill parallelogram edges; 42 elsewhere (s25 H). KF, tol 50 / limit 100 | **KF; text slot** | Even a perfect bitmap edge leaves 708 > 100. NO-GO for the bitmap slot |
| `avm2/stage3d_fractal output` (1 104 108) **[re-tested]** | **CPU Stage3D shading budget.** Needs ~200 M shading units (197 tokens × 800×600 × 2 frames); `S3D_FRAG_BUDGET` = 48 M latches the backend off mid-frame (`avm2_stage3d.c:1148-1195`). Also KF upstream: Ruffle's own render misses the golden by 46 611 channels (text overlay font + 1–2 LSB fractal) | **KF** — no flip even at Ruffle parity | GPU Stage3D (AGAL→WGSL on Dawn, Ruffle's naga-agal route). XL arc |

### 4b. Records that are NOT dispositions (fixable; Ruffle passes them)

| row | mechanism | verdict | completion mechanism / price |
|---|---|---|---|
| `avm2/stage3d_raytrace` (660 000, **not KF**) **[re-tested, s25 premise refuted]** | s25 said "needs an instrumented run to find the first failing Context3D call". **Refuted:** a gdb census shows the whole pipeline runs (1 `requestContext3D`, 1 program upload, 60 cube-face uploads, **79 `drawTriangles` + 79 `present`**). The frame is black because the CPU backend's shading budget (48 M) latches it off long before the ~15 G units an 833-token AGAL2 shader × 550×400 × 80 frames needs. Second, independent gap: CPU `tex` ignores **cube** samplers (`avm2_stage3d.c:1056`, "phase C"); this shader's only `tex` is a cube lookup. A 45-line cube-sample probe (major-axis face select, Flash face order = wgpu layer order) moves nothing while the budget latches | **NO-GO on the CPU route** | GPU Stage3D (XL). The cube-sample hunk is a prerequisite for raytrace and away3d on ANY route; land it with the GPU arc |
| `avm2/away3d_advanced_shallow_water_demo` (1 326 365, **not KF**) | Same budget latch (the in-code comment: away3d is the row pinned at the 30 s execution wall; the budget was tuned against it) + cube maps | **NO-GO on the CPU route** | GPU Stage3D (XL) |
| `avm2/blend_shader_luma_lighten` (37 018 excess, **not KF**) | `blendShader` is drawn as NORMAL (`avm2_display.c` `do_blendshader_set`: "No shader-blend backend"). Ruffle runs it through naga-pixelbender → WGSL | **GO-priced (M-L), not prototyped**: the **L6 CPU-PixelBender route** is cheaper than PBJ→WGSL | ~200 LOC: (a) `avm2_pixelbender_run_blend` = the existing filter-mode runner (`avm2_pixelbender_run_filter`, `avm2_pixelbender.c:1814`) plus a `tex1` override (tex0 = background, tex1 = foreground); (b) a render-walk arm for `blend "shader"` nodes: CPU backdrop = `avm2_cpu_walk` of everything below the node clipped to its bounds (needs a stop-at-node flag), CPU raster of the node subtree, PBJ eval, then draw the result as a dynamic bitmap quad at the bounds origin (the Bitmap-node draw path exists); (c) cache on a content stamp (`avm2_pixelbender_filter_stamp`). Flip odds: good — three-tier checks (tol 2/3300, 64/280, 180/0) that Ruffle passes despite "doesn't AA well"; the risk is CPU-vs-MSAA AA on the two ellipse edges under the node rect (~1 500 edge px < 3 300). Rider: `visual/blend_modes/shader_as_mask` (KF, 2100) moves. PBJ→WGSL is L+ and buys nothing extra for the corpus |
| `visual/definefont4` (16 086, not KF) **[re-tested]** | Recompiler still has no DefineFont4 (tag 91) handler (`grep DefineFont4 SWFRecomp/src` → nothing); TLF/FTE TextLine render path absent; no other FTE row has an image comparison | **NO-GO (price unchanged)** | "DefineFont4 (CFF via vendored `stb_truetype`) + TLF compose + TextLine glyph render" mini-arc (L); fund when a second FTE pixel row appears |
| `from_shumway/bitmapbuttons` (618 042, not KF) **[re-tested, NO-GO REFUTED]** | AVM2 bitmap-fill timeline shapes invisible (§2) | **GO (band)** | §2 slices 2+3 → 52 channels; the last 27 px are panel-corner AA |
| `avm2/pixelbender_dithering` (1 277 415 excess) **[re-tested]** | §2 | **GO (+1)** | §2 slices 1+2 |
| `visual/static_text_offstage` (9 600) | §1 | **GO (+1)** | §1 |
| `from_shumway/acid/acid-color-0` (17 312 excess) | §3 | **NO-GO for a flip** | §3 chain |

### 4c. `RUFFLE_VS_FLASH_DIFFERENCES.md` entry (drafted) — `visual/fonts/font_lookup_as3` **[re-tested]**

```markdown
### visual/fonts/font_lookup_as3 (image axis) <!-- image-axis: visual/fonts/font_lookup_as3 output -->

**Diff:** 11 520 excess channels (tol 1, limit 72), ALL in the right-hand column's first four rows:
`embedFonts = true` with `TextFormat.font = ""` (regular / italic / bold / bold-italic). The golden draws
"ABCDEF@" there in Ruffle's injected default font (`with_default_font = true`); we draw nothing. Every
other cell (device fonts, and the embedded "Source Code Pro" rows) matches within 2 px.

**Why:** an embedded-font TextField whose font name resolves to no embedded font renders no glyphs in
Flash Player (no fallback across the embedded/device boundary). The golden was regenerated by Ruffle
("Update test expectations"), and Ruffle falls back to its bundled default font, which the test's own
toml flags: "TODO Fix this test. It shouldn't depend on the default font."

**Decision:** keep the Flash behaviour (blank). Do not add a default-font fallback for embedded fields.
```

(`font_lookup_as3` is not KF upstream, so it stays on the failing board under this RVF marker; the board treats
an RVF image-axis entry as hard-excluded per §3.)


## Wave-2 patch scope (from `w1-pixel-tail-prototype.patch`)

| file | function(s) touched | slice |
|---|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | NEW statics `bd1_apply_cx_over`, `bd1_draw_timeline_entries` (+ file statics `g_bd1_draw_app`, `g_bd1_scratch*`); in `rasterizeMovieClipToBitmap` one call added + the child-matrix skew fix; one line in `bitmapDataDraw` | 1 (+skew, required with 2) |
| `SWFModernRuntime/src/avm2/avm2_cpu_raster.c` | `RasterCtx` (trailing fields), NEW `bmp_texel` / `bmp_sample`; `raster_tri`, `raster_tri_aa` (bitmap shade arm); `avm2_cpu_raster_shape` (accepts 0x40-0x43); `avm2_cpu_raster_tris` / `avm2_cpu_raster_morph` (`R.bmp = NULL`) | 2 |
| `SWFModernRuntime/src/libswf/tag.c` | NEW `ng_getBitmapByIndex` next to `ng_registerBitmapMetadata` (declare it in `tag.h` when landing) | 2 |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `resolve_shape_geom` (drop the `renderable` gate; better: drop `shape_renderable = false` at `SWFRecomp/src/swf.cpp:11161` and `--recompile`); `avm2_render_init` (static-bitmap upload + finalize; `#include <zlib.h>`) | 2, 3 |
| `ruffle-tests/verify_output.py` | `avm2_cpu_raster.c` moved from `AVM2_CORE_SOURCES` to the base list | 1 |
| (not in prototype) `SWFModernRuntime/CMakeLists.txt` `CORE_SOURCES`, AVM1 WASM source lists, AVM2 WASM list | same move | 1 |

Before/after per test: `BitmapDataDraw` trace ruffle_matched → pass (both modes); `static_text_offstage` 9600 → 0; `pixelbender_dithering` 1 297 344 → 8 614 (pass);
`bitmapbuttons` 618 042 → 52; everything else in the 221-comparison sweep md5-identical. Mode parity: no
`swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arm touched; the action.c arm runs in both modes (cxform is graphics-only
data, so no-graphics text draws with its glyph fill colour; no trace row reads it — `static_text_offstage` and the 4
AVM1 `draw()` trace rows pass in no-graphics). Strip nothing: the prototype carries no env switches.

## Refutations

1. **"`pixelbender_dithering` needs the CPU bitmap-fill arm in `avm2_cpu_raster_shape`"** (s24/s25): necessary but
   not sufficient. Alone it moves 0 channels; the shape is dropped earlier, at `resolve_shape_geom`, by the
   recompiler's `renderable = 0`.
2. **"`bitmapbuttons` unchanged NO-GO"** (playbook §24 L1421): refuted — 618 042 → 52 with the same three slices.
3. **"The draw golden's sampling is plain floor"**: no — ties go to the lower texel (plateau measured above).
4. **"AVM1 `draw()` timeline arm is medium-large (~100–150 LOC CPU rasterizer)"** (s24 §3): ~130 LOC, but it does
   not need a new rasterizer; the AVM2 one is table-compatible and self-contained. The real cost is the build-list move.
5. **"`stage3d_fractal` / `stage3d_raytrace` / `away3d` need an instrumented run to find the first failing Context3D
   call"** (s25 w1-pixel-drawing): no call fails. gdb census on raytrace: 79 `drawTriangles` + 79 `present`, program
   and cube faces uploaded. The black viewport is the deliberate CPU shading-budget latch documented in
   `avm2_stage3d.c:1148-1195` since s20 (raytrace needs ~15 G units, fractal ~200 M, budget 48 M). Also `fractal` is
   KF and Ruffle itself misses its golden by 46 611 channels.
6. **"The AVM1 `draw()` riders are unaffected"** (my own slice-1-only sweep): true for slice 1 alone, false once
   slice 2 lets bitmap fills draw — a sheared child exposed the dropped-skew bug. Re-sweep after every slice.

## New unclaimed leads

1. **AVM2 `blendShader` via the CPU PixelBender evaluator** (L6 route for `blend_shader_luma_lighten`): priced in §4.
2. **Loaded-child AVM2 bitmap fills**: once slice 2 lands, a child movie's bitmap-fill shape samples root slot ids.
   Needs per-movie static bitmap bases (the `ng_predeclareChildBitmaps` mechanism, AVM2 side).
3. **AVM1 `draw()` AA**: the timeline arm (and the existing Drawing-API arm) rasterize aliased; Ruffle's `draw()`
   renders at stage quality. No graded AVM1 row distinguishes it today.
4. **AVM1 `draw()` depth interleave** of timeline entries vs child MCs (§1 note (i)).
5. **Stage3D cube sampling** (`avm2_stage3d.c:1056`, `tex` with `dim == 1` returns 0): a 45-line major-axis face
   select (Flash face order +X,−X,+Y,−Y,+Z,−Z = wgpu layer order, clamp, nearest/bilinear) was probed and is
   unmeasurable while the shading budget latches; it is a prerequisite for raytrace/away3d on any route.
6. **AVM2 `draw()` of a Bitmap-fill shape under rotation/skew**: the CPU arm samples by inverse matrix and handles it,
   but no corpus row exercises it; a fixture needs a Ruffle-exporter golden (not requested: no flip rides on it).

## LOCAL ORACLE REQUESTS

none
