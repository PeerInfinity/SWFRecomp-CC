# Ruffle Test Results Diff

**Previous:** `be9aafd78ec0` (2026-05-16T21:06:43.860062+00:00)
**Current:** `6fe6fb1a2f62` (2026-05-24T23:52:34.212383+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 127 | 126 | -1 |
| Total | 243 | 243 | 0 |
| Pass rate | 52.3% | 51.9% | -0.4% |
| Mismatched lines | 11073 | 9227 | -1846 |
|   Decreased | | | -1862 |
|   Increased | | | +16 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `case-v5` | runtime_error | 39/39 | 39/39 |

## Status Changed (28)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `Function-v5` | output_mismatch | ruffle_matched | 135/158 | 144/158 |
| `Function-v6` | output_mismatch | ruffle_matched | 181/271 | 263/271 |
| `Function-v7` | output_mismatch | ruffle_matched | 205/272 | 264/272 |
| `Function-v8` | output_mismatch | ruffle_matched | 205/272 | 264/272 |
| `NetConnection-v6` | output_mismatch | ruffle_matched | 71/126 | 122/126 |
| `NetConnection-v7` | output_mismatch | ruffle_matched | 75/126 | 122/126 |
| `NetConnection-v8` | output_mismatch | ruffle_matched | 75/126 | 122/126 |
| `Object-v6` | output_mismatch | ruffle_matched | 286/333 | 324/333 |
| `Object-v7` | output_mismatch | ruffle_matched | 299/333 | 325/333 |
| `Object-v8` | output_mismatch | ruffle_matched | 299/333 | 325/333 |
| `Sound-v6` | output_mismatch | ruffle_matched | 91/121 | 113/121 |
| `Sound-v7` | output_mismatch | ruffle_matched | 93/121 | 113/121 |
| `Sound-v8` | output_mismatch | ruffle_matched | 93/121 | 113/121 |
| `TextFormat-v8` | output_mismatch | ruffle_matched | 128/172 | 136/172 |
| `Transform-v8` | output_mismatch | ruffle_matched | 71/101 | 94/101 |
| `XML-v5` | output_mismatch | ruffle_matched | 281/449 | 439/449 |
| `XML-v6` | output_mismatch | ruffle_matched | 288/486 | 483/486 |
| `XML-v7` | output_mismatch | ruffle_matched | 288/486 | 483/486 |
| `XML-v8` | output_mismatch | ruffle_matched | 288/465 | 462/465 |
| `XMLNode-v5` | output_mismatch | ruffle_matched | 174/207 | 204/207 |
| `XMLNode-v6` | output_mismatch | ruffle_matched | 174/207 | 204/207 |
| `XMLNode-v7` | output_mismatch | ruffle_matched | 174/207 | 204/207 |
| `XMLNode-v8` | output_mismatch | ruffle_matched | 174/207 | 204/207 |
| `getvariable-v6` | output_mismatch | ruffle_matched | 48/64 | 61/64 |
| `with-v5` | ruffle_matched | output_mismatch | 21/49 | 21/49 |
| `with-v6` | ruffle_matched | output_mismatch | 23/107 | 23/107 |
| `with-v7` | ruffle_matched | output_mismatch | 23/107 | 23/107 |
| `with-v8` | ruffle_matched | output_mismatch | 23/107 | 23/107 |

## Line Count Changed (17)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `MovieClip-v7` | output_mismatch | 798/969 | 867/969 | -69 |
| `MovieClip-v6` | output_mismatch | 777/936 | 845/936 | -68 |
| `MovieClip-v8` | output_mismatch | 885/1087 | 953/1087 | -68 |
| `TextField-v6` | output_mismatch | 404/545 | 456/545 | -52 |
| `TextField-v8` | output_mismatch | 415/571 | 467/571 | -52 |
| `TextField-v7` | output_mismatch | 414/570 | 465/570 | -51 |
| `MovieClip-v5` | ruffle_matched | 315/363 | 338/363 | -23 |
| `argstest-v7` | output_mismatch | 45/2061 | 67/2061 | -22 |
| `getvariable-v7` | output_mismatch | 49/64 | 61/64 | -12 |
| `getvariable-v8` | output_mismatch | 49/64 | 61/64 | -12 |
| `Sound-v5` | ruffle_matched | 73/100 | 84/100 | -11 |
| `getvariable-v5` | output_mismatch | 44/58 | 55/58 | -11 |
| `argstest-v8` | output_mismatch | 51/2434 | 58/2434 | -7 |
| `array-v6` | output_mismatch | 604/644 | 608/644 | -4 |
| `array-v7` | output_mismatch | 585/654 | 589/654 | -4 |
| `array-v8` | output_mismatch | 585/654 | 589/654 | -4 |
| `argstest-v6` | output_mismatch | 58/2192 | 42/2192 | +16 |
