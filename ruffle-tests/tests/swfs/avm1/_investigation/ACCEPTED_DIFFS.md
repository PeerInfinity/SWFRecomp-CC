# Accepted Permanent Diffs

Tests where some output lines will never match, and we have decided not to fix them.
Each entry explains *why* the diff is permanent and documents the decision.

This is distinct from `RUFFLE_VS_FLASH_DIFFERENCES.md`, which covers cases where our
implementation matches Flash's spec but disagrees with Ruffle's design choices. The cases
here are impossible to fix for more fundamental reasons.

---

## Category 1: Platform/UB-Dependent Expected Output

The expected output was generated on a specific machine and depends on C undefined behavior
(integer overflow, out-of-range float-to-int conversion, floating-point rounding) that
produces different results on different compilers, platforms, or optimization levels. We
cannot portably replicate the specific UB values without introducing our own UB.

### `date` — NaN/Infinity year in multi-arg constructor (~9 diff pairs)

**Example diff:**
```
- FullYear = -2147481748, ...
+ FullYear = ..., ...
```

When `new Date(NaN, 0)` or `new Date(Infinity, 0)` is called, the year argument is cast
via `(int32_t)year`. For NaN/Infinity this is C undefined behavior — the x86 `cvttsd2si`
instruction produces INT_MIN (−2147483648), but this is not guaranteed. The expected output
reflects the values produced by the specific Ruffle test machine. Our CI (Ubuntu x86_64)
may produce the same INT_MIN, or the compiler may generate different code. No portable fix
is possible without hardcoding UB-specific magic values.

### `date` — TimezoneOffset precision for extreme dates (~1 diff pair)

**Example diff:**
```
- TimezoneOffset = -345
+ TimezoneOffset = -345.002666667
```

For dates near the maximum representable timestamp (~8.64e15 ms), the UTC offset
calculation accumulates floating-point rounding error, producing a fractional offset
instead of the exact integer −345. This is a precision artefact with no clean fix short
of special-casing the offset calculation for extreme values.

### `native_subclasses` — Date toString timezone (1 diff line)

**Example diff:**
```
- super(123456): Thu Jan 1 05:47:03 GMT+0545 1970
+ super(123456): Wed Dec 31 16:02:03 GMT-0800 1969
```

The expected output was generated on a machine in the `GMT+0545` timezone (Nepal). Our CI
and dev machines produce a different timezone offset (e.g. `GMT-0800` for US Pacific).
Date.toString() is inherently timezone-dependent and no portable fix is possible.

---

## Category 2: Internally Inconsistent Expected Output

The expected output is mathematically self-contradictory — no correct implementation
could produce all of the expected values simultaneously. This is a bug in how the Ruffle
test expected output was generated.

### `date` — UTCHours at boundary −8.64e15 (~18 diff pairs)

**Example diff:**
```
- UTCHours = 0, UTCDate = 1
+ UTCHours = 23, UTCDate = 1
```

For timestamps near −8.64e15 ms (the minimum representable Flash date), the expected
output sometimes shows UTCHours=0 in a context where the local date fields (e.g.,
LocalDate=20 at UTC+5:45) require UTCHours=23 or 0+previous-day. The expected values
are internally inconsistent: given the UTC offset and the local fields, the UTCHours
value shown is wrong. Our UTCHours=23 is mathematically correct. This appears to be a
Ruffle test-generation bug affecting only the extreme negative boundary.

### `native_objects_swf6` — `new TextField()` typeof check (1 diff line, line 56)

> Note (2026-05-29): a *separate*, graphics-mode-only segfault flake in this test
> was root-caused and fixed (ASArray-as-ASObject type confusion in `super()` over an
> array receiver + `Date.prototype.getDate.call([])`). See SESSION_NOTES.md. The
> remaining single-line diff below is unchanged and still accepted.

**Diff:**
```
- new TextField(): non-object: non-object: undefined
+ new TextField(): native
```

The test `getNativeStatus(new TextField())` is expected to return `"non-object: undefined"`,
implying that `new TextField()` returns `undefined` in SWF6. But two other tests assert the
opposite:

