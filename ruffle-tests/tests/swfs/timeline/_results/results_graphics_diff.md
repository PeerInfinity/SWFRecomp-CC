# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.695878+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.536992+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 12 | 0 | -12 |
| Total | 17 | 17 | 0 |
| Pass rate | 70.6% | 0.0% | -70.6% |
| Mismatched lines | 38 | 0 | -38 |
|   Decreased | | | -38 |

## Newly Failing (12)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clip_action_no_key_code` | compile_fail | 1/1 | - |
| `frame_label_count_oom` | compile_fail | 1/1 | - |
| `frame_script_cleanup` | compile_fail | 30/30 | - |
| `frame_script_cleanup2` | compile_fail | 32/32 | - |
| `frame_script_cleanup3` | compile_fail | 30/30 | - |
| `frame_script_cleanup_goto` | compile_fail | 30/30 | - |
| `frame_script_construct` | compile_fail | 25/25 | - |
| `scene_count_oom` | compile_fail | 1/1 | - |
| `swf_9_frame_script_button_order` | compile_fail | 15/15 | - |
| `swf_9_frame_script_cleanup_goto` | compile_fail | 30/30 | - |
| `swf_9_frame_script_cleanup_goto2` | compile_fail | 34/34 | - |
| `swf_9_frame_script_dynamic_goto_2` | compile_fail | 33/33 | - |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `frame_script_button_order` | ruffle_matched | compile_fail | 13/14 | - |
| `frame_script_cleanup_goto2` | output_mismatch | compile_fail | 12/34 | - |
| `missing_frame_scripts` | output_mismatch | compile_fail | 12/22 | - |
| `swf_9_event_goto_frame_script` | ruffle_matched | compile_fail | 3/5 | - |
| `swf_9_frame_script_dynamic_goto` | ruffle_matched | compile_fail | 31/34 | - |
