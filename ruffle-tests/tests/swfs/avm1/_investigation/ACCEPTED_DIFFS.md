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

### `netstream_play_flv` — Sorenson Spark pixel parity (52,828 outliers, max diff 140)

**Example diff (solid red region inside the decoded frame):**
```
expected (R, G, B, A) = (248, 48, 0, 255)
actual   (R, G, B, A) = (246, 48, 0, 255)
```

The trace test (22/22) passes — `onStatus` events, NetStream lifecycle, and FLV
metadata parsing all match Ruffle. The image test fails because libavcodec's
YUV→RGB output drifts 1-3 levels per channel from Ruffle's, and our CPU bilinear
resample to the SWF's declared display bounds differs from Ruffle's GPU-side
sampling. The rendered content is visually correct (Japanese-flag test pattern at
the expected position and size).

**Decision:** Accept; matching another H.263 decoder bit-exactly is not a goal
of the project. Trace test continues to pass.

---

## Summary Table

| Test | Category | Diff pairs | Decision |
|------|----------|-----------|----------|
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
| `movieclip_hittest_shapeflag` | Hit test accuracy (morph boundary precision) | 1 | Accept; float vs integer precision |
| `movieclip_hittest_shapeflag` | Hit test accuracy (Drawing API stroke tessellation) | 1 | Accept; tessellation boundary |
| `bitmap_data_thorough/pixelDissolve` | Ruffle known failure (panic) + Flash-specific Feistel coercion | ~38 | Accept; 97.2% match, no Ruffle oracle for `ruffle_matched` |
| `netstream_play_flv` | Video decoder pixel parity (libavcodec H.263 vs h263-rs) | 52,828 image outliers | Accept; trace passes, render is visually correct, bit-exact match not a project goal |
