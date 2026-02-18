# Ruffle Test Results Diff

**Previous:** `229cb534e3fe` (2026-02-18T06:34:26.692377+00:00)
**Current:** `45a5281eefde` (2026-02-18T16:07:08.365240+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 225 | 226 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 36.3% | 36.5% | +0.2% |
| Mismatched lines | 42714 | 42652 | -62 |
|   Decreased | | | -62 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `movieclip_get_instance_at_depth` | output_mismatch | 18/28 | 28/28 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_depth_methods` | output_mismatch | 76/98 | 96/98 | -20 |
| `rewind_depth` | output_mismatch | 9/30 | 26/30 | -17 |
| `this_scoping` | output_mismatch | 32/52 | 42/52 | -10 |
| `unload` | output_mismatch | 8/52 | 11/52 | -3 |
| `default_names` | output_mismatch | 11/52 | 13/52 | -2 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `place_and_lookup` | output_mismatch | 0/30 | 0/30 | 0 |
