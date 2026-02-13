# Ruffle Test Results Diff

**Previous:** `28a85fbf831e` (2026-02-13T01:01:02.041564+00:00)
**Current:** `69066103679e` (2026-02-13T01:26:04.469292+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 105 | 108 | +3 |
| Total | 616 | 616 | 0 |
| Pass rate | 17.0% | 17.5% | +0.5% |
| Mismatched lines | 57088 | 57047 | -41 |
|   Decreased | | | -41 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `focusrect_swf5` | output_mismatch | 1/6 | 6/6 |
| `goto_advance2` | output_mismatch | 1/2 | 2/2 |
| `goto_both_ways2` | output_mismatch | 2/3 | 3/3 |
| `goto_rewind2` | output_mismatch | 2/3 | 3/3 |
| `goto_rewind3` | output_mismatch | 1/2 | 2/2 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `goto_rewind1` | output_mismatch | 1/1 | 1/1 |
| `looping` | output_mismatch | 6/6 | 6/6 |

## Line Count Changed (11)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | output_mismatch | 35/231 | 60/231 | -25 |
| `remove_movie_clip` | output_mismatch | 7/29 | 10/29 | -3 |
| `default_names` | output_mismatch | 3/52 | 5/52 | -2 |
| `netstream_seek_flv` | output_mismatch | 0/25 | 1/25 | -1 |
| `tell_target_invalid` | output_mismatch | 0/6 | 1/6 | -1 |
| `closure_scope` | output_mismatch | 0/7 | 0/7 | 0 |
| `goto_both_ways1` | output_mismatch | 1/3 | 1/3 | 0 |
| `movieclip_hittest_shapeflag` | output_mismatch | 10/338 | 10/338 | 0 |
| `register_globals_across_frames` | output_mismatch | 7/15 | 7/15 | 0 |
| `tell_target_invalid_swf6` | output_mismatch | 0/5 | 0/5 | 0 |
| `variable_args` | output_mismatch | 0/5 | 0/5 | 0 |
