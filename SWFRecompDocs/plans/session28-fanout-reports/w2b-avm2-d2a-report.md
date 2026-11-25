# s28 w2b-avm2-d2a: avmplus number→string (D2A) port, bucket J of w1b-rm-avm2

Wave 2, cloud. Branch `fanout/w2b-avm2-d2a`. Base `origin/master` = `f7a0f5f2`. Corpus downloaded with
`download_tests.sh avm2 from_avmplus` on 2026-11-25 (upstream Ruffle master that day; flash-fixes applied: 3).
Graphics mode on lavapipe (`SETUP_STATUS`: apt/Pillow/Dawn OK). avmplus reference: `github.com/adobe/avmplus`
HEAD `858d034` (tamarin-redux): `core/d2a.cpp`, `core/BigInteger.cpp`, `core/MathUtils.cpp`
(`convertDoubleToString`, `convertDoubleToStringRadix`, `convertStringToDouble`), `core/NumberClass.cpp`,
`platform/*/MathUtils*` (`frexp`, `mod`).

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w2b-avm2-d2a-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w2b-avm2-d2a.patch`
  (`git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`)

No new source files, no new fixtures (every behaviour is pinned by an FP32 corpus golden).

## Verdict (lead)

**GO. All 8 bucket-J rows `ruffle_matched → pass`, plus a 9th row the brief did not price (`avm2/number_tostring`,
`fail → pass`, 168 → 0 diff lines). 0 regressions** over the gate (below). The patch also fixes a master regression
from `558c5a8cf`: `from_avmplus/ecma3/JSON/AS3Types`, which passes at the CI baseline but fails on master.


## EXPECTED-FLIP LEDGER (check CI against this)

Trace axis, graphics (and no-graphics: same code, both modes measured on 3 rows). Baseline column = CI `e1425f417`.

| row | CI baseline | this patch | note |
|---|---|---|---|
| `avm2/int_toexponential` | ruffle_matched | **pass** | `known_failure`; also in `avm2/ignored_tests.txt` (de-list) |
| `avm2/uint_toexponential` | ruffle_matched | **pass** | same |
| `avm2/number_to_string` | ruffle_matched | **pass** | `known_failure` |
| `avm2/json_parse_numbers` | ruffle_matched | **pass** | `known_failure`; needed the JSON number READER too (below) |
| `avm2/number_tostring` | output_mismatch | **pass** | upstream `ignore = true`; ACCEPTED_DIFFS Category 14 is STALE (below) |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf14` | ruffle_matched | **pass** | SWF<15 bugzilla-513039 arm |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf15` | ruffle_matched | **pass** | |
| `from_avmplus/ecma3/Number/eregress_121952` | ruffle_matched | **pass** | |
| `from_avmplus/ecma3/Number/toStringLimits` | ruffle_matched | **pass** | |

Not yield of this patch, so don't book them here: `from_avmplus/ecma3/JSON/Classes` and `JSON/adhoc` show
`ruffle_matched → pass` against the CI baseline, but they flipped in `558c5a8cf` (w1b P9). They pass on clean
`origin/master` locally, before this patch.

**Regression this patch FIXES (already on master):** `from_avmplus/ecma3/JSON/AS3Types` is `pass` in the CI
baseline, but it fails on clean `origin/master` locally ("stringify XML object FAILED! expected: "XML" got: {}").
`558c5a8cf` P9 caused it: `js_map_value` now calls `toJSON` only when `get("toJSON")` is a Function, and on an XML
receiver that get is an E4X child lookup (an empty XMLList). This patch exempts XML/XMLList from the callable test.
Measured: fail on master → pass with the patch; Classes and adhoc still pass. **If master is graded before this
patch lands, expect `AS3Types pass → fail` from `558c5a8cf`.**

Pixel axis: **none expected.** None of the 9 rows has `[image_comparisons]`. The canary below is md5-identical.

Also tighter, with no status change: `avm2/number_tofixed` and `avm2/number_toexponential` passed only through
their `[approximations]` tolerance. They now match byte-exactly (raw diff lines 20 → 0 and 70 → 0;
`1.2314e-8`, `1231500000000000000000` and so on are the Flash spellings).

## Per-test before/after (same box, graphics, clean `origin/master` vs patch; content diff lines vs `output.txt`)

| row | lines | before diff | after diff | before status | after status |
|---|---|---|---|---|---|
| avm2/int_toexponential | 1215 | 76 | 0 | ruffle_matched | pass |
| avm2/uint_toexponential | 1215 | 100 | 0 | ruffle_matched | pass |
| avm2/number_to_string | 353 | 104 | 0 | ruffle_matched | pass |
| avm2/json_parse_numbers | 131 | 4 | 0 | ruffle_matched | pass |
| avm2/number_tostring | 1050 | 168 | 0 | mismatch | pass |
| from_avmplus/as3/Types/Number/e15_7_4_6_1/swf14 | 29 | 18 | 0 | ruffle_matched | pass |
| from_avmplus/as3/Types/Number/e15_7_4_6_1/swf15 | 29 | 3 | 0 | ruffle_matched | pass |
| from_avmplus/ecma3/Number/eregress_121952 | 12 | 1 | 0 | ruffle_matched | pass |
| from_avmplus/ecma3/Number/toStringLimits | 4 | 1 | 0 | ruffle_matched | pass |
| from_avmplus/ecma3/JSON/AS3Types | 26 | 1 | 0 | mismatch (master) | pass |

## Mechanism and patch scope (AVM2 runtime only; no recompiler, no AVM1, no NG-only code)

Files and functions:
- `SWFModernRuntime/src/avm2/avm2_number.c`:
  - **New static block:** an exact port of avmplus `D2A` (`d2a_init`/`d2a_scale`/`d2a_fixup`/`d2a_next_digit`), a
    minimal exact bignum standing in for `BigInteger`, `MathUtils::frexp`/`powInt`/`quickPowTen`, and
    `BigInteger::doubleValueOf`.
  - **New exported functions:** `avm2_d2s` (= `convertDoubleToString`: modes NORMAL/FIXED/PRECISION/EXPONENTIAL,
    bugzilla 513039 flag), `avm2_d2s_radix` (= `convertDoubleToStringRadix`) and `avm2_avmplus_json_number`
    (= `convertStringToDouble` for a JSON token).
  - **Rewritten:** `print_with_radix`, `number_to_string` (radix 10 / NaN / ±Infinity bypass the radix range
    check, as in `NumberClass::_numberToString`), `number_to_fixed`, `number_to_exponential`,
    `number_to_precision` (all now go through a new `number_convert`). Removed: `print_with_precision`.
- `SWFModernRuntime/src/avm2/avm2_value.c`: `avm2_format_number` = `avm2_d2s(NORMAL, 15)`. It keeps an
  integer fast path for |d| < 1e15, which matched D2A on 3M random integers. The Ruffle-model helpers are deleted
  (`tie_round_away_from_zero`, `shortest_digits`, `format_plain`). This function is the shared ToString(Number)
  for all AVM2 code: trace, String(), +, JSON.stringify, display/text callers.
- `SWFModernRuntime/src/avm2/avm2_json.c`: the number-token reader uses `avm2_avmplus_json_number`, not `strtod`.
  `js_map_value` gets the XML/XMLList `toJSON` exemption.
- `SWFModernRuntime/include/avm2/avm2_value.h`: declarations plus the `AVM2_DTOSTR_*` constants.

What the port reproduces. Every item is pinned by an FP32 golden:
- **Fixed modes scale `r`/`s` by 10^p but not m±.** Digit generation therefore continues past the shortest digits,
  and once it "finishes" the rest is zero fill: `1000000000000000128.toFixed(0)` = `1000000000000000100`.
- **Final rounding is by the NEXT generated digit (> 4).** It runs only on the fast (double) path or in FIXED or
  PRECISION mode, and only while the generator has not already "finished". EXPONENTIAL on the BigInteger path never
  rounds. The truncating `77.1234.toExponential(0)` = `7e+1` and the `int_/uint_toexponential` digit pattern both
  fall out of this. I verified them against the goldens; I did not hand-derive every case.
- **NORMAL mode:** the exponential mantissa is capped at 15 digits and TRUNCATED for e > 20. For e ≤ −7 the `kNormal`
  arm prints every digit, then `e-N`. This replaces Ruffle's "16-character mantissa cut"; both pinned rows still
  pass.
- **`frexp` normalises subnormals,** so their m± are 2^52 too narrow and they print about 17 digits
  (`number_to_string`).
- **2^1022 and 2^1023 take the asymmetric-boundary arm,** where `value*4.0` overflows to Infinity, so both print
  `1e+308`. This is the pair Ruffle hard-codes. Here it falls out of modelling x86-64 `frexp(inf)`.
- **Zero:** `0.toExponential(0)` = `1e-15` and `0.toExponential(d)` = `0.00…e-16` fall out of D2A(0), which has
  base-10 exponent −15. They were special cases before.
- **bugzilla 513039:** the flag is set for SWF ≥ 15 (`AvmCore.cpp` BugCompatibility, `kSWF15`). Below that,
  `(-0.05).toFixed(0)` = `-1.` and `(0.00005).toFixed(2)` = `0.01`. Read from `ctx->swf_version`.
- **Radix (`convertDoubleToStringRadix`):** integer part only, built with `floor(u/radix)` in doubles. Any |v| < 1,
  negative included, is `"0"`, so `(-MIN_VALUE).toString(2)` = `"0"` (`toStringLimits`). Past 2^53 the "digit"
  `j` leaves `[0, radix)`, and the byte goes out through `newStringLatin1`. **Those are exactly
  `number_tostring`'s "random" `W`/`x`/`°`/`(`/`,`/space/0x97 characters: deterministic, not corruption.** The
  only missing piece was emitting the byte as Latin-1 (re-encoded to UTF-8) instead of a raw byte.
- **JSON reader (`convertStringToDouble`):** up to 15 digits it accumulates in a double; past 15 it builds an exact
  integer and multiplies by a DOUBLE `pow(10,k)` (inexact for k ≥ 23), then divides. So
  `1.7976931348623157e308` parses to Infinity, `1.1754944e-38` lands one ulp low, and the 270-digit string comes
  out `…12` (`json_parse_numbers`, its 4 lines).

## Dispositions (STALE: for the coordinator to edit; I did not touch dispositions)

- **`ACCEPTED_DIFFS.md` Category 14 (`avm2/number_tostring`) is STALE.** Its premise was that "31 impossible digits
  are Flash corrupting its buffer, ceiling 1019/1050". That is refuted: they are avmplus's double-arithmetic radix
  digits written as Latin-1 bytes, and this patch reproduces all 1050 lines. Strike the entry and its summary row.
  Also drop `number_tostring` from `avm2/ignored_tests.txt` (upstream `ignore = true` in `test.toml` stays
  upstream's call; the test.toml comment "Flash Player adds extra … symbols randomly" is wrong).
- **`avm2/ignored_tests.txt`: de-list `int_toexponential` and `uint_toexponential`** (now `pass`).
- **RvF candidates (Ruffle ≠ Flash; append when booking):**
  - All 9 rows: Ruffle prints shortest-round-trip, correctly-rounded digits, while Flash prints avmplus D2A.
  - Ruffle's `known_failure` comments ("print routine that adds extraneous zeros") describe exactly the 10^p-scaling
    zero fill.
  - `number_tostring`: Ruffle's `ignore` rationale is wrong.

## Gate (all on the patched tree unless noted)

- **Headline + neighbours, A/B on the same box (45 rows), see `gate.txt` below:** every `toFixed`/
  `toExponential`/`toPrecision`/`toString` row in avm2 (`int_*`, `uint_*`, `number_*`,
  `number_convert_edge_cases`, `number_convert_errors`, `coerce_string_precision`, `convert_number`,
  `parse_float*`, `primitive_toString`, `weird_number_bound_methods`, `goto_methods`, `number_constr`,
  `matrix3d_precision`, `json_parse`, `json_stringify`) plus from_avmplus `ecma3/Number/*` spot rows,
  `as3/Math/MathUtils`, `ecma3/TypeConversion/e9_8_1` and `ecma3/Expressions/e11_5_2`.
  - Only the ledger rows move.
  - `number_convert_errors` stays `ruffle_matched` with byte-identical output (its residual is bucket B, stack
    frames).
- **Wide sweep (277 rows) vs CI baseline statuses:** `regression/avm2_*` (54), all of `from_avmplus/ecma3/Number`,
  `as3/Types/Number`, `as3/Math`, `ecma3/JSON` and `ecma3/TypeConversion`, plus avm2 rows matching
  `json_|matrix|point|rectangle|colortransform|math|_width|_height|rotation|alpha|scale|number|tostring|tofixed|precision|exponential`.
  - 272 pass.
  - 4 stay `ruffle_matched`, unchanged from baseline: `matrix3d_recompose_edge_cases`, `number_convert_errors`,
    `as3/Math/e15_1_2_2` and `as3/Types/Number/cos`.
  - 1 failed (`JSON/AS3Types`): the master regression above, fixed in this patch. Re-measured after the fix: the
    final 60-row gate (the 45 above plus every `ecma3/JSON/*` and the avm2 `json_*` rows) is 59 pass +
    `number_convert_errors` rm.
  - **All 54 `regression/avm2_*` pass.**
- **Static golden scan:** every numeric token in every avm2 / from_avmplus `output.txt` was re-formatted with the new
  NORMAL-mode formatter. Every token where golden ≠ new is a source literal (`-1234e+5`, `01e+2`, `5e-324` in
  "x / 5e-324 PASSED!"), a `toFixed` spelling, or a known flip. **No passing row prints a ToString number that the
  new formatter spells differently.**
- **No-graphics parity:** `int_toexponential`, `number_tostring` and `e15_7_4_6_1/swf14` pass in no-graphics too.
  No `#ifdef NO_GRAPHICS` code was touched.
- **Render canary:** every AVM2/from_avmplus/mixed_avm member of `render_canary_tests.txt` (36 rows), captured
  before and after. **All 36 match on PNG md5, trace status and image status.** AVM1 members were not run: AVM1
  code never reaches `avm2_value.c`/`avm2_number.c`/`avm2_json.c` (the AVM1 formatter is in `action.c`). No canary
  member added: no pixel path is involved beyond number text, and none of the changed spellings appears in a canary
  row.
- **Shared code:** `avm2_format_number` is the AVM2-wide ToString(Number), so every AVM2 caller is affected,
  including text/display callers in `avm2_display.c`/`avm2_text.c` (unchanged files). The static scan and the
  277-row sweep are the evidence that nothing passing moves.
- **Perf:** D2A replaces up to 18 `snprintf("%.*e")`+`strtod` probes per non-integer number. The integer fast path
  is kept, so this should be neutral or faster. Not measured in a browser.

## Refutations / premise checks

- The brief's premise "`number_tostring` Category 14 is a separate, permanent NO-GO" is **refuted**. The
  "corruption" is deterministic avmplus behaviour; the port reproduces it exactly.
- The w1b row note for `json_parse_numbers` ("DBL_MAX→Infinity, subnormal 17-digit spellings, 270-digit strtod") is
  partly mis-attributed. After the D2A port, the 4 residual lines are all on the READ side (`convertStringToDouble`),
  not the print side. Both sides are now ported for JSON.

## New unclaimed leads

- **L1: global `convertStringToDouble`.** `Number("…")`, `parseFloat` and implicit string→number still use the
  Ruffle-model `avm2_string_to_f64`, which is correctly rounded. Flash uses the same inexact reader as JSON. A
  global swap (S–M) would be Flash-exact, but it touches every string→number coercion. It needs its own gate over
  `parse_float*`, `ecma3/GlobalObject/*`, `ecma3/TypeConversion/*` and `e9_3_1_*`. No currently failing row is known
  to need it, so it is unpriced.
- **L2: `avm2/number_convert_errors` (bucket B)** is untouched: its 706 lines are stack frames, not digits.
- **L3: master regression `ecma3/JSON/AS3Types` from `558c5a8cf`** is fixed here. If this patch is not landed, that
  one-line `avm2_value_is_xmlish` exemption in `js_map_value` should land on its own.

## Not finished

Nothing in scope. Docs and dispositions are left for the coordinator, listed above.

## LOCAL ORACLE REQUESTS

None. Every row graded here already has an FP32 golden (trace-provenance table A).
