# w1-gfx-fill — wave-1 pixel diagnosis: `same_geometry_wrong_fill` (+ non-video
# `unrelated_content`, `global_color_shift`)

Read-only wave. Board: `wave0-image-board.md`, `image_triage.json` (run
`33857494837` at `659153865`). Scratch:
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-fill/`
(probe/attrib/crop/montage scripts + a private recompile-only tree `rc/` — the
recompiler was run on COPIES of six SWFs in scratch, never in the shared test
dirs).

**Disposition check (rule 2): NONE of the 26 live rows in my three clusters has an
entry in `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
`RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md`, the global
`ignored_tests.txt`, or the `avm2`/`visual`/`from_shumway` suite ignore lists.**
(`avm2/bitmapdata_applyfilter_blur` is the one dispositioned row and the board
already excludes it; `avm2/graphics_draw_path` carries a suite-local trace ignore
only.) Nothing here is pre-empted.

---

## 0. Verdicts, ranked by evidence strength × price

Every number below is **outlier channels at the test's own chosen check**
(re-derived from `test.toml` + the two PNGs; matches the CI JSON exactly for all
26 rows).

| # | verdict | test | now → predicted | mechanism (one line) | owner file |
|---|---|---|---:|---|---|
| **A1** | **GO — +1 flip, high confidence** | `avm2/displayobject_blendmode` | 62 400 → **0** | AVM2 render walk has **no blend arm at all**; `DisplayObject.blendMode` only writes a `__blendMode` dyn prop that nothing reads | `avm2_display.c` |
| **A2** | **GO — +1 flip, ONE token** | `avm2/edittext_always_show_selection` | 432 → **0** | unfocused selection fill is `0x808080`; Ruffle's `Color::GRAY` is `0x555555` | `avm2_text.c:3859` |
| **A3** | **GO — +1 flip, high confidence** | `from_shumway/acid/acid-filter-2` | 16 764 → **~0** | the object's **colour transform is not applied to the filter OUTPUT**, only to the source | `tag.c::render_filtered_object` |
| **A4** | **GO — +1 flip, ~10 LOC** | `avm2/bitmapdata_draw_self_via_graphic` | 7 500 → **0** | `BitmapData.draw` src-over does not **accumulate destination alpha** (`aOut = as + ad(1−as)`) | `avm2_bitmap.c` |
| **A5** | **GO — +1 flip (arithmetic checked), AA risk** | `from_shumway/acid/acid-morph` | 4 311 → **~2 200** (budget 2 600) | a 1-px green stroke lands on a **half-pixel phase** (2 rows at exactly 128/255 each) | stroke rasterisation |
| **B1** | **GO — 94 % band move, flip uncertain** | `visual/cache_as_bitmap/avm2_button` | 4 432 → **~278** | RECOMPILER: `tagSetOpaqueBackground` is emitted at **one** site (root arm); the DefineSprite arm drops it | `SWFRecomp/src/swf.cpp:4805` vs `:6234` |
| **B2** | **GO — 97 % band move, 2-px tie left** | `avm2/graphics_draw_path` | 204 → **6** | `drawPath` **aborts on a NaN coordinate** instead of coercing NaN→0 and continuing | AVM2 Graphics `drawPath` |
| **B3** | **DIAGNOSE-then-GO** | `visual/cache_as_bitmap/nested_rotation` | 25 665 → 0 or 25 665 | a descendant's runtime `_rotation` never reaches the screen inside a cacheAsBitmap subtree — cache not invalidated by a DESCENDANT change (or `_rotation` on a named sprite child is a no-op) | discriminator in §B3 |
| **B4** | **DIAGNOSE** | `visual/drawing_api/drawing_order` | 6 664 → ? | AVM1 runtime `lineStyle`/`moveTo`/`lineTo` strokes render **nowhere** — neither the bare-call (root) form nor the `mc.` form | AVM1 drawing API |
| **C1** | **HOLD (arc)** | `visual/blend_modes/layer_alpha`, `layer_erase` | 66 762 + 66 967 | **layer groups are not implemented** — stated verbatim in `render_webgpu.c:4394` ("we have no layer groups yet"); ALPHA/ERASE draw as NORMAL | `render_webgpu.c` + both render walks |
| **C2** | **HOLD (text-layout owner)** | `avm2/edittext_get_{line,char}_index_at_point` | 18 403 + 22 849 | line-band boundaries differ; **the traces PASS**, so this is layout geometry, not the API's return values | `avm2_text.c` layout |
| **C3** | **DIAGNOSE (small, sharp)** | `visual/filters/color_matrix` | 237 → 0? | NOT a colour rule: one element's **bottom-right rounded corner** is a flat 10-px-short stub (79 px) + 2 px at the top | shape/round-corner geometry |
| **C4** | **DIAGNOSE (small, sharp)** | `avm2/graphics_simple_shapes` | 240 | `drawRoundRect` corner **radii unimplemented** (s17 already named it inside `acid-shapes`) | AVM2 Graphics |
| **C5** | **DIAGNOSE** | `avm2/bitmapdata_draw_masks` | 5 850 | `BitmapData.draw` ignores the source's `.mask` (2 colour pairs, no AA) | `avm2_bitmap.c` draw walk |
| **C6** | **DIAGNOSE** | `avm2/bitmapdata_copypixels`, `from_shumway/acid/acid-bitmapData-copyPixels` | 25 200 + 53 760 | alpha-source `copyPixels`: measured `expected = 0.733·actual + 36` in the affected cells ⇒ we write the source **opaque** where Ruffle honours `alphaBitmapData` | `avm2_bitmap.c` |
| **D1** | **NO-GO for this session** | `avm2/pixelbender_effect_glassDisplace_shaderfilter` (879 464), `avm2/away3d_advanced_shallow_water_demo` (1 331 169) | — | Pixel Bender / Stage3D backends (s17 M1/M2, PARKED) | — |
| **D2** | **PRICE ONLY (`known_failure`)** | `avm2/bitmapdata_draw_filters` (14 400), `visual/blend_modes/shader_as_mask` (2 100), `avm2/bitmapdata_applyfilter_destpoint_edges` (169 250) | — | `draw_filters` is a clean uniform **G↔B swap** (7 200 px, one pair) — cheapest of the three, but the row is a Ruffle `known_failure` | — |

