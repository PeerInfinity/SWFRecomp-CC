# Ruffle Test Results Diff

**Previous:** `2bc6c9b9b0c8` (2026-07-27T18:48:15.203990+00:00)
**Current:** `3c0d4817f878` (2026-07-27T20:41:44.826409+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 866 | 871 | +5 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 70.9% | 71.3% | +0.4% |
| Mismatched lines | 45787 | 45698 | -89 |
|   Decreased | | | -89 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loader_error_in_root_ctor` | output_mismatch | 0/4 | 4/4 |
| `loader_loaderurl` | output_mismatch | 5/6 | 6/6 |
| `loader_noninteractive_try_click_root` | output_mismatch | 4/5 | 5/5 |
| `mouse_children` | output_mismatch | 114/192 | 192/192 |
| `sandbox_type_inherited` | output_mismatch | 1/2 | 2/2 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mouse_wheel_events` | output_mismatch | 29/36 | 33/36 | -4 |
| `font_registerfont` | output_mismatch | 8/129 | 8/129 | 0 |
| `loader_try_click_root` | output_mismatch | 0/16 | 0/16 | 0 |
