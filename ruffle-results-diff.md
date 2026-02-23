# Ruffle Test Results Diff

**Previous:** `ead961fbbf43` (2026-02-22T23:54:26.198884+00:00)
**Current:** `2a0809e5f3dc` (2026-02-23T00:43:47.222999+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 306 | 307 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 49.4% | 49.6% | +0.2% |
| Mismatched lines | 35256 | 35189 | -67 |
|   Decreased | | | -69 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `stage_scale_mode` | output_mismatch | 35/39 | 39/39 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `selection` | output_mismatch | 372/454 | 434/454 | -62 |
| `movieclip_focusenabled` | output_mismatch | 82/99 | 85/99 | -3 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `global_proto_decls` | output_mismatch | 14/4497 | 13/4497 | +1 |
| `global_proto_decls_delete` | output_mismatch | 1/4158 | 0/4158 | +1 |
