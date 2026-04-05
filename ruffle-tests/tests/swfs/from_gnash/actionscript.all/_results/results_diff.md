# Ruffle Test Results Diff

**Previous:** `bb3378dad6c9` (2026-04-05T05:39:03.070396+00:00)
**Current:** `64854045e7ed` (2026-04-05T18:15:03.514957+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 68 | 74 | +6 |
| Total | 190 | 190 | 0 |
| Pass rate | 35.8% | 38.9% | +3.1% |
| Mismatched lines | 4532 | 4512 | -20 |
|   Decreased | | | -26 |
|   Increased | | | +6 |

## Newly Passing (8)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `AsBroadcaster-v5` | output_mismatch | 8/11 | 11/11 |
| `Key-v5` | output_mismatch | 47/51 | 51/51 |
| `LocalConnection-v5` | output_mismatch | 4/7 | 7/7 |
| `NetConnection-v5` | output_mismatch | 4/7 | 7/7 |
| `Video-v5` | output_mismatch | 4/7 | 7/7 |
| `flash-v5` | output_mismatch | 7/10 | 10/10 |
| `flash-v6` | output_mismatch | 7/10 | 10/10 |
| `flash-v7` | output_mismatch | 7/10 | 10/10 |

## Newly Failing (2)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `Camera-v5` | output_mismatch | 7/7 | 4/7 |
| `TextSnapshot-v5` | output_mismatch | 7/7 | 4/7 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `MovieClip-v5` | output_mismatch | 237/363 | 238/363 | -1 |
