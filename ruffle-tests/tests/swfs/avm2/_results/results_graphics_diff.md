# Ruffle Test Results Diff

**Previous:** `c4496a4c8f4b` (2026-08-01T19:38:38.282151+00:00)
**Current:** `6de65043250d` (2026-08-06T06:23:32.589933+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1084 | 1088 | +4 |
| Total | 1224 | 1226 | +2 |
| Pass rate | 88.6% | 88.7% | +0.1% |
| Mismatched lines | 33253 | 33702 | +449 |
|   Decreased | | | -160 |
|   Increased | | | +83 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `constructsuper_null` | output_mismatch | 0/2 | 2/2 |
| `cross_api_version_call_newer` | output_mismatch | 11/12 | 12/12 |
| `doabc_and_symbolclass_script_init_goto` | output_mismatch | 1/7 | 7/7 |
| `doabc_and_symbolclass_script_init_normal` | output_mismatch | 1/6 | 6/6 |
| `graphic_linkage` | output_mismatch | 7/9 | 9/9 |
| `system_exit` | output_mismatch | 0/3 | 3/3 |

## Added Tests (4)

| Test | Status | Lines |
|------|--------|-------|
| `av_classes` | output_mismatch | 1/340 |
| `avm1movie_addcallback_call` | output_mismatch | 0/14 |
| `flash_trace` | output_mismatch | 0/17 |
| `groupelement_text` | output_mismatch | 0/156 |

## Removed Tests (2)

| Test | Previous Status | Lines |
|------|----------------|-------|
| `av_networking_params` | pass | 9/9 |
| `av_tag_data` | pass | 2/2 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `edittext_device_transform_layout` | output_mismatch | 160/288 | 236/288 | -76 |
| `perspective_projection` | output_mismatch | 1368/1443 | 1428/1443 | -60 |
| `delayed_symbolclass` | output_mismatch | 16/28 | 20/28 | -4 |
| `geom_transform` | output_mismatch | 20/74 | 21/74 | -1 |
| `textblock_line_changes` | output_mismatch | 125/158 | 166/282 | +83 |
