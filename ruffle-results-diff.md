# Ruffle Test Results Diff

**Previous:** `c1f23adabbb1` (2026-02-24T23:34:38.258211+00:00)
**Current:** `2ba006e23e31` (2026-02-25T00:13:31.438905+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 345 | 345 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 55.7% | 55.7% | 0% |
| Mismatched lines | 33550 | 33256 | -294 |
|   Decreased | | | -309 |
|   Increased | | | +15 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `swf4_actions_coercion_order` | output_mismatch | 9/158 | 158/158 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clone_sprite_types` | output_mismatch | 24/24 | 19/24 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 266/338 | - |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `clone_sprite_edittext` | output_mismatch | 24/94 | 83/94 | -59 |
| `property_invalid_base_clip` | output_mismatch | 14/36 | 34/36 | -20 |
| `tell_target` | output_mismatch | 3/37 | 10/37 | -7 |
| `tell_target_invalid` | output_mismatch | 1/6 | 2/6 | -1 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 2/5 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `call` | output_mismatch | 5/63 | 4/63 | +1 |
| `path_string` | output_mismatch | 47/322 | 38/322 | +9 |
