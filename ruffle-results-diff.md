# Ruffle Test Results Diff

**Previous:** `a3e1445501c0` (2026-02-24T05:30:27.958886+00:00)
**Current:** `95c991d0e5c1` (2026-02-24T06:32:55.245493+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 330 | 333 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 53.3% | 53.8% | +0.5% |
| Mismatched lines | 34379 | 33814 | -565 |
|   Decreased | | | -565 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loadmovie_fail` | output_mismatch | 1/2 | 2/2 |
| `loadmovienum` | output_mismatch | 1/3 | 3/3 |
| `unloadmovienum` | output_mismatch | 6/13 | 13/13 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_1` | output_mismatch | runtime_error | 2/75 | 2/75 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | runtime_error | 2/75 | 2/75 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_swf5_6_7_8_9` | output_mismatch | 5/1145 | 553/1145 | -548 |
| `global_swf6_7_8` | output_mismatch | 0/15 | 4/15 | -4 |
| `cross_movie_root` | output_mismatch | 0/10 | 3/10 | -3 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 2/11 | 2/11 | 0 |
