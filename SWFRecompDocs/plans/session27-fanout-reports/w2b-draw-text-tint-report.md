# s27 wave 2b: `w2b-draw-text-tint`: `draw()` TextField tint rules (device vs embedded) and AVM1 opaque-target alpha, against FLASH

**Branch:** `fanout/w2b-draw-text-tint` · **Patch:** `w2b-draw-text-tint.patch` (apply with `git apply`; it also creates the three new
regression fixture dirs) · **Base:** `origin/master` `f223ee7a` · **Upstream tests:** Ruffle master `efb612fd7` at download time
(avm1 avm2 visual from_shumway from_gnash; upstream has moved past the brief's `1e604fa87`) · **Box:** cloud, Dawn/lavapipe OK
(`SETUP_STATUS` all OK)

## NEW files

- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_draw_text_glyph_cx/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `Test.as` (the original mxmlc source, kept as the spec) and `output.txt` = **Flash** (`w2-local-oracles/…/flash.direct.txt`, verbatim).
- `ruffle-tests/tests/swfs/regression/avm1_bitmapdata_draw_text_glyph_cx/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt` = **Flash** (verbatim).
- `ruffle-tests/tests/swfs/regression/avm1_bitmapdata_draw_child_color/`: `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt` = **Flash** (`65280 / 65280 / 8323200 / 65535 / 16711680`, verbatim).
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-draw-text-tint-fixtures/avm1_bitmapdata_draw_text_embed_cx/`:
  `create_test_swf.py`, `test.swf`, `test.toml`. This is an ORACLE-REQUEST fixture (the AVM1 embedded twin) and is **not** landed.
- `SWFRecompDocs/plans/session27-fanout-reports/w2-draw-cx-text-fixtures/`: the three w2 oracle-request fixtures. They were
  only on `fanout/w2-draw-cx-text` and are carried here unchanged for provenance.
- this report, `w2b-draw-text-tint.patch`

No new `.c`/`.h` files and no new public symbols. Everything added is `static`, inside `avm2_bitmap.c` and `action.c`.

## Verdict: GO

**Priced flips: 2 trace rows** (new `regression/` fixtures with Flash goldens that fail on clean master), **plus 1 new row that
passes on both sides.** No corpus row moves (sweep + canary below).

| test (`regression/`) | before (clean master, graphics) | after (graphics) | after (no-graphics) |
|---|---|---|---|
| `avm2_bitmapdata_draw_text_glyph_cx` (16 lines) | output_mismatch: lines 14–16 `X embed box … = ff0000` (Flash `ff00`) | **pass** | **pass** |
| `avm1_bitmapdata_draw_child_color` (5 lines) | output_mismatch: line 3 `16711680` (Flash `8323200`) | **pass** | **pass** |
| `avm1_bitmapdata_draw_text_glyph_cx` (4 lines) | pass (Flash: device glyphs draw no solid pixel; ours draws none) | pass | pass |
| `avm2_bitmapdata_draw_textfield` (pin) | pass | pass | pass |
| `avm2_bitmapdata_draw_edittext_box` (device box pin) | pass | pass | pass |
| `avm1_bitmapdata_draw_edittext` (device box pin) | pass | pass | pass |

Lines 1–13 of the AVM2 fixture already matched Flash on clean master. That covers every device line and all 4 embedded *glyph*
lines: w2's per-node `g_bd_cx` already tints embedded glyphs under the draw ct, a descendant cx and holder+ct. Only the
embedded-*box* rule was missing.

## EXPECTED-FLIP LEDGER (check CI against this)

**Trace axis, both modes:**
- `regression/avm2_bitmapdata_draw_text_glyph_cx`: new row → **pass** (fails on clean master: 3 lines)
- `regression/avm1_bitmapdata_draw_child_color`: new row → **pass** (fails on clean master: 1 line)
- `regression/avm1_bitmapdata_draw_text_glyph_cx`: new row → **pass** (passes on master too, so no flip)

**Pixel axis: none.** No corpus or canary PNG changes md5 (section below). Any other trace or pixel move is a regression
attributable to this patch.

## What changed (exact scope)

### AVM2: `SWFModernRuntime/src/avm2/avm2_bitmap.c`

The Flash rule, from `avm2_bitmapdata_draw_text_glyph_cx`:
- **DEVICE field:** the box stays `ff0000` under every tint, and no solid glyph pixel is drawn.
- **EMBEDDED field:** the box AND the glyphs follow the draw ct, the field's own cx under a drawn holder, and holder+ct.

So the landed (w2) "box never tinted" rule is device-only. Changes:
- **NEW `bd_tf_box_is_device`** returns 1 for a device-font box, 0 for an embedded-font box, -1 when there is no box info. It reads
  `avm2_text_box_info` flag bit 4, the same bit `bd_draw_tf_box`'s device cull already used.
- **`bd_draw_shape_walk` (EditText leaf):**
  - A device box is still drawn straight onto the target, untinted, before the cx layer (unchanged).
  - An embedded box is now drawn into the node's cx layer (`sdst`), under the glyphs, so `bd_cx_compose_layer` tints it with the
    running cx (draw ct ∘ ancestors ∘ own).
  - Under identity cx, `sdst == dst`, so that path is byte-identical.
- **`bd_draw_textfield` (`draw(tf, m, ct)`):**
  - Embedded field with a non-identity ct: the box goes through **NEW `bd_draw_tf_box_tinted`**. It rasters the box untinted into
    a transparent layer, seeds `g_bd_cx` from the ct, composes the layer with `bd_cx_compose_layer` (the walk's fixed-8 math),
    then restores `g_bd_cx`.
  - Otherwise it calls `bd_draw_tf_box` as before.
- **Not touched:** `text_raster_core`, `glyph_raster_core`, `bd_apply_filter`, `bd_draw_cm_filtered`, `avm2_cpu_raster.c`.

### AVM1: `SWFModernRuntime/src/actionmodern/action.c`. Functions touched:

**`bd1_draw_textfield_box`: embedded box tint.**
- It takes the running `DrawColorTransform* cx`, and passes it to `bd1_apply_cx_over` **only when `embedFonts`**. A device box
  stays untinted.
- The call site in `rasterizeMovieClipToBitmap` passes `cx`. That `cx` is the draw ct composed with every ancestor's and the
  field's own Color; the draw root's own transform is ignored, as before.
- This is the AVM2 Flash rule carried over. The renderer is AVM-agnostic, but the AVM1 measurement is pending: LOCAL ORACLE
  REQUEST 1.

**`rasterizeMovieClipToBitmap`: translucent Drawing-API fills and strokes on an OPAQUE target.** This is w2's lead 2.
- **Old behaviour:** `RASTER_TRI` forced an opaque target's source alpha to `0xFF` and overwrote the pixel. A child's `_alpha`,
  `beginFill(c, 50)` and a ct alphaMultiplier were all dropped.
- **Flash:** `child_color` line 3, red at `_alpha` 50 over opaque blue, gives `0x7F0080`. That is source-over at alpha **127**,
  from Flash's fixed-8 cx alpha `255 * 128 >> 8`. Ours used `c*m+o` rounding, which gives 128 and would read `0x80007F`.
- **New helper `bd1_opaque_src_alpha`:** the fixed-8 source alpha, `(round(a*255) * round(am*256)) >> 8 + ao`, clamped.
- **New helper `bd1_opaque_over`:** the 8-bit source-over onto an opaque pixel.
- **New helpers `bd1_tri_mark_begin` / `bd1_tri_mark_flush`:** a per-path coverage byte map, so the overlapping triangles of a
  path (shared edges, stroke joins) composite once per pixel rather than once per triangle.
- **Scope:** solid fills and solid strokes, opaque target, alpha < 255 only, and never when writing a mask stencil.
  - In every other case `tri_mark` is NULL and `RASTER_TRI` overwrites exactly as before. That covers transparent targets,
    opaque sources and gradients.
  - The colour channels keep the existing `c*m+o` math. Only the alpha uses fixed-8, and only on this new path.

No `tag.c`, `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-arm edits. The headline rows also pass in no-graphics (table above).

## HOLD: AVM1 embedded-font GLYPHS in `draw()` (unchanged from w2's HOLD; it is now the only open piece)

- **Not done:** AVM1 `draw()` still draws no EditText glyphs at all. The AVM1 embedded twin (`avm1_bitmapdata_draw_text_embed_cx`)
  reads `red=false green=false` on all 4 G lines. If AVM1 matches AVM2 Flash, those should read
  `red=true green=false` / `red=false green=true` ×3.
- **Why not now:**
  1. There is no AVM1 Flash golden for embedded glyphs yet (request 1 below).
  2. The AVM1 layout lives inside `tag.c`'s GPU painter `textfield_glyph_render_cb` (~900 lines: measure pass, soft wrap,
     `has_matrix` composition, run fonts, scroll). It has no CPU sink. `w2-avm1-text-layout` landed (`c2f237a9`), so this is now
     unblocked, but it is a `tag.c` refactor in a file several siblings edit.
