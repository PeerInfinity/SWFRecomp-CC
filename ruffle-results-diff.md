# Ruffle Test Results Diff

**Previous:** `27c921770011` (2026-02-25T06:48:06.332430+00:00)
**Current:** `a9f8745287ee` (2026-02-25T20:15:46.978434+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 347 | 356 | +9 |
| Total | 619 | 619 | 0 |
| Pass rate | 56.1% | 57.5% | +1.4% |
| Mismatched lines | 33019 | 32992 | -27 |
|   Decreased | | | -34 |
|   Increased | | | +7 |

## Newly Passing (11)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `as_set_prop_flags_version` | output_mismatch | 24/31 | 31/31 |
| `as_set_prop_flags_version_swf5` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf6` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf7` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf8` | output_mismatch | 0/1 | 1/1 |
| `as_set_prop_flags_version_swf9` | output_mismatch | 0/1 | 1/1 |
| `define_function2_preload` | output_mismatch | 12/13 | 13/13 |
| `define_function2_preload_order` | output_mismatch | 2/4 | 4/4 |
| `execution_order2` | output_mismatch | 4/7 | 7/7 |
| `function_suppress_and_preload` | output_mismatch | 23/28 | 28/28 |
| `swf5_no_closure` | output_mismatch | 16/19 | 19/19 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `execution_order3` | output_mismatch | 4/4 | 2/4 |
| `goto_execution_order2` | output_mismatch | 2/2 | 0/2 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `register_and_init_order` | output_mismatch | 27/231 | 34/231 | -7 |
| `coerce_to_object_monkeypatch` | output_mismatch | 9/129 | 10/129 | -1 |
| `removed_clip_halts_script` | output_mismatch | 1/15 | 1/15 | 0 |
| `goto_frame2` | output_mismatch | 13/44 | 12/44 | +1 |
| `global_instance_decls` | output_mismatch | 3/758 | 1/758 | +2 |
