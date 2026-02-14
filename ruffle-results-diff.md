# Ruffle Test Results Diff

**Previous:** `2f9b09c8f013` (2026-02-14T02:03:41.668617+00:00)
**Current:** `57df325235b1` (2026-02-14T02:14:43.888351+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 153 | 155 | +2 |
| Total | 619 | 619 | 0 |
| Pass rate | 24.7% | 25.0% | +0.3% |
| Mismatched lines | 57202 | 56758 | -444 |
|   Decreased | | | -469 |
|   Increased | | | +25 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_max_size_swf10` | output_mismatch | 9/12 | 12/12 |
| `bitmap_data_max_size_swf9` | output_mismatch | 7/10 | 10/10 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_data_noise` | output_mismatch | 1/631 | 334/631 | -333 |
| `bitmap_data_threshold` | output_mismatch | 4/176 | 104/176 | -100 |
| `bitmap_data` | output_mismatch | 46/1126 | 68/1126 | -22 |
| `globals_swf8` | output_mismatch | 137/304 | 143/304 | -6 |
| `bitmap_data_hittest` | output_mismatch | 39/132 | 41/132 | -2 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf6` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf7` | output_mismatch | 0/84 | 0/84 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
| `globals_swf5` | output_mismatch | 207/304 | 200/304 | +7 |
| `globals_swf6` | output_mismatch | 214/304 | 205/304 | +9 |
| `globals_swf7` | output_mismatch | 211/304 | 202/304 | +9 |
