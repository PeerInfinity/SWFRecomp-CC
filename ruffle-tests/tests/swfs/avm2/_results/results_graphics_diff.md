# Ruffle Test Results Diff

**Previous:** `6de65043250d` (2026-08-06T06:23:32.589933+00:00)
**Current:** `1f8396f5799f` (2026-08-06T10:26:29.668321+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1088 | 1105 | +17 |
| Total | 1226 | 1226 | 0 |
| Pass rate | 88.7% | 90.1% | +1.4% |
| Mismatched lines | 33702 | 32011 | -1691 |
|   Decreased | | | -1694 |
|   Increased | | | +3 |

## Newly Passing (17)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `av_classes` | output_mismatch | 1/340 | 340/340 |
| `avm1movie_addcallback_call` | output_mismatch | 0/14 | 14/14 |
| `currency_parse_result` | output_mismatch | 0/7 | 7/7 |
| `error_stack_trace_edge_cases` | output_mismatch | 0/6 | 6/6 |
| `error_throwerror` | output_mismatch | 6/103 | 103/103 |
| `flash_trace` | output_mismatch | 0/17 | 17/17 |
| `json_stringify_function` | output_mismatch | 0/12 | 12/12 |
| `netfilterevent` | output_mismatch | 0/10 | 10/10 |
| `perspective_projection` | output_mismatch | 1428/1443 | 1443/1443 |
| `primitive_toString` | output_mismatch | 20/277 | 277/277 |
| `primitive_valueOf` | output_mismatch | 25/285 | 285/285 |
| `property_is_enumerable` | output_mismatch | 25/114 | 114/114 |
| `proxy_not_overridden` | output_mismatch | 4/54 | 54/54 |
| `stage_properties2` | output_mismatch | 23/213 | 213/213 |
| `static_length` | output_mismatch | 11/24 | 24/24 |
| `timer_invalid_delay` | output_mismatch | 1/30 | 30/30 |
| `xml_list_ctor_errors` | output_mismatch | 5/34 | 34/34 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `edittext_device_transform_layout` | output_mismatch | ruffle_matched | 236/288 | 268/288 |
| `groupelement_text` | output_mismatch | ruffle_matched | 0/156 | 154/156 |
| `textblock_line_changes` | output_mismatch | ruffle_matched | 166/282 | 240/282 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/events/swf10` | output_mismatch | 3/1638 | 3/1638 | 0 |
| `all_classes/events/swf11` | output_mismatch | 3/1750 | 3/1750 | 0 |
| `all_classes/events/swf12` | output_mismatch | 3/1814 | 3/1814 | 0 |
| `avm1_root` | output_mismatch | 0/58 | 0/58 | 0 |
| `all_classes/events/swf30` | output_mismatch | 1/2353 | 0/2353 | +1 |
| `all_classes/events/swf9` | output_mismatch | 2/1030 | 1/1030 | +1 |
| `textblock_recreateline` | output_mismatch | 40/98 | 39/98 | +1 |
