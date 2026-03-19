# Ruffle Test Results Diff

**Previous:** `ef1e80b3a44d` (2026-03-18T04:04:37.084786+00:00)
**Current:** `ea87da0d59ad` (2026-03-19T01:34:53.079850+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 4 | 8 | +4 |
| Total | 14 | 14 | 0 |
| Pass rate | 28.6% | 57.1% | +28.5% |
| Mismatched lines | 9 | 8 | -1 |
|   Decreased | | | -4 |
|   Increased | | | +3 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `afunc_dict` | output_mismatch | 1/2 | 2/2 |
| `dict_cross` | compile_fail | - | 3/3 |
| `dict_override` | output_mismatch | 1/2 | 2/2 |
| `func_dict` | output_mismatch | 1/3 | 3/3 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `dict_event` | compile_fail | output_mismatch | - | 3/5 |
| `jump_to_prev_block` | compile_fail | output_mismatch | - | 0/1 |
