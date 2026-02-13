# Ruffle Test Results Diff

**Previous:** `ef611bfba5d6` (2026-02-13T02:28:55.884855+00:00)
**Current:** `56ef4af542bf` (2026-02-13T03:07:33.078008+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 113 | 114 | +1 |
| Total | 616 | 616 | 0 |
| Pass rate | 18.3% | 18.5% | +0.2% |
| Mismatched lines | 57071 | 56450 | -621 |
|   Decreased | | | -665 |
|   Increased | | | +44 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `call_method_empty_name` | output_mismatch | 0/1 | 1/1 |
| `define_function2` | output_mismatch | 7/8 | 8/8 |
| `object_constructor` | output_mismatch | 32/33 | 33/33 |
| `tab_ordering_properties_tab_index_edge_case` | output_mismatch | 0/4 | 4/4 |

## Newly Failing (3)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `access_unnamed_shape` | output_mismatch | 1/1 | 0/1 |
| `add2` | output_mismatch | 354/354 | 340/354 |
| `movieclip_prototype_extension` | output_mismatch | 5/5 | 3/5 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `enumerate` | segfault | output_mismatch | 1/64 | 17/64 |
| `register_underflow` | output_mismatch | runtime_error | 15/26 | 8/26 |

## Line Count Changed (19)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `focusrect_property_swf5` | output_mismatch | 3/1237 | 210/1237 | -207 |
| `focusrect_property_swf6` | output_mismatch | 3/1237 | 210/1237 | -207 |
| `focusrect_property_swf7` | output_mismatch | 2/1237 | 209/1237 | -207 |
| `movieclip_lockroot` | output_mismatch | 6/29 | 15/29 | -9 |
| `define_function2_preload` | output_mismatch | 4/13 | 9/13 | -5 |
| `get_variable_in_scope` | output_mismatch | 23/29 | 26/29 | -3 |
| `stage_object_children` | output_mismatch | 62/83 | 64/83 | -2 |
| `register_and_init_order` | output_mismatch | 35/231 | 36/231 | -1 |
| `string_paths_other` | output_mismatch | 4/36 | 5/36 | -1 |
| `define_local_with_paths` | output_mismatch | 15/54 | 15/54 | 0 |
| `form_loader_encoding_2` | output_mismatch | 0/3 | 0/3 | 0 |
| `swf4_actions_coercion_order` | segfault | 9/158 | 9/158 | 0 |
| `path_string` | segfault | 44/322 | 43/322 | +1 |
| `with_variable_scopes` | output_mismatch | 25/43 | 24/43 | +1 |
| `named_shapes` | output_mismatch | 5/14 | 3/14 | +2 |
| `root_global_parent` | output_mismatch | 3/6 | 1/6 | +2 |
| `swf6_case_insensitive` | output_mismatch | 25/42 | 23/42 | +2 |
| `tab_ordering_properties` | output_mismatch | 8/293 | 5/293 | +3 |
| `swf7_case_sensitive` | output_mismatch | 41/44 | 32/44 | +9 |
