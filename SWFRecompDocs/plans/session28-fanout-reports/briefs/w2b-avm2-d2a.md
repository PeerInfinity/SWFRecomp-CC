**Port avmplus number→string exactly (bucket J of w1b-rm-avm2) (M–L).**

Inputs: `w1b-rm-avm2-report.md` (on master; its P1–P14 prototype LANDED as `558c5a8cf`), bucket J and its per-row
table. Rows (all `ruffle_matched` with FP32 goldens, trace-provenance table A): `int_toexponential` (76 lines),
`uint_toexponential` (100), `from_avmplus/ecma3/Number/e15_7_4_6_1` swf14 (18) and swf15 (3), `eregress_121952` (1),
`number_to_string` (104, subnormal 17-digit spellings), `json_parse_numbers` (4), `toStringLimits` (1,
`(-MIN_VALUE).toString(2)` → `"0"`).

Task: port avmplus `MathUtils::convertDoubleToString` and its D2A (read the avmplus source: tamarin-redux
`core/MathUtils.cpp`, `core/d2a.cpp`/`BigInteger`; clone it in the cloud) into `avm2_number.c` / `avm2_format_number`
exactly: the 17-significant-digit cap with zero fill (`1000000000000000128.toFixed(0)` = `…100`), truncating
`toExponential` (`77.1234.toExponential(0)` = `7e+1`), radix output, and the SWF < 15 bug-513039 `toFixed` arm
(`(-0.05).toFixed(0)` = `"-1."`, `(0.00005).toFixed(2)` = `"0.01"`). Check the `number_tostring` Category-14
ACCEPTED_DIFFS entry first and say whether it is stale. Gate: every passing avm2 + from_avmplus row that prints numbers
(grep `toFixed|toExponential|toPrecision|toString(` in their ABC names or use the w1b's suite neighbours), both
JSON rows, the `regression/avm2_*` set. AVM2 runtime only (graphics mode suffices; say if you touch shared code).
