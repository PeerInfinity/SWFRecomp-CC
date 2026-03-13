# Ruffle Test Results Diff

**Previous:** `e5aadd667fc8` (2026-03-13T18:01:43.624698+00:00)
**Current:** `d368848b67b3` (2026-03-13T18:59:09.757321+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 531 | 528 | -3 |
| Total | 618 | 618 | 0 |
| Pass rate | 85.9% | 85.4% | -0.5% |
| Mismatched lines | 15121 | 15333 | +212 |
|   Decreased | | | -42 |
|   Increased | | | +254 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `globals_swf5` | output_mismatch | 296/304 | 304/304 |
| `globals_swf6` | output_mismatch | 301/304 | 304/304 |
| `target_clip_swf5` | output_mismatch | 0/2 | 2/2 |
| `textfield_props_swf5` | output_mismatch | 173/175 | 175/175 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `equals_swf4` | output_mismatch | 665/665 | 598/665 |
| `global_is_bare` | output_mismatch | 7/7 | 6/7 |
| `greater_swf6` | output_mismatch | 1175/1175 | 1150/1175 |
| `greater_swf7` | output_mismatch | 1175/1175 | 1128/1175 |
| `lessthan2_swf6` | output_mismatch | 1226/1226 | 1201/1226 |
| `lessthan2_swf7` | output_mismatch | 1226/1226 | 1179/1226 |
| `lessthan_swf4` | output_mismatch | 902/902 | 860/902 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_swf5_6_7_8_9` | output_mismatch | 1115/1145 | 1137/1145 | -22 |
| `global_proto_decls` | output_mismatch | 11/4497 | 15/4497 | -4 |
| `native_objects_swf6` | output_mismatch | 82/84 | 83/84 | -1 |
| `global_instance_decls` | output_mismatch | 12/758 | 12/758 | 0 |
| `global_proto_decls_delete` | output_mismatch | 1/4158 | 1/4158 | 0 |
