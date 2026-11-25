# Ruffle Test Results Diff

**Previous:** `13b40eabb012` (2026-11-25T20:23:11.932228+00:00)
**Current:** `10a5b515a03a` (2026-11-25T21:42:12.151468+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 148 | 167 | +19 |
| Total | 243 | 243 | 0 |
| Pass rate | 60.9% | 68.7% | +7.8% |
| Mismatched lines | 7913 | 7801 | -112 |
|   Decreased | | | -112 |

## Newly Passing (19)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `HitTest-v6` | ruffle_matched | 80/88 | 88/88 |
| `HitTest-v7` | ruffle_matched | 80/88 | 88/88 |
| `String-v6` | ruffle_matched | 368/377 | 377/377 |
| `String-v7` | ruffle_matched | 368/377 | 377/377 |
| `String-v8` | ruffle_matched | 368/377 | 377/377 |
| `TextField-v5` | ruffle_matched | 9/12 | 12/12 |
| `XML-v6` | ruffle_matched | 483/486 | 486/486 |
| `XML-v7` | ruffle_matched | 483/486 | 486/486 |
| `XMLNode-v5` | ruffle_matched | 204/207 | 207/207 |
| `XMLNode-v6` | ruffle_matched | 204/207 | 207/207 |
| `XMLNode-v7` | ruffle_matched | 204/207 | 207/207 |
| `XMLNode-v8` | ruffle_matched | 204/207 | 207/207 |
| `toString_valueOf-v6` | ruffle_matched | 150/155 | 155/155 |
| `toString_valueOf-v7` | ruffle_matched | 150/155 | 155/155 |
| `toString_valueOf-v8` | ruffle_matched | 150/155 | 155/155 |
| `with-v5` | ruffle_matched | 46/49 | 49/49 |
| `with-v6` | ruffle_matched | 101/107 | 107/107 |
| `with-v7` | ruffle_matched | 101/107 | 107/107 |
| `with-v8` | ruffle_matched | 101/107 | 107/107 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | ruffle_matched | output_mismatch | 72/107 | 72/107 |
| `ASnative-v6` | ruffle_matched | output_mismatch | 70/110 | 70/110 |
| `ASnative-v7` | ruffle_matched | output_mismatch | 70/110 | 70/110 |
| `ASnative-v8` | ruffle_matched | output_mismatch | 70/110 | 70/110 |
| `toString_valueOf-v5` | ruffle_matched | output_mismatch | 103/137 | 105/137 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `HitTest-v8` | ruffle_matched | 79/88 | 85/88 | -6 |
| `XML-v8` | ruffle_matched | 462/465 | 465/465 | -3 |
| `XML-v5` | ruffle_matched | 439/449 | 440/449 | -1 |
