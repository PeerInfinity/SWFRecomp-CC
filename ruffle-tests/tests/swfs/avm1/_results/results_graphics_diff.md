# Ruffle Test Results Diff

**Previous:** `2511a9854408` (2026-06-13T22:44:31.374922+00:00)
**Current:** `828b69b82dfb` (2026-06-13T23:44:02.448249+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 620 | 598 | -22 |
| Total | 687 | 665 | -22 |
| Pass rate | 90.2% | 89.9% | -0.3% |
| Mismatched lines | 12519 | 12519 | 0 |

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
