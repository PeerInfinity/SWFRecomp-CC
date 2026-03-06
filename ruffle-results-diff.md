# Ruffle Test Results Diff

**Previous:** `36e2e955d8f5` (2026-03-06T17:05:14.034013+00:00)
**Current:** `378a0f9dd092` (2026-03-06T17:44:15.712416+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 480 | 480 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 77.5% | 77.5% | 0% |
| Mismatched lines | 20291 | 20196 | -95 |
|   Decreased | | | -100 |
|   Increased | | | +5 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `interface_implements_op` | output_mismatch | 0/47 | 47/47 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 69/69 | 68/69 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_hittest_shapeflag` | output_mismatch | compile_fail | 286/338 | - |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_library_state_values` | output_mismatch | 76/78 | 77/78 | -1 |
| `mcl_events_swf_version` | output_mismatch | 37/232 | 33/232 | +4 |
