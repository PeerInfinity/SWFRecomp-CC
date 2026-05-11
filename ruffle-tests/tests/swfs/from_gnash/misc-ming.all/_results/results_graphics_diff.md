# Ruffle Test Results Diff

**Previous:** `947b8351af9a` (2026-05-11T03:25:40.001190+00:00)
**Current:** `be795aae226b` (2026-05-11T03:59:41.873647+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 48 | 52 | +4 |
| Total | 102 | 102 | 0 |
| Pass rate | 47.1% | 51.0% | +3.9% |
| Mismatched lines | 1645 | 1614 | -31 |
|   Decreased | | | -31 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `DefineEditTextVariableNameTest` | segfault | - | 72/72 |
| `loop/loop_test8` | output_mismatch | 35/38 | 38/38 |
| `replace_shapes1test` | output_mismatch | 8/23 | 23/23 |
| `shape_test` | output_mismatch | 13/21 | 21/21 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `loading/loadMovieTest` | output_mismatch | 67/80 | 71/80 | -4 |
| `goto_frame_test` | output_mismatch | 6/15 | 7/15 | -1 |
