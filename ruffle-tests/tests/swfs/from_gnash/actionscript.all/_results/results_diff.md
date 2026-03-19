# Ruffle Test Results Diff

**Previous:** `ef1e80b3a44d` (2026-03-18T04:04:37.087661+00:00)
**Current:** `ea87da0d59ad` (2026-03-19T01:34:53.084235+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 38 | 44 | +6 |
| Total | 190 | 190 | 0 |
| Pass rate | 20.0% | 23.2% | +3.2% |
| Mismatched lines | 3743 | 6019 | +2276 |
|   Decreased | | | -449 |
|   Increased | | | +2725 |

## Newly Passing (6)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Boolean-v6` | output_mismatch | 35/38 | 38/38 |
| `Boolean-v7` | output_mismatch | 35/38 | 38/38 |
| `Boolean-v8` | output_mismatch | 35/38 | 38/38 |
| `Video-v6` | output_mismatch | 81/85 | 85/85 |
| `Video-v7` | output_mismatch | 81/85 | 85/85 |
| `Video-v8` | output_mismatch | 81/85 | 85/85 |

## Status Changed (38)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `BitmapData-v8` | compile_fail | output_mismatch | - | 219/417 |
| `Global-v6` | compile_fail | output_mismatch | - | 146/210 |
| `Global-v7` | compile_fail | output_mismatch | - | 134/182 |
| `HitTest-v6` | segfault | output_mismatch | 16/88 | 70/88 |
| `HitTest-v7` | segfault | output_mismatch | 16/88 | 70/88 |
| `HitTest-v8` | segfault | output_mismatch | 16/88 | 71/88 |
| `Inheritance-v7` | compile_fail | segfault | - | 74/181 |
| `Inheritance-v8` | compile_fail | segfault | - | 74/181 |
| `Math-v5` | compile_fail | output_mismatch | - | 272/278 |
| `Math-v6` | compile_fail | output_mismatch | - | 272/278 |
| `Math-v7` | compile_fail | output_mismatch | - | 280/287 |
| `Math-v8` | compile_fail | output_mismatch | - | 280/287 |
| `Matrix-v6` | compile_fail | output_mismatch | - | 42/168 |
| `Matrix-v7` | compile_fail | output_mismatch | - | 38/168 |
| `Matrix-v8` | compile_fail | output_mismatch | - | 139/168 |
| `MovieClip-v5` | compile_fail | output_mismatch | - | 228/363 |
| `Number-v5` | compile_fail | output_mismatch | - | 188/244 |
| `Number-v6` | compile_fail | output_mismatch | - | 177/239 |
| `Number-v7` | compile_fail | output_mismatch | - | 182/237 |
| `Number-v8` | compile_fail | output_mismatch | - | 181/237 |
| `Point-v8` | compile_fail | output_mismatch | - | 163/193 |
| `String-v5` | compile_fail | output_mismatch | - | 216/358 |
| `String-v6` | compile_fail | output_mismatch | - | 228/377 |
| `String-v7` | compile_fail | output_mismatch | - | 225/377 |
| `String-v8` | compile_fail | output_mismatch | - | 225/377 |
| `TextSnapshot-v6` | compile_fail | output_mismatch | - | 132/173 |
| `TextSnapshot-v7` | compile_fail | output_mismatch | - | 132/173 |
| `TextSnapshot-v8` | compile_fail | output_mismatch | - | 132/173 |
| `array-v5` | compile_fail | segfault | - | 74/560 |
| `case-v5` | segfault | output_mismatch | 23/39 | 32/39 |
| `case-v6` | segfault | output_mismatch | 18/73 | 18/73 |
| `case-v7` | segfault | output_mismatch | 13/67 | 13/67 |
| `case-v8` | segfault | output_mismatch | 13/67 | 13/67 |
| `ops-v8` | compile_fail | output_mismatch | - | 251/262 |
| `with-v5` | compile_fail | output_mismatch | - | 21/49 |
| `with-v6` | compile_fail | output_mismatch | - | 23/107 |
| `with-v7` | compile_fail | output_mismatch | - | 23/107 |
| `with-v8` | compile_fail | output_mismatch | - | 23/107 |

## Line Count Changed (52)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Rectangle-v8` | output_mismatch | 109/166 | 132/166 | -23 |
| `System-v6` | output_mismatch | 28/100 | 40/100 | -12 |
| `System-v7` | output_mismatch | 28/101 | 40/101 | -12 |
| `System-v8` | output_mismatch | 28/101 | 40/101 | -12 |
| `ColorTransform-v8` | output_mismatch | 34/55 | 45/55 | -11 |
| `ContextMenu-v7` | output_mismatch | 84/131 | 95/131 | -11 |
| `ContextMenu-v8` | output_mismatch | 84/131 | 95/131 | -11 |
| `LoadVars-v6` | output_mismatch | 57/152 | 67/152 | -10 |
| `LoadVars-v7` | output_mismatch | 57/152 | 67/152 | -10 |
| `LoadVars-v8` | output_mismatch | 57/152 | 67/152 | -10 |
| `Inheritance-v6` | output_mismatch | 148/181 | 157/181 | -9 |
| `MovieClipLoader-v7` | output_mismatch | 39/165 | 46/165 | -7 |
| `MovieClipLoader-v8` | output_mismatch | 39/165 | 46/165 | -7 |
| `Color-v6` | output_mismatch | 139/171 | 144/171 | -5 |
| `Color-v7` | output_mismatch | 133/161 | 138/161 | -5 |
| `Color-v8` | output_mismatch | 133/161 | 138/161 | -5 |
| `Microphone-v6` | output_mismatch | 43/79 | 48/79 | -5 |
| `Microphone-v7` | output_mismatch | 43/79 | 48/79 | -5 |
| `Microphone-v8` | output_mismatch | 43/79 | 48/79 | -5 |
| `AsBroadcaster-v6` | output_mismatch | 93/121 | 97/121 | -4 |
| `AsBroadcaster-v7` | output_mismatch | 82/121 | 86/121 | -4 |
| `AsBroadcaster-v8` | output_mismatch | 81/121 | 85/121 | -4 |
| `LocalConnection-v6` | output_mismatch | 20/58 | 24/58 | -4 |
| `LocalConnection-v7` | output_mismatch | 20/58 | 24/58 | -4 |
| `LocalConnection-v8` | output_mismatch | 20/58 | 24/58 | -4 |
| `XMLSocket-v6` | output_mismatch | 27/35 | 31/35 | -4 |
| `XMLSocket-v7` | output_mismatch | 27/35 | 31/35 | -4 |
| `XMLSocket-v8` | output_mismatch | 27/35 | 31/35 | -4 |
| `Error-v6` | output_mismatch | 21/31 | 24/31 | -3 |
| `Error-v7` | output_mismatch | 21/31 | 24/31 | -3 |
| `Error-v8` | output_mismatch | 21/31 | 24/31 | -3 |
| `NetStream-v6` | output_mismatch | 73/80 | 76/80 | -3 |
| `NetStream-v7` | output_mismatch | 73/80 | 76/80 | -3 |
| `NetStream-v8` | output_mismatch | 73/80 | 76/80 | -3 |
| `enumerate-v6` | output_mismatch | 19/49 | 22/49 | -3 |
| `enumerate-v7` | output_mismatch | 19/49 | 22/49 | -3 |
| `enumerate-v8` | output_mismatch | 19/49 | 22/49 | -3 |
| `Inheritance-v5` | output_mismatch | 93/114 | 95/114 | -2 |
| `toString_valueOf-v6` | segfault | 104/155 | 106/155 | -2 |
| `toString_valueOf-v7` | output_mismatch | 110/155 | 112/155 | -2 |
| `toString_valueOf-v8` | output_mismatch | 109/155 | 111/155 | -2 |
| `Color-v5` | output_mismatch | 116/140 | 117/140 | -1 |
| `Key-v6` | output_mismatch | 14/55 | 15/55 | -1 |
| `Key-v7` | output_mismatch | 14/55 | 15/55 | -1 |
| `Key-v8` | output_mismatch | 14/55 | 15/55 | -1 |
| `Mouse-v6` | output_mismatch | 12/21 | 13/21 | -1 |
| `Mouse-v7` | output_mismatch | 12/21 | 13/21 | -1 |
| `Mouse-v8` | output_mismatch | 11/21 | 12/21 | -1 |
| `Selection-v6` | output_mismatch | 107/125 | 108/125 | -1 |
| `Selection-v7` | output_mismatch | 108/125 | 109/125 | -1 |
| `Selection-v8` | output_mismatch | 108/125 | 109/125 | -1 |
| `toString_valueOf-v5` | segfault | 77/137 | 76/137 | +1 |
