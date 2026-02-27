# Ruffle Test Results Diff

**Previous:** `a4be5eedce2d` (2026-02-27T01:51:02.812440+00:00)
**Current:** `4c464530ce68` (2026-02-27T03:31:32.732113+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 386 | 388 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 62.4% | 62.7% | +0.3% |
| Mismatched lines | 31564 | 31577 | +13 |
|   Decreased | | | -68 |
|   Increased | | | +81 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `place_and_lookup` | output_mismatch | 18/30 | 30/30 |
| `tab_ordering_children` | output_mismatch | 181/208 | 208/208 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | compile_fail | output_mismatch | - | 266/338 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `selection` | output_mismatch | 434/454 | 452/454 | -18 |
| `tab_ordering_movieclip_enabled_default` | output_mismatch | 55/462 | 63/462 | -8 |
| `tab_ordering_tabbable` | output_mismatch | 33/47 | 36/47 | -3 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `global_proto_decls` | output_mismatch | 20/4497 | 11/4497 | +9 |
