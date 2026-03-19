# Ruffle Test Results Diff

**Previous:** `182a3864f7fe` (2026-03-19T03:48:19.645529+00:00)
**Current:** `f246282a73c1` (2026-03-19T20:52:22.897051+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 44 | 0 | -44 |
| Total | 190 | 190 | 0 |
| Pass rate | 23.2% | 0.0% | -23.2% |
| Mismatched lines | 6019 | 0 | -6019 |
|   Decreased | | | -6019 |

## Newly Failing (44)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `Accessibility-v5` | compile_fail | 15/15 | - |
| `BitmapData-v5` | compile_fail | 7/7 | - |
| `BitmapData-v6` | compile_fail | 7/7 | - |
| `BitmapData-v7` | compile_fail | 7/7 | - |
| `Boolean-v5` | compile_fail | 38/38 | - |
| `Boolean-v6` | compile_fail | 38/38 | - |
| `Boolean-v7` | compile_fail | 38/38 | - |
| `Boolean-v8` | compile_fail | 38/38 | - |
| `Camera-v5` | compile_fail | 7/7 | - |
| `ColorTransform-v5` | compile_fail | 7/7 | - |
| `ColorTransform-v6` | compile_fail | 7/7 | - |
| `ColorTransform-v7` | compile_fail | 7/7 | - |
| `ContextMenu-v5` | compile_fail | 7/7 | - |
| `ContextMenu-v6` | compile_fail | 7/7 | - |
| `ExternalInterface-v5` | compile_fail | 7/7 | - |
| `LoadVars-v5` | compile_fail | 8/8 | - |
| `Matrix-v5` | compile_fail | 7/7 | - |
| `Microphone-v5` | compile_fail | 6/6 | - |
| `MovieClipLoader-v5` | compile_fail | 6/6 | - |
| `MovieClipLoader-v6` | compile_fail | 6/6 | - |
| `NetStream-v5` | compile_fail | 6/6 | - |
| `Point-v5` | compile_fail | 7/7 | - |
| `Point-v6` | compile_fail | 7/7 | - |
| `Point-v7` | compile_fail | 7/7 | - |
| `Random-v5` | compile_fail | 30/30 | - |
| `Random-v6` | compile_fail | 30/30 | - |
| `Random-v7` | compile_fail | 30/30 | - |
| `Random-v8` | compile_fail | 30/30 | - |
| `Rectangle-v5` | compile_fail | 7/7 | - |
| `Rectangle-v6` | compile_fail | 7/7 | - |
| `Rectangle-v7` | compile_fail | 7/7 | - |
| `TextFieldHTML-v5` | compile_fail | 6/6 | - |
| `TextSnapshot-v5` | compile_fail | 7/7 | - |
| `Transform-v5` | compile_fail | 7/7 | - |
| `Video-v6` | compile_fail | 85/85 | - |
| `Video-v7` | compile_fail | 85/85 | - |
| `Video-v8` | compile_fail | 85/85 | - |
| `argstest-v5` | compile_fail | 4/4 | - |
| `enumerate-v5` | compile_fail | 6/6 | - |
| `swap-v5` | compile_fail | 7/7 | - |
| `swap-v6` | compile_fail | 7/7 | - |
| `swap-v7` | compile_fail | 7/7 | - |
| `swap-v8` | compile_fail | 7/7 | - |
| `targetPath-v5` | compile_fail | 12/12 | - |

## Status Changed (146)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | output_mismatch | compile_fail | 30/107 | - |
| `ASnative-v6` | output_mismatch | compile_fail | 28/110 | - |
| `ASnative-v7` | output_mismatch | compile_fail | 28/110 | - |
| `ASnative-v8` | output_mismatch | compile_fail | 29/110 | - |
| `Accessibility-v6` | output_mismatch | compile_fail | 10/19 | - |
| `Accessibility-v7` | output_mismatch | compile_fail | 10/19 | - |
| `Accessibility-v8` | output_mismatch | compile_fail | 9/19 | - |
| `AsBroadcaster-v5` | output_mismatch | compile_fail | 8/11 | - |
| `AsBroadcaster-v6` | output_mismatch | compile_fail | 97/121 | - |
| `AsBroadcaster-v7` | output_mismatch | compile_fail | 86/121 | - |
| `AsBroadcaster-v8` | output_mismatch | compile_fail | 85/121 | - |
| `BitmapData-v8` | output_mismatch | compile_fail | 219/417 | - |
| `Camera-v6` | output_mismatch | compile_fail | 33/90 | - |
| `Camera-v7` | output_mismatch | compile_fail | 33/90 | - |
| `Camera-v8` | output_mismatch | compile_fail | 33/90 | - |
| `Color-v5` | output_mismatch | compile_fail | 116/140 | - |
| `Color-v6` | output_mismatch | compile_fail | 144/171 | - |
| `Color-v7` | output_mismatch | compile_fail | 138/161 | - |
| `Color-v8` | output_mismatch | compile_fail | 138/161 | - |
| `ColorTransform-v8` | output_mismatch | compile_fail | 45/55 | - |
| `ContextMenu-v7` | output_mismatch | compile_fail | 95/131 | - |
| `ContextMenu-v8` | output_mismatch | compile_fail | 95/131 | - |
| `Error-v5` | output_mismatch | compile_fail | 21/28 | - |
| `Error-v6` | output_mismatch | compile_fail | 24/31 | - |
| `Error-v7` | output_mismatch | compile_fail | 24/31 | - |
| `Error-v8` | output_mismatch | compile_fail | 24/31 | - |
| `ExternalInterface-v6` | output_mismatch | compile_fail | 28/55 | - |
| `ExternalInterface-v7` | output_mismatch | compile_fail | 28/55 | - |
| `ExternalInterface-v8` | output_mismatch | compile_fail | 82/118 | - |
| `Global-v6` | output_mismatch | compile_fail | 146/210 | - |
| `Global-v7` | output_mismatch | compile_fail | 134/182 | - |
| `Global-v8` | output_mismatch | compile_fail | 128/169 | - |
| `HitTest-v6` | output_mismatch | compile_fail | 70/88 | - |
| `HitTest-v7` | output_mismatch | compile_fail | 70/88 | - |
| `HitTest-v8` | output_mismatch | compile_fail | 71/88 | - |
| `Inheritance-v5` | output_mismatch | compile_fail | 95/114 | - |
| `Inheritance-v6` | output_mismatch | compile_fail | 157/181 | - |
| `Inheritance-v7` | segfault | compile_fail | 74/181 | - |
| `Inheritance-v8` | segfault | compile_fail | 74/181 | - |
| `Instance-v5` | output_mismatch | compile_fail | 32/52 | - |
| `Instance-v6` | output_mismatch | compile_fail | 33/52 | - |
| `Instance-v7` | output_mismatch | compile_fail | 32/52 | - |
| `Instance-v8` | output_mismatch | compile_fail | 27/52 | - |
| `Key-v5` | output_mismatch | compile_fail | 10/51 | - |
| `Key-v6` | output_mismatch | compile_fail | 15/55 | - |
| `Key-v7` | output_mismatch | compile_fail | 15/55 | - |
| `Key-v8` | output_mismatch | compile_fail | 15/55 | - |
| `LoadVars-v6` | output_mismatch | compile_fail | 67/152 | - |
| `LoadVars-v7` | output_mismatch | compile_fail | 67/152 | - |
| `LoadVars-v8` | output_mismatch | compile_fail | 67/152 | - |
| `LocalConnection-v5` | output_mismatch | compile_fail | 4/7 | - |
| `LocalConnection-v6` | output_mismatch | compile_fail | 24/58 | - |
| `LocalConnection-v7` | output_mismatch | compile_fail | 24/58 | - |
| `LocalConnection-v8` | output_mismatch | compile_fail | 24/58 | - |
| `Math-v5` | output_mismatch | compile_fail | 272/278 | - |
| `Math-v6` | output_mismatch | compile_fail | 272/278 | - |
| `Math-v7` | output_mismatch | compile_fail | 280/287 | - |
| `Math-v8` | output_mismatch | compile_fail | 280/287 | - |
| `Matrix-v6` | output_mismatch | compile_fail | 42/168 | - |
| `Matrix-v7` | output_mismatch | compile_fail | 38/168 | - |
| `Matrix-v8` | output_mismatch | compile_fail | 139/168 | - |
| `Microphone-v6` | output_mismatch | compile_fail | 48/79 | - |
| `Microphone-v7` | output_mismatch | compile_fail | 48/79 | - |
| `Microphone-v8` | output_mismatch | compile_fail | 48/79 | - |
| `Mouse-v5` | output_mismatch | compile_fail | 8/13 | - |
| `Mouse-v6` | output_mismatch | compile_fail | 13/21 | - |
| `Mouse-v7` | output_mismatch | compile_fail | 13/21 | - |
| `Mouse-v8` | output_mismatch | compile_fail | 12/21 | - |
| `MovieClip-v5` | output_mismatch | compile_fail | 228/363 | - |
| `MovieClipLoader-v7` | output_mismatch | compile_fail | 46/165 | - |
| `MovieClipLoader-v8` | output_mismatch | compile_fail | 46/165 | - |
| `NetConnection-v5` | output_mismatch | compile_fail | 4/7 | - |
| `NetStream-v6` | output_mismatch | compile_fail | 76/80 | - |
| `NetStream-v7` | output_mismatch | compile_fail | 76/80 | - |
| `NetStream-v8` | output_mismatch | compile_fail | 76/80 | - |
| `Number-v5` | output_mismatch | compile_fail | 188/244 | - |
| `Number-v6` | output_mismatch | compile_fail | 177/239 | - |
| `Number-v7` | output_mismatch | compile_fail | 182/237 | - |
| `Number-v8` | output_mismatch | compile_fail | 181/237 | - |
| `Point-v8` | output_mismatch | compile_fail | 163/193 | - |
| `Rectangle-v8` | output_mismatch | compile_fail | 132/166 | - |
| `Selection-v5` | output_mismatch | compile_fail | 18/21 | - |
| `Selection-v6` | output_mismatch | compile_fail | 108/125 | - |
| `Selection-v7` | output_mismatch | compile_fail | 109/125 | - |
| `Selection-v8` | output_mismatch | compile_fail | 109/125 | - |
| `Sound-v5` | output_mismatch | compile_fail | 77/100 | - |
| `Sound-v6` | output_mismatch | compile_fail | 76/121 | - |
| `Sound-v7` | output_mismatch | compile_fail | 76/121 | - |
| `Sound-v8` | output_mismatch | compile_fail | 76/121 | - |
| `Stage-v5` | output_mismatch | compile_fail | 33/38 | - |
| `String-v5` | output_mismatch | compile_fail | 216/358 | - |
| `String-v6` | output_mismatch | compile_fail | 228/377 | - |
| `String-v7` | output_mismatch | compile_fail | 225/377 | - |
| `String-v8` | output_mismatch | compile_fail | 225/377 | - |
| `System-v5` | output_mismatch | compile_fail | 26/67 | - |
| `System-v6` | output_mismatch | compile_fail | 40/100 | - |
| `System-v7` | output_mismatch | compile_fail | 40/101 | - |
| `System-v8` | output_mismatch | compile_fail | 40/101 | - |
| `TextField-v5` | output_mismatch | compile_fail | 8/12 | - |
| `TextFieldHTML-v6` | output_mismatch | compile_fail | 32/37 | - |
| `TextFieldHTML-v7` | output_mismatch | compile_fail | 32/37 | - |
| `TextFieldHTML-v8` | output_mismatch | compile_fail | 32/37 | - |
| `TextFormat-v5` | output_mismatch | compile_fail | 101/128 | - |
| `TextFormat-v6` | output_mismatch | compile_fail | 101/128 | - |
| `TextFormat-v7` | output_mismatch | compile_fail | 107/174 | - |
| `TextSnapshot-v6` | output_mismatch | compile_fail | 132/173 | - |
| `TextSnapshot-v7` | output_mismatch | compile_fail | 132/173 | - |
| `TextSnapshot-v8` | output_mismatch | compile_fail | 132/173 | - |
| `Transform-v6` | output_mismatch | compile_fail | 4/7 | - |
| `Transform-v7` | output_mismatch | compile_fail | 4/7 | - |
| `Try-v5` | segfault | compile_fail | 11/20 | - |
| `Try-v6` | segfault | compile_fail | 11/20 | - |
| `Try-v7` | segfault | compile_fail | 11/20 | - |
| `Try-v8` | segfault | compile_fail | 11/20 | - |
| `Video-v5` | output_mismatch | compile_fail | 4/7 | - |
| `XMLSocket-v5` | output_mismatch | compile_fail | 27/35 | - |
| `XMLSocket-v6` | output_mismatch | compile_fail | 31/35 | - |
| `XMLSocket-v7` | output_mismatch | compile_fail | 31/35 | - |
| `XMLSocket-v8` | output_mismatch | compile_fail | 31/35 | - |
| `array-v5` | segfault | compile_fail | 74/560 | - |
| `case-v5` | output_mismatch | compile_fail | 32/39 | - |
| `case-v6` | output_mismatch | compile_fail | 18/73 | - |
| `case-v7` | output_mismatch | compile_fail | 13/67 | - |
| `case-v8` | output_mismatch | compile_fail | 13/67 | - |
| `delete-v5` | output_mismatch | compile_fail | 37/60 | - |
| `delete-v6` | output_mismatch | compile_fail | 38/60 | - |
| `delete-v7` | output_mismatch | compile_fail | 39/60 | - |
| `delete-v8` | output_mismatch | compile_fail | 40/60 | - |
| `enumerate-v6` | output_mismatch | compile_fail | 22/49 | - |
| `enumerate-v7` | output_mismatch | compile_fail | 22/49 | - |
| `enumerate-v8` | output_mismatch | compile_fail | 22/49 | - |
| `flash-v5` | output_mismatch | compile_fail | 7/10 | - |
| `flash-v6` | output_mismatch | compile_fail | 7/10 | - |
| `flash-v7` | output_mismatch | compile_fail | 7/10 | - |
| `ops-v8` | output_mismatch | compile_fail | 251/262 | - |
| `targetPath-v6` | output_mismatch | compile_fail | 9/23 | - |
| `targetPath-v7` | output_mismatch | compile_fail | 9/23 | - |
| `targetPath-v8` | output_mismatch | compile_fail | 9/23 | - |
| `toString_valueOf-v5` | segfault | compile_fail | 77/137 | - |
| `toString_valueOf-v6` | segfault | compile_fail | 106/155 | - |
| `toString_valueOf-v7` | output_mismatch | compile_fail | 112/155 | - |
| `toString_valueOf-v8` | output_mismatch | compile_fail | 111/155 | - |
| `with-v5` | output_mismatch | compile_fail | 21/49 | - |
| `with-v6` | output_mismatch | compile_fail | 23/107 | - |
| `with-v7` | output_mismatch | compile_fail | 23/107 | - |
| `with-v8` | output_mismatch | compile_fail | 23/107 | - |
