# Ruffle Test Results Diff

**Previous:** `1c7ae0dee24f` (2026-02-26T01:33:13.313164+00:00)
**Current:** `e82d47c31c23` (2026-02-26T02:16:53.621196+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 365 | 366 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 59.0% | 59.1% | +0.1% |
| Mismatched lines | 32876 | 32843 | -33 |
|   Decreased | | | -33 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_frame2` | output_mismatch | 13/44 | 44/44 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `resolve_different_root` | output_mismatch | segfault | 0/2 | - |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
