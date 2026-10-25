# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.748169+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:41.913859+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 10 | 0 | -10 |
| Total | 12 | 12 | 0 |
| Pass rate | 83.3% | 0.0% | -83.3% |
| Mismatched lines | 22 | 0 | -22 |
|   Decreased | | | -22 |

## Newly Failing (10)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `avm1_doabc` | compile_fail | 1/1 | - |
| `avm1_loads_avm2_doaction` | compile_fail | 2/2 | - |
| `avm1_sprite_sc_ignored` | compile_fail | 3/3 | - |
| `avm2_doaction` | compile_fail | 1/1 | - |
| `avm2_loads_avm1` | compile_fail | 14/14 | - |
| `avm2_loads_avm1_doabc` | compile_fail | 4/4 | - |
| `avm2_loads_avm1_loads_avm2_doabc` | compile_fail | 3/3 | - |
| `avm2_loads_avm1_loads_into_root` | compile_fail | 2/2 | - |
| `avm2_loads_avm1_v10` | compile_fail | 8/8 | - |
| `avm2_loads_avm1_v9` | compile_fail | 8/8 | - |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `avm1_loads_avm2` | output_mismatch | compile_fail | 3/7 | - |
| `avm2_loads_avm1_events` | ruffle_matched | compile_fail | 8/26 | - |
