# s27 wave-2 sibling file map (who edits what; self-localize, name every function you touch)

| slot | files / functions |
|---|---|
| w2-layer-alpha-group | `tag.c` layer-group render (AVM1), `avm2_display.c` layer group composite, `render_webgpu.c` group composite only |
| w2-flash-filter-kernels | `avm2_bitmap.c` `bd_apply_filter` kernels (glow/dropshadow/bevel/gradient*), `bd_draw_cm_filtered` |
| w2-jpeg-flash-decode | `image_decode.c` (JPEG decode), maybe `render_webgpu.c` nearest sampler tie rule |
| w2-allow-networking-subtests | `ruffle-tests/verify_output.py` (subtest variants → rows), runtime networking gates (`avm2_*` SharedObject/net, `action.c` getURL/LocalConnection arms) |
| w2-draw-cx-text | `avm2_bitmap.c` `bd_draw_shape_walk`, `bd_draw_textfield`, `text_raster_core` (+ wrapper for `glyph_raster_core`); `action.c` `rasterizeMovieClipToBitmap` + `bd1_*` |
| w2-applyfilter-cm | `action.c` `bitmapDataApplyFilter` (bridge to AVM2 kernels via wrapper), AVM1 CM fold/live paths in `tag.c` `render_filtered_core` / `swf.cpp` `PlaceCmCompose` |
| w2-holder-drawing-full | `tag.c` attached render pass, `render_attached_child`, `tagRerenderFrame` attached pass, late sprite-text pass; `action.c` `actionRenderHolderDrawingsInline` |
| w2-avm2-text-tail | `abc_timeline.cpp` `parseDefineText`, `Avm2StaticTextData` (trailing field), `avm2_render_statictext`, `avm2_cpu_raster_statictext`, `abc_devicefont.cpp` DefineFont4 |
| w2-avm1-text-layout | `tag.c` `textfield_glyph_render_cb`, `tag_text_glyph_compose`; `action.c` `actionIterateTextFieldGlyphs`, `otf_emit_textfield`; `action.h` `TextFieldGlyphInfo` (trailing fields) |
| w2-avm1-leftovers-land | `action.c` mouse dispatch (`actionDispatchMCPress` etc.), EditText path-variable binding, `__resolve`, setNewTextFormat, TextControl Cut/Copy/Paste, SWF≤6 case-insensitive dispatchers; `tag.c` button pick (+22) |
| w2-timers-land | `swf.cpp` DoInitAction/DefineSprite emission; `tag.c` `tagDoInitActionFrame*`, goto-init queue, `tagShowFrame` top block, dead `tagSetFilter*` removal; `swf.c`/`swf_core.c` goto catch-up + `swfStart` retry loop; `timer.c`; `tag_stubs.c` clone-depth table; `action.c` watch table, root goto arms from timers, `actionGetMemberImpl` dead `efd` branch |
| w2-exec-order-land | `swf.c` `tagMain` eligibility slot; `action.c` `actionDispatchEnterFrameHandlers`, `dispatch_root_dprops_enterframe`; `action.h` `MovieClip.ef_fired_tick` (trailing); nested-frame order (frame loop) |
| w2-loaded-shell-land | `action.c` `ng_rootDLEnter/Leave`, `childDLSwapIn`, `actionClearChildMovieShell`, `actionProcessDeferred*`, loaded-movie arms of `actionGetMemberImpl` / `resolveSlashPathToMC` / `actionGetVariableImpl`; `tag.c` (+ phase-3 hunk) |
| local `browser-arms-land` | `action.c` browser `#else` arms (createTextField, getInstanceAtDepth, getRGB, getBounds, …, `actionGetVariableImpl` browser arm), `tools/gate_inventory.py`, `verify_output.py` `SWF_BROWSER_ARMS_TU` |
| local `n-ragdoll-strokes` (N ladder) | `tag.c` `advance_sprite_frames` (children-placed-by-attached-clip init parent), `ng_attached_run_tree` |
