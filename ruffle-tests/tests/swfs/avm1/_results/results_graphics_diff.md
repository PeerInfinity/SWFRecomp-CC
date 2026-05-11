# Ruffle Test Results Diff

**Previous:** `65b80680126b` (2026-05-11T18:15:21.425744+00:00)
**Current:** `3589c6bcc859` (2026-05-11T19:20:52.177332+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 589 | 592 | +3 |
| Total | 651 | 651 | 0 |
| Pass rate | 90.5% | 90.9% | +0.4% |
| Mismatched lines | 9141 | 9231 | +90 |
|   Decreased | | | -15 |
|   Increased | | | +105 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `click_block` | output_mismatch | 5/5 | 5/5 |
| `goto_frame2` | output_mismatch | 39/44 | 44/44 |
| `removed_clip_halts_script` | output_mismatch | 5/15 | 15/15 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `native_objects_swf6` | output_mismatch | segfault | 114/115 | 9/115 |
