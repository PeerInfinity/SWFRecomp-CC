# s29 w1-pixel-flash-gaps — report (wave 1, diagnosis + measured prototypes)

**New files (all under `session29-fanout-reports/`):**
- `w1-pixel-flash-gaps-report.md` (this file)
- `w1-pixel-flash-gaps-prototype.patch`: all three prototypes A + B + C (`git diff origin/master -- SWFModernRuntime`, 4 files)
- `w1-pixel-flash-gaps-prototype-B-drawapi-centre.patch`: prototype B alone (`render_webgpu.c` only)

Sources are reverted on the branch. Base: `origin/master` `aa36d43a` (code = `bfa47037b`, results `014124ed5`).
Upstream Ruffle test download: master at `b7ff32d93` (2026-11-26; newer than the `31e07df77` named in BRIEFS_COMMON).
Categories downloaded: from_gnash, from_shumway, visual, avm2, avm1. flash_fixes applied cleanly (51 + 11).
**Fidelity:** my *before* renders are byte-identical (md5) to CI's `ruffle-image-results` actual PNGs for
`place_object_test`, `shape_test` and `acid-shapes`, so local grading is CI-grade on those rows. Every other number
here is an A/B on this box; the before legs reproduce the `s29-baseline-pixel-failing.txt` counts exactly.

## Verdicts (lead)

| # | item | verdict | priced moves (by name) |
|---|---|---|---|
| 1a | `place_object_test` (5073) | **100 % text.** The shapes are pixel-exact vs the FP32 LOW golden. **GO (prototype A): LOW glyph pen → whole device px** for plain (non-FlashType) embedded-font fields | 5073 → **2604** (no flip) |
| 1b | `shape_test` (10300) | **89 % an open-fill-contour leak (9172 ch), 11 % text (1128).** Text: prototype A 1128 → 543. Leak: **NO-GO (L)**, it is Flash's cross-object scanline parity | 10300 → **9715** (no flip) |
| 2 | `acid-shapes` (88 → 243 over) | **GO (prototype B).** All of `e81d27317`'s effect on this row is the ¼-px quantization of EVERY drawing-API polyline centre. Quantize only centres that end an exactly axis-aligned segment | over-limit 243 → **88** (= pre-s28, byte-for-byte the snap-off render); `graphics_simple_shapes` 124 → 114, `graphics_gradients` 304 → 293 (both Flash goldens); Flash fixture `avm1_drawing_stroke_scale` 11703 → 11736 ch (still passes, limit 14000); the two drawapi snap fixtures unchanged |
| 3a | `shadow_shape_a50` (768 px) | **Premise stale: LANDED in s28** (w2-filter-residuals-land). Both twins pass at 0 outliers, max 1, today | — |
| 3b | bevel HOLD probe | **Premise stale: LANDED in s28** (fitted bevel sample, 18/30 probe cases exact; `avm1_applyfilter_bevel` exact). Rows pass today | — |
| 4a (UNSURE 9) | `acid-shapes` | Resolved: not "AA noise" for the 88→243 step (prototype B recovers it exactly). The remaining 88 is HIGH edge AA, the standing AA-mode NO-GO | see 2 |
| 4b (UNSURE 10) | `cache_as_bitmap/avm1_color` | **GO (prototype C): unfiltered cacheAsBitmap snaps at LOW only.** The "pending" Flash request was already captured in s28 (`lowq_sample_point` row 3): at HIGH Flash draws the cached rect at (7.5, 127.5) with 50 % edges / 25 % corners = NOT snapped. All 3 priced blockers (`scroll_rect` Flash golden, `drawing_api`, `avm2_button`) are LOW and keep the snap | `avm1_color` 1200 → **230 (max 1)** (Flash golden; still fails at tol 0), `scroll_rect_scaled` 799 → 697 (pass→pass); 0 other moves on 23 HIGH cacheAsBitmap rows |
| 4c (UNSURE 11) | `graphics_simple_shapes` / `gradientTransform` | **Both live Flash targets, not NO-GOs.** `graphics_simple_shapes` (124, tol 1): LOW curved-edge / stroke-on-curve pixel decisions (sibling w1-lowq-next owns the LOW stroke raster); −10 under prototype B. `gradientTransform` (6 over tol 3, max 9): see §4c, a FLASH request decides whether the golden is LOW or HIGH | — |
| 4d (UNSURE 12) | s24 zero-headroom rows | **Re-graded at `014124ed5` vs FP32 LOW: the "zero headroom" disposition is obsolete.** None has a Flash golden; ours is closer to Flash than the golden on every row (table §4d). `edittext_border_filters` passes | — |

