# Filters arc — scoping

**Status**: **CLOSED 2026-07-30** — F1 + F2 shipped, F3 measured and NOT
landed (§6). CI `30555976332` graphics/full: **+16, zero regressions**
against a +12 prediction. Census was 15 direct targets (13 filter tests +
2 uncaught-error riders), predicted +12.

Oracle: Ruffle @ `437be1498` (re-fetched from upstream this session; was
`75c3cec57`). The original PROVENANCE CAVEAT here — that the local clone had
corrupted `ConvolutionFilter.as` text and a gradient bug in `filters.rs` — is
**withdrawn**: both are upstream's own content, see §6 "Provenance
correction". `output.txt` remains the authority for every rule and none of
the targets is `known_failure`.

## 1. The structural key

**AVM2 filter classes do ZERO coercion.** They are pure-AS sealed value
bags (`core/src/avm2/globals/flash/filters/*.as` — no Rust natives, no
version gates); constructors just assign. Every clamping/quantization
behavior the nine `*_filter` tests grade happens in the
**`DisplayObject.filters` round-trip**: AS object → native `swf::Filter`
struct → *freshly constructed* AS object (`core/src/avm2/filters.rs`).
Each test reads values back out of `test.filters[i]`, never from the
object it constructed. So our port is: (a) nine trivial slot classes +
three enum classes, (b) ONE conversion layer owning all the quantization,
(c) PlaceObject-tag filters parsed into the same internal representation
(the tests' `.fla`s pre-bake 2-3 filters on the `test` symbol and dump
them — the SWF-tag→AS direction shows the identical quantization).

Contrast: the AVM1 side is already REAL and passing (`avm1/bitmap_filters`
548/548, `native_subclasses` 191/191, from_shumway `avm1/filters`
149/149) via virtual prototype properties in `action.c` ~39280; the AVM1
`_global` stub ctors at `action.c:38968` feed the decls dumps. AVM1 is
NOT touched by this arc except the one-line `avm1_convolution_initialization`
quirk (§4).

## 2. Quantization rules (filters.rs, verified against recorded output)

- blurX/blurY: `max(0.0)` then **Fixed16** (1/65536). Negative → 0, NO
  upper bound (AVM1 clamps 0..255 — do not copy that here).
- quality: `coerce_to_u32.clamp(0,15)` → passes bitfield → reads back int.
- strength: `clamp(0.0,255.0)` → **Fixed8** (1/256): `0.63671875`,
  `1.19921875` are graded verbatim.
- alpha family: `(a*255.0) as u8` saturating (−1→0, >1→255); read back
  a/255 — `0.5` → `0.4980392156862745`.
- color family: keep low 3 bytes, read back as positive int (`11259375`).
- angle: `to_radians()` → Fixed16 → `to_degrees()` — 45 reads back
  `44.999253346524966`; tag-authored 0 reads `359.9992723574823`.
- distance: Fixed16, NO clamp, negatives preserved.
- type strings: `"inner"`→inner, `"outer"`→outer, ANYTHING else→`"full"`,
  no error.
- ColorMatrixFilter.matrix: fixed 20 × f32, copy min(20,len),
  `coerce_to_number` per element, holes→0.0; `[]` → 20 zeros. The AS
  class getter/setter COPY the array (use `AS3::concat` semantics — the
  public-namespace subclass-of-Array trap is documented in the .as).
- ConvolutionFilter: matrix `Vec<f32>` then `resize(matrixX*matrixY, 0)`
  (grows AND truncates); matrixX/Y `clamp(0,255) as u8`; bias/divisor
  plain `as f32` — the graded `0.10000000149011612` / `1.100000023841858`
  are f32-widened doubles printed shortest-round-trip.
- DisplacementMapFilter: scales `as f32`; componentX/Y truncating u8;
  mapPoint via `coerce_to_i32` (Point(1.5,-2) → (1,-2)); **mode is the
  ONLY throwing path** — unrecognized STRING → #2008, non-string →
  silently "wrap"; mapBitmap round-trips to null.
- Gradient colors/alphas/ratios: common length =
  **min(len(colors),len(alphas),len(ratios))** — short arrays truncate
  all three; ratio clamp 0..255 u8; read back as NEW arrays. Values come
  from their RESPECTIVE arrays (the fork's filters.rs bug reads all from
  colors — implement the correct rule; no graded line exercises it).
