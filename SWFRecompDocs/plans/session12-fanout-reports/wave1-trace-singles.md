# Session 12 · wave-1 · `w1-trace-singles`

Read-only evidence pass on the three diagnosed-but-unfixed trace leads carried
on `SWFRecompDocs/plans/polish-sweep-arc.md` §12.3. All three re-verified at
`f166e424e` with local single-test runs (`--mode` default = no-graphics).

**Headline: all three are GO, and two of the three §12.3 premises are refuted.**

| # | Lead | §12.3 premise | Verdict at HEAD | Predicted | Effort | Confidence |
|---|---|---|---|---|---|---|
| 1 | `avm2/edittext_device_transform_layout` | "wide blast radius" | **Refuted** — blast radius is 3 tests, all enumerable, and the 2 highest-risk ones provably do not move | +1 (→ `ruffle_matched`) | **XS** (4 lines) | **HIGH** |
| 2 | number→string tie-break | "corpus-wide risk" | **Refuted** — a scan of all 5 095 expected-output files finds **0** tokens anywhere in the corpus that could regress | +1 (→ `pass`) | S (~20 lines) | **HIGH** |
| 3 | B6 morph hit-test | "recompiler-side, stroke tessellation missing from `shape_data`" | **Refuted** — the recompiler already emits everything needed (`path_data` + `ng_record_morph_path`); this is a pure AVM2-runtime routing gap | +1 (→ `pass`) | M (~40 lines) | **HIGH** (simulated the exact fix off the generated tables; it reproduces the expected output byte-for-byte) |

Dispositions checked first for every target:
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`, `ruffle-tests/ignored_tests.txt` and every
suite-local `ignored_tests.txt`. **No target carries a disposition.** The one
ignore-list hit is `avm2/edittext_device_transform_layout`, present in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:65` — that suppresses it from
the *filtered* report only; the headline corpus figure is the **unfiltered**
`effective_pass`, so the flip still banks +1 (see that file's header comment,
lines 6–16).

---

# Lead 1 — `avm2/edittext_device_transform_layout`

## Verified at HEAD

`output_mismatch`, 288 graded lines. Two separate distances matter:

* vs `output.txt` (Flash oracle): **40 diff lines**. Unreachable in this batch —
  see "Why `pass` is not the target" below.
* vs `output.ruffle.txt`: **exactly 64 diff lines = 32 line changes**, all
  confined to output lines 182–288 (`Auto size, autoSize=center` and
  `autoSize=right` groups). `test.toml` is `known_failure = true`, so matching
  `output.ruffle.txt` promotes the test to `ruffle_matched`, which
  `verify_output.py:3419/4245` counts in `effective_pass`.

Run: `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=edittext_device_transform_layout --diff --verbose`
(78 s compile). Confirms the s11 `w2-b9-fonts-report.md` residual figure (32
lines) unchanged at HEAD.

## Mechanism — pinned, and the arithmetic checks on all 32 lines

Ruffle `core/src/display_object/edit_text.rs:774-790`:

```rust
fn layout_to_local_matrix(self) -> Matrix {
    let bounds = self.0.bounds.get();
    let matrix = Matrix::translate(
        bounds.x_min + Self::GUTTER - Twips::from_pixels(self.0.hscroll.get()),
        bounds.y_min + Self::GUTTER - self.0.vertical_scroll_offset(),
    );
    if self.font_type() == FontType::Device { matrix * Matrix::scale(self.device_font_scale_x(), 1.0f32) } else { matrix }
}
```

Ours, `SWFModernRuntime/src/avm2/avm2_text.c:8136-8145`
(`txt_get_char_boundaries`), applies the device x-scale in the same order but
translates by `GUTTER` alone:

```c
{ float sx = et_device_font_scale_x(ctx, et);
  x_min = layout_x_to_local_x(x_min, sx);
  x_max = layout_x_to_local_x(x_max, sx); }
x_min += GUTTER;
x_max += GUTTER;
y_min += GUTTER - vscroll_off;
y_max += GUTTER - vscroll_off;
```

`et->bounds_x` is the missing term. We already replicate Ruffle's autosize
bounds shift faithfully — `avm2_text.c:3679-3706` (`et_relayout`) computes
`new_x = (bounds_x + (bounds_x + bounds_w) - width) / 2` for center and
`bounds_x + bounds_w - width` for right, matching `edit_text.rs:927-935`
verbatim — so `bounds_x` is already correct at the moment `getCharBoundaries`
runs; it is simply not read.

