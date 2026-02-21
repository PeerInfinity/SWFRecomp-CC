# Ruffle Test Results Diff

**Previous:** `07bb2fe2056e` (2026-02-21T01:19:44.350634+00:00)
**Current:** `3c59fa1ad5de` (2026-02-21T01:31:19.003986+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 242 | 246 | +4 |
| Total | 619 | 619 | 0 |
| Pass rate | 39.1% | 39.7% | +0.6% |
| Mismatched lines | 39629 | 39579 | -50 |
|   Decreased | | | -50 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `math_swf6` | output_mismatch | 522/530 | 530/530 |
| `math_swf7` | output_mismatch | 522/530 | 530/530 |
| `math_swf8` | output_mismatch | 522/530 | 530/530 |
| `unload_clip_event` | output_mismatch | 2/4 | 4/4 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `clip_events` | segfault | output_mismatch | 1/19 | 1/19 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `unload` | output_mismatch | 13/52 | 36/52 | -23 |
| `global_proto_decls` | output_mismatch | 9/4497 | 10/4497 | -1 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
