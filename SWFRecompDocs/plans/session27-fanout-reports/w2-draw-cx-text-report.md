# s27 wave 2: `w2-draw-cx-text`: `BitmapData.draw()` of descendant colour transforms and TextFields (AVM1 + AVM2)

**Branch:** `fanout/w2-draw-cx-text` · **Patch:** `w2-draw-cx-text.patch` (apply with `git apply`; it also creates the two new
fixture dirs) · **Base:** `origin/master` `53540ff02` · **Upstream tests:** Ruffle `1e604fa87` (avm1 avm2 visual from_shumway
text fonts from_gnash downloaded) · **Box:** cloud, Dawn/lavapipe OK (`SETUP_STATUS` all OK)

## NEW files

- `ruffle-tests/tests/swfs/regression/avm1_bitmapdata_draw_edittext/` (`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt` = **Flash**)
- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_edittext_box/` (`Test.as`, `build_swf.sh`, `test.swf` = the coordinator's
  mxmlc build archived in `w1-local-oracles/…`, `test.toml`, `output.txt` = **Flash**)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-draw-cx-text-fixtures/`: three ORACLE-REQUEST fixtures, **not** landed (no Flash golden yet):
  - `avm2_bitmapdata_draw_text_glyph_cx/Test.as` (needs mxmlc)
  - `avm1_bitmapdata_draw_text_glyph_cx/` (`create_test_swf.py`, `test.swf`, `test.toml`)
  - `avm1_bitmapdata_draw_child_color/` (`create_test_swf.py`, `test.swf`, `test.toml`)
- this report, `w2-draw-cx-text.patch`

No new `.c`/`.h` files. The one new public symbol, `avm2_cpu_raster_textbox`, lives in the existing `avm2_cpu_raster.c` TU. That TU
is already in both the AVM1 and AVM2 source lists, in CMake and in the Emscripten build.

## Verdict: GO

**Priced flips: 2 trace rows, both new `regression/` fixtures with FLASH goldens. 0 corpus rows.** Pricing confirmed: no corpus row
draws a boxed or tinted field, or a holder with a tinted descendant. All 42 corpus/regression rows that call `draw` are
md5-identical and keep their status (table below).

| test (`regression/`) | mode | before (clean master) | after |
|---|---|---|---|
| `avm1_bitmapdata_draw_edittext` | graphics | output_mismatch (`255`×3) | **pass** |
| `avm1_bitmapdata_draw_edittext` | no-graphics | (same code path) | **pass** |
| `avm2_bitmapdata_draw_edittext_box` | graphics | output_mismatch (A `ff`, A ct `ff`, B tf `ff`, B shape `ff0000`) | **pass** |
| `avm2_bitmapdata_draw_edittext_box` | no-graphics | n/a | **pass** |
| `avm2_bitmapdata_draw_textfield` (glyph + draw-ct pin) | graphics | pass | pass (md5/status identical) |

## EXPECTED-FLIP LEDGER (check CI against this)

**Trace axis, both modes:**
- `regression/avm1_bitmapdata_draw_edittext`: new row → **pass**
- `regression/avm2_bitmapdata_draw_edittext_box`: new row → **pass**

**Pixel axis: none.** Nothing in the patch can move a render that has no TextField box or tinted descendant inside a
`draw()` source, or no tinted shape under a draw ct. Every sweep and canary PNG is md5-identical (sections below). Any other trace or
pixel move is a regression attributable to this patch.

## What changed (exact scope)

### AVM2: `SWFModernRuntime/src/avm2/avm2_bitmap.c`
- **Running colour transform through `bd_draw_shape_walk`**. New `BdCx g_bd_cx` (the CPU twin of `avm2_display.c`'s
  `g_avm2_cur_cx`), with helpers `bd_cx_is_identity`, `bd_cx_push`, `bd_cx_fixed8`, `bd_cx_add16` and `bd_cx_compose_layer`.
  - Each child, and the SimpleButton state child, composes its own `cx_rm/gm/bm` and `cx_ra/ga/ba/aa` into the running
    transform. Its alpha multiplier keeps riding the walk's `alpha`.
  - The draw ROOT's own transform stays ignored.
  - Under a non-identity running cx, a node's own content goes into a transparent layer, which is then composed through the cx
    per covered texel. The content is bitmap, morph, shape, EditText glyphs, static text and Graphics geometry.
  - The layer pass uses the same fixed-8 `ctx_channel` math as the old draw-ct layer loop. Identity cx means no layer, so the
    path is byte-identical to before.
- **The draw() colorTransform on a vector source now seeds `g_bd_cx`.** It is applied per node, composed with descendants,
  like Ruffle's per-draw cxform. It used to tint one whole-subtree layer afterwards, which would have tinted the box.
  - A layer remains only for `blendMode != normal`, where it is now blend-only.
  - One semantic difference: a pure `alphaOffset > 0` ct no longer paints uncovered (alpha 0) texels. Per-node application only
    touches covered pixels, which is the GPU behaviour. No swept row exercises this (all md5-identical).
