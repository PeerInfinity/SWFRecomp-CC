# Uncaught-error worklist — closing F3

**Status**: IN PROGRESS (this session, 2026-07-30). Continues
`filters-arc.md` §6 "F3 — NOT LANDED", whose 22-test per-cause table is the
worklist. That section stays as the historical record; this doc is the
close-out.

## 0. The framing that makes the accounting honest

All 22 worklist tests **PASS today**. They pass *with an uncaught error on
stderr*: script execution dies partway, and for the visual ones the rest of
the frame never renders, which the (ungraded) image comparison exposes.

So **fixing a bucket yields ZERO corpus delta by itself.** The yield is:

1. the F3 re-land once the list is empty (`uncaught_error_basic`,
   `loader_method`, and the tails of `loader_load` /
   `remove_child_clear_field`), and
2. **currently-FAILING tests that need the same APIs** — which is what the
   step-0 census was for, and where nearly all of this session's yield came
   from.

## 1. Step 0 — census expansion (done before predicting)

Every API name in the worklist was grepped across the FAILING corpus (all
suites, `.as` sources *and* `test.swf` via `strings` for the sourceless
ones). Findings, with the prompt's own suspicions marked:

| worklist API | failing-corpus riders found |
|---|---|
| `Video` | `flash_media_video_constructor` (156 lines), `_setter` (40), `_rotation_probe` (27) |
| `recompose`/`decompose`/3D geom | `vector3d` (397), `matrix3d` (57), `matrix3d_compose` (34), `utils3d` (7), `perspective_projection_basic` (40), `perspective_projection` (1443), `geom_transform` (74), from_shumway `Matrix3DClass` (56), `TransformBasics` (13), `PerspectiveProjectionClass` (20) |
| `registerFont` #1508 | `font_enumeratefonts_order` (9), `font_registerfont` (129) |
| `GraphicsPath` | `graphics_draw_path` (ruffle_matched, 51/101) |
| `BitmapDataChannel`, `CapsStyle`, `GraphicsBitmapFill`, `PNGEncoderOptions`, `lineBitmapStyle`, `drawRoundRectComplex` | only the `all_classes/display/swf*` mega-dumps (315 actual vs 1959-2936 expected — nowhere near a flip) |
| `BreakOpportunity` | none |

**The prompt's two named suspicions did not survive the sweep.** There are
no "two failing avm2 `gradient*` tests" — the only failing test with
`gradient` in its name is from_gnash `GradientFillTest`, an AVM1 test that
never touches `lineGradientStyle`. The flash.geom 3D tail, by contrast, was
real and much larger than "~8 tests": it is where most of this arc's yield
came from.

**Lesson: census the FAILING corpus before pricing a bucket, and let the
sweep overrule the scoping's guesses in both directions.** The graphics
bucket, priced as the second-biggest, turned out to be worth zero corpus
delta; the 3D-geom bucket, filed as a single away3d row, was worth ~5.

## 2. Buckets

### A — constant bags + sealed-class accessors (zero-risk, mechanical)

`BitmapDataChannel` (RED/GREEN/BLUE/ALPHA); `PNGEncoderOptions` /
`JPEGEncoderOptions`; `CapsStyle`; `JointStyle`; `GraphicsBitmapFill` /
`GraphicsEndFill` (both `IGraphicsData`); the twelve remaining pure-constant
`flash.text.engine` classes; `Rectangle.left/right/top/bottom/topLeft/
bottomRight/size/copyFrom`; `ColorTransform.color` + `concat`.

`copyChannel` was **already real** since Stage 9 — only the constant bag was
missing, so every caller that spelled the channel `BitmapDataChannel.RED`
died at the `getlex` before reaching working code. A one-word class closed
five worklist tests.

`Rectangle` and `ColorTransform` are SEALED, so a missing accessor is
`#1056 Cannot create property X` rather than a silently-created expando —
which is exactly the signature `stage3d_bitmap` and
`displayobject_colortransform_nested` were reporting. **Read the error code:
#1056 on a builtin means a missing accessor on a sealed class, not a
missing class.**

### B — `BitmapData.encode` (PNG)

`bitmapdata_colortransform` imports `PNGEncoderOptions` for a **commented-out**
`encode` call — and the compiled ABC still `getlex`es the class *and* still
calls `encode`. Adding the empty class only moved the error to
`#1069 Property encode not found`. Implemented for real: a valid RGBA8 (or
RGB8 for an opaque BitmapData) non-interlaced PNG via zlib's `compress2`,
written at the ByteArray's current position. zlib was already a dependency of
`avm2_bitmap.c`. JPEGEncoderOptions writes nothing (no DCT encoder, no
graded line reaches it).

### C — Graphics API gaps

