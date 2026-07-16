# Ruffle Test Results Diff

**Previous:** `aca2a606e973` (2026-07-16T10:37:05.717645+00:00)
**Current:** `a05b56ddf072` (2026-07-16T22:53:07.437819+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 822 | 793 | -29 |
| Total | 1207 | 1170 | -37 |
| Pass rate | 68.1% | 67.8% | -0.3% |
| Mismatched lines | 47043 | 46757 | -286 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `verify_illegal_opcode` | output_mismatch | 0/1 |
| `verify_method_info_duplicate` | output_mismatch | 0/2 |
| `verify_method_info_oob` | output_mismatch | 0/1 |

## Missing Tests — Shard Failure (40)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 29 were previously passing
- 11 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `stage3d_program_constants_invalid_input` | output_mismatch | 0/21 |
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
| `stage_properties2` | output_mismatch | 18/213 |
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

</details>
