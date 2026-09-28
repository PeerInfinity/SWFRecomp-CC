# Session 21 — sibling file map (who is editing what)

| agent | wave | files it may edit | notes |
|---|---|---|---|
| w2-arraysort-m3 | 2 | `SWFModernRuntime/src/actionmodern/action.c` (standard Array sort path ONLY), gnash `ignored_tests.txt` / `ACCEPTED_DIFFS.md` array-v5 entries | |
| w2-devicefont-a1 | 2 | `SWFRecomp/src/abc/abc_devicefont.cpp` + recompiler glyph emission; runtime glyph raster if the 5-pixel tie needs it | stay out of EditText caret/selection |
| w2-caret-multiline | 2 | AVM2 EditText caret/selection drawing (`avm2_display.c` / `avm2_text.c` near selection highlight) | NOT `avm2_render_textbox` border arm; not glyph code |
| w1-filters-snap | 1 | throwaway worktree only | prototype |

## Shared, always-conflicting files
- `ruffle-tests/render_canary_tests.txt` — append at EOF; coordinator merges with `--3way`, keeps all blocks.
- `SWFRecompDocs/plans/session21-fanout-reports/` — namespace files by agent label.
