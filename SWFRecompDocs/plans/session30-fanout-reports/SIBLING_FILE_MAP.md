# s30 sibling file map (who edits what; self-localize, name every function you touch)

| slot | files / functions |
|---|---|
| w1-drift-smalls | AVM2 `XMLDocument`/`XMLNode.toString`; AVM1 TextField `tabIndex` setter/delete/enumeration; AVM2 Loader/`<img>` unhandled ErrorEvent #2044 (`ul_deliver`); shape-flag `hitTest` (layers geometry, morph boundary) |
| w1-native-table | **sole owner** of `setupNativeFuncOwnProps` and every AVM1 native member/flag table (`action.c`, `avm1_*.c`, `math.c`); new generator script |
| w1-exec-order | **FILE-ADJACENT to the browser ladder item 1**: frame loops in `swf.c` / `swf_core.c`, `action_queue.c` (`order_key`, `actionAQOrder*`), `tag.c` `advance_sprite_frames` / `advance_nested_sprite_frames`, clip-event enterFrame walk; `tag_stubs.c` only if unavoidable. Land one at a time with the ladder |
| w1-rm-avm1-gnash | `action.c` AVM1 builtins other than native tables (loadVariables, LoadVars, watch/addProperty, setProperty, SWF5 visibility), gnash singletons |
| w1-rm-avm2 | AVM2 frame/event lifecycle (`avm2_*` loader/event dispatch), typed nulls, FTE; recompiler `abc_*.cpp` if needed |
| w1-lowq-residues | `render_webgpu.c` LOW (MSAA_SAMPLES == 1) tie / band / 45° stroke rules; LOW glyph path (`tag.c` text render) |
| w1-stroke-geometry | recompiler stroke builders (`swf.cpp`, lyon), `render_webgpu.c` stroke pipeline at HIGH, `avm2_display.c` `gfx_build_stroke` / `gfx_stroke_seam_caps_on`, `drawingUnionTris` |
| local browser ladder | `tag_stubs.c` `ng_attachMovie` browser-only force-nested-build block (`#if !NG && !OR`); placement warning path; then nested-child swapDepths + removeMovieClip; then timeline-sprite self-goto port |