- ShaderFilter: 4 extensions `coerce_to_i32`; `shader` kept BY IDENTITY
  through the round-trip (ShaderFilter object differs, `.shader` ===).
  Ruffle panics on a null-shader ShaderFilter in the setter — do NOT
  copy; error or ignore gracefully.

## 3. The DisplayObject.filters contract (displayobject_filters, 17 lines)

- Getter: brand-new Array of brand-new filter objects EVERY call
  (`o.filters === o.filters` is FALSE).
- Setter is a VALUE conversion — mutating the AS object afterwards has
  no effect.
- Non-Object arg (undefined/null/number) → CLEARS to empty, no error.
- Object-but-not-Array → **silent no-op** (previous list preserved).
- Non-filter ELEMENT → #2005 "Parameter 0 … type Filter" — the index is
  HARDCODED 0 whatever the position, and the throw happens BEFORE the
  store (previous list preserved).
- True array holes are SKIPPED silently (undefined stored is NOT a hole
  — it throws #2005).
- Non-empty filters forces cacheAsBitmap ON (recheck on change only);
  blendMode untouched.

## 4. Census and tranches

### F1 — value objects + the filters round-trip + tag parsing · predicted +8 of 10 · MEDIUM-LARGE
Targets: the nine `*_filter` tests (blur 44, color_matrix 20, convolution
90, displacement_map 62, glow 128, drop_shadow 173, bevel 188,
gradient_bevel 207, gradient_glow 207 — shared shape: tag-authored dump →
`filters=[]` → defaults round-trip → 1-2 hostile-args round-trips, one
property per trace, blank line after each; empty list/array traces an
EMPTY line) + `displayobject_filters` (17). Precision watch:
`color_matrix_filter`, `convolution_filter`, `displacement_map_filter`
have NO epsilon — the f32-widening prints must be bit-exact
(shortest-round-trip formatting already exists; the f32→f64 widen must
happen before formatting). `blur` ε=1e-5, dropshadow/glow/gradients
ε=1e-3, bevel ε=0.01 (the angle round-trip). Requires PlaceObject
filter-LIST parsing (tag.c currently carries only filter_blur_x/y —
check what the recompiler emits for filter tags first; this is the
least-known cost in the arc). GradientBevel/GradientGlow must keep
IDENTICAL slot order. Hedge: the two exact-match convolution/displacement
tests and one gradient test are the likeliest misses.

### F2 — the three odd ones · predicted +2 of 3 · SMALL-MEDIUM
- `filters_array_holes` (25): NOT about .filters holes — holes in
  matrix/colors/alphas/ratios arrays, graded via `applyFilter` +
  `getPixel32` hex. Needs a real CPU `BitmapData.applyFilter` for
  ColorMatrixFilter (4×5 per-pixel multiply) and the rule that a
  ZERO-BLUR gradient bevel/glow (blur 0, distance 0) is a passthrough
  no-op. applyFilter for other filter kinds can stay no-op.
- `glassDisplace_shaderfilter` (4): Rectangle.toString + the identity
  contract + `generateFilterRect`, whose ShaderFilter arm returns
  `this.rect.clone()` IGNORING sourceRect (the 512×512 is
  max(mandelbrot 512², flowers 500×375) — nothing to do with extensions);
  all other filter kinds return `sourceRect.clone()` (Ruffle stubs them
  too — do the same).
- `visual/filters/avm1_convolution_initialization` (17/18): AVM1 quirk —
  a ConvolutionFilter constructed WITH the 8th (color) argument forces
  the alpha byte to 255 ("despite the documentation"; AVM2 does NOT do
  this). One line. AVM1 canaries mandatory (§5).

### F3 — uncaught-error-tracing re-land · predicted +2 · SMALL
Re-land `3b401b5f9` (reverted in `d1c307c51`; avm2_error.c +
avm2_function.c only). Its filter blockers are exactly the six
zero-trace image-only avm2 `bitmapdata_*` tests (constructibility +
applyFilter/draw ACCEPTING the objects — F1/F2 provide). Collects
`uncaught_error_basic` (Error: hello + `\tat Test()`) and
`loader_method` (#1034 + `\tat Test/onFrame()`); `loader_load` tail may
promote. Those six image tests must STAY silent passes.

Non-targets recorded: partial-line progress lands free in
`stage_properties2`, avm1 decls dumps, `all_classes/display/*`, gnash
`MovieClip-v8` — none expected to flip.

**Arc prediction: +12 of 15.**

## 5. Canaries and blast radius

51 corpus files read `.filters`; 38 tests touching filters PASS today.
Two canary classes:
- REAL passes that must not move: `avm1/bitmap_filters` (548 lines — the
  AVM1 convolution quirk fix is adjacent; stash-diff it),
  `avm1/native_subclasses` 191, from_shumway `avm1/filters` 149,
  `avm1/displacementmapfilter_mappoint_throw_error`, `globals_swf6/7/8`,
  the visual/filters render set, cache_as_bitmap pair.
- TRIVIAL 0/0 passes that go LIVE when classes exist: the six avm2
  `bitmapdata_applyfilter_*`/`draw_filters`/`filter_sourcerect` tests —
  after F1 they construct real filters and call applyFilter; they must
  stay trace-silent (the PB-effect-tests dynamic from shader P1/P2).
Also: `avm2_builtin_class MINTS and rebinds, never looks up` — the
existing BitmapFilter shell (avm2_text.c, shared by ShaderFilter in
avm2_pixelbender.c) and DropShadowFilter stub must be taken over the way
S1 took over Matrix3D (delete the shell, share via accessor), or the
shader arc's ShaderFilter silently forks its base class.

## 6. Postmortems

### Arc result — CI `30555976332` (graphics/full, baseline `41d8d6865`)

**+16, zero regressions, zero other status moves.** Corpus 4018 → 4034 of
4421 (91.2%); avm2 1006 → 1019, from_shumway 183 → 185, visual 136 → 137.
Histogram flat (`ruffle_matched` 241 → 241, `runtime_error` 7 → 7,
`recomp_fail` 1 → 1, no segfault/timeout/compile_fail). Prediction was +12
**including** F3; F1+F2 alone delivered +16 and F3 did not land (below).

| tranche | predicted | landed | commit |
|---|---|---|---|
| F1 value objects + round trip + tag parsing | +8 of 10 | **+11** (10 census + `filter_rewind`) | `a250f0573` |
| F2 the three odd ones | +2 of 3 | **+3** | `0612bc78e` |
| F3 uncaught-error re-land | +2 | **0 — not landed**, costs 22 | — |
| unscoped riders | — | +2 (`from_shumway acid/acid-filter`, `timeline/nav/filters`) | |

### F1 — the tag path was in a different table than the census assumed

The scoping called PlaceObject3 filter parsing "the least-known cost", and it
was the only real cost — but not where §1 looked. `tag.c` DOES carry a full
eight-kind filter list (`tagBeginFilterList` / `ng_getFilterListDataByDepth`,
feeding the AVM1 `mc.filters` getter), which made the tag half look nearly
free. It is unreachable from AVM2: an AVM2 movie runs `abc_timeline.c`'s
static `Avm2TimelineData` tables and never executes `tagMain.c` at all
(`app_context.frame_funcs` is NULL). `abc_timeline.cpp` had a
`skipFilterList` and nothing else. **Two runtimes, two tag tables — check
which one the VM under test actually reads before pricing a tag feature.**

Second structural finding, cheap once seen: keep the SWF's own fixed-point
BITS in the native value (`Avm2FilterVal`) rather than a re-derived double.
A tag-authored filter and a script-authored one then reach AS through
exactly one division, so they quantize identically and the tag path needs no
re-quantization pass. The alternative — storing dequantized doubles and
re-quantizing on import — silently loses alpha bytes: `229/255*255` is
`228.99999999999997` in IEEE, and the truncating cast turns 229 into 228.

Precision worked out exactly as §2 predicted, with one confirmation worth
recording: `strength` 1.2 reading back as the graded `1.19921875` (307/256)
**proves** `Fixed8::from_f64` truncates rather than rounds, and that pins
every other fixed-point conversion in the file at once.

`filter_rewind` (not in the census, 2/8 at baseline) went to 7/8 for free
from the tag parse, and to 8/8 with one line: a fresh (non-MOVE) placement
carrying no filter list must CLEAR the depth. Our runtime reuses the display
object across a rewind, so without the clear it kept the filters a later
frame had given it. A plain MOVE keeps them.

### F2 — three tests, three unrelated mechanisms, all small

`filters_array_holes` needed a real CPU `applyFilter`; the color-matrix pass
is a direct port of `color_matrix.wgsl` (unpremultiply → 4×5 in 0..1 with the
bias column over 255 → clamp → re-premultiply), and the zero-blur gradient
passthrough is a straight copy. `generateFilterRect` was not registered at
all; its ShaderFilter arm ignores `sourceRect` entirely. The AVM1
convolution quirk was one line, and all seven AVM1 canaries (`bitmap_filters`
548, `native_subclasses` 191, from_shumway `avm1/filters` 149, the mapPoint
throw, `globals_swf6/7/8`) stayed green.

### F3 — NOT LANDED: the blocker census was 34, not 6

The scoping said F3's blockers were "exactly the six zero-trace image-only
avm2 `bitmapdata_*` tests". That under-read `d1c307c51`'s own revert message,
which lists ~18 causes across 71 tests. Measured directly this session (the
re-land applied to a worktree, then every at-risk test re-run):

**The risk set is computable, not guessable.** `results.json` records
`error_signature` for PASSING tests too, and it is populated from exactly one
source — `print_uncaught`'s stderr line. So *every* test that can regress on
this change is `status == pass AND error_signature != null`, no sweep needed
to find them. Today that is **34 tests** (21 avm2, 13 visual); across the
whole corpus nothing else can move.

F1 closed **12 of the 34** (the BlurFilter / ColorMatrixFilter / GlowFilter /
`filters=` ones, including six of the seven `bitmapdata_*`). Re-running the
remaining 22 with the re-land applied: **all 22 regress**, against a gain of
~4. Net −18. Not landed; `avm2_error.c` + `avm2_function.c` are untouched.

The remaining 22, grouped — this is the ready-made worklist, and F3 lands
the day it is empty:

| cause | tests |
|---|---|
| `BitmapDataChannel` undefined | `bitmapdata_copychannel`, visual `filters/displacement_map{,_scales_with_screen,_through_applyFilter,_through_filters}` (5) |
| Graphics API gaps (`lineBitmapStyle`, `lineGradientStyle`, `drawRoundRectComplex`, `CapsStyle`, `GraphicsBitmapFill`) | `graphics_bitmaps`, `graphics_gradients`, `graphics_round_rects`, `graphics_direct_commands`, `graphics_bitmap_fill` (5) |
| Stage3D | `stage3d_bitmap`, `stage3d_raytrace`, `stage3d_texture` (3) |
| `Video` undefined | visual `video/h264`, `video/h264_multinalu` (2) |
| `PNGEncoderOptions` | `bitmapdata_colortransform` (1) |
| `BreakOpportunity` | visual `definefont4` (1) |
| ColorTransform property creation (#1056) | `displayobject_colortransform_nested` (1) |
| `away3d` `recompose` (#1006) | `away3d_advanced_shallow_water_demo` (1) |
| `registerFont` rejects a valid font (#1508) | `font_enumeratefonts` (1) |
| **real bug in the re-land**: the error prints TWICE for a loaded SWF's root ctor | `loader_error_in_root_ctor` (1) |
| output shifts after the traced line | `remove_child_clear_field` (1) |

Two of those are evidence *about* the re-land rather than about a platform
gap. `loader_error_in_root_ctor`'s expected output CONTAINS the traced error
once — so Flash really does trace uncaught errors, we already emit it through
another path, and `print_uncaught` duplicates it. Fix that before the next
attempt. Conversely `font_enumeratefonts` expects NO trace, which means the
#1508 is ours and Flash never threw it.

### Provenance correction

The scoping's PROVENANCE CAVEAT is wrong and should not be carried forward.
`~/CC/ruffle` was re-fetched from `https://github.com/ruffle-rs/ruffle.git`
this session (`75c3cec57` → `437be1498`, 28 commits, our 12 local patches
re-applied cleanly). `ConvolutionFilter.as`'s `this.matrixull` /
`preserveAlpharue` and the `filters.rs:888,893` gradient bug are **upstream's
own content**, not a corrupted local clone. The clone was never suspect; only
`clone()` is broken upstream, and no graded line touches it. The gradient bug
(alpha and ratio read from `colors_array`) is real and we implement the
correct per-array rule instead — still unexercised by any graded line.