- `avm1/textfield_props_swf6` (PASS, no `known_failure`) — expects `var o = new TextField();`
  to produce a real object that traces as `[object Object]` with `typeof o == "object"` and
  enumerates 35 properties.
- `from_gnash/actionscript.all/toString_valueOf-v6` — does `text1 = new TextField(); check(typeof(text1) == "object");`.

Both Flash and Ruffle return a real object for `new TextField()` in SWF6 (per the other
tests' expected output). The `native_objects_swf6` line 56 expectation is internally
inconsistent with the rest of the AVM1 test corpus. Forcing `new TextField()` to undefined
in SWF6 fixes line 56 but breaks `textfield_props_swf6` (210/210 → 77/210) and
`toString_valueOf-v6` (ruffle_matched 150/155 → output_mismatch 141/155). The test is
already marked `known_failure = true` and listed in `ruffle-tests/ignored_tests.txt`, so the
1-line diff is harmless to the filtered pass rate. **Decision:** keep current behavior
(`new TextField()` returns an object in all SWF versions where the class exists), accept the
1-line diff in `native_objects_swf6`.

---

## Category 3: Flash Implementation Quirks We Do Not Replicate

Undocumented or locale-specific behaviors of Flash Player's built-in functions that
produce outputs we cannot portably reproduce without hardcoding platform-specific magic.

### `array_sort` — Non-ASCII `CASEINSENSITIVE` ordering (1 diff pair, line 50)

**Diff:**
```
- hëllo,HËLLO,TeSt,test
+ HËLLO,hëllo,TeSt,test
```

`["hëllo", "HËLLO", "TeSt", "test"].sort(Array.CASEINSENSITIVE)`.

Flash's `CASEINSENSITIVE` comparison uses a locale-aware or Unicode-aware case fold where
`ë` (U+00EB) and `Ë` (U+00CB) are treated as equal (as they are in proper Unicode case
folding). With the two strings equal, a stable insertion sort preserves their input order
(`hëllo` before `HËLLO`).

Our implementation uses ASCII-only case folding (only `A–Z → a–z`), leaving `ë` and `Ë`
unmodified. This makes `Ë` (203) < `ë` (235), so `hËllo` < `hëllo`, and `HËLLO` sorts
before `hëllo`.

Switching to Unicode-aware case folding (e.g., via `towlower`) would fix this diff but
could introduce regressions for other tests that expect ASCII-only behavior. Additionally,
the second test case (`["TeSt", "hëllo", "HËLLO", "test"]` → `HËLLO,hëllo,TeSt,test`)
produces `HËLLO` before `hëllo` despite `hëllo` appearing earlier in the input — which
contradicts stable sort — suggesting Flash's behavior for non-ASCII chars is in fact
locale-specific and not consistently reproducible.

**Decision:** Accept 1 diff pair. Non-ASCII case-insensitive ordering is platform/locale-
dependent in Flash and not reliably reproducible.

### `array_sort` — `sortOn` multi-key `DESCENDING` flag quirk (2 diff pairs, lines 129, 132)

**Diff:**
```
- {n: BAR, b: 22},{n: bar, b: 3},{n: foo, b: 1},{n: foo, b: 2}
+ {n: foo, b: 1},{n: foo, b: 2},{n: bar, b: 3},{n: BAR, b: 22}
```

`sortOn(["n", "b"], [Array.DESCENDING])` — one flag in the array for two sort keys.
Same diff appears for `sortOn(["n", "b"], [Array.DESCENDING, Array.0, 0])` (line 132).

The expected output shows ascending order by `"n"` (BAR < bar < foo), even though
`Array.DESCENDING` is specified. This contradicts the documented semantics (apply the
last flag to all remaining keys), which would give descending order by `"n"` — exactly
what we produce.

The behavior suggests Flash Player's internal flag-to-key mapping for `sortOn` has an
undocumented off-by-one or other quirk when the flags array is shorter than the keys
array, causing the `DESCENDING` flag to be silently dropped or applied to a non-existent
position. Replicating this would require reverse-engineering undocumented Flash internals.

**Decision:** Accept 2 diff pairs. Flash's multi-key `sortOn` DESCENDING flag handling
is undocumented and cannot be replicated without guessing at implementation internals.

---

## Category 4: Flash UB Behavior We Intentionally Do Not Replicate

Flash Player produced specific outputs that depend on undefined or implementation-defined
behavior in its own runtime. Replicating these values would require us to introduce the
same UB, which conflicts with producing a correct and portable implementation. We accept
the diff and prefer the spec-correct behavior.

### `date` — Infinity getter values (~14 diff pairs)

**Example diff:**
```
- FullYear = -2147481678, Month = 11, Date = -2130706433, ...
+ FullYear = NaN, Month = NaN, Date = NaN, ...
```

When `new Date(Infinity)` is constructed, the internal Time value is Infinity. Flash
Player passes this Infinity through integer conversion in its getter implementations
(equivalent to `(int32_t)Infinity`), which is C UB and produces specific garbage
values (-2147481678, -2130706433, etc.) via x86 `cvttsd2si` saturation or wraparound.

Our implementation correctly returns NaN for all getters when Time is non-finite, which
matches ECMAScript 3 §15.9.5. Matching Flash's UB values would require hardcoding
magic constants or deliberately invoking UB.

**Decision:** Return NaN for non-finite Time. Accept ~14 diff pairs in the `date` test.

### `movieclip_getbounds` — Morph shape getBounds matrix precision (2 diff pairs, lines 63, 159)

**Diff:**
```
- -99.9
+ -99.9511255968007
```

`clip.getBounds('clip:clip')` with a morph shape at a specific ratio produces a yMin
value that differs by 0.0511 pixels. The test has `epsilon = 0.051`, so our result
exceeds the tolerance by only 0.0001 pixels. The difference arises from accumulated
floating-point rounding during the matrix inversion and composition required for
cross-coordinate-space bounds transformation. All other values on the same line match
perfectly.

**Decision:** Accept 2 diff pairs. Floating-point precision in matrix calculations;
our error is 0.0001 pixels beyond the test's epsilon tolerance.

---

## Category 5: Test Harness Limitations

Expected output depends on Ruffle's test runner infrastructure (viewport geometry,
default mouse position, etc.) that our native test harness does not replicate.

