# Ruffle Test Results Diff

**Previous:** `4d467b25b6d6` (2026-03-07T02:01:55.866369+00:00)
**Current:** `1e2c9890659a` (2026-03-07T02:59:15.043296+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 492 | 487 | -5 |
| Total | 619 | 619 | 0 |
| Pass rate | 79.5% | 78.7% | -0.8% |
| Mismatched lines | 19742 | 19873 | +131 |
|   Decreased | | | -37 |
|   Increased | | | +168 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `default_names` | output_mismatch | 15/52 | 52/52 |

## Newly Failing (6)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clone_sprite_types` | output_mismatch | 24/24 | 15/24 |
| `named_shapes` | output_mismatch | 14/14 | 10/14 |
| `native_objects_swf7` | output_mismatch | 84/84 | 83/84 |
| `native_objects_swf8` | output_mismatch | 84/84 | 83/84 |
| `place_and_lookup` | output_mismatch | 30/30 | 6/30 |
| `string_paths_hidden` | output_mismatch | 54/54 | 36/54 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `native_objects_swf6` | output_mismatch | 83/84 | 82/84 | +1 |
| `register_and_init_order` | output_mismatch | 146/231 | 36/231 | +110 |
