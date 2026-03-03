# Ruffle Test Results Diff

**Previous:** `d13982ddd567` (2026-03-03T03:27:12.388892+00:00)
**Current:** `6877ca0e4c33` (2026-03-03T04:25:27.752350+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 434 | 434 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 70.1% | 70.1% | 0% |
| Mismatched lines | 23318 | 23318 | 0 |
|   Decreased | | | -4 |
|   Increased | | | +4 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `function_base_clip_removed` | output_mismatch | 22/25 | 25/25 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `attach_movie` | output_mismatch | 59/59 | 56/59 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `function_base_clip_readded` | output_mismatch | 9/11 | 10/11 | -1 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `removed_target_clip_scope` | output_mismatch | 24/35 | 23/35 | +1 |
