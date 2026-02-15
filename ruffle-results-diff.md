# Ruffle Test Results Diff

**Previous:** `06244c7b7de8` (2026-02-15T20:56:56.320180+00:00)
**Current:** `cd84b0f8a0a4` (2026-02-15T21:39:16.486333+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 200 | 203 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 32.3% | 32.8% | +0.5% |
| Mismatched lines | 46270 | 45863 | -407 |
|   Decreased | | | -407 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `matrix` | output_mismatch | 123/171 | 171/171 |
| `point` | output_mismatch | 124/175 | 175/175 |
| `rectangle` | output_mismatch | 516/745 | 745/745 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `arguments` | output_mismatch | 77/127 | 106/127 | -29 |
| `bitmap_data_pixeldissolve` | output_mismatch | 68/1075 | 96/1075 | -28 |
| `bitmap_data_hittest` | output_mismatch | 39/132 | 60/132 | -21 |
| `global_instance_decls` | output_mismatch | 1/758 | 2/758 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `native_objects_swf8` | output_mismatch | 0/84 | 0/84 | 0 |
