# Ruffle Test Results Diff

**Previous:** `518e30146ed4` (2026-02-27T00:48:09.669038+00:00)
**Current:** `fc96eb5ca495` (2026-02-27T01:40:24.575105+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 385 | 384 | -1 |
| Total | 619 | 619 | 0 |
| Pass rate | 62.2% | 62.0% | -0.2% |
| Mismatched lines | 31555 | 31662 | +107 |
|   Decreased | | | -29 |
|   Increased | | | +136 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `named_shapes` | output_mismatch | 12/14 | 14/14 |
| `string_paths_hidden` | output_mismatch | 35/54 | 54/54 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_antialiastype` | output_mismatch | 296/296 | 274/296 |
| `edittext_password` | output_mismatch | 5/5 | 3/5 |
| `tab_ordering_children` | output_mismatch | 208/208 | 181/208 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 266/338 |
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `place_and_lookup` | output_mismatch | 10/30 | 18/30 | -8 |
| `tab_ordering_tabbable` | output_mismatch | 36/47 | 33/47 | +3 |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | 63/462 | 55/462 | +8 |
