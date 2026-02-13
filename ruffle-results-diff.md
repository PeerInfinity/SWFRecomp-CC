# Ruffle Test Results Diff

**Previous:** `69066103679e` (2026-02-13T01:26:04.469292+00:00)
**Current:** `d482f825a729` (2026-02-13T02:01:43.150910+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 108 | 112 | +4 |
| Total | 616 | 616 | 0 |
| Pass rate | 17.5% | 18.2% | +0.7% |
| Mismatched lines | 57047 | 57076 | +29 |
|   Decreased | | | -6 |
|   Increased | | | +35 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `goto_both_ways1` | output_mismatch | 1/3 | 3/3 |
| `goto_execution_order2` | output_mismatch | 0/2 | 2/2 |
| `goto_rewind1` | output_mismatch | 1/1 | 1/1 |
| `looping` | output_mismatch | 6/6 | 6/6 |

## Line Count Changed (15)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `execution_order3` | output_mismatch | 2/4 | 3/4 | -1 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 1/5 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `movieclip_hittest_shapeflag` | output_mismatch | 10/338 | 10/338 | 0 |
| `netstream_seek_flv` | output_mismatch | 1/25 | 1/25 | 0 |
| `register_globals_across_frames` | output_mismatch | 7/15 | 7/15 | 0 |
| `removed_base_clip_tell_target` | output_mismatch | 0/2 | 0/2 | 0 |
| `tell_target_invalid` | output_mismatch | 1/6 | 1/6 | 0 |
| `variable_args` | output_mismatch | 0/5 | 0/5 | 0 |
| `execution_order2` | output_mismatch | 3/7 | 2/7 | +1 |
| `goto_frame_number` | output_mismatch | 2/3 | 1/3 | +1 |
| `default_names` | output_mismatch | 5/52 | 3/52 | +2 |
| `remove_movie_clip` | output_mismatch | 10/29 | 7/29 | +3 |
| `rewind_depth` | output_mismatch | 9/30 | 6/30 | +3 |
| `register_and_init_order` | output_mismatch | 60/231 | 35/231 | +25 |
