# Ruffle Test Results Diff

**Previous:** `574824001e94` (2026-11-27T01:02:33.911334+00:00)
**Current:** `6ee6eded7b66` (2026-11-27T01:51:12.165339+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1310 | 1316 | +6 |
| Total | 1352 | 1352 | 0 |
| Pass rate | 96.9% | 97.3% | +0.4% |
| Mismatched lines | 1661 | 1435 | -226 |
|   Decreased | | | -231 |
|   Increased | | | +5 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `dependent_strings` | output_mismatch | 46/84 | 83/83 |
| `edittext_getcharboundaries_culling` | ruffle_matched | 125/305 | 305/305 |
| `event_handler_exception` | ruffle_matched | 8/11 | 11/11 |
| `freestanding_superclass` | ruffle_matched | 2/4 | 4/4 |
| `loader_applicationDomain` | output_mismatch | 0/4 | 3/3 |
| `weird_superinterface_properties` | ruffle_matched | 1/2 | 2/2 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `coerce_property` | ruffle_matched | 33/36 | 35/36 | -2 |
| `swz` | output_mismatch | 0/2 | 2/3 | -1 |
| `loader_load` | output_mismatch | 126/128 | 125/128 | +1 |
| `slot_holes_fail` | ruffle_matched | 0/0 | 0/1 | +1 |
| `slot_id_exceeds_trait_count` | ruffle_matched | 0/0 | 0/3 | +3 |