**Total priced flips this brief: 5 confident (A1–A5) + 2 probable band-to-flip
(B1, B2) + 1 conditional (B3).**

---

## 1. The five GO leads, with evidence

### A1 — `avm2/displayobject_blendmode`: the AVM2 renderer has no blend arm (62 400 → 0)

The brief filed this as "blend math". It is not math; **the AVM2 walk never asks
the renderer for a blend at all.**

Decoded the test out of `RecompiledABC/abc0_methods.c` (no `Test.as` in the
mirror). It draws a background plus six rects via `addRect(x, y, color, blendMode,
alpha[, side])`:

| rect | colour | blend | alpha | expected | ours |
|---|---|---|---|---|---|
| (0,0) 80×80 | `0x440044` | **ADD** | 0.9 | (188, 42, 169) | (74, 4, 72) |
| (100,0) | `0x440044` | **ADD** | 0.5 | (161, 42, 142) | (98, 21, 88) |
| (0,100) | `0xE1E854` | NORMAL | 0.9 | (215, 213, 86) | (216, 213, 87) ✅ |
| (10,110) 40×40 | `0xAAAAAA` | **ADD** | 0.3 | (255, 255, 137) | (203, 201, 112) |
| (100,100) | `0xD5D5F7` | **ADD** | 0.1 | (148, 63, 132) | (137, 60, 123) |
| (110,110) 40×40 | `0xFF0000` | **ADD** | 0.3 | (224, 63, 132) | (172, 42, 86) |

Backdrop is (127, 42, 108). Arithmetic, exact to the unit:

* Flash ADD with premultiplied source: `dst + 0.9·(68,0,68)` = `(127+61, 42, 108+61)` = **(188, 42, 169)** = expected.
* NORMAL: `0.9·(68,0,68) + 0.1·(128,43,109)` = **(74, 4, 72)** = ours.
* Same identity holds for the 0.5 rect (161/98) and the NORMAL control row passes.

So **every ADD rect is rendered as NORMAL**, and the one NORMAL rect already
matches. Confirmed in source, not just by arithmetic:

* `avm2_display.c:11896-11939` — `do_blendmode_get/set` store the name in a
  `__blendMode` dont-enum dynamic property.
* `grep -rn "__blendMode" SWFModernRuntime/src` outside `avm2_display.c` → **zero
  hits**. Nothing reads it.
* `renderer_blend_mode_is_layered` / `renderer_capture_backdrop` /
  `renderer_composite_blend` / `renderer_set_blend_mode` are called from
  **`tag.c` only** (`:4048, :6554-6584, :7565-7610`). `avm2_render_node`
  (`avm2_display.c:18262`) has no blend arm.
* The tag side works: `avm2/blend_multiply_alpha`, `blend_scroll`,
  `blend_transform` all pass with 0 outliers — those carry the blend on the
  PlaceObject3 tag, which reaches `Avm2TimelineOp.blend_mode` → the display
  entry.

