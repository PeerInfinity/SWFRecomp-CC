# Ruffle Test Results Diff

**Previous:** `13b40eabb012` (2026-11-25T20:23:11.835751+00:00)
**Current:** `10a5b515a03a` (2026-11-25T21:42:12.057687+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1293 | 1299 | +6 |
| Total | 1346 | 1346 | 0 |
| Pass rate | 96.1% | 96.5% | +0.4% |
| Mismatched lines | 2305 | 2113 | -192 |
|   Decreased | | | -192 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_access_oob_interpreter` | ruffle_matched | 0/1 | 1/1 |
| `edittext_getcharboundaries_missing_embedded_font` | ruffle_matched | 4/7 | 7/7 |
| `encode_uri_surrogate_pair_swf10` | ruffle_matched | 0/15 | 15/15 |
| `graphics_draw_path` | ruffle_matched | 51/101 | 101/101 |
| `groupelement_text` | ruffle_matched | 154/156 | 156/156 |
| `vector_indexing_cutoffs` | ruffle_matched | 17/18 | 18/18 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_getcharboundaries_culling` | ruffle_matched | 5/305 | 125/305 | -120 |
