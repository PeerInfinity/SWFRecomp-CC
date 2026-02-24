# Ruffle Test Results Diff

**Previous:** `36a69b839072` (2026-02-24T01:41:59.795018+00:00)
**Current:** `3df670af59c1` (2026-02-24T03:39:33.391395+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 320 | 324 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 51.7% | 52.3% | +0.6% |
| Mismatched lines | 34642 | 34586 | -56 |
|   Decreased | | | -56 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loadmovie` | output_mismatch | 1/2 | 2/2 |
| `loadmovie_method` | output_mismatch | 1/2 | 2/2 |
| `lock_root` | output_mismatch | 0/1 | 1/1 |
| `unloadmovie_method` | output_mismatch | 1/3 | 3/3 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_6` | output_mismatch | compile_fail | 1/10 | - |
| `movieclip_invalid_get_bounds_7` | output_mismatch | compile_fail | 1/10 | - |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loadmovie_registerclass` | output_mismatch | 0/30 | 9/30 | -9 |
| `swf6_to_5_cross_call` | output_mismatch | 0/29 | 7/29 | -7 |
| `register_class_swf6` | output_mismatch | 0/37 | 6/37 | -6 |
| `swf5_to_6_cross_call` | output_mismatch | 0/29 | 6/29 | -6 |
| `loadmovie_replace_root` | output_mismatch | 0/5 | 2/5 | -2 |
| `unloadmovie` | output_mismatch | 1/4 | 3/4 | -2 |
| `focusrect_property_swf5` | output_mismatch | 287/1237 | 288/1237 | -1 |
| `focusrect_property_swf6` | output_mismatch | 717/1237 | 717/1237 | 0 |
| `focusrect_property_swf7` | output_mismatch | 718/1237 | 718/1237 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `issue_2870` | output_mismatch | 2/3 | 2/3 | 0 |
