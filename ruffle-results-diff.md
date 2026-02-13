# Ruffle Test Results Diff

**Previous:** `ced90dd8593b` (2026-02-13T07:04:31.534125+00:00)
**Current:** `4f02643feca2` (2026-02-13T20:11:30.390221+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 129 | 137 | +8 |
| Total | 616 | 619 | +3 |
| Pass rate | 20.9% | 22.1% | +1.2% |
| Mismatched lines | 56130 | 57783 | +1653 |
|   Decreased | | | -26 |
|   Increased | | | +89 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_length` | output_mismatch | 35/42 | 42/42 |
| `define_function2_preload` | output_mismatch | 12/13 | 13/13 |
| `goto_both_ways1` | output_mismatch | 3/3 | 3/3 |
| `goto_both_ways2` | output_mismatch | 3/3 | 3/3 |
| `goto_frame_number` | output_mismatch | 2/3 | 3/3 |
| `goto_rewind1` | output_mismatch | 1/1 | 1/1 |
| `goto_rewind3` | output_mismatch | 2/2 | 2/2 |
| `movieclip_name_from_timeline` | output_mismatch | 11/13 | 13/13 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `define_local` | output_mismatch | segfault | 2/27 | 2/27 |
| `placeobject_occupied_depth` | timeout | output_mismatch | - | 0/6 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `math_swf6` | output_mismatch | 0/530 |
| `math_swf7` | output_mismatch | 0/530 |
| `math_swf8` | output_mismatch | 0/530 |

## Line Count Changed (31)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `slash_syntax` | output_mismatch | 0/14 | 9/14 | -9 |
| `tell_target` | output_mismatch | 0/37 | 4/37 | -4 |
| `execution_order2` | output_mismatch | 2/7 | 3/7 | -1 |
| `target_clip_removed` | output_mismatch | 0/5 | 1/5 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `custom_clip_methods` | output_mismatch | 0/4 | 0/4 | 0 |
| `execution_order1` | output_mismatch | 0/5 | 0/5 | 0 |
| `execution_order4` | output_mismatch | 1/12 | 1/12 | 0 |
| `root_global_parent` | output_mismatch | 1/6 | 1/6 | 0 |
| `tell_target_invalid` | output_mismatch | 0/6 | 0/6 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `variable_args` | output_mismatch | 0/5 | 0/5 | 0 |
| `device_font_spacing` | segfault | 1/91 | 0/91 | +1 |
| `edittext_html_condensewhite_swf7` | output_mismatch | 93/311 | 92/311 | +1 |
| `edittext_html_condensewhite_swf8` | output_mismatch | 90/311 | 89/311 | +1 |
| `netstream_seek_flv` | output_mismatch | 1/25 | 0/25 | +1 |
| `textfield_background_color` | output_mismatch | 8/11 | 7/11 | +1 |
| `textfield_border_color` | output_mismatch | 8/11 | 7/11 | +1 |
| `textfield_text` | output_mismatch | 6/7 | 5/7 | +1 |
| `clone_sprite_edittext` | output_mismatch | 2/94 | 0/94 | +2 |
| `edittext_autosize_setter` | output_mismatch | 2/20 | 0/20 | +2 |
| `edittext_scroll` | output_mismatch | 33/54 | 31/54 | +2 |
| `clone_sprite_types` | output_mismatch | 12/24 | 9/24 | +3 |
| `edittext_tag_indent` | output_mismatch | 5/31 | 0/31 | +5 |
| `register_and_init_order` | output_mismatch | 35/231 | 30/231 | +5 |
| `textfield_properties` | output_mismatch | 32/44 | 26/44 | +6 |
| `edittext_html_swf6` | output_mismatch | 2014/5377 | 2006/5377 | +8 |
| `edittext_html_swf7` | output_mismatch | 1378/5377 | 1370/5377 | +8 |
| `edittext_html_swf8` | output_mismatch | 1363/5377 | 1355/5377 | +8 |
| `textfield_variable` | output_mismatch | 54/81 | 44/81 | +10 |
| `edittext_newline_stripping` | output_mismatch | 32/64 | 15/64 | +17 |