**Fix shape**: give `avm2_render_node` the arm `tag.c:6554-6584` already has,
sourced from a numeric blend cached on the display ext when
`do_blendmode_set` runs (the tag→name direction already exists at
`avm2_display.c:1844`). ~70–90 LOC in `avm2_display.c`; no renderer change.
**Tolerance note that makes this a clean flip**: 14 400 px are off by exactly +1
in all channels (the background) and 4 800 by +1 in R/B — the test's tolerance is
1, so those are already free. The 62 400 outliers are *exactly* the five ADD
regions (6 400+6 400+4 800+1 600+1 600 px × 3 ch). Fix ADD and the count is 0.

**Canary**: `avm2/blend_multiply_alpha` (tier 1, tol 0),
`visual/blend_modes/multiply` + `from_shumway/acid/acid-blend-2` (tier 2). Add
`avm2/blend_scroll` and `avm2/blend_transform` (both pass at tol 0) for the run.

---

### A2 — `avm2/edittext_always_show_selection`: one wrong constant (432 → 0)

Single colour pair, 144 px, no AA: expected `(85,85,85)`, ours `(128,128,128)`.

```
SWFModernRuntime/src/avm2/avm2_text.c:3859
    *out_color = focused ? 0x000000u : 0x808080u;
```

Ruffle `core/src/display_object/edit_text.rs:1188-1192` uses `Color::GRAY`, and
`swf/src/types/color.rs:34` defines `pub const GRAY: Self = Self::from_rgb(0x555555, 255)`.
The comment four lines above our line already says "`Color::GRAY` otherwise" —
the constant was mis-transcribed. `0x808080` appears exactly once in the whole
runtime, so there is no second site.

tolerance 0 / max_outliers 0 and this is the **only** differing pair in the
image ⇒ deterministic flip.

**Canary**: nothing in the standing set covers EditText selection.
`avm1/edittext_tag_indent` + `visual/edittext/edittext_border_transform` are the
nearest; a wave-2 agent should state that gap.

---

### A3 — `from_shumway/acid/acid-filter-2`: the cxform must be applied to the FILTER OUTPUT (16 764 → ~0)

The board reads this as `same_geometry_wrong_fill`. It is one rule, and the
evidence is unusually tight.

**100 % of the outliers obey `expected = (255, v, v)` while ours is `(v, v, v)`**
(8 848 exact + 5 494 with a ±1 on the same rule; scripted check in
`scratchpad/w1-gfx-fill/`). Sampling the vertical profile through the ellipse's
glow at x=105:

```
y    expected        ours
33   (255,233,233)   (234,234,234)
39   (255,207,207)   (207,207,207)
49   (255,156,156)   (156,156,156)
```

**The G/B falloff is byte-identical** — our blur radius, strength and profile are
right. Only the colour of the halo is wrong: Ruffle's halo is RED, ours is
neutral.

Why: I parsed the SWF's `PlaceObject3` (depth 1) by hand —

```
flags1=0x0e (HasMatrix|HasCharacter|HasColorTransform)  flags2=0x01 (HasFilterList)
CXFORMWITHALPHA: hasAdd=1 hasMult=0 nbits=9  add=[+255, 0, 0, 0]
filters: count=2 -> [Glow  rgba=00 00 00 ff (BLACK), blurX=blurY=50.0, strength=1.0, flags=0x21],
                    [Blur 4.0/4.0]
```

The shape is dark; the **cxform's `+255` on red** is what makes it red. Ruffle
renders the object into the filter texture with an identity colour transform,
runs the filter chain, then draws the result **with** the object's colour
transform — so the black glow becomes red too. We apply the cxform to the source
before filtering, so the source is red and the glow stays black.

**Fix shape**: in `tag.c::render_filtered_object` (`:3846`), render the source
into the offscreen with an identity cxform and apply the object's cxform when
compositing the filter output back. Mirror it in `avm2_display.c::avm2_render_filtered`
(`:17954`) — the AVM2 route has the same structure.

**Residual after the fix should be ~0**: the only reason the outliers exist is
the R channel; with the cxform applied the profile matches to the byte (the ±1s
are inside tolerance 20).

**Blast radius / canary**: every filtered object that also has a colour
transform. Standing set has `visual/filters/{drop_shadow,color_matrix}` (tier 2),
`visual/filters/glow_pass_scaling` + `avm1/bitmapdata_applyfilter_colormatrix`
(tier 1), `avm1/color` (cxform). **Recommended addition:
`from_shumway/acid/acid-filter`** — it is the direct sibling, currently 482
outliers at tol 4 (`hairline_edge_drift`, NOT this bug: its residual is
edge-drift pairs, checked), so it is a sharp guard against a regression here.

---

### A4 — `avm2/bitmapdata_draw_self_via_graphic`: destination alpha is not accumulated (7 500 → 0)

