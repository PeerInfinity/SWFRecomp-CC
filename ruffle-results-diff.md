# Ruffle Test Results Diff

**Previous:** `7c3cc798128e` (2026-02-20T18:03:45.886761+00:00)
**Current:** `07bb2fe2056e` (2026-02-21T01:19:44.350634+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 237 | 242 | +5 |
| Total | 619 | 619 | 0 |
| Pass rate | 38.3% | 39.1% | +0.8% |
| Mismatched lines | 39788 | 39629 | -159 |
|   Decreased | | | -185 |
|   Increased | | | +26 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `globals_swf5` | output_mismatch | 293/304 | 304/304 |
| `localconnection_properties` | output_mismatch | 4/8 | 8/8 |
| `printjob_props_swf5` | output_mismatch | 7/45 | 45/45 |
| `printjob_props_swf6` | output_mismatch | 5/45 | 45/45 |
| `printjob_props_swf7` | output_mismatch | 7/45 | 45/45 |
| `sound_props_swf5` | output_mismatch | 48/68 | 68/68 |
| `sound_props_swf6` | output_mismatch | 36/68 | 68/68 |
| `target_clip_removed` | output_mismatch | 4/5 | 5/5 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mouse_listeners` | output_mismatch | 67/67 | 59/67 |
| `object_prototypes` | output_mismatch | 74/74 | 71/74 |
| `textfield_props_swf6` | output_mismatch | 210/210 | 208/210 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 1/5 | -1 |
| `global_proto_decls` | output_mismatch | 9/4497 | 9/4497 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `this_swf6` | output_mismatch | 18/41 | 17/41 | +1 |
| `textsnapshot_props_swf6` | output_mismatch | 7/56 | 5/56 | +2 |
| `focusrect_property_swf6` | output_mismatch | 717/1237 | 707/1237 | +10 |
