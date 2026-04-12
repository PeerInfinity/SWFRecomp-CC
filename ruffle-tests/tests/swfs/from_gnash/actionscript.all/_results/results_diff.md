# Ruffle Test Results Diff

**Previous:** `7cd98a820d18` (2026-04-12T20:05:04.702871+00:00)
**Current:** `3e6993b0e763` (2026-04-12T20:39:30.032672+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 84 | 92 | +8 |
| Total | 190 | 190 | 0 |
| Pass rate | 44.2% | 48.4% | +4.2% |
| Mismatched lines | 4315 | 4090 | -225 |
|   Decreased | | | -231 |
|   Increased | | | +6 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `AsBroadcaster-v5` | output_mismatch | 8/11 | 11/11 |
| `Color-v5` | output_mismatch | 124/140 | 140/140 |
| `Color-v6` | output_mismatch | 156/171 | 171/171 |
| `LocalConnection-v6` | output_mismatch | 52/58 | 58/58 |
| `NetStream-v6` | output_mismatch | 73/80 | 80/80 |
| `Video-v6` | output_mismatch | 79/85 | 85/85 |
| `XMLSocket-v5` | output_mismatch | 25/35 | 35/35 |
| `XMLSocket-v6` | output_mismatch | 25/35 | 35/35 |

## Line Count Changed (14)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `AsBroadcaster-v6` | output_mismatch | 28/121 | 98/121 | -70 |
| `TextSnapshot-v6` | output_mismatch | 97/173 | 132/173 | -35 |
| `LoadVars-v6` | output_mismatch | 55/152 | 67/152 | -12 |
| `Sound-v5` | output_mismatch | 65/100 | 77/100 | -12 |
| `Sound-v6` | output_mismatch | 64/121 | 76/121 | -12 |
| `Microphone-v6` | output_mismatch | 38/79 | 48/79 | -10 |
| `Inheritance-v5` | output_mismatch | 96/114 | 98/114 | -2 |
| `Inheritance-v6` | output_mismatch | 163/181 | 165/181 | -2 |
| `toString_valueOf-v6` | output_mismatch | 132/155 | 134/155 | -2 |
| `Camera-v6` | output_mismatch | 32/90 | 33/90 | -1 |
| `ASnative-v5` | output_mismatch | 27/107 | 26/107 | +1 |
| `ASnative-v6` | output_mismatch | 25/110 | 24/110 | +1 |
| `Instance-v5` | output_mismatch | 28/52 | 26/52 | +2 |
| `Instance-v6` | output_mismatch | 29/52 | 27/52 | +2 |
