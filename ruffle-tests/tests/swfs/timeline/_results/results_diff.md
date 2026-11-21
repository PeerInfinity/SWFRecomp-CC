# Ruffle Test Results Diff

**Previous:** `344c85a166c3` (2026-11-15T08:31:27.871711+00:00)
**Current:** `08709f65842a` (2026-11-21T17:00:08.535744+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 14 | +14 |
| Total | 17 | 17 | 0 |
| Pass rate | 0.0% | 82.4% | +82.4% |
| Mismatched lines | 0 | 6 | +6 |
|   Increased | | | +6 |

## Newly Passing (14)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `clip_action_no_key_code` | compile_fail | - | 1/1 |
| `frame_label_count_oom` | compile_fail | - | 1/1 |
| `frame_script_cleanup` | compile_fail | - | 30/30 |
| `frame_script_cleanup2` | compile_fail | - | 32/32 |
| `frame_script_cleanup3` | compile_fail | - | 30/30 |
| `frame_script_cleanup_goto` | compile_fail | - | 30/30 |
| `frame_script_cleanup_goto2` | compile_fail | - | 34/34 |
| `frame_script_construct` | compile_fail | - | 25/25 |
| `missing_frame_scripts` | compile_fail | - | 22/22 |
| `scene_count_oom` | compile_fail | - | 1/1 |
| `swf_9_frame_script_button_order` | compile_fail | - | 15/15 |
| `swf_9_frame_script_cleanup_goto` | compile_fail | - | 30/30 |
| `swf_9_frame_script_cleanup_goto2` | compile_fail | - | 34/34 |
| `swf_9_frame_script_dynamic_goto_2` | compile_fail | - | 33/33 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `frame_script_button_order` | compile_fail | ruffle_matched | - | 13/14 |
| `swf_9_event_goto_frame_script` | compile_fail | ruffle_matched | - | 3/5 |
| `swf_9_frame_script_dynamic_goto` | compile_fail | ruffle_matched | - | 31/34 |
