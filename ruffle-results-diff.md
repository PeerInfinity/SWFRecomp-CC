# Ruffle Test Results Diff

**Previous:** `5990fc78c71c` (2026-02-26T00:26:44.146501+00:00)
**Current:** `1c7ae0dee24f` (2026-02-26T01:33:13.313164+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 364 | 365 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 58.8% | 59.0% | +0.2% |
| Mismatched lines | 32879 | 32876 | -3 |
|   Decreased | | | -7 |
|   Increased | | | +4 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_constructor` | output_mismatch | 29/30 | 30/30 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | segfault | output_mismatch | - | 0/2 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tell_target` | output_mismatch | 4/37 | 10/37 | -6 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `path_string` | output_mismatch | 40/322 | 38/322 | +2 |
