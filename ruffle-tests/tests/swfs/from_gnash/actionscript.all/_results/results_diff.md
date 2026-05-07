# Ruffle Test Results Diff

**Previous:** `873e520ed49f` (2026-05-07T16:51:19.158223+00:00)
**Current:** `8fdf331148d6` (2026-05-07T17:29:28.009886+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 126 | +126 |
| Total | 190 | 190 | 0 |
| Pass rate | 0.0% | 66.3% | +66.3% |
| Mismatched lines | 16957 | 1583 | -15374 |
|   Decreased | | | -15374 |

## Newly Passing (126)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `Accessibility-v5` | output_mismatch | 0/15 | 15/15 |
| `Accessibility-v6` | output_mismatch | 0/19 | 19/19 |
| `Accessibility-v7` | output_mismatch | 0/19 | 19/19 |
| `Accessibility-v8` | output_mismatch | 0/19 | 19/19 |
| `AsBroadcaster-v5` | output_mismatch | 0/11 | 11/11 |
| `BitmapData-v5` | output_mismatch | 0/7 | 7/7 |
| `BitmapData-v6` | output_mismatch | 0/7 | 7/7 |
| `BitmapData-v7` | output_mismatch | 0/7 | 7/7 |
| `Boolean-v5` | output_mismatch | 0/38 | 38/38 |
| `Boolean-v6` | output_mismatch | 0/38 | 38/38 |
| `Boolean-v7` | output_mismatch | 0/38 | 38/38 |
| `Boolean-v8` | output_mismatch | 0/38 | 38/38 |
| `Camera-v5` | output_mismatch | 0/7 | 7/7 |
| `Color-v5` | output_mismatch | 0/140 | 140/140 |
| `Color-v6` | output_mismatch | 0/171 | 171/171 |
| `Color-v7` | output_mismatch | 0/161 | 161/161 |
| `Color-v8` | output_mismatch | 0/161 | 161/161 |
| `ColorTransform-v5` | output_mismatch | 0/7 | 7/7 |
| `ColorTransform-v6` | output_mismatch | 0/7 | 7/7 |
| `ColorTransform-v7` | output_mismatch | 0/7 | 7/7 |
| `ColorTransform-v8` | output_mismatch | 0/55 | 55/55 |
| `ContextMenu-v5` | output_mismatch | 0/7 | 7/7 |
| `ContextMenu-v6` | output_mismatch | 0/7 | 7/7 |
| `ContextMenu-v7` | output_mismatch | 0/131 | 131/131 |
| `ContextMenu-v8` | output_mismatch | 0/131 | 131/131 |
| `Error-v5` | output_mismatch | 0/28 | 28/28 |
| `Error-v6` | output_mismatch | 0/31 | 31/31 |
| `Error-v7` | output_mismatch | 0/31 | 31/31 |
| `Error-v8` | output_mismatch | 0/31 | 31/31 |
| `ExternalInterface-v5` | output_mismatch | 0/7 | 7/7 |
| `ExternalInterface-v6` | output_mismatch | 0/55 | 55/55 |
| `ExternalInterface-v7` | output_mismatch | 0/55 | 55/55 |
| `Global-v7` | output_mismatch | 0/182 | 182/182 |
| `Global-v8` | output_mismatch | 0/169 | 169/169 |
| `Instance-v5` | output_mismatch | 0/52 | 52/52 |
| `Instance-v6` | output_mismatch | 0/52 | 52/52 |
| `Instance-v7` | output_mismatch | 0/52 | 52/52 |
| `Instance-v8` | output_mismatch | 0/52 | 52/52 |
| `Key-v5` | output_mismatch | 0/51 | 51/51 |
| `Key-v6` | output_mismatch | 0/55 | 55/55 |
| `Key-v7` | output_mismatch | 0/55 | 55/55 |
| `Key-v8` | output_mismatch | 0/55 | 55/55 |
| `LoadVars-v5` | output_mismatch | 0/8 | 8/8 |
| `LocalConnection-v5` | output_mismatch | 0/7 | 7/7 |
| `LocalConnection-v6` | output_mismatch | 0/58 | 58/58 |
| `LocalConnection-v7` | output_mismatch | 0/58 | 58/58 |
| `LocalConnection-v8` | output_mismatch | 0/58 | 58/58 |
| `Matrix-v5` | output_mismatch | 0/7 | 7/7 |
| `Microphone-v5` | output_mismatch | 0/6 | 6/6 |
| `Mouse-v5` | output_mismatch | 0/13 | 13/13 |
| `Mouse-v6` | output_mismatch | 0/21 | 21/21 |
| `Mouse-v7` | output_mismatch | 0/21 | 21/21 |
| `Mouse-v8` | output_mismatch | 0/21 | 21/21 |
| `MovieClipLoader-v5` | output_mismatch | 0/6 | 6/6 |
| `MovieClipLoader-v6` | output_mismatch | 0/6 | 6/6 |
| `NetConnection-v5` | output_mismatch | 0/7 | 7/7 |
| `NetStream-v5` | output_mismatch | 0/6 | 6/6 |
| `NetStream-v6` | output_mismatch | 0/80 | 80/80 |
| `NetStream-v7` | output_mismatch | 0/80 | 80/80 |
| `NetStream-v8` | output_mismatch | 0/80 | 80/80 |
| `Number-v6` | output_mismatch | 0/239 | 239/239 |
| `Number-v7` | output_mismatch | 0/237 | 237/237 |
| `Number-v8` | output_mismatch | 0/237 | 237/237 |
| `Point-v5` | output_mismatch | 0/7 | 7/7 |
| `Point-v6` | output_mismatch | 0/7 | 7/7 |
| `Point-v7` | output_mismatch | 0/7 | 7/7 |
| `Point-v8` | output_mismatch | 0/193 | 193/193 |
| `Random-v5` | output_mismatch | 0/30 | 30/30 |
| `Random-v6` | output_mismatch | 0/30 | 30/30 |
| `Random-v7` | output_mismatch | 0/30 | 30/30 |
| `Random-v8` | output_mismatch | 0/30 | 30/30 |
| `Rectangle-v5` | output_mismatch | 0/7 | 7/7 |
| `Rectangle-v6` | output_mismatch | 0/7 | 7/7 |
| `Rectangle-v7` | output_mismatch | 0/7 | 7/7 |
| `Selection-v5` | output_mismatch | 0/21 | 21/21 |
| `Stage-v5` | output_mismatch | 0/38 | 38/38 |
| `System-v5` | output_mismatch | 0/67 | 67/67 |
| `System-v6` | output_mismatch | 0/100 | 100/100 |
| `System-v7` | output_mismatch | 0/101 | 101/101 |
| `System-v8` | output_mismatch | 0/101 | 101/101 |
| `TextFieldHTML-v5` | output_mismatch | 0/6 | 6/6 |
| `TextFieldHTML-v6` | output_mismatch | 0/37 | 37/37 |
| `TextFieldHTML-v7` | output_mismatch | 0/37 | 37/37 |
| `TextFieldHTML-v8` | output_mismatch | 0/37 | 37/37 |
| `TextFormat-v5` | output_mismatch | 0/128 | 128/128 |
| `TextFormat-v6` | output_mismatch | 0/128 | 128/128 |
| `TextSnapshot-v5` | output_mismatch | 0/7 | 7/7 |
| `TextSnapshot-v6` | output_mismatch | 0/173 | 173/173 |
| `TextSnapshot-v7` | output_mismatch | 0/173 | 173/173 |
| `TextSnapshot-v8` | output_mismatch | 0/173 | 173/173 |
| `Transform-v5` | output_mismatch | 0/7 | 7/7 |
| `Transform-v6` | output_mismatch | 0/7 | 7/7 |
| `Transform-v7` | output_mismatch | 0/7 | 7/7 |
| `Try-v5` | output_mismatch | 0/20 | 20/20 |
| `Try-v6` | output_mismatch | 0/20 | 20/20 |
| `Try-v7` | output_mismatch | 0/20 | 20/20 |
| `Try-v8` | output_mismatch | 0/20 | 20/20 |
| `Video-v5` | output_mismatch | 0/7 | 7/7 |
| `Video-v6` | output_mismatch | 0/85 | 85/85 |
| `Video-v7` | output_mismatch | 0/85 | 85/85 |
| `Video-v8` | output_mismatch | 0/85 | 85/85 |
| `XMLSocket-v5` | output_mismatch | 0/35 | 35/35 |
| `XMLSocket-v6` | output_mismatch | 0/35 | 35/35 |
| `XMLSocket-v7` | output_mismatch | 0/35 | 35/35 |
| `XMLSocket-v8` | output_mismatch | 0/35 | 35/35 |
| `argstest-v5` | output_mismatch | 0/4 | 4/4 |
| `case-v5` | output_mismatch | 0/39 | 39/39 |
| `case-v6` | output_mismatch | 0/73 | 73/73 |
| `case-v7` | output_mismatch | 0/67 | 67/67 |
| `case-v8` | output_mismatch | 0/67 | 67/67 |
| `delete-v5` | output_mismatch | 0/60 | 60/60 |
| `delete-v6` | output_mismatch | 0/60 | 60/60 |
| `delete-v7` | output_mismatch | 0/60 | 60/60 |
| `delete-v8` | output_mismatch | 0/60 | 60/60 |
| `enumerate-v5` | output_mismatch | 0/6 | 6/6 |
| `enumerate-v6` | output_mismatch | 0/49 | 49/49 |
| `enumerate-v7` | output_mismatch | 0/49 | 49/49 |
| `enumerate-v8` | output_mismatch | 0/49 | 49/49 |
| `flash-v5` | output_mismatch | 0/10 | 10/10 |
| `flash-v6` | output_mismatch | 0/10 | 10/10 |
| `flash-v7` | output_mismatch | 0/10 | 10/10 |
| `swap-v5` | output_mismatch | 0/7 | 7/7 |
| `swap-v6` | output_mismatch | 0/7 | 7/7 |
| `swap-v7` | output_mismatch | 0/7 | 7/7 |
| `swap-v8` | output_mismatch | 0/7 | 7/7 |
| `targetPath-v5` | output_mismatch | 0/12 | 12/12 |

## Status Changed (63)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `ASnative-v5` | output_mismatch | ruffle_matched | 0/107 | 72/107 |
| `ASnative-v6` | output_mismatch | ruffle_matched | 0/110 | 70/110 |
| `ASnative-v7` | output_mismatch | ruffle_matched | 0/110 | 70/110 |
| `ASnative-v8` | output_mismatch | ruffle_matched | 0/110 | 70/110 |
| `AsBroadcaster-v6` | output_mismatch | ruffle_matched | 0/121 | 114/121 |
| `AsBroadcaster-v7` | output_mismatch | ruffle_matched | 0/121 | 114/121 |
| `AsBroadcaster-v8` | output_mismatch | ruffle_matched | 0/121 | 114/121 |
| `BitmapData-v8` | output_mismatch | ruffle_matched | 0/417 | 409/417 |
| `Camera-v6` | output_mismatch | ruffle_matched | 0/90 | 33/90 |
| `Camera-v7` | output_mismatch | ruffle_matched | 0/90 | 33/90 |
| `Camera-v8` | output_mismatch | ruffle_matched | 0/90 | 33/90 |
| `ExternalInterface-v8` | output_mismatch | ruffle_matched | 0/118 | 114/118 |
| `Global-v6` | output_mismatch | ruffle_matched | 0/210 | 201/210 |
| `HitTest-v6` | output_mismatch | ruffle_matched | 0/88 | 80/88 |
| `HitTest-v7` | output_mismatch | ruffle_matched | 0/88 | 80/88 |
| `HitTest-v8` | output_mismatch | ruffle_matched | 0/88 | 79/88 |
| `Inheritance-v5` | output_mismatch | ruffle_matched | 0/114 | 114/114 |
| `Inheritance-v6` | output_mismatch | ruffle_matched | 0/181 | 173/181 |
| `Inheritance-v7` | output_mismatch | ruffle_matched | 0/181 | 177/181 |
| `Inheritance-v8` | output_mismatch | ruffle_matched | 0/181 | 177/181 |
| `LoadVars-v6` | output_mismatch | ruffle_matched | 0/152 | 146/152 |
| `LoadVars-v7` | output_mismatch | ruffle_matched | 0/152 | 146/152 |
| `LoadVars-v8` | output_mismatch | ruffle_matched | 0/152 | 146/152 |
| `Math-v5` | output_mismatch | ruffle_matched | 0/278 | 273/278 |
| `Math-v6` | output_mismatch | ruffle_matched | 0/278 | 273/278 |
| `Math-v7` | output_mismatch | ruffle_matched | 0/287 | 282/287 |
| `Math-v8` | output_mismatch | ruffle_matched | 0/287 | 282/287 |
| `Matrix-v6` | output_mismatch | ruffle_matched | 0/168 | 139/168 |
| `Matrix-v7` | output_mismatch | ruffle_matched | 0/168 | 140/168 |
| `Matrix-v8` | output_mismatch | ruffle_matched | 0/168 | 140/168 |
| `Microphone-v6` | output_mismatch | ruffle_matched | 0/79 | 48/79 |
| `Microphone-v7` | output_mismatch | ruffle_matched | 0/79 | 48/79 |
| `Microphone-v8` | output_mismatch | ruffle_matched | 0/79 | 48/79 |
| `MovieClip-v5` | output_mismatch | ruffle_matched | 0/363 | 315/363 |
| `MovieClipLoader-v7` | output_mismatch | ruffle_matched | 0/165 | 47/165 |
| `MovieClipLoader-v8` | output_mismatch | ruffle_matched | 0/165 | 47/165 |
| `Number-v5` | output_mismatch | ruffle_matched | 0/244 | 236/244 |
| `Rectangle-v8` | output_mismatch | ruffle_matched | 0/166 | 145/166 |
| `Selection-v6` | output_mismatch | ruffle_matched | 0/125 | 118/125 |
| `Selection-v7` | output_mismatch | ruffle_matched | 0/125 | 118/125 |
| `Selection-v8` | output_mismatch | ruffle_matched | 0/125 | 118/125 |
| `Sound-v5` | output_mismatch | ruffle_matched | 0/100 | 73/100 |
| `Sound-v6` | output_mismatch | ruffle_matched | 0/121 | 91/121 |
| `Sound-v7` | output_mismatch | ruffle_matched | 0/121 | 93/121 |
| `Sound-v8` | output_mismatch | ruffle_matched | 0/121 | 93/121 |
| `String-v5` | output_mismatch | ruffle_matched | 0/358 | 339/358 |
| `String-v6` | output_mismatch | ruffle_matched | 0/377 | 367/377 |
| `String-v7` | output_mismatch | ruffle_matched | 0/377 | 367/377 |
| `String-v8` | output_mismatch | ruffle_matched | 0/377 | 367/377 |
| `TextField-v5` | output_mismatch | ruffle_matched | 0/12 | 9/12 |
| `TextFormat-v7` | output_mismatch | ruffle_matched | 0/174 | 136/174 |
| `ops-v8` | output_mismatch | ruffle_matched | 0/262 | 255/262 |
| `targetPath-v6` | output_mismatch | ruffle_matched | 0/23 | 9/23 |
| `targetPath-v7` | output_mismatch | ruffle_matched | 0/23 | 9/23 |
| `targetPath-v8` | output_mismatch | ruffle_matched | 0/23 | 9/23 |
| `toString_valueOf-v5` | output_mismatch | ruffle_matched | 0/137 | 103/137 |
| `toString_valueOf-v6` | output_mismatch | ruffle_matched | 0/155 | 150/155 |
| `toString_valueOf-v7` | output_mismatch | ruffle_matched | 0/155 | 150/155 |
| `toString_valueOf-v8` | output_mismatch | ruffle_matched | 0/155 | 150/155 |
| `with-v5` | output_mismatch | ruffle_matched | 0/49 | 21/49 |
| `with-v6` | output_mismatch | ruffle_matched | 0/107 | 23/107 |
| `with-v7` | output_mismatch | ruffle_matched | 0/107 | 23/107 |
| `with-v8` | output_mismatch | ruffle_matched | 0/107 | 23/107 |

## Line Count Changed (1)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `array-v5` | output_mismatch | 0/560 | 517/560 | -517 |
