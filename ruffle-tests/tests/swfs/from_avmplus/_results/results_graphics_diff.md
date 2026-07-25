# Ruffle Test Results Diff

**Previous:** `da35e5d771bb` (2026-07-25T00:20:14.007100+00:00)
**Current:** `8e8370df1193` (2026-07-25T02:29:16.984933+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1299 | 1339 | +40 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 82.5% | 85.1% | +2.6% |
| Mismatched lines | 4012 | 2003 | -2009 |
|   Decreased | | | -2009 |

## Newly Passing (40)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Statements/Exceptions/MultipleCatchBlocksURI` | output_mismatch | 0/1 | 1/1 |
| `as3/Statements/Exceptions/TryCatchBlockUserWithBuiltInExceptions` | output_mismatch | 6/7 | 7/7 |
| `as3/Types/Number/abs` | output_mismatch | 0/41 | 41/41 |
| `as3/Types/Number/acos` | output_mismatch | 0/29 | 29/29 |
| `as3/Types/Number/asin` | output_mismatch | 0/34 | 34/34 |
| `as3/Types/Number/atan` | output_mismatch | 0/33 | 33/33 |
| `as3/Types/Number/atan2` | output_mismatch | 0/72 | 72/72 |
| `as3/Types/Number/ceil` | output_mismatch | 0/49 | 49/49 |
| `as3/Types/Number/e` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/exp` | output_mismatch | 0/30 | 30/30 |
| `as3/Types/Number/floor` | output_mismatch | 0/46 | 46/46 |
| `as3/Types/Number/ln10` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/ln2` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/log` | output_mismatch | 0/32 | 32/32 |
| `as3/Types/Number/log10e` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/log2e` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/max` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/min` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/pi` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/pow` | output_mismatch | 0/96 | 96/96 |
| `as3/Types/Number/random` | output_mismatch | 0/4 | 4/4 |
| `as3/Types/Number/round` | output_mismatch | 0/54 | 54/54 |
| `as3/Types/Number/sin` | output_mismatch | 0/28 | 28/28 |
| `as3/Types/Number/sqrt` | output_mismatch | 0/69 | 69/69 |
| `as3/Types/Number/sqrt1_2` | output_mismatch | 2/9 | 9/9 |
| `as3/Types/Number/sqrt2` | output_mismatch | 2/8 | 8/8 |
| `as3/Types/Number/tan` | output_mismatch | 0/28 | 28/28 |
| `as3/Types/Number/visibility/v16` | output_mismatch | 0/9 | 9/9 |
| `as3/Vector/nonindexproperty/v11` | output_mismatch | 0/55 | 55/55 |
| `ecma3/GlobalObject/decodeURI` | output_mismatch | 0/38 | 38/38 |
| `ecma3/GlobalObject/decodeURIComponent` | output_mismatch | 0/24 | 24/24 |
| `ecma3/GlobalObject/e15_1_2_4` | output_mismatch | 50/983 | 983/983 |
| `ecma3/GlobalObject/e15_1_2_5_1` | output_mismatch | 530/531 | 531/531 |
| `ecma3/GlobalObject/e15_1_3` | output_mismatch | 0/2 | 2/2 |
| `ecma3/GlobalObject/encodeURI` | output_mismatch | 0/39 | 39/39 |
| `ecma3/GlobalObject/encodeURIComponent` | output_mismatch | 0/23 | 23/23 |
| `regress/bug_538107` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_551587_2_swf10` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_551587_2_swf11` | output_mismatch | 0/2 | 2/2 |
| `regress/bug_609416_swf11` | output_mismatch | 0/1 | 1/1 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3/Types/Number/cos` | output_mismatch | ruffle_matched | 0/29 | 28/29 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3/Vector/nonindexproperty/v10` | output_mismatch | 0/51 | 44/51 | -44 |
| `as3/RuntimeErrors/Error1115NotAConstructor/v10` | output_mismatch | 0/3 | 0/3 | 0 |
| `regress/bug_609416_swf10` | ruffle_matched | 0/1 | 0/1 | 0 |
