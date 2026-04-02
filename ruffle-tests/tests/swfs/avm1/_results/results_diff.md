# Ruffle Test Results Diff

**Previous:** `33b4d52d1573` (2026-04-02T01:29:20.503968+00:00)
**Current:** `14cdc0f864df` (2026-04-02T02:48:10.534690+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 561 | 569 | +8 |
| Total | 620 | 620 | 0 |
| Pass rate | 90.5% | 91.8% | +1.3% |
| Mismatched lines | 13081 | 10354 | -2727 |
|   Decreased | | | -2940 |
|   Increased | | | +213 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_broadcaster_initialize` | output_mismatch | 9/10 | 10/10 |
| `bitmap_data` | output_mismatch | 83/1126 | 1126/1126 |
| `bitmap_data_compare` | output_mismatch | 31/40 | 40/40 |
| `bitmap_data_copypixels` | output_mismatch | 2/17 | 17/17 |
| `bitmap_data_noise` | output_mismatch | 1/631 | 631/631 |
| `bitmap_data_pixeldissolve` | output_mismatch | 5/1075 | 1075/1075 |
| `bitmap_data_threshold` | output_mismatch | 8/176 | 176/176 |
| `native_subclasses` | output_mismatch | 189/191 | 191/191 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_filters` | output_mismatch | 542/548 | 544/548 | -2 |
| `global_proto_decls_delete` | output_mismatch | 296/4158 | 289/4158 | +7 |
| `global_proto_decls` | output_mismatch | 836/4497 | 630/4497 | +206 |
