# Ruffle Test Results Diff

**Previous:** `658f9a212770` (2026-02-21T02:00:04.412251+00:00)
**Current:** `2a083a781951` (2026-02-21T03:22:01.678858+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 248 | 260 | +12 |
| Total | 619 | 619 | 0 |
| Pass rate | 40.1% | 42.0% | +1.9% |
| Mismatched lines | 39301 | 39063 | -238 |
|   Decreased | | | -243 |
|   Increased | | | +5 |

## Newly Passing (13)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `conflicting_instance_names` | output_mismatch | 20/23 | 23/23 |
| `do_init_action` | output_mismatch | 3/3 | 3/3 |
| `enumerate` | output_mismatch | 31/64 | 64/64 |
| `execution_order2` | output_mismatch | 5/7 | 7/7 |
| `goto_advance1` | output_mismatch | 1/6 | 6/6 |
| `goto_advance2` | output_mismatch | 2/2 | 2/2 |
| `goto_both_ways1` | output_mismatch | 2/3 | 3/3 |
| `goto_both_ways2` | output_mismatch | 1/3 | 3/3 |
| `goto_rewind1` | output_mismatch | 1/1 | 1/1 |
| `goto_rewind2` | output_mismatch | 3/3 | 3/3 |
| `mouse_listeners` | output_mismatch | 59/67 | 67/67 |
| `object_prototypes` | output_mismatch | 71/74 | 74/74 |
| `textfield_props_swf6` | output_mismatch | 208/210 | 210/210 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_1906` | output_mismatch | 4/4 | 2/4 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_object_properties` | output_mismatch | 132/241 | 223/241 | -91 |
| `stage_object_properties_swf6` | output_mismatch | 131/231 | 210/231 | -79 |
| `focusrect_property_swf6` | output_mismatch | 707/1237 | 717/1237 | -10 |
| `textsnapshot_props_swf6` | output_mismatch | 5/56 | 7/56 | -2 |
| `default_names` | output_mismatch | 14/52 | 15/52 | -1 |
| `this_swf6` | output_mismatch | 17/41 | 18/41 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `goto_rewind3` | output_mismatch | 2/2 | 2/2 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 1/5 | 1/5 | 0 |
| `movieclip_depth_methods` | output_mismatch | 95/98 | 94/98 | +1 |
| `clip_events` | output_mismatch | 3/19 | 1/19 | +2 |
