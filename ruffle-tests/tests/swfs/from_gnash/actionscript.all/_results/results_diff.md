# Ruffle Test Results Diff

**Previous:** `f246282a73c1` (2026-03-19T20:52:22.897051+00:00)
**Current:** `ed111aed62c7` (2026-03-19T21:20:27.390111+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 44 | +44 |
| Total | 190 | 190 | 0 |
| Pass rate | 0.0% | 23.2% | +23.2% |
| Mismatched lines | 0 | 5995 | +5995 |
|   Increased | | | +5995 |

## Newly Passing (44)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Accessibility-v5` | compile_fail | - | 15/15 |
| `BitmapData-v5` | compile_fail | - | 7/7 |
| `BitmapData-v6` | compile_fail | - | 7/7 |
| `BitmapData-v7` | compile_fail | - | 7/7 |
| `Boolean-v5` | compile_fail | - | 38/38 |
| `Boolean-v6` | compile_fail | - | 38/38 |
| `Boolean-v7` | compile_fail | - | 38/38 |
| `Boolean-v8` | compile_fail | - | 38/38 |
| `Camera-v5` | compile_fail | - | 7/7 |
| `ColorTransform-v5` | compile_fail | - | 7/7 |
| `ColorTransform-v6` | compile_fail | - | 7/7 |
| `ColorTransform-v7` | compile_fail | - | 7/7 |
| `ContextMenu-v5` | compile_fail | - | 7/7 |
| `ContextMenu-v6` | compile_fail | - | 7/7 |
| `ExternalInterface-v5` | compile_fail | - | 7/7 |
| `LoadVars-v5` | compile_fail | - | 8/8 |
| `Matrix-v5` | compile_fail | - | 7/7 |
| `Microphone-v5` | compile_fail | - | 6/6 |
| `MovieClipLoader-v5` | compile_fail | - | 6/6 |
| `MovieClipLoader-v6` | compile_fail | - | 6/6 |
| `NetStream-v5` | compile_fail | - | 6/6 |
| `Point-v5` | compile_fail | - | 7/7 |
| `Point-v6` | compile_fail | - | 7/7 |
| `Point-v7` | compile_fail | - | 7/7 |
| `Random-v5` | compile_fail | - | 30/30 |
| `Random-v6` | compile_fail | - | 30/30 |
| `Random-v7` | compile_fail | - | 30/30 |
| `Random-v8` | compile_fail | - | 30/30 |
| `Rectangle-v5` | compile_fail | - | 7/7 |
| `Rectangle-v6` | compile_fail | - | 7/7 |
| `Rectangle-v7` | compile_fail | - | 7/7 |
| `TextFieldHTML-v5` | compile_fail | - | 6/6 |
| `TextSnapshot-v5` | compile_fail | - | 7/7 |
| `Transform-v5` | compile_fail | - | 7/7 |
| `Video-v6` | compile_fail | - | 85/85 |
| `Video-v7` | compile_fail | - | 85/85 |
| `Video-v8` | compile_fail | - | 85/85 |
| `argstest-v5` | compile_fail | - | 4/4 |
| `enumerate-v5` | compile_fail | - | 6/6 |
| `swap-v5` | compile_fail | - | 7/7 |
| `swap-v6` | compile_fail | - | 7/7 |
| `swap-v7` | compile_fail | - | 7/7 |
| `swap-v8` | compile_fail | - | 7/7 |
| `targetPath-v5` | compile_fail | - | 12/12 |

## Status Changed (146)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | compile_fail | output_mismatch | - | 30/107 |
| `ASnative-v6` | compile_fail | output_mismatch | - | 28/110 |
| `ASnative-v7` | compile_fail | output_mismatch | - | 28/110 |
| `ASnative-v8` | compile_fail | output_mismatch | - | 29/110 |
| `Accessibility-v6` | compile_fail | output_mismatch | - | 10/19 |
| `Accessibility-v7` | compile_fail | output_mismatch | - | 10/19 |
| `Accessibility-v8` | compile_fail | output_mismatch | - | 9/19 |
| `AsBroadcaster-v5` | compile_fail | output_mismatch | - | 8/11 |
| `AsBroadcaster-v6` | compile_fail | output_mismatch | - | 96/121 |
| `AsBroadcaster-v7` | compile_fail | output_mismatch | - | 85/121 |
| `AsBroadcaster-v8` | compile_fail | output_mismatch | - | 85/121 |
| `BitmapData-v8` | compile_fail | output_mismatch | - | 219/417 |
| `Camera-v6` | compile_fail | output_mismatch | - | 33/90 |
| `Camera-v7` | compile_fail | output_mismatch | - | 33/90 |
| `Camera-v8` | compile_fail | output_mismatch | - | 33/90 |
| `Color-v5` | compile_fail | output_mismatch | - | 116/140 |
| `Color-v6` | compile_fail | output_mismatch | - | 144/171 |
| `Color-v7` | compile_fail | output_mismatch | - | 138/161 |
| `Color-v8` | compile_fail | output_mismatch | - | 138/161 |
| `ColorTransform-v8` | compile_fail | output_mismatch | - | 45/55 |
| `ContextMenu-v7` | compile_fail | output_mismatch | - | 95/131 |
| `ContextMenu-v8` | compile_fail | output_mismatch | - | 95/131 |
| `Error-v5` | compile_fail | output_mismatch | - | 21/28 |
| `Error-v6` | compile_fail | output_mismatch | - | 24/31 |
| `Error-v7` | compile_fail | output_mismatch | - | 24/31 |
| `Error-v8` | compile_fail | output_mismatch | - | 24/31 |
| `ExternalInterface-v6` | compile_fail | output_mismatch | - | 28/55 |
| `ExternalInterface-v7` | compile_fail | output_mismatch | - | 28/55 |
| `ExternalInterface-v8` | compile_fail | output_mismatch | - | 82/118 |
| `Global-v6` | compile_fail | output_mismatch | - | 146/210 |
| `Global-v7` | compile_fail | output_mismatch | - | 134/182 |
| `Global-v8` | compile_fail | output_mismatch | - | 128/169 |
| `HitTest-v6` | compile_fail | output_mismatch | - | 70/88 |
| `HitTest-v7` | compile_fail | output_mismatch | - | 70/88 |
| `HitTest-v8` | compile_fail | output_mismatch | - | 71/88 |
| `Inheritance-v5` | compile_fail | output_mismatch | - | 95/114 |
| `Inheritance-v6` | compile_fail | output_mismatch | - | 155/181 |
| `Inheritance-v7` | compile_fail | segfault | - | 74/181 |
| `Inheritance-v8` | compile_fail | segfault | - | 72/181 |
| `Instance-v5` | compile_fail | output_mismatch | - | 32/52 |
| `Instance-v6` | compile_fail | output_mismatch | - | 33/52 |
| `Instance-v7` | compile_fail | output_mismatch | - | 32/52 |
| `Instance-v8` | compile_fail | output_mismatch | - | 27/52 |
| `Key-v5` | compile_fail | output_mismatch | - | 10/51 |
| `Key-v6` | compile_fail | output_mismatch | - | 15/55 |
| `Key-v7` | compile_fail | output_mismatch | - | 15/55 |
| `Key-v8` | compile_fail | output_mismatch | - | 15/55 |
| `LoadVars-v6` | compile_fail | output_mismatch | - | 67/152 |
| `LoadVars-v7` | compile_fail | output_mismatch | - | 67/152 |
| `LoadVars-v8` | compile_fail | output_mismatch | - | 67/152 |
| `LocalConnection-v5` | compile_fail | output_mismatch | - | 4/7 |
| `LocalConnection-v6` | compile_fail | output_mismatch | - | 24/58 |
| `LocalConnection-v7` | compile_fail | output_mismatch | - | 24/58 |
| `LocalConnection-v8` | compile_fail | output_mismatch | - | 24/58 |
| `Math-v5` | compile_fail | output_mismatch | - | 272/278 |
| `Math-v6` | compile_fail | output_mismatch | - | 272/278 |
| `Math-v7` | compile_fail | output_mismatch | - | 280/287 |
| `Math-v8` | compile_fail | output_mismatch | - | 280/287 |
| `Matrix-v6` | compile_fail | output_mismatch | - | 42/168 |
| `Matrix-v7` | compile_fail | output_mismatch | - | 38/168 |
| `Matrix-v8` | compile_fail | output_mismatch | - | 139/168 |
| `Microphone-v6` | compile_fail | output_mismatch | - | 48/79 |
| `Microphone-v7` | compile_fail | output_mismatch | - | 48/79 |
| `Microphone-v8` | compile_fail | output_mismatch | - | 48/79 |
| `Mouse-v5` | compile_fail | output_mismatch | - | 8/13 |
| `Mouse-v6` | compile_fail | output_mismatch | - | 13/21 |
| `Mouse-v7` | compile_fail | output_mismatch | - | 13/21 |
| `Mouse-v8` | compile_fail | output_mismatch | - | 12/21 |
| `MovieClip-v5` | compile_fail | output_mismatch | - | 228/363 |
| `MovieClipLoader-v7` | compile_fail | output_mismatch | - | 46/165 |
| `MovieClipLoader-v8` | compile_fail | output_mismatch | - | 46/165 |
| `NetConnection-v5` | compile_fail | output_mismatch | - | 4/7 |
| `NetStream-v6` | compile_fail | output_mismatch | - | 76/80 |
| `NetStream-v7` | compile_fail | output_mismatch | - | 76/80 |
| `NetStream-v8` | compile_fail | output_mismatch | - | 76/80 |
| `Number-v5` | compile_fail | output_mismatch | - | 188/244 |
| `Number-v6` | compile_fail | output_mismatch | - | 177/239 |
| `Number-v7` | compile_fail | output_mismatch | - | 182/237 |
| `Number-v8` | compile_fail | output_mismatch | - | 181/237 |
| `Point-v8` | compile_fail | output_mismatch | - | 163/193 |
| `Rectangle-v8` | compile_fail | output_mismatch | - | 132/166 |
| `Selection-v5` | compile_fail | output_mismatch | - | 18/21 |
| `Selection-v6` | compile_fail | output_mismatch | - | 108/125 |
| `Selection-v7` | compile_fail | output_mismatch | - | 109/125 |
| `Selection-v8` | compile_fail | output_mismatch | - | 109/125 |
| `Sound-v5` | compile_fail | output_mismatch | - | 77/100 |
| `Sound-v6` | compile_fail | output_mismatch | - | 76/121 |
| `Sound-v7` | compile_fail | output_mismatch | - | 76/121 |
| `Sound-v8` | compile_fail | output_mismatch | - | 76/121 |
| `Stage-v5` | compile_fail | output_mismatch | - | 33/38 |
| `String-v5` | compile_fail | output_mismatch | - | 216/358 |
| `String-v6` | compile_fail | output_mismatch | - | 227/377 |
| `String-v7` | compile_fail | output_mismatch | - | 225/377 |
| `String-v8` | compile_fail | output_mismatch | - | 224/377 |
| `System-v5` | compile_fail | output_mismatch | - | 26/67 |
| `System-v6` | compile_fail | output_mismatch | - | 40/100 |
| `System-v7` | compile_fail | output_mismatch | - | 40/101 |
| `System-v8` | compile_fail | output_mismatch | - | 40/101 |
| `TextField-v5` | compile_fail | output_mismatch | - | 8/12 |
| `TextFieldHTML-v6` | compile_fail | output_mismatch | - | 32/37 |
| `TextFieldHTML-v7` | compile_fail | output_mismatch | - | 32/37 |
| `TextFieldHTML-v8` | compile_fail | output_mismatch | - | 32/37 |
| `TextFormat-v5` | compile_fail | output_mismatch | - | 101/128 |
| `TextFormat-v6` | compile_fail | output_mismatch | - | 101/128 |
| `TextFormat-v7` | compile_fail | output_mismatch | - | 107/174 |
| `TextSnapshot-v6` | compile_fail | output_mismatch | - | 132/173 |
| `TextSnapshot-v7` | compile_fail | output_mismatch | - | 132/173 |
| `TextSnapshot-v8` | compile_fail | output_mismatch | - | 132/173 |
| `Transform-v6` | compile_fail | output_mismatch | - | 4/7 |
| `Transform-v7` | compile_fail | output_mismatch | - | 4/7 |
| `Try-v5` | compile_fail | runtime_error | - | 11/20 |
| `Try-v6` | compile_fail | runtime_error | - | 11/20 |
| `Try-v7` | compile_fail | runtime_error | - | 11/20 |
| `Try-v8` | compile_fail | runtime_error | - | 11/20 |
| `Video-v5` | compile_fail | output_mismatch | - | 4/7 |
| `XMLSocket-v5` | compile_fail | output_mismatch | - | 27/35 |
| `XMLSocket-v6` | compile_fail | output_mismatch | - | 31/35 |
| `XMLSocket-v7` | compile_fail | output_mismatch | - | 31/35 |
| `XMLSocket-v8` | compile_fail | output_mismatch | - | 31/35 |
| `array-v5` | compile_fail | runtime_error | - | 74/560 |
| `case-v5` | compile_fail | output_mismatch | - | 32/39 |
| `case-v6` | compile_fail | output_mismatch | - | 18/73 |
| `case-v7` | compile_fail | output_mismatch | - | 13/67 |
| `case-v8` | compile_fail | output_mismatch | - | 13/67 |
| `delete-v5` | compile_fail | output_mismatch | - | 37/60 |
| `delete-v6` | compile_fail | output_mismatch | - | 38/60 |
| `delete-v7` | compile_fail | output_mismatch | - | 39/60 |
| `delete-v8` | compile_fail | output_mismatch | - | 40/60 |
| `enumerate-v6` | compile_fail | output_mismatch | - | 22/49 |
| `enumerate-v7` | compile_fail | output_mismatch | - | 22/49 |
| `enumerate-v8` | compile_fail | output_mismatch | - | 22/49 |
| `flash-v5` | compile_fail | output_mismatch | - | 7/10 |
| `flash-v6` | compile_fail | output_mismatch | - | 7/10 |
| `flash-v7` | compile_fail | output_mismatch | - | 7/10 |
| `ops-v8` | compile_fail | output_mismatch | - | 251/262 |
| `targetPath-v6` | compile_fail | output_mismatch | - | 9/23 |
| `targetPath-v7` | compile_fail | output_mismatch | - | 9/23 |
| `targetPath-v8` | compile_fail | output_mismatch | - | 9/23 |
| `toString_valueOf-v5` | compile_fail | output_mismatch | - | 82/137 |
| `toString_valueOf-v6` | compile_fail | output_mismatch | - | 118/155 |
| `toString_valueOf-v7` | compile_fail | output_mismatch | - | 119/155 |
| `toString_valueOf-v8` | compile_fail | output_mismatch | - | 119/155 |
| `with-v5` | compile_fail | output_mismatch | - | 21/49 |
| `with-v6` | compile_fail | output_mismatch | - | 23/107 |
| `with-v7` | compile_fail | output_mismatch | - | 23/107 |
| `with-v8` | compile_fail | output_mismatch | - | 23/107 |
