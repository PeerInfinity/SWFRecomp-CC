# Graphics vs Trace Mode Differences

Trace: 1457/1574 passing | Graphics: 1447/1574 passing

## Graphics Regressions (10 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `as3/ByteArray/ByteArray` | Output Mismatch | 424/425 lines match |
| 2 | `as3/ByteArray/ByteArrayLzma` | Output Mismatch | 7/397 lines match |
| 3 | `as3/ByteArray/ByteArrayLzmaThirdParty` | Output Mismatch | 0/2 lines match |
| 4 | `as3/ByteArray/ByteArray_bug662851_32bit` | Timeout | runtime timeout (>10s) |
| 5 | `as3/ByteArray/ByteArray_bug662851_64bit` | Timeout | runtime timeout (>10s) |
| 6 | `recursion/pcre_could_be_empty_branch` | Output Mismatch | 0/1 lines match |
| 7 | `recursion/pcre_find_firstassertedchar` | Output Mismatch | 1/2 lines match |
| 8 | `recursion/pcre_is_anchored` | Output Mismatch | 1/2 lines match |
| 9 | `recursion/pcre_is_startline` | Output Mismatch | 1/2 lines match |
| 10 | `regress/bug_558863_swf11` | Output Mismatch | 0/1 lines match |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
