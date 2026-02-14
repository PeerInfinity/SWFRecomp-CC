# Ruffle Test Results Diff

**Previous:** `27050241144c` (2026-02-14T08:00:43.383825+00:00)
**Current:** `c8c38b1895cc` (2026-02-14T19:40:21.130709+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 167 | 180 | +13 |
| Total | 619 | 619 | 0 |
| Pass rate | 27.0% | 29.1% | +2.1% |
| Mismatched lines | 53010 | 52579 | -431 |
|   Decreased | | | -433 |
|   Increased | | | +2 |

## Newly Passing (13)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `xml` | output_mismatch | 1/15 | 15/15 |
| `xml_append_child` | output_mismatch | 16/28 | 28/28 |
| `xml_attributes_read` | output_mismatch | 1/4 | 4/4 |
| `xml_cdata` | output_mismatch | 5/11 | 11/11 |
| `xml_clone_expandos` | output_mismatch | 10/19 | 19/19 |
| `xml_first_last_child` | output_mismatch | 6/8 | 8/8 |
| `xml_has_child_nodes` | output_mismatch | 0/3 | 3/3 |
| `xml_inspect_doctype` | output_mismatch | 1/7 | 7/7 |
| `xml_inspect_xmldecl` | output_mismatch | 1/7 | 7/7 |
| `xml_parent_and_child` | output_mismatch | 3/5 | 5/5 |
| `xml_remove_node` | output_mismatch | 7/22 | 22/22 |
| `xml_siblings` | output_mismatch | 6/10 | 10/10 |
| `xml_to_string_comment` | output_mismatch | 0/1 | 1/1 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `xml_child_nodes_edge_cases` | output_mismatch | runtime_error | 0/4 | 0/4 |
| `xml_namespaces` | output_mismatch | runtime_error | 8/203 | - |
| `xml_to_string` | output_mismatch | runtime_error | 0/13 | - |

## Line Count Changed (15)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `xml_inspect_parsexml` | output_mismatch | 2/62 | 57/62 | -55 |
| `xml_ignore_comments` | output_mismatch | 0/21 | 18/21 | -18 |
| `xml_ignore_white` | output_mismatch | 13/34 | 27/34 | -14 |
| `xml_inspect_createmethods` | output_mismatch | 0/15 | 14/15 | -14 |
| `xml_append_child_with_parent` | output_mismatch | 8/20 | 16/20 | -8 |
| `xml_insert_before` | output_mismatch | 8/20 | 16/20 | -8 |
| `globals_swf5` | output_mismatch | 204/304 | 210/304 | -6 |
| `globals_swf6` | output_mismatch | 211/304 | 217/304 | -6 |
| `globals_swf7` | output_mismatch | 208/304 | 214/304 | -6 |
| `globals_swf8` | output_mismatch | 149/304 | 155/304 | -6 |
| `global_proto_decls` | output_mismatch | 2/4497 | 3/4497 | -1 |
| `global_instance_decls` | output_mismatch | 1/758 | 1/758 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `xml_idmap` | output_mismatch | 2/21 | 0/21 | +2 |
