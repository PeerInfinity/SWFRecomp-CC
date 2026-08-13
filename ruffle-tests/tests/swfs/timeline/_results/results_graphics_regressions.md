# Graphics vs Trace Mode Differences

Trace: 12/17 passing | Graphics: 0/17 passing

## Graphics Regressions (12 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `clip_action_no_key_code` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `frame_label_count_oom` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `frame_script_cleanup` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `frame_script_cleanup2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `frame_script_cleanup3` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `frame_script_cleanup_goto` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `frame_script_construct` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `scene_count_oom` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `swf_9_frame_script_button_order` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `swf_9_frame_script_cleanup_goto` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `swf_9_frame_script_cleanup_goto2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `swf_9_frame_script_dynamic_goto_2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
