# Ruffle Test Results Diff

**Previous:** `8d0f9c63c087` (2026-04-01T20:15:46.253795+00:00)
**Current:** `33b4d52d1573` (2026-04-02T01:29:20.520350+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 58 | 5 | -53 |
| Total | 190 | 190 | 0 |
| Pass rate | 30.5% | 2.6% | -27.9% |
| Mismatched lines | 5206 | 14320 | +9114 |
|   Decreased | | | -133 |
|   Increased | | | +9247 |

## Newly Failing (53)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `Accessibility-v5` | output_mismatch | 15/15 | 3/15 |
| `BitmapData-v5` | output_mismatch | 7/7 | 3/7 |
| `BitmapData-v6` | output_mismatch | 7/7 | 3/7 |
| `BitmapData-v7` | output_mismatch | 7/7 | 3/7 |
| `Boolean-v5` | output_mismatch | 38/38 | 3/38 |
| `Boolean-v6` | output_mismatch | 38/38 | 3/38 |
| `Boolean-v7` | output_mismatch | 38/38 | 3/38 |
| `Boolean-v8` | output_mismatch | 38/38 | 3/38 |
| `Camera-v5` | output_mismatch | 7/7 | 3/7 |
| `Color-v5` | output_mismatch | 140/140 | 3/140 |
| `Color-v7` | output_mismatch | 161/161 | 3/161 |
| `Color-v8` | output_mismatch | 161/161 | 3/161 |
| `ColorTransform-v5` | output_mismatch | 7/7 | 3/7 |
| `ColorTransform-v6` | output_mismatch | 7/7 | 3/7 |
| `ColorTransform-v7` | output_mismatch | 7/7 | 3/7 |
| `ContextMenu-v5` | output_mismatch | 7/7 | 3/7 |
| `ContextMenu-v6` | output_mismatch | 7/7 | 3/7 |
| `ExternalInterface-v5` | output_mismatch | 7/7 | 3/7 |
| `LoadVars-v5` | output_mismatch | 8/8 | 3/8 |
| `Matrix-v5` | output_mismatch | 7/7 | 3/7 |
| `Microphone-v5` | output_mismatch | 6/6 | 3/6 |
| `MovieClipLoader-v5` | output_mismatch | 6/6 | 3/6 |
| `MovieClipLoader-v6` | output_mismatch | 6/6 | 3/6 |
| `NetStream-v5` | output_mismatch | 6/6 | 3/6 |
| `Point-v5` | output_mismatch | 7/7 | 3/7 |
| `Point-v6` | output_mismatch | 7/7 | 3/7 |
| `Point-v7` | output_mismatch | 7/7 | 3/7 |
| `Random-v5` | output_mismatch | 30/30 | 3/30 |
| `Random-v6` | output_mismatch | 30/30 | 3/30 |
| `Random-v7` | output_mismatch | 30/30 | 3/30 |
| `Random-v8` | output_mismatch | 30/30 | 3/30 |
| `Rectangle-v5` | output_mismatch | 7/7 | 3/7 |
| `Rectangle-v6` | output_mismatch | 7/7 | 3/7 |
| `Rectangle-v7` | output_mismatch | 7/7 | 3/7 |
| `Selection-v5` | output_mismatch | 21/21 | 4/21 |
| `TextFieldHTML-v5` | output_mismatch | 6/6 | 3/6 |
| `TextSnapshot-v5` | output_mismatch | 7/7 | 3/7 |
| `Transform-v5` | output_mismatch | 7/7 | 3/7 |
| `Try-v5` | output_mismatch | 20/20 | 3/20 |
| `Try-v6` | output_mismatch | 20/20 | 3/20 |
| `Try-v7` | output_mismatch | 20/20 | 3/20 |
| `Try-v8` | output_mismatch | 20/20 | 3/20 |
| `Video-v7` | output_mismatch | 85/85 | 3/85 |
| `Video-v8` | output_mismatch | 85/85 | 3/85 |
| `XMLSocket-v7` | output_mismatch | 35/35 | 3/35 |
| `XMLSocket-v8` | output_mismatch | 35/35 | 3/35 |
| `argstest-v5` | output_mismatch | 4/4 | 3/4 |
| `enumerate-v5` | output_mismatch | 6/6 | 3/6 |
| `swap-v5` | output_mismatch | 7/7 | 3/7 |
| `swap-v6` | output_mismatch | 7/7 | 3/7 |
| `swap-v7` | output_mismatch | 7/7 | 3/7 |
| `swap-v8` | output_mismatch | 7/7 | 3/7 |
| `targetPath-v5` | output_mismatch | 12/12 | 3/12 |

## Line Count Changed (108)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `System-v7` | output_mismatch | 40/101 | 83/101 | -43 |
| `System-v8` | output_mismatch | 40/101 | 83/101 | -43 |
| `System-v6` | output_mismatch | 40/100 | 82/100 | -42 |
| `toString_valueOf-v7` | output_mismatch | 131/155 | 133/155 | -2 |
| `toString_valueOf-v8` | output_mismatch | 131/155 | 133/155 | -2 |
| `Instance-v5` | output_mismatch | 31/52 | 32/52 | -1 |
| `LocalConnection-v5` | output_mismatch | 4/7 | 3/7 | +1 |
| `NetConnection-v5` | output_mismatch | 4/7 | 3/7 | +1 |
| `Selection-v6` | output_mismatch | 110/125 | 109/125 | +1 |
| `Transform-v6` | output_mismatch | 4/7 | 3/7 | +1 |
| `Transform-v7` | output_mismatch | 4/7 | 3/7 | +1 |
| `Video-v5` | output_mismatch | 4/7 | 3/7 | +1 |
| `AsBroadcaster-v5` | output_mismatch | 8/11 | 5/11 | +3 |
| `flash-v5` | output_mismatch | 7/10 | 3/10 | +4 |
| `flash-v6` | output_mismatch | 7/10 | 3/10 | +4 |
| `flash-v7` | output_mismatch | 7/10 | 3/10 | +4 |
| `Mouse-v5` | output_mismatch | 8/13 | 3/13 | +5 |
| `TextField-v5` | output_mismatch | 8/12 | 3/12 | +5 |
| `targetPath-v6` | output_mismatch | 9/23 | 3/23 | +6 |
| `targetPath-v7` | output_mismatch | 9/23 | 3/23 | +6 |
| `targetPath-v8` | output_mismatch | 9/23 | 3/23 | +6 |
| `Accessibility-v6` | output_mismatch | 10/19 | 3/19 | +7 |
| `Accessibility-v7` | output_mismatch | 10/19 | 3/19 | +7 |
| `Accessibility-v8` | output_mismatch | 10/19 | 3/19 | +7 |
| `Error-v5` | output_mismatch | 13/28 | 3/28 | +10 |
| `Error-v6` | output_mismatch | 13/31 | 3/31 | +10 |
| `Error-v7` | output_mismatch | 13/31 | 3/31 | +10 |
| `Error-v8` | output_mismatch | 13/31 | 3/31 | +10 |
| `Mouse-v6` | output_mismatch | 13/21 | 3/21 | +10 |
| `Mouse-v7` | output_mismatch | 13/21 | 3/21 | +10 |
| `Mouse-v8` | output_mismatch | 13/21 | 3/21 | +10 |
| `case-v7` | output_mismatch | 13/67 | 3/67 | +10 |
| `case-v8` | output_mismatch | 13/67 | 3/67 | +10 |
| `Key-v6` | output_mismatch | 16/55 | 3/55 | +13 |
| `Key-v7` | output_mismatch | 16/55 | 3/55 | +13 |
| `Key-v8` | output_mismatch | 16/55 | 3/55 | +13 |
| `enumerate-v7` | output_mismatch | 22/49 | 3/49 | +19 |
| `enumerate-v8` | output_mismatch | 22/49 | 3/49 | +19 |
| `with-v6` | output_mismatch | 23/107 | 3/107 | +20 |
| `with-v7` | output_mismatch | 23/107 | 3/107 | +20 |
| `with-v8` | output_mismatch | 23/107 | 3/107 | +20 |
| `Instance-v8` | output_mismatch | 26/52 | 3/52 | +23 |
| `System-v5` | output_mismatch | 26/67 | 3/67 | +23 |
| `ASnative-v6` | output_mismatch | 28/110 | 3/110 | +25 |
| `ASnative-v7` | output_mismatch | 28/110 | 3/110 | +25 |
| `ASnative-v8` | output_mismatch | 28/110 | 3/110 | +25 |
| `ExternalInterface-v6` | output_mismatch | 28/55 | 3/55 | +25 |
| `ExternalInterface-v7` | output_mismatch | 28/55 | 3/55 | +25 |
| `ASnative-v5` | output_mismatch | 30/107 | 3/107 | +27 |
| `Instance-v7` | output_mismatch | 31/52 | 3/52 | +28 |
| `Instance-v6` | output_mismatch | 32/52 | 3/52 | +29 |
| `TextFieldHTML-v7` | output_mismatch | 32/37 | 3/37 | +29 |
| `TextFieldHTML-v8` | output_mismatch | 32/37 | 3/37 | +29 |
| `Camera-v7` | output_mismatch | 33/90 | 3/90 | +30 |
| `Camera-v8` | output_mismatch | 33/90 | 3/90 | +30 |
| `Matrix-v7` | output_mismatch | 38/168 | 3/168 | +35 |
| `Matrix-v6` | output_mismatch | 42/168 | 3/168 | +39 |
| `ColorTransform-v8` | output_mismatch | 46/55 | 3/55 | +43 |
| `MovieClipLoader-v7` | output_mismatch | 46/165 | 3/165 | +43 |
| `MovieClipLoader-v8` | output_mismatch | 46/165 | 3/165 | +43 |
| `Microphone-v7` | output_mismatch | 48/79 | 3/79 | +45 |
| `Microphone-v8` | output_mismatch | 48/79 | 3/79 | +45 |
| `LoadVars-v6` | output_mismatch | 67/152 | 3/152 | +64 |
| `LoadVars-v7` | output_mismatch | 67/152 | 3/152 | +64 |
| `LoadVars-v8` | output_mismatch | 67/152 | 3/152 | +64 |
| `HitTest-v6` | output_mismatch | 70/88 | 3/88 | +67 |
| `NetStream-v6` | output_mismatch | 76/80 | 3/80 | +73 |
| `Sound-v7` | output_mismatch | 76/121 | 3/121 | +73 |
| `Sound-v8` | output_mismatch | 76/121 | 3/121 | +73 |
| `Sound-v5` | output_mismatch | 77/100 | 3/100 | +74 |
| `toString_valueOf-v5` | output_mismatch | 82/137 | 3/137 | +79 |
| `ContextMenu-v7` | output_mismatch | 95/131 | 3/131 | +92 |
| `ContextMenu-v8` | output_mismatch | 95/131 | 3/131 | +92 |
| `AsBroadcaster-v6` | output_mismatch | 97/121 | 3/121 | +94 |
| `Inheritance-v5` | output_mismatch | 97/114 | 3/114 | +94 |
| `TextFormat-v5` | output_mismatch | 101/128 | 3/128 | +98 |
| `TextFormat-v6` | output_mismatch | 101/128 | 3/128 | +98 |
| `TextFormat-v7` | output_mismatch | 113/174 | 3/174 | +110 |
| `toString_valueOf-v6` | output_mismatch | 130/155 | 3/155 | +127 |
| `Global-v8` | output_mismatch | 131/169 | 3/169 | +128 |
| `Rectangle-v8` | output_mismatch | 132/166 | 3/166 | +129 |
| `TextSnapshot-v6` | output_mismatch | 132/173 | 3/173 | +129 |
| `TextSnapshot-v7` | output_mismatch | 132/173 | 3/173 | +129 |
| `TextSnapshot-v8` | output_mismatch | 132/173 | 3/173 | +129 |
| `Global-v7` | output_mismatch | 137/182 | 3/182 | +134 |
| `Matrix-v8` | output_mismatch | 139/168 | 3/168 | +136 |
| `Global-v6` | output_mismatch | 149/210 | 3/210 | +146 |
| `Color-v6` | output_mismatch | 165/171 | 3/171 | +162 |
| `Inheritance-v6` | output_mismatch | 165/181 | 3/181 | +162 |
| `Point-v8` | output_mismatch | 166/193 | 3/193 | +163 |
| `Inheritance-v7` | output_mismatch | 176/181 | 3/181 | +173 |
| `Inheritance-v8` | output_mismatch | 177/181 | 3/181 | +174 |
| `Number-v6` | output_mismatch | 178/239 | 3/239 | +175 |
| `Number-v7` | output_mismatch | 183/237 | 3/237 | +180 |
| `Number-v8` | output_mismatch | 183/237 | 3/237 | +180 |
| `Number-v5` | output_mismatch | 185/244 | 3/244 | +182 |
| `String-v5` | output_mismatch | 218/358 | 3/358 | +215 |
| `String-v7` | output_mismatch | 232/377 | 3/377 | +229 |
| `String-v8` | output_mismatch | 232/377 | 3/377 | +229 |
| `String-v6` | output_mismatch | 235/377 | 3/377 | +232 |
| `MovieClip-v5` | output_mismatch | 240/363 | 3/363 | +237 |
| `BitmapData-v8` | output_mismatch | 252/417 | 3/417 | +249 |
| `ops-v8` | output_mismatch | 255/262 | 3/262 | +252 |
| `Math-v5` | output_mismatch | 273/278 | 3/278 | +270 |
| `Math-v6` | output_mismatch | 273/278 | 3/278 | +270 |
| `Math-v7` | output_mismatch | 282/287 | 3/287 | +279 |
| `Math-v8` | output_mismatch | 282/287 | 3/287 | +279 |
| `array-v5` | output_mismatch | 348/560 | 3/560 | +345 |
