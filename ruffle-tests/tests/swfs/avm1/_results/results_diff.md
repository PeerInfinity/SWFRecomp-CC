# Ruffle Test Results Diff

**Previous:** `aa4c108d6a4c` (2026-03-31T04:48:25.717834+00:00)
**Current:** `a6a3e688d968` (2026-03-31T18:49:43.401252+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 565 | 569 | +4 |
| Total | 620 | 620 | 0 |
| Pass rate | 91.1% | 91.8% | +0.7% |
| Mismatched lines | 11097 | 10838 | -259 |
|   Decreased | | | -355 |
|   Increased | | | +96 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `netconnection_close` | output_mismatch | 3/39 | 39/39 |
| `sound_duration_position_props` | output_mismatch | 2/290 | 290/290 |
| `sound_load_start` | output_mismatch | 0/3 | 3/3 |
| `sound_multiple_load` | output_mismatch | 0/1 | 1/1 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `global_proto_decls` | output_mismatch | 237/4497 | 250/4497 | -13 |
| `sound_id3_prop` | output_mismatch | 1/138 | 8/138 | -7 |
| `sound_id3` | output_mismatch | 11/633 | 17/633 | -6 |
| `netstream_play_flv` | output_mismatch | 1/21 | 2/21 | -1 |
| `netconnection_send_remote` | output_mismatch | 1/50 | 1/50 | 0 |
| `global_instance_decls` | output_mismatch | 40/758 | 23/758 | +17 |
| `global_proto_decls_delete` | output_mismatch | 255/4158 | 176/4158 | +79 |
