# Ruffle Test Results Diff

**Previous:** `0a99be1a92de` (2026-08-09T08:51:22.868925+00:00)
**Current:** `88ebde66534f` (2026-08-16T08:44:05.379311+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 674 | 681 | +7 |
| Total | 718 | 725 | +7 |
| Pass rate | 93.9% | 93.9% | 0% |
| Mismatched lines | 14546 | 11731 | -2815 |
|   Decreased | | | -2836 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `textfield_asbroadcaster` | output_mismatch | 0/14 | 14/14 |
| `watch_recursion_double_swf7` | output_mismatch | 409/3118 | 3118/3118 |
| `watch_recursion_swf7` | output_mismatch | 1036/1042 | 1042/1042 |
| `watch_virtual_property` | output_mismatch | 9/60 | 60/60 |

## Added Tests (7)

| Test | Status | Lines |
|------|--------|-------|
| `sound_load_multiple_instances` | pass | 19/19 |
| `sound_load_multiple_remote` | output_mismatch | 2/6 |
| `sound_load_props` | output_mismatch | 96/111 |
| `sound_load_start_remote` | output_mismatch | 0/1 |
| `sound_load_stops_when_dereferenced` | pass | 0/0 |
| `sound_load_streaming_stop_remote` | output_mismatch | 2/3 |
| `sound_mixed_attach_load` | pass | 13/13 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `watch_recursion_double_swf6` | ruffle_matched | 18/46 | 42/46 | -24 |
| `looping_child_swf32` | output_mismatch | 29/141 | 38/141 | -9 |
| `looping_child_swf5` | output_mismatch | 29/141 | 38/141 | -9 |
| `looping_child_swf9` | output_mismatch | 29/141 | 38/141 | -9 |
| `watch_recursion_swf6` | ruffle_matched | 12/18 | 17/18 | -5 |
| `sound_load_start` | pass | 3/3 | 6/6 | 0 |
