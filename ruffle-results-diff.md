# Ruffle Test Results Diff

**Previous:** `f0cb91cadc1d` (2026-02-23T04:32:54.043105+00:00)
**Current:** `feedc1a8893e` (2026-02-23T05:22:04.188666+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 310 | 313 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 50.1% | 50.6% | +0.5% |
| Mismatched lines | 35018 | 35013 | -5 |
|   Decreased | | | -6 |
|   Increased | | | +1 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `attach_movie` | output_mismatch | 57/59 | 59/59 |
| `attach_movie_stop` | output_mismatch | 1/3 | 3/3 |
| `empty_movieclip_can_attach_movies` | output_mismatch | 10/11 | 11/11 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_clip_halts_script` | output_mismatch | 1/15 | 2/15 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `focus_remove` | output_mismatch | 7/33 | 6/33 | +1 |
