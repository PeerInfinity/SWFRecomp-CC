# Ruffle Test Results Diff

**Previous:** `f246282a73c1` (2026-03-19T20:52:22.894795+00:00)
**Current:** `ed111aed62c7` (2026-03-19T21:20:27.385693+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 3 | 8 | +5 |
| Total | 14 | 14 | 0 |
| Pass rate | 21.4% | 57.1% | +35.7% |
| Mismatched lines | 5 | 11 | +6 |
|   Increased | | | +6 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `afunc_dict` | compile_fail | - | 2/2 |
| `dict_callframe` | compile_fail | - | 3/3 |
| `dict_cross` | compile_fail | - | 3/3 |
| `dict_override` | compile_fail | - | 2/2 |
| `func_dict` | compile_fail | - | 3/3 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `dict_event` | compile_fail | output_mismatch | - | 3/5 |
| `tags_after_last_showframe` | compile_fail | output_mismatch | - | 0/1 |
| `zeroframe_definesprite` | compile_fail | output_mismatch | - | 0/3 |
