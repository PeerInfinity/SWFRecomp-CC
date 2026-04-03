# Ruffle Test Results Diff

**Previous:** `868900bbb1a2` (2026-04-02T15:39:42.077685+00:00)
**Current:** `82bf8b804cb6` (2026-04-03T16:28:13.532238+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 5 | 68 | +63 |
| Total | 190 | 190 | 0 |
| Pass rate | 2.6% | 35.8% | +33.2% |
| Mismatched lines | 14320 | 4538 | -9782 |
|   Decreased | | | -9783 |
|   Increased | | | +1 |

## Newly Passing (63)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Accessibility-v5` | output_mismatch | 3/15 | 15/15 |
| `Accessibility-v6` | output_mismatch | 3/19 | 19/19 |
| `Accessibility-v7` | output_mismatch | 3/19 | 19/19 |
| `Accessibility-v8` | output_mismatch | 3/19 | 19/19 |
| `BitmapData-v5` | output_mismatch | 3/7 | 7/7 |
| `BitmapData-v6` | output_mismatch | 3/7 | 7/7 |
| `BitmapData-v7` | output_mismatch | 3/7 | 7/7 |
| `Boolean-v5` | output_mismatch | 3/38 | 38/38 |
| `Boolean-v6` | output_mismatch | 3/38 | 38/38 |
| `Boolean-v7` | output_mismatch | 3/38 | 38/38 |
| `Boolean-v8` | output_mismatch | 3/38 | 38/38 |
| `Camera-v5` | output_mismatch | 3/7 | 7/7 |
| `Color-v5` | output_mismatch | 3/140 | 140/140 |
| `Color-v7` | output_mismatch | 3/161 | 161/161 |
| `Color-v8` | output_mismatch | 3/161 | 161/161 |
| `ColorTransform-v5` | output_mismatch | 3/7 | 7/7 |
| `ColorTransform-v6` | output_mismatch | 3/7 | 7/7 |
| `ColorTransform-v7` | output_mismatch | 3/7 | 7/7 |
| `ContextMenu-v5` | output_mismatch | 3/7 | 7/7 |
| `ContextMenu-v6` | output_mismatch | 3/7 | 7/7 |
| `ExternalInterface-v5` | output_mismatch | 3/7 | 7/7 |
| `Key-v6` | output_mismatch | 3/55 | 55/55 |
| `Key-v7` | output_mismatch | 3/55 | 55/55 |
| `Key-v8` | output_mismatch | 3/55 | 55/55 |
| `LoadVars-v5` | output_mismatch | 3/8 | 8/8 |
| `Matrix-v5` | output_mismatch | 3/7 | 7/7 |
| `Microphone-v5` | output_mismatch | 3/6 | 6/6 |
| `Mouse-v5` | output_mismatch | 3/13 | 13/13 |
| `Mouse-v6` | output_mismatch | 3/21 | 21/21 |
| `Mouse-v7` | output_mismatch | 3/21 | 21/21 |
| `Mouse-v8` | output_mismatch | 3/21 | 21/21 |
| `MovieClipLoader-v5` | output_mismatch | 3/6 | 6/6 |
| `MovieClipLoader-v6` | output_mismatch | 3/6 | 6/6 |
| `NetStream-v5` | output_mismatch | 3/6 | 6/6 |
| `Point-v5` | output_mismatch | 3/7 | 7/7 |
| `Point-v6` | output_mismatch | 3/7 | 7/7 |
| `Point-v7` | output_mismatch | 3/7 | 7/7 |
| `Random-v5` | output_mismatch | 3/30 | 30/30 |
| `Random-v6` | output_mismatch | 3/30 | 30/30 |
| `Random-v7` | output_mismatch | 3/30 | 30/30 |
| `Random-v8` | output_mismatch | 3/30 | 30/30 |
| `Rectangle-v5` | output_mismatch | 3/7 | 7/7 |
| `Rectangle-v6` | output_mismatch | 3/7 | 7/7 |
| `Rectangle-v7` | output_mismatch | 3/7 | 7/7 |
| `Selection-v5` | output_mismatch | 4/21 | 21/21 |
| `TextFieldHTML-v5` | output_mismatch | 3/6 | 6/6 |
| `TextSnapshot-v5` | output_mismatch | 3/7 | 7/7 |
| `Transform-v5` | output_mismatch | 3/7 | 7/7 |
| `Try-v5` | output_mismatch | 3/20 | 20/20 |
| `Try-v6` | output_mismatch | 3/20 | 20/20 |
| `Try-v7` | output_mismatch | 3/20 | 20/20 |
| `Try-v8` | output_mismatch | 3/20 | 20/20 |
| `Video-v7` | output_mismatch | 3/85 | 85/85 |
| `Video-v8` | output_mismatch | 3/85 | 85/85 |
| `XMLSocket-v7` | output_mismatch | 3/35 | 35/35 |
| `XMLSocket-v8` | output_mismatch | 3/35 | 35/35 |
| `argstest-v5` | output_mismatch | 3/4 | 4/4 |
| `enumerate-v5` | output_mismatch | 3/6 | 6/6 |
| `swap-v5` | output_mismatch | 3/7 | 7/7 |
| `swap-v6` | output_mismatch | 3/7 | 7/7 |
| `swap-v7` | output_mismatch | 3/7 | 7/7 |
| `swap-v8` | output_mismatch | 3/7 | 7/7 |
| `targetPath-v5` | output_mismatch | 3/12 | 12/12 |

## Line Count Changed (98)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array-v5` | output_mismatch | 3/560 | 448/560 | -445 |
| `Math-v7` | output_mismatch | 3/287 | 282/287 | -279 |
| `Math-v8` | output_mismatch | 3/287 | 282/287 | -279 |
| `Math-v5` | output_mismatch | 3/278 | 273/278 | -270 |
| `Math-v6` | output_mismatch | 3/278 | 273/278 | -270 |
| `BitmapData-v8` | output_mismatch | 3/417 | 259/417 | -256 |
| `String-v7` | output_mismatch | 3/377 | 259/377 | -256 |
| `String-v8` | output_mismatch | 3/377 | 259/377 | -256 |
| `String-v6` | output_mismatch | 3/377 | 258/377 | -255 |
| `ops-v8` | output_mismatch | 3/262 | 255/262 | -252 |
| `String-v5` | output_mismatch | 3/358 | 240/358 | -237 |
| `MovieClip-v5` | output_mismatch | 3/363 | 237/363 | -234 |
| `Number-v5` | output_mismatch | 3/244 | 193/244 | -190 |
| `Number-v7` | output_mismatch | 3/237 | 192/237 | -189 |
| `Number-v8` | output_mismatch | 3/237 | 192/237 | -189 |
| `Number-v6` | output_mismatch | 3/239 | 186/239 | -183 |
| `Inheritance-v8` | output_mismatch | 3/181 | 177/181 | -174 |
| `Inheritance-v7` | output_mismatch | 3/181 | 176/181 | -173 |
| `Point-v8` | output_mismatch | 3/193 | 169/193 | -166 |
| `Color-v6` | output_mismatch | 3/171 | 165/171 | -162 |
| `Inheritance-v6` | output_mismatch | 3/181 | 164/181 | -161 |
| `Global-v6` | output_mismatch | 3/210 | 149/210 | -146 |
| `Rectangle-v8` | output_mismatch | 3/166 | 140/166 | -137 |
| `Matrix-v8` | output_mismatch | 3/168 | 139/168 | -136 |
| `Global-v7` | output_mismatch | 3/182 | 137/182 | -134 |
| `TextSnapshot-v6` | output_mismatch | 3/173 | 132/173 | -129 |
| `TextSnapshot-v7` | output_mismatch | 3/173 | 132/173 | -129 |
| `TextSnapshot-v8` | output_mismatch | 3/173 | 132/173 | -129 |
| `toString_valueOf-v6` | output_mismatch | 3/155 | 132/155 | -129 |
| `Global-v8` | output_mismatch | 3/169 | 131/169 | -128 |
| `TextFormat-v7` | output_mismatch | 3/174 | 113/174 | -110 |
| `TextFormat-v5` | output_mismatch | 3/128 | 101/128 | -98 |
| `TextFormat-v6` | output_mismatch | 3/128 | 101/128 | -98 |
| `AsBroadcaster-v6` | output_mismatch | 3/121 | 98/121 | -95 |
| `ContextMenu-v7` | output_mismatch | 3/131 | 96/131 | -93 |
| `ContextMenu-v8` | output_mismatch | 3/131 | 96/131 | -93 |
| `Inheritance-v5` | output_mismatch | 3/114 | 96/114 | -93 |
| `toString_valueOf-v5` | output_mismatch | 3/137 | 82/137 | -79 |
| `Sound-v5` | output_mismatch | 3/100 | 77/100 | -74 |
| `NetStream-v6` | output_mismatch | 3/80 | 76/80 | -73 |
| `Sound-v7` | output_mismatch | 3/121 | 76/121 | -73 |
| `Sound-v8` | output_mismatch | 3/121 | 76/121 | -73 |
| `HitTest-v6` | output_mismatch | 3/88 | 70/88 | -67 |
| `LoadVars-v6` | output_mismatch | 3/152 | 67/152 | -64 |
| `LoadVars-v7` | output_mismatch | 3/152 | 67/152 | -64 |
| `LoadVars-v8` | output_mismatch | 3/152 | 67/152 | -64 |
| `System-v5` | output_mismatch | 3/67 | 50/67 | -47 |
| `Microphone-v7` | output_mismatch | 3/79 | 48/79 | -45 |
| `Microphone-v8` | output_mismatch | 3/79 | 48/79 | -45 |
| `ColorTransform-v8` | output_mismatch | 3/55 | 46/55 | -43 |
| `MovieClipLoader-v7` | output_mismatch | 3/165 | 46/165 | -43 |
| `MovieClipLoader-v8` | output_mismatch | 3/165 | 46/165 | -43 |
| `Matrix-v6` | output_mismatch | 3/168 | 42/168 | -39 |
| `Key-v5` | output_mismatch | 11/51 | 47/51 | -36 |
| `Matrix-v7` | output_mismatch | 3/168 | 38/168 | -35 |
| `Camera-v7` | output_mismatch | 3/90 | 33/90 | -30 |
| `Camera-v8` | output_mismatch | 3/90 | 33/90 | -30 |
| `Instance-v6` | output_mismatch | 3/52 | 32/52 | -29 |
| `TextFieldHTML-v7` | output_mismatch | 3/37 | 32/37 | -29 |
| `TextFieldHTML-v8` | output_mismatch | 3/37 | 32/37 | -29 |
| `ASnative-v5` | output_mismatch | 3/107 | 30/107 | -27 |
| `Instance-v7` | output_mismatch | 3/52 | 29/52 | -26 |
| `ASnative-v6` | output_mismatch | 3/110 | 28/110 | -25 |
| `ASnative-v7` | output_mismatch | 3/110 | 28/110 | -25 |
| `ASnative-v8` | output_mismatch | 3/110 | 28/110 | -25 |
| `ExternalInterface-v6` | output_mismatch | 3/55 | 28/55 | -25 |
| `ExternalInterface-v7` | output_mismatch | 3/55 | 28/55 | -25 |
| `Error-v6` | output_mismatch | 3/31 | 27/31 | -24 |
| `Error-v7` | output_mismatch | 3/31 | 27/31 | -24 |
| `Error-v8` | output_mismatch | 3/31 | 27/31 | -24 |
| `Error-v5` | output_mismatch | 3/28 | 24/28 | -21 |
| `Instance-v8` | output_mismatch | 3/52 | 23/52 | -20 |
| `with-v6` | output_mismatch | 3/107 | 23/107 | -20 |
| `with-v7` | output_mismatch | 3/107 | 23/107 | -20 |
| `with-v8` | output_mismatch | 3/107 | 23/107 | -20 |
| `enumerate-v7` | output_mismatch | 3/49 | 22/49 | -19 |
| `enumerate-v8` | output_mismatch | 3/49 | 22/49 | -19 |
| `case-v7` | output_mismatch | 3/67 | 13/67 | -10 |
| `case-v8` | output_mismatch | 3/67 | 13/67 | -10 |
| `targetPath-v6` | output_mismatch | 3/23 | 9/23 | -6 |
| `targetPath-v7` | output_mismatch | 3/23 | 9/23 | -6 |
| `targetPath-v8` | output_mismatch | 3/23 | 9/23 | -6 |
| `TextField-v5` | output_mismatch | 3/12 | 8/12 | -5 |
| `flash-v5` | output_mismatch | 3/10 | 7/10 | -4 |
| `flash-v6` | output_mismatch | 3/10 | 7/10 | -4 |
| `flash-v7` | output_mismatch | 3/10 | 7/10 | -4 |
| `AsBroadcaster-v5` | output_mismatch | 5/11 | 8/11 | -3 |
| `AsBroadcaster-v7` | output_mismatch | 86/121 | 87/121 | -1 |
| `AsBroadcaster-v8` | output_mismatch | 86/121 | 87/121 | -1 |
| `LocalConnection-v5` | output_mismatch | 3/7 | 4/7 | -1 |
| `NetConnection-v5` | output_mismatch | 3/7 | 4/7 | -1 |
| `Selection-v6` | output_mismatch | 109/125 | 110/125 | -1 |
| `Selection-v7` | output_mismatch | 110/125 | 111/125 | -1 |
| `Selection-v8` | output_mismatch | 110/125 | 111/125 | -1 |
| `Transform-v6` | output_mismatch | 3/7 | 4/7 | -1 |
| `Transform-v7` | output_mismatch | 3/7 | 4/7 | -1 |
| `Video-v5` | output_mismatch | 3/7 | 4/7 | -1 |
| `Instance-v5` | output_mismatch | 32/52 | 31/52 | +1 |
