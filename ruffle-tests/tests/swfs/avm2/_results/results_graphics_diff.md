# Ruffle Test Results Diff

**Previous:** `63ca22e398c4` (2026-07-21T23:49:05.128836+00:00)
**Current:** `f490e4b247e8` (2026-07-22T00:51:45.642767+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 790 | 823 | +33 |
| Total | 1174 | 1215 | +41 |
| Pass rate | 67.3% | 67.7% | +0.4% |
| Mismatched lines | 47211 | 47961 | +750 |

## Added Tests (41)

| Test | Status | Lines |
|------|--------|-------|
| `divide` | pass | 1058/1058 |
| `doabc_and_symbolclass_script_init_goto` | output_mismatch | 1/7 |
| `doabc_and_symbolclass_script_init_normal` | output_mismatch | 1/6 |
| `doabc_is_eager` | pass | 1/1 |
| `documentclass` | pass | 9/9 |
| `domain_memory` | runtime_error | 1/133 |
| `drag_drop` | pass | 10/10 |
| `drop_shadow_filter` | output_mismatch | 4/172 |
| `duplicate_defs` | pass | 1/1 |
| `eager_init` | pass | 1/1 |
| `east_asian_justifier_clone` | output_mismatch | 0/8 |
| `edit_text_linkage` | pass | 7/7 |
| `edittext_align` | pass | 60/60 |
| `edittext_always_show_selection` | pass | 0/0 |
| `edittext_antialiastype` | pass | 296/296 |
| `edittext_at_point_methods_basic` | pass | 16/16 |
| `edittext_autosize` | pass | 39/39 |
| `edittext_autosize_align` | pass | 0/0 |
| `edittext_autosize_height_dynamic` | pass | 60/60 |
| `edittext_autosize_height_input` | pass | 60/60 |
| `edittext_autosize_lazy_bounds_events` | pass | 65/65 |
| `edittext_autosize_lazy_bounds_interactions` | pass | 19/19 |
| `edittext_autosize_lazy_bounds_props` | pass | 490/490 |
| `edittext_autosize_lazy_bounds_visual` | pass | 0/0 |
| `edittext_autosize_lazy_bounds_vs_relayout` | pass | 106/106 |
| `edittext_bottom_scroll_v_basic` | pass | 210/210 |
| `edittext_bounds_scale` | pass | 24/24 |
| `edittext_bullet` | pass | 30/30 |
| `edittext_default_format` | pass | 221/221 |
| `edittext_default_format_empty` | pass | 136/136 |
| `edittext_device_transform_layout` | output_mismatch | 160/288 |
| `edittext_empty_text_format` | pass | 7/7 |
| `edittext_focus_selection` | pass | 5/5 |
| `edittext_font_size` | pass | 45/45 |
| `edittext_format_empty_font` | pass | 8/8 |
| `edittext_get_char_index_at_point` | pass | 4/4 |
| `edittext_get_line_index_at_point` | pass | 2/2 |
| `edittext_get_line_index_of_char` | pass | 76/76 |
| `edittext_getcharboundaries` | pass | 172/172 |
| `edittext_getcharboundaries_culling` | ruffle_matched | 5/305 |
| `edittext_getcharboundaries_missing_embedded_font` | ruffle_matched | 4/7 |
