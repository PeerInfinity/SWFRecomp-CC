# s29 sibling file map (who edits what; self-localize, name every function you touch)

| slot | files / functions |
|---|---|
| w1-drift | BitmapData paletteMap (AVM1 + AVM2 arms) |
| w1-disposition-audit | AVM2 Loader .swz signature / securityError path; tab ordering (`tabIndex` edge case); hitTest shapeFlag; docs (ACCEPTED_DIFFS, ignored_tests, RvF) |
| w1-timers-goto | `timer.c`; `action.c` `actionNextFrame`/`actionPrevFrame` enterframe arm; gnash gotoFrameFromInterval path |
| w1-rm-avm1-gnash | `action.c` AVM1 builtins (ExternalInterface, loadVariables, super re-resolution), loader cancel |
| w1-rm-avm2 | `verify_output.py` TZ override; `avm2_date*.c` setMinutes DST; recompiler `abc_emit.cpp` debug line (bucket P) |
| w1-lowq-next | `render_webgpu.c` LOW (MSAA_SAMPLES==1) sample/tie rules, stroke y |
| w1-aa-sizing | none (diagnosis; debug build only) |
| w1-text-pixels | `tag.c` `textfield_glyph_render_cb`, `tf_border_line_segment`; `avm2_display.c` `avm2_render_glyphs` |
| w1-pixel-flash-gaps | filters (`tag.c` `render_filtered_core`, `avm2_bitmap.c` bevel), drawing-API stroke snap |
| local N ladder | recompiler stroke builders / lyon (`swf.cpp`), `render_webgpu.c` stroke pipeline: closed seam as two caps |
| local browser ladder | `ng_gotoFrameByMC` same-frame branch, browser-only gotoAndStop(current) guard (`swf.c`/`tag.c`/`action.c`) |