Test (`Test.as`): `BitmapData(100,100,true,0xA0A0A0A0)`, a `Bitmap` of it inside a
MovieClip, then `bmd.draw(mc, translate(50,50))` — i.e. the bitmap drawn onto
itself, offset. Exactly one colour pair over the 50×50 overlap at (50,50):
expected `172`, ours `195`, alpha untouched.

8-bit premultiplied arithmetic:

```
src = dst = (160,160,160, a=160)        premul (100,100,100,160)
Porter-Duff over:  rgbP = 100 + 100·(95/255) = 137
                   a    = 160 + 160·(95/255) = 220
unmultiply -> stored (159,159,159,220)
composited over the white stage: 137 + 255·(1 − 220/255) = 172   ✅ expected
alpha LEFT AT 160 instead:       100 + 255·(1 − 160/255) = 195   ✅ ours
```

The colour is a fixed point here (src == dst), so the *only* observable is the
alpha term. We leave the destination alpha at the source's value instead of
`aOut = as + ad·(1 − as)`.

tolerance 0, one pair, no AA anywhere else in the image ⇒ deterministic flip.

**Guards (all currently PASSING at tol 0/1, so they carry absolute verdicts)**:
`avm2/bitmapdata_draw_alpha_erase`, `avm2/bitmapdata_draw_colortransform`,
`avm2/bitmapdata_draw_cpu_overwrite_gpu`, `avm2/bitmapdata_draw_stage`,
`avm1/bitmap_data_copypixels`, `visual/bitmapdata_copypixels_with_alpha_oob`.
Related row that may also move: `avm2/bitmapdata_draw` (24 585 / budget 600).

---

### A5 — `from_shumway/acid/acid-morph`: a 1-px green stroke on a half-pixel phase (4 311 → ~2 200, budget 2 600)

Checks are `[(tol 5, max_out 5600), (tol 64, max_out 2600)]`; CI picks the second,
so the budget is 2 600 and the excess is 1 711.

Outlier-channel attribution (scripted, at tol 64):

| region | outlier channels |
|---|---:|
| gradient rect + its green 1-px border (x330-530, y280-386) | 2 369 (border-green 1 057 + white side 1 312) |
| green capsule outline | 606 |
| the two morph polygons (blue / gold) | 1 126 |
| rest | 210 |

The border pairs are **exactly** `(0,255,0) → (128,255,128)` (1 136 ch) and
`(255,255,255) → (128,255,128)` (1 046 ch) — a hairline stroke that should sit on
one pixel row is split 50/50 across two rows. That is a half-pixel phase, not
"antialiasing noise". Removing it takes 4 311 → ~2 150–2 200, **under the 2 600
budget ⇒ flip.**

**Attack on my own pricing**: the `hairline stroke pixel-snapping` family has an
ACCEPTED_DIFFS entry (gnash `simple_loop_test`) and has burnt sessions before.
What is different here is that the split is *exactly* 128/255 on both sides —
a deterministic half-pixel offset, not a coverage tie. A wave-2 agent should
confirm that before committing: if the fix moves the stroke a full pixel instead,
the count does not drop.

The remaining 1 126 channels on the morph polygons are a **separate** rule
(systematic −9…−11 on R and G of the gold gradient across 1 190 pairs) — a morph
gradient-lerp/ratio rounding, adjacent to s16's `morph_lerp_color_u8`. Not needed
for the flip; do not scope it.

---

## 2. The two band-move leads

### B1 — `visual/cache_as_bitmap/avm2_button`: RECOMPILER drops `opaqueBackground` inside a DefineSprite (4 432 → ~278)

Expected: a 100×100 **green** square with a blue circle. Ours: white with the
blue circle — the green square is simply absent (4 152 of 4 432 channels).

Parsed both `PlaceObject3` tags out of the SWF (the second one is nested inside
`DefineSprite 4`, which is why a flat tag walk misses it):

```
DefineSprite 4
  PO3  flags2=0x44 (HasCacheAsBitmap|HasOpaqueBackground) depth 1 char 3
       BitmapCache=1   BackgroundColor = 00 ff 00 ff   <-- GREEN
PO3    flags2=0x44                                   depth 1 char 4
       BitmapCache=1   BackgroundColor = ff 00 00 ff   <-- RED (covered by the green in Ruffle too)
```

Our emitted `RecompiledTags/tagMain.c`:

```
frame_0:          tagSetOpaqueBackground(app_context, 1, 1, 16711680u);   // red, root arm
                  tagSetCacheAsBitmap(app_context, 1, 1);
sprite_4_frame_0: tagSetCacheAsBitmap(app_context, 1, 1);                 // <-- no opaque background
```

Cause, verifiable with one grep:

