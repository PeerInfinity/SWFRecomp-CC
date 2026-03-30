# Ruffle Test Results Diff

**Previous:** `d99210bb1847` (2026-03-29T18:01:34.307950+00:00)
**Current:** `35ae511427a1` (2026-03-30T00:01:00.601976+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 563 | 564 | +1 |
| Total | 620 | 620 | 0 |
| Pass rate | 90.8% | 91.0% | +0.2% |
| Mismatched lines | 12885 | 11881 | -1004 |
|   Decreased | | | -1005 |
|   Increased | | | +1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_pixeldissolve` | output_mismatch | 82/1075 | 1075/1075 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_filters` | segfault | output_mismatch | 78/548 | 84/548 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 113/4497 | 119/4497 | -6 |
| `global_instance_decls` | output_mismatch | 18/758 | 17/758 | +1 |