### `movieclip_library_state_values` — Default mouse position (1 diff line)

**Example diff:**
```
- _xmouse = 21
+ _xmouse = 0
```

Ruffle's test runner positions the virtual mouse at a non-zero coordinate derived from
the viewport/stage geometry mapping. Our native test harness initializes the mouse at
(0, 0). The test has no `viewport_dimensions` in test.toml and no mouse input events —
the value 21 is purely a Ruffle test infrastructure artifact, not a test assertion about
mouse behavior.

**Decision:** Accept 1 diff line. Low priority; would need to reverse-engineer Ruffle's
default mouse position formula (viewport center → stage coordinates → _xmouse).

### `movieclip_library_state_values` — VFS URL path format (1 diff line)

**Example diff:**
```
- _url = movieclip_library_state_values/test.swf
+ _url = /test.swf
```

Ruffle's test runner uses `file:///test.swf` as the movie URL (VfsPath root is the
test directory, so `as_str()` returns `/test.swf`). Most tests with `_url` output expect
`/test.swf`, consistent with this. However, `movieclip_library_state_values`'s expected
output uniquely expects `movieclip_library_state_values/test.swf`, suggesting this test's
expected output was generated with a different VFS root (parent of test directory rather
than test directory itself). Using `file:///{test_name}/test.swf` to match this one test
would break `movieclip_default_state` and other tests.

**Decision:** Accept 1 diff line. Use `file:///test.swf` (matches majority of tests).
The anomalous expected output is likely a Ruffle test-generation artifact.

---

## Category 6: Missing Feature (Image Loading)

