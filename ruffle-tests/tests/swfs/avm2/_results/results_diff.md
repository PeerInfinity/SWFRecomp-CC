# Ruffle Test Results Diff

**Previous:** `b5695059b2cd` (2026-07-13T05:09:06.996464+00:00)
**Current:** `278cc359c409` (2026-07-13T16:41:32.736065+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 819 | 824 | +5 |
| Total | 1204 | 1204 | 0 |
| Pass rate | 68.0% | 68.4% | +0.4% |
| Mismatched lines | 47838 | 47734 | -104 |
|   Decreased | | | -109 |
|   Increased | | | +5 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `loaderinfo_properties` | output_mismatch | 1/18 | 18/18 |
| `loaderinfo_root` | output_mismatch | 3/10 | 10/10 |
| `loaderinfo_root_allows` | output_mismatch | 0/2 | 2/2 |
| `sandbox_type_local_file` | output_mismatch | 0/1 | 1/1 |
| `urlrequest` | output_mismatch | 0/18 | 18/18 |

## Line Count Changed (27)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `stage_loaderinfo_properties` | output_mismatch | 1/24 | 22/24 | -21 |
| `navigateToURL_target_normalize` | output_mismatch | 1/107 | 6/107 | -5 |
| `loader_method` | output_mismatch | 0/83 | 4/83 | -4 |
| `loaderinfo_events` | output_mismatch | 0/7 | 4/7 | -4 |
| `net_navigateToURL` | output_mismatch | 0/57 | 4/57 | -4 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 4/1638 | -3 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 4/1750 | -3 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 4/1814 | -3 |
| `delayed_symbolclass` | output_mismatch | 0/28 | 3/28 | -3 |
| `loader_load` | output_mismatch | 0/126 | 3/126 | -3 |
| `sound_rootless` | output_mismatch | 2/7 | 5/7 | -3 |
| `loader_loaderurl` | output_mismatch | 0/6 | 2/6 | -2 |
| `sound_constructor_with_args` | output_mismatch | 0/6 | 2/6 | -2 |
| `sound_load_multiple` | output_mismatch | 1/19 | 3/19 | -2 |
| `sandbox_type_inherited` | output_mismatch | 0/2 | 1/2 | -1 |
| `url_vars` | output_mismatch | 0/27 | 1/27 | -1 |
| `all_classes/display/swf30` | output_mismatch | 0/2936 | 0/2936 | 0 |
| `all_classes/display/swf9` | output_mismatch | 1/1959 | 1/1959 | 0 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
| `sandbox_type_local_network` | output_mismatch | 0/1 | 0/1 | 0 |
| `sandbox_type_remote` | output_mismatch | 0/3 | 0/3 | 0 |
| `stage_domain_getQualifiedDefinitionNames` | output_mismatch | 0/5 | 0/5 | 0 |
| `all_classes/display/swf10` | output_mismatch | 2/2569 | 1/2569 | +1 |
| `all_classes/display/swf11` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf12` | output_mismatch | 2/2593 | 1/2593 | +1 |
| `all_classes/display/swf13` | output_mismatch | 2/2671 | 1/2671 | +1 |
| `all_classes/events/swf9` | output_mismatch | 2/1030 | 1/1030 | +1 |