- **TextField box.** New `bd_draw_tf_box` reads `avm2_text_box_info` (prototype added locally) and draws the background and
  border untinted, before the glyphs.
  - It is called from `bd_draw_textfield` (`draw(tf)`) and from the walk's EditText leaf. In the walk it goes onto the real
    target, outside the cx layer.
  - It applies Ruffle's device-font rotate/shear/reflect cull.
  - `text_raster_core` itself is unchanged: `avm2_cpu_raster_text` also feeds `avm2_cpu_walk`, which must not grow a box.
- `bd_draw_masked`: the mask coverage pass runs under identity cx (save and restore `g_bd_cx`).
- **Not touched:** `bd_apply_filter`, `bd_draw_cm_filtered` (sibling `w2-flash-filter-kernels`), `glyph_raster_core`. The
  running cx simply flows through `bd_draw_cm_filtered`'s inner walk.

### Shared CPU painter: `avm2_cpu_raster.c` / `avm2_cpu_raster.h`
- New `avm2_cpu_raster_textbox(...)` (plus a static `cpu_box_px`). It paints the field box in field-local pixels → target pixels
  into a premultiplied buffer. Rules:
  - **Axis-aligned case:** the device-box rule of `avm2_render_textbox`'s device arm, which matches Ruffle `draw_device_text_box`.
    Corners are rounded, the fill is `[x0,x0+w)×[y0,y0+h)`, and the 1px border lines leave the bottom-right corner pixel uninked.
  - **Rotated or sheared case:** background only, by pixel-centre coverage. The border is not drawn.

### AVM1: `SWFModernRuntime/src/actionmodern/action.c`. Functions touched:
- **`rasterizeMovieClipToBitmap`** gains two changes:
  - **TextField arm:** if `ng_textfield_idx >= 0 || == -2` (the `MC_IS_TEXTFIELD` test; that macro is defined later in the
    file), it calls `bd1_draw_textfield_box`.
  - **Child-recursion cx composition:** `bd1_compose_child_cx` composes the child's Color into `cx`. It is skipped when writing
    a mask stencil.
- **NEW `bd1_draw_textfield_box`**: the box props are the ones `actionIterateTextFields` reads.
  - It reads `background`, `backgroundColor`, `border`, `borderColor` and `embedFonts`, plus the device cull.
  - The box geometry is `_tf_visualOffX/Y`, the DefineEditText RECT min via `ng_getTextFieldBounds`, and `mc->width/height`.
  - It paints via `avm2_cpu_raster_textbox` into `g_bd1_scratch`, then `bd1_apply_cx_over(…, cx20 = NULL, cx = NULL, …)`.
    That gives the clip rect and stencil, and keeps the box **untinted**.
- **NEW `bd1_compose_child_cx`**: `out = outer(child)` from `MovieClip.cx_*`. Every build mode keeps that mirror in sync on
  `Color.setRGB`/`setTransform`, `transform.colorTransform` and `_alpha`, so no `#ifdef` was needed.
