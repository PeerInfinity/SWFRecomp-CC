# Ruffle Test Results Diff

**Previous:** `f9f0700382a1` (2026-06-18T05:55:10.451275+00:00)
**Current:** `fe0030e4fc7d` (2026-06-18T21:40:01.207373+00:00)
**⚠️ Incomplete run: 26/30 shards produced results (4 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 622 | 532 | -90 |
| Total | 701 | 608 | -93 |
| Pass rate | 88.7% | 87.5% | -1.2% |
| Mismatched lines | 16460 | 16419 | -41 |
|   Increased | | | +13 |

## Missing Tests — Shard Failure (93)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 90 were previously passing
- 3 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
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
| `call` | pass | 62/62 |
| `call_method_empty_name` | pass | 1/1 |
| `capabilities_resolution` | pass | 8/8 |
| `catch_references_registers` | pass | 2/2 |
| `click_block` | pass | 5/5 |
| `clip_constructors` | pass | 8/8 |
| `clip_event_propagation_order` | pass | 17/17 |
| `clip_events` | pass | 19/19 |
| `clone_sprite_edittext` | pass | 94/94 |
| `clone_sprite_edittext_dynamic` | pass | 86/86 |
| `clone_sprite_types` | pass | 24/24 |
| `closure_scope` | pass | 7/7 |
| `goto_execution_order` | pass | 2/2 |
| `goto_execution_order2` | pass | 2/2 |
| `goto_frame` | pass | 12/12 |
| `goto_frame2` | pass | 44/44 |
| `goto_frame_number` | pass | 3/3 |
| `goto_label` | pass | 17/17 |
| `goto_methods` | pass | 40/40 |
| `goto_rewind1` | pass | 1/1 |
| `goto_rewind2` | pass | 3/3 |
| `goto_rewind3` | pass | 2/2 |
| `greater_swf6` | pass | 1175/1175 |
| `greater_swf7` | pass | 1175/1175 |
| `greaterthan_swf5` | pass | 1/1 |
| `greaterthan_swf8` | pass | 1/1 |
| `has_own_property` | pass | 32/32 |
| `hittest_lockroot` | pass | 15/15 |
| `hittest_morph` | pass | 70/70 |
| `hittest_morph_input` | pass | 1/1 |
| `hittest_winding_rule` | pass | 12/12 |
| `infinite_recursion_function` | pass | 4/4 |
| `infinite_recursion_function_in_setter` | pass | 131/131 |
| `infinite_recursion_virtual_property` | pass | 67/67 |
| `init_array_invalid` | pass | 4/4 |
| `movieclip_lockroot` | pass | 29/29 |
| `movieclip_methods_with_loaded_image` | pass | 4/4 |
| `movieclip_name_from_timeline` | pass | 13/13 |
| `movieclip_onconstruct` | pass | 20/20 |
| `movieclip_prototype_extension` | pass | 5/5 |
| `movieclip_setmask` | pass | 14/14 |
| `movieclip_state_values` | pass | 114/114 |
| `moviecliploader_flashvars` | pass | 4/4 |
| `mutable_this` | pass | 18/18 |
| `named_shapes` | pass | 14/14 |
| `nan_scale` | pass | 9/9 |
| `native_double_construct` | pass | 12/12 |
| `native_objects_swf6` | output_mismatch | 114/115 |
| `native_objects_swf7` | pass | 115/115 |
| `native_objects_swf8` | pass | 115/115 |
| `native_subclasses` | pass | 191/191 |
| `nested_textfields_in_buttons` | pass | 0/0 |
| `netconnection_close` | pass | 39/39 |
| `netconnection_send_remote` | output_mismatch | 2/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 |
| `netstream_play_flv` | pass | 21/21 |
| `netstream_play_flv_screen` | pass | 0/0 |
| `netstream_seek_flv` | pass | 25/25 |
| `swf5_encoding` | pass | 3/3 |
| `swf5_global_funcs` | pass | 232/232 |
| `swf5_no_closure` | pass | 19/19 |
| `swf5_to_6_cross_call` | pass | 29/29 |
| `swf5_xml_event_handler_context` | pass | 2/2 |
| `swf6_case_insensitive` | pass | 42/42 |
| `swf6_global_funcs` | pass | 232/232 |
| `swf6_string_as_bool` | pass | 15/15 |
| `swf6_to_5_cross_call` | pass | 29/29 |
| `swf7_case_sensitive` | pass | 44/44 |
| `swf7_global_funcs` | pass | 232/232 |
| `tab_ordering_automatic_basic` | pass | 92/92 |
| `tab_ordering_automatic_order_grid` | pass | 21/21 |
| `tab_ordering_automatic_order_same_position` | pass | 12/12 |
| `tab_ordering_children` | pass | 208/208 |
| `tab_ordering_custom_basic` | pass | 71/71 |
| `tab_ordering_custom_duplicate_index` | pass | 22/22 |
| `tab_ordering_custom_i32_vs_u32` | pass | 12/12 |
| `tab_ordering_custom_m1` | pass | 29/29 |
| `tab_ordering_events` | pass | 150/150 |
| `tab_ordering_events_mouse` | pass | 65/65 |
| `tab_ordering_movieclip_enabled_default` | pass | 462/462 |
| `tab_ordering_properties` | pass | 293/293 |

</details>

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_instance_decls` | output_mismatch | 26/758 | 13/758 | +13 |