No prototype flips a row (the brief warned: honest residuals). Net on Flash goldens: 4 gnash rows, `acid-shapes`,
`avm1_color`, `graphics_simple_shapes`, `graphics_gradients` move toward Flash; one Ruffle-golden loss
(`text_field_mask`, LOCAL ORACLE REQUEST 1) and one Flash-fixture band (+33 ch, in tolerance).

## 1. gnash `place_object_test` / `shape_test` (goldens = FP32 LOW)

### 1.1 Where the pixels are (tol 50, channels)

| row | text (y < 100) | shapes | owner |
|---|---:|---:|---|
| `place_object_test` | **5073** (1691 px) | **0** | LOW glyph raster (no s28 model covered it) |
| `shape_test` | 1128 (376 px) | **9172** (4585 px, one cluster x 119–259, y 140–180) | open-fill leak (§1.3) |

Neither row is owned by the LOW sample point, the stroke snap, or the LOW stroke y rule: the gnash squares (fills +
1-px strokes) already match Flash exactly.

### 1.2 Text: the LOW glyph rule (prototype A)

The text is a DefineEditText with `UseOutlines` (embedded Bitstream Vera Sans, no CSMTextSettings). Flash at LOW draws
it aliased. `tf_glyph_quarter_snap` (tag.c) scoped its ¼-px snap to AA builds because "the quality=low Flash captures
fit no single grid/pen rule". **Those captures were old-stub, i.e. HIGH** (s28 flash-oracle-harness finding). With the
real FP32 LOW goldens a rule fits. Sweep (text channels, `place_object_test` / `shape_test`):

| variant (LOW, embedded, non-device) | pot | st |
|---|---:|---:|
| master (unsnapped) | 5073 | 1128 |
| outline ¼-px grid + pen ¼ (the HIGH rule) | 5766 | 1350 |
| outline ½ px | 7098 | 1656 |
| **pen rint → whole px, outline unsnapped** | **2604** | **543** |
| pen + outline whole px | 2502 | 531 |
| pen floor / ceil | 11280 / 6990 | 2679 / 1725 |
| pen whole px + offsets ±¼, ±½ in x or y | all worse (2868 … 8388) | |

