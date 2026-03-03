# Ruffle Test Results Diff

**Previous:** `6877ca0e4c33` (2026-03-03T04:25:27.752350+00:00)
**Current:** `33e19e866ba6` (2026-03-03T05:37:38.645166+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 434 | 434 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 70.1% | 70.1% | 0% |
| Mismatched lines | 23318 | 23304 | -14 |
|   Decreased | | | -16 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `string_paths_other` | output_mismatch | 30/36 | 36/36 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `target_clip_removed` | output_mismatch | 5/5 | 4/5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `function_base_clip` | output_mismatch | segfault | 1/8 | 7/8 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_lockroot` | output_mismatch | 16/29 | 19/29 | -3 |
| `call` | output_mismatch | 4/63 | 5/63 | -1 |
| `custom_clip_methods` | output_mismatch | 0/4 | 0/4 | 0 |
| `movieclip_invalid_get_bounds_5` | output_mismatch | 2/11 | 2/11 | 0 |
| `removed_clip_halts_script` | output_mismatch | 1/15 | 1/15 | 0 |
| `movieclip_gettextsnapshot` | output_mismatch | 7/112 | 6/112 | +1 |
