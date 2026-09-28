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

## Batch 2 (wave 2, launched after w1-trace-tail / w1-pixel-smalls reports)

| agent | files it may edit | notes |
|---|---|---|
| w2-tt-a (resumed w1-trace-tail) | `avm2_display.c`: empty button-state Sprite (~12961) + frame-scripts phase orphan ordering (~3778-3792); recompiler `has_end_tag` | simplebutton_childevents_multichild + missing_frame_scripts |
| w2-tt-b | `avm2_media.c` (Sound load-state machine), `avm2_text.c` TextLine atom functions ONLY | sound_load_multiple + textline_atom_index_at_char_index; stay out of caret/device-font code in avm2_text.c (already landed) |
| w2-tt-c | `action.c` / AVM1 mouse-pick path (single topmost pick on mouse move) | hitarea_remove_owner_drag; stay out of Array sort code |
| w2-px-a (resumed w1-pixel-smalls) | `avm2_bitmap.c::bd_copy_pixels`; `tag.c::compose_children` (~3232) gate | copypixels + nested_rotation probes |
| w2-px-b | clip transform matrix storage (exact `transform.matrix`), `tag.c` AVM1 EditText transformed-border branch (`emulate_line_as_rect`) | small_shear + border_transform; in tag.c stay out of compose_children |
