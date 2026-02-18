# Ruffle Test Results Diff

**Previous:** `10a57582eb0f` (2026-02-18T16:25:46.003654+00:00)
**Current:** `c3381e0ef86a` (2026-02-18T19:49:09.012283+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 229 | 226 | -3 |
| Total | 619 | 619 | 0 |
| Pass rate | 37.0% | 36.5% | -0.5% |
| Mismatched lines | 41386 | 40686 | -700 |
|   Decreased | | | -729 |
|   Increased | | | +29 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `stage_object_enumerate` | output_mismatch | 1/4 | 4/4 |
| `stage_property_representation` | output_mismatch | 4/586 | 586/586 |

## Newly Failing (5)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `edittext_width_height` | output_mismatch | 103/103 | 84/103 |
| `execution_order3` | output_mismatch | 4/4 | 2/4 |
| `goto_both_ways1` | output_mismatch | 3/3 | 1/3 |
| `goto_execution_order2` | output_mismatch | 2/2 | 0/2 |
| `goto_rewind3` | output_mismatch | 2/2 | 1/2 |

## Line Count Changed (12)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties` | output_mismatch | 173/241 | 225/241 | -52 |
| `stage_object_properties_swf6` | output_mismatch | 166/231 | 212/231 | -46 |
| `focusrect_property_swf5` | output_mismatch | 239/1237 | 269/1237 | -30 |
| `frame_size_translated_negative` | output_mismatch | 14/21 | 20/21 | -6 |
| `frame_size_translated_positive` | output_mismatch | 14/21 | 20/21 | -6 |
| `default_names` | output_mismatch | 13/52 | 15/52 | -2 |
| `path_string` | output_mismatch | 48/322 | 49/322 | -1 |
| `register_and_init_order` | output_mismatch | 30/231 | 31/231 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `placeobject_occupied_depth` | output_mismatch | 0/6 | 0/6 | 0 |
| `movieclip_lockroot` | output_mismatch | 16/29 | 15/29 | +1 |
| `movieclip_depth_methods` | output_mismatch | 96/98 | 94/98 | +2 |