**Every one of the 32 lines is explained by exactly `+ bounds.x_min`.** Spot
checks against the `x:` line the test prints immediately above each group
(`text.x` = `base().x() + bounds_x_offset()`, and `bounds_x_offset` scales by
`scale_x` — `edit_text.rs:422-426`, so divide the printed `x` by `scaleX` to
recover the local-space `bounds.x_min`):

| output line | group | printed `x` | scaleX | ⇒ `bounds.x_min` (px) | expected − ours |
|---|---|---|---|---|---|
| 182 | autoSize=center, device=false, 1×1 | 20 | 1 | 20 | 22 − 2 = **20** |
| 217 | autoSize=center, device=true, 2×1 | 48 | 2 | 24 | 26 − 2 = **24** |
| 224 | autoSize=center, device=true, 1×2 | 12 | 1 | 12 | 14 − 2 = **12** |
| 238 | autoSize=right, device=false, 1×1 | 40 | 1 | 40 | 42 − 2 = **40** |
| 273 | autoSize=right, device=true, 2×1 | 96 | 2 | 48 | 50 − 2 = **48** |
| 280 | autoSize=right, device=true, 1×2 | 24 | 1 | 24 | 26 − 2 = **24** |
| 287 | autoSize=right, device=true, 2×2 | 80 | 2 | 40 | 42 − 2 = **40** |

All `y` values are already correct (`bounds.y_min == 0` throughout this test);
adding `bounds_y` is faithful to Ruffle and provably inert here.

## Proposed wave-2 scope — 4 lines, one function

`SWFModernRuntime/src/avm2/avm2_text.c:8142-8145`:

```c
x_min += et->bounds_x + GUTTER;
x_max += et->bounds_x + GUTTER;
y_min += et->bounds_y + GUTTER - vscroll_off;
y_max += et->bounds_y + GUTTER - vscroll_off;
```

**Three implementation invariants wave 2 must not violate:**

1. **Read `et->bounds_x` RAW. Do NOT route through `avm2_text_self_bounds()`
   (`avm2_text.c:7644`) or otherwise call `et_apply_lazy_bounds()`.** Ruffle's
   `char_bounds` (`edit_text.rs:2413-2433`) reads `self.0.bounds.get()` and
   never calls `apply_autosize_bounds()`. This is load-bearing: in
   `avm2/edittext_autosize_lazy_bounds_vs_relayout` (currently **pass**) the
   field has a *pending* `autoSize="right"` bound of `x_min = −1280` twips that
   is never applied; reading raw keeps every `getCharBoundaries` row at
   `(x=2,…)` (matching `output.txt:95-98`), while applying it would emit
   `x=−62` and **break a passing test**.
2. **Do not touch hscroll.** Ruffle subtracts hscroll in the matrix and then
   adds it straight back for char bounds specifically
   (`edit_text.rs:2428-2431`, "FP does not apply hscroll to char boundaries") —
   which is exactly what our `:8129-8130` comment already encodes. Net zero;
   leave it.
3. **Do not add an `apply` to `has_pick`-style call sites**, and do not touch
   `display_self_bounds`. Scope is one function.

Optional, same mechanism, **not required for the flip**: `getLineMetrics`
(`avm2_text.c:8076`, `args[0] = (lx + GUTTER)/20.0`) has the identical omission
versus Ruffle `edit_text.rs:2274`. The target test never calls it. Recommend
**shipping it in the same patch only if wave 2 is willing to run the extra
canary** below; otherwise defer — it buys no measured line.

## Predicted flips

* `avm2/edittext_device_transform_layout`: `output_mismatch` → **`ruffle_matched`**, +1 unfiltered `effective_pass`.
* Nothing else moves.

### Why `pass` is not the target
The remaining 40 lines against `output.txt` are the `Text align, device=true,
scaleX≠1` groups (output lines 89-93, 113-120) plus a `41.95` vs `42`
right-margin rounding difference. **We already match `output.ruffle.txt`
byte-for-byte on all of those** — i.e. those are Ruffle's own divergences from
Flash, not ours. Chasing `pass` is a separate, larger item (device-font
independent-axis scaling in the align path). Do not scope it here.

## Blast radius — fully enumerated

