# Ruffle Test Results Diff

**Previous:** `45164a5b0854` (2026-05-15T03:20:32.456601+00:00)
**Current:** `ef6584787e7e` (2026-05-16T20:55:02.551204+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 126 | 127 | +1 |
| Total | 243 | 243 | 0 |
| Pass rate | 51.9% | 52.3% | +0.4% |
| Mismatched lines | 11121 | 11073 | -48 |
|   Decreased | | | -62 |
|   Increased | | | +14 |

## Newly Passing (1)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `flash-v8` | output_mismatch | 36/41 | 41/41 |

## Status Changed (11)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `Date-v5` | output_mismatch | ruffle_matched | 305/315 | 308/315 |
| `Date-v6` | output_mismatch | ruffle_matched | 348/357 | 351/357 |
| `Date-v7` | output_mismatch | ruffle_matched | 349/357 | 351/357 |
| `Date-v8` | output_mismatch | ruffle_matched | 349/357 | 351/357 |
| `Object-v5` | output_mismatch | ruffle_matched | 135/145 | 142/145 |
| `Sound-v6` | ruffle_matched | output_mismatch | 91/121 | 91/121 |
| `Sound-v7` | ruffle_matched | output_mismatch | 93/121 | 93/121 |
| `Sound-v8` | ruffle_matched | output_mismatch | 93/121 | 93/121 |
| `Stage-v6` | output_mismatch | ruffle_matched | 54/64 | 50/64 |
| `Stage-v7` | output_mismatch | ruffle_matched | 54/64 | 50/64 |
| `Stage-v8` | output_mismatch | ruffle_matched | 54/64 | 50/64 |

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `argstest-v6` | output_mismatch | 44/2192 | 58/2192 | -14 |
| `Object-v6` | output_mismatch | 279/333 | 286/333 | -7 |
| `Object-v7` | output_mismatch | 292/333 | 299/333 | -7 |
| `Object-v8` | output_mismatch | 292/333 | 299/333 | -7 |
| `argstest-v8` | output_mismatch | 46/2434 | 51/2434 | -5 |
| `MovieClip-v7` | output_mismatch | 798/969 | 797/969 | +1 |
| `argstest-v7` | output_mismatch | 46/2061 | 45/2061 | +1 |
