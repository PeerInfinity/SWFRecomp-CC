# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.752845+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:42.013976+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 7 | 0 | -7 |
| Total | 7 | 8 | +1 |
| Pass rate | 100.0% | 0.0% | -100.0% |
| Mismatched lines | 0 | 0 | 0 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `request_matching_profiles` | compile_fail | 190/190 | - |
| `request_profiles` | compile_fail | 16/16 | - |
| `sampler_odd_size` | compile_fail | 1/1 | - |
| `scissor_rectangle` | compile_fail | 0/0 | - |
| `scissor_rectangle_invalid` | compile_fail | 1/1 | - |
| `unbound_texture` | compile_fail | 0/0 | - |
| `unbound_texture_multiple` | compile_fail | 0/0 | - |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `draw_to_bitmap_data_unconfigured` | compile_fail | - |