```
$ grep -n "tagSetOpaqueBackground\|tagSetCacheAsBitmap" SWFRecomp/src/swf.cpp
4805:  tagSetOpaqueBackground(...)      <- root PlaceObject arm ONLY
4814:  tagSetCacheAsBitmap(...)         <- root arm
6234:  tagSetCacheAsBitmap(...)         <- sprite arm  (no opaque-background twin)
```

**`tagSetOpaqueBackground` is emitted at exactly one site.** The sprite arm
(`sprite_definitions`, ~`:6234`) grew the `cacheAsBitmap` and `tagSetFilter`
twins but never the opaque-background one. ~8 LOC, mirroring `:4805`.

**Honest pricing**: the residual after the green lands is ~278 channels
(166 ch where expected is blue and we are white, 112 ch where expected is green
and we are blue) — a sub-pixel circle-edge difference at tolerance 1 / max 0. So
this is a **94 % band move, and a flip only if the cache's pixel snapping also
changes with an opaque background present.** Do not sell it as a guaranteed +1.

**Canary**: `visual/opaque_background` PASSES at tol 1 — add it (tier 1); plus the
existing `visual/cache_as_bitmap/{shape_changed,masks}`. Any recompiler edit also
needs `--recompile` on every copied dir.

---

### B2 — `avm2/graphics_draw_path`: `drawPath` aborts on a NaN coordinate (204 → 6)

Rendered an ASCII map of both PNGs. The grid is `testShape()`'s
`x = 10·(id % 5), y = 10·⌊id/5⌋`, run twice (once for `drawPath`, once for
`drawGraphicsData`). Exactly ONE of the ten cases is blank in our render, in both
passes:

```
        id5 = case 6 "Non-integer coord"   at (0,10) and (0,30)
        expected: solid 10x10 red      ours: nothing
```

Case 6 is `MOVE_TO(0,0), LINE_TO("X","Y"), LINE_TO("X","Y"), MOVE_TO(0,0),
LINE_TO(10,0), LINE_TO(10,10), LINE_TO(0,10), LINE_TO(0,0)`. `Number("X")` is
NaN; Ruffle's `Twips::from_pixels(NaN)` casts to 0, so the first subpath is
degenerate and invisible and the **second subpath still draws the square**. We
drop the whole path.

All 202 differing pixels sit in that one column (verified: zero diffs outside
`x<10, 10≤y<78`), so this is the entire defect.

**Residual = 6 outlier channels** — two single pixels at (2,47) and (2,77) in the
`smokeTest` zigzag where expected is red and we are cyan/yellow: a 1-sample
rasteriser tie on a diagonal at `quality = "low"`. tolerance 0 / max_outliers 0,
so **204 → 6 is a band move, not a flip**, unless the tie also resolves. Say so.

Note the test is `known_failure = true` on the TRACE axis (and on
`avm2/ignored_tests.txt`); its trace status is `ruffle_matched`. The image golden
is still the grading reference, so a pixel fix here is legitimate — but do not
touch the trace.

---

## 3. Diagnoses that need one more measurement before they are leads

### B3 — `visual/cache_as_bitmap/nested_rotation` (25 665, only TWO colour pairs)

Expected: a light-grey (204) card with a **rotated** black rectangle. Ours: the
same card with the rectangle **axis-aligned**. 4 284 px grey→black and 4 271 px
black→grey — a pure content displacement, so the board's
`same_geometry_wrong_fill` label is wrong here.

From the recompile: root places sprite 4 with `tagSetCacheAsBitmap(1)`; sprite 4
frame 0 places a child named `"a"`; sprite 4 **frame 1** runs
`a._rotation = 10` (`script_1.c`: `PUSH "a"; PUSH "_rotation"; PUSH f64 10.0;
actionSetMember`). `num_frames = 3`.

Two candidate mechanisms, one cheap discriminator:

1. the cacheAsBitmap cache is not invalidated by a **descendant** transform
   change (cached frame-0 content is reused), or
2. `_rotation` on a named child inside a sprite is a no-op on this path.

**Discriminator (A/B, no golden needed)**: patch out the `tagSetCacheAsBitmap`
call in a scratch copy of the emitted `tagMain.c` and re-render. Rotation appears
⇒ (1); still square ⇒ (2). Both PNGs are 2-colour with hard edges (no AA at
`quality = "low"`), so if the geometry lands, a tol-0 flip of 25 665 channels is
genuinely reachable — this is the largest single-mechanism prize in my set.

### B4 — `visual/drawing_api/drawing_order` (6 664)

Expected has a green diagonal drawn on `_root` (visible only outside the red
rect) and a blue diagonal drawn on an attached clip (visible on top). **Ours
draws neither line anywhere.** Three colour pairs carry 6 604 of 6 664 channels
and there are no intermediate AA values on either side.