**(Empty)** — `movieclip_state_values` was previously here but now passes (114/114) thanks
to image loading support via loadMovie (synthetic MovieEntry with swf_version=0, image
dimensions stored on MovieClip). Removed 2026-04-06.

---

## Category 7: Ruffle Known Failures

Tests that Ruffle itself marks as `known_failure = true` in their `test.toml`. These tests
don't pass in Ruffle either, so matching their expected output is not meaningful.

### `string_paths_reference_launder` — Ruffle known failure (stack_push issue)

**Ruffle test.toml:**
```toml
known_failure = true # See the comment in `stack_push` in avm1/activiation.rs for details
```

Ruffle marks this test as a known failure due to an architectural limitation in their AVM1
stack push implementation. We produce `0` / `undefined` instead of `100` / `50`. Since Ruffle
also fails this test, there is no correct reference to match against.

**Decision:** Accept; Ruffle known failure, no valid reference output.

### `tab_ordering_properties_tab_index_edge_case` — Conflicting test expectations (tabIndex coercion)

**Ruffle test.toml:**
```toml
known_failure = true
```

**Example diff:**
```
- asdf
+ undefined
- asdf2
+ undefined
```

Flash stores string values in `tabIndex` as-is (no coercion). Ruffle coerces `tabIndex` to
signed 32-bit integer on buttons/MovieClips, with NaN values (non-numeric strings, objects)
preserving the previous numeric value. The `tab_ordering_properties` test (293 lines, not a
known failure) expects Ruffle's coercion behavior. This edge case test expects Flash's raw
storage behavior. The two tests have irreconcilable expectations — implementing coercion for
the 293-line test causes this 4-line known-failure test to fail.

**Decision:** Accept; Ruffle known failure, contradicts `tab_ordering_properties` expectations.

### `bitmap_data_thorough/pixelDissolve` — Flash-specific Feistel return value (Ruffle panics)

**Ruffle test.toml:**
```toml
num_frames = 1
known_failure.panic = "attempt to add with overflow"
```

**Status:** 1333 / 1371 (97.2%) match. Remaining 38 diff lines are all in the
`pixelDissolve` return value (Feistel `raw_perm_index`) and the dest pixel
positions chosen by the Feistel permutation, for calls where `random_seed` is
something other than a plain finite integer (e.g. `null`, `undefined`,
`objLooksLikeNum.valueOf()`).

Ruffle panics with `attempt to add with overflow` while running this test, so
no `output.ruffle.txt` exists for `ruffle_subset_match` to promote us. The
expected `output.txt` was produced by Flash Player itself. Without a Flash
oracle, we can't determine whether Flash's coercion path is `coerce_to_i32`
(invokes `valueOf`), some plain integer cast, or something else entirely for
each arg type — and small differences in the seed change the entire Feistel
sequence.

**Decision:** Accept; Ruffle known-failure (panic) prevents `ruffle_matched`
promotion, and matching Flash exactly requires reverse-engineering Adobe's
exact coercion semantics. Most pixel placements (and all sentinel return
codes for missing/invalid args) match.

---

## Category 8: Shape Hit Test Accuracy Limits

Tests where shape-accurate `hitTest(x, y, true)` results differ due to inherent
differences in font glyph outlines, morph boundary precision, and Drawing API
stroke tessellation accuracy. 329/338 lines pass; the remaining 9 are at exact
geometric boundaries where our implementation disagrees with Ruffle's.

### `movieclip_hittest_shapeflag` — Noto Sans vs Flash device font glyph outlines (7 diff lines)

**Example diff (text glyph boundary):**
```
// _level0.clip.hitTest(262, 320, true)
- true
+ false
```

Hit testing against text glyphs uses Noto Sans TTF outlines (our device font substitute).
Flash Player uses its own proprietary built-in device fonts with different glyph outlines.
At coordinates near glyph curve boundaries (lines 71, 163, 165, 167, 171, 175, 177), the
Noto Sans outline includes or excludes the test point differently than Flash's font.

Not fixable without Flash's actual glyph outlines, which are proprietary.

**Decision:** Accept; font metric incompatibility between Noto Sans and Flash device fonts.

