# Ruffle Test Results Diff

**Previous:** `034db2a0f605` (2026-02-23T02:38:02.525888+00:00)
**Current:** `66568c15e2bd` (2026-02-23T03:03:16.907536+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 307 | 308 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 49.6% | 49.8% | +0.2% |
| Mismatched lines | 35263 | 35159 | -104 |
|   Decreased | | | -104 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `edittext_width_height` | output_mismatch | 83/103 | 103/103 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_align_trailing_spaces_swf7` | output_mismatch | 228/576 | 264/576 | -36 |
| `edittext_align_trailing_spaces_swf8` | output_mismatch | 252/576 | 288/576 | -36 |
| `clone_sprite_edittext_dynamic` | output_mismatch | 45/86 | 50/86 | -5 |
| `edittext_autosize` | output_mismatch | 41/71 | 44/71 | -3 |
| `frame_size_translated_negative` | output_mismatch | 18/21 | 20/21 | -2 |
| `frame_size_translated_positive` | output_mismatch | 18/21 | 20/21 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
