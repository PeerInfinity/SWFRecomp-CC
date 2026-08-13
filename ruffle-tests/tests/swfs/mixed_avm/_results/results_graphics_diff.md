# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.569702+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.726027+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 7 | +7 |
| Total | 11 | 11 | 0 |
| Pass rate | 0.0% | 63.6% | +63.6% |
| Mismatched lines | 0 | 13 | +13 |
|   Increased | | | +13 |

## Newly Passing (7)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `avm1_doabc` | compile_fail | - | 1/1 |
| `avm1_loads_avm2_doaction` | compile_fail | - | 2/2 |
| `avm1_sprite_sc_ignored` | compile_fail | - | 3/3 |
| `avm2_doaction` | compile_fail | - | 1/1 |
| `avm2_loads_avm1_doabc` | compile_fail | - | 4/4 |
| `avm2_loads_avm1_loads_avm2_doabc` | compile_fail | - | 3/3 |
| `avm2_loads_avm1_loads_into_root` | compile_fail | - | 2/2 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `avm1_loads_avm2` | compile_fail | output_mismatch | - | 3/7 |
| `avm2_loads_avm1` | compile_fail | output_mismatch | - | 9/14 |
| `avm2_loads_avm1_v10` | compile_fail | output_mismatch | - | 5/8 |
| `avm2_loads_avm1_v9` | compile_fail | output_mismatch | - | 7/8 |
