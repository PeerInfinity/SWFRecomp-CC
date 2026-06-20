# Ruffle Test Results Diff

**Previous:** `fe0030e4fc7d` (2026-06-18T22:05:01.962784+00:00)
**Current:** `6e0b2fc8f8b0` (2026-06-20T19:39:30.169730+00:00)
**⚠️ Incomplete run: 29/30 shards produced results (1 missing).** Tests absent from results are likely from failed shards, not intentional removals.

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 101 | 128 | +27 |
| Total | 179 | 235 | +56 |
| Pass rate | 56.4% | 54.5% | -1.9% |
| Mismatched lines | 1851 | 8669 | +6818 |
|   Decreased | | | -97 |

## Added Tests (64)

| Test | Status | Lines |
|------|--------|-------|
| `ContextMenu-v8` | pass | 131/131 |
| `Date-v5` | ruffle_matched | 308/315 |
| `Date-v6` | ruffle_matched | 351/357 |
| `Date-v7` | ruffle_matched | 351/357 |
| `Date-v8` | ruffle_matched | 351/357 |
| `Error-v5` | pass | 28/28 |
| `Error-v6` | pass | 31/31 |
| `Error-v7` | pass | 31/31 |
| `Error-v8` | pass | 31/31 |
| `ExternalInterface-v5` | pass | 7/7 |
| `ExternalInterface-v6` | pass | 55/55 |
| `ExternalInterface-v7` | pass | 55/55 |
| `ExternalInterface-v8` | ruffle_matched | 114/118 |
| `Function-v5` | ruffle_matched | 144/158 |
| `Function-v6` | ruffle_matched | 263/271 |
| `Function-v7` | ruffle_matched | 264/272 |
| `Key-v5` | pass | 51/51 |
| `Key-v6` | pass | 55/55 |
| `Key-v7` | pass | 55/55 |
| `Key-v8` | pass | 55/55 |
| `LoadVars-v5` | pass | 8/8 |
| `LoadVars-v6` | ruffle_matched | 146/152 |
| `LoadVars-v7` | ruffle_matched | 146/152 |
| `LoadVars-v8` | ruffle_matched | 146/152 |
| `Object-v5` | ruffle_matched | 142/145 |
| `Object-v6` | ruffle_matched | 324/333 |
| `Object-v7` | ruffle_matched | 325/333 |
| `Object-v8` | ruffle_matched | 325/333 |
| `Point-v5` | pass | 7/7 |
| `Point-v6` | pass | 7/7 |
| `Point-v7` | pass | 7/7 |
| `Point-v8` | pass | 193/193 |
| `System-v5` | pass | 67/67 |
| `System-v6` | pass | 100/100 |
| `System-v7` | pass | 101/101 |
| `System-v8` | pass | 101/101 |
| `TextField-v5` | ruffle_matched | 9/12 |
| `TextField-v6` | output_mismatch | 463/545 |
| `TextField-v7` | output_mismatch | 472/570 |
| `TextField-v8` | output_mismatch | 474/571 |
| `XML-v5` | ruffle_matched | 439/449 |
| `XML-v6` | ruffle_matched | 483/486 |
| `XML-v7` | ruffle_matched | 483/486 |
| `XML-v8` | ruffle_matched | 462/465 |
| `XMLNode-v5` | ruffle_matched | 204/207 |
| `XMLNode-v6` | ruffle_matched | 204/207 |
| `XMLNode-v7` | ruffle_matched | 204/207 |
| `XMLNode-v8` | ruffle_matched | 204/207 |
| `XMLSocket-v5` | pass | 35/35 |
| `XMLSocket-v6` | pass | 35/35 |
| `XMLSocket-v7` | pass | 35/35 |
| `XMLSocket-v8` | pass | 35/35 |
| `argstest-v5` | pass | 4/4 |
| `argstest-v6` | output_mismatch | 42/2192 |
| `argstest-v7` | output_mismatch | 67/2061 |
| `argstest-v8` | output_mismatch | 58/2434 |
| `flash-v5` | pass | 10/10 |
| `flash-v6` | pass | 10/10 |
| `flash-v7` | pass | 10/10 |
| `flash-v8` | pass | 41/41 |
| `getvariable-v5` | pass | 58/58 |
| `getvariable-v6` | pass | 64/64 |
| `getvariable-v7` | pass | 64/64 |
| `getvariable-v8` | pass | 64/64 |

## Missing Tests — Shard Failure (8)

These tests were in the previous run but absent from this run due to missing shards. This is **not** a regression — the tests were not executed.

- 7 were previously passing
- 1 were previously failing

<details><summary>Show all missing tests</summary>

| Test | Previous Status | Lines |
|------|----------------|-------|
| `Random-v5` | pass | 30/30 |
| `Random-v6` | pass | 30/30 |
| `Random-v7` | pass | 30/30 |
| `Random-v8` | pass | 30/30 |
| `Rectangle-v5` | pass | 7/7 |
| `Rectangle-v6` | pass | 7/7 |
| `Rectangle-v7` | pass | 7/7 |
| `Rectangle-v8` | ruffle_matched | 145/166 |

</details>

## Line Count Changed (7)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `MovieClip-v7` | output_mismatch | 902/969 | 918/969 | -16 |
| `MovieClip-v8` | output_mismatch | 988/1087 | 1004/1087 | -16 |
| `array-v5` | output_mismatch | 536/560 | 552/560 | -16 |
| `array-v6` | output_mismatch | 608/644 | 624/644 | -16 |
| `array-v7` | output_mismatch | 589/654 | 603/654 | -14 |
| `array-v8` | output_mismatch | 589/654 | 603/654 | -14 |
| `MovieClip-v6` | output_mismatch | 880/936 | 885/936 | -5 |
