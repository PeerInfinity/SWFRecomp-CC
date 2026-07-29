# Ruffle Test Results Diff

**Previous:** `d01a54495772` (2026-07-28T23:20:22.707960+00:00)
**Current:** `767a301d2bae` (2026-07-29T01:25:01.991409+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 910 | 919 | +9 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 74.5% | 75.3% | +0.8% |
| Mismatched lines | 44165 | 44016 | -149 |
|   Decreased | | | -150 |
|   Increased | | | +1 |

## Newly Passing (9)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `socket_after_disconnect` | output_mismatch | 0/1 | 1/1 |
| `socket_close` | output_mismatch | 0/2 | 2/2 |
| `socket_connect` | output_mismatch | 2/4 | 4/4 |
| `socket_read_big` | output_mismatch | 0/48 | 48/48 |
| `socket_read_little` | output_mismatch | 0/48 | 48/48 |
| `socket_read_write_object` | output_mismatch | 0/8 | 8/8 |
| `socket_write_big` | output_mismatch | 0/15 | 15/15 |
| `socket_write_little` | output_mismatch | 0/14 | 14/14 |
| `xml_socket` | output_mismatch | 0/11 | 11/11 |

## Line Count Changed (5)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 1/2353 | -1 |
| `all_classes/events/swf10` | output_mismatch | 1/1638 | 1/1638 | 0 |
| `all_classes/events/swf11` | output_mismatch | 1/1750 | 1/1750 | 0 |
| `all_classes/events/swf12` | output_mismatch | 1/1814 | 1/1814 | 0 |
| `all_classes/events/swf9` | output_mismatch | 2/1030 | 1/1030 | +1 |