From the recompile, the AVM1 script uses **two different call shapes**:

```
actionCallFunction("lineStyle") ; actionCallFunction("lineTo")   // bare, on _root
... this.attachMovie("mc", ...) ...
actionCallMethod("lineStyle") ; ("moveTo") ; ("lineTo")          // on the clip
```

Both are missing, which argues against "bare-call target resolution" alone.
`avm1/mask_with_drawing` (tier-1 canary, runtime drawing API) passes, so the
drawing API is not globally dead — the discriminator is whether *stroke-only*
subpaths (no `beginFill`) survive our shape build. That is the measurement a
wave-2 agent should take first. Pricing: tolerance 0 on 1-px diagonals makes an
exact flip unlikely even when the lines land; **band move, flip uncertain.**

### C1 — `visual/blend_modes/layer_alpha` + `layer_erase` (66 762 + 66 967): HOLD, arc-sized

Expected renders the "ruffle" wordmark as a **knockout** through the checkerboard;
we draw it opaque. This is already documented as unimplemented in our own source:

```
SWFModernRuntime/src/rendering/render_webgpu.c:4392-4396
// Alpha (11) and Erase (12) are handled by the caller: with no Layer above them
// Flash ignores the object entirely (surface.rs:239-244), and we have no layer
// groups yet, so that is always true. Layer (2) itself still falls through to normal.
```

The corpus confirms the split: `alpha_no_layer` and `erase_no_layer` are 21
outliers each (near-pass — the no-Layer rule is right), while the two `layer_*`
rows are 66 k each. **Completion mechanism**: a real LAYER group — render the
group's subtree to an offscreen (needs a texture pool for nesting, which
`render_webgpu_blend_mode_is_layered` currently refuses at
`offscreen_depth > 0`), then composite ALPHA/ERASE against the group's alpha.
Two comparisons for a new pipeline pair plus a pool; not a wave-2 slice.

**Board correction**: the brief asks whether these two are "a layer-blend
compositing mechanism". They are, and they are the *only* two rows of it —
the ten `visual/blend_modes/*` `a_epsilon` rows (8–27 outliers) are the CAPPED
sub-pixel family and share nothing with this.

### C2 — `avm2/edittext_get_{line,char}_index_at_point` (18 403 + 22 849): not my family

These paint one colour band per returned index. **Both traces PASS**, so the API
returns the right values at the sampled points; the pixels disagree about *where
the line boundaries are* (our cells show an extra band and different band
heights). This is EditText line-height/leading layout — hand to the text owner
(`w1-gfx-text`), not to a fill/colour session.

### C3 — `visual/filters/color_matrix` (237): the brief's premise is wrong

Listed as head-of-board "same geometry, wrong colour". Measured: **one colour
pair, 81 pixels, and the colour we produce is already correct.** Expected
`(0,8,0)`, ours white — i.e. *missing geometry*, at a single element's
bottom-right rounded corner:

```
row   expected right edge        ours
269   ############### (33 wide)  ############### (33)
270   ############### (33)       ####### (23, flat)
...
279   ########## (26, tapering)  ####### (23, flat)
```

Our render is a flat 23-wide stub for the last ten rows where the golden tapers
33→26; plus 2 px one column narrow at rows 82–83. **This also refutes s16's
`wave1-gfx-filters.md` §2 claim that `filters/color_matrix` "emits no
`tagSetFilter` at all"**: the recompile in my scratch tree emits none (confirmed),
yet our rendered halo colour `(0,8,0)` already equals the golden's — the
ColorMatrix in this test is a no-op for this element, and the residual is a
rounded-corner geometry defect that has nothing to do with filters. Re-file it
under shape geometry.

### C4 — `avm2/graphics_simple_shapes` (240)

