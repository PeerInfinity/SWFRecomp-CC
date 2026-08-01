# Ruffle Test Results Diff

**Previous:** `2ab0c01beab9` (2026-08-01T00:14:14.582798+00:00)
**Current:** `73c786e3fa45` (2026-08-01T02:48:45.569827+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1493 | 1501 | +8 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 94.9% | 95.4% | +0.5% |
| Mismatched lines | 655 | 637 | -18 |
|   Decreased | | | -18 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RuntimeErrors/Error1052InvalidUriPassed` | output_mismatch | 0/1 | 1/1 |
| `e4x/XML/e13_4_4_36` | output_mismatch | 13/16 | 16/16 |
| `ecma3/Exceptions/exception_011_rt` | output_mismatch | 1/3 | 3/3 |
| `ecma3/ObjectObjects/hasOwnProperty` | output_mismatch | 9/10 | 10/10 |
| `ecma3/Statements/e12_10` | output_mismatch | 0/1 | 1/1 |
| `ecma3/String/e15_5_3_2_3` | output_mismatch | 474/481 | 481/481 |
| `ecma3/String/e15_5_4_5_4` | output_mismatch | 321/323 | 323/323 |
| `ecma3/Unicode/utf8count` | output_mismatch | 2/3 | 3/3 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `as3/RegExp/replace` | ruffle_matched | 5/7 | 5/7 | 0 |
| `e4x/XML/bug_564468` | ruffle_matched | 3/10 | 3/10 | 0 |
| `ecma3/JSON/Classes` | ruffle_matched | 5/6 | 5/6 | 0 |
| `regress/bug_550958` | output_mismatch | 2/3 | 2/3 | 0 |