### `movieclip_hittest_shapeflag` — Morph fill boundary precision (1 diff line)

**Example diff (morph shape boundary):**
```
// _level0.clip.hitTest(400, 300, true)
- false
+ true
```

Line 296: Morph shape 41 at interpolated position (400, 300) with fill0=1. Our
floating-point quadratic curve winding solver says the point is inside the fill, but
Ruffle's integer-arithmetic approach (via `lerp_twips` rounding + i64 cross-product)
says outside. The point is at the exact fill boundary where both implementations are
technically correct within their precision domains.

**Decision:** Accept; inherent floating-point vs integer precision difference at exact boundary.

### `movieclip_hittest_shapeflag` — Drawing API stroke tessellation (1 diff line)

**Example diff (scribble curve boundary):**
```
// _level0.clip.hitTest(672, 670, true)
- false
+ true
```

Line 137: A stroke-only Drawing API shape ("scribble") is hit-tested near a curve boundary.
Our stroke hit testing uses quad expansion (perpendicular rectangles around flattened curve
segments), while Ruffle uses true distance-to-curve testing. At this specific boundary point,
the quad expansion incorrectly includes the test point. Path-based stroke distance was
investigated but fixing this point introduced 2 regressions at other scribble boundary points.

**Decision:** Accept; tessellation accuracy at curve boundaries, not worth trading regressions.

---

### `from_shumway/avm1/text-bind` — device-font file mismatch: text ~14px too low (~1900 outlier pixels, max diff 158)

**Test:** image-only comparison. Both render "SUCCESS" in magenta
(`#d662c6`) at the same font size (42) with correctly-formed glyphs — but
our text sits **~14px lower** than the expected image (ours text-top
y≈86 vs expected y≈72; identical 31px glyph height = a pure vertical
offset). An aligned single-glyph comparison shows the glyph shapes/AA
match Ruffle; the outliers are the vertical misalignment, not glyph
quality.

**Root cause (investigated end-to-end 2026-06-02): a device-font
font-FILE mismatch, not a layout or tessellation bug.** The SWF declares
font_id=1 as `_sans` device font with empty `<glyphs/>` (`DefineFont3`,
no embedded glyphs). Which Noto Sans resolves `_sans` decides the
baseline:

- **Our recompiler** synthesizes device-font glyphs/metrics from its
  bundled `SWFRecomp/assets/NotoSans.ttf` — a full Noto, `unitsPerEm=1000`,
  `hhea.ascent=1069` = **1.069 em**. The runtime places the first-line
  baseline at `field_top + ascent·scale + gutter`
  (`tag.c::textfield_glyph_render_cb`), so text lands lower.
- **The `text-bind` test dir ships its OWN `NotoSans.ttf`** (25 KB subset,
  `unitsPerEm=1024`, `hhea.ascent=784` = **0.7656 em**) plus a `fonts.conf`
  mapping `sans-serif`→"Noto Sans". Ruffle's oracle resolves `_sans` to
  *that* font via fontconfig → baseline ~14px higher.

**Proof:** temporarily swapping the test's `NotoSans.ttf` into
`SWFRecomp/assets/` moves our text-top from y=86 to **y=73, matching the
expected y=72 within 1px** (outliers 1961→1462; the residual is sub-pixel
AA). So our text layout is correct — only the font's vertical metrics
differ.

