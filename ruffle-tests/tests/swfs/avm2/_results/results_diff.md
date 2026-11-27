# Ruffle Test Results Diff

**Previous:** `dbc43c157352` (2026-11-27T03:57:01.428486+00:00)
**Current:** `2d40d37996b8` (2026-11-27T07:04:58.932906+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1315 | 1276 | -39 |
| Total | 1352 | 1307 | -45 |
| Pass rate | 97.3% | 97.6% | +0.3% |
| Mismatched lines | 1553 | 1451 | -102 |
|   Decreased | | | -1 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `swz` | output_mismatch | 2/3 | 3/3 |

## Missing Tests — Shard Failure (45)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 40 were previously passing
- 5 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `slot_holes_fail` | ruffle_matched | 0/1 |
| `slot_id_exceeds_trait_count` | ruffle_matched | 0/3 |
| `slots_force_autoassigned` | pass | 1/1 |
| `socket_after_disconnect` | pass | 1/1 |
| `socket_close` | pass | 2/2 |
| `socket_connect` | pass | 4/4 |
| `socket_errors` | pass | 56/56 |
| `socket_read_big` | pass | 48/48 |
| `socket_read_little` | pass | 48/48 |
| `socket_read_write_object` | pass | 8/8 |
| `socket_write_big` | pass | 15/15 |
| `socket_write_little` | pass | 14/14 |
| `sound_constructor_with_args` | pass | 6/6 |
| `sound_embeddedprops` | pass | 26/26 |
| `sound_load_multiple` | pass | 19/19 |
| `sound_play` | pass | 19/19 |
| `sound_rootless` | pass | 7/7 |
| `sound_valueof` | pass | 33/33 |
| `soundchannel_position` | ruffle_matched | 66/140 |
| `soundchannel_position_after_end` | pass | 6/6 |
| `soundchannel_soundcomplete` | ruffle_matched | 6/16 |
| `soundchannel_soundtransform` | pass | 835/835 |
| `soundchannel_soundtransform_exists` | pass | 5/5 |
| `soundchannel_stop` | pass | 8/8 |
| `soundmixer_buffertime` | pass | 5/5 |
| `soundmixer_soundtransform` | pass | 900/900 |
| `soundmixer_stopall` | pass | 6/6 |
| `soundtransform` | pass | 442/442 |
| `space_justifier_clone` | pass | 12/12 |
| `sprite_dropTarget` | ruffle_matched | 6/19 |
| `sprite_with_frames` | pass | 0/0 |
| `stage3d_agal_cross_product` | pass | 0/0 |
| `stage3d_agal_upload_errors` | pass | 66/66 |
| `stage3d_bitmap` | pass | 0/0 |
| `stage3d_blend` | pass | 81/81 |
| `stage3d_context3d_string_args` | pass | 158/158 |
| `stage3d_errors` | pass | 7/7 |
| `stage3d_errors_atf` | pass | 3/3 |
| `stage3d_errors_swf_29` | pass | 6/6 |
| `stage3d_float1_index` | pass | 0/0 |
| `stage3d_fractal` | pass | 0/0 |
| `stage3d_ignore_sampler_override` | pass | 0/0 |
| `stage3d_missing_vertex_stream` | pass | 37/37 |
| `stage3d_multistage_triangle` | pass | 3/3 |
| `stage3d_program_constants_bytearray_be` | pass | 0/0 |

</details>
