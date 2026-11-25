# Ruffle Test Results Diff

**Previous:** `10a5b515a03a` (2026-11-25T21:10:43.751034+00:00)
**Current:** `16033a154646` (2026-11-25T22:59:03.465411+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1298 | 1303 | +5 |
| Total | 1346 | 1347 | +1 |
| Pass rate | 96.4% | 96.7% | +0.3% |
| Mismatched lines | 2231 | 1787 | -444 |
|   Decreased | | | -452 |
|   Increased | | | +8 |

## Newly Passing (5)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `int_toexponential` | ruffle_matched | 1139/1215 | 1215/1215 |
| `json_parse_numbers` | ruffle_matched | 127/131 | 131/131 |
| `number_to_string` | ruffle_matched | 249/353 | 353/353 |
| `number_tostring` | output_mismatch | 882/1050 | 1050/1050 |
| `uint_toexponential` | ruffle_matched | 1115/1215 | 1215/1215 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `mouse_pick_avm1_root` | output_mismatch | 2/2 | 1/2 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `enter_frame_non_display_dispatcher` | pass | 23/23 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `avm1_root` | output_mismatch | 12/58 | 5/58 | +7 |
