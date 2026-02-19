# Ruffle Test Results Diff

**Previous:** `64db84cffa42` (2026-02-18T23:38:13.406288+00:00)
**Current:** `724bae7f65e8` (2026-02-19T03:02:39.305825+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 236 | 237 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 38.1% | 38.3% | +0.2% |
| Mismatched lines | 40065 | 39984 | -81 |
|   Decreased | | | -85 |
|   Increased | | | +4 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `color` | output_mismatch | 35/57 | 57/57 |
| `color_transform` | output_mismatch | 7/48 | 48/48 |
| `transform` | output_mismatch | 50/70 | 70/70 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `movieclip_default_state` | output_mismatch | 69/69 | 68/69 |
| `textfield_variable` | output_mismatch | 81/81 | 78/81 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `extends_native_type` | output_mismatch | 8/11 | 10/11 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
