# Filters arc — scoping

**Status**: scoped 2026-07-30 (pre-implementation). Census: **15 direct
targets** (13 filter tests + 2 uncaught-error-rider tests), predicted
**+12**. Oracle: Ruffle @ `75c3cec57` — **PROVENANCE CAVEAT**: the local
clone has corrupted text in `ConvolutionFilter.as:56-60` (`this.matrixull`,
`this.preserveAlpharue`) and a real bug in `filters.rs:888,893` (gradient
`alpha`/`ratio` read from `colors_array`; not exercised by any graded
line). Verify against github before copying either; everywhere else,
`output.txt` is Flash's recording and none of the targets is
`known_failure`.

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

(append per tranche)