Corpus grep for `getCharBoundaries|getLineMetrics|getCharIndexAtPoint` across
all `*.as` **and** all `*.swf` binaries returns **20 tests**. `bounds.x_min` is
non-zero only when (a) `autoSize` is `center`/`right`, or (b) the field comes
from a `DefineEditText` tag with a non-zero bounds origin. 17 of the 20 create
their field with `new TextField()` (origin 0,0) and never touch `autoSize` —
for those the patch is arithmetically a no-op. That leaves three:

| Test | Baseline (confirmed at HEAD unless noted) | Exposure | Expected movement |
|---|---|---|---|
| `avm2/edittext_autosize_lazy_bounds_props` | **PASS** (re-run at HEAD) | `autoSize="center"` (`Test.as:1028`), `"right"` (`:81`); calls all three APIs | **None** — the return values are discarded (`:786-864` call the methods purely to observe whether the *call* applies lazy bounds). Only the `x/y/w/h` dumps are graded, and the patch changes no bounds state. |
| `avm2/edittext_autosize_lazy_bounds_vs_relayout` | **PASS** (re-run at HEAD) | `autoSize="right"`→`"left"`; **prints** `getCharBoundaries(0)`/`(5)` and `getCharIndexAtPoint` | **None**, *provided invariant 1 above is honoured.* Traced by hand through `Test.as:92-113` against `output.txt:92-104`: raw `bounds.x_min` is 0 at every graded point. This is the single highest-risk row — run it first. |
| `from_shumway/flash_text_TextField` | `ruffle_matched` (results JSON) | sets `autoSize` CENTER/RIGHT/NONE (`test.as:47-55`) then `getLineMetrics(0)` (`:136`) | **None if the `getLineMetrics` half is deferred.** If wave 2 does ship the `:8076` line, this is its canary. |

### Canary list for wave 2 (mode=graphics, categories=full)
Required: `avm2/edittext_autosize_lazy_bounds_vs_relayout`,
`avm2/edittext_autosize_lazy_bounds_props`,
`avm2/edittext_device_transform_layout` (the target).
Cheap confirmations that should be inert:
`avm2/edittext_getcharboundaries`, `…_scroll`, `…_missing_glyphs`,
`avm2/edittext_get_char_index_at_point`, `avm2/edittext_at_point_methods_basic`,
`avm2/edittext_line_metrics`, `avm2/edittext_wrap_breaks`,
`avm2/edittext_empty_text_format`,
`fonts/device_font_{kerning,glyph_fallback,list}`,
`visual/edittext/edittext_device_transform_{basic,metrics,negative}`.
Only if `getLineMetrics` is included: add `from_shumway/flash_text_TextField`.

`edittext_device_transform_layout` carries **no** `[[image_comparisons]]` —
pixel-board neutral.

## GO / NO-GO — **GO.** XS effort, HIGH confidence, enumerated 3-test radius.

---

# Lead 2 — number→string tie-break (`avm2/perspective_projection`)

## Verified at HEAD

`output_mismatch`, **exactly 14 diff lines**, all of the form:

```
-  48  FOV to FL 29 966.6782836914063     (expected)
+  48  FOV to FL 29 966.6782836914062     (ours)
```

Affected FOVs: **29 32 35 37 52 95 98 99 107 109 123 143 147 167** — identical
to the list in `session11-fanout-reports/wave1-trace-singles.md:293`. Nothing
else remains; the test flips to **`pass`** when these 14 are fixed. Not in any
ignore list, no disposition.

## Mechanism — pinned

`SWFModernRuntime/src/avm2/avm2_value.c:498-533`, `shortest_digits()`:

```c
for (int prec = 0; prec <= 17; prec++)
{
    snprintf(tmp, sizeof(tmp), "%.*e", prec, d);
    if (strtod(tmp, NULL) == d) { … }
}
```

glibc's `printf` is correctly rounded and resolves exact decimal ties
**to-even**. `966.67828369140625` is an exact f64 (an f32-derived focal length)
whose 16-significant-digit rounding is an exact midpoint; both
`966.6782836914062` and `966.6782836914063` round-trip, and glibc picks the
even one.

Ruffle prints through Rust's `f64: Display`, whose shortest-repr resolves the
same tie **away from zero**. Verified directly (`rustc -O`, this machine):

```
966.67828369140625  →  Rust: 966.6782836914063
                        glibc/Python/us: 966.6782836914062
```

So this is not "Flash rounds differently" — it is a Rust-vs-glibc shortest-repr
tie rule, and the expected file is Ruffle's own output.

