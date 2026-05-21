# TextFormat-v8 Investigation Plan
<!-- TESTS: TextFormat-v8 -->

Last updated: 2026-05-21 (Phase 1 landed → TextFormat-v8 promoted to
`ruffle_matched`. Setting a TextFormat numeric property to a
non-numeric string now coerces via ECMA ToNumber in SWF8+, yielding
NaN → INT_MIN instead of atof()'s 0. Our residual diff is only the
Phase 2 getTextExtent font-metric lines, which Ruffle fails too —
strict subset → auto-promote.)

<!-- PLAN_META
id: TEXTFORMAT_V8_PLAN
status: in_progress
phases:
  - id: 1
    name: "Negative INT_MIN clamping on numeric setters (blockIndent/leading/indent/size)"
    status: completed
  - id: 2
    name: "getTextExtent font-metric precision (ascent/descent/width/height/textFieldWidth/textFieldHeight)"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac); TextFormat-v8 became visible at that point. TextFormat-v5/v6 PASS; v7 ruffle_matched."
related:
  - id: TEXTFIELD_VN_PLAN
    reason: "Setter-coercion bugs in TextFormat parallel those in TextField. Not shared code but similar pattern."
blockers: []
status_note: |
  Only two failure clusters; both are local and self-contained. Phase
  1 is mechanical, Phase 2 requires comparing our font metrics against
  Flash's bundled font to decide whether to ship dedicated metrics
  or document as ACCEPTED_DIFFS / RUFFLE_VS_FLASH_DIFFERENCES. Promotion
  plumbing in place via `known_failure = true` + `output.fp9-18.ruffle.txt`.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| TextFormat-v8 | 128/172 | 74.4% | output_mismatch |

After Phase 1 (2026-05-21, pending CI): **`ruffle_matched`**. The 8
INT_MIN clamping lines (176/186 blockIndent, 208/218 leading,
240/250 indent, 268/278 size) now PASS. The residual diff is only
the Phase 2 getTextExtent font-metric lines — Ruffle fails those too
(its `output.fp10.ruffle.txt` returns 0/4 for the same lines, an
even larger divergence from Flash), so our diff is a strict subset
and `verify_output.py::ruffle_subset_match` auto-promotes the test.

For comparison, TextFormat-v5/v6 PASS and v7 is ruffle_matched per
`complete/GNASH_FEATURE_PLAN.md`. v8 adds assertions the others
don't have.

### Phase 1 fix (2026-05-21)

Root cause was simpler than the plan's "ToInt32 wrap" hypothesis:
the test sets `tf.blockIndent = "string"` (a non-numeric *string*),
and Flash coerces it via ECMA ToNumber → NaN, which the TextFormat
integer setter maps to INT_MIN (-2147483648). Our `tfCoerceInteger`
already mapped NaN → INT_MIN correctly, but its STRING branch used
`atof()`, which yields **0.0** for any unparseable input instead of
NaN — so `d` was 0, in-range, and stored as 0.

Fix in `SWFModernRuntime/src/actionmodern/action.c`: new
`tfStringToNumber()` helper. For SWF8+ it routes the string through
`convertFloat()` (the AVM1 ECMA ToNumber, which correctly returns
NaN for non-numeric input). For SWF7 and below it keeps the old
`atof()` behaviour — TextFormat-v5/v6/v7 expect `tf.size = "string"`
→ 0, not INT_MIN (a genuine version difference; first attempt
without the version gate regressed v5 lines 266/276). All four tf
numeric-coercion functions (`tfCoerceInteger`, `tfCoerceNonNegInt`,
`tfCoerceUnsigned`, `tfCoerceFloat`) now call the helper from their
STRING branch.

Verified no regressions: TextFormat-v5/v6 PASS, v7 RM (all
unchanged); AVM1 `text_format_rounding_swf7/swf8`,
`text_format_get_text_extent_undefined_width`, `gettextextent`,
`edittext_default_format`, `edittext_default_format_font_style`,
`edittext_font_size`, `edittext_leading`, `edittext_margins`,
`edittext_letter_spacing` all PASS; gnash misc-ming
`DefineEditTextTest`/`DefineEditTextVariableNameTest`/`DefineTextTest`
unchanged.

## Test source

Gnash testsuite/actionscript.all/TextFormat.as. The failing portion
of v8 exercises:

- TextFormat property setters with extreme numeric inputs (-2^31)
- `tf.getTextExtent(...)` returns layout dimensions for given text
  + format combinations (Phase 2)

## Failure clusters

### A. Negative INT_MIN clamping (Phase 1)

Lines: 176, 186 (`blockIndent`); 208, 218 (`leading`); 240, 250
(`indent`); 268, 278 (`size`).

```
- PASSED: tf.blockIndent == -2147483648 [./TextFormat.as:176]
+ FAILED: expected: -2147483648 obtained: 0
```

