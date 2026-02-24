# Ruffle Test Results Diff

**Previous:** `35e5d7be5978` (2026-02-24T21:49:52.436808+00:00)
**Current:** `1e2621bf53e3` (2026-02-24T23:00:57.500221+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 342 | 346 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 55.3% | 55.9% | +0.6% |
| Mismatched lines | 33480 | 33363 | -117 |
|   Decreased | | | -119 |
|   Increased | | | +2 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `mutable_this` | output_mismatch | 12/18 | 18/18 |
| `swf5_no_closure` | output_mismatch | 8/19 | 19/19 |
| `swf6_string_as_bool` | output_mismatch | 0/15 | 15/15 |
| `this_swf5` | output_mismatch | 24/41 | 41/41 |
| `this_swf6` | output_mismatch | 18/41 | 41/41 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `textfield_props_swf5` | output_mismatch | 175/175 | 174/175 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_3` | runtime_error | output_mismatch | 2/13 | 2/13 |
| `movieclip_invalid_get_bounds_4` | runtime_error | output_mismatch | 2/13 | 2/13 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf5_global_funcs` | output_mismatch | 57/232 | 73/232 | -16 |
| `swf6_global_funcs` | output_mismatch | 60/232 | 76/232 | -16 |
| `focusrect_property_swf5` | output_mismatch | 288/1237 | 298/1237 | -10 |
| `function_base_clip_removed` | output_mismatch | 17/25 | 20/25 | -3 |
| `textsnapshot_props_swf5` | output_mismatch | 12/56 | 14/56 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 2/11 | 2/11 | 0 |
| `swf6_to_5_cross_call` | output_mismatch | 10/29 | 9/29 | +1 |
