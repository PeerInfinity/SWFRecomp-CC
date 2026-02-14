# Ruffle Test Results Diff

**Previous:** `88113607f20c` (2026-02-14T04:37:59.848113+00:00)
**Current:** `bce37d63c446` (2026-02-14T05:21:39.257714+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 158 | 159 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 25.5% | 25.7% | +0.2% |
| Mismatched lines | 56048 | 54059 | -1989 |
|   Decreased | | | -1989 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `text_format` | output_mismatch | 156/1146 | 1146/1146 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `text_format_rounding_swf8` | output_mismatch | 159/840 | 687/840 | -528 |
| `text_format_rounding_swf7` | output_mismatch | 150/840 | 609/840 | -459 |
| `globals_swf5` | output_mismatch | 201/304 | 204/304 | -3 |
| `globals_swf6` | output_mismatch | 208/304 | 211/304 | -3 |
| `globals_swf7` | output_mismatch | 205/304 | 208/304 | -3 |
| `globals_swf8` | output_mismatch | 146/304 | 149/304 | -3 |
| `global_proto_decls` | output_mismatch | 2/4497 | 2/4497 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
