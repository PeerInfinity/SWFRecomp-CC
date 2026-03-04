# Ruffle Test Results Diff

**Previous:** `6226e655792e` (2026-03-04T02:56:52.372190+00:00)
**Current:** `8f807f41b78e` (2026-03-04T05:14:25.035074+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 444 | 441 | -3 |
| Total | 619 | 619 | 0 |
| Pass rate | 71.7% | 71.2% | -0.5% |
| Mismatched lines | 22376 | 22383 | +7 |
|   Decreased | | | -1 |
|   Increased | | | +8 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `issue_1104` | output_mismatch | 1/2 | 2/2 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `bad_placeobject_clipaction` | output_mismatch | 2/2 | 1/2 |
| `button_order` | output_mismatch | 2/2 | 0/2 |
| `create_empty_movie_clip` | output_mismatch | 3/3 | 2/3 |
| `movieclip_in_removed_button` | output_mismatch | 4/4 | 1/4 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loadmovienum_cross_version_prototype` | output_mismatch | 6/9 | 6/9 | 0 |
| `issue_2870` | output_mismatch | 2/3 | 1/3 | +1 |
