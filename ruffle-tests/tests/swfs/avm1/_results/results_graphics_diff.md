# Ruffle Test Results Diff

**Previous:** `fe491ef7b556` (2026-05-13T20:24:13.808970+00:00)
**Current:** `bf47589e067e` (2026-05-13T23:16:45.244694+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 600 | 605 | +5 |
| Total | 651 | 654 | +3 |
| Pass rate | 92.2% | 92.5% | +0.3% |
| Mismatched lines | 8953 | 9280 | +327 |
|   Increased | | | +105 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_children` | segfault | 8/8 | 8/8 |
| `button_order` | segfault | 2/2 | 2/2 |
| `button_v5` | segfault | 18/18 | 18/18 |
| `button_v6` | segfault | 18/18 | 18/18 |
| `nested_textfields_in_buttons` | segfault | - | 0/0 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | segfault | 114/115 | 9/115 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `array_reverse` | output_mismatch | 122/226 |
| `array_shift` | output_mismatch | 149/216 |
| `array_unshift` | output_mismatch | 95/146 |
