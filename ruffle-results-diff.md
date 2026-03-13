# Ruffle Test Results Diff

**Previous:** `d368848b67b3` (2026-03-13T18:59:09.757321+00:00)
**Current:** `530c6389e49c` (2026-03-13T19:33:41.353274+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 528 | 536 | +8 |
| Total | 618 | 618 | 0 |
| Pass rate | 85.4% | 86.7% | +1.3% |
| Mismatched lines | 15333 | 15067 | -266 |
|   Decreased | | | -267 |
|   Increased | | | +1 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `equals_swf4` | output_mismatch | 598/665 | 665/665 |
| `global_is_bare` | output_mismatch | 6/7 | 7/7 |
| `global_swf5_6_7_8_9` | output_mismatch | 1137/1145 | 1145/1145 |
| `greater_swf6` | output_mismatch | 1150/1175 | 1175/1175 |
| `greater_swf7` | output_mismatch | 1128/1175 | 1175/1175 |
| `lessthan2_swf6` | output_mismatch | 1201/1226 | 1226/1226 |
| `lessthan2_swf7` | output_mismatch | 1179/1226 | 1226/1226 |
| `lessthan_swf4` | output_mismatch | 860/902 | 902/902 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 15/4497 | 20/4497 | -5 |
| `global_proto_decls_delete` | output_mismatch | 1/4158 | 0/4158 | +1 |
