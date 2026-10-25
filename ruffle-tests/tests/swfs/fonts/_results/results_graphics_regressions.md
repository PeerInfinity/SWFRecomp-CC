# Graphics vs Trace Mode Differences

Trace: 0/9 passing | Graphics: 7/9 passing

## Graphics Regressions (0 tests)

Tests that **pass** in trace mode but **fail** in graphics mode.

No regressions.

## Graphics Improvements (7 tests)

Tests that **fail** in trace mode but **pass** in graphics mode.

| # | Test | Trace Status | Detail |
|---|------|---------------|--------|
| 1 | `device_font_glyph_fallback` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 2 | `device_font_kerning` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 3 | `device_font_list` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 4 | `embed_matching/fallback_preferences` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 5 | `embed_matching/match_style` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 6 | `embed_matching/no_font_found` | Compile Fail | avm2_date.c:231:35: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
| 7 | `embed_name_lookup` | Compile Fail | date.c:186:28: error: implicit declaration of function ‘timegm’; did you mean ‘time’? [-Wimplicit-function-declaration] |
