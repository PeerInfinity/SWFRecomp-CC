# Ruffle Test Results Diff

**Previous:** `bf585e4486b6` (2026-08-12T23:11:20.779103+00:00)
**Current:** `16314e63feaa` (2026-08-13T21:54:57.600795+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 135 | 0 | -135 |
| Total | 243 | 243 | 0 |
| Pass rate | 55.6% | 0.0% | -55.6% |
| Mismatched lines | 8431 | 0 | -8431 |
|   Decreased | | | -8431 |

## Newly Failing (135)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `Accessibility-v5` | compile_fail | 15/15 | - |
| `Accessibility-v6` | compile_fail | 19/19 | - |
| `Accessibility-v7` | compile_fail | 19/19 | - |
| `Accessibility-v8` | compile_fail | 19/19 | - |
| `AsBroadcaster-v5` | compile_fail | 11/11 | - |
| `BitmapData-v5` | compile_fail | 7/7 | - |
| `BitmapData-v6` | compile_fail | 7/7 | - |
| `BitmapData-v7` | compile_fail | 7/7 | - |
| `Boolean-v5` | compile_fail | 38/38 | - |
| `Boolean-v6` | compile_fail | 38/38 | - |
| `Boolean-v7` | compile_fail | 38/38 | - |
| `Boolean-v8` | compile_fail | 38/38 | - |
| `Camera-v5` | compile_fail | 7/7 | - |
| `Color-v5` | compile_fail | 140/140 | - |
| `Color-v6` | compile_fail | 171/171 | - |
| `Color-v7` | compile_fail | 161/161 | - |
| `Color-v8` | compile_fail | 161/161 | - |
| `ColorTransform-v5` | compile_fail | 7/7 | - |
| `ColorTransform-v6` | compile_fail | 7/7 | - |
| `ColorTransform-v7` | compile_fail | 7/7 | - |
| `ColorTransform-v8` | compile_fail | 55/55 | - |
| `ContextMenu-v5` | compile_fail | 7/7 | - |
| `ContextMenu-v6` | compile_fail | 7/7 | - |
| `ContextMenu-v7` | compile_fail | 131/131 | - |
| `ContextMenu-v8` | compile_fail | 131/131 | - |
| `Error-v5` | compile_fail | 28/28 | - |
| `Error-v6` | compile_fail | 31/31 | - |
| `Error-v7` | compile_fail | 31/31 | - |
| `Error-v8` | compile_fail | 31/31 | - |
| `ExternalInterface-v5` | compile_fail | 7/7 | - |
| `ExternalInterface-v6` | compile_fail | 55/55 | - |
| `ExternalInterface-v7` | compile_fail | 55/55 | - |
| `Global-v5` | compile_fail | 172/172 | - |
| `Global-v7` | compile_fail | 182/182 | - |
| `Global-v8` | compile_fail | 169/169 | - |
| `Instance-v5` | compile_fail | 52/52 | - |
| `Instance-v6` | compile_fail | 52/52 | - |
| `Instance-v7` | compile_fail | 52/52 | - |
| `Instance-v8` | compile_fail | 52/52 | - |
| `Key-v5` | compile_fail | 51/51 | - |
| `Key-v6` | compile_fail | 55/55 | - |
| `Key-v7` | compile_fail | 55/55 | - |
| `Key-v8` | compile_fail | 55/55 | - |
| `LoadVars-v5` | compile_fail | 8/8 | - |
| `LocalConnection-v5` | compile_fail | 7/7 | - |
| `LocalConnection-v6` | compile_fail | 58/58 | - |
| `LocalConnection-v7` | compile_fail | 58/58 | - |
| `LocalConnection-v8` | compile_fail | 58/58 | - |
| `Matrix-v5` | compile_fail | 7/7 | - |
| `Microphone-v5` | compile_fail | 6/6 | - |
| `Mouse-v5` | compile_fail | 13/13 | - |
| `Mouse-v6` | compile_fail | 21/21 | - |
| `Mouse-v7` | compile_fail | 21/21 | - |
| `Mouse-v8` | compile_fail | 21/21 | - |
| `MovieClipLoader-v5` | compile_fail | 6/6 | - |
| `MovieClipLoader-v6` | compile_fail | 6/6 | - |
| `NetConnection-v5` | compile_fail | 7/7 | - |
| `NetStream-v5` | compile_fail | 6/6 | - |
| `NetStream-v6` | compile_fail | 80/80 | - |
| `NetStream-v7` | compile_fail | 80/80 | - |
| `NetStream-v8` | compile_fail | 80/80 | - |
| `Number-v6` | compile_fail | 239/239 | - |
| `Number-v7` | compile_fail | 237/237 | - |
| `Number-v8` | compile_fail | 237/237 | - |
| `Point-v5` | compile_fail | 7/7 | - |
| `Point-v6` | compile_fail | 7/7 | - |
| `Point-v7` | compile_fail | 7/7 | - |
| `Point-v8` | compile_fail | 193/193 | - |
| `Random-v5` | compile_fail | 30/30 | - |
| `Random-v6` | compile_fail | 30/30 | - |
| `Random-v7` | compile_fail | 30/30 | - |
| `Random-v8` | compile_fail | 30/30 | - |
| `Rectangle-v5` | compile_fail | 7/7 | - |
| `Rectangle-v6` | compile_fail | 7/7 | - |
| `Rectangle-v7` | compile_fail | 7/7 | - |
| `Selection-v5` | compile_fail | 21/21 | - |
| `Stage-v5` | compile_fail | 38/38 | - |
| `System-v5` | compile_fail | 67/67 | - |
| `System-v6` | compile_fail | 100/100 | - |
| `System-v7` | compile_fail | 101/101 | - |
| `System-v8` | compile_fail | 101/101 | - |
| `TextFieldHTML-v5` | compile_fail | 6/6 | - |
| `TextFieldHTML-v6` | compile_fail | 37/37 | - |
| `TextFieldHTML-v7` | compile_fail | 37/37 | - |
| `TextFieldHTML-v8` | compile_fail | 37/37 | - |
| `TextFormat-v5` | compile_fail | 128/128 | - |
| `TextFormat-v6` | compile_fail | 128/128 | - |
| `TextSnapshot-v5` | compile_fail | 7/7 | - |
| `TextSnapshot-v6` | compile_fail | 173/173 | - |
| `TextSnapshot-v7` | compile_fail | 173/173 | - |
| `TextSnapshot-v8` | compile_fail | 173/173 | - |
| `Transform-v5` | compile_fail | 7/7 | - |
| `Transform-v6` | compile_fail | 7/7 | - |
| `Transform-v7` | compile_fail | 7/7 | - |
| `Try-v5` | compile_fail | 20/20 | - |
| `Try-v6` | compile_fail | 20/20 | - |
| `Try-v7` | compile_fail | 20/20 | - |
| `Try-v8` | compile_fail | 20/20 | - |
| `Video-v5` | compile_fail | 7/7 | - |
| `Video-v6` | compile_fail | 85/85 | - |
| `Video-v7` | compile_fail | 85/85 | - |
| `Video-v8` | compile_fail | 85/85 | - |
| `XMLSocket-v5` | compile_fail | 35/35 | - |
| `XMLSocket-v6` | compile_fail | 35/35 | - |
| `XMLSocket-v7` | compile_fail | 35/35 | - |
| `XMLSocket-v8` | compile_fail | 35/35 | - |
| `argstest-v5` | compile_fail | 4/4 | - |
| `case-v5` | compile_fail | 39/39 | - |
| `case-v6` | compile_fail | 73/73 | - |
| `case-v7` | compile_fail | 67/67 | - |
| `case-v8` | compile_fail | 67/67 | - |
| `delete-v5` | compile_fail | 61/61 | - |
| `delete-v6` | compile_fail | 61/61 | - |
| `delete-v7` | compile_fail | 61/61 | - |
| `delete-v8` | compile_fail | 61/61 | - |
| `enumerate-v5` | compile_fail | 6/6 | - |
| `enumerate-v6` | compile_fail | 49/49 | - |
| `enumerate-v7` | compile_fail | 49/49 | - |
| `enumerate-v8` | compile_fail | 49/49 | - |
| `flash-v5` | compile_fail | 10/10 | - |
| `flash-v6` | compile_fail | 10/10 | - |
| `flash-v7` | compile_fail | 10/10 | - |
| `flash-v8` | compile_fail | 41/41 | - |
| `getvariable-v5` | compile_fail | 58/58 | - |
| `getvariable-v6` | compile_fail | 64/64 | - |
| `getvariable-v7` | compile_fail | 64/64 | - |
| `getvariable-v8` | compile_fail | 64/64 | - |
| `swap-v5` | compile_fail | 7/7 | - |
| `swap-v6` | compile_fail | 7/7 | - |
| `swap-v7` | compile_fail | 7/7 | - |
| `swap-v8` | compile_fail | 7/7 | - |
| `targetPath-v5` | compile_fail | 12/12 | - |
| `targetPath-v6` | compile_fail | 23/23 | - |
| `targetPath-v7` | compile_fail | 23/23 | - |
| `targetPath-v8` | compile_fail | 23/23 | - |

## Status Changed (108)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | ruffle_matched | compile_fail | 72/107 | - |
| `ASnative-v6` | ruffle_matched | compile_fail | 70/110 | - |
| `ASnative-v7` | ruffle_matched | compile_fail | 70/110 | - |
| `ASnative-v8` | ruffle_matched | compile_fail | 70/110 | - |
| `AsBroadcaster-v6` | ruffle_matched | compile_fail | 114/121 | - |
| `AsBroadcaster-v7` | ruffle_matched | compile_fail | 114/121 | - |
| `AsBroadcaster-v8` | ruffle_matched | compile_fail | 114/121 | - |
| `BitmapData-v8` | ruffle_matched | compile_fail | 409/417 | - |
| `Camera-v6` | ruffle_matched | compile_fail | 33/90 | - |
| `Camera-v7` | ruffle_matched | compile_fail | 33/90 | - |
| `Camera-v8` | ruffle_matched | compile_fail | 33/90 | - |
| `Date-v5` | ruffle_matched | compile_fail | 308/315 | - |
| `Date-v6` | ruffle_matched | compile_fail | 351/357 | - |
| `Date-v7` | ruffle_matched | compile_fail | 351/357 | - |
| `Date-v8` | ruffle_matched | compile_fail | 351/357 | - |
| `ExternalInterface-v8` | ruffle_matched | compile_fail | 114/118 | - |
| `Function-v5` | ruffle_matched | compile_fail | 144/158 | - |
| `Function-v6` | ruffle_matched | compile_fail | 263/271 | - |
| `Function-v7` | ruffle_matched | compile_fail | 264/272 | - |
| `Function-v8` | ruffle_matched | compile_fail | 264/272 | - |
| `Global-v6` | ruffle_matched | compile_fail | 201/210 | - |
| `HitTest-v6` | ruffle_matched | compile_fail | 80/88 | - |
| `HitTest-v7` | ruffle_matched | compile_fail | 80/88 | - |
| `HitTest-v8` | ruffle_matched | compile_fail | 79/88 | - |
| `Inheritance-v5` | ruffle_matched | compile_fail | 114/114 | - |
| `Inheritance-v6` | ruffle_matched | compile_fail | 173/181 | - |
| `Inheritance-v7` | ruffle_matched | compile_fail | 177/181 | - |
| `Inheritance-v8` | ruffle_matched | compile_fail | 177/181 | - |
| `LoadVars-v6` | ruffle_matched | compile_fail | 146/152 | - |
| `LoadVars-v7` | ruffle_matched | compile_fail | 146/152 | - |
| `LoadVars-v8` | ruffle_matched | compile_fail | 146/152 | - |
| `Math-v5` | ruffle_matched | compile_fail | 273/278 | - |
| `Math-v6` | ruffle_matched | compile_fail | 273/278 | - |
| `Math-v7` | ruffle_matched | compile_fail | 282/287 | - |
| `Math-v8` | ruffle_matched | compile_fail | 282/287 | - |
| `Matrix-v6` | ruffle_matched | compile_fail | 139/168 | - |
| `Matrix-v7` | ruffle_matched | compile_fail | 140/168 | - |
| `Matrix-v8` | ruffle_matched | compile_fail | 140/168 | - |
| `Microphone-v6` | ruffle_matched | compile_fail | 48/79 | - |
| `Microphone-v7` | ruffle_matched | compile_fail | 48/79 | - |
| `Microphone-v8` | ruffle_matched | compile_fail | 48/79 | - |
| `MovieClip-v5` | ruffle_matched | compile_fail | 339/363 | - |
| `MovieClip-v6` | output_mismatch | compile_fail | 901/936 | - |
| `MovieClip-v7` | output_mismatch | compile_fail | 934/969 | - |
| `MovieClip-v8` | output_mismatch | compile_fail | 1020/1087 | - |
| `MovieClipLoader-v7` | ruffle_matched | compile_fail | 47/165 | - |
| `MovieClipLoader-v8` | ruffle_matched | compile_fail | 47/165 | - |
| `NetConnection-v6` | ruffle_matched | compile_fail | 122/126 | - |
| `NetConnection-v7` | ruffle_matched | compile_fail | 122/126 | - |
| `NetConnection-v8` | ruffle_matched | compile_fail | 122/126 | - |
| `Number-v5` | ruffle_matched | compile_fail | 236/244 | - |
| `Object-v5` | ruffle_matched | compile_fail | 142/145 | - |
| `Object-v6` | ruffle_matched | compile_fail | 325/333 | - |
| `Object-v7` | ruffle_matched | compile_fail | 325/333 | - |
| `Object-v8` | ruffle_matched | compile_fail | 325/333 | - |
| `Rectangle-v8` | ruffle_matched | compile_fail | 145/166 | - |
| `Selection-v6` | ruffle_matched | compile_fail | 118/125 | - |
| `Selection-v7` | ruffle_matched | compile_fail | 118/125 | - |
| `Selection-v8` | ruffle_matched | compile_fail | 118/125 | - |
| `Sound-v5` | ruffle_matched | compile_fail | 84/100 | - |
| `Sound-v6` | ruffle_matched | compile_fail | 113/121 | - |
| `Sound-v7` | ruffle_matched | compile_fail | 113/121 | - |
| `Sound-v8` | ruffle_matched | compile_fail | 113/121 | - |
| `Stage-v6` | ruffle_matched | compile_fail | 50/64 | - |
| `Stage-v7` | ruffle_matched | compile_fail | 50/64 | - |
| `Stage-v8` | ruffle_matched | compile_fail | 50/64 | - |
| `String-v5` | ruffle_matched | compile_fail | 339/358 | - |
| `String-v6` | ruffle_matched | compile_fail | 367/377 | - |
| `String-v7` | ruffle_matched | compile_fail | 367/377 | - |
| `String-v8` | ruffle_matched | compile_fail | 367/377 | - |
| `TextField-v5` | ruffle_matched | compile_fail | 9/12 | - |
| `TextField-v6` | output_mismatch | compile_fail | 467/545 | - |
| `TextField-v7` | output_mismatch | compile_fail | 476/570 | - |
| `TextField-v8` | output_mismatch | compile_fail | 478/571 | - |
| `TextFormat-v7` | ruffle_matched | compile_fail | 136/174 | - |
| `TextFormat-v8` | ruffle_matched | compile_fail | 136/172 | - |
| `Transform-v8` | ruffle_matched | compile_fail | 94/101 | - |
| `XML-v5` | ruffle_matched | compile_fail | 439/449 | - |
| `XML-v6` | ruffle_matched | compile_fail | 483/486 | - |
| `XML-v7` | ruffle_matched | compile_fail | 483/486 | - |
| `XML-v8` | ruffle_matched | compile_fail | 462/465 | - |
| `XMLNode-v5` | ruffle_matched | compile_fail | 204/207 | - |
| `XMLNode-v6` | ruffle_matched | compile_fail | 204/207 | - |
| `XMLNode-v7` | ruffle_matched | compile_fail | 204/207 | - |
| `XMLNode-v8` | ruffle_matched | compile_fail | 204/207 | - |
| `argstest-v6` | output_mismatch | compile_fail | 80/2192 | - |
| `argstest-v7` | output_mismatch | compile_fail | 110/2061 | - |
| `argstest-v8` | output_mismatch | compile_fail | 175/2434 | - |
| `array-v5` | output_mismatch | compile_fail | 551/560 | - |
| `array-v6` | output_mismatch | compile_fail | 623/644 | - |
| `array-v7` | output_mismatch | compile_fail | 604/654 | - |
| `array-v8` | output_mismatch | compile_fail | 604/654 | - |
| `ops-v5` | ruffle_matched | compile_fail | 253/260 | - |
| `ops-v6` | ruffle_matched | compile_fail | 253/260 | - |
| `ops-v7` | ruffle_matched | compile_fail | 255/262 | - |
| `ops-v8` | ruffle_matched | compile_fail | 255/262 | - |
| `setProperty-v5` | ruffle_matched | compile_fail | 3/52 | - |
| `setProperty-v6` | ruffle_matched | compile_fail | 3/52 | - |
| `setProperty-v7` | ruffle_matched | compile_fail | 3/52 | - |
| `setProperty-v8` | ruffle_matched | compile_fail | 3/52 | - |
| `toString_valueOf-v5` | ruffle_matched | compile_fail | 103/137 | - |
| `toString_valueOf-v6` | ruffle_matched | compile_fail | 150/155 | - |
| `toString_valueOf-v7` | ruffle_matched | compile_fail | 150/155 | - |
| `toString_valueOf-v8` | ruffle_matched | compile_fail | 150/155 | - |
| `with-v5` | ruffle_matched | compile_fail | 46/49 | - |
| `with-v6` | ruffle_matched | compile_fail | 101/107 | - |
| `with-v7` | ruffle_matched | compile_fail | 101/107 | - |
| `with-v8` | ruffle_matched | compile_fail | 101/107 | - |
