# Flash-Correct Behavior Regressions Plan
<!-- TESTS: string_relational_compare, bitmap_filters, edittext_default_format_empty -->

<!-- PLAN_META
id: FLASH_CORRECT_REGRESSIONS
status: incomplete
phases:
  - id: 1
    name: "Revert u16_cmp to raw code-unit comparison"
    status: not_started
  - id: 2
    name: "Revert filter angle defaults and setter to Flash-correct values"
    status: not_started
  - id: 3
    name: "Update documentation"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-07

## Problem

Two commits introduced Ruffle-compatible behavior that overrode previously
Flash-correct implementations. The tests now "pass" against Ruffle's expected
output but produce wrong results compared to Flash Player:

1. **`string_relational_compare`** — `u16_cmp` changed from raw UTF-16 code-unit
   comparison to Unicode code-point comparison (commit `600dfa6d`).
2. **`bitmap_filters`** — Filter angle defaults changed from `45.0` to
   `44.9999999772279`, and angle setter gained a gratuitous deg→rad→deg
   round-trip (commit `679ccc32`).

A third test, **`edittext_default_format_empty`**, was also investigated but is
**not a regression** — the `display` property was genuinely implemented, and the
RUFFLE_VS_FLASH_DIFFERENCES.md entry about it was factually wrong. That entry
should be removed (Phase 3).

## Phase 1: Revert `u16_cmp` to raw code-unit comparison

**File:** `SWFModernRuntime/src/actionmodern/action.c` lines 251–263

**Root cause:** Commit `600dfa6d` changed `u16_cmp` from a simple per-code-unit
loop to a code-point-aware comparison using `u16_decode_codepoint()`. This
combines surrogate pairs `[0xD800, 0xDC02]` into U+10002 before comparing,
changing the sort order for characters above U+D800.

**Flash behavior:** String relational operators (`<`, `>`) compare raw UTF-16
code units, matching ECMAScript semantics. For `"\uFF61" < "\uD800\uDC02"`:
- First code units: 0xFF61 vs 0xD800
- 0xFF61 > 0xD800 → result is `false`

**Current (wrong) behavior:** Compares code points U+FF61 (65377) vs U+10002
(65538) → result is `true` (matches Ruffle).

**Fix:** Replace the current `u16_cmp` with raw code-unit comparison:

```c
// Lexicographic comparison of two UTF-16 strings by raw code unit (Flash/ECMAScript semantics)
static int u16_cmp(const uint16_t* a, u32 a_len, const uint16_t* b, u32 b_len)
{
    u32 min_len = a_len < b_len ? a_len : b_len;
    for (u32 i = 0; i < min_len; i++) {
        if (a[i] != b[i]) return (int)a[i] - (int)b[i];
    }
    return (int)a_len - (int)b_len;
}
```

The `u16_decode_codepoint` helper (lines 235–249) can remain — it may be used
elsewhere for valid purposes (e.g., UTF-16→UTF-8 output conversion). Only
`u16_cmp` should stop using it.

**Test impact:** `string_relational_compare` will go back to failing on line 4
(3/4 match). This is an existing accepted Ruffle-vs-Flash difference already
documented and already in `ignored_tests.txt`.

**Regression risk:** Low. The only test that exercises surrogate-pair string
comparison is `string_relational_compare`. All other string comparisons use BMP
characters where code-unit and code-point order are identical. Run the full test
suite via CI to confirm.

## Phase 2: Revert filter angle defaults and setter

**File:** `SWFModernRuntime/src/actionmodern/action.c`

### 2a: Default angle values (3 sites)

Commit `679ccc32` changed filter constructor defaults from `45.0` to
`44.9999999772279` (Ruffle's truncated-pi artifact: `0.785398163 rad * 180/π`).

| Line | Filter | Current (wrong) | Fix |
|------|--------|-----------------|-----|
| 44162 | BevelFilter | `44.9999999772279` | `45.0` |
| 44230 | DropShadowFilter | `44.9999999772279` | `45.0` |
| 44269 | GradientBevel/GlowFilter | `44.9999999772279` | `45.0` |

### 2b: Angle setter round-trip (1 site)

Lines 35506–35510 add a gratuitous degrees→radians→degrees conversion:
```c
dv = fmod(dv, 360.0);
double rad = dv * 3.14159265358979323846 / 180.0;
double deg_back = rad * 180.0 / 3.14159265358979323846;
value_var = makeF64(deg_back);
```

For integer angles this round-trip is lossless (IEEE 754 f64), so it doesn't
cause visible diffs for values like 0, 1, 6, -1, 50. But it's unnecessary
complexity that exists only to mimic Ruffle's internal storage model. Flash
stores angles as degrees directly.

**Fix:** Simplify the angle setter to just `fmod(val, 360)`:
```c
if (prop_name_len == 5 && memcmp(prop_name, "angle", 5) == 0) {
    dv = fmod(dv, 360.0);
    value_var = makeF64(dv); handled = 1;
}
```

### Test impact

`bitmap_filters` expected output has 8 lines with Ruffle-specific angle
precision artifacts:

| Expected (Ruffle) | Flash-correct | Count |
|-------------------|---------------|-------|
| `44.9999999772279` | `45` | 4 lines |
| `49.9991703850277` | `50` (approx) | 3 lines |
| `44.999253346525` | `45` (approx) | 1 line |

Reverting the defaults (Phase 2a) will fix the 4 lines with `44.9999999772279`.
The other 4 lines (`49.9991703850277` and `44.999253346525`) come from
explicitly-set angles where Ruffle's internal precision diverges from Flash. Our
`fmod` approach will return exact values (e.g., `50.0` for angle=50), so these
will also become diffs.

Net impact: `bitmap_filters` goes from 548/548 → ~540/548. The test is already
in `ignored_tests.txt` (categorized under "Bitmap data operations").

**Regression risk:** Low. Filter angle precision only affects `bitmap_filters`.
No other test exercises filter angle getters with precision-sensitive values.

## Phase 3: Update documentation

### 3a: Remove stale `edittext_default_format_empty` entry

Remove the "TextFormat `display` Property in Expected Output" section from
`RUFFLE_VS_FLASH_DIFFERENCES.md` (currently at lines 65–78). The analysis was
wrong — the test source DOES access `tf.display` (line 8 of `test.as`), and the
`display` property is now correctly implemented. The test passes with
Flash-correct behavior.

Also remove `edittext_default_format_empty` from `ignored_tests.txt` (line 93)
and from `ACCEPTED_DIFFS.md` if present.

### 3b: Update `bitmap_filters` angle entry

Update the "Filter Angle Property Precision" section in
`RUFFLE_VS_FLASH_DIFFERENCES.md` (currently lines 121–141) to note that:
- The Ruffle-compat angle code has been reverted
- Our implementation now returns Flash-correct exact angle values
- The 8-line diff is a permanent Ruffle-vs-Flash difference

### 3c: Update CURRENT_STATUS.md

Update the near-passing table and any references to these tests.

## Verification

After Phases 1–2, run locally:
```bash
python3 ruffle-tests/verify_output.py --test=string_relational_compare --diff --verbose
# Expected: FAIL, 3/4 lines match (line 4 differs: true vs false)

python3 ruffle-tests/verify_output.py --test=bitmap_filters --diff --verbose
# Expected: FAIL, ~540/548 lines match (8 angle precision lines differ)

python3 ruffle-tests/verify_output.py --test=edittext_default_format_empty --diff --verbose
# Expected: PASS, 100/100 (unaffected by this plan)
```

Then commit and run CI to verify no regressions in other tests.
