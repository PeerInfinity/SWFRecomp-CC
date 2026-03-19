# Ruffle Test Results Diff

**Previous:** `182a3864f7fe` (2026-03-19T03:48:19.639473+00:00)
**Current:** `f246282a73c1` (2026-03-19T20:52:22.894795+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 8 | 3 | -5 |
| Total | 14 | 14 | 0 |
| Pass rate | 57.1% | 21.4% | -35.7% |
| Mismatched lines | 9 | 5 | -4 |
|   Decreased | | | -6 |
|   Increased | | | +2 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `afunc_dict` | compile_fail | 2/2 | - |
| `dict_callframe` | compile_fail | 3/3 | - |
| `dict_cross` | compile_fail | 3/3 | - |
| `dict_override` | compile_fail | 2/2 | - |
| `func_dict` | compile_fail | 3/3 | - |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `dict_event` | output_mismatch | compile_fail | 3/5 | - |
| `jump_after_end` | compile_fail | output_mismatch | - | 1/3 |
| `tags_after_last_showframe` | output_mismatch | compile_fail | 0/1 | - |
| `zeroframe_definesprite` | output_mismatch | compile_fail | 0/3 | - |
