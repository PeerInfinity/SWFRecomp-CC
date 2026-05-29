# Ruffle Test Results Diff

**Previous:** `611d2674d88f` (2026-05-29T01:34:46.003681+00:00)
**Current:** `55d725fb0c25` (2026-05-29T23:01:08.845435+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 126 | 130 | +4 |
| Total | 243 | 243 | 0 |
| Pass rate | 51.9% | 53.5% | +1.6% |
| Mismatched lines | 9227 | 8952 | -275 |
|   Decreased | | | -275 |

## Newly Passing (4)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `getvariable-v5` | output_mismatch | 55/58 | 58/58 |
| `getvariable-v6` | ruffle_matched | 61/64 | 64/64 |
| `getvariable-v7` | output_mismatch | 61/64 | 64/64 |
| `getvariable-v8` | output_mismatch | 61/64 | 64/64 |

## Status Changed (4)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `with-v5` | output_mismatch | ruffle_matched | 21/49 | 46/49 |
| `with-v6` | output_mismatch | ruffle_matched | 23/107 | 67/107 |
| `with-v7` | output_mismatch | ruffle_matched | 23/107 | 67/107 |
| `with-v8` | output_mismatch | ruffle_matched | 23/107 | 67/107 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `MovieClip-v6` | output_mismatch | 845/936 | 880/936 | -35 |
| `MovieClip-v7` | output_mismatch | 867/969 | 902/969 | -35 |
| `MovieClip-v8` | output_mismatch | 953/1087 | 988/1087 | -35 |
| `MovieClip-v5` | ruffle_matched | 338/363 | 339/363 | -1 |
