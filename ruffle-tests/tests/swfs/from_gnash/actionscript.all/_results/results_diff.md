# Ruffle Test Results Diff

**Previous:** `13fe9441a428` (2026-05-20T03:45:19.677149+00:00)
**Current:** `3fe53f7a7328` (2026-05-20T03:59:43.529514+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 132 | 128 | -4 |
| Total | 243 | 243 | 0 |
| Pass rate | 54.3% | 52.7% | -1.6% |
| Mismatched lines | 10872 | 10863 | -9 |
|   Decreased | | | -21 |
|   Increased | | | +12 |

## Newly Failing (4)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `getvariable-v5` | output_mismatch | 58/58 | 55/58 |
| `getvariable-v6` | ruffle_matched | 64/64 | 61/64 |
| `getvariable-v7` | output_mismatch | 64/64 | 61/64 |
| `getvariable-v8` | output_mismatch | 64/64 | 61/64 |

## Status Changed (1)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `MovieClip-v5` | output_mismatch | ruffle_matched | 311/363 | 315/363 |

## Line Count Changed (6)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `MovieClip-v6` | output_mismatch | 773/936 | 777/936 | -4 |
| `MovieClip-v7` | output_mismatch | 794/969 | 798/969 | -4 |
| `MovieClip-v8` | output_mismatch | 881/1087 | 885/1087 | -4 |
| `TextField-v7` | output_mismatch | 412/570 | 414/570 | -2 |
| `TextField-v8` | output_mismatch | 414/571 | 416/571 | -2 |
| `TextField-v6` | output_mismatch | 403/545 | 404/545 | -1 |
