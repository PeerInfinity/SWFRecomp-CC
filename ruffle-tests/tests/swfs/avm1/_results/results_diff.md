# Ruffle Test Results Diff

**Previous:** `2a090d60ddf3` (2026-06-03T02:26:00.853801+00:00)
**Current:** `eb280b751d6b` (2026-06-11T16:10:17.999347+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 616 | 609 | -7 |
| Total | 673 | 678 | +5 |
| Pass rate | 91.5% | 89.8% | -1.7% |
| Mismatched lines | 9584 | 11981 | +2397 |
|   Decreased | | | -1 |
|   Increased | | | +371 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `call` | output_mismatch | 63/63 | 42/62 |
| `path_string` | output_mismatch | 322/322 | 56/301 |
| `property_invalid_base_clip` | output_mismatch | 36/36 | 19/35 |
| `swf4_actions_coercion_order` | output_mismatch | 158/158 | 106/157 |
| `tell_target` | output_mismatch | 37/37 | 4/34 |
| `tell_target_invalid` | output_mismatch | 6/6 | 0/5 |
| `tell_target_invalid_swf6` | output_mismatch | 5/5 | 0/4 |

## Added Tests (5)

| Test | Status | Lines |
|------|--------|-------|
| `placeobject_all_event_flags` | output_mismatch | 7/10 |
| `target_paths/swf4` | output_mismatch | 171/818 |
| `target_paths/swf5` | output_mismatch | 171/854 |
| `target_paths/swf6` | output_mismatch | 171/854 |
| `xml_socket_connect_null` | output_mismatch | 1/12 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `removed_base_clip_tell_target` | output_mismatch | 0/2 | 0/1 | -1 |
