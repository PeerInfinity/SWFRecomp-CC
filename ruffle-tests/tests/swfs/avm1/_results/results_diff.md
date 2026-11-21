# Ruffle Test Results Diff

**Previous:** `08709f65842a` (2026-11-21T17:00:08.480588+00:00)
**Current:** `bc91565cea8e` (2026-11-21T19:30:16.371895+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 713 | 692 | -21 |
| Total | 775 | 749 | -26 |
| Pass rate | 92.0% | 92.4% | +0.4% |
| Mismatched lines | 13095 | 3883 | -9212 |

## Missing Tests — Shard Failure (26)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 21 were previously passing
- 5 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `function_as_function` | pass | 35/35 |
| `function_base_clip` | pass | 8/8 |
| `function_base_clip_readded` | pass | 11/11 |
| `function_base_clip_removed` | pass | 25/25 |
| `function_suppress_and_preload` | pass | 28/28 |
| `funky_function_calls` | pass | 56/56 |
| `get_bytes_total` | pass | 4/4 |
| `get_variable_in_scope` | pass | 29/29 |
| `getproperty` | pass | 28/28 |
| `getproperty_swf4` | pass | 28/28 |
| `getproperty_swf5` | pass | 28/28 |
| `gettextextent` | pass | 56/56 |
| `geturl` | pass | 7/7 |
| `geturl_opcode_target_normalize` | pass | 45/45 |
| `geturl_target_normalize` | pass | 89/89 |
| `global_array` | pass | 3/3 |
| `global_instance_decls` | output_mismatch | 19/758 |
| `global_is_bare` | pass | 7/7 |
| `global_proto_decls` | output_mismatch | 59/4562 |
| `global_proto_decls_delete` | output_mismatch | 461/4158 |
| `global_swf5_6_7_8_9` | pass | 1145/1145 |
| `global_swf6_7_8` | pass | 15/15 |
| `globals_monkeypatch` | output_mismatch | 43/306 |
| `globals_swf5` | output_mismatch | 294/304 |
| `globals_swf6` | pass | 304/304 |
| `globals_swf7` | pass | 304/304 |

</details>
