# Ruffle Test Results Diff

**Previous:** `254145a5b617` (2026-09-11T21:45:09.797368+00:00)
**Current:** `f48c532bf170` (2026-09-12T00:02:29.983572+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1200 | 1205 | +5 |
| Total | 1272 | 1274 | +2 |
| Pass rate | 94.3% | 94.6% | +0.3% |
| Mismatched lines | 4189 | 4044 | -145 |
|   Decreased | | | -267 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_filter_abstract` | output_mismatch | 0/6 | 6/6 |
| `bytearray_bad_symbol_class` | output_mismatch | 1/3 | 3/3 |
| `bytearray_bad_symbol_class_other_movie` | output_mismatch | 4/6 | 6/6 |
| `json_parse_errors` | output_mismatch | 4/84 | 84/84 |
| `matrix3d_append_rotation` | ruffle_matched | 22/23 | 23/23 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `json_parse_numbers` | output_mismatch | ruffle_matched | 31/131 | 127/131 |
| `loader_events_2` | output_mismatch | ruffle_matched | 2/35 | 5/35 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `goto_framescript_queued/swf10` | output_mismatch | 15/59 |
| `goto_framescript_queued/swf13` | ruffle_matched | 17/59 |
| `goto_framescript_queued/swf9` | output_mismatch | 11/52 |

## Removed Tests (1)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `goto_framescript_queued` | ruffle_matched | 1/6 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `matrix3d_recompose_edge_cases` | ruffle_matched | 113/198 | 190/198 | -77 |
