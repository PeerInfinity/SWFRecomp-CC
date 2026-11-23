# s26 wave-2 sibling file map (who edits what; self-localize)

| slot | files / functions |
|---|---|
| w2-loaded-shell-phase2 | `action.c` loaded-movie paths (`actionChildMovieGoto`, `actionGotoFrame` routing, path resolution, `actionInvalidateCachedMovieClip`), `tag.c` `collect_attached_standalone`, shell arms in clip events / button walk, `tag_stubs.c` `ng_findChildEntryDepth`, `ng_shared.c` `ng_enumerateChildren` |
| w2-attached-holder-render | `tag.c` `render_attached_child`, attached depth pass, `ng_update_button_states*` pick order; `action.c` `actionTryBindTextFieldVariable` path branch |
| w2-avm2-applyfilter-kernels | `avm2_bitmap.c` (`bd_apply_filter`, `bd_draw_*`), `avm2_filter_from_object`; maybe `action.c` `bitmapDataApplyFilter` |
| w2-acid-clip-fill-region | shape fill-region / tessellation (`SWFRecomp` shape converter or runtime tessellation), text glyph geometry |
| w2-cm-chain-cab-edge | `SWFRecomp` `swf.cpp` `PlaceCmCompose`, `tag.c` `render_filtered_core` (type-6 arm), cacheAsBitmap capture/bounds |
| local `n-pixel-pass` (one-task session) | may touch `tag.c` / `action.c` / `ng_shared.c` / `swf.c` (N rendering, browser enterFrame) |
| w2-tail-bitmap-draw | `action.c` `rasterizeMovieClipToBitmap` + new `bd1_*` statics; `avm2_cpu_raster.c`; `avm2_display.c` `resolve_shape_geom`, `avm2_render_init`; `tag.c` new `ng_getBitmapByIndex`; `swf.cpp` bitmap-fill `shape_renderable`; build lists (verify_output.py, CMake, WASM scripts) |
| w2-blendshader-cpu-pbj | `avm2_pixelbender.c` (new `avm2_pixelbender_run_blend`); `avm2_display.c` blend-shader render-walk arm, `do_blendshader_set` |
| w2-text-cx-jpeg3 | `action.c` AVM1 text iterators (EditText cxform); text render in `tag.c`/`swf.c`; `swf.cpp` JPEG3/4 emit |
| w2-robustness-land | `ng_shared.c` registries (buttons/videos/fonts/exports/sounds), `tag.c` `tagDoInitActionGuarded`, `tagSetSpriteLabels`, `ng_registerBitmapMetadata` table, cxform-override stack, filter side tables, `registered_class.c`, `action.h` `VAL()`, build flags everywhere, recompiler DefineFunction2 register clamp |
