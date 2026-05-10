# Ruffle Test Results Diff

**Previous:** `ab614b80ddcf` (2026-05-10T22:54:41.151328+00:00)
**Current:** `e527f410660e` (2026-05-10T23:40:32.507025+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 513 | 523 | +10 |
| Total | 651 | 651 | 0 |
| Pass rate | 78.8% | 80.3% | +1.5% |
| Mismatched lines | 10988 | 10586 | -402 |
|   Decreased | | | -402 |

## Newly Passing (11)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `button_keypress` | output_mismatch | 1/3 | 3/3 |
| `call` | output_mismatch | 0/63 | 63/63 |
| `execution_order1` | output_mismatch | 4/5 | 5/5 |
| `execution_order2` | output_mismatch | 7/7 | 7/7 |
| `execution_order4` | output_mismatch | 12/12 | 12/12 |
| `function_base_clip` | output_mismatch | 0/8 | 8/8 |
| `goto_frame` | output_mismatch | 3/12 | 12/12 |
| `goto_label` | output_mismatch | 3/17 | 17/17 |
| `target_clip_removed` | output_mismatch | 5/5 | 5/5 |
| `tell_target_invalid` | output_mismatch | 5/6 | 6/6 |
| `tell_target_invalid_swf6` | output_mismatch | 4/5 | 5/5 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `issue_9885` | output_mismatch | 2/2 | 2/2 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `movieclip_invalid_get_bounds_6` | runtime_error | output_mismatch | 2/10 | 2/10 |
| `movieclip_invalid_get_bounds_7` | runtime_error | output_mismatch | 2/10 | 2/10 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `movieclip_hittest_shapeflag` | output_mismatch | 193/338 | 329/338 | -136 |
| `global_proto_decls` | segfault | 740/4497 | 862/4497 | -122 |
| `goto_frame2` | output_mismatch | 4/44 | 39/44 | -35 |
| `global_instance_decls` | output_mismatch | 15/758 | 23/758 | -8 |
| `removed_clip_halts_script` | output_mismatch | 3/15 | 5/15 | -2 |
