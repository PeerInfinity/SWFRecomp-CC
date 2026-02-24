# Ruffle Test Results Diff

**Previous:** `95c991d0e5c1` (2026-02-24T06:32:55.245493+00:00)
**Current:** `ab2567073826` (2026-02-24T20:16:24.476913+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 333 | 340 | +7 |
| Total | 619 | 619 | 0 |
| Pass rate | 53.8% | 54.9% | +1.1% |
| Mismatched lines | 33814 | 33538 | -276 |
|   Decreased | | | -284 |
|   Increased | | | +8 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loadmovie_flashvars` | output_mismatch | 1/4 | 4/4 |
| `mcl_mislabeled_target` | output_mismatch | 3/6 | 6/6 |
| `mcl_target_gif87a` | output_mismatch | 3/6 | 6/6 |
| `mcl_target_gif89a` | output_mismatch | 3/6 | 6/6 |
| `mcl_target_jpg` | output_mismatch | 3/6 | 6/6 |
| `mcl_target_png` | output_mismatch | 3/6 | 6/6 |
| `moviecliploader_flashvars` | output_mismatch | 1/4 | 4/4 |
| `stage_object_properties_swf6` | output_mismatch | 229/231 | 231/231 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 69/69 | 66/69 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_1` | runtime_error | output_mismatch | 2/75 | 2/75 |
| `movieclip_invalid_get_bounds_2` | runtime_error | output_mismatch | 2/75 | 3/75 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_swf5_6_7_8_9` | output_mismatch | 553/1145 | 798/1145 | -245 |
| `global_swf6_7_8` | output_mismatch | 4/15 | 11/15 | -7 |
| `swf6_to_5_cross_call` | output_mismatch | 7/29 | 10/29 | -3 |
| `movieclip_library_state_values` | output_mismatch | 68/78 | 70/78 | -2 |
| `swf5_to_6_cross_call` | output_mismatch | 6/29 | 8/29 | -2 |
| `movieclip_gettextsnapshot` | output_mismatch | 6/112 | 7/112 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `movieclip_invalid_get_bounds_3` | runtime_error | 2/13 | 2/13 | 0 |
| `movieclip_invalid_get_bounds_4` | runtime_error | 2/13 | 2/13 | 0 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 2/11 | 2/11 | 0 |
| `movieclip_methods_with_loaded_image` | output_mismatch | 0/4 | 0/4 | 0 |
| `instanceof_coercions` | output_mismatch | 13/88 | 12/88 | +1 |
| `mcl_events_swf_version` | output_mismatch | 16/232 | 12/232 | +4 |