`avm2_format_number` (`avm2_value.c:572`) is the single entry point; it is
AVM2-only (26 call sites, all under `src/avm2/`). AVM1's formatter in
`actionmodern/action.c` is untouched by any change here.

## Corpus-wide risk — measured, not estimated

I emulated both tie rules exactly (glibc `%.*e` for to-even; `decimal` with
`ROUND_HALF_UP` on the exact value for away-from-zero, cross-checked against
`rustc` on the two known PP values and on a 24 k-value random/f32 sample) and
replayed the full `avm2_format_number` pipeline over **every numeric token in
every expected-output file in the corpus** — 5 095 files
(`output.txt`, `output.ruffle.txt`, and every `output.*.txt` variant), tokens
of length ≥ 4:

```
== WOULD FIX  (expected uses tie-away, we print tie-even) ==
     15  avm2/perspective_projection
  total: 15 tokens in 1 test
== WOULD REGRESS (expected uses tie-even, we'd print tie-away) ==
  total: 0 tokens in 0 tests
  neither-matches tokens: 0
```

The argument is tight, not merely statistical: for any **currently-passing**
test our emitted output is byte-identical to its expected file, so every number
we print appears verbatim as a token in that file. Zero corpus tokens change
formatting under the new rule ⇒ **no passing test's output can change.** The
§12.3 "corpus-wide risk" premise is refuted.

