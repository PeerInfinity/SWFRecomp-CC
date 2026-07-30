# Ruffle Test Results Diff

**Previous:** `9277e0e1b214` (2026-07-30T07:00:20.398305+00:00)
**Current:** `c045e044c667` (2026-07-30T08:52:49.868130+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1459 | 1467 | +8 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 92.7% | 93.2% | +0.5% |
| Mismatched lines | 780 | 772 | -8 |
|   Decreased | | | -9 |
|   Increased | | | +1 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1075MathNotAFunction` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1076MathNotAConstructor` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/exception_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/exception_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/expression_005_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Expressions/e11_2_2_10_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Function/e15_3_4_3_1` | output_mismatch | 13/14 | 14/14 |
| `ecma3/Function/e15_3_4_4_1_rt` | output_mismatch | 9/10 | 10/10 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | output_mismatch | 3/3 | 2/3 |