`Test.as` is `drawRect / lineStyle(2,blue) + drawRoundRect(30,5,15,20,10) /
drawCircle / lineStyle(4,green) + drawEllipse`. All 240 outlier channels sit on
the round-rect's corners: 92 ch expected-white→ours-red (red bleeding into the
corners we render square), 84 ch expected-blue→ours-red (the blue arc we never
draw), 56 ch expected-white→ours-blue (our square corner's stroke). This is the
**same `drawRoundRect` radii gap s17 already named as `acid-shapes`'s
residual** — same owner, +1 more comparison on the ledger.

### C5 / C6 — BitmapData rows

* `avm2/bitmapdata_draw_masks` (5 850, tol 0, two pairs, no AA): 2 700 px expected
  black→ours red (content the mask should have hidden) and 1 050 px expected
  magenta→ours green. `BitmapData.draw` ignores the source's `.mask`. s17's
  `w2-gfx-cab-mask-stencil` explicitly excluded this row from the alpha-mask arm;
  it is still open.
* `avm2/bitmapdata_copypixels` (25 200) — 900×900 grid of variants, 20 pairs in
  800/700-px blocks. In the failing cells `expected = 0.733·ours + 36` holds to
  the unit across all three channels (e.g. ours (0,136,255) → expected
  (36,135,223); ours (255,0,0) → expected (223,36,36)), i.e. Ruffle composites the
  source at α≈187/255 over a grey-135 backdrop and we write it opaque — an
  `alphaBitmapData` / `mergeAlpha` arm. Other cells expect the grey backdrop
  untouched where we draw content at all. s17's `w2-gfx-smalls` already recorded
  that the AVM1 `copyPixels` un-premultiply fix left this AVM2 row "unchanged by
  construction" — this is the missing AVM2 arm.
* `from_shumway/acid/acid-bitmapData-copyPixels` (53 760): only THREE colour
  pairs — 16 640 px expected `(13,27,40)` → ours `(204,0,0)`, 768 px the reverse.
  Two source/dest regions are swapped wholesale. Same family, different rule.
  **NOTE for whoever picks this up**: the playbook §6 line "`bitmapdata_copypixels`
  shows ~25 k phantom outliers locally while passing CI" is stale/misattributed —
  `avm2/bitmapdata_copypixels` FAILS CI at 25 200 in this baseline. Do not use it
  as evidence that a local diff is phantom.

---

## 4. Attacks on the brief (refutations and corrections)

1. **`visual/filters/color_matrix` is not a colour rule** (§C3) — it is a
   rounded-corner geometry stub, and it also refutes s16's "no `tagSetFilter` at
   all ⇒ that's the residual" reading.
2. **`avm2/displayobject_blendmode` is not "blend math"** (§A1) — the AVM2 walk
   has no blend arm at all, and the test uses `BlendMode.ADD`, not the exotic
   modes. The brief's "max_diff 114" framing hides that 14 400 px of +1 rounding
   are already inside tolerance.
3. **`visual/cache_as_bitmap/nested_rotation` is not `same_geometry_wrong_fill`**
   (§B3) — the geometry is the whole defect (a lost rotation); the two colours are
   incidental.
4. **`visual/cache_as_bitmap/avm2_button` is not a "wrong fill"** (§B1) — a whole
   element is absent, and the owner is the RECOMPILER, not the renderer.
5. **`visual/filters/blur_scales_with_screen`'s brief line is superseded.** The
   brief (from §16) says the AVM1 sprite-tag filter route "needs a real offscreen
   cache pass" and s16 measured "a sharp red box, golden is heavily blurred".
   **We now render the blur**: both sides carry the full red→cyan ramp across
   2 494 distinct colour pairs, mean |Δ| 0.85, max 40. I tested every integer
   shift in ±2 px in both axes — **none** improves the match (best is dx=dy=0),
   so it is not a phase/placement error either. The residual is blur *width /
   profile* accuracy under a screen scale (our result sits slightly closer to the
   unblurred source, i.e. our kernel is marginally narrow). That is a filters-family
   accuracy row, adjacent to `blur_quality`'s per-pass rounding — **not** a
   missing-plumbing row. Re-price it and hand it to `w1-gfx-filters`.
6. **`avm2/blend_shader_luma_lighten` is not simply "Pixel Bender is not
   executed".** We DO produce a plausible gradient (21 outlier pairs at the
   chosen tol 180). Measured relation on the survivors: expected has `G ≈ 2·R`,
   ours has `G ≈ R/2` — a factor-4 green scale, e.g. expected (120,239,0) vs ours
   (116,58,0). That smells like a shader constant/normalisation, not an absent
   backend. Worth 30 minutes from whoever owns the shader arm before it is
   re-parked. (The brief's "max_diff 204" and the earlier top pair that looked
   like a clean R↔G swap are both artefacts of ranking at tolerance 0.)
7. **`from_shumway/acid/acid-color-0`: I cannot attribute the s17 regression, and
   the brief's "attribute first" cannot be satisfied from images.** The
   `ruffle-image-results` branch is force-pushed and has exactly ONE commit
   (`8b73d71ac`), so no pre-s17 `output.actual.png` exists anywhere. What I can
   give is the decomposition (44 819 outlier channels at tol 3 / budget 3):
   * **24 840 ch** — the radial-gradient swatch at (512–640, 0–128): the gradient
     we draw is *pixel-correct where it exists*, but **the top-right triangle of
     the quad is simply missing** (a clean diagonal cut). A dropped triangle in a
     gradient-filled rectangle. Note this magnitude equals the s17 regression
     delta (44 817 − 20 014 = 24 803) almost exactly — suggestive, **not** proof.
   * **15 613 ch** — the "Hello" field at (768–896, 192–256): the golden has a
     TextField with a **green background, black text and a border**; we draw red
     text on white with no background and a different position. This is the block
     that plausibly belongs to s17's EditText per-depth interleave.
   * **2 635 ch** — the ring/donut swatch. **~1 700 ch** — everything else.
   A wave-2 agent wanting attribution must A/B the s17 EditText commit locally;
   the image axis cannot answer it.

