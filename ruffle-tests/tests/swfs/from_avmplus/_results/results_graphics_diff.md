# Ruffle Test Results Diff

**Previous:** `9b6bbcb5757f` (2026-07-25T20:09:02.207279+00:00)
**Current:** `2b244c01b173` (2026-07-25T21:37:09.731727+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1406 | 1421 | +15 |
| Total | 1574 | 1574 | 0 |
| Pass rate | 89.3% | 90.3% | +1.0% |
| Mismatched lines | 1914 | 1885 | -29 |
|   Decreased | | | -29 |

## Newly Passing (15)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as3/Vector/bug_678952` | output_mismatch | 1/2 | 2/2 |
| `as3/Vector/filter` | output_mismatch | 8/9 | 9/9 |
| `as3/Vector/filter_initializers` | output_mismatch | 4/5 | 5/5 |
| `as3/Vector/foreach` | output_mismatch | 5/6 | 6/6 |
| `as3/Vector/foreach_initializers` | output_mismatch | 4/5 | 5/5 |
| `as3/Vector/initializer_expressions` | output_mismatch | 40/41 | 41/41 |
| `as3/Vector/initializer_large_vector` | compile_fail | - | 1/1 |
| `as3/Vector/map` | output_mismatch | 11/12 | 12/12 |
| `as3/Vector/map_initializers` | output_mismatch | 6/7 | 7/7 |
| `as3/Vector/nested` | output_mismatch | 7/8 | 8/8 |
| `as3/Vector/nonindexproperty/v10` | output_mismatch | 44/51 | 51/51 |
| `as3/Vector/some` | output_mismatch | 12/13 | 13/13 |
| `as3/Vector/some_initializers` | output_mismatch | 5/6 | 6/6 |
| `as3/Vector/vectorIndexRangeExceptions` | output_mismatch | 1260/1270 | 1270/1270 |
| `ecma3/String/localeCompare_rt` | output_mismatch | 3/4 | 4/4 |
