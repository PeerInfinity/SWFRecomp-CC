# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.897816+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.552825+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 10 | +10 |
| Total | 12 | 12 | 0 |
| Pass rate | 0.0% | 83.3% | +83.3% |
| Mismatched lines | 0 | 22 | +22 |
|   Increased | | | +22 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `avm1_doabc` | compile_fail | - | 1/1 |
| `avm1_loads_avm2_doaction` | compile_fail | - | 2/2 |
| `avm1_sprite_sc_ignored` | compile_fail | - | 3/3 |
| `avm2_doaction` | compile_fail | - | 1/1 |
| `avm2_loads_avm1` | compile_fail | - | 14/14 |
| `avm2_loads_avm1_doabc` | compile_fail | - | 4/4 |
| `avm2_loads_avm1_loads_avm2_doabc` | compile_fail | - | 3/3 |
| `avm2_loads_avm1_loads_into_root` | compile_fail | - | 2/2 |
| `avm2_loads_avm1_v10` | compile_fail | - | 8/8 |
| `avm2_loads_avm1_v9` | compile_fail | - | 8/8 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `avm1_loads_avm2` | compile_fail | output_mismatch | - | 3/7 |
| `avm2_loads_avm1_events` | compile_fail | ruffle_matched | - | 8/26 |
