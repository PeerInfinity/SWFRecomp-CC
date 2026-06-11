# Ruffle Test Results Diff

**Previous:** `257f96acd0f8` (2026-06-03T17:58:29.216119+00:00)
**Current:** `db8c78080cb1` (2026-06-11T17:13:23.228355+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 616 | 616 | 0 |
| Total | 673 | 678 | +5 |
| Pass rate | 91.5% | 90.9% | -0.6% |
| Mismatched lines | 9620 | 11161 | +1541 |
|   Decreased | | | -1 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `placeobject_all_event_flags` | output_mismatch | 7/10 |
| `target_paths/swf4` | output_mismatch | 642/818 |
| `target_paths/swf5` | output_mismatch | 178/854 |
| `target_paths/swf6` | output_mismatch | 178/854 |
| `xml_socket_connect_null` | output_mismatch | 1/12 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_base_clip_tell_target` | output_mismatch | 0/2 | 0/1 | -1 |
| `call` | pass | 63/63 | 62/62 | 0 |
| `path_string` | pass | 322/322 | 301/301 | 0 |
| `property_invalid_base_clip` | pass | 36/36 | 35/35 | 0 |
| `swf4_actions_coercion_order` | pass | 158/158 | 157/157 | 0 |
| `tell_target` | pass | 37/37 | 34/34 | 0 |
| `tell_target_invalid` | pass | 6/6 | 5/5 | 0 |
| `tell_target_invalid_swf6` | pass | 5/5 | 4/4 | 0 |
