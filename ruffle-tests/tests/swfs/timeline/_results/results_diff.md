# Ruffle Test Results Diff

**Previous:** `f55511379655` (2026-10-18T08:49:49.712726+00:00)
**Current:** `344c85a166c3` (2026-10-25T08:41:41.543706+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 14 | 0 | -14 |
| Total | 17 | 17 | 0 |
| Pass rate | 82.4% | 0.0% | -82.4% |
| Mismatched lines | 6 | 0 | -6 |
|   Decreased | | | -6 |

## Newly Failing (14)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `clip_action_no_key_code` | compile_fail | 1/1 | - |
| `frame_label_count_oom` | compile_fail | 1/1 | - |
| `frame_script_cleanup` | compile_fail | 30/30 | - |
| `frame_script_cleanup2` | compile_fail | 32/32 | - |
| `frame_script_cleanup3` | compile_fail | 30/30 | - |
| `frame_script_cleanup_goto` | compile_fail | 30/30 | - |
| `frame_script_cleanup_goto2` | compile_fail | 34/34 | - |
| `frame_script_construct` | compile_fail | 25/25 | - |
| `missing_frame_scripts` | compile_fail | 22/22 | - |
| `scene_count_oom` | compile_fail | 1/1 | - |
| `swf_9_frame_script_button_order` | compile_fail | 15/15 | - |
| `swf_9_frame_script_cleanup_goto` | compile_fail | 30/30 | - |
| `swf_9_frame_script_cleanup_goto2` | compile_fail | 34/34 | - |
| `swf_9_frame_script_dynamic_goto_2` | compile_fail | 33/33 | - |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `frame_script_button_order` | ruffle_matched | compile_fail | 13/14 | - |
| `swf_9_event_goto_frame_script` | ruffle_matched | compile_fail | 3/5 | - |
| `swf_9_frame_script_dynamic_goto` | ruffle_matched | compile_fail | 31/34 | - |