---

## 5. Rows I am explicitly NOT scoping

| row | why |
|---|---|
| `visual/video/h264` (9 comparisons, 98 k–117 k) | codec, excluded by the brief ("non-video") |
| `avm2/pixelbender_effect_glassDisplace_shaderfilter` (879 084) | 57 067 px of expected-black render as flat pure blue — Pixel Bender bytecode is not executed (s17 M2, PARKED) |
| `avm2/away3d_advanced_shallow_water_demo` (1 331 169) | Stage3D content (s17 M1, PARKED); 36 285 distinct pairs |
| `avm2/bitmapdata_applyfilter_destpoint_edges` (169 250), `visual/blend_modes/shader_as_mask` (2 100) | Ruffle `known_failure` |
| `avm2/bitmapdata_draw_filters` (14 400) | Ruffle `known_failure`, but worth one line: a **uniform G↔B swap** over 7 200 px, expected `(255,255,0)` vs ours `(255,0,255)`, one pair, zero AA. Cheapest known_failure row in the corpus if anyone wants it |
| `avm2/bitmapdata_applyfilter_blur` (28 871) | dispositioned (ACCEPTED_DIFFS, image-axis scope), correctly excluded by the board |

---

## 6. Suggested wave-2 slicing

* **Slice "avm2-blend-arm"** — A1 alone. `avm2_display.c` only. Clean +1, no
  overlap with any other agent's file if the numeric blend is cached on the
  display ext rather than re-plumbed through `Avm2TimelineOp`.
* **Slice "fill-smalls"** — A2 (`avm2_text.c` one token) + A4 (`avm2_bitmap.c`
  alpha accumulate) + B2 (`drawPath` NaN). Three independent one-rule changes,
  +2 flips and one 97 % band move. Watch the file overlap with any EditText agent
  on `avm2_text.c`.
* **Slice "filter-cxform"** — A3. `tag.c::render_filtered_object` +
  `avm2_display.c::avm2_render_filtered`. Highest single-flip confidence after A1.
  Must run `from_shumway/acid/acid-filter` and every `visual/filters/*` canary.
* **Slice "recompiler-opaque-bg"** — B1. `SWFRecomp/src/swf.cpp` only, ~8 LOC.
  Needs a cmake rebuild in the worktree **and `--recompile` on every copied test
  dir** (playbook §5).
* B3 and B4 are measurements, not slices, until their discriminator runs.

## 7. Canary gaps this brief exposes

The standing set has **no** member covering: EditText selection rendering (A2),
`BitmapData.draw` alpha accumulation (A4 — though four passing
`avm2/bitmapdata_draw_*` rows exist and should be added), filtered objects
**with a colour transform** (A3 — add `from_shumway/acid/acid-filter`), and
`opaqueBackground` (B1 — add `visual/opaque_background`, which passes at tol 1).
All five additions are CI-passing today, so they would be tier-1.

---

## 8. New unclaimed leads

1. **`from_shumway/acid/acid-color-0`, gradient swatch: one triangle of a
   gradient-filled quad is dropped** (~24.8 k channels, a clean diagonal cut with
   the drawn half pixel-correct). Largest single unexplained geometry defect I
   found. Owner unknown — tessellation or a winding/index-buffer drop.
2. **`from_shumway/acid/acid-color-0`, "Hello": an AVM1 dynamic TextField's
   `background` / `backgroundColor` / `textColor` are all ignored** (green box +
   black text + border vs our red text on white), ~15.6 k channels.
3. **`acid-morph`'s morph polygons**: 1 126 outlier channels, systematic −9…−11 on
   R and G of the gold gradient over 1 190 pairs — a morph gradient ratio/lerp
   rounding distinct from s16's `morph_lerp_color_u8`.
4. **`avm2/bitmapdata_draw` (24 585 / budget 600)** is not on any board row I was
   given but is in the same family as A4 and may move with it — worth measuring
   in the same slice.
5. **`avm2/blend_shader_luma_lighten`'s factor-4 green scale** (§4.6) — a
   possible one-constant shader bug hiding inside a "parked backend" label.
6. **Playbook §6 correction**: the claim that `bitmapdata_copypixels` "passes CI"
   is stale; `avm2/bitmapdata_copypixels` fails at 25 200 in the current baseline.
   Someone should fix that line before it is used as a false-positive excuse.
