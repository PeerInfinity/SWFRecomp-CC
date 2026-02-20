# Ruffle Test Results Diff

**Previous:** `6a95bcac32c7` (2026-02-20T02:09:54.909330+00:00)
**Current:** `7d128ba10acf` (2026-02-20T02:35:19.470359+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 226 | 226 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.5% | 36.5% | 0% |
| Mismatched lines | 39737 | 39605 | -132 |
|   Decreased | | | -144 |
|   Increased | | | +12 |

## Status Changed (6)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_events` | runtime_error | output_mismatch | 1/19 | 1/19 |
| `default_names` | runtime_error | output_mismatch | 12/52 | 16/52 |
| `function_base_clip_readded` | runtime_error | output_mismatch | - | 0/11 |
| `movieclip_depth_methods` | runtime_error | output_mismatch | 90/98 | 93/98 |
| `movieclip_hittest_shapeflag` | runtime_error | output_mismatch | 61/338 | 180/338 |
| `placeobject_occupied_depth` | runtime_error | output_mismatch | 1/6 | 1/6 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `duplicate_movie_clip` | output_mismatch | 1/20 | 19/20 | -18 |
| `issue_2870` | output_mismatch | 2/3 | 2/3 | 0 |
| `bad_placeobject_clipaction` | output_mismatch | 1/2 | 0/2 | +1 |
