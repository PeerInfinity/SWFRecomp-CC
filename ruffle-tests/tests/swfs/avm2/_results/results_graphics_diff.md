# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.229197+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.719596+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1155 | 1141 | -14 |
| Total | 1243 | 1209 | -34 |
| Pass rate | 92.9% | 94.4% | +1.5% |
| Mismatched lines | 12171 | 3449 | -8722 |
|   Decreased | | | -8912 |
|   Increased | | | +4 |

## Newly Passing (21)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `all_classes/events/swf10` | output_mismatch | 15/1638 | 1638/1638 |
| `all_classes/events/swf11` | output_mismatch | 15/1750 | 1750/1750 |
| `all_classes/events/swf12` | output_mismatch | 15/1814 | 1814/1814 |
| `all_classes/events/swf30` | output_mismatch | 25/2353 | 2353/2353 |
| `all_classes/events/swf9` | output_mismatch | 10/1030 | 1030/1030 |
| `appdomain_lookup_edge_cases` | output_mismatch | 7/32 | 32/32 |
| `automation_classes` | output_mismatch | 1/122 | 122/122 |
| `button_nested_frame_simple` | output_mismatch | 27/27 | 27/27 |
| `displayobject_early_init` | output_mismatch | 1/54 | 54/54 |
| `displayobject_hittestpoint_boundary` | output_mismatch | 47/65 | 65/65 |
| `displayobject_scrollrect` | output_mismatch | 27/33 | 33/33 |
| `displayobject_transform` | output_mismatch | 67/89 | 89/89 |
| `matrix3d_determinant` | output_mismatch | 149/182 | 182/182 |
| `matrix3d_precision` | output_mismatch | 5/25 | 28/28 |
| `matrix3d_raw_data` | output_mismatch | 28/33 | 33/33 |
| `method_association` | output_mismatch | 1/5 | 5/5 |
| `mouse_pick_avm1_root` | output_mismatch | 1/2 | 2/2 |
| `native_menu_basic` | output_mismatch | 0/19 | 19/19 |
| `scope_optimizations` | output_mismatch | 3/4 | 4/4 |
| `supercalls_coerce` | output_mismatch | 1/8 | 8/8 |
| `textfield_input_events` | output_mismatch | 9/25 | 25/25 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `getouterscope_two_classobjects` | ruffle_matched | 13/13 | 9/13 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bounds_mode` | output_mismatch | ruffle_matched | 253/269 | 263/269 |

## Added Tests (8)

| Test | Status | Lines |
|------|--------|-------|
| `matrix3d_append_prepend_scale` | output_mismatch | 0/86 |
| `matrix3d_append_prepend_translation` | pass | 42/42 |
| `matrix3d_constructor_clone` | pass | 15/15 |
| `matrix3d_copy_from` | output_mismatch | 15/19 |
| `matrix3d_copy_to_matrix3d` | output_mismatch | 15/19 |
| `matrix3d_interpolate` | output_mismatch | 0/21 |
| `number_to_string` | output_mismatch | 237/353 |
| `vector3d_near_equals` | output_mismatch | 67/80 |

## Missing Tests — Shard Failure (42)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 36 were previously passing
- 6 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `large_preload_from_url` | output_mismatch | 16/27 |
| `large_preload_image_from_bytes` | output_mismatch | 19/25 |
| `lazyinit` | pass | 17/17 |
| `lessequals` | pass | 512/512 |
| `lessthan` | pass | 512/512 |
| `loader_applicationDomain` | output_mismatch | 0/4 |
| `loader_bitmap_transparency` | pass | 14/14 |
| `loader_bytes_unknown_content` | pass | 14/14 |
| `loader_child_getdefinition` | pass | 5/5 |
| `loader_duplicate_class` | output_mismatch | 29/48 |
| `loader_duplicate_coerce` | pass | 3/3 |
| `loader_duplicate_coerce_new_domain` | pass | 4/4 |
| `loader_error_in_root_ctor` | pass | 4/4 |
| `loader_events` | pass | 92/92 |
| `loader_image` | pass | 8/8 |
| `loader_jpegxr` | pass | 2/2 |
| `loader_jpegxr_alpha` | pass | 1/1 |
| `loader_load` | output_mismatch | 126/128 |
| `loader_loadbytes_events` | pass | 30/30 |
| `loader_loadbytes_invalid_png` | pass | 4/4 |
| `loader_loadbytes_url` | pass | 12/12 |
| `loader_loaderurl` | pass | 6/6 |
| `loader_method` | pass | 85/85 |
| `loader_noninteractive_try_click_root` | pass | 5/5 |
| `loader_reuse` | pass | 38/38 |
| `loader_try_click_root` | output_mismatch | 0/16 |
| `loader_unknown_content` | pass | 24/24 |
| `loader_visibility_interactive` | pass | 1/1 |
| `loaderinfo_events` | pass | 7/7 |
| `loaderinfo_loadurl` | pass | 12/12 |
| `loaderinfo_more` | pass | 6/6 |
| `loaderinfo_properties` | pass | 18/18 |
| `loaderinfo_properties_not_loaded` | pass | 23/23 |
| `loaderinfo_quine` | pass | 1005/1005 |
| `loaderinfo_root` | pass | 10/10 |
| `loaderinfo_root_allows` | pass | 2/2 |
| `localconnection` | pass | 890/890 |
| `localconnection_send` | pass | 4/4 |
| `lshift` | pass | 1058/1058 |
| `mask_reapply` | pass | 1/1 |
| `math` | pass | 497/497 |
| `matrix` | pass | 338/338 |

</details>

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `large_preload_from_bytes` | output_mismatch | 18/51 | 35/51 | -17 |
| `mouse_pick_loader_avm1` | output_mismatch | 5/42 | 16/42 | -11 |
| `displayobject_getrect` | output_mismatch | 2/16 | 11/16 | -9 |
| `number_tostring` | output_mismatch | 873/1050 | 882/1050 | -9 |
| `stage_display_state` | output_mismatch | 0/6 | 0/6 | 0 |
