# Ruffle Test Results Diff

**Previous:** `72fdc5e933a6` (2026-07-29T03:45:41.141164+00:00)
**Current:** `b4c983ea4c3d` (2026-08-02T09:26:35.702647+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 136 | 138 | +2 |
| Total | 143 | 143 | 0 |
| Pass rate | 95.1% | 96.5% | +1.4% |
| Mismatched lines | 112 | 98 | -14 |
|   Decreased | | | -14 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `avm2_button_scroll_rect` | output_mismatch | 0/2 | 2/2 |
| `filters/avm1_convolution_initialization` | output_mismatch | 17/18 | 18/18 |
| `simple_shapes/heavy_tesselation` | recomp_fail | - | 0/0 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `definefont4` | output_mismatch | 0/0 | 0/0 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `define_bits_jpeg2_huge` | output_mismatch | 2/19 | 13/19 | -11 |
