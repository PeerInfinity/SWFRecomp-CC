# w2-gfx-drawgraphicsdata — `Graphics.drawGraphicsData` + `lineBitmapStyle`

**Session 17, wave 2 (PIXEL axis). Worktree:**
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a9ac135756f7ae47d`

## NEW FILES (stage these by name — `git add -u` will drop them)

**None.** The patch touches exactly one already-tracked file:

```
SWFModernRuntime/src/avm2/avm2_display.c | 652 insertions(+), 120 deletions(-)
```

The two deliverables themselves are new files under
`SWFRecompDocs/plans/session17-fanout-reports/`:

- `w2-gfx-drawgraphicsdata.patch`  (the single-file `git diff`)
- `w2-gfx-drawgraphicsdata-report.md` (this file)

No second patch: `lineBitmapStyle` shares the stroke-style plumbing with
`drawGraphicsData`'s `GraphicsStroke` arm, so splitting them would produce two
patches that do not apply independently.

---

## VERDICT — **GO**

| | |
|---|---|
| **Flips delivered (local, `--mode=graphics`)** | **1** — `avm2/graphics_bad_direct_commands` `6390 → 0` outliers, byte-exact at `tolerance 1 / max_outliers 0` |
| **Band moves** | `graphics_bitmap_fill` **76 870 → 194** (−99.75 %), `graphics_gradients` **3338 → 492** (−85 %), `graphics_direct_commands` **2568 → 587** (−77 %), `graphics_draw_path` **764 → 204** (−73 %), `graphics_draw_triangles` **2512 → 1812** (−28 %), `graphics_bitmaps` **40 588 → 37 650** (−7 %) |
| **Regressions** | none in the graded set (see canary table) |
| **Trace** | all 10 graded `avm2/graphics_*` tests still `PASS`; `graphics_path` (trace-only) unchanged |
| **Local ⇄ CI fidelity** | **exact** — every "before" number measured locally reproduced the merged CI number from run `31877239992` to the digit (76 870 / 40 588 / 6390 / 2568 / 764 / 2512 / 3338 / 600 / 240). The A/B below is therefore CI-faithful for this family. |

---

## What was actually broken (three defects, not one)

The brief said `drawGraphicsData` "walks the Vector to raise #2004/#2008 and
draws nothing". True — but it was the *third* of three layers, and the first
two had to be fixed for it to be reachable at all.

1. **The `IGraphicsData` carrier classes had no constructors.**
   `GraphicsSolidFill`, `GraphicsGradientFill`, `GraphicsBitmapFill`,
   `GraphicsStroke` and `GraphicsShaderFill` were registered by
   `avm2_graphics_register` as argument-less non-sealed shells
   ("*No ctor needed*" in the old comment). So
   `new GraphicsBitmapFill(bmd, mtx)` stored **nothing**, and even a perfect
   dispatcher would have read `undefined` for every style field. Each class now
   stores its arguments under the property names playerglobal declares
   (`Ruffle core/src/avm2/globals/flash/display/Graphics*.as`), with the AS3
   defaults (`thickness = NaN`, `repeat = true`, `smooth = false`,
   `miterLimit = 3`, `caps = "none"`, `joints = "round"`,
   `scaleMode = "normal"`, `spreadMethod = "pad"`,
   `interpolationMethod = "rgb"`, `type = "linear"`).
   `describeType` is table-driven (`dtd_*`), so the `all_classes/display/*`
   expectations are untouched by this.

2. **`lineBitmapStyle` / `lineGradientStyle` *cleared* the stroke.**
   Both were bound to `gfx_line_fill_style`, a stub whose body is
   `gfx_finalize_path(g); g->cur_line = 0;`. Ruffle's
   `Drawing::set_line_fill_style` **replaces the fill of the current line
   style** and is a **no-op when no line style is active** — it never clears the
   stroke. So every bitmap/gradient stroke in the corpus was actively deleted by
   the very call that was supposed to style it.

3. **`drawGraphicsData` was validation-only.** Now a full
   `handle_igraphics_data` mirror.

### Mechanism, as landed

* New `Avm2GfxStyle` value type: a stroke's own fill style (kind `0` legacy
  solid → the path's `lr/lg/lb/la`, `2` gradient, `3` bitmap). It rides on
  `Avm2GraphicsExt.clsty` (current) and `Avm2GfxPath.lsty` (snapshotted at
  finalize, with the pixel buffer deep-copied and freed by `gfx_free_path`).
  `lineStyle()` resets it, matching Ruffle's "a new `LineStyle` drops the old
  fill".
* `avm2_render_graphics` and `avm2_graphics_cpu_composite` gained a stroke
  dispatch mirroring the fill dispatch (`renderer_draw_gradient_tris` /
  `renderer_draw_bitmap_tris` / solid). No new renderer entry point, so
  `render_stub.c` / NO_GRAPHICS parity is automatic — both macros already exist
  in both headers.
* `gfx_begin_fill` / `gfx_begin_gradient_fill` / `gfx_begin_bitmap_fill` were
  refactored into **value-tuple cores** (`gfx_set_solid_fill`,
  `gfx_build_gradient_style`, `gfx_build_bitmap_style` + `gfx_commit_*`), so the
  `GraphicsSolidFill` / `GraphicsGradientFill` / `GraphicsBitmapFill` carriers
  and `lineGradientStyle` / `lineBitmapStyle` run **the same code path** the
  method form runs. Nothing about the method form's behaviour changed (proved
  by `graphics_gradients_nulls` and `graphics_simple_shapes` being
  bit-for-bit unmoved).
* `gfx_draw_graphics_data` now dispatches, in Ruffle's own order and with its
  error cases: `GraphicsBitmapFill`, `GraphicsEndFill`, `GraphicsGradientFill`,
  `GraphicsPath`, `GraphicsSolidFill`, `GraphicsShaderFill` (→ clear the fill,
  as Ruffle does), `GraphicsStroke` (thickness `NaN` → no stroke; otherwise
  clamp to `[0,255]`, default `swf::LineStyle::default()`'s **opaque black**,
  then apply its `fill` through `handle_igraphics_fill`), `GraphicsTrianglePath`.

### The fourth defect the brief did not name: **the fill rule**

`Ruffle`'s runtime `Drawing::new()` sets `default_winding_rule: FillRule::EvenOdd`
(`core/src/drawing.rs:47`), and `process_commands` brackets a `drawPath` /
`GraphicsPath` with `set_fill_rule(Some(rule)) … set_fill_rule(None)` — and
`set_fill_rule` goes through `new_fill`, i.e. the commands land in a **subpath of
their own**. Our tessellator hard-coded `TESS_WINDING_NONZERO` for every AVM2
`Graphics` fill and ignored the `winding` argument entirely.

`Avm2GfxPath.winding` now carries the rule per subpath (`0` evenOdd default,
`1` nonZero), `drawPath` and `GraphicsPath` bracket their commands the way
Ruffle does, and `tessTesselate` picks `TESS_WINDING_ODD` / `TESS_WINDING_NONZERO`.
**This is what flips `graphics_bad_direct_commands` and moves
`graphics_direct_commands`, `graphics_draw_path`, `graphics_gradients` and
`graphics_draw_triangles`** — every one of those draws a self-intersecting
star or overlapping subpaths under one fill.

### Fifth, found while reading: `gfx_new_fill_path` dropped the bitmap fill

`drawTriangles` / `GraphicsTrianglePath` snapshot the current style through
`gfx_new_fill_path`, which copied the solid and gradient fields but **not** the
bitmap ones — so an explicit triangle list under `beginBitmapFill` recorded
`fill_kind 3` with a `NULL` pixel pointer and the renderer's
`p->bmp_px != NULL` guard silently dropped it. Fixed (no corpus row exercises
it today; it is a latent blank-render).

---

## Ledger — per-row before/after (local, `--mode=graphics --images --verbose`)

`before` = the unpatched tree (a pristine copy of the worktree with the patch
reverted, so both legs are the same machine, same Dawn, same test data).

| row | tolerance / max_outliers | before | after | Δ | verdict |
|---|---|---|---|---|---|
| `avm2/graphics_bad_direct_commands` | 1 / 0 | 6390 | **0** | −6390 | **FLIP (image PASS)** |
| `avm2/graphics_bitmap_fill` | 5 / 60 | 76 870 | **194** | −99.75 % | no flip — residual named below |
| `avm2/graphics_gradients` | 0 / 0 | 3338 | **492** | −85 % | no flip (`max_outliers 0`) |
| `avm2/graphics_direct_commands` | best rung 64 / 300 | 2568 | **587** | −77 % | no flip |
| `avm2/graphics_draw_path` | 0 / 0, test `known_failure` | 764 | **204** | −73 % | no flip |
| `avm2/graphics_draw_triangles` | 0 / 0, cmp `known_failure` | 2512 | **1812** | −28 % | no flip |
| `avm2/graphics_bitmaps` | best rung 32 / 600 | 40 588 | **37 650** | −7 % | no flip — residual named below |
| `avm2/graphics_gradients_nulls` | 0 / 0 | 600 | 600 | 0 | untouched (as intended) |
| `avm2/graphics_simple_shapes` | 0 / 0 | 240 | 240 | 0 | untouched (as intended) |
| `avm2/graphics_path` | trace only | PASS | PASS | — | no trace regression |

Every row's **trace** verdict is `PASS` before and after.

### Residual mechanisms, named

**`graphics_bitmap_fill` — 194 left (needs ≤ 60), two causes, neither mine.**
A pixel-level census of the diff (`an.py`/`an2.py` in the scratchpad) puts
**100 %** of the residual in the two *stroke* quadrants, zero in the two fill
quadrants:

* **28 px — miter vs round joins.** AS3 `Graphics.lineStyle(5)` defaults
  `joints = "round"` and `GraphicsStroke` defaults `joints = "round"`; Ruffle
  honours them (`joints_to_join_style`). Our `gfx_build_stroke` emits
  miter/bevel joins only. At half-width 2.5 px a miter tip reaches 3.54 px
  diagonally out of the corner where a round join reaches 2.5 px — exactly the
  4–6 outliers seen at each of the 8 stroked-rect corners.
  *Completion mechanism:* round joins + round caps in `gfx_build_stroke`
  (and its AVM1 twin `drawingBuildStroke`), driven by the `caps`/`joints`
  fields the carriers now already store. Broad blast radius — its own A/B.
* **44 px — the dynamic-bitmap layer's tiling period.**
  `render_webgpu_draw_bitmap_tris` pre-tiles the source across the whole padded
  `bitmap_highest_w+1 × bitmap_highest_h+1` layer and records
  `content = {bw-1, bh-1}`, so the repeat period is the *layer*, not `src_w/src_h`.
  For the stroke rows *above* the rect (negative bitmap Y) the sample crosses
  that seam and lands on the wrong texel. The in-tree comment
  (`render_webgpu.c:2816-2823`) already names this and calls the fix
  "a separate patch with its own A/B".

**`graphics_bitmaps` — 37 650 left (needs ≤ 600), one dominant cause.**
Ink is now essentially correct (**our 68 703 vs Ruffle's 68 333** non-white
pixels — the three missing stroke groups are drawn), but 13 566 of the
tolerance-32 outliers sit inside `logo_fill`'s **second** rect
(`beginBitmapFill(logo, scale(0.5), repeat = true, smooth = true)`, screen
x 200–400 / y 150–350). It is **not** a translation — a ±6 px shift search finds
its optimum at `(0,0)` — it is the same **layer-period tiling seam** as above,
amplified because that rect tiles a 200×200 source at 0.5 into a 200×200 box.
*Completion mechanism:* upload `src_w × src_h` and set `content = {src_w, src_h}`
in `render_webgpu_draw_bitmap_tris`, with the clipped arm clamped to `content`.

**`graphics_direct_commands` — 587 left (needs ≤ 300).** Not a
drawGraphicsData row at all: it uses `copyFrom`, `drawRoundRect` (we
approximate the corner radii away — `gfx_draw_round_rect` is `gfx_draw_rect`),
and `cubicCurveTo`. The winding fix took it from 2568 to 587; the rest is
round-rect geometry + stroke joins.

**`graphics_gradients` / `graphics_simple_shapes` / `graphics_gradients_nulls`
are `max_outliers = 0` rows** — the s16 lesson ("a diff-line lead is not a flip
lead") applies verbatim: `graphics_gradients` improved 85 % and still cannot
flip.

---

## RIDER (coordinator, wave-1 lead P6): AVM2 `beginBitmapFill`'s `smooth` — **REFUTED, already implemented**

The board's P6 says `smooth` is "parsed and thrown away" and that
`graphics_bitmaps`' "**558 vs 759 distinct colours**" is the nearest-vs-linear
signature. Both halves are wrong for the AVM2 `Graphics` route:

1. **The flag is wired end to end, and has been since s16.**
   `gfx_begin_bitmap_fill` → `g->cbsmo` → `gfx_finalize_path` →
   `Avm2GfxPath.bmp_smooth` → `avm2_render_graphics` passes it as the `smooth`
   argument of `renderer_draw_bitmap_tris` →
   `render_webgpu_draw_bitmap_tris` (`render_webgpu.c:2873`)
   `u32 sx_word = render_webgpu_bitmap_fill_style_word(repeat, smooth);` →
   fill type `0x40`/`0x41` → the fragment shader's
   `textureSampleLevel(bitmap_tex, bitmap_samp_linear, …)` arm
   (`render_webgpu.c:286-298`). The board's citation
   (`render_webgpu.c:2702-2708`, hard-coded `(0,0)`) is
   **`render_webgpu_draw_bitmap_quad_scaled`** — the `attachBitmap` / `Bitmap` /
   video-fallback path, which the board itself prices at **0 pixels**.
   The only thing that *was* stale is the **comment** in
   `gfx_begin_bitmap_fill` claiming the renderer ignores the flag; this patch
   deletes it.
2. **Measured, per region, on the patched tree** (`an4.py`):

   | region | ours | Ruffle |
   |---|---|---|
   | whole image | **702** | 759 |
   | `logo_fill` rect A — `smooth = false` | **53** | 53 |
   | `logo_fill` rect B — `smooth = true`, scale 0.5, repeat | **114** | 112 |
   | `simple_shapes_fill` band | 396 | 424 |
   | `simple_shapes_stroke` band | 472 | 517 |

   A nearest-sampled region cannot produce 114 distinct colours from a
   53-colour source: **we are already interpolating**. The whole-image count
   moved 558 → 702 with *this* patch and no sampler change at all — i.e. the
   board's colour deficit was **the three missing `lineBitmapStyle` stroke
   groups**, not the sampler.

**No `w2-gfx-bitmapfill-smooth.patch` is delivered, deliberately.** The real
lead hiding under P6 is the *layer tiling period* described above; it owns
graphics_bitmaps' remaining 37 650 and part of graphics_bitmap_fill's 194.
Priced: 0–1 flips (`graphics_bitmaps`), one large band move. Owner:
`render_webgpu_draw_bitmap_tris`.

---

## Canary

Standing set (`ruffle-tests/render_canary_tests.txt`, 25 tests) **plus the two
additions the wave-1 board asked for** — `from_shumway/acid/acid-bitmap-fill`
and `acid-bitmap-fill-2` — **plus** `avm2/graphics_bitmap_fill` and
`avm2/graphics_bitmaps` as the change class's own covering rows.

**Bar: md5 identity** (local Dawn is byte-deterministic). Two legs, both on
this machine: `before` = the pristine (patch-reverted) copy, `after` = the
patched worktree. **54 of 56 comparisons IDENTICAL; the only two that DIFFER
are the two rows this patch is supposed to move.** No trace output changed on
any member.

| test | cmps | before md5 (first cmp) | after md5 | verdict |
|---|---|---|---|---|
| `avm1/color` | 1 | `44a2ebac` | `44a2ebac` | IDENTICAL |
| `avm1/bitmap_data_fillrect` | 1 | `c2626aa5` | `c2626aa5` | IDENTICAL |
| `avm1/mask_with_drawing` | 1 | `c19e92c7` | `c19e92c7` | IDENTICAL |
| `avm1/movieclip_setmask` | 1 | `0ca5d413` | `0ca5d413` | IDENTICAL |
| `avm1/edittext_tag_indent` | 1 | `93bfd4a5` | `93bfd4a5` | IDENTICAL |
| `avm1/focusrect_swf5` | 12 | `d4140261` | `d4140261` | IDENTICAL |
| `avm1/bitmapdata_applyfilter_colormatrix` | 1 | `c5c7ecd1` | `c5c7ecd1` | IDENTICAL |
| `avm2/blend_multiply_alpha` | 1 | `191f3bcc` | `191f3bcc` | IDENTICAL |
| `visual/filters/glow_pass_scaling` | 1 | `94dd9e23` | `94dd9e23` | IDENTICAL |
| `visual/cache_as_bitmap/masks` | 7 | `01f2fcb4` | `01f2fcb4` | IDENTICAL |
| `visual/simple_shapes/winding_rule` | 1 | `c1cef7ca` | `c1cef7ca` | IDENTICAL |
| `visual/cache_as_bitmap/shape_changed` | 1 | `f7b0c91b` | `f7b0c91b` | IDENTICAL |
| `from_shumway/timeline/timeline_as2_5` | 7 | `96adf09a` | `96adf09a` | IDENTICAL |
| `from_shumway/acid/acid-gradient-0` | 1 | `e8d2dbfc` | `e8d2dbfc` | IDENTICAL |
| `regression/avm2_timeline_stroke_gradient` | 1 | `c8ade16d` | `c8ade16d` | IDENTICAL |
| `regression/avm2_timeline_gradients` | 1 | `b1621d75` | `b1621d75` | IDENTICAL |
| `regression/mask_sibling_union` | 1 | `26d21480` | `26d21480` | IDENTICAL |
| `regression/mask_nested_intersect` | 1 | `8a4ca41f` | `8a4ca41f` | IDENTICAL |
| `visual/simple_shapes/masks` | 1 | `4916fcb7` | `4916fcb7` | IDENTICAL |
| `visual/simple_shapes/gradients/gradients` | 1 | `d6025108` | `d6025108` | IDENTICAL |
| `visual/filters/drop_shadow` | 1 | `3b46c880` | `3b46c880` | IDENTICAL |
| `visual/filters/color_matrix` | 1 | `de055336` | `de055336` | IDENTICAL |
| `visual/blend_modes/multiply` | 1 | `8c077f83` | `8c077f83` | IDENTICAL |
| `regression/avm2_morph` | 1 | `d2fe8a7b` | `d2fe8a7b` | IDENTICAL |
| `from_shumway/acid/acid-blend-2` | 5 | `af53d0f4` | `af53d0f4` | IDENTICAL |
| `from_shumway/acid/acid-bitmap-fill` | 1 | `d520a5dc` | `d520a5dc` | IDENTICAL |
| `from_shumway/acid/acid-bitmap-fill-2` | 1 | `408052b5` | `408052b5` | IDENTICAL |
| `avm2/graphics_bitmap_fill` | 1 | `048780f6` | `9519771c` | **DIFFERS** |
| `avm2/graphics_bitmaps` | 1 | `a377bb7a` | `5a7a68b9` | **DIFFERS** |

54/56 comparisons IDENTICAL

### Canary blind spots (s15 rule)

- The standing set has **no AVM2 runtime-`Graphics` member with a bitmap or
  gradient stroke, and no member that exercises the AVM2 `Graphics` fill rule
  at all.** Both are precisely what this patch changes. The covering rows I
  graded by hand are the ten `avm2/graphics_*` rows in the ledger above.
- `from_shumway/acid/acid-bitmap-fill` / `-2` cover *static SWF-tag* bitmap
  fills, i.e. the `render_webgpu_draw_bitmap_tris` consumer, not the AVM2
  producer — they are the right canary for the tiling-seam follow-up, less so
  for this patch.
- Nothing in the standing set uses `drawPath` / `drawTriangles` /
  `drawGraphicsData`, so the *trace* canary for this change class is the ten
  headline rows (all `PASS`).

---

## Risk statement for the merge

The one change with a blast radius beyond `drawGraphicsData`/`lineBitmapStyle`
is the **evenOdd fill-rule default for AVM2 `Graphics`**. It cannot affect:
AVM1 drawing (`action.c`, untouched), SWF-tag shapes (recompiler path,
untouched), or any AVM2 `Graphics` drawing whose subpaths do not overlap
(evenOdd ≡ nonZero there). It *can* change any AVM2 script that draws
overlapping or self-intersecting subpaths under a single `beginFill`, which is
exactly the set the corpus rows above measure — and every one of them improved
or stayed identical. If a merge-time canary shows an unexpected DIFFERS, the
rule change is isolated to three places (`Avm2GfxPath.winding`,
the `tessTesselate` argument, and the two `cur_winding` brackets) and can be
reverted to `1` (nonZero) without touching anything else in the patch.

### Memory footprint (flagged, not measured on a game)

`Avm2GfxStyle` is ~1.17 KB (it carries a 256x4 ramp), and it is embedded **by
value** in both `Avm2GraphicsExt` (one per `Graphics` object) and `Avm2GfxPath`
(one per finalized subpath). Both structs already carried a 1 KB ramp, so this
roughly doubles them: ~1.3 KB -> ~2.5 KB per Graphics object and per subpath.
For the corpus that is irrelevant; for an AVM2 game with thousands of Shapes it
is a few MB. If `avm2-browser-footprint` cares, the drop-in fix is to make both
fields `Avm2GfxStyle*`, heap-allocated on the first non-solid stroke and NULL
otherwise -- the accessors are already funnelled through `gfx_commit_line_style`
/ `gfx_free_path`, so it is a contained change. Left by value here so the
measured patch is the delivered patch.

## Reproduce

Scratchpad (private): `<session scratchpad>/w2dgd/`
- `patch1.py … patch7.py` — the exact edits, each with a uniqueness assertion
- `pristine/` — the unpatched copy used for the `before` leg
- `headline_before/`, `headline_after/` — per-row verify_output logs
- `an.py … an5.py` — the pixel censuses quoted above
- `canary_ext.txt` — the extended canary list

## Method note worth a standing rule

`render_canary.py` has its **own** per-test timeout, `TIMEOUT_DEFAULT = 900`
(`render_canary.py:136`), which is *independent of* `SWFRECOMP_COMPILE_TIMEOUT`.
Under s17 fan-out load (load average 20–30) it manufactured `NO_RESULT` rows on
the standing set — the render-canary equivalent of the s16 `compile_fail`
trap, and it looks like a tool error rather than a false failure. **Always pass
`--timeout 5400` alongside `export SWFRECOMP_COMPILE_TIMEOUT=2400`.**
