# Ruffle Test Results Diff

**Previous:** `8f4f6e395305` (2026-11-25T03:59:19.198207+00:00)
**Current:** `10a5b515a03a` (2026-11-25T21:10:43.773614+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1533 | 1544 | +11 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 97.4% | 98.1% | +0.7% |
| Mismatched lines | 428 | 402 | -26 |
|   Decreased | | | -27 |
|   Increased | | | +1 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/RegExp/replace` | ruffle_matched | 5/7 | 7/7 |
| `as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | ruffle_matched | 0/1 | 1/1 |
| `e4x/XML/bug_564468` | ruffle_matched | 6/10 | 10/10 |
| `e4x/XML/e13_4_4_30` | ruffle_matched | 8/11 | 11/11 |
| `e4x/XML/misc_errors` | ruffle_matched | 32/33 | 33/33 |
| `e4x/XMLList/e13_5_4_18` | ruffle_matched | 3/5 | 5/5 |
| `ecma3/Date/e15_9_4_2_1` | ruffle_matched | 2/4 | 4/4 |
| `ecma3/JSON/Classes` | ruffle_matched | 5/6 | 6/6 |
| `ecma3/JSON/adhoc` | ruffle_matched | 35/40 | 40/40 |
| `misc/bug_508617` | ruffle_matched | 2/5 | 5/5 |
| `regress/bug_609416_swf10` | ruffle_matched | 0/1 | 1/1 |
| `regress/bug_638233` | ruffle_matched | 17/19 | 19/19 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `ecma3/JSON/AS3Types` | output_mismatch | 26/26 | 25/26 |
