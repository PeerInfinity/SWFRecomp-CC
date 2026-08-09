# Ruffle Test Results Diff

**Previous:** `b4c983ea4c3d` (2026-08-02T09:26:35.644742+00:00)
**Current:** `0a99be1a92de` (2026-08-09T08:51:22.919632+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1510 | 1514 | +4 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 95.9% | 96.2% | +0.3% |
| Mismatched lines | 605 | 581 | -24 |
|   Decreased | | | -24 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/String/localeCompare_585791/v9` | output_mismatch | 2/8 | 8/8 |
| `ecma3/Expressions/e11_6_1_3` | output_mismatch | 3/9 | 9/9 |
| `ecma3/String/e15_5_4_8_2` | output_mismatch | 54/60 | 60/60 |
| `regress/bug_550958` | output_mismatch | 2/3 | 3/3 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `regress/bug_539328` | output_mismatch | ruffle_matched | 7/15 | 12/15 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `e4x/XML/bug_564468` | ruffle_matched | 3/10 | 3/10 | 0 |
