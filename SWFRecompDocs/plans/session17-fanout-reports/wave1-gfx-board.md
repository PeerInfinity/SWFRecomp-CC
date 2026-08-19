# Session 17 — wave 1 — PIXEL-AXIS BOARD (w1-gfx-board)

**Agent:** `w1-gfx-board` · read-only diagnosis · no source edits in the main tree, no commits.
**Method:** `graphics-fanout-playbook.md` §2 (board), §3 (dispositions), §4 (accounting),
§7 (provenance), §15 (prior state). Deliverable shape mirrors
`session16-fanout-reports/wave1-gfx-board.md`.

## PROVENANCE (read this before using any number below)

| | |
|---|---|
| Grading run | `31877239992` at `aeebf9ede383da45c61df6c9e10f29c8425fee8b` (graphics / categories=full / images=true), created 2026-08-15T09:32:10Z, completed 10:10:36Z |
| Per-suite stems | all **12** `_results/image_results_graphics.json` carry `run_id=31877239992`, `git_sha=aeebf9ede`, `incomplete=false`, timestamps 10:09:52.7–10:09:53.3 — **consistent, no mixed-run stems** |
| `ruffle-image-results` | `bfecef0ad` "Ruffle image comparison failures", **2026-08-15T10:09:54Z** — inside the run's window, `index.json` `generated=10:09:54.25`, **228** `*.actual.png` (force-pushed ⇒ exactly this run's failures) |
| Board command | `python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 3` (52.8 s under fan-out load) |
| Raw board | `wave1-gfx-board.rawboard.md` (cluster table, cluster×band, top-30, group table, full disposition audit) |
| Accounting | `python3 scripts/image_status_diff.py 380c68c84 88ebde665 --per-suite` (s16 run `31748059158` → s17 baseline run `31877239992`) |
| Scratch | `<session-scratch>/w1gfxboard/` (`board.json`, `board.md`, `live_rows.txt`, `an.py`, `map.py`, `q.py`) |

**Baseline CONFIRMED: 338 / 569 unique comparisons = 59.40 %.**

