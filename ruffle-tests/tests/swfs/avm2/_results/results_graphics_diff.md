# Ruffle Test Results Diff

**Previous:** `e6f33267e7f3` (2026-07-24T18:56:22.021128+00:00)
**Current:** `d36c8da2b2bd` (2026-07-24T20:26:59.030082+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 829 | 803 | -26 |
| Total | 1217 | 1177 | -40 |
| Pass rate | 68.1% | 68.2% | +0.1% |
| Mismatched lines | 47483 | 47213 | -270 |
|   Decreased | | | -6 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `parse_float` | output_mismatch | 80/81 | 81/81 |
| `string_concat_fromcharcode` | output_mismatch | 36/37 | 37/37 |
| `string_slice_substr_substring` | output_mismatch | 169/170 | 170/170 |
| `xml_basic` | output_mismatch | 32/33 | 33/33 |

## Missing Tests — Shard Failure (40)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 30 were previously passing
- 10 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `stage3d_raytrace` | pass | 0/0 |
| `stage3d_rotating_cube` | pass | 0/0 |
| `stage3d_sampler` | pass | 0/0 |
| `stage3d_sampler_partial_upload` | pass | 0/0 |
| `stage3d_stencil` | pass | 0/0 |
| `stage3d_texture` | pass | 0/0 |
| `stage3d_texture_bytearray` | pass | 0/0 |
| `stage3d_texture_bytearray_compressed_alpha` | pass | 0/0 |
| `stage3d_texture_bytearray_compressed_raw_alpha` | pass | 0/0 |
| `stage3d_triangle` | pass | 0/0 |
| `stage3d_triangle_bytes4` | pass | 0/0 |
| `stage3d_triangle_float1` | pass | 0/0 |
| `stage3d_triangle_index_upload` | pass | 0/0 |
| `stage3d_x_y` | output_mismatch | 0/22 |
| `stage_access` | pass | 10/10 |
| `stage_display_state` | output_mismatch | 0/6 |
| `stage_displayobject_properties` | pass | 24/24 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 0/5 |
| `stage_framerate_nan` | pass | 7/7 |
| `stage_framerate_negative` | pass | 6/6 |
| `stage_framerate_zero` | pass | 6/6 |
| `stage_invalidate` | pass | 38/38 |
| `stage_loaderinfo_properties` | output_mismatch | 22/24 |
| `stage_mousechildren` | pass | 2/2 |
| `stage_mouseenabled` | pass | 15/15 |
| `stage_overriden_setters` | pass | 31/31 |
| `stage_properties` | pass | 30/30 |
| `stage_properties2` | output_mismatch | 23/213 |
| `stage_scale_factor` | output_mismatch | 6/12 |
| `stage_stage3Ds_vector` | output_mismatch | 0/1 |
| `static_length` | output_mismatch | 3/24 |
| `static_text` | output_mismatch | 0/3 |
| `static_var_with_this_in_ctor` | pass | 2/2 |
| `statictext_text` | output_mismatch | 0/8 |
| `stored_properties` | pass | 11/11 |
| `strict_equality` | pass | 34/34 |
| `string_call` | pass | 13/13 |
| `string_case` | pass | 23/23 |
| `string_char_at` | pass | 27/27 |
| `string_char_code_at` | pass | 28/28 |

</details>

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `parse_float_swf10` | output_mismatch | 78/81 | 79/81 | -1 |
| `parse_int` | output_mismatch | 132/135 | 133/135 | -1 |
| `external_interface` | output_mismatch | 3/105 | 3/105 | 0 |
| `filefilter_properties` | output_mismatch | 0/4 | 0/4 | 0 |
