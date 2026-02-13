# Ruffle Test Results Diff

**Previous:** `56ef4af542bf` (2026-02-13T03:07:33.078008+00:00)
**Current:** `a5a14902b8cd` (2026-02-13T03:33:31.841390+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 114 | 117 | +3 |
| Total | 616 | 616 | 0 |
| Pass rate | 18.5% | 19.0% | +0.5% |
| Mismatched lines | 56450 | 56406 | -44 |
|   Decreased | | | -45 |
|   Increased | | | +1 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `access_unnamed_shape` | output_mismatch | 0/1 | 1/1 |
| `add2` | output_mismatch | 340/354 | 354/354 |
| `movieclip_prototype_extension` | output_mismatch | 3/5 | 5/5 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `register_underflow` | runtime_error | output_mismatch | 8/26 | 18/26 |

## Line Count Changed (9)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `swf7_case_sensitive` | output_mismatch | 32/44 | 41/44 | -9 |
| `named_shapes` | output_mismatch | 3/14 | 6/14 | -3 |
| `stage_object_children` | output_mismatch | 64/83 | 66/83 | -2 |
| `swf6_case_insensitive` | output_mismatch | 23/42 | 25/42 | -2 |
| `global_instance_decls` | output_mismatch | 0/758 | 1/758 | -1 |
| `string_paths_other` | output_mismatch | 5/36 | 6/36 | -1 |
| `define_local_with_paths` | output_mismatch | 15/54 | 15/54 | 0 |
| `form_loader_encoding_2` | output_mismatch | 0/3 | 0/3 | 0 |
| `register_and_init_order` | output_mismatch | 36/231 | 35/231 | +1 |
