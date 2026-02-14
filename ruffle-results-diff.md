# Ruffle Test Results Diff

**Previous:** `73a7b457723b` (2026-02-14T20:35:19.182692+00:00)
**Current:** `733a70e9c5f3` (2026-02-14T20:44:57.230326+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 173 | 186 | +13 |
| Total | 619 | 619 | 0 |
| Pass rate | 27.9% | 30.0% | +2.1% |
| Mismatched lines | 62255 | 52553 | -9702 |
|   Decreased | | | -9793 |
|   Increased | | | +91 |

## Newly Passing (13)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `add2` | output_mismatch | 31/354 | 354/354 |
| `equals2_swf5` | segfault | 32/926 | 926/926 |
| `equals2_swf6` | segfault | 32/926 | 926/926 |
| `equals2_swf7` | segfault | 32/926 | 926/926 |
| `greater_swf6` | segfault | 32/1175 | 1175/1175 |
| `greater_swf7` | segfault | 32/1175 | 1175/1175 |
| `issue_1671` | segfault | - | 0/0 |
| `lessthan2_swf5` | segfault | 32/1226 | 1226/1226 |
| `lessthan2_swf6` | segfault | 32/1226 | 1226/1226 |
| `lessthan2_swf7` | segfault | 32/1226 | 1226/1226 |
| `object_constructor` | segfault | 10/33 | 33/33 |
| `strictequals_swf6` | segfault | 32/902 | 902/902 |
| `string_coercion` | output_mismatch | 107/117 | 117/117 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `button_keypress_vs_tab` | segfault | output_mismatch | - | 0/20 |
| `tab_ordering_tabbable` | segfault | output_mismatch | - | 0/47 |
| `textfield_cache_as_bitmap` | segfault | output_mismatch | - | 0/1 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mcl_loadclip` | output_mismatch | 8/149 | 25/149 | -17 |
| `array_call_method` | output_mismatch | 0/9 | 0/9 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `path_string` | segfault | 44/322 | 44/322 | 0 |
| `array_sort` | output_mismatch | 112/161 | 111/161 | +1 |
| `duplicate_movie_clip` | output_mismatch | 6/20 | 4/20 | +2 |
| `mcl_getprogress` | output_mismatch | 20/30 | 0/30 | +20 |
