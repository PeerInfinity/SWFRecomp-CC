# Ruffle Test Results Diff

**Previous:** `446f5ed7afc5` (2026-03-07T20:22:00.320919+00:00)
**Current:** `bdfe895cebc3` (2026-03-07T22:30:46.866159+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 490 | 498 | +8 |
| Total | 619 | 619 | 0 |
| Pass rate | 79.2% | 80.5% | +1.3% |
| Mismatched lines | 19610 | 19596 | -14 |
|   Decreased | | | -15 |
|   Increased | | | +1 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `execution_order1` | output_mismatch | 3/5 | 5/5 |
| `execution_order2` | output_mismatch | 7/7 | 7/7 |
| `execution_order4` | output_mismatch | 10/12 | 12/12 |
| `getproperty_swf4` | output_mismatch | 26/28 | 28/28 |
| `set_interval` | output_mismatch | 22/27 | 27/27 |
| `stage_object_children` | output_mismatch | 82/83 | 83/83 |
| `tell_target_invalid` | output_mismatch | 5/6 | 6/6 |
| `tell_target_invalid_swf6` | output_mismatch | 4/5 | 5/5 |
| `textfield_properties` | output_mismatch | 43/44 | 44/44 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `goto_frame_number` | output_mismatch | 3/3 | 2/3 |
