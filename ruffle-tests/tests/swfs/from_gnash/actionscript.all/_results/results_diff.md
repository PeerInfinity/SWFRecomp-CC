# Ruffle Test Results Diff

**Previous:** `e0af5c2d15d5` (2026-05-07T03:24:59.831355+00:00)
**Current:** `873e520ed49f` (2026-05-07T16:51:19.158223+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 126 | 0 | -126 |
| Total | 190 | 190 | 0 |
| Pass rate | 66.3% | 0.0% | -66.3% |
| Mismatched lines | 1583 | 16957 | +15374 |
|   Increased | | | +15374 |

## Newly Failing (126)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `Accessibility-v5` | output_mismatch | 15/15 | 0/15 |
| `Accessibility-v6` | output_mismatch | 19/19 | 0/19 |
| `Accessibility-v7` | output_mismatch | 19/19 | 0/19 |
| `Accessibility-v8` | output_mismatch | 19/19 | 0/19 |
| `AsBroadcaster-v5` | output_mismatch | 11/11 | 0/11 |
| `BitmapData-v5` | output_mismatch | 7/7 | 0/7 |
| `BitmapData-v6` | output_mismatch | 7/7 | 0/7 |
| `BitmapData-v7` | output_mismatch | 7/7 | 0/7 |
| `Boolean-v5` | output_mismatch | 38/38 | 0/38 |
| `Boolean-v6` | output_mismatch | 38/38 | 0/38 |
| `Boolean-v7` | output_mismatch | 38/38 | 0/38 |
| `Boolean-v8` | output_mismatch | 38/38 | 0/38 |
| `Camera-v5` | output_mismatch | 7/7 | 0/7 |
| `Color-v5` | output_mismatch | 140/140 | 0/140 |
| `Color-v6` | output_mismatch | 171/171 | 0/171 |
| `Color-v7` | output_mismatch | 161/161 | 0/161 |
| `Color-v8` | output_mismatch | 161/161 | 0/161 |
| `ColorTransform-v5` | output_mismatch | 7/7 | 0/7 |
| `ColorTransform-v6` | output_mismatch | 7/7 | 0/7 |
| `ColorTransform-v7` | output_mismatch | 7/7 | 0/7 |
| `ColorTransform-v8` | output_mismatch | 55/55 | 0/55 |
| `ContextMenu-v5` | output_mismatch | 7/7 | 0/7 |
| `ContextMenu-v6` | output_mismatch | 7/7 | 0/7 |
| `ContextMenu-v7` | output_mismatch | 131/131 | 0/131 |
| `ContextMenu-v8` | output_mismatch | 131/131 | 0/131 |
| `Error-v5` | output_mismatch | 28/28 | 0/28 |
| `Error-v6` | output_mismatch | 31/31 | 0/31 |
| `Error-v7` | output_mismatch | 31/31 | 0/31 |
| `Error-v8` | output_mismatch | 31/31 | 0/31 |
| `ExternalInterface-v5` | output_mismatch | 7/7 | 0/7 |
| `ExternalInterface-v6` | output_mismatch | 55/55 | 0/55 |
| `ExternalInterface-v7` | output_mismatch | 55/55 | 0/55 |
| `Global-v7` | output_mismatch | 182/182 | 0/182 |
| `Global-v8` | output_mismatch | 169/169 | 0/169 |
| `Instance-v5` | output_mismatch | 52/52 | 0/52 |
| `Instance-v6` | output_mismatch | 52/52 | 0/52 |
| `Instance-v7` | output_mismatch | 52/52 | 0/52 |
| `Instance-v8` | output_mismatch | 52/52 | 0/52 |
| `Key-v5` | output_mismatch | 51/51 | 0/51 |
| `Key-v6` | output_mismatch | 55/55 | 0/55 |
| `Key-v7` | output_mismatch | 55/55 | 0/55 |
| `Key-v8` | output_mismatch | 55/55 | 0/55 |
| `LoadVars-v5` | output_mismatch | 8/8 | 0/8 |
| `LocalConnection-v5` | output_mismatch | 7/7 | 0/7 |
| `LocalConnection-v6` | output_mismatch | 58/58 | 0/58 |
| `LocalConnection-v7` | output_mismatch | 58/58 | 0/58 |
| `LocalConnection-v8` | output_mismatch | 58/58 | 0/58 |
| `Matrix-v5` | output_mismatch | 7/7 | 0/7 |
| `Microphone-v5` | output_mismatch | 6/6 | 0/6 |
| `Mouse-v5` | output_mismatch | 13/13 | 0/13 |
| `Mouse-v6` | output_mismatch | 21/21 | 0/21 |
| `Mouse-v7` | output_mismatch | 21/21 | 0/21 |
| `Mouse-v8` | output_mismatch | 21/21 | 0/21 |
| `MovieClipLoader-v5` | output_mismatch | 6/6 | 0/6 |
| `MovieClipLoader-v6` | output_mismatch | 6/6 | 0/6 |
| `NetConnection-v5` | output_mismatch | 7/7 | 0/7 |
| `NetStream-v5` | output_mismatch | 6/6 | 0/6 |
| `NetStream-v6` | output_mismatch | 80/80 | 0/80 |
| `NetStream-v7` | output_mismatch | 80/80 | 0/80 |
| `NetStream-v8` | output_mismatch | 80/80 | 0/80 |
| `Number-v6` | output_mismatch | 239/239 | 0/239 |
| `Number-v7` | output_mismatch | 237/237 | 0/237 |
| `Number-v8` | output_mismatch | 237/237 | 0/237 |
| `Point-v5` | output_mismatch | 7/7 | 0/7 |
| `Point-v6` | output_mismatch | 7/7 | 0/7 |
| `Point-v7` | output_mismatch | 7/7 | 0/7 |
| `Point-v8` | output_mismatch | 193/193 | 0/193 |
| `Random-v5` | output_mismatch | 30/30 | 0/30 |
| `Random-v6` | output_mismatch | 30/30 | 0/30 |
| `Random-v7` | output_mismatch | 30/30 | 0/30 |
| `Random-v8` | output_mismatch | 30/30 | 0/30 |
| `Rectangle-v5` | output_mismatch | 7/7 | 0/7 |
| `Rectangle-v6` | output_mismatch | 7/7 | 0/7 |
| `Rectangle-v7` | output_mismatch | 7/7 | 0/7 |
| `Selection-v5` | output_mismatch | 21/21 | 0/21 |
| `Stage-v5` | output_mismatch | 38/38 | 0/38 |
| `System-v5` | output_mismatch | 67/67 | 0/67 |
| `System-v6` | output_mismatch | 100/100 | 0/100 |
| `System-v7` | output_mismatch | 101/101 | 0/101 |
| `System-v8` | output_mismatch | 101/101 | 0/101 |
| `TextFieldHTML-v5` | output_mismatch | 6/6 | 0/6 |
| `TextFieldHTML-v6` | output_mismatch | 37/37 | 0/37 |
| `TextFieldHTML-v7` | output_mismatch | 37/37 | 0/37 |
| `TextFieldHTML-v8` | output_mismatch | 37/37 | 0/37 |
| `TextFormat-v5` | output_mismatch | 128/128 | 0/128 |
| `TextFormat-v6` | output_mismatch | 128/128 | 0/128 |
| `TextSnapshot-v5` | output_mismatch | 7/7 | 0/7 |
| `TextSnapshot-v6` | output_mismatch | 173/173 | 0/173 |
| `TextSnapshot-v7` | output_mismatch | 173/173 | 0/173 |
| `TextSnapshot-v8` | output_mismatch | 173/173 | 0/173 |
| `Transform-v5` | output_mismatch | 7/7 | 0/7 |
| `Transform-v6` | output_mismatch | 7/7 | 0/7 |
| `Transform-v7` | output_mismatch | 7/7 | 0/7 |
| `Try-v5` | output_mismatch | 20/20 | 0/20 |
| `Try-v6` | output_mismatch | 20/20 | 0/20 |
| `Try-v7` | output_mismatch | 20/20 | 0/20 |
| `Try-v8` | output_mismatch | 20/20 | 0/20 |
| `Video-v5` | output_mismatch | 7/7 | 0/7 |
| `Video-v6` | output_mismatch | 85/85 | 0/85 |
| `Video-v7` | output_mismatch | 85/85 | 0/85 |
| `Video-v8` | output_mismatch | 85/85 | 0/85 |
| `XMLSocket-v5` | output_mismatch | 35/35 | 0/35 |
| `XMLSocket-v6` | output_mismatch | 35/35 | 0/35 |
| `XMLSocket-v7` | output_mismatch | 35/35 | 0/35 |
| `XMLSocket-v8` | output_mismatch | 35/35 | 0/35 |
| `argstest-v5` | output_mismatch | 4/4 | 0/4 |
| `case-v5` | output_mismatch | 39/39 | 0/39 |
| `case-v6` | output_mismatch | 73/73 | 0/73 |
| `case-v7` | output_mismatch | 67/67 | 0/67 |
| `case-v8` | output_mismatch | 67/67 | 0/67 |
| `delete-v5` | output_mismatch | 60/60 | 0/60 |
| `delete-v6` | output_mismatch | 60/60 | 0/60 |
| `delete-v7` | output_mismatch | 60/60 | 0/60 |
| `delete-v8` | output_mismatch | 60/60 | 0/60 |
| `enumerate-v5` | output_mismatch | 6/6 | 0/6 |
| `enumerate-v6` | output_mismatch | 49/49 | 0/49 |
| `enumerate-v7` | output_mismatch | 49/49 | 0/49 |
| `enumerate-v8` | output_mismatch | 49/49 | 0/49 |
| `flash-v5` | output_mismatch | 10/10 | 0/10 |
| `flash-v6` | output_mismatch | 10/10 | 0/10 |
| `flash-v7` | output_mismatch | 10/10 | 0/10 |
| `swap-v5` | output_mismatch | 7/7 | 0/7 |
| `swap-v6` | output_mismatch | 7/7 | 0/7 |
| `swap-v7` | output_mismatch | 7/7 | 0/7 |
| `swap-v8` | output_mismatch | 7/7 | 0/7 |
| `targetPath-v5` | output_mismatch | 12/12 | 0/12 |

## Status Changed (63)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | ruffle_matched | output_mismatch | 72/107 | 0/107 |
| `ASnative-v6` | ruffle_matched | output_mismatch | 70/110 | 0/110 |
| `ASnative-v7` | ruffle_matched | output_mismatch | 70/110 | 0/110 |
| `ASnative-v8` | ruffle_matched | output_mismatch | 70/110 | 0/110 |
| `AsBroadcaster-v6` | ruffle_matched | output_mismatch | 114/121 | 0/121 |
| `AsBroadcaster-v7` | ruffle_matched | output_mismatch | 114/121 | 0/121 |
| `AsBroadcaster-v8` | ruffle_matched | output_mismatch | 114/121 | 0/121 |
| `BitmapData-v8` | ruffle_matched | output_mismatch | 409/417 | 0/417 |
| `Camera-v6` | ruffle_matched | output_mismatch | 33/90 | 0/90 |
| `Camera-v7` | ruffle_matched | output_mismatch | 33/90 | 0/90 |
| `Camera-v8` | ruffle_matched | output_mismatch | 33/90 | 0/90 |
| `ExternalInterface-v8` | ruffle_matched | output_mismatch | 114/118 | 0/118 |
| `Global-v6` | ruffle_matched | output_mismatch | 201/210 | 0/210 |
| `HitTest-v6` | ruffle_matched | output_mismatch | 80/88 | 0/88 |
| `HitTest-v7` | ruffle_matched | output_mismatch | 80/88 | 0/88 |
| `HitTest-v8` | ruffle_matched | output_mismatch | 79/88 | 0/88 |
| `Inheritance-v5` | ruffle_matched | output_mismatch | 114/114 | 0/114 |
| `Inheritance-v6` | ruffle_matched | output_mismatch | 173/181 | 0/181 |
| `Inheritance-v7` | ruffle_matched | output_mismatch | 177/181 | 0/181 |
| `Inheritance-v8` | ruffle_matched | output_mismatch | 177/181 | 0/181 |
| `LoadVars-v6` | ruffle_matched | output_mismatch | 146/152 | 0/152 |
| `LoadVars-v7` | ruffle_matched | output_mismatch | 146/152 | 0/152 |
| `LoadVars-v8` | ruffle_matched | output_mismatch | 146/152 | 0/152 |
| `Math-v5` | ruffle_matched | output_mismatch | 273/278 | 0/278 |
| `Math-v6` | ruffle_matched | output_mismatch | 273/278 | 0/278 |
| `Math-v7` | ruffle_matched | output_mismatch | 282/287 | 0/287 |
| `Math-v8` | ruffle_matched | output_mismatch | 282/287 | 0/287 |
| `Matrix-v6` | ruffle_matched | output_mismatch | 139/168 | 0/168 |
| `Matrix-v7` | ruffle_matched | output_mismatch | 140/168 | 0/168 |
| `Matrix-v8` | ruffle_matched | output_mismatch | 140/168 | 0/168 |
| `Microphone-v6` | ruffle_matched | output_mismatch | 48/79 | 0/79 |
| `Microphone-v7` | ruffle_matched | output_mismatch | 48/79 | 0/79 |
| `Microphone-v8` | ruffle_matched | output_mismatch | 48/79 | 0/79 |
| `MovieClip-v5` | ruffle_matched | output_mismatch | 315/363 | 0/363 |
| `MovieClipLoader-v7` | ruffle_matched | output_mismatch | 47/165 | 0/165 |
| `MovieClipLoader-v8` | ruffle_matched | output_mismatch | 47/165 | 0/165 |
| `Number-v5` | ruffle_matched | output_mismatch | 236/244 | 0/244 |
| `Rectangle-v8` | ruffle_matched | output_mismatch | 145/166 | 0/166 |
| `Selection-v6` | ruffle_matched | output_mismatch | 118/125 | 0/125 |
| `Selection-v7` | ruffle_matched | output_mismatch | 118/125 | 0/125 |
| `Selection-v8` | ruffle_matched | output_mismatch | 118/125 | 0/125 |
| `Sound-v5` | ruffle_matched | output_mismatch | 73/100 | 0/100 |
| `Sound-v6` | ruffle_matched | output_mismatch | 91/121 | 0/121 |
| `Sound-v7` | ruffle_matched | output_mismatch | 93/121 | 0/121 |
| `Sound-v8` | ruffle_matched | output_mismatch | 93/121 | 0/121 |
| `String-v5` | ruffle_matched | output_mismatch | 339/358 | 0/358 |
| `String-v6` | ruffle_matched | output_mismatch | 367/377 | 0/377 |
| `String-v7` | ruffle_matched | output_mismatch | 367/377 | 0/377 |
| `String-v8` | ruffle_matched | output_mismatch | 367/377 | 0/377 |
| `TextField-v5` | ruffle_matched | output_mismatch | 9/12 | 0/12 |
| `TextFormat-v7` | ruffle_matched | output_mismatch | 136/174 | 0/174 |
| `ops-v8` | ruffle_matched | output_mismatch | 255/262 | 0/262 |
| `targetPath-v6` | ruffle_matched | output_mismatch | 9/23 | 0/23 |
| `targetPath-v7` | ruffle_matched | output_mismatch | 9/23 | 0/23 |
| `targetPath-v8` | ruffle_matched | output_mismatch | 9/23 | 0/23 |
| `toString_valueOf-v5` | ruffle_matched | output_mismatch | 103/137 | 0/137 |
| `toString_valueOf-v6` | ruffle_matched | output_mismatch | 150/155 | 0/155 |
| `toString_valueOf-v7` | ruffle_matched | output_mismatch | 150/155 | 0/155 |
| `toString_valueOf-v8` | ruffle_matched | output_mismatch | 150/155 | 0/155 |
| `with-v5` | ruffle_matched | output_mismatch | 21/49 | 0/49 |
| `with-v6` | ruffle_matched | output_mismatch | 23/107 | 0/107 |
| `with-v7` | ruffle_matched | output_mismatch | 23/107 | 0/107 |
| `with-v8` | ruffle_matched | output_mismatch | 23/107 | 0/107 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array-v5` | output_mismatch | 517/560 | 0/560 | +517 |
