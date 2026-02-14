# Ruffle Test Results Diff

**Previous:** `c8c38b1895cc` (2026-02-14T19:40:21.130709+00:00)
**Current:** `73a7b457723b` (2026-02-14T20:35:19.182692+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 180 | 173 | -7 |
| Total | 619 | 619 | 0 |
| Pass rate | 29.1% | 27.9% | -1.2% |
| Mismatched lines | 52579 | 62255 | +9676 |
|   Decreased | | | -136 |
|   Increased | | | +9812 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `xml_append_child_with_parent` | output_mismatch | 16/20 | 20/20 |
| `xml_idmap` | output_mismatch | 0/21 | 21/21 |
| `xml_ignore_white` | output_mismatch | 27/34 | 34/34 |
| `xml_insert_before` | output_mismatch | 16/20 | 20/20 |
| `xml_inspect_createmethods` | output_mismatch | 14/15 | 15/15 |
| `xml_inspect_parsexml` | output_mismatch | 57/62 | 62/62 |

## Newly Failing (13)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `add2` | output_mismatch | 354/354 | 31/354 |
| `equals2_swf5` | segfault | 926/926 | 32/926 |
| `equals2_swf6` | segfault | 926/926 | 32/926 |
| `equals2_swf7` | segfault | 926/926 | 32/926 |
| `greater_swf6` | segfault | 1175/1175 | 32/1175 |
| `greater_swf7` | segfault | 1175/1175 | 32/1175 |
| `issue_1671` | segfault | 0/0 | - |
| `lessthan2_swf5` | segfault | 1226/1226 | 32/1226 |
| `lessthan2_swf6` | segfault | 1226/1226 | 32/1226 |
| `lessthan2_swf7` | segfault | 1226/1226 | 32/1226 |
| `object_constructor` | segfault | 33/33 | 10/33 |
| `strictequals_swf6` | segfault | 902/902 | 32/902 |
| `string_coercion` | output_mismatch | 117/117 | 107/117 |

## Status Changed (6)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `button_keypress_vs_tab` | output_mismatch | segfault | 0/20 | - |
| `tab_ordering_tabbable` | output_mismatch | segfault | 0/47 | - |
| `textfield_cache_as_bitmap` | output_mismatch | segfault | 0/1 | - |
| `xml_child_nodes_edge_cases` | runtime_error | output_mismatch | 0/4 | 3/4 |
| `xml_namespaces` | runtime_error | output_mismatch | - | 187/203 |
| `xml_to_string` | runtime_error | output_mismatch | - | 11/13 |

## Line Count Changed (8)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `mcl_getprogress` | output_mismatch | 0/30 | 20/30 | -20 |
| `duplicate_movie_clip` | output_mismatch | 4/20 | 6/20 | -2 |
| `array_sort` | output_mismatch | 111/161 | 112/161 | -1 |
| `array_call_method` | output_mismatch | 0/9 | 0/9 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `path_string` | segfault | 44/322 | 44/322 | 0 |
| `global_proto_decls` | output_mismatch | 3/4497 | 2/4497 | +1 |
| `mcl_loadclip` | output_mismatch | 25/149 | 8/149 | +17 |
