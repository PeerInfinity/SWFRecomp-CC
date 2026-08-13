# Graphics vs Trace Mode Differences

Trace: 135/243 passing | Graphics: 0/243 passing

## Graphics Regressions (135 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `Accessibility-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `Accessibility-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `Accessibility-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `Accessibility-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `AsBroadcaster-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `BitmapData-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `BitmapData-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `BitmapData-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `Boolean-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `Boolean-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `Boolean-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `Boolean-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `Camera-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `Color-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `Color-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `Color-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `Color-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `ColorTransform-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `ColorTransform-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 20 | `ColorTransform-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 21 | `ColorTransform-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 22 | `ContextMenu-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 23 | `ContextMenu-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 24 | `ContextMenu-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 25 | `ContextMenu-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 26 | `Error-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 27 | `Error-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 28 | `Error-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 29 | `Error-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 30 | `ExternalInterface-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 31 | `ExternalInterface-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 32 | `ExternalInterface-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 33 | `Global-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 34 | `Global-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 35 | `Global-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 36 | `Instance-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 37 | `Instance-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 38 | `Instance-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 39 | `Instance-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 40 | `Key-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 41 | `Key-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 42 | `Key-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 43 | `Key-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 44 | `LoadVars-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 45 | `LocalConnection-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 46 | `LocalConnection-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 47 | `LocalConnection-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 48 | `LocalConnection-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 49 | `Matrix-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 50 | `Microphone-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 51 | `Mouse-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 52 | `Mouse-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 53 | `Mouse-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 54 | `Mouse-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 55 | `MovieClipLoader-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 56 | `MovieClipLoader-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 57 | `NetConnection-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 58 | `NetStream-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 59 | `NetStream-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 60 | `NetStream-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 61 | `NetStream-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 62 | `Number-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 63 | `Number-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 64 | `Number-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 65 | `Point-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 66 | `Point-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 67 | `Point-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 68 | `Point-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 69 | `Random-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 70 | `Random-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 71 | `Random-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 72 | `Random-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 73 | `Rectangle-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 74 | `Rectangle-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 75 | `Rectangle-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 76 | `Selection-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 77 | `Stage-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 78 | `System-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 79 | `System-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 80 | `System-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 81 | `System-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 82 | `TextFieldHTML-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 83 | `TextFieldHTML-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 84 | `TextFieldHTML-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 85 | `TextFieldHTML-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 86 | `TextFormat-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 87 | `TextFormat-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 88 | `TextSnapshot-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 89 | `TextSnapshot-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 90 | `TextSnapshot-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 91 | `TextSnapshot-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 92 | `Transform-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 93 | `Transform-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 94 | `Transform-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 95 | `Try-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 96 | `Try-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 97 | `Try-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 98 | `Try-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 99 | `Video-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 100 | `Video-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 101 | `Video-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 102 | `Video-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 103 | `XMLSocket-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 104 | `XMLSocket-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 105 | `XMLSocket-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 106 | `XMLSocket-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 107 | `argstest-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 108 | `case-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 109 | `case-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 110 | `case-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 111 | `case-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 112 | `delete-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 113 | `delete-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 114 | `delete-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 115 | `delete-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 116 | `enumerate-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 117 | `enumerate-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 118 | `enumerate-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 119 | `enumerate-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 120 | `flash-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 121 | `flash-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 122 | `flash-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 123 | `flash-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 124 | `getvariable-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 125 | `getvariable-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 126 | `getvariable-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 127 | `getvariable-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 128 | `swap-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 129 | `swap-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 130 | `swap-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 131 | `swap-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 132 | `targetPath-v5` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 133 | `targetPath-v6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 134 | `targetPath-v7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 135 | `targetPath-v8` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
