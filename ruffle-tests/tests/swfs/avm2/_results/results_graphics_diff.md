# Ruffle Test Results Diff

**Previous:** `1f8396f5799f` (2026-08-06T10:26:29.668321+00:00)
**Current:** `fb36ba11005c` (2026-08-06T23:55:08.621945+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1105 | 1109 | +4 |
| Total | 1226 | 1226 | 0 |
| Pass rate | 90.1% | 90.5% | +0.4% |
| Mismatched lines | 32011 | 30384 | -1627 |
|   Decreased | | | -1627 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `describe_type_basic` | output_mismatch | 1/152 | 152/152 |
| `describe_type_json` | output_mismatch | 1/301 | 301/301 |
| `error_stack_trace` | output_mismatch | 38/45 | 45/45 |
| `loaderinfo_quine` | output_mismatch | 1/1005 | 1005/1005 |

## Line Count Changed (24)

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
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 11/1030 | -10 |
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
| `all_classes/display3D/swf13` | output_mismatch | 0/326 | 3/326 | -3 |
| `all_classes/errors/swf9` | output_mismatch | 0/121 | 1/121 | -1 |
| `describe_type_native` | output_mismatch | 0/23 | 1/23 | -1 |
| `all_classes/display3D/swf12` | output_mismatch | 1/61 | 1/61 | 0 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
