# Ruffle Test Results Diff

**Previous:** `c146dc66ef9a` (2026-07-31T05:17:46.016988+00:00)
**Current:** `a28b3e2cbb40` (2026-07-31T14:52:54.940098+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1472 | 1481 | +9 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 93.5% | 94.1% | +0.6% |
| Mismatched lines | 761 | 726 | -35 |
|   Decreased | | | -35 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | output_mismatch | 0/1 | 1/1 |
| `as3/RuntimeErrors/Error1117InvalidXmlName` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | output_mismatch | 0/2 | 2/2 |
| `as3/RuntimeErrors/Error1120CannotDeleteProperty` | output_mismatch | 0/1 | 1/1 |
| `e4x/Expressions/e11_3_1` | output_mismatch | 10/20 | 20/20 |
| `e4x/Global/isXMLNameTypeErr` | output_mismatch | 0/5 | 5/5 |
| `ecma3/ObjectObjects/isPrototypeOf` | output_mismatch | 6/8 | 8/8 |
| `ecma3/String/e15_5_5_1` | output_mismatch | 7/10 | 10/10 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `e4x/Global/e13_1_2_1` | output_mismatch | 0/10 | 7/10 | -7 |
