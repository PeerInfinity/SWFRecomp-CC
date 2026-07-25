# Ruffle Test Results Diff

**Previous:** `da35e5d771bb` (2026-07-25T00:20:13.972877+00:00)
**Current:** `8e8370df1193` (2026-07-25T02:29:16.950975+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 835 | 840 | +5 |
| Total | 1217 | 1217 | 0 |
| Pass rate | 68.6% | 69.0% | +0.4% |
| Mismatched lines | 47424 | 47269 | -155 |
|   Decreased | | | -155 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `capabilities_resolution` | output_mismatch | 1/8 | 8/8 |
| `decode_uri` | output_mismatch | 0/71 | 71/71 |
| `encode_uri_surrogate_pair_swf11` | output_mismatch | 0/15 | 15/15 |
| `escape` | output_mismatch | 20/71 | 71/71 |
| `unescape` | output_mismatch | 25/28 | 28/28 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `invalid_utf8` | output_mismatch | 3/12 | 11/12 | -8 |
| `encode_uri_surrogate_pair_swf10` | ruffle_matched | 0/15 | 0/15 | 0 |
