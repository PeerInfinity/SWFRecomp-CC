# Ruffle Test Results Diff

**Previous:** `cdc61ecbd34e` (2026-04-28T04:21:17.220268+00:00)
**Current:** `431a14a0d250` (2026-04-28T17:26:50.518471+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 597 | 595 | -2 |
| Total | 641 | 641 | 0 |
| Pass rate | 93.1% | 92.8% | -0.3% |
| Mismatched lines | 8897 | 8905 | +8 |
|   Increased | | | +8 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `looping` | output_mismatch | 6/6 | 6/6 |
| `register_globals_across_frames` | output_mismatch | 15/15 | 15/15 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 23/758 | 15/758 | +8 |
