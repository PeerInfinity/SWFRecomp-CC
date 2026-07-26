# Ruffle Test Results Diff

**Previous:** `5da28a6a5bb0` (2026-07-25T23:58:08.706947+00:00)
**Current:** `ffe48dff672e` (2026-07-26T02:00:51.628760+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1439 | 1447 | +8 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 91.4% | 91.9% | +0.5% |
| Mismatched lines | 1531 | 1295 | -236 |
|   Decreased | | | -236 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Expressions/deleteOperator/deleteFixedFunction` | output_mismatch | 0/1 | 1/1 |
| `as3/Expressions/deleteOperator/deleteFixedVar` | output_mismatch | 0/1 | 1/1 |
| `as3/Expressions/deleteOperator/deleteNonexistentFixedProperty` | output_mismatch | 0/1 | 1/1 |
| `as3/ShellClasses/DictionarySubclass` | output_mismatch | 20/22 | 22/22 |
| `regress/bug_420755` | output_mismatch | 25/27 | 27/27 |
| `regress/bug_654807_swf12` | output_mismatch | 54/170 | 170/170 |
| `regress/bug_654807_swf13` | output_mismatch | 102/170 | 170/170 |
| `regress/bug_687838` | output_mismatch | 85/111 | 111/111 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `as3/Array/bug_535446` | output_mismatch | ruffle_matched | 2/10 | 6/10 |
| `as3/Array/length_mods` | output_mismatch | ruffle_matched | 0/20 | 15/20 |
