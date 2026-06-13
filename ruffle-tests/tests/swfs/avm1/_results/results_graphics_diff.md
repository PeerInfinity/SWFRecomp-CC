# Ruffle Test Results Diff

**Previous:** `716d0f7787b7` (2026-06-13T03:47:57.188292+00:00)
**Current:** `c764b605aa9a` (2026-06-13T18:31:39.827638+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 619 | 598 | -21 |
| Total | 684 | 665 | -19 |
| Pass rate | 90.5% | 89.9% | -0.6% |
| Mismatched lines | 12507 | 12519 | +12 |

## Added Tests (3)

| Test | Status | Lines |
|------|--------|-------|
| `amf_array_serialization` | output_mismatch | 3/10 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 |
| `set_target_2_swf5` | pass | 13/13 |

## Missing Tests — Shard Failure (22)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 22 were previously passing
- 0 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `this_swf6` | pass | 41/41 |
| `this_swf7` | pass | 41/41 |
| `timeline_function_def` | pass | 7/7 |
| `timeout` | pass | 0/0 |
| `timer_run_actions` | pass | 18/18 |
| `trace` | pass | 8/8 |
| `transform` | pass | 70/70 |
| `try_catch_finally` | pass | 118/118 |
| `try_catch_stack` | pass | 16/16 |
| `try_finally_simple` | pass | 16/16 |
| `typeof` | pass | 22/22 |
| `typeof_globals` | pass | 7/7 |
| `uncaught_exception` | pass | 1/1 |
| `uncaught_exception_bubbled` | pass | 1/1 |
| `undefined_to_string_swf6` | pass | 4/4 |
| `unescape` | pass | 43/43 |
| `unload` | pass | 52/52 |
| `unload_clip_event` | pass | 4/4 |
| `unload_nested_child` | pass | 5/5 |
| `unloadmovie` | pass | 4/4 |
| `unloadmovie_method` | pass | 3/3 |
| `unloadmovienum` | pass | 13/13 |

</details>
