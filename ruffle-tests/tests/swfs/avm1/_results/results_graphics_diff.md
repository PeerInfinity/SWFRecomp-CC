# Ruffle Test Results Diff

**Previous:** `aeebf9ede383` (2026-08-15T10:09:49.204284+00:00)
**Current:** `9d038c750eaf` (2026-08-19T13:54:51.696717+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 681 | 666 | -15 |
| Total | 725 | 701 | -24 |
| Pass rate | 93.9% | 95.0% | +1.1% |
| Mismatched lines | 11731 | 11389 | -342 |
|   Decreased | | | -26 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `shared_stack` | output_mismatch | 11/16 | 16/16 |
| `sound_load_multiple_remote` | output_mismatch | 2/6 | 6/6 |
| `sound_load_props` | output_mismatch | 96/111 | 111/111 |
| `sound_load_start_remote` | output_mismatch | 0/1 | 1/1 |
| `sound_load_streaming_stop_remote` | output_mismatch | 2/3 | 3/3 |

## Missing Tests — Shard Failure (24)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 20 were previously passing
- 4 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `loadmovienum_cross_version_prototype` | pass | 9/9 |
| `loadvariables` | pass | 2/2 |
| `loadvariables2` | pass | 8/8 |
| `loadvariables_method` | output_mismatch | 0/7 |
| `loadvariablesnum` | pass | 2/2 |
| `loadvars_tostring` | pass | 5/5 |
| `local_to_global` | pass | 49/49 |
| `localconnection` | pass | 579/579 |
| `localconnection_properties` | pass | 8/8 |
| `localconnection_top_level` | pass | 7/7 |
| `lock_root` | pass | 1/1 |
| `logical_ops_swf4` | pass | 90/90 |
| `logical_ops_swf8` | pass | 108/108 |
| `looping` | pass | 6/6 |
| `looping_child_swf32` | output_mismatch | 38/141 |
| `looping_child_swf5` | output_mismatch | 38/141 |
| `looping_child_swf9` | output_mismatch | 38/141 |
| `looping_real_1_declared_1` | pass | 1/1 |
| `looping_real_1_declared_2` | pass | 1/1 |
| `looping_real_2_declared_1` | pass | 5/5 |
| `looping_real_2_declared_2` | pass | 5/5 |
| `mask_reapply` | pass | 0/0 |
| `mask_with_drawing` | pass | 0/0 |
| `math_min_max` | pass | 101/101 |

</details>
