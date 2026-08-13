# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.772461+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.595609+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 19 | 0 | -19 |
| Total | 20 | 20 | 0 |
| Pass rate | 95.0% | 0.0% | -95.0% |
| Mismatched lines | 2 | 0 | -2 |
|   Decreased | | | -2 |

## Newly Failing (19)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `afunc_dict` | compile_fail | 2/2 | - |
| `background` | compile_fail | 0/0 | - |
| `dict_callframe` | compile_fail | 3/3 | - |
| `dict_cross` | compile_fail | 3/3 | - |
| `dict_event` | compile_fail | 5/5 | - |
| `dict_override` | compile_fail | 2/2 | - |
| `func_dict` | compile_fail | 3/3 | - |
| `initaction_in_definesprite` | compile_fail | 2/2 | - |
| `jump_after_end` | compile_fail | 3/3 | - |
| `jump_to_prev_block` | compile_fail | 1/1 | - |
| `missing_bitmap` | compile_fail | 0/0 | - |
| `mixed-bytecode-as2` | compile_fail | 1/1 | - |
| `registers` | compile_fail | 36/36 | - |
| `tags_after_last_showframe` | compile_fail | 1/1 | - |
| `trace-as2/arguments` | compile_fail | 8/8 | - |
| `trace-as2/root_onload` | compile_fail | 4/4 | - |
| `trace-as2/shortstack` | compile_fail | 2/2 | - |
| `trace-as2/super` | compile_fail | 8/8 | - |
| `trace-as2/this` | compile_fail | 8/8 | - |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `zeroframe_definesprite` | ruffle_matched | compile_fail | 1/3 | - |