Arithmetic: `index.json` totals = **570** comparisons / 338 pass / 229 fail / 3 skip.
Minus the one `from_shumway/avm1/*` **nested double-count** → denominator **569**
(playbook standing fact #2). `image_status_diff.py` independently reports an
intersection of **569**. The board triages **228** failing comparisons, not 229:
the missing row is exactly the nested duplicate `from_shumway/avm1/text-bind
[output]` (it is on the board once, under the `from_shumway` stem). The 3 skips
are all `no_expected_image` in `regression/` (`avm2_graphics_runtime`,
`avm2_morph`, `avm2_timeline_solid`).

Per-suite pass/comparisons: avm1 62/69 · avm2 **59/123** · fonts 1/4 ·
gnash-ming 8/18 · gnash-swfmill 2/2 · from_shumway 86/123 · from_shumway/avm1 0/1 ·
import_assets 0/1 · regression 4/7 (3 skip) · stage3d 0/3 · text 1/5 · visual **115/214**.

Board decomposition of the 228 deduped failing comparisons:
**197 live** (180 test×cluster rows) · 31 excluded = **8 hard-dispositioned**
+ **23** Ruffle `known_failure`. Soft `[trace-ign]` rows kept on the board: **6**.

### s16 → s17 delta (verified, not quoted)

`+14 / −0`, exactly the s16 ledger; **0 regressions, 0 NEW, 0 GONE**, bands
**improved 32 / worsened 2**. GAINS: `avm2/bitmapdata_draw_alpha_erase`,
`avm2/edittext_tag_indent`, `avm2/geom_transform`,
`from_gnash/misc-ming.all/GradientFillTest`, `from_shumway/acid/acid-large`,
`visual/cache_as_bitmap/contains_grown_filter`, `visual/cache_as_bitmap/morph`,
`visual/filters/blur_pass_scaling`, `visual/filters/blur_quality`,
`visual/filters/glow_pass_scaling`, `visual/gradient_issue_9892`,
`visual/gradient_nonsequential_ratios`, `visual/gradient_radial_same_ratios`,
`visual/gradient_same_ratios`.

Band histogram (failures): a_epsilon 36→39, b_tiny 24→27, c_small 39→35,
d_moderate 68→62, e_large 41→32, f_catastrophic 33→33, `no_render` 1→**0**.
The mass moved *down*: `e_large` −9 with `f_catastrophic` flat, i.e. s16's work
converted large failures into small ones without creating any new catastrophic row.

**The two worsened bands, read (playbook §15 asked):**
`from_shumway/acid/acid-scale` 302 → **320** (+6 %) and
`visual/simple_shapes/strokes/scale` 66 243 → **70 119** (+6 %). Both are
hairline/extra-ink stroke-width rows and both are consistent with leg C's
−39.2 % vertex reduction changing which sub-pixel the stroke edge lands on.
**`strokes/scale` is a Ruffle `known_failure` and is NOT on the live board at
all** — half of the "2 worsened" is not a flip target and not a regression risk;
the live half is 18 channels on a 2-colour test. Neither is worth a slot.

---

# PART 1 — RANKED, PRICED PIXEL LEADS FOR WAVE 2

Ranked by **mechanism × evidence strength × cost**, not by near-pass distance
(playbook standing fact #3). Leads ALREADY handed off this session are listed in
PART 3 and are **not** re-priced here: cacheAsBitmap `PixelSnapping::Always`
(`w2-gfx-cab-pixelsnap`), `drawGraphicsData`/`lineBitmapStyle`
(`w2-gfx-drawgraphicsdata`), filters cut 2 displacement trio
(`w2-gfx-filters-cut2`), EditText background/border mechanism (A)
(`w2-gfx-edittext-bg`). Stage3D + h264 stay parked.

---

## P1 — **GO, +1 flip, ~6 lines, zero blast radius** — `BitmapData.copyPixels` with an alpha source un-premultiplies through the Flash factor table where Ruffle uses float division + `round()`

| comparison | cluster | band | excess | checks |
|---|---|---|---:|---|
| `avm1/bitmap_data_copypixels [output]` | hairline_edge_drift | b_tiny | **840** | `tolerance 0 / max_outliers 0` |

**The residual is 280 pixels, and every one of them is exactly `−1` on R, G and B
with alpha identical.** Measured from the published PNGs: two blocks
(x 25–34 × y 78–84 and x 425–434 × y 578–584 of a 900×900 frame), expected
`(73,182,137) (95,182,183) (119,85,137) (119,111,163) (119,182,234)`, ours
`(72,181,136) (94,181,182) (118,84,136) (118,110,162) (118,181,233)`. That is not
antialiasing: it is one arithmetic step.

**Oracle.** `~/CC/ruffle/core/src/bitmap/operations.rs:1200-1210`
(`copy_pixels_with_alpha_source`) un-premultiplies the source with **floats and
`.round()`**, then re-premultiplies:

```rust
let a = source_color.alpha() as f64 / 255.0;
let r = (source_color.red() as f64 / a).round() as u8;   // g, b likewise
let intermediate_color = Color::rgba(r, g, b, source_color.alpha())
    .with_alpha(final_alpha).to_premultiplied_alpha(true);
```

Ours (`SWFModernRuntime/src/actionmodern/action.c::bitmapDataCopyPixels`,
**12288–12420**, the `alpha_bmp && transparent` arm) calls `unpremultiplyAlpha()`,
which is the **brute-forced `FLASH_PREMUL_FACTOR` table**
(`action.c:4789`, `((c * factor + 0x8000) >> 16)`). The table is the right oracle
for `getPixel`/`setPixel` (Ruffle's `to_un_multiplied_alpha`,
`bitmap_data.rs:112-152`) — but Ruffle **deliberately does not use it here**; the
comment above the float block says so ("there could be a faster or more accurate
way to do this ... but for now this should suffice"). We ported the wrong one of
Ruffle's two un-premultiply routines into this one function.

Everything else in the arm already matches Ruffle exactly:
`final_alpha = (ab_alpha * sa) >> 8` (`:1189`), `premultiplyAlpha` already does
`(c*a + 127)/255` (`action.c:4749`, = `to_premultiplied_alpha`), and the blend is
`blend_over`'s truncating `/255` (`bitmap_data.rs:164-172`).

**Scope discipline (the trap):** the fix must be *local to this function*.
`premultiplyAlpha`/`unpremultiplyAlpha` have **18 other call sites** in
`action.c` (getPixel32, setPixel, fillRect, noise, compare, applyFilter …), all
of which are correct against `to_un_multiplied_alpha` and several of which are
graded by passing tests. Do **not** change the shared helpers.

**Pricing: +1 flip.** `tolerance 0 / max_outliers 0` with a residual of exactly
±1 means the flip is all-or-nothing; the wave-2 agent must A/B and confirm the
sign (the round can move a channel either way). Independent slot: **YES**.
Second row for the same family but a **different** mechanism, do not bundle:
`from_shumway/acid/acid-bitmapData-copyPixels [output]` = 53 760 excess with
signed deltas of `−40 / −27 / +191`, i.e. structurally wrong pixels, not rounding.

---

## P2 — **GO, +1 flip (high confidence), 1 token change** — the AVM2 runtime gradient ramp rounds where Ruffle truncates

| comparison | cluster | band | excess | checks |
|---|---|---|---:|---|
| `avm2/graphics_gradients_nulls [output]` | hairline_edge_drift | b_tiny | **600** | `tolerance 5 / max_outliers 0` |

The §15 lead "gradient per-channel `GRADIENT_RAMP_ROUND→_TRUNC` /
`_LINEAR_U8→_LINEAR`" is **half confirmed and half refuted**.

### Confirmed half — ROUND → TRUNC, and the golden proves it

`SWFModernRuntime/include/gradient_ramp.h:110-114` rounds (`v += 0.5f`) for the
sRGB path; the recompiler's static path already passes `GRADIENT_RAMP_TRUNC`
(`SWFRecomp/src/swf.cpp:7182`), but **both runtime call sites pass
`GRADIENT_RAMP_ROUND`** (`action.c:28282`, `avm2_display.c:7973`). Ruffle
truncates (`mesh.rs::CommonGradient::new`, `as u8`).

Decisive fingerprint, measured from `graphics_gradients_nulls`'s golden: the test
draws `beginGradientFill("linear", [0,0xFFFFFF,0,0xFFFFFF,0], null, null, m)`, so
the ratio list is `0,63,127,191,255`. I built both ramps from those stops and
compared to the expected PNG's own value set:

* **every distinct grey in the golden's gradient band is a member of the TRUNC ramp** (0 misses),
* **27 of them do not exist anywhere in the ROUND ramp**.

The 600 failing channels are one column (`x = 125`, rows 100–299 × 3 channels),
ours `131` against expected `125`, i.e. `diff 6` at `tolerance 5`. In that
neighbourhood the TRUNC ramp sits exactly **one level below** the ROUND ramp
(`t=32`: 129 vs 130; `t=33`: 133 vs 134), which lands the column at `diff 5` —
inside tolerance, `max_outliers 0` satisfied.

**Blast-radius audit (why this is safe).** I enumerated every image-bearing test
in the corpus (384) and grepped for runtime gradients
(`beginGradientFill`/`lineGradientStyle`). **Exactly 7 hit, and not one of them
currently passes:** `avm1/movieclip_begin_gradient_fill` (723),
`avm1/movieclip_line_gradient_style` (1 420), `avm2/graphics_gradients` (3 338),
`avm2/graphics_gradients_nulls` (600), `avm2/blend_shader_luma_lighten` (1 237),
`visual/filters/displacement_map` (123 218, owned by cut 2), and
`regression/avm2_graphics_runtime` (skipped, no golden). **Zero pixel-regression
risk.** Static (recompiler) gradients are untouched by this change.

### Refuted half — `_LINEAR_U8 → _LINEAR` has no test that can show it

`GRADIENT_RAMP_LINEAR_U8` is only reachable when the AS call passes
`interpolationMethod = "linearRGB"`. **No image-bearing test in the corpus passes
`linearRGB` to a runtime gradient** — `graphics_gradients`'s second gradient
passes the string `"linear"`, which is the *type*, not the interpolation, and
maps to `interp = 0`. So the linearRGB leg is **unpriceable on the pixel axis**:
correct to fix as hygiene, worth **0** flips and **0** band moves, and it must not
be bundled into P2's A/B (it would make the ledger unattributable).

**Caveat the wave-2 agent must respect:** the AVM1 twin (`action.c:28282`) shares
the flag. Its two rows have *mixed-sign* residuals (`begin_gradient_fill`: 27 028
channels at `+1` vs 23 828 at `−1`), so flipping AVM1 to TRUNC may move them
slightly in either direction; neither can flip (both are edge/AA-dominated at
`max_diff 255`). Ship the AVM2 site alone if the A/B disagrees.

**Owner file:** `SWFModernRuntime/src/avm2/avm2_display.c:7973` (one argument).
Independent slot: **YES**, but it is the same function region as
`w2-gfx-drawgraphicsdata`'s `gfx_*` work — self-localise.

---

## P3 — **DIAGNOSE-then-GO, 4 comparisons one mechanism (up to 6)** — AVM2 `DisplayObject.mask` is a no-op for Bitmap / cached / runtime-drawn maskers

The brief lists `cab_mask_filters` as a single item. It is not: **four rows share
one measured signature**, and two more are plausibly the same family.

| comparison | cluster | excess | checks | ink ours/Ruffle | extra ink |
|---|---|---:|---|---|---:|
| `visual/cache_as_bitmap/cab_mask_triangle [output]` | unrelated_content | 5 080 | tol 0 / 200 | 0.900 / 0.107 | 0.896 |
| `visual/cache_as_bitmap/cab_mask_filters [output]` | extra_element | 4 968 | tol 4 / 0 | 0.900 / 0.224 | 0.778 |
| `visual/cache_as_bitmap/cab_mask_alpha [output]` | extra_element | 4 644 | tol 2 / 0 | 0.900 / 0.210 | 0.793 |
| `visual/cache_as_bitmap/cab_mask_transform [output]` | extra_element | 2 340 | tol 4 / 0 | 0.900 / 0.219 | 0.783 |

`ink_frac_actual = 0.9000` on all four — **the identical number**, because in all
four we paint the whole maskee and Ruffle paints only the mask window. The diff
map of `cab_mask_alpha` (80×40, 8 sub-cases: {bitmap masker, graphics masker} ×
{maskee cab, mask cab}²) shows the difference filling **every one of the eight
cells except the mask rectangle interior** — the mask is ignored in all 8, for
both masker kinds, cached or not.

We *do* have an AVM2 mask walk (`avm2_display.c:16074 avm2_push_clip_mask`,
`renderer_begin_clip_mask`), and `visual/cache_as_bitmap/masks` **passes** 7/7 —
so this is not "masks are unimplemented", it is "these maskers never rasterise
into the stencil". Wave-2's first measurement should be which of
`Bitmap`-as-masker / `cacheAsBitmap`-as-masker / runtime-`graphics`-as-masker
produces an empty stencil.

**Adjacent, same family, unpriced:** `visual/cache_as_bitmap/oversize/swf_9_masks`
and `swf_10_masks` (119 943 each, `blank_render`, `tol 128 / max_out 0`) — s16's
P7, still unowned; their `*_too_big` siblings pass only because the mask is
dropped by the SWF-9 size limit, i.e. we pass those for the wrong reason.

**Pricing: 0–4 flips.** The masked result is a bitmap crop with flat colours, so
exactness at `tolerance 2–4` is achievable, but `max_outliers = 0` on three of
the four rows is the risk (the s16 P2/P3/P4 lesson: −99 % excess and no flip).
**Canary risk to state up front:** `visual/cache_as_bitmap/masks`, a **tier-1
canary**, passes with only 3–20 % slack (2 520–3 103 outliers against a 3 200
budget). Any mask/stencil change must re-grade it, and a DIFFERS there is not
automatically a win.

**Owner files:** `SWFModernRuntime/src/avm2/avm2_display.c` (`avm2_push_clip_mask`
16074–16101, the render walk 16040+), `SWFModernRuntime/src/rendering/render_webgpu.c`
(`renderer_begin_clip_mask` / stencil ops). **Conflicts with:** nothing handed
off this session; but it shares `render_webgpu.c` with any filter work.

---

## P4 — **DECOMPOSITION, NOT A LEAD — `blank_render` is 8 mechanisms, 36 live rows** (see PART 2; this is the item the brief flagged as most important)

Do not brief `blank_render` as one item. Full table in **PART 2**.

---

## P5 — **DIAGNOSE (5 rows, band moves, 0–1 flips) — mechanism (B) restated: device-font text has no OUTLINE source at all; it is not a placement bug**

§15/§16 named mechanism (B) "device-font glyph placement under a matrix".
**Refuted.** The measurement:

| comparison | cluster | excess | checks | missing ink | extra ink |
|---|---|---:|---|---:|---:|
| `visual/fonts/leading_device_font [output]` | halo_penumbra | 12 978 | tol 128 / 0 | **0.735** | 0.004 |
| `visual/fonts/device-font [output]` | blank_render | 8 202 | tol 0 / 3 | **1.000** | 0.000 |
| `visual/edittext/edittext_device_transform_negative [output]` | halo_penumbra | 2 619 | tol 0/90 + 128/14 | 0.156 | 0.001 |
| `visual/edittext/edittext_device_transform_basic [output]` | halo_penumbra | 2 386 | tol 0/90 + 128/14 | 0.270 | 0.000 |
| `fonts/device_font_kerning [output]` | missing_element | 1 680 | tol 0 / 0 | **0.693** | 0.000 |

`extra_ink ≈ 0` everywhere: our ink is a strict **subset** of Ruffle's. A
placement/matrix error produces *displaced* ink (extra ≈ missing); this is
**absent** ink. `shift_gain = 0.00` on all five — no translation explains any of
them. In `edittext_device_transform_basic` the whole **left column (embedded
fonts) is pixel-identical**; every differing pixel is in the right column, which
is the same TestFont used as a *device* font.

**Root cause, named.** The recompiler's device-font importer
(`SWFRecomp/src/abc/abc_devicefont.cpp`, 398 lines) reads the test's
`[fonts.*] path = "TestFont.ttf"` with stb_truetype and emits **metrics only** —
`codes`, `advances`, `kern` pairs, ascent/descent/leading. No outlines. The
runtime's built-in Noto fallback is metrics-only too by construction
(`ng_shared.c:500`), and `ng_find_device_fallback_font()` only works when the SWF
itself declares a synthesized `_sans`/`_serif`/`_typewriter`
(memory: `device-font-partial-embedded-fallback`). So device text has **correct
metrics and no glyphs** — which is exactly "right layout, missing ink", and it is
why the trace side of these tests (getCharBoundaries / textWidth) passes.

**The fix is a port, and the oracle is short.** Ruffle builds device glyphs the
same way it builds embedded ones: `core/src/font.rs:284-320` (`get_glyph`) calls
`face.outline_glyph()` into `GlyphToDrawing` (`font.rs:163-196`), which emits
`MoveTo/LineTo/QuadraticCurveTo/CubicCurveTo` with **font units used directly as
twips and Y negated**, filled `FillRule::NonZero` (TTF winding), advance =
`glyph_hor_advance`. stb_truetype's `stbtt_GetGlyphShape` gives exactly that
contour stream, and the file already links stb_truetype and has its own
big-endian table reader.

**Pricing: 0–1 flips, 5 band moves.** `leading_device_font` (`tolerance 128`) is
the one row where coverage alone can pass; the other four are `tolerance 0` rows
with tiny outlier budgets, so they need our rasterisation to agree with Ruffle's
*exactly* — which the embedded column proves is possible when the outlines are
identical, but which the NonZero-vs-EvenOdd fill rule can break. **Traps:**
(1) NonZero fill for TTF contours (our tessellator's default rule is the shape
path's); (2) cubics appear only for CFF/`embedAsCFF=true`; (3) the emitted table
is consumed at `actionIterateTextFieldGlyphs` and by the AVM2 text path — both
must see the new glyph rows.

Also parked in this family and **not** part of (B):
`from_shumway/avm1/text-bind` is hard-dispositioned (different TTF file), and
`avm2/bitmapdata_applyfilter_blur` gained an image-axis ACCEPTED_DIFFS entry in
s16 (30 844 → 28 871, "residual is the default-font text, not the blur").

---

## P6 — **GO (band move, 0–1 flips) — `beginBitmapFill`'s `smooth` flag is parsed and thrown away**

`avm2_display.c:8505` stores `g->cbsmo = gfx_arg_bool(act, 3, 0)` under a comment
that says the renderer ignores it, and `render_webgpu.c:2702-2708`
(`render_webgpu_draw_bitmap_quad_scaled`, the `attachBitmap` / `Bitmap` /
video-fallback path) hard-codes `render_webgpu_bitmap_fill_style_word(0, 0)`
— Nearest — with a comment inviting exactly this patch.

**Which image-bearing tests can show it — the honest list:**

* `avm2/graphics_bitmaps [output]` — 39 988 excess, `same_geometry_wrong_fill`,
  `ink IoU 0.93`, 6.9 % of pixels repainted, **558 vs 759 distinct colours** (the
  nearest-vs-linear signature). Its `Test.as` calls
  `beginBitmapFill(bmd, matrix, true, true)` and `(bmd, matrix, false, false)`
  side by side. Tolerance ladder 8/4000, 16/800, 32/600 — generous.
* `avm1/bitmap_data_copypixels` uses `attachBitmap`, but its residual is P1's ±1,
  not sampling.
* `visual/filters/displacement_map_scales_with_screen` and
  `_through_filters` set `Bitmap.smoothing` — **owned by `w2-gfx-filters-cut2`,
  out of scope here.**

**Refutation of the wider premise:** there is **no** failing image row that
depends on AVM1 `attachBitmap(..., smoothing)`. The AVM1 half of this lead is
worth 0 pixels today; only the AVM2 `Graphics` half is measurable.

**Pricing: 0–1 flips (`graphics_bitmaps`), one large band move.** Owner:
`avm2_display.c` (`gfx_begin_bitmap_fill`, the fill record) +
`render_webgpu.c::render_webgpu_draw_bitmap_tris`. **Canary risk:**
`from_shumway/acid/acid-bitmap-fill` passes with 9.4 % slack and
`acid-bitmap-fill-2` with **3.5 %** — both must be re-graded.

---

## P7 — **HOLD (filters family, adjacent to cut 2)** — `blur_scales_with_screen` 30 810

`same_geometry_wrong_fill`, `tolerance 2 / max_outliers 0`, **max diff 40**,
`ink IoU 0.995`, only 0.29 % of pixels significant. Geometry is right; the blur
kernel's *scale* is slightly off, and 30 810 channels are 3–40 levels out. Its
sibling `any_blur_scales_with_screen` (4 884, `halo_penumbra`, 30 % extra ink) is
a different shape of wrong. Both are in the 27-row filters family whose
displacement slice is already owned. **Completion mechanism:** hand this to the
filters owner *after* cut 2 lands, or to a dedicated blur-scaling agent with
`glow_pass_scaling`'s byte-exactness as the reference; it is not a standalone
slot at `max_outliers = 0`.

---

## P8 — **FREE-PIXEL CANDIDATES: image rows whose TRACE also fails** (s16 standing follow-up)

s16 got two pixel flips for free this way (`bitmapdata_draw_alpha_erase`,
`edittext_tag_indent` — the image failed for the *same* reason as the trace).
The full remaining list at this baseline, all six soft `[trace-ign]` rows plus
three non-flagged ones:

| comparison | trace | pixel excess | pixel checks | read |
|---|---|---:|---|---|
| `avm2/stage_scale_factor` | output_mismatch | **1 912 924** | tol 1 / 0 | `content_displaced`, whole frame. Trace mismatch is about stage scale mode; a correct stage scale almost certainly moves the whole picture. **Highest-value dual-axis row on the board.** |
| `avm2/netstream_play_flv` | output_mismatch | 229 724 | tol 1 / 0 | `blank_render`. See PART 2 M3a — a band move, **not** a flip (its AVM1 twin lands at 44 residual outliers and is ACCEPTED_DIFFS) |
| `from_shumway/acid/acid-shapes` | output_mismatch | 78 982 | tol 200 / 0 | `blank_render`, ours has **4** colours vs 6 802. Trace-first: fix the script failure, then re-read |
| `avm2/netstream_seek_flv` | output_mismatch | 40 672 | tol 30 / 271 | same decoder wiring as above |
| `avm2/graphics_draw_path` | ruffle_matched | 764 | tol 0 / 0 | trace matches Ruffle's *known-failure* output — Ruffle is not the oracle; pixels are a separate question |
| `avm2/displayobject_hittestpoint_boundary` | output_mismatch | **76** | tol 0 / 900 | 976 outliers against a 900 budget — 76 channels from a flip. Cheapest row here |
| `avm2/displayobject_scrollrect` | output_mismatch | **4** | tol 0 / 0 | 4 channels. Cheapest row on the entire board |
| `from_shumway/acid/acid-text-x` | ruffle_matched | 6 | tol 0 / 0 | 2 pixels |
| `visual/edittext/edittext_device_transform_negative` | ruffle_matched | 2 619 | tol 0/90 | P5's device-font family |

**Recommendation:** hand `displayobject_scrollrect` (4) and
`displayobject_hittestpoint_boundary` (76) to whoever owns their trace rows this
session — they are two lines of measurement, not a slot. Flag
`stage_scale_factor` to the trace board as a dual-axis row worth 1.9 M channels.

---

## P9 — **`hairline_edge_drift` re-check: which near-passes are NOT antialiasing**

58 live hairline rows. The cluster is mostly the lavapipe-AA gap, but **five rows
are arithmetic, not AA**, and two of them are already priced above:

| comparison | excess | max diff | verdict |
|---|---:|---:|---|
| `avm1/bitmap_data_copypixels` | 840 | **1** | **NOT AA** — uniform `−1` on 280 px. → **P1, +1 flip** |
| `avm2/graphics_gradients_nulls` | 600 | **6** | **NOT AA** — one ramp texel column. → **P2, +1 flip** |
| `avm2/bitmapdata_colortransform` | 726 | 125 | **NOT AA** — 30 666 px sit at a uniform `+1` (signed mean 0.99/1.05/1.08); only a handful of channels exceed `tolerance 5`. A `ColorTransform` rounding port; the +1 field is free, the >5 tail needs its own read. **Unpriced, cheap to diagnose** |
| `visual/drawing_api/gradient_focal_point` | 60 | 39 | **NOT AA** — 34 830 px differ with mean −0.115 and 60 channels over `tolerance 13`: the focal-gradient parameterisation diverges near the focal point. Small, hard, unpriced |
| `from_shumway/acid/acid-gradient` | 6 639 | 189 | mixed; gradient geometry, unread this session |

**Everything else in the cluster is AA-shaped and should not be briefed**, and I
can now say that precisely: the 12 rows the classifier marks `uniform_shift` at
`max_diff 255` are single-pixel on/off ties (e.g. `visual/fonts/duplicate_font` =
**1 pixel**, `avm1/edittext_stylesheet` = **2 pixels** at exactly 95,
`visual/fonts/glyph` = 2 pixels, `avm2/mouse_pick_dobj_mask` = 2 pixels). The
fonts near-pass family the brief asked me to read is entirely of this kind after
leg C — `glyph` 6, `duplicate_font` 3, `match_style` 12, `fallback_preferences`
156, all with `ink_iou ≥ 0.999`, `missing_ink ≤ 0.001` and `shift_gain 0.00`.
**Leg C did not move them and nothing short of matching lavapipe's rasteriser
will.** Keep them capped.

---

# PART 2 — THE `blank_render` DECOMPOSITION (the brief's headline ask)

38 comparisons, **36 live** (2 excluded: `avm1/netstream_play_flv_screen`
hard-dispositioned, `from_shumway/acid/acid-bitmap-draw_quality_low` Ruffle
`known_failure`). §15 said "41 live, five unrelated causes" — **the count is
stale (36) and the cause count is low: there are eight.**

| # | mechanism | live cmps | excess range | owner file(s) | priced flips |
|---:|---|---:|---|---|---|
| M1 | **Stage3D / Context3D has no GPU backend** — `avm2_stage3d.c` is a 2 579-line *API + argument validator* (its own header says the 21 render-only siblings only grade the validator); nothing reaches `render_webgpu.c` | **24** (21 `avm2/stage3d_*` + `stage3d/scissor_rectangle`, `_invalid`, `sampler_odd_size`) | 85 740 – 1 920 000 | `SWFModernRuntime/src/avm2/avm2_stage3d.c`; a new 3D pipeline in `render_webgpu.c` | **0 — PARKED ARC** |
| M2 | **Pixel Bender / `Shader` byte-code is not executed** | 1 (`avm2/pixelbender_dithering`, 2 744 871) | — | `avm2_display.c` shader stubs (`beginShaderFill` is bound to `gfx_begin_bitmap_fill`, `:14490`) | **0 — PARKED** (family also owns `glassDisplace`, `_shaderfilter`, `blend_shader_luma_lighten`, `shader_as_mask` in other clusters) |
| M3a | **AVM2 `NetStream` never feeds the Sorenson decoder we already ship** — `video_codec.c` decodes FLV/H.263 for AVM1 (`avm1/netstream_play_flv` = 44 residual outliers), the AVM2 path renders nothing | 2 (`avm2/netstream_play_flv` 229 724, `avm2/netstream_seek_flv` 40 672) | — | `SWFModernRuntime/src/avm2/avm2_media.c` + `actionmodern/video_codec.c` | **0 flips, 2 big band moves** — the AVM1 twin's own residual is ACCEPTED_DIFFS (Sorenson parity), so expect ~44 outliers at `tolerance 1 / max_outliers 0` and a new disposition entry, not a pass |
| M3b | **No H.264 decoder** | 1 here (`visual/video/h264_multinalu` 172 800) + 10 `h264 [frame*]` rows in `unrelated_content` | — | — | **0 — PARKED ARC** (11 comparisons family-wide, unchanged since s15) |
| M4 | **No JPEG XR decoder** — `avm2_display.c:5740` says so explicitly ("stb cannot read it") | 2 (`avm2/loader_jpegxr` 136 033, `loader_jpegxr_alpha` 10 074) | — | `avm2_display.c` loader sniffer (`:4987`, `:5740`) | **0 — parked** (a JPEG-XR decoder is a library import, not a fix) |
| M5 | **AVM2 mask on a scaled masker** (P3's adjacent pair) | 2 (`cache_as_bitmap/oversize/swf_9_masks`, `swf_10_masks`, 119 943 each) | — | `avm2_display.c` mask walk + `render_webgpu.c` stencil | **0–2** — folds into P3's slot |
| M6 | **Font arcs with no glyph source** | 2 — `visual/definefont4` (16 086; DefineFont4 = embedded CFF/TLF, expected image has just **2** colours) and `visual/fonts/device-font` (8 202; P5's device-font outlines, `missing_ink = 1.000`) | — | `SWFRecomp/src/swf.cpp` (DefineFont4 tag), `SWFRecomp/src/abc/abc_devicefont.cpp` + `ng_shared.c` | **0–1** — `device-font` rides P5; `definefont4` is its own feature arc |
| M7 | **`BitmapData.draw` at `quality = "high"`** — we render a flat stage where Ruffle draws the full acid scene | 1 (`from_shumway/acid/acid-bitmap-draw_quality_high`, 194 784, `tol 5/35000 + 32/700 + 64/0`) | — | `action.c` `BitmapData.draw` / offscreen capture path | **0–1, undiagnosed** — its `_low` twin is a Ruffle `known_failure`, so the pair cannot both pay |
| M8 | **`acid-shapes` — dual-axis** (trace `output_mismatch` too; ours renders 4 colours, Ruffle 6 802) | 1 (78 982) | — | trace-side owner first | **0 — trace-first** |

**Totals: 36 live = 24 + 1 + 2 + 1 + 2 + 2 + 2 + 1 + 1.**
**25 of 36 (69 %) are the two parked backends (Stage3D + Pixel Bender).** The
addressable remainder is 11 comparisons across six mechanisms, and only three of
them (M5, M6, M7) are worth a wave-2 slot at all — M5 inside P3, M6 inside P5.
Anyone briefed on "blank_render" as one item will mis-scope it exactly the way
s15's `no_render` brief would have.

---

# PART 3 — §15 LEADS AUDIT, HANDOFFS, DISPOSITIONS, CANARY

## §15 "Top remaining leads", checked against run `31877239992`

| §15 claim | status | evidence |
|---|---|---|
| cacheAsBitmap `PixelSnapping::Always` (+1 to +4) | **CONFIRMED, HANDED OFF** → `w2-gfx-cab-pixelsnap` | `offset_translation` is still 3 rows (`cache_as_bitmap/text` 7 410, `text/br_at_start` 14 411, `edittext_hscroll [output.02]` 960) |
| `drawGraphicsData` is validation-only + `lineBitmapStyle` | **CONFIRMED, HANDED OFF** → `w2-gfx-drawgraphicsdata` | `avm2_display.c:14487-14489` binds `lineBitmapStyle`, `lineGradientStyle` **and** `lineShaderStyle` to `gfx_line_fill_style`, which clears the style and returns |
| filters cut 2 (displacement trio) | **CONFIRMED, HANDED OFF** → `w2-gfx-filters-cut2` | `displacement_map` 123 218, `_scales_with_screen` 99 353, `_through_filters` 27 565 |
| EditText background/border family "31 live comparisons, at least two mechanisms" | **(A) HANDED OFF** → `w2-gfx-edittext-bg`; **(B) REFUTED AND RESTATED** → P5 | The family is **not** 31 rows any more; `halo_penumbra` is 11 (was 13) and the EditText slice of it is 6. (B) is "no device-font outlines", not "placement under a matrix" — `extra_ink ≈ 0`, `shift_gain = 0` on all five rows |
| `acid-filter` 482 and `simple_shapes/masks` 181 "hairline/tessellation-tie territory" | **CONFIRMED** | `acid-filter` 482, `100 % on edges, 0 % survives erosion, ink IoU 0.994`; `masks`/`masks_equal_clipdepth` 181 each, still hard-dispositioned |
| "`blank_render` bucket (41 live), five unrelated causes" | **NUMBER + COUNT BOTH REFUTED** | **36** live, **eight** mechanisms — PART 2 |
| `acid-gradient-2` residual "79" | **STALE BY ONE RUN** | 12 555 → **56** at the closeout run (79 was run `31874872388`), `a_epsilon`, 13 tiny bands, `ink_iou 0.995` — a tessellation tie now, not a fill defect |
| `graphics_gradients_nulls` 600 "blocked by max_outliers = 0" | **REFUTED — it is one ramp texel** | → **P2, +1 flip** |
| `acid-blend-2 [output.15]` slack after leg C | **CONFIRMED, and it is the thinnest margin in the blend family** | 5 926 outliers against a 6 000 budget = **74 channels (1.2 %)**. Siblings: `[output.10]` 4 114/5 000, `[output.20]` 5 286/5 500, `[output.26]` 5 618/6 000, `[output.40]` 8 506/9 000. It is a tier-2 canary — any tessellation or blend change must re-grade it |
| Stage3D (29 family-wide) + h264 (11 + FLV seek) parked | **CONFIRMED** | 24 `blank_render` Stage3D rows + `pixelbender_dithering`; h264 = 1 `blank_render` + 10 `unrelated_content` |
| Recompiler-output movers | **READ** | `from_shumway/3_joystick` 7 482 → **307** (b_tiny, `ink_iou 0.999`, edge-only); `from_shumway/gradientTransform` 1 441 → **9** but it is a Ruffle `known_failure`, so it is **not on the live board**; `from_shumway/bitmapbuttons` **618 042** with `missing_ink 0.985` (98 % of Ruffle's ink absent — the s12 DEFER still stands, it is a button-state/bitmap arc, not a polish row); `avm2/away3d_advanced_shallow_water_demo` **1 331 281**, 26 colours vs 36 006 — Stage3D content, parked with M1 |
| `visual/definefont4`, `acid-shapes`, `netstream_play_flv`, `graphics_bitmap*` | **PRICED** | definefont4 / acid-shapes / netstream → PART 2 M6, M8, M3a. `graphics_bitmap_fill` 136 030 → **76 810** (`missing_element`, 56 % of Ruffle's ink still absent at `tol 5 / max_out 60` — the s16 bitmap-fill route landed but half the picture is still unpainted, undiagnosed); `graphics_bitmaps` 185 430 → **39 988** → **P6** |

## Disposition audit (playbook §3)

- **Hard exclusions: 8** (was 7). The new one is
  `avm2/bitmapdata_applyfilter_blur` (s16's image-axis ACCEPTED_DIFFS entry,
  "residual is the default-font text, not the blur"). All eight resolve `exact`
  through an `<!-- image-axis: … -->` scope marker or an unambiguous test name;
  **no basename matches remain**.
- **Soft `[trace-ign]` rows kept on the board: 6** (was 9). Three left by
  *passing*: `bitmapdata_draw_alpha_erase`, `edittext_tag_indent` (both flipped
  on both axes) and `geom_transform`. The remaining six are all in P8.
- **Ruffle `known_failure`: 23**, set unchanged. Two of them matter for pricing:
  `acid-bitmap-draw_quality_low` (caps M7 at +1) and
  `visual/simple_shapes/strokes/scale` (one of the two "worsened" bands is
  therefore not a live row).
- **STALE entries (dispositioned but now PASSING): 2**, unchanged —
  `avm1/display_object_properties`, `from_gnash/misc-ming.all/loop/simple_loop_test`.
  Both docs already carry explicit `**STALE**` annotations; not new doc debt.
- **Frame-phase suspects: 0.** Four tests carry more than one cluster
  (`cache_as_bitmap/edittext_hscroll`, `cache_as_bitmap/edittext_selection`,
  `visual/video/h264`, `edittext/edittext_border_transform`); in each the split
  is amplitude, not phase.
- **`png_unavailable`: 0** — the local corpus is still in sync with CI.

## Canary audit (s15 rule) — the standing set does NOT cover three of this session's four handed-off change classes

`ruffle-tests/render_canary_tests.txt`, 18 tier-1 + 7 tier-2 members:

| handed-off change class | covered? | by what | recommended addition |
|---|---|---|---|
| cacheAsBitmap offsets (`PixelSnapping::Always`) | **partly** | `visual/cache_as_bitmap/masks` (7 cmps) and `shape_changed` are tier 1 — but **no member puts TEXT inside a cached surface**, which is what all three pixelsnap targets do | the family's only fully-passing cab+text-ish neighbours are `cache_as_bitmap/color_transform` / `children_changed`; if none carries text, state the blind spot. **`masks` has only 3–20 % outlier slack — treat a DIFFERS there as a warning, not a win** |
| AVM2 `Graphics` vector fills/strokes with **bitmap styles** | **NO** | the set has zero AVM2 runtime-`Graphics` member with a bitmap style; `avm1/mask_with_drawing` is the AVM1 drawing API and `regression/avm2_graphics_runtime` has **no golden** (skipped) | **`from_shumway/acid/acid-bitmap-fill`** (playbook's own suggestion; passing, 9.4 % slack, `0x40` repeating smoothed fill) **and `acid-bitmap-fill-2`** (passing, 3.5 % slack — the tightest bitmap row in the corpus) |
| displacement filters | **NO** | tier 1 has `glow_pass_scaling` (AVM2 `.filters`) and `bitmapdata_applyfilter_colormatrix` (CPU applyFilter); neither exercises a displacement map | **`visual/filters/displacement_map_through_applyFilter`** — it PASSES (max diff 2 vs `tolerance 4`) and is the only CI-passing displacement row in the corpus. Tier 1 |
| EditText background/border | **NO** | `avm1/edittext_tag_indent` covers EditText *layout*, not the background/border rects | **`visual/edittext/edittext_border_transform`** — 4 of its 6 comparisons pass at `tolerance 0`, so it is a real border canary (add as tier 1 for the passing comparisons; the 2 failing ones are A/B-only) |
| P2's gradient ramp (if briefed) | **yes** | `from_shumway/acid/acid-gradient-0`, `regression/avm2_timeline_gradients`, `regression/avm2_timeline_stroke_gradient` — but all three are **static** gradients; the runtime ramp has no passing representative anywhere (all 7 runtime-gradient image tests fail). State the blind spot rather than inventing a member |


## Sibling owner-file conflicts (checked against `SIBLING_FILE_MAP.md`)

| lead | files it needs | collides with | verdict |
|---|---|---|---|
| P1 copyPixels | `action.c` 12288–12420 (+ read-only 4749/4789) | `w2-crossvm-legE` (`actionTickAvm1ChildrenUnderAvm2`/`processTimers`), `w2-sound-load` (Sound region) | **clean** — three disjoint regions of a 50 k-line file |
| P2 gradient ramp | `avm2_display.c:7973` (one argument) | `avm2_display.c` is the session's busiest file: `w2-avm2-smalls` (hit-test), `w2-crossvm-legE` (mouse-pick walk), `w2-gfx-drawgraphicsdata` (`gfx_draw_graphics_data` ~8819), `w2-gfx-filters-cut2` (`.filters` path), `w2-scrollrect` (`display_world_matrix`) | **clean but crowded** — nearest neighbour is 850 lines away; a one-token change, ideal to bundle into an existing `avm2_display.c` slot rather than open a sixth |
| P3 AVM2 masks | `avm2_display.c` 16040–16101 **+ `render_webgpu.c` stencil** | `render_webgpu.c` is also touched by `w2-gfx-cab-pixelsnap` (`compose_children` snap) and `w2-gfx-filters-cut2` (displacement shader/uniforms) | **REAL RISK** — stencil state and the compose path interact; serialise this after cab-pixelsnap or require a `static` helper |
| P5 device-font outlines | `SWFRecomp/src/abc/abc_devicefont.cpp` (unowned), `ng_shared.c`, `action.c actionIterateTextFieldGlyphs` | **`w2-gfx-edittext-bg` (pending) owns `tag.c` / `ng_shared.c` / the edittext render path** | **CONFLICT** — same family, same files. Either give (A) and (B) to one agent or make (B) recompiler-only (`abc_devicefont.cpp` + the generated table) and defer the consumer edit |
| P6 bitmap smoothing | `avm2_display.c:8468-8508`, `render_webgpu.c::render_webgpu_draw_bitmap_tris` | `w2-gfx-drawgraphicsdata` edits `gfx_draw_graphics_data` at ~8819 — **350 lines away, and it consumes the same fill records** | **coordinate** — the two patches touch the same `Avm2GraphicsExt` fill-record struct; whoever lands second must re-check the other's ledger |
| P7 blur scaling | `avm2_display.c` filter passes, `avm2_filters.c` | `w2-gfx-filters-cut2` owns exactly these | **HOLD** — not a separate slot by construction |

---

# APPENDIX — how to reproduce anything above

Scratch (this session, not committed):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ab0a66b8-f5eb-4947-8b92-d32ad2d435e1/scratchpad/w1gfxboard/`

- `image-results/` — `git archive origin/ruffle-image-results` at `bfecef0ad`
- `board.json` / `board.md` — the raw triage board (copied to `*.rawboard.md`)
- `live_rows.txt` — all 197 live comparisons, cluster-sorted, with tolerances
- `q.py` — query any test's row across all 12 stems (passing rows included, which
  is how the canary slack numbers were measured)
- `an.py` — per-comparison diff histogram + signed-delta census from the PNGs
- `map.py` — coarse DIFF / ours-ink / Ruffle-ink ASCII maps
- `imgtests.txt` — the 384 image-bearing tests (the blast-radius denominators)

No test was run locally by this agent and **no main-tree file outside
`SWFRecompDocs/plans/session17-fanout-reports/` was written**; every number above
comes from the merged CI stems and the published PNGs.
