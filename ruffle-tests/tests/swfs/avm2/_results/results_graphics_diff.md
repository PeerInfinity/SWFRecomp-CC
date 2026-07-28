# Ruffle Test Results Diff

**Previous:** `bbefcf37694e` (2026-07-28T21:16:22.811567+00:00)
**Current:** `937047612d70` (2026-07-28T22:42:30.770768+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 900 | 909 | +9 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 73.7% | 74.4% | +0.7% |
| Mismatched lines | 44390 | 44166 | -224 |
|   Decreased | | | -234 |
|   Increased | | | +10 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `air_datagram_socket` | output_mismatch | 0/1 | 1/1 |
| `av_networking_params` | output_mismatch | 0/9 | 9/9 |
| `net_stream_play_options` | output_mismatch | 0/6 | 6/6 |
| `netconnection_close` | output_mismatch | 0/55 | 55/55 |
| `netconnection_properties` | output_mismatch | 0/78 | 78/78 |
| `netstream_client` | output_mismatch | 0/10 | 10/10 |
| `netstream_connect` | output_mismatch | 0/7 | 7/7 |
| `responder_null_callbacks` | output_mismatch | 0/1 | 1/1 |
| `sandbox_type_local_network` | output_mismatch | 0/1 | 1/1 |
| `socket_errors` | output_mismatch | 0/56 | 56/56 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `air_hidden_lookup` | output_mismatch | 2/2 | 1/2 |

## Line Count Changed (12)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `amf_array_serialization` | output_mismatch | 4/17 | 6/17 | -2 |
| `netconnection_send_remote` | output_mismatch | 0/50 | 2/50 | -2 |
| `socket_connect` | output_mismatch | 0/4 | 2/4 | -2 |
| `all_classes/events/swf9` | output_mismatch | 1/1030 | 2/1030 | -1 |
| `netconnection_serialize_arrays` | output_mismatch | 0/6 | 1/6 | -1 |
| `netstream_play_stop_replay` | output_mismatch | 0/11 | 1/11 | -1 |
| `sandbox_type_remote` | output_mismatch | 0/3 | 1/3 | -1 |
| `all_classes/events/swf30` | output_mismatch | 0/2353 | 0/2353 | 0 |
| `netstream_seek_flv` | output_mismatch | 0/49 | 0/49 | 0 |
| `all_classes/events/swf10` | output_mismatch | 4/1638 | 1/1638 | +3 |
| `all_classes/events/swf11` | output_mismatch | 4/1750 | 1/1750 | +3 |
| `all_classes/events/swf12` | output_mismatch | 4/1814 | 1/1814 | +3 |
