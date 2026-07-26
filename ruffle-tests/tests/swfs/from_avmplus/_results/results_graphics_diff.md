# Ruffle Test Results Diff

**Previous:** `ffe48dff672e` (2026-07-26T02:00:51.628760+00:00)
**Current:** `1884c6ab93fe` (2026-07-26T03:36:27.380476+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1447 | 1457 | +10 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 91.9% | 92.6% | +0.7% |
| Mismatched lines | 1295 | 888 | -407 |
|   Decreased | | | -407 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/ByteArray/ByteArray` | output_mismatch | 424/425 | 425/425 |
| `as3/ByteArray/ByteArrayLzma` | output_mismatch | 7/397 | 397/397 |
| `as3/ByteArray/ByteArrayLzmaThirdParty` | output_mismatch | 0/2 | 2/2 |
| `as3/ByteArray/ByteArray_bug662851_32bit` | timeout | - | 4/4 |
| `as3/ByteArray/ByteArray_bug662851_64bit` | timeout | - | 2/2 |
| `recursion/pcre_could_be_empty_branch` | output_mismatch | 0/1 | 1/1 |
| `recursion/pcre_find_firstassertedchar` | output_mismatch | 1/2 | 2/2 |
| `recursion/pcre_is_anchored` | output_mismatch | 1/2 | 2/2 |
| `recursion/pcre_is_startline` | output_mismatch | 1/2 | 2/2 |
| `regress/bug_558863_swf11` | output_mismatch | 0/1 | 1/1 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `recursion/pcre_find_fixedlength` | output_mismatch | 10/20 | 19/20 | -9 |
