# Ruffle Test Results Diff

**Previous:** `497483af083a` (2026-03-11T03:36:02.802360+00:00)
**Current:** `e946183199f9` (2026-03-11T06:19:22.169057+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 512 | 505 | -7 |
| Total | 618 | 618 | 0 |
| Pass rate | 82.8% | 81.7% | -1.1% |
| Mismatched lines | 19176 | 19205 | +29 |
|   Decreased | | | -82 |
|   Increased | | | +111 |

## Newly Failing (7)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mcl_loadclip` | output_mismatch | 149/149 | 61/149 |
| `mcl_mislabeled_target` | output_mismatch | 6/6 | 2/6 |
| `mcl_target_gif87a` | output_mismatch | 6/6 | 2/6 |
| `mcl_target_gif89a` | output_mismatch | 6/6 | 2/6 |
| `mcl_target_jpg` | output_mismatch | 6/6 | 2/6 |
| `mcl_target_png` | output_mismatch | 6/6 | 2/6 |
| `mcl_unloadclip` | output_mismatch | 5/5 | 2/5 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mcl_replace_root_swf7_to_swf5` | output_mismatch | 14/57 | 56/57 | -42 |
| `mcl_replace_root_swf7_to_swf6` | output_mismatch | 17/57 | 56/57 | -39 |
| `root_button_mode` | output_mismatch | 0/10 | 1/10 | -1 |
