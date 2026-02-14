# Ruffle Test Results Diff

**Previous:** `34aa7dfded11` (2026-02-14T02:59:32.030487+00:00)
**Current:** `88113607f20c` (2026-02-14T04:37:59.848113+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 155 | 158 | +3 |
| Total | 619 | 619 | 0 |
| Pass rate | 25.0% | 25.5% | +0.5% |
| Mismatched lines | 56749 | 56048 | -701 |
|   Decreased | | | -702 |
|   Increased | | | +1 |

## Newly Passing (3)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `textfield_props_swf6` | output_mismatch | 37/210 | 210/210 |
| `textfield_props_swf7` | output_mismatch | 36/210 | 210/210 |
| `textfield_props_swf8` | output_mismatch | 36/210 | 210/210 |

## Line Count Changed (19)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `tab_ordering_properties` | output_mismatch | 5/293 | 156/293 | -151 |
| `textfield_props_swf5` | output_mismatch | 37/175 | 42/175 | -5 |
| `edittext_html_swf6` | output_mismatch | 2013/5377 | 2016/5377 | -3 |
| `edittext_html_swf7` | output_mismatch | 1377/5377 | 1380/5377 | -3 |
| `edittext_html_swf8` | output_mismatch | 1362/5377 | 1365/5377 | -3 |
| `globals_swf6` | output_mismatch | 205/304 | 208/304 | -3 |
| `globals_swf7` | output_mismatch | 202/304 | 205/304 | -3 |
| `globals_swf8` | output_mismatch | 143/304 | 146/304 | -3 |
| `edittext_scroll` | output_mismatch | 33/54 | 35/54 | -2 |
| `focusrect_property_swf6` | output_mismatch | 210/1237 | 211/1237 | -1 |
| `focusrect_property_swf7` | output_mismatch | 209/1237 | 210/1237 | -1 |
| `globals_swf5` | output_mismatch | 200/304 | 201/304 | -1 |
| `stage_object_enumerate` | output_mismatch | 0/4 | 1/4 | -1 |
| `textfield_variable` | output_mismatch | 53/81 | 54/81 | -1 |
| `device_font_spacing` | segfault | 1/91 | 1/91 | 0 |
| `global_proto_decls` | output_mismatch | 2/4497 | 2/4497 | 0 |
| `global_proto_decls_delete` | output_mismatch | 0/4158 | 0/4158 | 0 |
| `goto_methods` | segfault | 8/40 | 8/40 | 0 |
| `focusrect_property_swf5` | output_mismatch | 210/1237 | 209/1237 | +1 |
