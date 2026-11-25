# s28 wave-2 sibling file map (who edits what; self-localize, name every function you touch)

| slot | files / functions |
|---|---|
| w2-root-onload-proto | `action.c` `actionDispatchRootOnLoad`, `actionDispatchMCOnLoad`; 2 `regression/` fixtures |
| local `browser-root-goto` (browser ladder) | browser arms in `swf.c`/`tag.c`/`action.c`: `ng_executeGotoCatchUp`, `ng_runPendingRootGoto`, timer/event callbacks, parked-frame gate; `tools/browser-test/child_probe/` |
| local `n-stroke-snap` (N ladder) | recompiler `swf.cpp` stroke tessellation; `render_webgpu.c` stroke pipeline; possibly `tag.c` shape draw |
| local `trace-provenance` | docs, `ruffle-tests/flash_fixes/`, RvF (no source) |
