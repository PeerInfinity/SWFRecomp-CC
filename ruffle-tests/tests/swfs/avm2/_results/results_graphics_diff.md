# Ruffle Test Results Diff

**Previous:** `dfef7a9d6945` (2026-07-27T05:37:49.155062+00:00)
**Current:** `5a7162e20401` (2026-07-27T18:12:25.847587+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 861 | 866 | +5 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 70.5% | 70.9% | +0.4% |
| Mismatched lines | 45922 | 45784 | -138 |
|   Decreased | | | -138 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `displayobject_set_name_loaded` | output_mismatch | 1/3 | 3/3 |
| `edittext_align` | segfault | 60/60 | 60/60 |
| `loader_events` | output_mismatch | 19/92 | 92/92 |
| `loader_loadbytes_events` | output_mismatch | 11/30 | 30/30 |
| `loader_reuse` | output_mismatch | 14/38 | 38/38 |

## Status Changed (2)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `verify_method_info_duplicate` | output_mismatch | compile_fail | 0/2 | - |
| `verify_method_info_oob` | output_mismatch | compile_fail | 0/1 | - |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `displayobject_hittestpoint_root` | output_mismatch | 5/13 | 11/13 | -6 |
| `xml_appendchild_swf_v21` | output_mismatch | 7/13 | 12/13 | -5 |
| `font_registerfont` | output_mismatch | 5/129 | 8/129 | -3 |
| `loader_loaderurl` | output_mismatch | 2/6 | 5/6 | -3 |
| `instantiate_root_character` | output_mismatch | 0/4 | 0/4 | 0 |
