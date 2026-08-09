# Ruffle Test Results Diff

**Previous:** `b4c983ea4c3d` (2026-08-02T09:26:35.614573+00:00)
**Current:** `0a99be1a92de` (2026-08-09T08:51:22.890105+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1084 | 1109 | +25 |
| Total | 1225 | 1227 | +2 |
| Pass rate | 88.5% | 90.4% | +1.9% |
| Mismatched lines | 33409 | 30505 | -2904 |
|   Decreased | | | -3036 |
|   Increased | | | +11 |

## Newly Passing (24)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `constructsuper_null` | output_mismatch | 0/2 | 2/2 |
| `cross_api_version_call_newer` | output_mismatch | 11/12 | 12/12 |
| `currency_parse_result` | output_mismatch | 0/7 | 7/7 |
| `describe_type_basic` | output_mismatch | 1/152 | 152/152 |
| `describe_type_json` | output_mismatch | 1/301 | 301/301 |
| `doabc_and_symbolclass_script_init_goto` | output_mismatch | 1/7 | 7/7 |
| `doabc_and_symbolclass_script_init_normal` | output_mismatch | 1/6 | 6/6 |
| `error_stack_trace` | output_mismatch | 38/45 | 45/45 |
| `error_stack_trace_edge_cases` | output_mismatch | 0/6 | 6/6 |
| `error_throwerror` | output_mismatch | 6/103 | 103/103 |
| `graphic_linkage` | output_mismatch | 7/9 | 9/9 |
| `json_stringify_function` | output_mismatch | 0/12 | 12/12 |
| `loaderinfo_quine` | output_mismatch | 1/1005 | 1005/1005 |
| `netfilterevent` | output_mismatch | 0/10 | 10/10 |
| `perspective_projection` | output_mismatch | 1368/1443 | 1443/1443 |
| `primitive_toString` | output_mismatch | 20/277 | 277/277 |
| `primitive_valueOf` | output_mismatch | 25/285 | 285/285 |
| `property_is_enumerable` | output_mismatch | 25/114 | 114/114 |
| `proxy_not_overridden` | output_mismatch | 4/54 | 54/54 |
| `stage_properties2` | output_mismatch | 23/213 | 213/213 |
| `static_length` | output_mismatch | 11/24 | 24/24 |
| `system_exit` | output_mismatch | 0/3 | 3/3 |
| `timer_invalid_delay` | output_mismatch | 1/30 | 30/30 |
| `xml_list_ctor_errors` | output_mismatch | 5/34 | 34/34 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_device_transform_layout` | output_mismatch | ruffle_matched | 160/288 | 268/288 |
| `groupelement_text` | output_mismatch | ruffle_matched | 0/156 | 154/156 |
| `textblock_line_changes` | output_mismatch | ruffle_matched | 125/158 | 240/282 |

## Added Tests (4)

| Test | Status | Lines |
|------|--------|-------|
| `automation_classes` | output_mismatch | 1/122 |
| `av_classes` | pass | 340/340 |
| `avm1movie_addcallback_call` | pass | 14/14 |
| `flash_trace` | pass | 17/17 |

## Removed Tests (2)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `av_networking_params` | pass | 9/9 |
| `av_tag_data` | pass | 2/2 |

## Line Count Changed (28)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/display/swf11` | output_mismatch | 1/2593 | 15/2593 | -14 |
| `all_classes/display/swf12` | output_mismatch | 1/2593 | 15/2593 | -14 |
| `all_classes/display/swf10` | output_mismatch | 1/2569 | 12/2569 | -11 |
| `all_classes/display/swf13` | output_mismatch | 1/2671 | 12/2671 | -11 |
| `all_classes/display3D/swf30` | output_mismatch | 1/412 | 12/412 | -11 |
| `all_classes/events/swf10` | output_mismatch | 3/1638 | 13/1638 | -10 |
| `all_classes/events/swf11` | output_mismatch | 3/1750 | 13/1750 | -10 |
| `all_classes/events/swf12` | output_mismatch | 3/1814 | 13/1814 | -10 |
| `all_classes/events/swf9` | output_mismatch | 2/1030 | 11/1030 | -9 |
| `all_classes/xml/swf30` | output_mismatch | 0/116 | 9/116 | -9 |
| `all_classes/xml/swf9` | output_mismatch | 0/116 | 9/116 | -9 |
| `all_classes/display/swf30` | output_mismatch | 1/2936 | 7/2936 | -6 |
| `all_classes/display/swf9` | output_mismatch | 1/1959 | 7/1959 | -6 |
| `all_classes/errors/swf10` | output_mismatch | 0/140 | 6/140 | -6 |
| `all_classes/errors/swf30` | output_mismatch | 0/140 | 6/140 | -6 |
| `describe_type_metadata` | output_mismatch | 0/125 | 5/125 | -5 |
| `all_classes/accessibility/swf10` | output_mismatch | 1/88 | 5/88 | -4 |
| `all_classes/accessibility/swf30` | output_mismatch | 1/88 | 5/88 | -4 |
| `all_classes/accessibility/swf9` | output_mismatch | 1/73 | 5/73 | -4 |
| `delayed_symbolclass` | output_mismatch | 16/28 | 20/28 | -4 |
| `all_classes/display3D/swf13` | output_mismatch | 0/326 | 3/326 | -3 |
| `all_classes/errors/swf9` | output_mismatch | 0/121 | 1/121 | -1 |
| `describe_type_native` | output_mismatch | 0/23 | 1/23 | -1 |
| `geom_transform` | output_mismatch | 20/74 | 21/74 | -1 |
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 1/61 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `all_classes/events/swf30` | output_mismatch | 1/2353 | 0/2353 | +1 |
| `textblock_recreateline` | output_mismatch | 40/98 | 39/98 | +1 |
