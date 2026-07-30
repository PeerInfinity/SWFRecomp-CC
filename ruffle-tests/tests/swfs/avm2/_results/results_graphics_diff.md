# Ruffle Test Results Diff

**Previous:** `9277e0e1b214` (2026-07-30T07:00:20.365759+00:00)
**Current:** `c045e044c667` (2026-07-30T08:52:49.835812+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 972 | 979 | +7 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 79.6% | 80.2% | +0.6% |
| Mismatched lines | 39361 | 39342 | -19 |
|   Decreased | | | -20 |
|   Increased | | | +1 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `construct_interface` | output_mismatch | 2/3 | 3/3 |
| `cpool_index_invalid_bytecode_1` | output_mismatch | 0/6 | 6/6 |
| `cpool_index_invalid_bytecode_2` | output_mismatch | 0/3 | 3/3 |
| `cpool_index_invalid_bytecode_3` | output_mismatch | 0/1 | 1/1 |
| `verification` | output_mismatch | 5/8 | 8/8 |
| `verify_dxns_without_flag` | output_mismatch | 1/3 | 3/3 |
| `verify_jump_to_middle_of_op` | output_mismatch | 0/1 | 1/1 |
| `verify_stack` | output_mismatch | 2/5 | 5/5 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `catch_class` | output_mismatch | 6/6 | 5/6 |
