# Ruffle Test Results Diff

**Previous:** `7a348be46a51` (2026-04-04T01:50:51.871950+00:00)
**Current:** `112f7a9df78d` (2026-04-04T02:19:30.585773+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 532 | 572 | +40 |
| Total | 578 | 620 | +42 |
| Pass rate | 92.0% | 92.3% | +0.3% |
| Mismatched lines | 9751 | 10265 | +514 |
|   Increased | | | +2 |

## Added Tests (42)

| Test | Status | Lines |
|------|--------|-------|
| `biturshift` | pass | 14/14 |
| `biturshift_swf8` | pass | 14/14 |
| `bitxor` | pass | 1058/1058 |
| `boxed_primitives` | pass | 24/24 |
| `button_children` | pass | 8/8 |
| `button_goto` | pass | 4/4 |
| `button_key_events` | pass | 14/14 |
| `button_key_events_special` | pass | 45/45 |
| `button_keypress` | pass | 3/3 |
| `button_keypress_vs_press` | pass | 25/25 |
| `button_keypress_vs_tab` | pass | 20/20 |
| `button_keypress_vs_textinput` | pass | 4/4 |
| `button_order` | pass | 2/2 |
| `button_properties_special_cases` | pass | 22/22 |
| `button_v5` | pass | 18/18 |
| `button_v6` | pass | 18/18 |
| `call` | pass | 63/63 |
| `call_method_empty_name` | pass | 1/1 |
| `capabilities_resolution` | pass | 8/8 |
| `catch_references_registers` | pass | 2/2 |
| `click_block` | pass | 5/5 |
| `loadmovienum_cross_version_prototype` | pass | 9/9 |
| `loadvariables` | pass | 2/2 |
| `loadvariables2` | pass | 8/8 |
| `loadvariables_method` | output_mismatch | 0/7 |
| `loadvariablesnum` | pass | 2/2 |
| `local_to_global` | pass | 49/49 |
| `localconnection` | output_mismatch | 74/579 |
| `localconnection_properties` | pass | 8/8 |
| `lock_root` | pass | 1/1 |
| `logical_ops_swf4` | pass | 90/90 |
| `logical_ops_swf8` | pass | 108/108 |
| `looping` | pass | 6/6 |
| `mask_reapply` | pass | 0/0 |
| `mask_with_drawing` | pass | 0/0 |
| `math_min_max` | pass | 101/101 |
| `math_swf6` | pass | 530/530 |
| `math_swf7` | pass | 530/530 |
| `math_swf8` | pass | 530/530 |
| `matrix` | pass | 171/171 |
| `mcl_as_broadcaster` | pass | 12/12 |
| `mcl_events_swf_version` | pass | 232/232 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 16/758 | 14/758 | +2 |
