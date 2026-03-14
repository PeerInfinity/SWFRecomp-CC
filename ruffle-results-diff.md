# Ruffle Test Results Diff

**Previous:** `6e238d4eaefa` (2026-03-14T03:47:24.548961+00:00)
**Current:** `60c48ae3a9f9` (2026-03-14T05:00:14.937376+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 539 | 539 | 0 |
| Total | 618 | 618 | 0 |
| Pass rate | 87.2% | 87.2% | 0% |
| Mismatched lines | 14835 | 14443 | -392 |
|   Decreased | | | -1430 |
|   Increased | | | +1038 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `bitmap_data_compare` | output_mismatch | 21/40 | 40/40 |
| `bitmapdata_channels` | output_mismatch | 11/19 | 19/19 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `global_swf5_6_7_8_9` | output_mismatch | 1145/1145 | 145/1145 |
| `native_subclasses` | output_mismatch | 191/191 | 190/191 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmap_data_hittest` | output_mismatch | segfault | 62/132 | 96/132 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `bitmap_data` | output_mismatch | 69/1126 | 1125/1126 | -1056 |
| `bitmap_data_noise` | output_mismatch | 334/631 | 627/631 | -293 |
| `bitmap_data_copypixels` | output_mismatch | 3/17 | 15/17 | -12 |
| `bitmap_data_threshold` | output_mismatch | 104/176 | 112/176 | -8 |
| `global_instance_decls` | output_mismatch | 3/758 | 3/758 | 0 |
| `global_proto_decls` | output_mismatch | 96/4497 | 90/4497 | +6 |
| `bitmap_data_pixeldissolve` | output_mismatch | 96/1075 | 82/1075 | +14 |
| `global_proto_decls_delete` | output_mismatch | 18/4158 | 1/4158 | +17 |