- **Completion mechanism (M):**
  - Factor the per-glyph placement loop of `textfield_glyph_render_cb` behind a sink callback. The GPU sink is today's
    `renderer_draw_*` calls. The CPU sink rasters each glyph's `glyph_data` shape range through `avm2_cpu_raster_shape`, the way
    `bd1_draw_timeline_entry` already does for static text.
  - Call it from `bd1_draw_textfield_box`'s call site for an `embedFonts` field only. Flash draws no solid device glyph, and the
    device rows already pass because nothing is drawn.
  - Tint through `bd1_apply_cx_over(…, cx)`, like the embedded box.
  - Land the twin with Flash's trace as its golden.

## Sweep: every row that calls `draw` + the standing canary (graphics, clean master vs patch, same box)

- **Driver:** `render_canary.py capture` (verdict-independent actual PNGs plus trace and image status) over a list of 216 rows: the
  standing `render_canary_tests.txt` plus every downloaded `test.swf` whose constant pool holds `BitmapData` and `draw` /
  `drawWithQuality` (51 rows across avm1, avm2, visual, from_shumway, from_gnash and regression).
- **Legs:** the `after` leg (patch) was captured first, then the `before` leg (`git apply -R` of the source diff, i.e. clean
  `origin/master`; the new fixture dirs were present in both legs), `--jobs 2`.

