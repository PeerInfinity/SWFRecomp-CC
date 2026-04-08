# Ruffle Test Results Diff

**Previous:** `69612f4204e8` (2026-04-08T17:46:11.961729+00:00)
**Current:** `2a4adfc3fdc2` (2026-04-08T22:58:46.064292+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 580 | 578 | -2 |
| Total | 620 | 620 | 0 |
| Pass rate | 93.5% | 93.2% | -0.3% |
| Mismatched lines | 8918 | 9012 | +94 |
|   Decreased | | | -15 |
|   Increased | | | +109 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `equals_swf4` | output_mismatch | 665/665 | 598/665 |
| `lessthan_swf4` | output_mismatch | 902/902 | 860/902 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 803/4497 | 813/4497 | -10 |
| `global_instance_decls` | output_mismatch | 13/758 | 16/758 | -3 |
| `global_proto_decls_delete` | output_mismatch | 296/4158 | 298/4158 | -2 |
