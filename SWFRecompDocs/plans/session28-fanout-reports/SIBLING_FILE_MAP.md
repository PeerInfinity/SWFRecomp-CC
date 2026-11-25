# s28 wave-2 sibling file map (who edits what; self-localize, name every function you touch)

| slot | files / functions |
|---|---|
| w2-root-onload-proto | `action.c` `actionDispatchRootOnLoad`, `actionDispatchMCOnLoad`; 2 `regression/` fixtures |
| local `browser-root-goto` (browser ladder) | browser arms in `swf.c`/`tag.c`/`action.c`: `ng_executeGotoCatchUp`, `ng_runPendingRootGoto`, timer/event callbacks, parked-frame gate; `tools/browser-test/child_probe/` |
| local `n-stroke-snap` (N ladder) | recompiler `swf.cpp` stroke tessellation; `render_webgpu.c` stroke pipeline; possibly `tag.c` shape draw |
| local `trace-provenance` | docs, `ruffle-tests/flash_fixes/`, RvF (no source) |
| w2-occupied-depth | `tag.c` `tagPlaceObject2` + display-list depth slot (under-chain), warning printf (also NG arms) |
| w2-lowq-sample-point | `render_webgpu.c` stage uploads (`render_webgpu_upload_stage_transform`, pass-open upload), `shade_main` paint fix, clip/mask/filter-layer/text quad passes (MSAA_SAMPLES==1 only); maybe `tag.c` `cab_snap_delta` |
| w2-avm1-leads-land | `action.c` `avm1QueueFormDataEvent`/`avm1FireFormDataEvents`, `actionLoadedMovieDeliveredThisTick`/`actionNoteLoadedMovieDelivered`/`actionFirePendingDirectLoadsImpl`, onUnload dispatch (`actionFireOnUnload`); `sprite_frame_scripts.c` `actionQueuePendingSpriteScript`; `tag.c` `queue_pending_finalize_mc`, `run_pending_finalize` |
| w2-hittest-shape-stale | `action.c` hitTest arm of `actionCallMethod` (~80573) + a per-clip render-time matrix snapshot (trailing MovieClip field) |
| w2-text-edit-land | `action.c` `actionTextFieldInput` restrict branch, setNewTextFormat span model (`tf_snf`), getTextFormat getters; `avm2_display.c` (selection, keep tint) |
| w2-glyph-quarter-snap | `tag.c` `textfield_glyph_render_cb`, `tf_border_line_segment`; maybe `avm2_display.c` `avm2_render_glyphs`, `avm2_render_textbox` |
| w2-test12-land | enterFrame snapshot/queue at tick start: `action.c` `actionDispatchEnterFrameHandlers` / `tagFlushPendingEnterFrame` (`tag.c`), `swf.c` frame loop (self-localize; shared with ladders) |
| w2-flash-stroke-width | recompiler `swf.hpp` `LineStyle`, `swf.cpp` LINESTYLE2 parse + `stroke_run_data` emit; `render_webgpu.c` `hairline_restage` (overlaps local n-stroke-snap: keep separable) |
| w2-loaded-shell-land | `action.c` loaded-movie delivery/advance order, `actionProcessDeferred*`, loaded goto deferral, MCL progress events, unloadMovie cancel; `timer.c` |
| w2-filter-residuals-land | `tag.c` `filter_shadow_offset_px`, `compose_chain_entry_to_layer`, `render_filtered_core` offset block; `avm2_display.c` filter composer / `avm2_render_filtered`; `avm2_bitmap.c` `fb_glow_amount`, bevel sampling |
| w2b-gnash-holds | `action.c` with-stack (`actionWithStart`), Selection.setSelection, NaN equality / string compare, SWF5 Function.prototype visibility, SetMember inherited setter |
| w2b-avm2-d2a | `avm2_number.c` number→string (`avm2_format_number`, toFixed/toExponential/toPrecision/radix) |
| w2b-stroke-width-merge | `render_webgpu.c` `hairline_restage` + new `hairline_flash_offset`; recompiler `swf.hpp` `LineStyle` / `swf.cpp` LINESTYLE2 (via `stroke_run_flags[]`) |
