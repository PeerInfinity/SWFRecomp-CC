# Ruffle Test Results Diff

**Previous:** `6744f84efd63` (2026-02-28T04:02:04.282299+00:00)
**Current:** `eb4a18cc7c07` (2026-02-28T05:09:42.682994+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 398 | 400 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 64.3% | 64.6% | +0.3% |
| Mismatched lines | 31380 | 31354 | -26 |
|   Decreased | | | -32 |
|   Increased | | | +6 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `create_empty_movie_clip` | output_mismatch | 3/3 | 3/3 |
| `movieclip_init_object` | output_mismatch | 1/5 | 5/5 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | output_mismatch | 127/231 | 142/231 | -15 |
| `register_class` | output_mismatch | 7/66 | 16/66 | -9 |
| `register_class_with_sound` | output_mismatch | 1/11 | 5/11 | -4 |
| `register_class_swf6` | output_mismatch | 7/37 | 1/37 | +6 |
