# Graphics vs Trace Mode Differences

Trace: 46/47 passing | Graphics: 0/47 passing

## Graphics Regressions (46 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

| # | Test | Graphics Status | Detail |
|---|------|-----------------|--------|
| 1 | `array` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 2 | `bitmapdata/getPixel` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 3 | `bitmapdata/loadBitmap` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 4 | `callee` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 5 | `depth` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 6 | `doactionorder/doactionorder` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 7 | `doactionorder/symbolclass` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 8 | `duplicateMovieClip/dontremove` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 9 | `duplicateMovieClip/duplicateMovieClip` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 10 | `duplicateMovieClip/name-coercion` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 11 | `duplicateMovieClip/samedepth` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 12 | `externalinterface` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 13 | `filters` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 14 | `haxe/flocons1` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 15 | `haxe/flocons2` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 16 | `label` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 17 | `levels` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 18 | `loadevent` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 19 | `loadvariables/loadvariables` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 20 | `loadvariables/loadvars` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 21 | `lookup` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 22 | `mouse-transparency` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 23 | `moviecliploader` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 24 | `nativeinheritance` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 25 | `nested-button` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 26 | `operations` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 27 | `property-paths/property-paths-6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 28 | `property-paths/property-paths-7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 29 | `propertycase/propertycase` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 30 | `propertycase/propertycase-preserving-6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 31 | `propertycase/propertycase-preserving-7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 32 | `rollover` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 33 | `scope` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 34 | `setinterval` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 35 | `settimeout` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 36 | `super` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 37 | `target` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 38 | `text-bind` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 39 | `textfield/textfield-html` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 40 | `textfield/textfield-text-setters` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 41 | `undefined/undefined-swf6` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 42 | `undefined/undefined-swf7` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 43 | `watch` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 44 | `xml/xmlbuild` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 45 | `xml/xmlload` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |
| 46 | `xml/xmlstring` | Compile Fail | action.c:11:10: fatal error: curve_flatten.h: No such file or directory |

## Graphics Improvements (0 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

No improvements.
