# Flash AVM1 f64 → String Formatting Plan
<!-- TESTS: Number-v5, Number-v6, Number-v7, Number-v8, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8 -->

Last updated: 2026-04-18

## Status: DONE (2026-04-18) — port landed as a direct replacement for `flash_format_double`.

### Result

- `SWFModernRuntime/src/actionmodern/action.c::flash_format_double` was rewritten
  as a C port of Ruffle's `f64_to_string` (`ruffle/core/src/avm1/value.rs:611-793`),
  with helper `decimal_shift` ported from `value.rs:580-603`. The port preserves
  Flash's decimal-shift-and-round algorithm — including the imprecise
  `LOG10_2 = 0.301029995663981` constant and the 9.999→10 / 100e15 → 1e17
  band-aids — so rounding ties match Flash/Ruffle instead of IEEE-correct.
- All `flash_format_double` callers (`varToStringBuf`, `convertString`,
  `actionTrace`, Array join/toString, Number.toString wrapper, etc.) now use
  the Ruffle-compatible helper. A dual-path fallback turned out to be
  unnecessary — no regressions were observed.

### Local test impact

| Test | Before | After |
|------|--------|-------|
| Number-v6 | 6 diffs | **PASS** |
| Number-v7 | 6 diffs | **PASS** |
| Number-v8 | 6 diffs | **PASS** |
| Number-v5 | 14 diffs | 10 diffs (−4 float-format; residual SWF5-specific issues unrelated to formatting) |
| toString_valueOf-v5..v8 | unchanged | unchanged (remaining diffs are unrelated — valueOf/toString invocation bookkeeping, not number formatting) |
| Global-v7 | 31 diffs | 27 diffs (−4) |
| String-v8 | 118 diffs | 116 diffs (−2) |

Regression spot-checks on avm1 `math_min_max`, `math_swf6/7/8`, `string_coercion`,
`text_format_rounding_swf7/8`, `instanceof_coercions`, `array_sort`,
`array_sort_random`, `array_trivial`, `array_length`, `array_slice` — all PASS.
Gnash `Color-v6`, `NetStream-v8`, `Error-v8`, `Math-v5/v8`, `ops-v8` still
PASS / ruffle_matched.

### Follow-up

Move this file to `complete/` once CI has confirmed the expected improvements
and no regressions appear across the full suite.
