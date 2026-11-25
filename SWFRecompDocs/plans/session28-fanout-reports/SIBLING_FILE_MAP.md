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
