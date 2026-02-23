# Ruffle Test Results Diff

**Previous:** `fec544b6b78f` (2026-02-23T03:47:56.898159+00:00)
**Current:** `f0cb91cadc1d` (2026-02-23T04:32:54.043105+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 309 | 310 | +1 |
| Total | 619 | 619 | 0 |
| Pass rate | 49.9% | 50.1% | +0.2% |
| Mismatched lines | 35143 | 35018 | -125 |
|   Decreased | | | -127 |
|   Increased | | | +2 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `export_assets` | output_mismatch | 2/3 | 3/3 |

## Line Count Changed (13)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_library_state_values` | runtime_error | 16/78 | 68/78 | -52 |
| `removed_target_clip_scope` | output_mismatch | 0/35 | 23/35 | -23 |
| `function_base_clip_removed` | output_mismatch | 1/25 | 17/25 | -16 |
| `attach_movie` | output_mismatch | 43/59 | 57/59 | -14 |
| `string_paths_other` | output_mismatch | 22/36 | 31/36 | -9 |
| `register_and_init_order` | output_mismatch | 30/231 | 34/231 | -4 |
| `string_paths_variable_scopes` | output_mismatch | 0/5 | 4/5 | -4 |
| `empty_movieclip_can_attach_movies` | output_mismatch | 8/11 | 10/11 | -2 |
| `movieclip_init_object` | output_mismatch | 0/5 | 1/5 | -1 |
| `register_class` | output_mismatch | 2/66 | 3/66 | -1 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `default_names` | output_mismatch | 16/52 | 15/52 | +1 |
| `removed_clip_halts_script` | output_mismatch | 2/15 | 1/15 | +1 |