Added `lineBitmapStyle`, `lineGradientStyle`, `lineShaderStyle`,
`beginShaderFill`, `cubicCurveTo`, `drawRoundRectComplex`, a real
`drawEllipse` (it shared `drawRect`'s body and drew a *box*), and the six
`GraphicsPath` path builders (`moveTo`/`lineTo`/`curveTo`/`cubicCurveTo`/
`wideMoveTo`/`wideLineTo`).

The command stream carries a solid-or-gradient fill and a SOLID stroke; a
bitmap fill and any non-solid stroke have no representation in it. The
convention `gfx_line_style` already documented — "a fill-typed stroke
degrades to no stroke" — is now applied uniformly: each of these flushes the
pending subpath and clears the style it governs. `beginBitmapFill` was a bare
`gfx_noop`, which both skipped the flush **and left the previous colour
current**, so it leaked a stale fill onto the next shape.

`cubicCurveTo` splits the cubic into 8 sub-curves and replaces each by its
least-squares quadratic (`control = (3*C1 - P0 + 3*C2 - P3)/4`); the SWF
shape record has no cubic.

### D — 3D geom (the biggest yield)

- **`Vector3D`** was a 4-slot dynamic-prop shell with NO methods. Ported
  whole from Ruffle's `Vector3D.as`, including the two quirks the corpus
  grades: `crossProduct` always sets `w = 1`, and `nearEquals(_, tol, true)`
  compares the OTHER vector's **raw** `w` against the tolerance instead of
  the difference (a Flash Player bug Ruffle documents and replicates).
  Almost every mutator deliberately leaves `w` alone.
- **`Matrix3D`**: `recompose`, `decompose`, `transformVectors`,
  `copyRowFrom/To`, `copyColumnFrom/To`, `copyToMatrix3D`; `pointAt` /
  `interpolate` / `interpolateTo` are stubs in Ruffle too.
  `recompose`'s zero-scale arm reproduces upstream's own typo (it tests
  `components[2].y` twice).
- **`Orientation3D`**, **`Utils3D`** (`projectVector`, `projectVectors`).
- **`PerspectiveProjection`** + a real `transform.perspectiveProjection`.
  The getter is non-null for the stage and the root and null elsewhere;
  assigning null is stored as "no override", so the stage's getter re-mints
  its default while a plain object goes back to null — which is exactly what
  `perspective_projection_basic` grades.
- **`TouchEvent`** — away3d's demo feature-checks for touch at class-init
  time, so the constant bag has to exist even though headless never
  generates one.

### E — `Video`

`flash.media.Video` as a DisplayObject whose **intrinsic bounds are its
declared size**, which makes `width`/`height`/`scaleX` fall straight out of
the existing DisplayObject machinery — that is why the 156-line constructor
probe went to a full pass in one step. `Video(w, h)`: negative either
dimension is `#2006`; a **zero in either** falls back to the 320x240 default
*pair* (so `new Video(100, 0)` is 320x240, not 100x240); otherwise Ruffle's
version-gated `is_size_valid` limits apply.

### F — the re-land's own two bugs

- **`loader_error_in_root_ctor` double print.** `print_uncaught` fired for
  *every* catch-all frame, including the ones the RUNTIME installs to handle
  an error itself. Ruffle only routes an error to `Avm2::uncaught_error`
  where the player loop **discards** it. Added `silent` to `Avm2TryFrame`
  plus `avm2_try_push_catch_all_silent`, and made
  `display_run_constructor_catching` silent exactly when the caller asked
  for `exc` (i.e. is going to render it itself). A caller that discards the
  error still reports normally.
- **`remove_child_clear_field`.** Ruffle's
  `remove_child_from_render_list` treats the two halves of the field-clearing
  differently: a throwing **getter** is swallowed outright ("they don't make
  it to flashlog or to uncaught error events"), while a throwing **setter**
  goes to `uncaught_error` and IS traced. We had one try frame around both.
  Split into two — silent for the read, reporting for the write.

## 3. Known residual blockers (NOT closed)

Two causes are genuinely bigger than this worklist and are recorded here
rather than bodged:

- **`stage3d_raytrace`, `stage3d_texture`** — `#1009` on a null
  `bitmapData`. Root cause found: the recompiler registers
  `DefineBits`/`JPEG2`/`JPEG3`/`JPEG4` as characters but emits **no**
  `BitmapAsset` for them (only `DefineBitsLossless{,2}` gets pixel data,
  `abc_timeline.cpp` ~1313). So every AVM2 movie with a JPEG-embedded asset
  sees `bitmapData == null`. Fixing it is an embedded-JPEG-assets feature
  (recompiler-side, plus a decode hop — `image_decode.c` already exists
  runtime-side), not a worklist item.
- **`visual/definefont4`** — needs the whole Text Layout Framework
  (`ElementFormat`, `TextBlock`, `TextElement`, `GroupElement`, `TextLine`).
  The SWF embeds all of TLF; the twelve constant bags added in bucket A get
  it past `BreakOpportunity` but not past `TextBlock.createTextLine`.
- **`font_enumeratefonts`** (+ `font_enumeratefonts_order`,
  `font_registerfont`) — `Font.registerFont` raises `#1508` because
  `font_by_id` has no entry. For `font_enumeratefonts` the symbol is a
  **DefineFont4** (CFF), which the recompiler does not parse at all; the
  `_order` test's fonts are 55-byte glyph-less `DefineFont3`s. Ruffle
  accepts both because they are `Character::Font` in its library. Same shape
  of fix as the JPEG one: the recompiler must record name-only font
  characters.

Because of those, F3 is landed **with the residual regressions named**
rather than at zero — see §4 for the measured trade.

## 4. Result — CI `30564063781` (graphics/full, baseline `b95ca09d7`)

**+8 gains, −5 regressions, net +3; histogram completely flat** (no
segfault / timeout / compile_fail / runtime_error move, `ruffle_matched`
241 → 241, `recomp_fail` 1 → 1). Corpus 4034 → 4037 of 4421; avm2
1019 → 1023, visual 137 → 136.

Attributing the two commits separately is what decided the endgame:

| | gains | regressions | net |
|---|---|---|---|
| platform-API work (`678e82e30`) | 6 | 0 | **+6** |
| uncaught-error trace (`1ca0ab117`) | 2 | 5 | **−3** |
| follow-up (`3dd78effc`, measured locally) | 2 | −1 recovered | **+3** |

Gains: `vector3d` (24 → 397/397), `utils3d` (0 → 7/7), `matrix3d`
(19 → 57/57), `matrix3d_compose` (0 → 34/34),
`perspective_projection_basic` (35 → 40/40),
`flash_media_video_constructor` (25 → 156/156) from the platform work;
`uncaught_error_basic` (0/2 → pass) and `loader_method` (83 → 85/85, it
needed the parameter-coercion frame pop) from the trace. Plus `rectangle`
(1 → 1094/1094) and `font_enumeratefonts` recovered in the follow-up.

Regressions, all five from the trace: `away3d_advanced_shallow_water_demo`,
`font_enumeratefonts` (recovered), `stage3d_raytrace`, `stage3d_texture`,
`visual/definefont4`.

### The trace is reverted again — but the worklist went 22 → 4

`ac2325c6f` reverts `1ca0ab117`. The landing condition was "the list is
empty, or every survivor is understood and harmless"; all four survivors are
understood and NONE is harmless, since each costs a corpus test. Keeping the
trace is worth −2 effective tests against reverting it.

**What stayed landed** is everything that made the re-land *correct*: the
`silent` catch-all frame (so `loader_error_in_root_ctor` can render its own
error without `print_uncaught` duplicating it) and the split getter/setter
frames in removeChild's field clearing. Only the stdout write and the
coercion frame pop came back out. Re-landing is this revert's inverse.

### Predicted vs actual, per bucket

| bucket | predicted | actual |
|---|---|---|
| BitmapDataChannel (5) | 0 corpus, unblocks 5 | exactly that — 5 worklist tests silent, no rider anywhere |
| Graphics APIs (5) | 0 corpus, unblocks 5 | exactly that; the "two failing gradient tests" did not exist |
| Video (2 + 3 riders) | +1 to +3 | **+1** (`_constructor`); `_setter` 1→33/40 and `_rotation_probe` 1→20/27 stall on integer-twips bounds |
| 3D geom (1 + ~10 riders) | +3 to +5 | **+4**, plus `perspective_projection` 4→1368/1443 and two from_shumway tests within 5 lines |
| Stage3D trio | 3 unblocked | **0** — the trio was never "Stage3D": two are embedded-JPEG, one was `Rectangle.left` |
| singletons | 4 unblocked | 3 unblocked, `definefont4` is TLF |
| re-land | ~+4 | **+2**, and −4 against it |

**Where the estimate went wrong, and why it is a repeatable lesson:** the
worklist's own labels named the *symptom class*, not the *owner*. "Stage3D
(3)" was one sealed-Rectangle accessor and two recompiler asset gaps;
"BreakOpportunity (1)" was the Text Layout Framework. Both times the cheap
name hid the expensive cause and vice versa. The census in §1 is the only
step that priced anything correctly — and it priced the two buckets the
scoping had ranked highest at exactly zero.

### The risk set is bigger than `status == pass`

`error_signature` is also recorded for `ruffle_matched` tests, and a
`ruffle_matched` test that gains a line can lose that status — so the
computable risk set is `status IN (pass, ruffle_matched) AND
error_signature != null`, **29** tests, not 22. All seven `ruffle_matched`
ones were re-run under the trace and every one KEPT its status, for a reason
worth recording: Ruffle traces the same line, so its reference output
already contains it. That is independent confirmation the change is
behaviourally right — and the reason it can only ever cost `pass` tests,
never `ruffle_matched` ones.
