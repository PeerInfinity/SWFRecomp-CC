# Ruffle Test Results Diff

**Previous:** `04f4d9cbe00e` (2026-02-24T04:41:14.127238+00:00)
**Current:** `a3e1445501c0` (2026-02-24T05:30:27.958886+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 325 | 330 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 52.5% | 53.3% | +0.8% |
| Mismatched lines | 34603 | 34379 | -224 |
|   Decreased | | | -224 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `mcl_as_broadcaster` | output_mismatch | 5/12 | 12/12 |
| `mcl_getprogress` | output_mismatch | 0/30 | 30/30 |
| `mcl_loadclip` | output_mismatch | 25/149 | 149/149 |
| `mcl_loadclip_properties` | output_mismatch | 0/6 | 6/6 |
| `mcl_unloadclip` | output_mismatch | 0/5 | 5/5 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_3` | output_mismatch | runtime_error | 1/13 | 2/13 |
| `movieclip_invalid_get_bounds_4` | output_mismatch | runtime_error | 1/13 | 2/13 |
| `movieclip_invalid_get_bounds_6` | output_mismatch | runtime_error | 1/10 | 1/10 |
| `movieclip_invalid_get_bounds_7` | output_mismatch | runtime_error | 1/10 | 1/10 |

## Line Count Changed (18)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mcl_events_swf_version` | output_mismatch | 0/232 | 16/232 | -16 |
| `global_swf5_6_7_8_9` | output_mismatch | 0/1145 | 5/1145 | -5 |
| `global_proto_decls` | output_mismatch | 13/4497 | 16/4497 | -3 |
| `mcl_mislabeled_target` | output_mismatch | 0/6 | 3/6 | -3 |
| `mcl_target_gif87a` | output_mismatch | 0/6 | 3/6 | -3 |
| `mcl_target_gif89a` | output_mismatch | 0/6 | 3/6 | -3 |
| `mcl_target_jpg` | output_mismatch | 0/6 | 3/6 | -3 |
| `mcl_target_png` | output_mismatch | 0/6 | 3/6 | -3 |
| `movieclip_invalid_get_bounds_8` | output_mismatch | 1/11 | 4/11 | -3 |
| `register_class` | output_mismatch | 3/66 | 5/66 | -2 |
| `interface_implements_op` | output_mismatch | 0/47 | 1/47 | -1 |
| `loadmovie_var_persistence` | output_mismatch | 1/8 | 2/8 | -1 |
| `movieclip_invalid_get_bounds_1` | output_mismatch | 1/75 | 2/75 | -1 |
| `movieclip_invalid_get_bounds_2` | output_mismatch | 1/75 | 2/75 | -1 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 1/11 | 2/11 | -1 |
| `string_paths_eval2` | output_mismatch | 1/7 | 2/7 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `loadmovie_fail` | output_mismatch | 1/2 | 1/2 | 0 |