- `#include <avm2/avm2_cpu_raster.h>` was already there (s26). No `tag.c`, `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-arm
  edits.

## Flash characterization implemented, and what is left as today

| element | in `draw()` | source | implemented |
|---|---|---|---|
| TextField **box**, device font | untinted by the draw ct, by its own cx, and by an ancestor's Color | FLASH (w1 oracles, both AVMs) | yes, AVM1 + AVM2 |
| tinted **shape** child (AVM2) | tinted by the descendant cx | FLASH (`B shape = ff00`) | yes; also morphs, bitmaps, static text, Graphics |
| tinted Drawing-API child (AVM1) | tinted (expected by construction) | **oracle request 3** | yes (ours now `65280`) |
| EditText **glyphs**, AVM2 | draw ct tints them (pinned by `avm2_bitmapdata_draw_textfield`) | Flash unknown, **oracle request 1** | unchanged for `draw(tf, ct)`; **new:** a descendant/holder cx now tints embedded glyphs too (they sit in the node's cx layer, like static text and Ruffle) |
| EditText **glyphs**, AVM1 | not drawn at all | — | **NOT done** (see HOLD below) |
| box of an **embedded-font** field | applied untinted too | Flash unknown, **oracle request 1 (X embed lines)** | untinted (Flash's measured case was device fonts only) |

**Premise attack: the "untinted box" may be a device-font rule, not a draw() rule.** Flash famously ignores colour transforms and
alpha on device text. Both measured fields were `embedFonts = false`. So the measurement cannot tell "draw() never tints a box"
apart from "a device-font field ignores cx". I implemented the box as untinted for both kinds, because that is the only measured
fact. Oracle request 1's `X embed …` lines settle it. If Flash tints an embedded-font box, gate `bd_draw_tf_box` /
`bd1_draw_textfield_box` on `device_font` and pass the running cx's RGB (S, ~10 lines).

The same question applies to the ON-SCREEN path. `avm2_textbox_cx_rgb` and `tf_cx_rgb` tint the box on screen, which is Ruffle's
behaviour. If Flash's device-font box ignores cx on screen too, that is a separate pixel lead (see New leads).

## HOLD: AVM1 EditText glyphs in `draw()`

- **Not done:** the brief's step 2 asked for AVM1 glyphs "via the AVM2 CPU glyph raster".
- **Why:** that raster (`glyph_raster_core`) consumes `Avm2GlyphPlacement[]` from the AVM2 layout engine. AVM1 has no CPU
  layout: line breaking, runs, alignment, margins and kerning are done inside `tag.c`'s GPU text pass
  (`textfield_glyph_render_cb` / `tag_text_glyph_compose`), which sibling `w2-avm1-text-layout` owns this wave.
- **Zero yield today:** every AVM1 draw() fixture we have uses a device font, and we render no device-font glyphs anywhere in
  AVM1 CPU paths. The new oracle fixture traces `red=false green=false` on all four lines, before and after.
- **Completion mechanism (M):** after `w2-avm1-text-layout` lands, add a CPU sink to `tag_text_glyph_compose`'s per-glyph
  callback. Each glyph is a `glyph_data` shape range, exactly what `bd1_draw_timeline_entry` already rasters for static text
  through `avm2_cpu_raster_shape`. Invoke it from `bd1_draw_textfield_box`'s call site with the draw matrix. Glyph tint rule:
  whatever oracle request 2 says.

## Sweep: every row that calls `draw` (graphics, `--images`, clean master vs patch, same box)

- **Scope:** a constant-pool scan of every downloaded `test.swf` (CWS/FWS) containing `BitmapData` plus `draw` or
  `drawWithQuality`. 44 rows across avm1, avm2, visual, from_shumway and regression, including the 3 regression draw-text rows.
  The new fixtures are covered above.
- **Result: 42/42 other rows identical, on both trace status and actual-PNG md5.** That holds for every row with PNGs: 30 rows,
  31 PNGs.
- **Rows that are image-failing before and after, unchanged and matching baseline:** `avm2/bitmapdata_applyfilter_blur`,
  `bitmapdata_draw`, `bitmapdata_opaque`, `blend_scroll` and `stage3d_raytrace`.
- `avm2/blend_transform` stays `ruffle_matched`, as before.
- **Regression check near the change** (all pass, identical): `avm2_bitmapdata_draw_textfield`, `avm2_graphics_runtime`,
  `avm2_morph`, `avm2_parent_child_render`, `avm2_parent_child_static_text`, `avm2_static_text`, `avm2_timeline_gradients`,
  `avm2_timeline_solid`, `avm2_timeline_stroke_gradient` and `avm2_timeline_text`.
- The s26 AVM1 draw rows are covered too: `visual/static_text_offstage`, `avm1/bitmap_data*` and
  `from_shumway/bitmapdata/draw-and-read`.

## Graphics canary (`render_canary.py`, `render_canary_tests.txt`, 152 tests / 217 PNGs)

**217/217 PNGs IDENTICAL (md5), 0 DIFFERS / APPEARED / VANISHED / NO_RENDER, no trace-status or image-status
changes.** Legs: `after` (patch) captured first, then `before` (patch reversed, i.e. clean `origin/master`), same box, `--jobs 2`.

The standing set already holds draw()-walk members (`acid-bitmapData-draw`, `bitmapdata_draw_self_via_graphic`,
`bitmapdata_draw_masks`, `bitmapdata_draw_filters`, `static_text_offstage`, `pixelbender_dithering`). The change class
(a boxed/tinted text or a tinted descendant inside `draw()`) has no pixel row anywhere in the corpus. Its guards are the two new
**trace** fixtures, which carry Flash goldens, so no canary member was appended. `render_canary_tests.txt` is unchanged.

## Our output on the oracle-request fixtures (for the coordinator to diff against Flash)

`avm1_bitmapdata_draw_child_color` (graphics). The lines marked * are by construction from Flash semantics; line 3 is open.

| line | before | after | expected |
|---|---|---|---|
| 1 `draw(h>setRGB c)` | 16711680 | **65280** | 65280* |
| 2 `draw(h>setTransform c)` | 16711680 | **65280** | 65280* |
| 3 `draw(h>_alpha50 c)` | 16711680 | 16711680 | Flash decides; ours ignores it: the AVM1 Drawing-API `RASTER_TRI` path writes opaque targets with alpha forced to 0xFF and never blends (pre-existing) |
| 4 `draw(h>setRGB c,m,ct)` | 16711935 | **65535** | 65535* |
| 5 `draw(tinted c itself)` | 16711680 | 16711680 | 16711680* (own transform ignored) |

`avm1_bitmapdata_draw_text_glyph_cx`: ours prints `red=false green=false` on all 4 lines, both legs (no AVM1 CPU glyphs).
`avm2_bitmapdata_draw_text_glyph_cx`: not buildable in the cloud (mxmlc).

## Refutations and notes

- **The w1 by-construction goldens were wrong** on 2 of 3 AVM1 lines and 2 of 4 AVM2 lines; Flash overrules them. Ruffle's
  exporter agrees with the wrong values (it tints the box in draw()). This is a Ruffle-vs-Flash difference with no corpus row,
  so there is no `RUFFLE_VS_FLASH_DIFFERENCES.md` entry (it covers corpus rows only). The fixture docstrings record it.
- **The brief's "draw the TextField box in `text_raster_core`" was adjusted.** `text_raster_core` is also reached from
  `avm2_cpu_walk` (via `avm2_cpu_raster_text`), and the box has to be drawn outside the walk's cx layer anyway. So the box is a
  sibling call (`bd_draw_tf_box`) at the two draw() call sites.
- **Name-aliasing in AVM1 `Color`:** see New leads. My first draft of the child-colour fixture named every child `c`, and
  `new Color(h2.c)` tinted `h1.c`.

## New unclaimed leads

1. **AVM1 `Color` resolves its target by instance NAME** (`colorGetMCName` → `actionFindMovieClipByName` /
   `ng_getColorTransform(name)`, `action.c` ~12100-12350, the `NO_GRAPHICS || OFFSCREEN_RENDER` arms).
   - `new Color(h2.c)` with a same-named `h1.c` tints `h1.c`; measured, see the fixture note.
   - The browser arm already resolves pointer-first (`colorGetTargetMC`).
   - Fix (S–M): use `colorGetTargetMC` in the native arms too.
   - Likely trace/pixel yield in games that reuse child names (`mc.bg`, `mc.icon`).
2. **AVM1 Drawing-API `draw()` onto an opaque BitmapData ignores source alpha** (`RASTER_TRI`, `la8 = dest->transparent ? … : 0xFF`
   overwrites instead of blending).
   - `_alpha`, `beginFill(c, 50)` and a ct alphaMultiplier are all dropped on opaque targets.
   - Oracle request 3 line 3 measures it. Fix (S) once Flash's rounding is known.
3. **On-screen device-font box tint.** `avm2_textbox_cx_rgb` (AVM2) and `tf_cx_rgb` (AVM1) tint the box on screen, which is
   Ruffle's behaviour. If Flash ignores cx on device-font text, the on-screen box is also wrong vs Flash.
   - Needs a FLASH image of a cx'd device-font field with a background (`run_image.py --screen`).
   - The existing `regression/avm1_edittext_placed_cxform` row is the natural probe.
4. **AVM1 EditText glyphs in draw()**: the HOLD above, after `w2-avm1-text-layout` lands.

## LOCAL ORACLE REQUESTS

1. **FLASH: `w2-draw-cx-text-fixtures/avm2_bitmapdata_draw_text_glyph_cx/`, trace, 1 frame.**
   - Build `Test.as` with `regression/avm2_bitmapdata_draw_textfield/build_swf.sh`'s recipe (DejaVuSans embed).
   - Need the 16 lines: glyph colour under draw ct, descendant cx and holder+ct, for device and embedded fields (`G …`), and
     the box colour of a device vs EMBEDDED field under the same tints (`X …`).
   - Decides (a) whether the untinted-box rule is device-only, and (b) the glyph tint rule.
   - A wave-3 worker applies it in `bd_draw_tf_box` and the glyph layer (S).
2. **FLASH: `w2-draw-cx-text-fixtures/avm1_bitmapdata_draw_text_glyph_cx/`, trace, 1 frame** (`test.swf` built).
   - Device-font glyph colour in AVM1 draw() under draw ct and an ancestor Color: 4 lines of `red=… green=…`.
   - Needed before the AVM1 glyph HOLD is implemented.
3. **FLASH: `w2-draw-cx-text-fixtures/avm1_bitmapdata_draw_child_color/`, trace, 1 frame** (`test.swf` built).
   - Confirms lines 1, 2, 4, 5 (the child-cx composition this patch implements; ours matches the by-construction values).
   - Measures line 3 (`_alpha` on an opaque target).
   - If Flash matches, land it as `regression/avm1_bitmapdata_draw_child_color` with `flash.txt` as `output.txt`. The trace
     axis would gain lines 1, 2 and 4 as a flip (all three fail on clean master).