**Why we don't "fix" it:** Ruffle's *own* bundled fallback device font
(`core/assets/notosans.subset.ttf.gz`) is **byte-identical to our
`assets/NotoSans.ttf`** (both 243912 bytes, 1.069 em). So in the normal
case — real games, and any SWF/test that doesn't ship a custom device
font — our device-font text **matches Ruffle's default**. (A bare Ruffle
exporter run on this SWF, ignoring the test's `fonts.conf`, renders at
y=84 ≈ our y=86.) text-bind diverges only because it bundles a custom
metrics font we don't resolve at recompile time. Replicating per-test
fontconfig device-font resolution in the recompiler is high-effort /
narrow value; switching our bundled font to the 0.7656 em subset would
fix this one test but **diverge from Ruffle's default fallback and from
real games** — a net regression. (Note: an earlier "shrink the
synthesized ascent" idea was wrong — it measured against this test's
custom-font oracle rather than Ruffle's default.)

**Decision:** Accept; device-font vertical metrics depend on which font
resolves `_sans`, and our choice matches Ruffle's default fallback font.
The divergence is specific to this test's bundled custom font.

---

## Category 9: Video Decoder Implementation Differences

Image-comparison tests that render decoded FLV frames at pixel-perfect parity with
Ruffle. Ruffle uses the pure-Rust `h263-rs` + `h263-rs-yuv` crates for Sorenson Spark
(FLV codec 2); we use libavcodec's `flv1` decoder + libswscale for YUV→RGB. Both are
valid H.263/Spark decoders and produce visually identical output, but they use
different fixed-point arithmetic internally (h263-rs-yuv: 16.16 with explicit
TV→full range expansion; swscale: its own routine with auto-detected colorspace).
Per-channel results typically differ by 1-3 levels in solid regions and up to ~140
at frame edges (different bilinear resampling). See
`SWFRecompDocs/plans/video-codec-support-plan.md`.

### `netstream_play_flv` — Sorenson Spark pixel parity (~52k outliers, max diff 64)

The trace test (22/22) passes — `onStatus` events, NetStream lifecycle, and FLV
metadata parsing all match Ruffle. After the 2026-05-13 Phase 1 landing of
GPU-side matrix-scale rendering for the Video display object
(`renderer_draw_bitmap_quad_scaled`, see
`SWFRecompDocs/plans/video-display-flash-parity-plan.md`), the decoded frame is
rendered at the SWF-declared bounds (160×120) per Flash's documented Video
render rule; the on-stage size matches expected. The remaining diff is purely
**libavcodec H.263 vs Ruffle's `h263-rs-yuv` pixel precision**: libavcodec's
YUV→RGB output drifts 1-3 levels per channel from Ruffle's pure-Rust decoder in
solid regions, plus larger drifts at the resampling boundary where the GPU
sample-stretch (320×234 → 160×120) interacts with codec-output differences.
Both are valid H.263/Spark decoders; the difference is fixed-point arithmetic
choices, not a correctness gap.

**Decision:** Accept; content decodes correctly and renders at the correct
on-stage size. Trace test continues to pass.

---

## Category 10: Watch Handler Deep Re-entrancy (SWF7 Recursion Depth)

New upstream tests (`watch_special_recursion_*`, `known_failure = true`). When a
watched property is set from *inside* its own `watch` handler, Flash re-fires the
handler a version-specific number of times before bottoming out: **SWF6 fires it
once** (then commits the value without re-firing); **SWF7+ recurses 65 levels**
(single property) or **130 levels** (two mutually-recursive properties). Ruffle
recurses unboundedly here (hence the tests are `known_failure`); our previous
behavior was an unbounded C-stack recursion → **SEGFAULT**.

We now bound this with a per-`(object, property)` firing stack capped at
`accessorReentryLimit()` (1 for SWF6, 65 for SWF7+ — the same depth Flash uses
for `addProperty` getter/setter re-entry), plus a combined `MAX_SPECIAL_DEPTH`
total-nesting safety cap so the mutually-recursive "double" case cannot overflow
the C stack (`action.c`, `g_watch_firing` / `watch_firing_depth`).

| Test | Result | Why not full match |
|------|--------|--------------------|
| `watch_special_recursion_swf6` | **ruffle_matched** | o1 matches Flash exactly; o2 residual ⊆ Ruffle's diff |
| `watch_special_recursion_double_swf6` | **ruffle_matched** | same |
| `watch_special_recursion_swf7` | accepted diff | ships **no** `output.ruffle.txt` (no RM target); o1 matches Flash (65 fires) but the o2 `addProperty`+`watch` interplay is a separate deep semantic gap |
| `watch_special_recursion_double_swf7` | accepted diff | has `output.ruffle.txt`, but ~63 RM-blocker lines remain in the o2 section, and Flash's 130-deep mutual recursion would overflow our C stack regardless |

### `watch_special_recursion_swf7` / `watch_special_recursion_double_swf7` — deep recursion + o2 interplay

The single-property `o1` section now matches Flash's bounded recursion exactly
(65 `o1.prop changed` lines). The unmatched lines are entirely in the `o2`
section, where a property has **both** an `addProperty` getter/setter **and** a
`watch`: the exact ordering of getter/setter/handler invocations and the
`undefined,undefined` argument values diverge. Matching it would require
replicating Flash's combined accessor+watch dispatch ordering and a non-recursive
130-deep evaluation; not worth it for two `known_failure` SWF7 variants.

**Decision:** Accept; segfault eliminated (the real bug). swf6 variants pass
(ruffle_matched); swf7 variants added to `ignored_tests.txt`.

---

## Category 11: Graphics — MSAA-vs-Flash Rasterizer Differences (image comparisons)

These are **image** diffs (`output.actual.png` vs `output.expected.png`). Key
references for interpreting them (see `IMAGE_COMPARISON_TESTS.md` and
`RUFFLE_VS_FLASH_DIFFERENCES.md`):

- **`output.expected.png` = the real Flash Player render** (the Flash oracle). This
  is the authoritative target.
- **`output.ruffle.png` = Ruffle's *own* render**, checked in only for
  `known_failure` image tests, frequently at `quality="low"` (1× MSAA, no AA). It
  is **not** a fidelity oracle — never treat it as ground truth (a 4× render of
  ours vs a 1× `ruffle.png` shows spurious 1px edge "shifts" that are not bugs).
- Triage with `ruffle-tests/triage_image_tests.py <test>`: it renders Ruffle at 4×
  (apples-to-apples) and classifies each diff as **fixable** (we differ from
  Ruffle, Ruffle ≈ Flash) vs **inherent** (we == Ruffle, both differ from Flash).

The cases below are **inherent**: we are byte-identical to a 4× Ruffle render and
both differ from Flash. This is the MSAA-vs-Flash-analytic-rasterizer gap — Flash's
coverage rasterizer + thin-stroke pixel-hinting produces crisp edges/seams that a
4× MSAA renderer (ours and Ruffle's alike) antialiases into a sub-pixel blend.

### `display_object_properties` — MSAA edge/stroke antialiasing (~192 image px)

`us-vs-Flash = 192`, `us-vs-Ruffle = 0`, `Ruffle-vs-Flash = 192`. Thin 1px diff
lines along shape edges where our (and Ruffle's) MSAA antialiasing differs from
Flash's analytic coverage. Same class as `from_gnash …/simple_loop_test` (hairline
pixel-snapping; see that file's Category 5 for the detailed mechanism).
**Decision:** Accept; we match Ruffle, no fix without reimplementing Flash hinting.

**FIXED (not accepted), for the record:** `movieclip_setmask` was in this bucket at
3594 px, but its residual turned out to be *missing* drawing-API stroke geometry,
not the MSAA gap. Three fixes took it to **0 px (pixel-perfect, beats Ruffle's
16px)**: close the stroke on filled open paths, mask stencils use fill-only, and
per-vertex miter joins (`fix(runtime)…`, `fix(graphics)…`, `feat(graphics): miter
joins…`). Rule of thumb: if Ruffle ≈ Flash but we don't, it's a *fixable* geometry
gap; if we == Ruffle, it's inherent.

**Known *fixable* gap (NOT accepted — tracked for follow-up):** the gradient-draw
tests `movieclip_begin_gradient_fill` (1266 px) and `movieclip_line_gradient_style`
(1052 px) still fail, but **Ruffle ≈ Flash there (180/151 px) while we are far off**
→ a real SWFRecomp **gradient color-ramp/banding** gap (the diagonal-stripe/arc
banding in the diff), a distinct next target. Do not file these as accepted.

---

## Summary Table

| Test | Category | Diff pairs | Decision |
|------|----------|-----------|----------|
| `display_object_properties` | Graphics: MSAA edge AA vs Flash analytic/hairline | ~192 img px | Accept; we==Ruffle, both differ from Flash |
| `date` | Platform UB (NaN/Infinity year cast) | ~9 | Accept; no portable fix |
| `date` | Float precision (TimezoneOffset extreme dates) | ~1 | Accept; edge case |
| `date` | Inconsistent expected output (UTCHours at −8.64e15) | ~18 | Accept; Ruffle test bug |
| `date` | Flash UB (Infinity getter values) | ~14 | Accept; prefer NaN (spec-correct) |
| `array_sort` | Flash quirk (non-ASCII CASEINSENSITIVE ordering) | 1 | Accept; locale-dependent, not reproducible |
| `array_sort` | Flash quirk (sortOn multi-key DESCENDING flag) | 2 | Accept; undocumented Flash internals |
| `movieclip_getbounds` | Float precision (morph getBounds matrix) | 2 | Accept; 0.0001px beyond epsilon |
| `movieclip_library_state_values` | Test harness limitation (default mouse position) | 1 | Accept; Ruffle infrastructure artifact |
| `movieclip_library_state_values` | Test harness limitation (VFS URL path format) | 1 | Accept; anomalous expected output |
| `native_objects_swf6` | Ruffle vs Flash (TextField in SWF6) | 1 | Accept; we match Flash, Ruffle's test is `known_failure` |
| `native_subclasses` | Platform UB (Date timezone) | 1 | Accept; timezone-dependent |
| `mcl_replace_root_swf7_to_swf5` | Ruffle vs Flash (SWF7 undefined concatenation) | 1 | Accept; our `"" + undefined` = `"undefined"` is correct per Flash |
| `mcl_replace_root_swf7_to_swf6` | Ruffle vs Flash (SWF7 undefined concatenation) | 1 | Accept; same as above |
| ~~`movieclip_state_values`~~ | ~~Missing feature~~ | ~~75~~ | **REMOVED** — now PASS (114/114) via image loading support |
| `string_paths_reference_launder` | Ruffle known failure (stack_push) | 2 | Accept; Ruffle also fails this test |
| `tab_ordering_properties_tab_index_edge_case` | Ruffle known failure (conflicting test expectations) | 4 | Accept; contradicts `tab_ordering_properties` |
| `movieclip_hittest_shapeflag` | Hit test accuracy (Noto Sans glyph outlines) | 7 | Accept; proprietary Flash font metrics |
| `from_shumway/avm1/text-bind` | Image: device-font file mismatch — text ~14px too low (test ships a 0.7656 em NotoSans + fonts.conf; we use our 1.069 em bundled Noto, which matches Ruffle's default fallback) | ~1900 px | Accept; device-font vertical metrics depend on which font resolves `_sans`; we match Ruffle's default |
| `movieclip_hittest_shapeflag` | Hit test accuracy (morph boundary precision) | 1 | Accept; float vs integer precision |
| `movieclip_hittest_shapeflag` | Hit test accuracy (Drawing API stroke tessellation) | 1 | Accept; tessellation boundary |
| `bitmap_data_thorough/pixelDissolve` | Ruffle known failure (panic) + Flash-specific Feistel coercion | ~38 | Accept; 97.2% match, no Ruffle oracle for `ruffle_matched` |
| `netstream_play_flv` | libavcodec H.263 vs h263-rs pixel precision | ~52k image outliers, max diff 64 | Accept; trace passes, on-stage size matches Flash after Phase 1 matrix-scale render, residual diff is decoder fixed-point arithmetic |
| `watch_special_recursion_swf7` | Deep watch re-entrancy (SWF7) + o2 addProperty/watch interplay; no `output.ruffle.txt` | ~part of test | Accept; segfault fixed, o1 matches Flash (65 fires); see Category 10 |
| `watch_special_recursion_double_swf7` | Deep mutual watch re-entrancy (130-deep, overflows C stack) + o2 interplay | ~63 | Accept; segfault fixed; see Category 10 |
