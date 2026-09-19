# Ruffle Test Results Diff

**Previous:** `317ac43cffd3` (2026-09-17T01:04:31.397110+00:00)
**Current:** `53a188c38f4e` (2026-09-19T12:56:43.095335+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1213 | 1217 | +4 |
| Total | 1275 | 1275 | 0 |
| Pass rate | 95.1% | 95.5% | +0.4% |
| Mismatched lines | 2889 | 2579 | -310 |
|   Decreased | | | -310 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_framescript_queued/swf10` | output_mismatch | 15/59 | 59/59 |
| `goto_framescript_queued/swf9` | output_mismatch | 11/52 | 52/52 |
| `goto_framescript_queued_same_frame` | output_mismatch | 3/4 | 4/4 |
| `tab_ordering_properties` | output_mismatch | 561/732 | 732/732 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `goto_framescript_queued/swf13` | output_mismatch | ruffle_matched | 17/59 | 56/59 |
| `number_to_string` | output_mismatch | ruffle_matched | 237/353 | 249/353 |
| `textblock_recreateline` | output_mismatch | ruffle_matched | 40/180 | 42/180 |