**Result (`render_canary.py compare before after`): 216 tests / 260 PNG comparisons.**

- **260 IDENTICAL (md5).** 0 DIFFERS, 0 APPEARED, 0 VANISHED, 0 NO_RENDER.
- **Image status changes:** none.
- **Trace status changes:** exactly the ledger:
  - `regression/avm1_bitmapdata_draw_child_color`: output_mismatch → pass
  - `regression/avm2_bitmapdata_draw_text_glyph_cx`: output_mismatch → pass
- **Every draw row:**
  - 4 avm1, 21 avm2, 3 visual, 4 from_shumway and 3 from_gnash rows keep their status and PNG md5. The from_gnash rows are
    `misc-ming.all/BitmapDataDraw`, `GradientFillTest` and `actionscript.all/BitmapData-v8`; they exercise the AVM1
    `RASTER_TRI` path most directly.
  - The 16 regression draw rows include `avm2_bitmapdata_draw_textfield`, `avm2_bitmapdata_draw_edittext_box`,
    `avm1_bitmapdata_draw_edittext`, `avm2_bitmapdata_draw_filtered`, `avm2_parent_child_*`, `avm2_timeline_*`, `avm2_morph`,
    `avm2_static_text` and `avm2_graphics_runtime`. Apart from the 2 flips, all are unchanged.
  - `avm2/graphics_draw_path` stays `ruffle_matched` in both legs.
- **Not covered:** 5 canary members were NO_RESULT in both legs because their categories were not downloaded:
  `fonts/device_font_kerning`, `fonts/embed_matching/fallback_preferences`, `text/auto_size/width`, `text/br_at_start` and
  `text/style_changes_in_html`. None of them calls `draw()`.
- **Canary list:** `render_canary_tests.txt` is unchanged. Nothing in the corpus draws an embedded-font boxed field or a
  translucent AVM1 Drawing-API child into an opaque BitmapData. The guards for both change classes are the 2 new **trace**
  fixtures with Flash goldens.
