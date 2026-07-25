# Ruffle Test Results Diff

**Previous:** `2b244c01b173` (2026-07-25T21:37:09.731727+00:00)
**Current:** `7ad4e0419427` (2026-07-25T22:42:41.043507+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1421 | 1426 | +5 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 90.3% | 90.6% | +0.3% |
| Mismatched lines | 1885 | 1868 | -17 |
|   Decreased | | | -17 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1112ArgCountMismatchOnClassCoercion` | output_mismatch | 0/2 | 2/2 |
| `ecma3/JSON/e15_12_0` | output_mismatch | 2/4 | 4/4 |
| `ecma3/JSON/e15_12_2` | output_mismatch | 11/12 | 12/12 |
| `ecma3/JSON/e15_12_3` | output_mismatch | 31/33 | 33/33 |
| `ecma3/JSON/regress` | output_mismatch | 3/5 | 5/5 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `regress/bug_420755` | output_mismatch | 17/27 | 25/27 | -8 |
| `ecma3/Exceptions/exception_001_rt` | output_mismatch | 0/1 | 0/1 | 0 |
