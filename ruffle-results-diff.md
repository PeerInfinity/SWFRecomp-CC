# Ruffle Test Results Diff

**Previous:** `2a0809e5f3dc` (2026-02-23T00:43:47.222999+00:00)
**Current:** `034db2a0f605` (2026-02-23T02:38:02.525888+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 307 | 307 | 0 |
| Total | 619 | 619 | 0 |
| Pass rate | 49.6% | 49.6% | 0% |
| Mismatched lines | 35189 | 35263 | +74 |
|   Decreased | | | -30 |
|   Increased | | | +104 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `stage_object_properties` | output_mismatch | 226/241 | 241/241 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_width_height` | output_mismatch | 103/103 | 83/103 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties_swf6` | output_mismatch | 214/231 | 229/231 | -15 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `frame_size_translated_negative` | output_mismatch | 20/21 | 18/21 | +2 |
| `frame_size_translated_positive` | output_mismatch | 20/21 | 18/21 | +2 |
| `edittext_autosize` | output_mismatch | 44/71 | 41/71 | +3 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 50/86 | 45/86 | +5 |
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 264/576 | 228/576 | +36 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 288/576 | 252/576 | +36 |
