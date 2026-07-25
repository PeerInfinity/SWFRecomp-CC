# Ruffle Test Results Diff

**Previous:** `17c19040c9cd` (2026-07-24T23:01:01.212550+00:00)
**Current:** `da35e5d771bb` (2026-07-25T00:20:13.948262+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 619 | 637 | +18 |
| Total | 693 | 716 | +23 |
| Pass rate | 89.3% | 89.0% | -0.3% |
| Mismatched lines | 12540 | 15348 | +2808 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `array_shift` | timeout | - | 216/216 |

## Added Tests (23)

| Test | Status | Lines |
|------|--------|-------|
| `watch` | pass | 117/117 |
| `watch_infinite_recursion` | pass | 1/1 |
| `watch_proto_recursion` | pass | 1/1 |
| `watch_recursion_double_swf6` | ruffle_matched | 18/46 |
| `watch_recursion_double_swf7` | output_mismatch | 409/3118 |
| `watch_recursion_swf6` | ruffle_matched | 12/18 |
| `watch_recursion_swf7` | output_mismatch | 1036/1042 |
| `watch_textfield` | pass | 12/12 |
| `watch_virtual_property` | output_mismatch | 9/60 |
| `watch_virtual_property_proto` | pass | 2/2 |
| `with` | pass | 46/46 |
| `with_return` | pass | 2/2 |
| `with_variable_scopes` | pass | 43/43 |
| `xml` | pass | 15/15 |
| `xml_append_child` | pass | 28/28 |
| `xml_append_child_with_parent` | pass | 20/20 |
| `xml_attributes_read` | pass | 4/4 |
| `xml_cdata` | pass | 11/11 |
| `xml_child_nodes_edge_cases` | pass | 4/4 |
| `xml_clone_expandos` | pass | 19/19 |
| `xml_first_last_child` | pass | 8/8 |
| `xml_getbytes` | output_mismatch | 9/17 |
| `xml_has_child_nodes` | pass | 3/3 |
