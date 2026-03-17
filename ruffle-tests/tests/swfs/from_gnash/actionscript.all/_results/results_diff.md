# Ruffle Test Results Diff

**Previous:** `be80957869ba` (2026-03-17T02:29:48.506116+00:00)
**Current:** `2fced9201c76` (2026-03-17T03:26:43.266775+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 1 | 17 | +16 |
| Total | 190 | 190 | 0 |
| Pass rate | 0.5% | 8.9% | +8.4% |
| Mismatched lines | 3908 | 3820 | -88 |
|   Decreased | | | -88 |

## Newly Passing (16)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `BitmapData-v6` | output_mismatch | 6/7 | 7/7 |
| `BitmapData-v7` | output_mismatch | 4/7 | 7/7 |
| `ColorTransform-v6` | output_mismatch | 6/7 | 7/7 |
| `ColorTransform-v7` | output_mismatch | 4/7 | 7/7 |
| `ContextMenu-v6` | output_mismatch | 6/7 | 7/7 |
| `MovieClipLoader-v6` | output_mismatch | 4/6 | 6/6 |
| `Point-v6` | output_mismatch | 6/7 | 7/7 |
| `Point-v7` | output_mismatch | 4/7 | 7/7 |
| `Random-v6` | output_mismatch | 29/30 | 30/30 |
| `Random-v7` | output_mismatch | 27/30 | 30/30 |
| `Random-v8` | output_mismatch | 27/30 | 30/30 |
| `Rectangle-v6` | output_mismatch | 6/7 | 7/7 |
| `Rectangle-v7` | output_mismatch | 4/7 | 7/7 |
| `swap-v6` | output_mismatch | 6/7 | 7/7 |
| `swap-v7` | output_mismatch | 4/7 | 7/7 |
| `swap-v8` | output_mismatch | 4/7 | 7/7 |

## Line Count Changed (58)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `Microphone-v5` | output_mismatch | 3/6 | 5/6 | -2 |
| `MovieClipLoader-v5` | output_mismatch | 3/6 | 5/6 | -2 |
| `ASnative-v7` | output_mismatch | 27/110 | 28/110 | -1 |
| `ASnative-v8` | output_mismatch | 28/110 | 29/110 | -1 |
| `Accessibility-v7` | output_mismatch | 9/19 | 10/19 | -1 |
| `Accessibility-v8` | output_mismatch | 8/19 | 9/19 | -1 |
| `AsBroadcaster-v7` | output_mismatch | 81/121 | 82/121 | -1 |
| `AsBroadcaster-v8` | output_mismatch | 80/121 | 81/121 | -1 |
| `Boolean-v7` | output_mismatch | 34/38 | 35/38 | -1 |
| `Boolean-v8` | output_mismatch | 34/38 | 35/38 | -1 |
| `Camera-v5` | output_mismatch | 5/7 | 6/7 | -1 |
| `Camera-v7` | output_mismatch | 32/90 | 33/90 | -1 |
| `Camera-v8` | output_mismatch | 32/90 | 33/90 | -1 |
| `Color-v7` | output_mismatch | 132/161 | 133/161 | -1 |
| `Color-v8` | output_mismatch | 132/161 | 133/161 | -1 |
| `ColorTransform-v8` | output_mismatch | 33/55 | 34/55 | -1 |
| `Error-v7` | output_mismatch | 20/31 | 21/31 | -1 |
| `Error-v8` | output_mismatch | 20/31 | 21/31 | -1 |
| `ExternalInterface-v7` | output_mismatch | 27/55 | 28/55 | -1 |
| `ExternalInterface-v8` | output_mismatch | 81/118 | 82/118 | -1 |
| `Instance-v7` | output_mismatch | 31/52 | 32/52 | -1 |
| `Instance-v8` | output_mismatch | 26/52 | 27/52 | -1 |
| `Key-v7` | output_mismatch | 13/55 | 14/55 | -1 |
| `Key-v8` | output_mismatch | 13/55 | 14/55 | -1 |
| `LocalConnection-v7` | output_mismatch | 19/58 | 20/58 | -1 |
| `LocalConnection-v8` | output_mismatch | 19/58 | 20/58 | -1 |
| `Microphone-v7` | output_mismatch | 42/79 | 43/79 | -1 |
| `Microphone-v8` | output_mismatch | 42/79 | 43/79 | -1 |
| `Mouse-v7` | output_mismatch | 11/21 | 12/21 | -1 |
| `Mouse-v8` | output_mismatch | 10/21 | 11/21 | -1 |
| `NetStream-v7` | output_mismatch | 72/80 | 73/80 | -1 |
| `NetStream-v8` | output_mismatch | 72/80 | 73/80 | -1 |
| `Rectangle-v8` | output_mismatch | 108/166 | 109/166 | -1 |
| `Selection-v7` | output_mismatch | 107/125 | 108/125 | -1 |
| `Selection-v8` | output_mismatch | 107/125 | 108/125 | -1 |
| `System-v7` | output_mismatch | 27/101 | 28/101 | -1 |
| `System-v8` | output_mismatch | 27/101 | 28/101 | -1 |
| `TextFieldHTML-v7` | output_mismatch | 31/37 | 32/37 | -1 |
| `TextFieldHTML-v8` | output_mismatch | 31/37 | 32/37 | -1 |
| `TextFormat-v7` | output_mismatch | 106/174 | 107/174 | -1 |
| `Transform-v7` | output_mismatch | 3/7 | 4/7 | -1 |
| `Video-v7` | output_mismatch | 80/85 | 81/85 | -1 |
| `Video-v8` | output_mismatch | 80/85 | 81/85 | -1 |
| `XMLSocket-v7` | output_mismatch | 26/35 | 27/35 | -1 |
| `XMLSocket-v8` | output_mismatch | 26/35 | 27/35 | -1 |
| `delete-v7` | output_mismatch | 38/60 | 39/60 | -1 |
| `delete-v8` | output_mismatch | 39/60 | 40/60 | -1 |
| `enumerate-v7` | output_mismatch | 18/49 | 19/49 | -1 |
| `enumerate-v8` | output_mismatch | 18/49 | 19/49 | -1 |
| `flash-v7` | output_mismatch | 6/10 | 7/10 | -1 |
| `swap-v5` | output_mismatch | 5/7 | 6/7 | -1 |
| `toString_valueOf-v7` | output_mismatch | 109/155 | 110/155 | -1 |
| `toString_valueOf-v8` | output_mismatch | 108/155 | 109/155 | -1 |
| `ContextMenu-v7` | output_mismatch | 84/131 | 84/131 | 0 |
| `ContextMenu-v8` | output_mismatch | 84/131 | 84/131 | 0 |
| `Global-v8` | output_mismatch | 128/169 | 128/169 | 0 |
| `targetPath-v7` | output_mismatch | 9/23 | 9/23 | 0 |
| `targetPath-v8` | output_mismatch | 9/23 | 9/23 | 0 |
