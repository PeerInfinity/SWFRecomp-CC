# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.536992+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.694439+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 12 | +12 |
| Total | 17 | 17 | 0 |
| Pass rate | 0.0% | 70.6% | +70.6% |
| Mismatched lines | 0 | 38 | +38 |
|   Increased | | | +38 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clip_action_no_key_code` | compile_fail | - | 1/1 |
| `frame_label_count_oom` | compile_fail | - | 1/1 |
| `frame_script_cleanup` | compile_fail | - | 30/30 |
| `frame_script_cleanup2` | compile_fail | - | 32/32 |
| `frame_script_cleanup3` | compile_fail | - | 30/30 |
| `frame_script_cleanup_goto` | compile_fail | - | 30/30 |
| `frame_script_construct` | compile_fail | - | 25/25 |
| `scene_count_oom` | compile_fail | - | 1/1 |
| `swf_9_frame_script_button_order` | compile_fail | - | 15/15 |
| `swf_9_frame_script_cleanup_goto` | compile_fail | - | 30/30 |
| `swf_9_frame_script_cleanup_goto2` | compile_fail | - | 34/34 |
| `swf_9_frame_script_dynamic_goto_2` | compile_fail | - | 33/33 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `frame_script_button_order` | compile_fail | ruffle_matched | - | 13/14 |
| `frame_script_cleanup_goto2` | compile_fail | output_mismatch | - | 12/34 |
| `missing_frame_scripts` | compile_fail | output_mismatch | - | 12/22 |
| `swf_9_event_goto_frame_script` | compile_fail | ruffle_matched | - | 3/5 |
| `swf_9_frame_script_dynamic_goto` | compile_fail | ruffle_matched | - | 31/34 |
