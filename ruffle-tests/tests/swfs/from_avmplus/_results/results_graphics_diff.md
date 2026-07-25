# Ruffle Test Results Diff

**Previous:** `b46ac6ee92f2` (2026-07-25T04:33:02.538012+00:00)
**Current:** `e4d1e78f665e` (2026-07-25T19:28:36.574035+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1384 | 1407 | +23 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 87.9% | 89.4% | +1.5% |
| Mismatched lines | 1937 | 1821 | -116 |
|   Decreased | | | -146 |
|   Increased | | | +30 |

## Newly Passing (23)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Array/insertremove` | output_mismatch | 30766/30870 | 30870/30870 |
| `as3/RuntimeErrors/Error1004MethodInvokedOnIncompatibleObj` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Array/e15_4_1` | output_mismatch | 11/14 | 14/14 |
| `ecma3/Array/e15_4_1_1` | output_mismatch | 2/7 | 7/7 |
| `ecma3/Array/e15_4_2_1_3` | output_mismatch | 1030/1031 | 1031/1031 |
| `ecma3/Array/e15_4_2_3` | output_mismatch | 4/5 | 5/5 |
| `ecma3/Array/e15_4_4` | output_mismatch | 2/4 | 4/4 |
| `ecma3/Boolean/e15_6_3_1` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Boolean/e15_6_3_1_3` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Boolean/e15_6_4` | output_mismatch | 1/2 | 2/2 |
| `ecma3/Boolean/e15_6_4__1` | output_mismatch | 3/4 | 4/4 |
| `ecma3/Date/e15_9_5` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/number_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/number_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/string_001_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Exceptions/string_002_rt` | output_mismatch | 0/1 | 1/1 |
| `ecma3/Expressions/e11_1_4` | output_mismatch | 25/28 | 28/28 |
| `ecma3/FunctionObjects/ecall_1` | output_mismatch | 1/3 | 3/3 |
| `ecma3/JSON/e15_12_1` | output_mismatch | 35/36 | 36/36 |
| `ecma3/NativeObjects/e15_2_rt` | output_mismatch | 3/9 | 9/9 |
| `ecma3/Number/e15_7_4_2_2_rt` | output_mismatch | 0/2 | 2/2 |
| `ecma3/ObjectObjects/e15_2_3_1_rt` | output_mismatch | 1/2 | 2/2 |
| `ecma3/ObjectObjects/e15_2_3_rt` | output_mismatch | 1/2 | 2/2 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ecma3/JSON/adhoc` | output_mismatch | ruffle_matched | 30/40 | 33/40 |
| `ecma3/Number/e15_7_4_2_4` | output_mismatch | ruffle_matched | 49/51 | 50/51 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `regress/bug_687838` | output_mismatch | 104/111 | 74/111 | +30 |