(Script kept at
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/…/scratchpad/tie.py` for the
session; it is ~90 lines and trivially regenerable.)

## Proposed wave-2 scope

Localised to `shortest_digits()` in `avm2_value.c`. After the loop settles on
`prec`, detect an exact midpoint and round away from zero:

1. Guard on `prec >= 13` (a tie needs the double's exact decimal expansion to
   terminate at `prec+2` significant digits; all 14 observed cases sit at 16).
   This keeps the hot path free — see the perf note at `avm2_value.c:583-588`,
   number formatting is ~10 % of Seedling frame self-time, and the
   integer fast path at `:589-599` already short-circuits the common case.
2. Print the **exact** expansion once (`snprintf("%.60e", d)` — glibc emits a
   double's exact decimal digits and zero-pads), and declare a tie iff digit
   `prec+1` is `'5'` and all digits after it are `'0'`.
3. On a tie, increment the `prec`-digit mantissa with carry (and bump `exp10`
   on a 999…→100… overflow).

~20 lines, one static function, no header change, no other call site.

## Predicted flips

`avm2/perspective_projection`: `output_mismatch` → **`pass`**, +1.
Nothing else, corpus-wide (measured above).

## Canary list

`avm2/perspective_projection` (the target), `avm2/perspective_projection_basic`
(pass), `avm2/geom_transform`, `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`
(prints focal lengths via `toFixed(10)` — a different path, should be inert),
plus any two float-heavy AVM2 tests as smoke
(`avm2/matrix3d_*`, `avm2/number_toprecision`). CI `mode=graphics`,
`categories=full` (AVM2 runtime).

## GO / NO-GO — **GO, not deferral.** The premise that blocked it in s11 is
measurably false: 0 regression candidates in 5 095 expected-output files.
The only real cost is a perf-sensitive hot path, which the `prec >= 13` guard
sidesteps.

---

# Lead 3 — B6 morph hit-test (`from_shumway/acid/acid-morph`)

## Verified at HEAD

`output_mismatch`, gap 2 — lines 3 and 4 transposed, unchanged from s11:

```
expected: true false false true false false
ours:     true false true  false false false
```

Grouped in pairs (`hitTestPoint(100,100,true)`, `hitTestPoint(300,300,true)` per
invocation): expected `(T,F) (F,T) (F,F)`; ours `(T,F) (T,F) (F,F)`. Only the
**second** invocation — the mid-tween one — is wrong. No disposition, not
ignored. Carries `[[image_comparisons]]` (two tolerance checks), but hit-testing
does not touch rendering, so a correct fix is pixel-neutral.

## The §12.3 premise is REFUTED — the recompiler is already complete

§12.3 records B6 as "recompiler-side (stroke tessellation missing from
`shape_data`)", from `session11-fanout-reports/w2-triage-batch-report.md:155-188`.
That conclusion came from lerping the **27 tessellated fill vertices** in
`shape_data`/`morph_end_shape_data`, which are indeed an incomplete, fill-only
subset. But the recompiler *also* emits a complete interleaved **morph path**
table, and it is already registered for this exact character:

`ruffle-tests/tests/swfs/from_shumway/acid/acid-morph/RecompiledTags/tagMain.c:13`
```c
ng_record_morph_path(1, 0, 30);          //  char_id 1, path_data[0..29]
…
tagSetInstanceName(app_context, 1, "morph");
```

`RecompiledTags/draws.c:1605+` `float path_data[96][3]` holds that block:
`{1.0,…}` style-change, `{1.5, line_style, start_width}` + `{9.0, ·, end_width}`
stroke style, then `{5.0/2.0/3.0/4.0, start_x, start_y}` each followed by its
`{9.0, end_x, end_y}` morph-end partner. **Strokes and end vertices are both
present.**

A stroke-and-ratio-aware walker over exactly that table already exists and is
already compiled into both build modes:
`SWFModernRuntime/src/libswf/shape_hit_test.c:446` `ng_hitTestMorphPath()`
(interpolates every vertex and the line width by `ratio/65535`, does
fill winding + stroke distance), reached via
`shape_hit_test.c:632 ng_hitTestShapeChar()` → `:740-751`. `shape_hit_test.c`
and `ng_shared.c` are in **both** source lists in `verify_output.py`
(`:2110-2111` no-graphics, `:2709-2715` graphics-native).

### Decisive check
I replayed `ng_hitTestMorphPath`'s algorithm over the generated
`path_data[0..29]` at the two ratios and the two local probe points that the s11
agent instrumented (`local (−3420,−1980)` for the `(100,100)` probe,
`local (580,2020)` for `(300,300)`; ratios `0` and `54237`):

```
ratio=     0  probe(100,100) -> fill hit = True     probe(300,300) -> False
ratio= 54237  probe(100,100) -> fill hit = False    probe(300,300) -> True
interpolated outline bbox: r=0      (-4900,-3440)…(-2180, -880)
                           r=0.827  (  180.7, 830.4)…(3405.1, 2200.9)
                           r=1      ( 1239,  1720)…( 5119,  3376)
```

That is **exactly** the expected `true false / false true` — including line 4,
the line s11 could not move. The s11 extrapolation ("no ratio in [0,1] puts
that point inside") was an artefact of lerping the 27-vertex fill tessellation
instead of the path table; the true interpolated bbox at r = 0.827 contains
(580, 2020) comfortably.

**B6 is therefore a runtime routing gap, not a recompiler geometry gap, and it
is patch-sized.**

## Mechanism — the two AVM2-side lags, with sites

The AVM1/libswf path already does the right thing
(`libswf/tag.c:3668-3678` calls `ng_hitTestShapeChar(char_id, obj->ratio, …)`).
The AVM2 display path does not:

1. `SWFModernRuntime/src/avm2/avm2_display.c:11764` `has_pick_geometry()` —
   `if (ext->shape_vert_count > 0 && !ext->is_morph_shape) return 1;` — a morph
   reports "no exact geometry", so `point_in_self` returns `1` for anything
   inside the AABB.
2. `avm2_display.c:11821` `point_in_self()` AABB-rejects against
   `self_bounds_full()` → `display_self_bounds()` → `char_self_bounds(ext->char_id)`
   (`:666`), which returns the character's recorded **START** bounds. At
   r = 0.827 the `(300,300)` probe is outside those, so it is rejected before
   any shape test can run.

Ruffle draws the same two lines but resolves both per-ratio —
`core/src/display_object/morph_shape.rs:144-168`: `world_bounds(BoundsMode::Engine).contains(point)`
(the *ratio's* frame bounds) followed by `shape_hit_test` on
`frames[&self.ratio()].shape`.

## Proposed wave-2 scope (~40 lines, 2 files)

1. `SWFModernRuntime/src/libswf/shape_hit_test.c` — export a thin wrapper so
   the AVM2 side does not depend on `dictionary[]`/`Character` typing:
   ```c
   int ng_hitTestMorphLocal(size_t char_id, u16 ratio, double lx, double ly)
   { size_t off, sz;
     if (!ng_find_morph_path(char_id, &off, &sz)) return -1;   // -1 = no data
     return ng_hitTestMorphPath(char_id, off, sz, lx, ly, ratio); }
   ```
   (~8 lines; `ng_find_morph_path` is already non-static in
   `libswf/ng_shared.c:232`.)
2. `SWFModernRuntime/src/avm2/avm2_display.c`
   * `has_pick_geometry()` `:11766` — also return 1 when
     `ext->is_morph_shape` and `ng_find_morph_path(ext->char_id, …)` succeeds.
   * `shape_contains_local()` `:11777` — add a leading morph branch calling
     `ng_hitTestMorphLocal(ext->char_id, ext->ratio, lx, ly)`; treat `-1`
     (no path data) as "fall through to the existing behaviour".
   * `point_in_self()` `:11825-11832` — for that same morph case, take the AABB
     from `ng_getCharBoundsForRatio(char_id, ratio, …)`
     (`libswf/ng_shared.c:124-150`, which lerps the tag's Start/End bounds) instead
     of `self_bounds_full()`. This is Ruffle's `BoundsMode::Engine`.

   `ext->ratio` (`avm2_display.c:1737`) and `ext->char_id` (`:1775`) are both
   already maintained.

**Hard constraint — do NOT change `display_self_bounds()`/`char_self_bounds()`
for morphs.** s11 tried a `morph_lerped_bounds()` there and it is corpus-visible:
`avm2/hittest_morph` (**pass**) prints `hitbox.getBounds(this)` and
`getRect(this)` for a morph across five ratios and expects a *constant*
`(x=-0.3, y=0.1, w=65, h=65)` for frames 1-4. Interpolating `getBounds` breaks
that test. Ruffle keeps the two bounds modes separate for exactly this reason;
so must we. Confine the ratio-aware bounds to the hit-test AABB.

## Predicted flips

`from_shumway/acid/acid-morph`: `output_mismatch` → **`pass`**, +1 trace,
pixel-neutral (image comparisons are not gating and rendering is untouched).

## Blast radius + canary list

Morph hit-testing changes from "AABB of the start shape" to "exact interpolated
outline" for **AVM2 only** (the AVM1 path already behaves this way). Every
corpus test touching a morph:

| Test | Baseline | Exposure |
|---|---|---|
| `avm2/hittest_morph` | **PASS** (re-run at HEAD) | **Primary canary.** Only `hitTestObject` (bounds) + `getBounds`/`getRect` on the morph; the shape probe is on a non-morph `bullet`. Should be inert — and it is the test that forbids touching `getBounds`. |
| `avm2/morph_shape` | **PASS** (re-run at HEAD) | class-identity only |
| `regression/avm2_morph` | **PASS** (re-run at HEAD) | project-owned; read its README before grading |
| `from_gnash/misc-ming.all/morph_test1` | pass | rendering/timeline; also on the pixel board (`w2-quality-msaa-report.md:191`) |
| `visual/cache_as_bitmap/morph` | image-axis | rendering only |
| `avm1/hittest_morph`, `avm1/hittest_morph_input` | pass | **AVM1 path — untouched by this patch.** Include as no-op proof. |
| `from_shumway/acid/acid-morph` | target | — |

CI: `mode=graphics`, `categories=all` is sufficient (no ABC emission change);
`images=false`.

## GO / NO-GO — **GO, and re-file it off the recompiler board.**
§12.3's "recompiler-side (stroke tessellation missing from `shape_data`)" should
be struck: the generated `path_data` + `ng_record_morph_path` tables are
complete, and the fix is ~40 lines of AVM2 runtime routing to an existing
libswf walker. Not arc-sized.

---

# Cross-cutting notes for the arc doc

* Two of the three §12.3 one-line risk labels ("wide blast radius",
  "corpus-wide risk") and one of the three ownership labels ("recompiler-side")
  were wrong. Consistent with the standing
  `worklist-labels-name-symptoms-not-owners` memory: a §12.x parenthetical is a
  *symptom summary written by whoever bounced off it*, not a scoping verdict.
* The B6 refutation came from replaying the shipped algorithm against the
  **generated tables checked into the test directory**
  (`RecompiledTags/draws.c`, `RecompiledTags/tagMain.c`). That is a cheap,
  build-free way to falsify "the data isn't there" claims — worth reaching for
  before staffing any "recompiler-side" item.
* Lead 2's risk was settled by scanning expected-output *tokens* rather than by
  running tests: for a passing test, output == expected, so "no expected token
  changes" is a proof of no regression. Reusable for any formatting change.

## Verification commands used (all single-test, no suite runs)

```
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=edittext_device_transform_layout --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=edittext_device_transform_layout --save-actual=<path>
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=perspective_projection --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway/acid --test=acid-morph --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=edittext_autosize_lazy_bounds_props --test=edittext_autosize_lazy_bounds_vs_relayout --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 --test=hittest_morph --test=morph_shape --verbose
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/regression --test=avm2_morph --verbose
```
