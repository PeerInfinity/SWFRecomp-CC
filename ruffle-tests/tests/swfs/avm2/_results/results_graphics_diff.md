# Ruffle Test Results Diff

**Previous:** `6a07045c4406` (2026-07-30T00:01:22.485822+00:00)
**Current:** `a584ada71e19` (2026-07-30T00:38:00.944629+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 930 | 932 | +2 |
| Total | 1221 | 1221 | 0 |
| Pass rate | 76.2% | 76.3% | +0.1% |
| Mismatched lines | 43863 | 43810 | -53 |
|   Decreased | | | -53 |

## Newly Passing (2)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `netconnection_send_remote` | output_mismatch | 2/50 | 50/50 |
| `netconnection_serialize_arrays` | output_mismatch | 1/6 | 6/6 |

## Line Count Changed (2)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `amf_array_serialization` | output_mismatch | 6/17 | 6/17 | 0 |
| `localconnection` | output_mismatch | 67/890 | 67/890 | 0 |
