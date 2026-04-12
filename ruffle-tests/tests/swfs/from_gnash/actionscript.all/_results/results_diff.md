# Ruffle Test Results Diff

**Previous:** `13565deb31b3` (2026-04-12T18:23:47.951449+00:00)
**Current:** `7cd98a820d18` (2026-04-12T20:05:04.702871+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 94 | 84 | -10 |
| Total | 190 | 190 | 0 |
| Pass rate | 49.5% | 44.2% | -5.3% |
| Mismatched lines | 4083 | 4315 | +232 |
|   Decreased | | | -10 |
|   Increased | | | +242 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `delete-v6` | output_mismatch | 56/60 | 60/60 |

## Newly Failing (11)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `AsBroadcaster-v5` | output_mismatch | 11/11 | 8/11 |
| `Color-v5` | output_mismatch | 140/140 | 124/140 |
| `Color-v6` | output_mismatch | 171/171 | 156/171 |
| `LocalConnection-v5` | output_mismatch | 7/7 | 4/7 |
| `LocalConnection-v6` | output_mismatch | 58/58 | 52/58 |
| `NetConnection-v5` | output_mismatch | 7/7 | 4/7 |
| `NetStream-v6` | output_mismatch | 80/80 | 73/80 |
| `Video-v5` | output_mismatch | 7/7 | 4/7 |
| `Video-v6` | output_mismatch | 85/85 | 79/85 |
| `XMLSocket-v5` | output_mismatch | 35/35 | 25/35 |
| `XMLSocket-v6` | output_mismatch | 35/35 | 25/35 |

## Line Count Changed (17)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Instance-v5` | output_mismatch | 26/52 | 28/52 | -2 |
| `Instance-v6` | output_mismatch | 27/52 | 29/52 | -2 |
| `ASnative-v5` | output_mismatch | 26/107 | 27/107 | -1 |
| `ASnative-v6` | output_mismatch | 24/110 | 25/110 | -1 |
| `targetPath-v6` | output_mismatch | 9/23 | 9/23 | 0 |
| `with-v6` | output_mismatch | 23/107 | 23/107 | 0 |
| `Camera-v6` | output_mismatch | 33/90 | 32/90 | +1 |
| `Inheritance-v5` | output_mismatch | 98/114 | 96/114 | +2 |
| `Inheritance-v6` | output_mismatch | 165/181 | 163/181 | +2 |
| `array-v5` | output_mismatch | 459/560 | 457/560 | +2 |
| `toString_valueOf-v6` | output_mismatch | 134/155 | 132/155 | +2 |
| `Microphone-v6` | output_mismatch | 48/79 | 38/79 | +10 |
| `LoadVars-v6` | output_mismatch | 67/152 | 55/152 | +12 |
| `Sound-v5` | output_mismatch | 77/100 | 65/100 | +12 |
| `Sound-v6` | output_mismatch | 76/121 | 64/121 | +12 |
| `TextSnapshot-v6` | output_mismatch | 132/173 | 97/173 | +35 |
| `AsBroadcaster-v6` | output_mismatch | 98/121 | 28/121 | +70 |
