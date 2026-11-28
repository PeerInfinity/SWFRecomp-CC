# Ruffle Test Results Diff

**Previous:** `0224aaf25632` (2026-11-27T22:24:41.216737+00:00)
**Current:** `b8671fd2f516` (2026-11-28T02:31:31.833173+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 181 | 193 | +12 |
| Total | 243 | 243 | 0 |
| Pass rate | 74.5% | 79.4% | +4.9% |
| Mismatched lines | 7550 | 7424 | -126 |
|   Decreased | | | -255 |
|   Increased | | | +129 |

## Newly Passing (12)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `ExternalInterface-v8` | ruffle_matched | 115/118 | 118/118 |
| `LoadVars-v6` | ruffle_matched | 146/152 | 152/152 |
| `LoadVars-v7` | ruffle_matched | 146/152 | 152/152 |
| `LoadVars-v8` | ruffle_matched | 146/152 | 152/152 |
| `Object-v6` | ruffle_matched | 325/333 | 333/333 |
| `Object-v7` | ruffle_matched | 325/333 | 333/333 |
| `Object-v8` | ruffle_matched | 325/333 | 333/333 |
| `Sound-v5` | ruffle_matched | 86/100 | 100/100 |
| `setProperty-v5` | ruffle_matched | 3/52 | 52/52 |
| `setProperty-v6` | ruffle_matched | 3/52 | 52/52 |
| `setProperty-v7` | ruffle_matched | 3/52 | 52/52 |
| `setProperty-v8` | ruffle_matched | 3/52 | 52/52 |

## Line Count Changed (3)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `argstest-v7` | output_mismatch | 93/2061 | 71/2061 | +22 |
| `argstest-v6` | output_mismatch | 110/2192 | 75/2192 | +35 |
| `argstest-v8` | output_mismatch | 144/2434 | 72/2434 | +72 |