- **Fidelity:** md5 A/B only. No absolute verdict against a golden PNG is claimed, so the CI-identity check was not needed.

## Premise attacks and notes

- **Brief: "the AVM2 SWF is mxmlc-built and archived there". REFUTED.**
  - `w2-local-oracles/w2-draw-cx-text/avm2_bitmapdata_draw_text_glyph_cx/` holds only `flash.direct.txt`, and the cloud has no
    mxmlc.
  - I built a **no-mxmlc twin** instead (`create_test_swf.py`): a hand-assembled script-init ABC making the same API calls in the
    same order as `Test.as`.
  - The embedded font is copied **byte-for-byte** from the mxmlc-built `regression/avm2_bitmapdata_draw_textfield/test.swf`
    (DefineFont3 "TestFont" + DefineFontName, the same `[Embed]`). It is Flash-valid outlines, not a synthetic square-glyph font.
  - Its golden is Flash's trace of the mxmlc build. The semantics are identical, but a Flash run of *this* SWF is requested to
    retire the twin caveat (request 2).
- **"Is the device glyph drawn at all in draw()?"**
  - Flash: no solid device-glyph pixel under any tint, even at 40px bold, where a drawn glyph would certainly have solid interior
    pixels. So Flash's draw() of a device field draws no device glyphs, or draws them without a single fully-covered pixel.
  - Ours: AVM2 and AVM1 CPU draw() also draw none, so all 8 device G lines match and no change is needed.
- **The AVM1 opaque-alpha fix is scoped to opaque targets on purpose.** On a transparent target `RASTER_TRI` still overwrites
  rather than composites, which is still wrong for overlapping translucent draws. No Flash row measures it, so it is left as a
  lead (below).

## New unclaimed leads

1. **AVM1 draw() onto a TRANSPARENT BitmapData overwrites instead of compositing** (`RASTER_TRI`, gradients and solids).
   - Overlapping translucent children, or a translucent draw over existing pixels, lose the underlying colour.
   - Needs a FLASH trace: two overlapping 50%-alpha rects drawn into `BitmapData(…, true, 0x800000FF)`, `getPixel32` at the
     overlap.
   - Fix (S): reuse `bd1_tri_mark_*` with a premultiplied over.
2. **AVM1 draw() colour channels use `c*m+o` rounding, not Flash fixed-8.**
   - Only alpha on opaque targets was moved to fixed-8. Fractional multipliers (`setTransform({ra:50})`) can be off by 1 per
     channel.
   - Needs a FLASH trace of a 50% `ra` on `0xFF` red. Fix (S).
3. **AVM1 embedded EditText glyphs in draw():** the HOLD above (M).
4. **w2's lead 1 still stands:** AVM1 `Color` resolves its target by instance NAME in the native arms. The fixtures here use
   unique child names to stay clear of it.

## LOCAL ORACLE REQUESTS

1. **FLASH: `w2b-draw-text-tint-fixtures/avm1_bitmapdata_draw_text_embed_cx/`, trace, 1 frame** (`test.swf` built).
   - 8 lines: 4 `G embed …` (glyph colour under draw / draw+ct / holder>Color c>tf / holder+ct) and 4 `X embed box …`.
   - Ours today: G = `red=false green=false` ×4 (the HOLD); X = `ff0000 / ff00 / ff00 / ff00` (this patch).
   - If Flash's X lines match ours, land it as `regression/avm1_bitmapdata_draw_text_embed_cx`, either with the G lines as the
     HOLD's target or with the G lines held back.
   - Also check that Flash rendered the font at all (G line 1 `red=true`); a missing font would read all-false.
2. **FLASH: `regression/avm2_bitmapdata_draw_text_glyph_cx/test.swf` (the no-mxmlc twin), trace, 1 frame.**
   - Must equal its `output.txt`, which is the mxmlc build's Flash trace. This retires the twin caveat.
   - If it differs, the twin's ABC or font import diverges from mxmlc; replace `output.txt` with the twin's Flash trace.
