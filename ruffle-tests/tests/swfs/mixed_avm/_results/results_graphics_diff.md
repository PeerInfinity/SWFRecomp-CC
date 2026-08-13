# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.738800+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.569702+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 4 | 0 | -4 |
| Total | 11 | 11 | 0 |
| Pass rate | 36.4% | 0.0% | -36.4% |
| Mismatched lines | 27 | 0 | -27 |
|   Decreased | | | -27 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `avm1_doabc` | compile_fail | 1/1 | - |
| `avm1_loads_avm2_doaction` | compile_fail | 2/2 | - |
| `avm1_sprite_sc_ignored` | compile_fail | 3/3 | - |
| `avm2_doaction` | compile_fail | 1/1 | - |

## Status Changed (7)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `avm1_loads_avm2` | output_mismatch | compile_fail | 3/7 | - |
| `avm2_loads_avm1` | output_mismatch | compile_fail | 1/14 | - |
| `avm2_loads_avm1_doabc` | output_mismatch | compile_fail | 1/4 | - |
| `avm2_loads_avm1_loads_avm2_doabc` | output_mismatch | compile_fail | 1/3 | - |
| `avm2_loads_avm1_loads_into_root` | output_mismatch | compile_fail | 1/2 | - |
| `avm2_loads_avm1_v10` | output_mismatch | compile_fail | 5/8 | - |
| `avm2_loads_avm1_v9` | output_mismatch | compile_fail | 7/8 | - |