Pen-rint is the clean rule; snapping the tessellated outline vertices is crude and only −100 more. The rest is glyph
interior decisions (Flash's LOW curve rasterisation of 'e', 'c', 't'), which is also what keeps the LOW stroke slice open.

**Scope found by measurement:** on the 13 other LOW rows with embedded-outline fields, the rule hurt exactly the rows
whose fields carry CSMTextSettings `antiAliasType=advanced` (FlashType): `acid-text` 2868 → 4029, `acid-text-escape`
480 → 1022, `acid-color-0` 18838 → 19147. The FP32 LOW capture `interim6-low/acid-color-0.low.png` shows Flash
**anti-aliases FlashType text even at LOW**, so those fields must not be pen-snapped. The prototype gates on that flag.

**Prototype A ledger** (rule: LOW, embedded, `csm_advanced == 0` → pen rint to 1 device px):

| row | golden | before | after |
|---|---|---:|---:|
| `from_gnash/misc-ming.all/place_object_test` | FP32 LOW | 5073 | **2604** |
| `from_gnash/misc-ming.all/shape_test` | FP32 LOW | 10300 | **9715** |
| `from_gnash/misc-ming.all/morph_test1` frames 2–5 | FP32 LOW (s28 swap) | 1530 ×4 | **1401 ×4** |
| `morph_test1` frame6 / frame1 | FP32 LOW | 727 / 193 | **598** / 193 |
| `from_gnash/misc-ming.all/BeginBitmapFill` (tol 100) | Flash (s27) | 951 | **894** |
| `visual/simple_shapes/text_field_mask` | Ruffle ("not Flash" under a HIGH-era capture) | 630 | **1738** (loss, REQUEST 1) |
| `sprite_with_frames`, `acid-color-0`, `acid-text`, `acid-text-4/5/x/escape`, `acid-textfield`, `duplicate_font`, `fonts/glyph` | — | unchanged (all FlashType) |

Every row on this list already fails, so the prototype has **no pass→fail**. `text_field_mask` (huge "W" glyphs,
AVM1, no CSM) is the one open question: its golden is Ruffle's and its s27 Flash grade predates the stub fix, so
LOCAL ORACLE REQUEST 1 decides it. HIGH is untouched (the MSAA>1 arm is unchanged; `avm1_edittext_wordwrap_render`
still passes at 69/69).

**Functions touched (prototype A):** `tag.c` `tf_glyph_quarter_snap` (new `MSAA_SAMPLES == 1` arm);
`action.h` `TextFieldGlyphInfo` (trailing field `csm_advanced`); `action.c` new static `tf_glyph_csm_advanced`, set in
the two TextFieldGlyphInfo producers (the `child_mc_cache` path next to `bounds_ymin_twips = 0`, and the orphan path
next to `device_font`). Wave-2 caveat: an AVM1/AVM2 runtime `antiAliasType` assignment is not plumbed (the prototype
reads only the tag's CSMTextSettings); no corpus row needs it.

### 1.3 `shape_test`'s 9172 channels: Flash does not close an open fill contour (NO-GO, L)

Shapes 6 / 8 (DefineShape3, green, `fillStyle0` only) end at (400, 600) without the closing edge back to (400, 200).
We (and Ruffle, lyon) close every contour implicitly. Flash does not: scanline parity stays odd on the rows the missing
edge spans (y 140–180 after the sprite transform), so the fill inverts right of x = 120 and **runs on across the gap to
the twin sprite's own missing edge at x = 240**:

| y | Flash green runs | ours |
|---|---|---|
| 145 | 101–119, **161–219**, 221–239, 241–279 | 101–119, **121–159**, 221–239, 241–279 |
| 165 | 121–139, **161–239**, 261–279 | 141–159, 261–279 |
| 185 / 195 | identical | identical |

The bar between two separate display objects shows the parity is shared across objects (a global edge list), so no
per-shape model reproduces it. A per-shape "no implicit close" model would also paint x 280–800. Shapes 10 / 12
(closed, and the `fillStyle1` variant) already match. **NO-GO (L, global scanline rasteriser).** Completion
mechanism: a CPU reference rasteriser that keeps open-contour parity across objects (the same seed as the s28 "4×4
SSAA CPU reference" lead). One corpus row, so it is not worth it alone.

**Flash fix:** none. Both goldens are FP32 LOW (s28 re-capture). The ~1k-px deferred-swap threshold no longer applies;
these are honest Flash residuals.

## 2. `acid-shapes`: the drawing-API centre quantization (prototype B)

`acid-shapes` is AS3, HIGH, 6 checks. At master it fails tol 32 by 243 (and 5 other checks). With
`SWF_STROKE_SNAP_DRAWAPI=0` it is back to 88 (tol 16 by 85, tol 32 by 88; the s27 state).

Splitting `render_webgpu_stroke_snap`'s non-snap effects with A/B knobs:
- width quantization (`target_px = 2*floor(u/2)/4` for W = 0): **no effect** on this row;
- the ¼-px grid on every polyline centre `cdx/cdy = floor(4c + 0.5)/4`: **all of it**. Without it the render is
  byte-for-byte the snap-off render (over-limit 0 / 85 / 88 / 0 / 0 / 0).

Per-band (tol 32): the loss is the thick curved-stroke rows (y 255–380), where every tessellated centre moved by up
to ⅛ px. Variants on the gate:

| quantize the centre when … | acid-shapes over (t16/t32) | drawapi fixtures avm1 / avm2 / stroke_scale |
|---|---:|---:|
| always (master) | 184 / 243 | 2436 / 2550 / 11703 |
| `snap_ok` (W ≠ 0 and axis matrix) | 278 / 219 | 2436 / 2550 / 11703 |
| `snap_ok` and an axis flag | 85 / 88 | 2454 / 2568 / 11760 |
| **an axis flag (`STROKE_SNAP_VERT`/`HORZ`), any width** | **85 / 88** | **2436 / 2550 / 11736** |
| never | 85 / 88 | — |

The last-but-one row is the rule: Flash's ¼-px position grid is a property of the exactly axis-aligned segments the
snap rule is about; quantising every vertex of a flattened curve is a mis-generalisation. All of `e81d27317`'s Flash
evidence was axis-aligned (`n-stroke-snap-report.md` §1).

**Prototype B ledger** (graphics, every image row in the corpus whose SWF contains `lineStyle`, 35 rows, plus the 8
regression stroke fixtures):

| row | golden | before | after |
|---|---|---:|---:|
| `from_shumway/acid/acid-shapes` | Flash | over 22/184/243/21/22/3 | **0/85/88/0/0/0** (2 of 6 checks fail, was 6) |
| `avm2/graphics_simple_shapes` (tol 1) | Flash | 124 | **114** |
| `avm2/graphics_gradients` | Flash | 304 | **293** |
| `regression/avm1_drawing_stroke_scale` | FP32 | 11703 | 11736 (limit 14000, pass) |
| `avm2/displayobject_getbounds_shape` | Ruffle | 3714 | 3716 (limit 3800, pass) |
| `avm2/graphics_bitmaps` | Ruffle | pass | pass (the deciding check moved: 705/800 → 526/600) |
| 29 others incl. `acid-shapes-testing` 10317, `acid-stroke-0` 7173, `cursor`, `fills_and_lines`, `drawing_order`, `stage3d_texture`, `graphics_draw_path`, `graphics_draw_triangles`, `avm1_drawapi_stroke_snap`, `avm2_drawapi_stroke_snap`, `avm1_stroke_join_cap_snap`, `avm1_stroke_noscale_signed`, `movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`, `acid-morph`, `definefont4` | | **unchanged** |

0 status moves. **Function touched:** `render_webgpu.c` `render_webgpu_stroke_snap` (the centre quantization only).
The timeline twin (`hairline_restage`) is untouched; the local N ladder owns closed seams in builders/lyon and does
not touch this line.

## 3. Filters: both brief items already landed

- `shadow_shape_a50`: `w2-filter-residuals-land` §2 landed the fractional (bilinear) display DropShadow offset.
  `regression/group_alpha_shadow_shape_a50` and `avm2_group_alpha_shadow_shape_a50` PASS today at 0 outliers, max 1.
  The PB §27 "w2b-group-alpha `shadow_shape_a50` residual, 768 px" line is a stale copy of the s27 board.
- Bevel HOLD: `w2-filter-residuals-land` §3 landed the fitted bevel sample. `avm2_applyfilter_bevel_sample` and
  `avm1_applyfilter_bevel` PASS (the latter exact at tol 0). What is genuinely still open is the s28 lead "display
  bevel offset is still nearest; check a display bevel at a fractional distance against Flash", and the display
  Glow/DS/Bevel composite parity lead. Neither has a Flash-golden corpus row; see §4d for the corpus bevel rows.

## 4. UNSURE 9–12

### 4a (9) `acid-shapes`
Resolved by §2. The 88 → 243 step is a mechanism, not noise; prototype B recovers it exactly. The remaining 88 is HIGH
edge AA (w1-acid-flash: 0 interior mismatches), the standing AA-mode NO-GO (Flash HIGH = 4×4 SSAA).

### 4b (10) `cache_as_bitmap/avm1_color`
The Flash request "cached shape at (x.5, y.5), LOW + HIGH" was filed in s28 as w1-avm2-vector-flash request 1, row 3,
and **was captured** (`session28-fanout-reports/w1-local-oracles/w1-avm2-vector-flash/lowq_sample_point.{low,high}.png`).
Nobody read row 3 for this question. The cell is a 25×25 rect, `cacheAsBitmap = true`, at (7.5, 127.5):
- HIGH: column 7 and row 127 at 50 % (128,213,255), corner 25 % (192,234,255), right/bottom edges 50 % too → drawn at
  the fractional position, **not snapped**.
- LOW: aliased, px 8..32 × 128..152. Snap and no-snap give the same pixels under the LOW sample rule, so LOW cannot
  tell them apart, and the LOW Flash-golden `scroll_rect` keeps the snap.

The `avm1_color` golden itself is FP32 (upstream `045db00b39` re-made it against Flash 32) and goes 1200 → 230 (max 1)
without the snap: a second, independent Flash witness. **Prototype C:** `tag.c` `cab_snap_delta` returns 0 for an
UNFILTERED entry when `MSAA_SAMPLES > 1`. (Gotcha for wave 2: `MSAA_SAMPLES` is only defaulted at tag.c:7629, after
`cab_snap_delta`, so the guard must be `!defined(MSAA_SAMPLES) || MSAA_SAMPLES > 1`; my first cut used `defined(...)`
and silently did nothing.)

| row (HIGH, cacheAsBitmap) | golden | before | after |
|---|---|---:|---:|
| `visual/cache_as_bitmap/avm1_color` | FP32 | 1200 (max 192) | **230 (max 1)**, still fails tol 0 |
| `visual/cache_as_bitmap/scroll_rect_scaled` | Ruffle | 799/900 | 697/900 |
| 10 other HIGH `cache_as_bitmap/*` rows + 11 other HIGH rows whose SWF uses cacheAsBitmap (`masked_layer_cached_children`, `shader_as_mask`, `bitmapdata_draw_cab_quality`, `graphics_bitmap_fill`, `bitmapdata_copychannel`, 6 regression rows) | | **unchanged** |

The LOW rows (`scroll_rect`, `drawing_api`, `avm2_button`, …) are untouched by construction. The 230 residual is the
8-bit blend rounding on half-coverage edges (w1-avm2-vector-flash §4). Caveat: the HIGH Flash evidence is a `draw()`
capture, and `draw()` may bypass the cache bitmap; the `avm1_color` golden (a real screen capture of a cached clip)
is the stronger witness. LOCAL ORACLE REQUEST 2 closes it. Then write the RvF entry s26 asked for as "Flash composites
an unfiltered cache at its sub-pixel position at HIGH", NOT "Flash never snaps".

### 4c (11) `graphics_simple_shapes`, `gradientTransform`
- `graphics_simple_shapes` (AVM2, golden = FP32 LOW exact, tol 1): 124 channels in 3 small curved shapes (x 29–81,
  y 3–26): Flash's LOW per-pixel decisions on curved fill edges and on a thick stroke following a curve. A live LOW
  target for sibling w1-lowq-next (LOW stroke raster / curve flattening). Prototype B takes it to 114.
- `gradientTransform` (golden = Flash at HIGH, exact per s27 draw `--quality high`; `test.toml` says low): ours at LOW
  is 6 channels over tol 3 (488 channels differ, max 9, spread over the whole ramp). Forcing HIGH (toml edited
  locally, reverted) gives 9 over (17 differ, max 11, only the 3 edge pixels at x = 0 / 100). So the ramp interior
  matches Flash at HIGH and differs by ≤ 9 at LOW. If FP32 at LOW also equals the golden, our LOW linear paint is off by
  ≤ 9 on this placement (a lowq-next item); if FP32 LOW differs, the golden is HIGH-made and the row is a flash_fixes
  swap candidate to a fresh FP32 LOW capture. Both stay live targets; REQUEST 3 decides which.

### 4d (12) the s24 zero-headroom rows at `014124ed5`

Graded with FP32 LOW captures (`session28-fanout-reports/lowq-recapture/png/*.low.png`, Linux `draw()`), channels
over each row's tolerance:

| row | status | ours–golden | **ours–FP32** | golden–FP32 | disposition now |
|---|---|---:|---:|---:|---|
| `visual/filters/bevel` | fail | 58894 | **107165** | 116897 | golden not Flash; ours closer. Residual is spread over the bevel body (display-bevel composite parity, s28 lead) |
| `visual/filters/bevel_full` | fail | 22945 | 92572 | 110141 | same |
| `visual/filters/bevel_inner` | fail | 15433 | 64795 | 73381 | same |
| `visual/filters/bevel_outer` | fail | 27926 | 112428 | 126477 | same |
| `visual/filters/glow_with_alpha_strength` | fail | 15800 | 57327 | 67343 | same |
| `visual/filters/glow_without_composite_source` | fail | 19184 | 29848 | 30907 | same |
| `visual/drawing_api/fills_and_lines` | fail (priced s28 loss) | 38429 | **5704** | 36155 | ours is 6× closer to Flash than the golden. flash_fixes candidate, held by the Windows check (Linux draw == screen at 1 ch; Windows `draw()` differs by 5523 ch: lowq-recapture class c) |
| `fonts/embed_matching/fallback_preferences` | fail | 4155 | n/a | n/a | untestable (AVM2 root + low: a direct root renders HIGH; s27) |
| `visual/edittext/edittext_border_filters` | **pass** | — | — | — | done |

"Zero headroom vs Ruffle goldens" no longer describes any of them. None has a Flash golden, so none is a Flash target
through its golden; under the Flash-over-Ruffle ruling the register row should read "not Flash targets; ours closer
to FP32 than the golden on all 7; `fills_and_lines` is a swap candidate pending Windows".

## Refutations (rule 1)

- **"`place_object_test` / `shape_test` misses belong to the s28 LOW / stroke models"**: refuted. Their shapes are
  Flash-exact. The misses are LOW glyph text (no model covered it) and an open-fill leak.
- **"LOW glyph captures fit no grid/pen rule"** (`tf_glyph_quarter_snap` comment): refuted. The captures were HIGH
  (old stub). FP32 LOW fits "pen → whole px" for plain fields, and "no snap" for FlashType fields.
- **"acid-shapes 243 is AA noise"**: refuted for the 88 → 243 step (§2).
- **"avm1_color: Flash request pending"**: refuted, captured in s28 and unread (§4b).
- **"shadow_shape_a50 768 px / bevel HOLD are open"**: refuted, landed in s28 (§3).
- **"graphics_simple_shapes / gradientTransform are fidelity NO-GOs"**: refuted, both are live Flash targets (§4c).
- **"s24 zero-headroom rows"**: refuted as a disposition (§4d).

## New unclaimed leads

1. **Flash keeps open-contour fill parity across objects** (`shape_test`). Fold into any CPU reference rasteriser
   effort; one row alone does not pay.
2. **Plumb runtime `antiAliasType`** (AVM1 property, AVM2 `TextField.antiAliasType`) into `TextFieldGlyphInfo`, if
   wave 2 lands prototype A: the tag-level CSM flag covers every corpus row today.
3. **LOW glyph interior shapes** (the remaining 2604 / 543 in the gnash text): Flash LOW curve rasterisation of glyph
   outlines. Likely the same mechanism as the LOW curved-fill decisions in `graphics_simple_shapes`; one fit for
   sibling w1-lowq-next.
4. **Windows check for `fills_and_lines`**: the last gate before a flash_fixes swap that would make its residual
   honest (5704 ch vs FP32).
5. Wave-2 note for prototype C: also price the `avm1/` and `avm2/` HIGH rows that set `cacheAsBitmap` from script (my
   scan covered every image row whose SWF names `cacheAsBitmap` or sets the PlaceObject3 flag; LZMA SWFs were skipped).

## LOCAL ORACLE REQUESTS

1. **FLASH: `ruffle-tests/tests/swfs/visual/simple_shapes/text_field_mask` (corpus, AVM1, `quality = "low"`), image,
   tick 1, direct pinned (NEW stub).** Compare ours at master and with prototype A. It decides the only Ruffle-golden
   loss of prototype A (630 → 1738): does Flash LOW round a plain field's pen to whole px? Grade the 4 big "W" glyph
   rows (y 124–169). The s27 grade of this row predates the stub fix.
2. **FLASH: `session28-fanout-reports/w1-local-oracles/w1-avm2-vector-flash/` `lowq_sample_point.test.swf` (already
   built), `run_image.py --quality high --screen`, tick 1.** Compare row 3's cacheAsBitmap cell (25×25 rect at
   (7.5, 127.5)) with `lowq_sample_point.high.png` (draw). Same 50 % edges → prototype C's HIGH no-snap is confirmed
   on the real screen. If the screen capture is snapped, `draw()` bypassed the cache and prototype C needs a rethink
   (the `avm1_color` golden still favours it).
3. **FLASH: `ruffle-tests/tests/swfs/from_shumway/gradientTransform`, image, direct pinned (NEW stub), at
   `quality = "low"` (as the toml says) AND default HIGH.** Compare each with the golden (tol 3). Decides §4c: LOW
   == golden → our LOW linear paint is off by ≤ 9 here (lowq-next); LOW ≠ golden → golden is HIGH-made, swap it to the
   LOW capture via flash_fixes.