The test sets `tf.blockIndent` (and similar fields) to a specific
extreme negative value via:

```
tf.blockIndent = -2147483649;   // line 176 expects clamp to -2147483648
// or
tf.blockIndent = "-2147483649"; // line 186 same expected, via string coercion
```

Flash coerces the input via ToInt32 (using ECMA truncate-then-wrap
semantics), so -2147483649 wraps to +2147483647 in the intermediate
step, but Flash's specific TextFormat handler then clamps to INT_MIN
for negative-overflow inputs. Our setter is returning 0 instead.

Likely root cause: our setter either rejects the over-range value
(returns to default 0) or coerces via `(int)(double)val` which is
undefined behaviour for out-of-range doubles in C (often returns 0
or INT_MIN depending on platform). Flash-compatible fix: ToInt32
semantics matching ECMA-262 (truncate, mod 2^32, signed reinterpret),
then clamp result to [INT_MIN, INT_MAX] — but the expected output
suggests Flash specifically maps the lower-overflow case to INT_MIN
(not INT_MAX after wrap).

Verify with simpler test cases first: try `tf.size = -2147483648`
(no wrap needed). If that returns INT_MIN correctly, the bug is in
the wrap. If it also returns 0, the bug is in the basic int-coerce
plumbing.

Estimate: 1-2 hours.

### B. getTextExtent font-metric precision (Phase 2)

Lines: 335, 336, 338, 344, 345, 352, 354, 356, 360, 383, 394, 395,
399, 406, 414, 416, 424, 425, 432, 434, 442, 443, 447, 448, 453,
454, 458 (and likely more in the tail).

```
- PASSED: te.textFieldWidth == 37 [./TextFormat.as:335]
+ FAILED: expected: 37 obtained: 32.95
- PASSED: te.ascent == 11.1 [./TextFormat.as:338]
+ FAILED: expected: 11.1 obtained: 12.828
- PASSED: te.descent == 2.8 [./TextFormat.as:345]
+ FAILED: expected: 2.8 obtained: 3.516
```

`getTextExtent(text, [width])` returns an object with `ascent`,
`descent`, `width`, `height`, `textFieldWidth`, `textFieldHeight`.
All six values are systematically wrong by small amounts that look
like font-metric drift:

- Expected ascent 11.1, we produce 12.828 (≈15% high)
- Expected descent 2.8, we produce 3.516 (≈25% high)
- Expected width 33, we produce 28.95 (≈12% low)

This is most likely **device-font precision**: Flash bundles specific
font metrics for its default `_serif` / `_sans` / `_typewriter`
device fonts, and our impl substitutes a different font (Noto Sans
per the existing pixel-text-layout work) whose ascent/descent/glyph-
width values don't match Flash's. The `te.textFieldWidth = 37`
expected suggests Flash's font has a specific cap-height + side-
bearing combination we are not replicating.

Three possible approaches:

1. **Ship Flash-matching font metrics.** Identify the font Flash
   uses for its default device font (likely Times for `_serif`) and
   embed its metrics in the layout engine. High effort, but is the
   only way to get precise PASS on this test.
2. **Document as RUFFLE_VS_FLASH or ACCEPTED_DIFFS.** Most likely
   outcome — Ruffle's `output.fpN.ruffle.txt` probably also
   diverges from Flash's expected values, and our diff would land
   inside Ruffle's diff set → auto-promote to `ruffle_matched`.
3. **Add per-test font hint.** If TextFormat-v8 (and similar
   text-layout tests) opted into specific font metrics via test.toml,
   we could special-case at validate time. Too invasive vs. value.

First step: diff `output.fp9-18.ruffle.txt` against `output.fp9-18.txt`
for TextFormat-v8 specifically:

```
diff /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/TextFormat-v8/output.fp9-18.txt \
     /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/TextFormat-v8/output.fp9-18.ruffle.txt
```

If Ruffle also diverges on these lines, our path is `ruffle_matched`
promotion (Approach 2). If Ruffle matches Flash, we need Approach 1.

Estimate: 30 min diagnosis. If promotion path: 1 hour to document
in RUFFLE_VS_FLASH_DIFFERENCES.md. If real fix needed: 4-8 hours
of font-metric work.

## Recommended fix order

1. **Phase 2 diagnosis (diff against ruffle.txt)** — 30 min.
   Determines whether the rest of Phase 2 is a hard fix or a
   documentation task.
2. **Phase 1 (INT_MIN clamping)** — 1-2 hours, independent.
3. **Phase 2 fix or document** — depending on Phase 2 diagnosis.

Total estimate: 2-10 hours depending on Phase 2 outcome.

## Promotion plumbing

`known_failure = true` + `output.fp9-18.ruffle.txt`. Subset-match
auto-promotes to `ruffle_matched`. If Phase 2 diagnoses Ruffle-matches-
us, the test will likely auto-promote as soon as Phase 1 lands.
