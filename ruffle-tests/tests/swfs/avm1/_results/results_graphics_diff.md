# Ruffle Test Results Diff

**Previous:** `7bef032ea24d` (2026-05-13T00:24:25.771698+00:00)
**Current:** `fe491ef7b556` (2026-05-13T20:24:13.808970+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 605 | 600 | -5 |
| Total | 651 | 651 | 0 |
| Pass rate | 92.9% | 92.2% | -0.7% |
| Mismatched lines | 9058 | 8953 | -105 |
|   Decreased | | | -105 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `button_children` | segfault | 8/8 | 8/8 |
| `button_order` | segfault | 2/2 | 2/2 |
| `button_v5` | segfault | 18/18 | 18/18 |
| `button_v6` | segfault | 18/18 | 18/18 |
| `nested_textfields_in_buttons` | segfault | 0/0 | - |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | segfault | output_mismatch | 9/115 | 114/115 |
