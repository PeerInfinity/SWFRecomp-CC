# Ruffle Test Results Diff

**Previous:** `16033a154646` (2026-11-25T22:59:03.611788+00:00)
**Current:** `b030ed745d4f` (2026-11-25T23:59:46.704522+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 167 | 177 | +10 |
| Total | 243 | 243 | 0 |
| Pass rate | 68.7% | 72.8% | +4.1% |
| Mismatched lines | 7801 | 7696 | -105 |
|   Decreased | | | -105 |

## Newly Passing (10)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Global-v6` | ruffle_matched | 201/210 | 210/210 |
| `Number-v5` | ruffle_matched | 236/244 | 244/244 |
| `Object-v5` | ruffle_matched | 142/145 | 145/145 |
| `Selection-v6` | ruffle_matched | 118/125 | 125/125 |
| `Selection-v7` | ruffle_matched | 118/125 | 125/125 |
| `Selection-v8` | ruffle_matched | 118/125 | 125/125 |
| `ops-v5` | ruffle_matched | 253/260 | 260/260 |
| `ops-v6` | ruffle_matched | 253/260 | 260/260 |
| `ops-v7` | ruffle_matched | 255/262 | 262/262 |
| `ops-v8` | ruffle_matched | 255/262 | 262/262 |

## Status Changed (5)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | output_mismatch | ruffle_matched | 72/107 | 73/107 |
| `ASnative-v6` | output_mismatch | ruffle_matched | 70/110 | 71/110 |
| `ASnative-v7` | output_mismatch | ruffle_matched | 70/110 | 71/110 |
| `ASnative-v8` | output_mismatch | ruffle_matched | 70/110 | 71/110 |
| `toString_valueOf-v5` | output_mismatch | ruffle_matched | 105/137 | 125/137 |

## Line Count Changed (4)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Function-v5` | ruffle_matched | 148/158 | 154/158 | -6 |
| `String-v5` | ruffle_matched | 340/358 | 344/358 | -4 |
| `Date-v5` | ruffle_matched | 308/315 | 309/315 | -1 |
| `MovieClip-v5` | ruffle_matched | 352/363 | 353/363 | -1 |
