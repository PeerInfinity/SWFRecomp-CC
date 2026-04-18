# Flash AVM1 f64 → String Formatting Plan
<!-- TESTS: Number-v5, Number-v6, Number-v7, Number-v8, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8 -->

Last updated: 2026-04-18

## Status: NOT STARTED — finding documented, implementation deferred (risk of broad regressions)

## Summary

Our `flash_format_double` in `SWFModernRuntime/src/actionmodern/action.c` uses
C's `snprintf("%.14e", d)` for scientific notation (exponent < -5 or > 14).
This produces IEEE-correct binary-to-decimal rounding, which disagrees with
Flash Player's buggy-but-deterministic decimal-shift-and-round algorithm in a
small number of cases.

## Concrete example (Number-v6/v7/v8, 4 diffs each)

SWF bytecode pushes IEEE 754 double `0x0008E0A3A2DE80EB` as `a` at
`Number-v6/RecompiledScripts/script_2.c:20791` (ConstantPool16[299] is the
string `"1.23456789123457e-308"` — the expected-output literal, not the value).
The raw f64 numeric value is `1.234567891234565e-308` (shortest-repr).

- Our output: `"1.23456789123456e-308"` (C's `%.14e` rounds the 15th digit to
  `6` because the exact value `1.23456789123456485411e-308` is closer to
  `...56e-308` than `...57e-308`).
- Flash / Ruffle output: `"1.23456789123457e-308"` (rounded up).

Same pattern repeats at 4 magnitudes in each Number-v[5–8] test:
`±1.23456789123457e-308`, `±1.23456789123457e-6`. 4 lines per test × 4 tests =
16 data lines; plus 2 count-lines per test → 6 diffs × 4 tests = 24 total diffs.
If fixed, **Number-v6/v7/v8 all likely flip to PASS** (Number-v5 has other
diffs too — check separately).

## Root cause

Flash Player (and Ruffle, which replicates Flash's bugs) implements f64 →
string via a decimal-shift-and-round algorithm that accumulates floating-point
error differently from IEEE-correct rounding:

1. Extract base-2 exponent from the f64 bits.
2. Compute base-10 exponent = `round(exp_base2 * 0.301029995663981)` (imprecise
   log10(2) constant).
3. Shift mantissa into `[0, 10)` via `decimal_shift(n, -exp)`.
4. Extract 15 decimal digits by repeated `digit = (int)mantissa; mantissa =
   (mantissa - digit) * 10.0`.
5. Peek at the 16th digit; round away from zero if ≥ 5; carry 9→0 with
   increment.
6. Band-aid cleanup for rounding artefacts (`9.999… → 10` overflow, leading
   zeros, `100e15 → 1e17`).

Reference implementation: `ruffle/core/src/avm1/value.rs:611-793`
(`f64_to_string`).

The accumulated multiplication-by-10 error systematically favors rounding up
near half-digits, producing results one ULP-in-the-last-digit higher than
IEEE-correct rounding for values like `1.234567891234565e-308`.

## Why it's deferred

- **Broad blast radius.** `flash_format_double` is called from `convertString`,
  `varToStringBuf`, `flashPrintValue`, Array join/toString, Number.toString,
  `actionTrace`, and many other sites. Changing its output can flip any test
  that prints a number.
- **Risk of regressions.** Many avm1 / gnash tests currently pass (or are
  `ruffle_matched`) via the current `%.14e` formatter. A port of Ruffle's
  algorithm that's not bit-identical in its edge cases (especially around
  subnormals, very large magnitudes, integer boundaries, and the `1e17`
  band-aid) could regress dozens of tests.
- **Small gain vs. effort.** ~3 tests likely flip to PASS (Number-v6/v7/v8).
  For comparison, a single architectural fix elsewhere (e.g. Object.prototype
  for version gating) has historically flipped 20+ tests. Better to attempt
  this in a dedicated session with a reference implementation alongside and
  targeted per-magnitude test cases.

## Implementation sketch (for whoever picks this up)

1. Add a static helper `flash_avm1_f64_to_string(char* buf, int buf_size,
   double d)` next to `flash_format_double` in `action.c`.
2. Port `f64_to_string` from `ruffle/core/src/avm1/value.rs:611-793` line by
   line. Keep the exact `LOG10_2` constant (`0.301029995663981`, not Rust's
   `f64::LOG10_2`) to reproduce the rounding bug.
3. Route `Number.prototype.toString` (line ~55675 of `action.c`) through the
   new helper first; fall back to `flash_format_double` only if needed to
   preserve existing behavior on other paths.
4. Run `Number-v5/v6/v7/v8` and `toString_valueOf-v5/v6/v7/v8` locally and
   confirm the expected diffs disappear with no new lines regressing.
5. Run the full avm1 suite locally (or via CI) and audit regressions. Likely
   candidates for regressions: tests that print large/small floats, tests that
   compare `n.toString()` to a string literal.
6. If regressions are limited, switch all `flash_format_double` callers to the
   new helper. If broad, keep the dual path with toString routing through the
   AVM1 helper and other sites through the existing formatter.

## Related tests

| Test | Diffs | Likely diffs from this |
|------|-------|------------------------|
| Number-v5 | 16 | 4+2 count |
| Number-v6 | 6 | 4+2 count |
| Number-v7 | 6 | 4+2 count |
| Number-v8 | 6 | 4+2 count |
| toString_valueOf-v5 | 48 | some |
| toString_valueOf-v6 | 8 | some |
| toString_valueOf-v7 | 10 | some |
| toString_valueOf-v8 | 10 | some |
