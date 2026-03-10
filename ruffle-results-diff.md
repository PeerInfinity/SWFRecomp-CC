# Ruffle Test Results Diff

**Previous:** `dbaf2a7d83b8` (2026-03-10T02:42:35.699379+00:00)
**Current:** `d0ddd456ce24` (2026-03-10T03:48:11.891189+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 504 | 502 | -2 |
| Total | 618 | 618 | 0 |
| Pass rate | 81.6% | 81.2% | -0.4% |
| Mismatched lines | 19419 | 19334 | -85 |
|   Decreased | | | -155 |
|   Increased | | | +70 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `function_base_clip_removed` | output_mismatch | 25/25 | 7/25 |
| `funky_function_calls` | output_mismatch | 56/56 | 4/56 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_1` | runtime_error | output_mismatch | 5/75 | 46/75 |
| `movieclip_invalid_get_bounds_2` | runtime_error | output_mismatch | 7/75 | 69/75 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_class` | output_mismatch | 48/66 | 64/66 | -16 |
| `movieclip_invalid_get_bounds_3` | output_mismatch | 2/13 | 10/13 | -8 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | 2/13 | 10/13 | -8 |
| `register_class_swf6` | output_mismatch | 3/37 | 11/37 | -8 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 2/11 | 8/11 | -6 |
| `loadmovie_registerclass` | output_mismatch | 21/30 | 24/30 | -3 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | 4/11 | 7/11 | -3 |
